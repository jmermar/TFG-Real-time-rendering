#version 330 core
out vec4 outColor;
  
in vec2 fTex;

uniform sampler2D colorTexture;

void main()
{
    outColor = texture(colorTexture, fTex);
}