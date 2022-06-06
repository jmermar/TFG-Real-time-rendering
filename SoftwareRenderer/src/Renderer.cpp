#include <Renderer.hpp>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

#include <glm/ext.hpp>
#include <Profiler.hpp>

SoftwareRenderer::SoftwareRenderer(int w, int h, SDL_Renderer* r) {
    width = w;
    height = h;
    render = r;

    output = SDL_CreateTexture(render,
        SDL_PIXELFORMAT_RGB24,
        SDL_TEXTUREACCESS_STREAMING,
        width,
        height);
    
    buffer.width = w;
    buffer.height = h;
    buffer.data.resize(w * h);

    zbuffer.resize(w * h);

    lineColor = {255, 255, 255};

    view = glm::mat4(1);
    projection = glm::mat4(1);
}

SoftwareRenderer::~SoftwareRenderer() {
    SDL_DestroyTexture(output);
}

void SoftwareRenderer::setView(glm::mat4 view) {
    this->view = view;
}

void SoftwareRenderer::setProjection(glm::mat4 projection) {
    this->projection = projection;
}

void SoftwareRenderer::setLightDirection(glm::vec3 dir) {
    lightDirection = glm::normalize(dir);
}

void SoftwareRenderer::plotPoint(int x, int y, Pixel& color) {
    if (x >= 0 && x < buffer.width && y >= 0 && y < buffer.height) {
        buffer.data[y * buffer.width + x] = color;
    }
}

void SoftwareRenderer::drawLine(glm::vec3 a, glm::vec3 b) {
    // First, transform line to device coordinates
    int x1 = (a.x + 1) * buffer.width * 0.5f;
    int x2 = (b.x + 1) * buffer.width * 0.5f;
    int y1 = (1 - a.y) * buffer.height * 0.5f;
    int y2 = (1 - b.y) * buffer.height * 0.5f;
    
    int dy = y2 - y1;
    int dx = x2 - x1;


    if (abs(dy) < abs(dx)) {
        if (x1 < x2) 
            bresenhamLow(x1, x2, y1, y2, lineColor);
        else 
            bresenhamLow(x2, x1, y2, y1, lineColor);
    } else {
        if (y1 < y2) 
            bresenhamHigh(x1, x2, y1, y2, lineColor);
        else 
            bresenhamHigh(x2, x1, y2, y1, lineColor);
    }
}

void SoftwareRenderer::bresenhamLow(int x1, int x2, int y1, int y2, Pixel & color) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int x = x1;
    int y = y1;
    int inc = 1;
    if (dy < 0) {
        inc = -1;
        dy = -dy;
    }

    int D = 2*dy - dx;

    plotPoint(x, y, color);

    while(x <= x2 && x < buffer.width) {
        plotPoint(x, y, color);
        x++;
        if (D < 0) D = D + 2*dy;
        else {
            y+=inc;
            D = D + 2 *(dy - dx);
        }
    }
}

void SoftwareRenderer::bresenhamHigh(int x1, int x2, int y1, int y2, Pixel & color) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int x = x1;
    int y = y1;
    int inc = 1;
    if (dx < 0) {
        inc = -1;
        dx = -dx;
    }

    int D = 2*dx - dy;

    plotPoint(x, y, color);

    while(y <= y2 && y < buffer.height) {
        plotPoint(x, y, color);
        y++;
        if (D < 0) D = D + 2*dx;
        else {
            x+=inc;
            D = D + 2 *(dx - dy);
        }
    }
}

void SoftwareRenderer::clear(float r, float g, float b) {
    for(int i = 0; i < width * height; i++) {
        buffer.data[i].r = r * 255;
        buffer.data[i].g = g * 255;
        buffer.data[i].b = b * 255;
        zbuffer[i] = INFINITY;
    }
}

void SoftwareRenderer::setLineColor(float r, float g, float b) {
    lineColor.r = r * 255;
    lineColor.g = g * 255;
    lineColor.b = b * 255;
}

SoftwareRenderer::HomogenousVertex SoftwareRenderer::intersection(HomogenousVertex& a, HomogenousVertex& b, glm::vec4& plane) {
    glm::vec4 delta = b.pos - a.pos;
    glm::vec3 norm = plane;
    glm::vec3 orig = a.pos;

    float dis = -(plane.w + glm::dot(glm::vec3(plane), orig)) / glm::dot(glm::vec3(plane), glm::vec3(delta));

    HomogenousVertex v;
    v.pos = a.pos + delta * dis;
    glm::vec2 duv = b.uv - a.uv;
    v.uv = a.uv + duv * dis;

    return v;
}

