#pragma once
#include <glad/glad.h>

#include <glm/glm.hpp>

#include <vector>
#include <string>

#include "Structs.hpp"

using namespace std;

class Mesh {
private:
    unsigned int vao;
    unsigned int ebo;
    unsigned int vbo;

    vector<unsigned int> indices;

    void generateData(vector<Vertex>& vertex, vector<unsigned int>& indices);
    void loadVertex(string file, vector<Vertex>& vout, vector<unsigned int>& iout);
public:
    Mesh(vector<Vertex>& vertex, vector<unsigned int>& indices);
    Mesh(string file);
    ~Mesh();

    void bind();
    int getIndicesCount();
    unsigned int* getIndicesData();
};