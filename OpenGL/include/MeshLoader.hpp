#pragma once

#include "Mesh.hpp"

namespace MeshLoader {
    void loadMesh(string name, vector<Vertex>& vertices, vector<GLuint>& indices);
};