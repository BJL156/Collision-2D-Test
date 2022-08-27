#include "CollisionBox.hpp"

CollisionBox::CollisionBox(glm::vec4 meshAttributes)
{
	Update(meshAttributes);
}

void CollisionBox::UpdateCollision(glm::vec4 meshAttributes, float x, float y, float w, float h)
{
	xoffset = x;
	yoffset = y;
	woffset = w;
	hoffset = h;
	Update(meshAttributes);
}

void CollisionBox::DrawCollision(glm::vec2 size, Shader& shader)
{
	mesh.DrawSolid(size, shader);
}

bool CollisionBox::IsCollidingBox(CollisionBox& box)
{
	return mesh.x + mesh.width > box.mesh.x && mesh.x < box.mesh.x + box.mesh.width
		&& mesh.y + mesh.height > box.mesh.y && mesh.y < box.mesh.y + box.mesh.height;
}

bool CollisionBox::IsColliding(Mesh& obj)
{
	return mesh.x+ mesh.width > obj.x && mesh.x < obj.x + obj.width
		&& mesh.y + mesh.height > obj.y && mesh.y < obj.y + obj.height;
}

void CollisionBox::Update(glm::vec4& meshAttributes)
{
	mesh.x = meshAttributes.x + xoffset;
	mesh.y = meshAttributes.y + yoffset;
	mesh.width = meshAttributes.z + woffset;
	mesh.height = meshAttributes.w + hoffset;
}