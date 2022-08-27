#pragma once

#include <GLAD/glad.h>
#include <GLM/glm.hpp>
#include <GLM/GTC/matrix_transform.hpp>

#include "Shader.hpp"
#include "Texture.hpp"

class Mesh
{
public:
	Mesh(float xpos = 0.0f, float ypos = 0.0f, float w = 0.0f, float h = 0.0f);
	~Mesh();

	void SetWireframeMode(bool value)
		{ wireFrame = true; }

	void Draw(glm::vec2 size, Texture& texture, Shader& shader);
	void DrawSolid(glm::vec2 size, Shader& shader);

	glm::vec4 GetMeshAttributes() { return glm::vec4(x, y, width, height); }

	float x = 0.0f;
	float y = 0.0f;
	float width = 0.0f;
	float height = 0.0f;
private:
	void CreateObjects();

	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;

	bool wireFrame = false;
};