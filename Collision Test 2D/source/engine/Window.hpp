#pragma once

#include <GLAD/glad.h> // include GLAD BEFORE GLFW
#include <GLFW/glfw3.h>
#include <GLM/glm.hpp>

#include <iostream>

class Window
{
public:
	Window(int w, int h, const char* t);
	~Window();

	void Update();

	bool ShouldClose() { return glfwWindowShouldClose(window); }

	GLFWwindow* GetWindow() { return window; }
	glm::vec2 GetSize() { return glm::vec2(width, height); }
private:
	void CreateWindow();

	GLFWwindow* window;
	int width, height;
	const char* title;
};