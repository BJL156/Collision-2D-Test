#pragma once

#include "Mesh.hpp"

class Entity
{
public:
	Entity();
	~Entity();

	void Draw();
private:
	Mesh* mesh;
};