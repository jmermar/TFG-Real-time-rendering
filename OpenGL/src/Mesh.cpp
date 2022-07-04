#include "Mesh.hpp"
#include "MeshLoader.hpp"

Mesh::Mesh(vector<Vertex>& vertex, vector<unsigned int>& indices)
{
    generateData(vertex, indices);
}

Mesh::Mesh(string file) {
    vector<Vertex> v;
    vector<unsigned int> i;

    MeshLoader::loadMesh(file, v, i);

    loadVertex(file, v, i);
    generateData(v, i);
}

Mesh::~Mesh() {
    glad_glBindVertexArray(0);
    glad_glDeleteBuffers(1, &vbo);
    glad_glDeleteBuffers(1, &ebo);
    glad_glDeleteVertexArrays(1, &vao);
}


void Mesh::generateData(vector<Vertex>& vertex, vector<unsigned int>& indices)
{
    this->indices = indices;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertex.size() * sizeof(Vertex), &(vertex[0]), GL_STATIC_DRAW);

    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &(indices[0]), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) 0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) sizeof(glm::vec3));
    
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_TRUE, sizeof(Vertex), (void*) (sizeof(glm::vec3) + sizeof(glm::vec2)));
}

void Mesh::loadVertex(string file, vector<Vertex>& vout, vector<unsigned int>& iout) {

}

void Mesh::bind() {
    glBindVertexArray(vao);
}

int Mesh::getIndicesCount() {
    return indices.size();
}

unsigned int* Mesh::getIndicesData() {
    return &(indices[0]);
}