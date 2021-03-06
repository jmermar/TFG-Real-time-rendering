#pragma once 
#include <string>
#include <vector>
#include <glm/glm.hpp>

using namespace std;

struct Pixel {
    unsigned char r, g, b;
};

struct Texture {
    int width, height;
    vector<Pixel> data;
};

Texture loadTexture(string file);