int SoftwareRenderer::clip(HomogenousTriangle& o, HomogenousTriangle* buff, glm::vec4& plane){
    int visibles = 0;
    int firstVisible = -1;
    bool prevVisible = false;
    for(int i = 0; i < 3; i++) {
        glm::vec4 v = o.v[i].pos;
        v.w = 1;
        if (glm::dot(v, plane) >= 0.f) {
            visibles++;
            if (firstVisible == -1 || (!prevVisible && i == 2)) firstVisible = i;
            prevVisible = true;
        } else {
            prevVisible = false;
        }
    }

    if (visibles == 3) {
        buff[0] = o;
        return 1;
    }

    if (visibles == 0) {
        return 0;
    }

    int a = firstVisible;
    int b = (a + 1) % 3;
    int c = (a + 2) % 3;
    if (visibles == 1) {
        buff[0].v[0] = o.v[a];
        buff[0].v[1] = intersection(o.v[a], o.v[b], plane);
        buff[0].v[2] = intersection(o.v[a], o.v[c], plane);

        return 1;
    }
    if (visibles == 2) {
        buff[0].v[0] = o.v[a];
        buff[0].v[1] = o.v[b];
        buff[0].v[2] = intersection(o.v[b], o.v[c], plane);

        buff[1].v[0] = o.v[a];
        buff[1].v[1] = intersection(o.v[b], o.v[c], plane);
        buff[1].v[2] = intersection(o.v[a], o.v[c], plane);
        
        return 2;
    }

    return 0;
}

bool SoftwareRenderer::isVisible(HomogenousVertex& a, HomogenousVertex& b, HomogenousVertex& c, Box& bb) {
    float maxX = glm::max(a.pos.x, glm::max(b.pos.x, c.pos.x));
    float maxY = glm::max(a.pos.y, glm::max(b.pos.y, c.pos.y));
    float minX = glm::min(a.pos.x, glm::min(b.pos.x, c.pos.x));
    float minY = glm::min(a.pos.y, glm::min(b.pos.y, c.pos.y));

    if (maxX < -1.f || maxY < -1.f || minX > 1.f || minY > 1.f) {
        return false;
    }
    
    glm::vec2 tl = ndc2sc(glm::vec2(minX, maxY));
    glm::vec2 br = ndc2sc(glm::vec2(maxX, minY));



    bb.x1 = max(0, (int) tl.x);
    bb.x2 = min(width - 1, (int) br.x);
    bb.y1 = max(0, (int) tl.y);
    bb.y2 = min(height - 1, (int) br.y);

    return true;
}

SoftwareRenderer::HomogenousVertex SoftwareRenderer::vertex(Vertex& v) {
    HomogenousVertex hv;
    hv.uv = v.uv;
    hv.pos = mvp * glm::vec4(v.pos, 1.f);
    return hv;
}

void SoftwareRenderer::drawWireframe(Mesh& mesh, glm::mat4 transform) {
    glm::vec4 near(0.f, 0.f, 1.f, -projection[3][2] / (projection[2][2] - 1));
    mvp = projection * view * transform;
    model = transform;
    for(int i = 0; i < mesh.triangles.size(); i++) {
        Triangle& original = mesh.triangles[i];

        HomogenousTriangle t;
        t.v[0] = vertex(original.a);
        t.v[0] = vertex(original.a);
        t.v[0] = vertex(original.a);
        HomogenousTriangle buff[2];
        int cFaces = clip(t, buff, near);

        for(int i = 0; i < cFaces; i++) {
            glm::vec3 a = buff[i].v[0].pos / buff[i].v[0].pos.w;
            glm::vec3 b = buff[i].v[1].pos / buff[i].v[1].pos.w;
            glm::vec3 c = buff[i].v[2].pos / buff[i].v[2].pos.w;

            drawLine(a, b);
            drawLine(b, c);
            drawLine(c, a);
        }
    }
}

float SoftwareRenderer::edgeFunction(glm::vec2& a, glm::vec2& b, glm::vec2& p) {
    return (a.x - b.x) * (p.y - a.y) - (a.y - b.y) * (p.x - a.x);
}

