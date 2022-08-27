#pragma once

#include <GLAD/glad.h>
#include <STB/stb_image.h>

#include <iostream>

class Texture
{
public:
	Texture(const char* filepath);
	~Texture();

	void Bind();

	int width, height;
private:
	void CreateTexture(const char* filepath);

	unsigned int ID;
};