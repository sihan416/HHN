#version 330 core

layout(location = 0) in vec2 Position;
layout(location = 1) in vec2 TexCoord;
layout(location = 2) in vec4 Color;

out vec2 texCoord;
out vec4 color;

void main()
{
	gl_Position = vec4(Position, -1.0, 1.0);
	texCoord = TexCoord;
	color = Color;
}