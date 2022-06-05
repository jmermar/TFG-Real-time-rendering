#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <glm/ext.hpp>
#include "Renderer.hpp"
#include <iostream>


const int Width = 1280, Height = 720;

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
    SDL_Window* window = SDL_CreateWindow("Software rasterizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, SDL_WINDOW_SHOWN);
    SDL_Renderer* render = SDL_CreateRenderer(window, 0, 0);

    SoftwareRenderer* renderer = new SoftwareRenderer(Width, Height, render);
    glm::mat4 p = glm::perspectiveFov(90.f, (float)Width, (float)Height, 0.1f, 1000.f);
    renderer->setLightDirection(glm::vec3(3, -1, 1));

    renderer->setProjection(p);

    Mesh mesh = loadMesh("res/vikingroom.obj");
    Texture tex = loadTexture("res/vikingroom_tex.png");

    glm::mat4 cubeModel = glm::scale(glm::mat4(1.f), glm::vec3(1, 1, 2));
    cubeModel = glm::translate(glm::mat4(1.f), glm::vec3(2, 0, -1)) * cubeModel;


    float angle = 0;

    bool running = 1;
    while(running) {
        SDL_Event ev;
        while(SDL_PollEvent(&ev)) {
            switch(ev.type) {
            case SDL_QUIT:
                running = 0;
                break;
            }
        }

        angle += 1.f;

        glm::mat4 r = glm::rotate(glm::mat4(1.f), glm::radians(angle), glm::vec3(0.f, 1.f, 0.f));
        glm::mat4 s = glm::scale(glm::mat4(1.f), glm::vec3(2.f, 2.f, 2.f));

        renderer->clear(0, 0, 0);

        renderer->setLineColor(1, 0, 0);

        glm::mat4 t = glm::translate(glm::mat4(1.f), glm::vec3(0, -2, -5));
        renderer->drawMesh(mesh, t * r * s, tex);

        renderer->display();


        SDL_RenderPresent(render);
    }

    delete renderer;

    IMG_Quit();

    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}