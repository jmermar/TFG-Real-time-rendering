#version 330 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec2 vTex;
layout (location = 2) in vec2 vNorm;

out vec2 fTex;

uniform mat4 mvpMatrix;

void main()
{
    gl_Position = mvpMatrix * vec4(vPos, 1.0);
    fTex = vTex;
}