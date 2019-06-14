#include "stdafx.h"

#include <gl/glew.h>
#include "Window.h"


Window::Window() {
	std::cout << "Window();" << std::endl;
}


void Window::create() {
	std::cout << "Window.create();" << std::endl;
	if (!glfwInit()) {
		std::cerr << "Failed to init glfw!" << std::endl;
		exit(1);
	}

	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	this->window = glfwCreateWindow(1080, 720, "Game", 0, 0);

	glfwMakeContextCurrent(this->window);
	const GLenum err = glewInit();

	if (GLEW_OK != err)
	{
		std::cout << "GLEW Error: " << glewGetErrorString(err) << std::endl;
		exit(1);
	}
}

void Window::show() {
	glfwShowWindow(this->window);
	
}

bool Window::isCloseRequested() {
	return glfwWindowShouldClose(this->window);
}

void Window::clear() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}

void Window::update() {

	glfwSwapBuffers(window);
	glfwPollEvents();
}
