#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <glm/ext.hpp>
#include "Renderer.hpp"
#include <iostream>

#include <Profiler.hpp>

const int Width = 1280, Height = 720;

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
    SDL_Window* window = SDL_CreateWindow("Software rasterizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, SDL_WINDOW_SHOWN);
    SDL_Renderer* render = SDL_CreateRenderer(window, 0, 0);

    // 
    SoftwareRenderer* renderer = new SoftwareRenderer(Width, Height, render);
    glm::mat4 p = glm::perspectiveFov(90.f, (float)Width, (float)Height, 0.1f, 1000.f);
    float camDis = 12.f;
    float xRot = -30.f;
    float yRot = 45.f;
    renderer->setProjection(p);

    Mesh mesh = loadMesh("res/house.obj");
    cout << "Cargada malla de " << mesh.triangles.size() * 3 << " vertices y " << mesh.triangles.size() << " caras" << endl;
    Texture tex = loadTexture("res/house_tex.png");

    bool running = 1;

    float deltaTime = 0.f;
    while(running) {
        Profiler::get().startFPSMeasure();

        SDL_Event ev;
        while(SDL_PollEvent(&ev)) {
            switch(ev.type) {
            case SDL_QUIT:
                running = 0;
                break;
            }
        }

        // User input
        const unsigned char* keys = SDL_GetKeyboardState(NULL);
        if (keys[SDL_SCANCODE_A])
            yRot -= deltaTime * 45;
        if (keys[SDL_SCANCODE_D])
            yRot += deltaTime * 45;
        if (keys[SDL_SCANCODE_W])
            camDis = glm::max(0.f, camDis - deltaTime);
        if (keys[SDL_SCANCODE_S])
            camDis = camDis + deltaTime;
        if (keys[SDL_SCANCODE_UP])
            xRot += deltaTime * 45;
        if (keys[SDL_SCANCODE_DOWN])
            xRot -= deltaTime * 45;


        glm::vec3 camPos = 
            glm::rotate(glm::mat4(1.f), glm::radians(yRot), glm::vec3(0, 1, 0)) *
            glm::rotate(glm::mat4(1.f), glm::radians(xRot), glm::vec3(1, 0, 0)) *
            glm::vec4(0, 0, camDis, 0);

        // Rendering
        renderer->clear(0, 0, 0);

        renderer->setView(glm::lookAt(camPos, glm::vec3(0.f), glm::vec3(0, 1, 0)));

        Profiler::get().startRasterMeasure();
        renderer->drawMesh(mesh, glm::scale(glm::mat4(1), glm::vec3(0.25f)), tex);
        float rasterTIme = Profiler::get().endRasterMeasure();

        renderer->display();


        SDL_RenderPresent(render);

        deltaTime = 1.f / Profiler::get().endFPSMeasure();

        cout << "Raster time(ms): " << rasterTIme * 1000.f << endl;
        cout << "Render time(ms): " << deltaTime * 1000.f << endl;
        cout << "FPS: " << 1.f / deltaTime << endl;
    }

    delete renderer;

    IMG_Quit();

    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();

    Profiler::get().printResults();
    return 0;
}
