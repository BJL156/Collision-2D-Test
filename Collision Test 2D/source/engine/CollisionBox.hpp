#pragma once

#include <GLM/glm.hpp>

#include "Texture.hpp"
#include "Shader.hpp"
#include "Mesh.hpp"

class CollisionBox
{
public:
	CollisionBox(glm::vec4 meshAttributes);
	~CollisionBox() {}

	void UpdateCollision(glm::vec4 meshAttributes, float x = 0.0f, float y = 0.0f, float w = 0.0f, float h = 0.0f);
	void DrawCollision(glm::vec2 size, Shader& shader);

	bool IsCollidingBox(CollisionBox& box);
	bool IsColliding(Mesh& obj);

	Mesh mesh{0.0f, 0.0f, 0.0f, 0.0f};
private:
	void Update(glm::vec4& meshAttributes);

	float xoffset, yoffset;
	float woffset, hoffset;
};