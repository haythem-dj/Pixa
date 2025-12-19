#version 330

in vec2 vTexCoords;
in vec4 vColor;

out vec4 oColor;

uniform sampler2D uDiffuse;

void main()
{
    oColor = texture(uDiffuse, vTexCoords);
}