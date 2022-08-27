#include "Window.hpp"

Window::Window(int w, int h, const char* t)
	: width(w), height(h), title(t)
{
	CreateWindow();
}

Window::~Window()
{
	glfwDestroyWindow(window);

	glfwTerminate();
}

void Window::Update()
{
	glfwSwapBuffers(window);
	glfwPollEvents();

	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::CreateWindow()
{
	if (glfwInit() == GLFW_FALSE) {
		std::cout << "failed to intialize GLFW" << std::endl;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (window == nullptr) {
		std::cout << "failed to create GLFW window" << std::endl;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "failed to initialize GLAD" << std::endl;
	}
}