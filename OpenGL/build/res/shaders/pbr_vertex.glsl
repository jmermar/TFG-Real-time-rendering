#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 2) in vec3 aNormal;
layout (location = 1) in vec2 aTexCoords;

out vec2 TexCoords;
out vec3 WorldPos;
out vec3 Normal;

uniform mat4 projMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

void main()
{
    TexCoords = aTexCoords;
    WorldPos = vec3(modelMatrix * vec4(aPos, 1.0));
    Normal = mat3(modelMatrix) * aNormal;   

    gl_Position =  projMatrix * viewMatrix * vec4(WorldPos, 1.0);
}