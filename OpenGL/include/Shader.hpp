#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>

using namespace std;

class Shader {
private:
    GLuint program;

    GLuint loadProgram(GLenum type, string source);
public:
    Shader(string vertex, string fragment);
    ~Shader();

    GLuint getProgram();
};