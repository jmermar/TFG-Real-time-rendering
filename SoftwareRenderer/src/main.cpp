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
    glm::vec3 camPos(0.f, 1.f, 5.f);
    renderer->setProjection(p);

    Mesh mesh = loadMesh("res/vikingroom.obj");
    cout << "Cargada malla de " << mesh.triangles.size() * 3 << " vertices y " << mesh.triangles.size() << " caras" << endl;
    Texture tex = loadTexture("res/vikingroom_tex.png");

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
            camPos = glm::rotate(glm::mat4(1.f), glm::radians(-deltaTime * 45), glm::vec3(0, 1, 0)) * glm::vec4(camPos, 1.f);
        if (keys[SDL_SCANCODE_D])
            camPos = glm::rotate(glm::mat4(1.f), glm::radians(deltaTime * 45), glm::vec3(0, 1, 0)) * glm::vec4(camPos, 1.f);
        if (keys[SDL_SCANCODE_W])
            camPos = camPos + glm::normalize(-camPos) * deltaTime;
        if (keys[SDL_SCANCODE_S])
            camPos = camPos + glm::normalize(camPos) * deltaTime;
        if (keys[SDL_SCANCODE_UP])
            camPos.y += deltaTime;
        if (keys[SDL_SCANCODE_DOWN])
            camPos.y -= deltaTime;


        // Rendering
        renderer->clear(0, 0, 0);

        renderer->setView(glm::lookAt(camPos, glm::vec3(0.f), glm::vec3(0, 1, 0)));

        Profiler::get().startRasterMeasure();
        renderer->drawMesh(mesh, glm::mat4(1.f), tex);
        Profiler::get().endRasterMeasure();

        renderer->display();


        SDL_RenderPresent(render);

        deltaTime = 1.f / Profiler::get().endFPSMeasure();
    }

    delete renderer;

    IMG_Quit();

    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();

    Profiler::get().printResults();
    return 0;
}