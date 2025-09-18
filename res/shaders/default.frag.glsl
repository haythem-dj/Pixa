#version 330

in vec2 vTexCoords;
in vec4 vColor;

out vec4 oColor;

uniform int uTex = 0;
uniform sampler2D uDiffuse;

void main()
{
    if (uTex == 1) oColor = texture(uDiffuse, vTexCoords);
    else oColor = vColor;
}