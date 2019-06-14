#pragma once

#include <GLFW/glfw3.h>
#pragma comment(lib,"opengl32.lib")



class Window
{
public:
	Window();
	void create();
	void show();
	void update();
	bool isCloseRequested();
	void clear();
	GLFWwindow* window;
};

