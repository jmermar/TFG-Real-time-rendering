#version 330 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec2 vTex;
layout (location = 2) in vec3 vNorm;
layout (location = 3) in vec3 vTangent;
layout (location = 4) in vec3 vBitangent;

out vec2 TexCoords;
out mat3 TBN;
out vec3 WorldPos;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projMatrix;

void main()
{
    WorldPos = vec3(modelMatrix * vec4(vPos, 1.0));
    TexCoords = vTex;

    vec3 T = normalize(vec3(modelMatrix * vec4(vTangent, 0.0)));
    vec3 B = normalize(vec3(modelMatrix * vec4(vBitangent, 0.0)));
    vec3 N = normalize(vec3(modelMatrix * vec4(vNorm, 0.0)));
    TBN = mat3(T, B, N);

    gl_Position = projMatrix * viewMatrix * modelMatrix * vec4(vPos, 1.0);
}