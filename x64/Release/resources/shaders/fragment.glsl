#version 330 core

out vec4 outColor;

in vec2 texturePosition;

uniform sampler2D image;

void main()
{
	outColor = texture(image, texturePosition);
}