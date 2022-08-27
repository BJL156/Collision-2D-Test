#include "Texture.hpp"

Texture::Texture(const char* filepath)
{
	CreateTexture(filepath);
}

Texture::~Texture()
{
	glDeleteTextures(1, &ID);
}

void Texture::Bind()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::CreateTexture(const char* filepath)
{
	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	int numberChannels;
	unsigned char* data = stbi_load(filepath, &width, &height, &numberChannels, 0);
	if (data == nullptr) {
		std::cout << "failed to load texture" << std::endl;
	}

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data);
}