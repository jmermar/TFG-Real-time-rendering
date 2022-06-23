#include "Shader.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

Shader::Shader(string vertex, string fragment) {
    GLuint vertexObject, fragmentObject;

    vertexObject = loadProgram(GL_VERTEX_SHADER, vertex);
    fragmentObject = loadProgram(GL_FRAGMENT_SHADER, fragment);

    program = glCreateProgram();

    glAttachShader(program, vertexObject);
    glAttachShader(program, fragmentObject);

    glLinkProgram(program);

    GLint linked;
    glGetProgramiv(program, GL_LINK_STATUS, &linked);

    if (!linked) {
        cerr << "No se pudo crear el Shader Program a partir de \"" << vertex << "\" y \"" << fragment << "\"" << endl;
    
        char* buffer = new char[2048];
        GLsizei length;
        glGetProgramInfoLog(program, 2048, &length, buffer);

        cerr << buffer << endl;

        exit(-1);
    }

    glDeleteShader(vertexObject);
    glDeleteShader(fragmentObject);
}


Shader::~Shader() {
    glDeleteProgram(program);
}

GLuint Shader::loadProgram(GLenum type, string source) {
    std::ifstream ifs(source);
    std::string sourceData((std::istreambuf_iterator<char>(ifs)),
        (std::istreambuf_iterator<char>()));
    const char* src = sourceData.c_str();

    GLuint shader = glCreateShader(type);

    glShaderSource(shader, 1, &(src), NULL);

    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        cerr << "No se pudo compilar el shader \"" << source << "\"" << endl;

        char* buffer = new char[2048];
        GLsizei length;
        glGetShaderInfoLog(shader, 2048, &length, buffer);

        cerr << buffer << endl;
        exit(-1);
    }

    return shader;
}

GLuint Shader::getProgram() {
    return program;
}