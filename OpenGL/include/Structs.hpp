#pragma once
#include <vector>
#include <glm/glm.hpp>

struct LightSource {
    glm::vec3 position;
    glm::vec3 color;
};

struct Sun {
    glm::vec3 dir;
    glm::vec3 color;
};

struct Transform {
    glm::vec3 position, rotation, scale;
};

struct Vertex {
    glm::vec3 pos;
    glm::vec2 uv;
    glm::vec3 norm;
    glm::vec3 tangent;
    glm::vec3 bitangent;
};