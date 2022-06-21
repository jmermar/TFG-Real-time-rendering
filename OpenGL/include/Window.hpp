#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;
class Window {
private:
    SDL_Window* win;

    const unsigned char* keys;

    int width, height;
public:
    Window(int w, int h);
    ~Window();

    bool getKeyState(int key);
    bool shouldQuit();

    int getWidth();
    int getHeight();

    void present();
};