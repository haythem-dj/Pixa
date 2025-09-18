#version 330

layout (location = 0) in vec2 iPosition;
layout (location = 1) in vec2 iTexCoords;
layout (location = 2) in vec4 iColor;

out vec2 vTexCoords;
out vec4 vColor;

uniform mat4 uProjection;
uniform mat4 uView;

void main()
{
    vTexCoords = iTexCoords;
    vColor = iColor;
    gl_Position = uProjection * uView * vec4(iPosition, 0.0, 1.0);
}