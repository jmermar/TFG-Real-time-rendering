#pragma once
#include "Structs.hpp"
#include "Shader.hpp"
#include <glm/glm.hpp>
#include "Texture.hpp"
#include "Mesh.hpp"
#include <vector>

class Material {
private:
    Shader* program;

    glm::vec3 albedo;
    float metallic;
    float roughness;
    float ao;

    vector<LightSource> lights;

    GLint lightPositions[4];
    GLint lightColors[4];

    GLint modelLocation, projLocation, viewLocation;
    GLint camPosLocation;

    GLint materialLocation[4];

    glm::vec3 camPos;
    glm::mat4 proj, view;
public:
    Material(glm::vec3 a, float m, float r, float _ao);
    ~Material();

    void setProj(glm::mat4& proj);
    void setView(glm::mat4& view);
    void setCamPos(glm::vec3 camPos);

    void setLightSources(vector<LightSource>& lights);

    void renderModel(Mesh* mesh, Transform& model);

    void start();
};