#include "ENGINE/Engine.hpp"

#include "Player.hpp"

#include <iostream>

int main()
{
	Window window(800, 600, "collision 2d opengl");
	Shader shader("resources/shaders/vertex.glsl", "resources/shaders/fragment.glsl");
	Shader collShader("resources/shaders/collisionVertex.glsl", "resources/shaders/collisionFragment.glsl");

	Mesh obj(0.0f, 200.0f, 100.0f, 100.0f);
	CollisionBox objBox(obj.GetMeshAttributes());

	Texture texture("resources/textures/chicken.png");

	Player plyr;

	int collCounter = 0;

	while (!window.ShouldClose()) {
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		window.Update();

		double xpos, ypos;
		glfwGetCursorPos(window.GetWindow(), &xpos, &ypos);
		obj.x = xpos - obj.width / 2;
		obj.y = ypos - obj.height / 2;

		if (objBox.IsCollidingBox(plyr.head) || objBox.IsCollidingBox(plyr.hand)
			|| objBox.IsCollidingBox(plyr.upperarm) || objBox.IsCollidingBox(plyr.body)
			|| objBox.IsCollidingBox(plyr.thigh) || objBox.IsCollidingBox(plyr.calf)
			|| objBox.IsCollidingBox(plyr.boot) || objBox.IsCollidingBox(plyr.feet)) {
			collCounter++;
			std::cout << "colliding with collision box (" << collCounter << ")" << std::endl;
		}

		plyr.Draw(window.GetSize(), shader, collShader);

		obj.Draw(window.GetSize(), texture, shader);
		objBox.UpdateCollision(obj.GetMeshAttributes(), 0.0f, 0.0f, 0.0f, 0.0f);
		// objBox.DrawCollision(window.GetSize(), collShader);
	}
}