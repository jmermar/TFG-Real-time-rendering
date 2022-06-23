#pragma once
#include <glad/glad.h>

#include <string>

using namespace std;

class Texture {
private:
    GLuint id;
public:
    Texture(string source);
    ~Texture();

    GLuint getId();
};