void SoftwareRenderer::rasterize(HomogenousTriangle t, Texture& tex) {
    Box bb;
    if (!isVisible(t.v[0], t.v[1], t.v[2], bb)) return;

    t.v[0].pos.w = 1.f / t.v[0].pos.w;
    t.v[1].pos.w = 1.f / t.v[1].pos.w;
    t.v[2].pos.w = 1.f / t.v[2].pos.w;

    t.v[0].uv = t.v[0].uv * t.v[0].pos.w;
    t.v[1].uv = t.v[1].uv * t.v[1].pos.w;
    t.v[2].uv = t.v[2].uv * t.v[2].pos.w;

    glm::vec2 coords[3];
    coords[0] = ndc2sc(t.v[0].pos);
    coords[1] = ndc2sc(t.v[1].pos);
    coords[2] = ndc2sc(t.v[2].pos);
    glm::vec2 p;
    float area = 1.f / edgeFunction(coords[0], coords[1], coords[2]);

    for(int y = bb.y1; y <= bb.y2; y++) {
        p.y = y;
        for (int x = bb.x1; x <= bb.x2; x++) {
            p.x = x;

            float u = edgeFunction(coords[1], coords[2], p) * area;
            float v = edgeFunction(coords[2], coords[0], p) * area;
            float w = edgeFunction(coords[0], coords[1], p) * area;

            if (u < 0 || v < 0 || w < 0) continue;


            float iz = t.v[0].pos.w * u + t.v[1].pos.w * v + t.v[2].pos.w * w;
            float z = 1.f / iz;
            #pragma omp critical
            if (zbuffer[y * width + x] > z) {
                // Perspective correct barycentrics
                glm::vec2 texCoords = (t.v[0].uv * u + t.v[1].uv * v + t.v[2].uv * w) * z;
                int tx = glm::clamp(texCoords.x, 0.f, 1.f) * (tex.width - 1);
                int ty = glm::clamp(texCoords.y, 0.f, 1.f) * (tex.height - 1);

                Pixel& color = tex.data[ty * tex.width + tx];

                buffer.data[y * width + x].r = color.r;
                buffer.data[y * width + x].g = color.g;
                buffer.data[y * width + x].b = color.b;

                zbuffer[y * width + x] = z;
            }
        }
    }
}

void SoftwareRenderer::drawMesh(Mesh& mesh, glm::mat4 model, Texture& tex) {
    glm::vec4 near(0.f, 0.f, 1.f, -projection[3][2] / (projection[2][2] - 1));
    mvp = projection * view * model;
    this->model = model;
    #pragma omp parallel for num_threads(6)
    for(int i = 0; i < mesh.triangles.size(); i++) {
        Triangle& original = mesh.triangles[i];

        HomogenousTriangle t;
        t.v[0] = vertex(original.a);
        t.v[1] = vertex(original.b);
        t.v[2] = vertex(original.c);

        HomogenousTriangle buff[2];
        int cFaces = clip(t, buff, near);

        for(int i = 0; i < cFaces; i++) {
            float z1 = buff[i].v[0].pos.w;
            float z2 = buff[i].v[1].pos.w;
            float z3 = buff[i].v[2].pos.w;

            buff[i].v[0].pos /= z1;
            buff[i].v[1].pos /= z2;
            buff[i].v[2].pos /= z3;

            buff[i].v[0].pos.w = z1;
            buff[i].v[1].pos.w = z2;
            buff[i].v[2].pos.w = z3;

            // Check if face is clock-wise
            float x1 = buff[i].v[0].pos.x;
            float y1 = buff[i].v[0].pos.y;
            float x2 = buff[i].v[1].pos.x;
            float y2 = buff[i].v[1].pos.y;
            float x3 = buff[i].v[2].pos.x;
            float y3 = buff[i].v[2].pos.y;
            if ((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1) >= 0) continue;

            rasterize(buff[i], tex);
        }
    }
}

void SoftwareRenderer::display() {
    // Copiar el buffer a la textura
    void* pixels;
    int pitch;
    SDL_LockTexture(output, NULL, &pixels, &pitch);

    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            unsigned char* pixel = ((unsigned char*) pixels) + y * pitch + x * 3;
            pixel[0] = buffer.data[y * width + x].r;
            pixel[1] = buffer.data[y * width + x].g;
            pixel[2] = buffer.data[y * width + x].b;

        }
    }

    SDL_UnlockTexture(output);

    SDL_RenderCopy(render, output, NULL, NULL);
}