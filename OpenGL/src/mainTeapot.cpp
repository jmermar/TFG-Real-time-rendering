#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <iostream>
#include <algorithm>

#include "Window.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"
#include "Shader.hpp"
#include "Material.hpp"
#include "MaterialTextured.hpp"

using namespace std;

const int Width = 1280;
const int Height = 720;

int main(int argc, char** argv) {
    Window* window = new Window(Width, Height);

    glm::mat4 proj = glm::perspectiveFov(90.f, (float)Width, (float)Height, 0.1f, 1000.f);

    Mesh* teapot = new Mesh("res/models/teapot.obj");
    Material* mat = new Material(glm::vec3(1, 0, 0), 1, 0.4, 1);
    mat->setProj(proj);

    vector<LightSource> lights;
    //lights.push_back({glm::vec3(0, 0, 5), glm::vec3(200)});
    //lights.push_back({glm::vec3(0, 5, 0), glm::vec3(200)});
    //lights.push_back({glm::vec3(5, 5, -5), glm::vec3(200)});

    mat->sun.dir = glm::vec3(0, -1, 0);
    mat->sun.color = glm::vec3(1);

    mat->setLightSources(lights);

    Transform modelTransform;


    float camDis = 5.f;
    float xRot = 0.f;
    float yRot = 0.f;

    float deltaTime = 0;

    while(!window->shouldQuit()) {
        uint32_t ticks = SDL_GetTicks();
        // User input
        if (window->getKeyState(SDL_SCANCODE_A))
            yRot -= 2 * deltaTime * 45;
        if (window->getKeyState(SDL_SCANCODE_D))
            yRot += 2 * deltaTime * 45;
        if (window->getKeyState(SDL_SCANCODE_W))
            camDis = glm::max(0.f, camDis - 2 * deltaTime);
        if (window->getKeyState(SDL_SCANCODE_S))
            camDis = camDis + 2 * deltaTime;
        if (window->getKeyState(SDL_SCANCODE_UP))
            xRot += deltaTime * 45;
        if (window->getKeyState(SDL_SCANCODE_DOWN))
            xRot -= deltaTime * 45;

        if (window->getKeyState(SDL_SCANCODE_LEFT))
            mat->metallic = max(0.f, mat->metallic - 0.5f * deltaTime);
        if (window->getKeyState(SDL_SCANCODE_RIGHT))
            mat->metallic = min(1.f, mat->metallic + 0.5f * deltaTime);

        if (window->getKeyState(SDL_SCANCODE_Q))
            mat->roughness = max(0.f, mat->roughness - 0.5f * deltaTime);
        if (window->getKeyState(SDL_SCANCODE_E))
            mat->roughness = min(1.f, mat->roughness + 0.5f * deltaTime);

        glm::vec3 camPos = 
            glm::rotate(glm::mat4(1.f), glm::radians(yRot), glm::vec3(0, 1, 0)) *
            glm::rotate(glm::mat4(1.f), glm::radians(xRot), glm::vec3(1, 0, 0)) *
            glm::vec4(0, 0, camDis, 0);
        
        glm::mat4 view = glm::lookAt(camPos, glm::vec3(0), glm::vec3(0, 1, 0)) ;
        mat->setView(view);
        mat->setCamPos(camPos);

        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        mat->start();
        modelTransform.position = glm::vec3(0, -1, 0);
        modelTransform.scale = glm::vec3(1);
        modelTransform.rotation = glm::vec3(0);

        mat->renderModel(teapot, modelTransform);
        window->present();

        deltaTime = (SDL_GetTicks() - ticks) / 1000.f;
    }

    delete teapot;
    delete mat;

    return 0;
}
