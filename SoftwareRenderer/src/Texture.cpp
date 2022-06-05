#include "Texture.hpp"
#include <SDL2/SDL_image.h>
#include <iostream>

Texture loadTexture(string source) {
    SDL_Surface* s = IMG_Load(source.c_str());
    if (!s) {
        cerr << "No se pudo cargar la imagen: " << source << endl;
        exit(1);
    }
    Texture ret;
    ret.width = s->w;
    ret.height = s->h;

    ret.data.resize(s->w * s->h);

    SDL_Surface* converted = SDL_ConvertSurfaceFormat(s, SDL_PIXELFORMAT_RGBA8888, 0);
    SDL_FreeSurface(s);
    for(int y = 0; y < s->h; y++) {
        for(int x = 0; x < s->w; x++) {
            char* pixel = ((char*)converted->pixels) + converted->pitch * y + x * 4;
            Pixel& texPix = ret.data[y * ret.width + x];
            texPix.r = pixel[3];
            texPix.g = pixel[2];
            texPix.b = pixel[1];
        }
    }

    return ret;
}