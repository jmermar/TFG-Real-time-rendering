#include "Material.hpp"
#include <glm/ext.hpp>
#include <iostream>

Material::Material(glm::vec3 a, float m, float r, float _ao) {
    program = new Shader("res/shaders/pbr_vertex.glsl", "res/shaders/pbr_fragment.glsl");

    albedo = a;
    metallic = m;
    roughness = r;
    ao = _ao;

    GLuint programId = program->getProgram();

    materialLocation[0] = glGetUniformLocation(programId, "albedo");
    materialLocation[1] = glGetUniformLocation(programId, "metallic");
    materialLocation[2] = glGetUniformLocation(programId, "roughness");
    materialLocation[3] = glGetUniformLocation(programId, "ao");

    modelLocation = glGetUniformLocation(programId, "modelMatrix");
    viewLocation = glGetUniformLocation(programId, "viewMatrix");
    projLocation = glGetUniformLocation(programId, "projMatrix");
    camPosLocation = glGetUniformLocation(programId, "camPos");


    for(int i = 0; i < 4; i++) {
        lightPositions[i] = glGetUniformLocation(programId, ("lightPositions[" + std::to_string(i) + "]").c_str());
        lightColors[i] = glGetUniformLocation(programId, ("lightColors[" + std::to_string(i) + "]").c_str());
    }
}

Material::~Material() {
    delete program;
}

void Material::setProj(glm::mat4& proj) {
    this->proj = proj;
}

void Material::setView(glm::mat4& view) {
    this->view = view;
}

void Material::setCamPos(glm::vec3 camPos) {
    this->camPos = camPos;
}

void Material::setLightSources(vector<LightSource>& lights) {
    this->lights = lights;
    // Nos quedamos con las 4 primeras luces
    if (this->lights.size() > 4) this->lights.resize(4);
}


void Material::start() {
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);


    glUseProgram(program->getProgram());
    
    
    glUniform3fv(materialLocation[0], 1, glm::value_ptr(albedo));
    glUniform1f(materialLocation[1], metallic);
    glUniform1f(materialLocation[2], roughness);
    glUniform1f(materialLocation[3], ao);

    glUniformMatrix4fv(projLocation, 1, GL_FALSE, glm::value_ptr(proj));
    glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));

    glUniform3fv(camPosLocation, 1, glm::value_ptr(camPos));


    for(int i = 0; i < 4; i++) {
        if (i < lights.size()) {
            glUniform3fv(lightPositions[i], 1, glm::value_ptr(lights[i].position));
            glUniform3fv(lightColors[i], 1, glm::value_ptr(lights[i].color));
        } else {
            glUniform3f(lightColors[i], 0, 0, 0);
        }
    }
}

void Material::renderModel(Mesh* mesh, Transform& model) {
    glm::mat4 modelMatrix = glm::scale(glm::mat4(1), model.scale);
    
    modelMatrix = glm::rotate(modelMatrix, glm::radians(model.rotation.y), glm::vec3(0, 1, 0));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(model.rotation.x), glm::vec3(1, 0, 0));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(model.rotation.z), glm::vec3(0, 0, 1));

    modelMatrix = glm::translate(modelMatrix, model.position);


    glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    mesh->bind();
    glDrawElements(GL_TRIANGLES, mesh->getIndicesCount(), GL_UNSIGNED_INT, NULL);
}