#include "MaterialTextured.hpp"
#include <glm/ext.hpp>
#include <iostream>

MaterialTextured::MaterialTextured(string texFolder) {
    program = new Shader("res/shaders/texturedPbr_vertex.glsl", "res/shaders/texturedPbr_fragment.glsl");
    
    albedo = new Texture(texFolder + "/albedo.png");
    normal = new Texture(texFolder + "/normal.png");
    metallic = new Texture(texFolder + "/metallic.png");
    roughness = new Texture(texFolder + "/roughness.png");
    ao = new Texture(texFolder + "/ao.png");

    GLuint programId = program->getProgram();

    modelLocation = glGetUniformLocation(programId, "modelMatrix");
    viewLocation = glGetUniformLocation(programId, "viewMatrix");
    projLocation = glGetUniformLocation(programId, "projMatrix");
    camPosLocation = glGetUniformLocation(programId, "camPos");


    for(int i = 0; i < 4; i++) {
        lightPositions[i] = glGetUniformLocation(programId, ("lightPositions[" + std::to_string(i) + "]").c_str());
        lightColors[i] = glGetUniformLocation(programId, ("lightColors[" + std::to_string(i) + "]").c_str());
    }
}

MaterialTextured::~MaterialTextured() {
    delete albedo;
    delete normal;
    delete metallic;
    delete roughness;

    delete program;
}

void MaterialTextured::setProj(glm::mat4& proj) {
    this->proj = proj;
}

void MaterialTextured::setView(glm::mat4& view) {
    this->view = view;
}

void MaterialTextured::setCamPos(glm::vec3 camPos) {
    this->camPos = camPos;
}

void MaterialTextured::setLightSources(vector<LightSource>& lights) {
    this->lights = lights;
    // Nos quedamos con las 4 primeras luces
    if (this->lights.size() > 4) this->lights.resize(4);
}


void MaterialTextured::start() {
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);


    glUseProgram(program->getProgram());
    
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, albedo->getId());
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, normal->getId());
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, metallic->getId());
    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, roughness->getId());
    glActiveTexture(GL_TEXTURE4);
    glBindTexture(GL_TEXTURE_2D, ao->getId());

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

void MaterialTextured::renderModel(Mesh* mesh, Transform& model) {
    glm::mat4 modelMatrix = glm::scale(glm::mat4(1), model.scale);
    
    modelMatrix = glm::rotate(modelMatrix, glm::radians(model.rotation.y), glm::vec3(0, 1, 0));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(model.rotation.x), glm::vec3(1, 0, 0));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(model.rotation.z), glm::vec3(0, 0, 1));

    modelMatrix = glm::translate(modelMatrix, model.position);


    glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    mesh->bind();
    glDrawElements(GL_TRIANGLES, mesh->getIndicesCount(), GL_UNSIGNED_INT, NULL);
}