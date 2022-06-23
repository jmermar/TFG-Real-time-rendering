#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <iostream>

#include "Window.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"
#include "Shader.hpp"

using namespace std;

const int Width = 1280;
const int Height = 720;

int main(int argc, char** argv) {
    Window* window = new Window(Width, Height);

    glm::mat4 p = glm::perspectiveFov(90.f, (float)Width, (float)Height, 0.1f, 1000.f);
    
    Shader* shader = new Shader("res/shaders/unlit_vertex.glsl", "res/shaders/unlit_fragment.glsl");
    Texture* tex = new Texture("res/textures/vikingroom_tex.png");
    Mesh* mesh = new Mesh("res/models/vikingroom.obj");
    GLuint mvpMatrixUniform = glGetUniformLocation(shader->getProgram(), "mvpMatrix");



    float camDis = 5.f;
    float xRot = 0.f;
    float yRot = 0.f;

    float deltaTime = 0;

    while(!window->shouldQuit()) {
        uint32_t ticks = SDL_GetTicks();
        // User input
        if (window->getKeyState(SDL_SCANCODE_A))
            yRot -= deltaTime * 45;
        if (window->getKeyState(SDL_SCANCODE_D))
            yRot += deltaTime * 45;
        if (window->getKeyState(SDL_SCANCODE_W))
            camDis = glm::max(0.f, camDis - deltaTime);
        if (window->getKeyState(SDL_SCANCODE_S))
            camDis = camDis + deltaTime;
        if (window->getKeyState(SDL_SCANCODE_UP))
            xRot += deltaTime * 45;
        if (window->getKeyState(SDL_SCANCODE_DOWN))
            xRot -= deltaTime * 45;

        glm::vec3 camPos = 
            glm::rotate(glm::mat4(1.f), glm::radians(yRot), glm::vec3(0, 1, 0)) *
            glm::rotate(glm::mat4(1.f), glm::radians(xRot), glm::vec3(1, 0, 0)) *
            glm::vec4(0, 0, camDis, 0);
        
        glm::mat4 mvp = p * glm::lookAt(camPos, glm::vec3(0), glm::vec3(0, 1, 0)) ;

        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(shader->getProgram());
        glBindTexture(GL_TEXTURE_2D, tex->getId());

        glUniformMatrix4fv(mvpMatrixUniform, 1, GL_FALSE, glm::value_ptr(mvp));

        int numIndices = mesh->getIndicesCount();

        mesh->bind();

        glDrawElements(GL_TRIANGLES, mesh->getIndicesCount(), GL_UNSIGNED_INT, NULL);

        window->present();

        deltaTime = (SDL_GetTicks() - ticks) / 1000.f;
    }

    delete mesh;
    delete tex;
    delete shader;


    delete window;

    return 0;
}
