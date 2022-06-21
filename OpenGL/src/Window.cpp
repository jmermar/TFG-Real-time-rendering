#include "Window.hpp"
#include <iostream>
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
}

Window::~Window() {
    SDL_DestroyWindow(win);
    IMG_Quit();
    SDL_Quit();
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
    
}