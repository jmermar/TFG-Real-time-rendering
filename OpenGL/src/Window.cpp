#include "Window.hpp"

#include <iostream>

#include <glad/glad.h>

Window::Window(int w, int h) {
    width = w;
    height = h;

    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
    win = SDL_CreateWindow("Hardware rasterizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_OPENGL);
    if (win == nullptr) {
        cerr << "No se pudo crear la ventana"  << SDL_GetError() << endl;
        exit(-1);
    }

    if (!loadContext()) {
        cerr << "No se pudo crear el OpenGL context" << endl;
        exit(-1);
    }
}

Window::~Window() {
    SDL_DestroyWindow(win);
    IMG_Quit();
    SDL_Quit();
}

bool Window::loadContext() {
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    context = SDL_GL_CreateContext(win);
    if (context == NULL) return false;

    if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress)) {
        SDL_GL_DeleteContext(context);
        return false;
    }

    glEnable(GL_DEPTH_TEST);

    return true;
}

bool Window::getKeyState(int key) {
    return keys[key];
}

bool Window::shouldQuit() {
    SDL_Event ev;
    bool should = false;
    while(SDL_PollEvent(&ev)) {
        switch (ev.type) {
        case SDL_QUIT:
            should = true;
            break;
        }
    }

    keys = SDL_GetKeyboardState(nullptr);
    return should;
}

int Window::getWidth() {
    return width;
}

int Window::getHeight() {
    return height;
}

void Window::present() {
    SDL_GL_SwapWindow(win);
}