#pragma once 
#include <glm/glm.hpp>
#include <vector>
#include <string>

using namespace std;

struct Vertex {
    glm::vec3 pos;
    glm::vec2 uv;
};

struct Triangle {
    Vertex a, b, c;
};

struct Mesh {
    vector<Triangle> triangles;
};

Mesh loadMesh(string file, bool ccw = true);