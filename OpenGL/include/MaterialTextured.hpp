#pragma once
#include "Structs.hpp"
#include "Shader.hpp"
#include <glm/glm.hpp>
#include "Texture.hpp"
#include "Mesh.hpp"
#include <vector>

class MaterialTextured {
private:
    Texture* albedo;
    Texture* normal;
    Texture* metallic;
    Texture* roughness;
    Texture* ao;

    Shader* program;

    vector<LightSource> lights;

    GLint lightPositions[4];
    GLint lightColors[4];

    GLint modelLocation, projLocation, viewLocation;
    GLint camPosLocation;

    glm::vec3 camPos;
    glm::mat4 proj, view;
public:
    MaterialTextured(string texture);
    ~MaterialTextured();

    void setProj(glm::mat4& proj);
    void setView(glm::mat4& view);
    void setCamPos(glm::vec3 camPos);

    void setLightSources(vector<LightSource>& lights);

    void renderModel(Mesh* mesh, Transform& model);

    void start();
};