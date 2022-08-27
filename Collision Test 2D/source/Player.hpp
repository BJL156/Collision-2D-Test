#pragma once

#include "ENGINE/Engine.hpp"

class Player
{
public:
	Player()
	{
		body.UpdateCollision(mesh.GetMeshAttributes());
	}

	void Draw(glm::vec2 size, Shader& shader, Shader& collShader)
	{
		mesh.y = size.y - texture.height * 5;

		mesh.Draw(size, texture, shader);

		head.UpdateCollision(glm::vec4(mesh.x + 110.0f, mesh.y + 5.0f, 35.0f, 35.0f));
		// head.DrawCollision(size, collShader);

		body.UpdateCollision(glm::vec4(mesh.x + 120.0f, mesh.y + 50.0f, 50.0f, 100.0f));
		// body.DrawCollision(size, collShader);

		feet.UpdateCollision(glm::vec4(mesh.x + 45.0f, mesh.y + mesh.height - 30.0f, 250.0f, 30.0f));
		// feet.DrawCollision(size, collShader);

		boot.UpdateCollision(glm::vec4(mesh.x + 45.0f, mesh.y + mesh.height - 60.0f, 200.0f, 30.0f));
		// boot.DrawCollision(size, collShader);

		calf.UpdateCollision(glm::vec4(mesh.x + 45.0f, mesh.y + mesh.height - 90.0f, 200.0f, 30.0f));
		// calf.DrawCollision(size, collShader);

		thigh.UpdateCollision(glm::vec4(mesh.x + 45.0f, mesh.y + mesh.height - 120.0f, 190.0f, 30.0f));
		// thigh.DrawCollision(size, collShader);

		upperarm.UpdateCollision(glm::vec4(mesh.x + 45.0f, mesh.y + 40.0f, 90.0f, 30.0f));
		// upperarm.DrawCollision(size, collShader);

		hand.UpdateCollision(glm::vec4(mesh.x, mesh.y, 50.0f, 50.0f));
		// hand.DrawCollision(size, collShader);
	}

	Texture texture{"resources/textures/chun_li.png"};
	Mesh mesh{100.0f, 0.0f, texture.width * 5, texture.height * 5};

	CollisionBox head{mesh.GetMeshAttributes()};
	CollisionBox hand{mesh.GetMeshAttributes()};
	CollisionBox upperarm{mesh.GetMeshAttributes()};
	CollisionBox body{mesh.GetMeshAttributes()};
	CollisionBox thigh{mesh.GetMeshAttributes()};
	CollisionBox calf{mesh.GetMeshAttributes()};
	CollisionBox boot{mesh.GetMeshAttributes()};
	CollisionBox feet{mesh.GetMeshAttributes()};
};