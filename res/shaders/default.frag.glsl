#version 330

in vec2 vTexCoords;

out vec4 oColor;

uniform sampler2D uDiffuse;

void main()
{
    oColor = vec4(1.0, 0.0, 0.0, 1.0);
    oColor = texture(uDiffuse, vTexCoords);
}