#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <SDL2/SDL.h>

#include "Mesh.hpp"
#include "Texture.hpp"

using namespace std;

class SoftwareRenderer {
private:
    struct Box {
        int x1, y1, x2, y2;
    };
    struct HomogenousVertex {
        glm::vec4 pos;
        glm::vec2 uv;
    };

    struct HomogenousTriangle {
        HomogenousVertex v[3];
    };
    int width, height;
    SDL_Texture* output;
    SDL_Renderer* render;
    Texture buffer;
    vector<float> zbuffer;
    Pixel lineColor;
    
    glm::mat4 projection;
    glm::mat4 view;
    glm::mat4 viewProj;
    glm::mat4 mvp;
    glm::mat4 model;

    glm::vec3 lightDirection;


    void plotPoint(int x, int y, Pixel& color);
    void bresenhamLow(int x1, int x2, int y1, int y2, Pixel& color);
    void bresenhamHigh(int x1, int x2, int y1, int y2, Pixel& color);
    void drawLine(glm::vec3 a, glm::vec3 b);

    inline glm::vec2 ndc2sc(glm::vec2 ndc) {
        return glm::vec2((1.f + ndc.x) * width * 0.5f, (1.f - ndc.y) * height * 0.5f);
    }
    
    inline float edgeFunction(glm::vec2&a, glm::vec2&b, glm::vec2&p);
    inline void rasterize(HomogenousTriangle t);

    inline HomogenousVertex intersection(HomogenousVertex& a, HomogenousVertex& b, glm::vec4& plane);
    inline bool isVisible(HomogenousVertex& a, HomogenousVertex& b, HomogenousVertex& c, Box& bb);
    int clip(HomogenousTriangle& o, HomogenousTriangle* buff, glm::vec4& plane);
    inline HomogenousVertex vertex(Vertex& v);
public:
    SoftwareRenderer(int w, int h, SDL_Renderer* r);
    ~SoftwareRenderer();

    void setView(glm::mat4 view);
    void setProjection(glm::mat4 projection);
    void setLightDirection(glm::vec3 dir);


    void setLineColor(float r, float g, float b);

    void clear(float r, float g, float b);
    void drawWireframe(Mesh& mesh, glm::mat4 model);
    void drawMesh(Mesh& mesh, glm::mat4 model);

    void display();
};