#version 330 core

in vec2 vertexPosition;

out vec4 vertexPos;

void main()
{
	vertexPos = vec4(vertexPosition, 0.0f, 1.0f);
}