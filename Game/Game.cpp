// Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "../Engine/Shader.h"
#include "../Engine/Mesh.h"
#include "../Engine/Window.h"
#include <experimental/filesystem>
#include <Windows.h>
#include <cassert>


int main() {


	std::cout << "Setting up\n";

	Window window = Window();

	window.create();

	window.show();


	Shader myShader = Shader::load("./shaders/shader.vs", "./shaders/shader.fs");

	myShader.setup();

	int programID = myShader.getProgramID();

	std::cout << "programID " << programID << std::endl;


	std::vector<float> positions = {
		-1, -1, 0,
		1, -1, 0,
		0, 1, 0
	};

	std::vector<unsigned int> indices = {
		0,
		1,
		2
	};
	Mesh mesh(positions, indices);

	myShader.bind();

	GLint loc = glGetUniformLocation(myShader.getProgramID(), "u_Color");
	glUniform4f(loc, 0.2f, 0.3f, 0.8f, 1.0f);

	loc = glGetUniformLocation(myShader.getProgramID(), "u_Scale");

	float scale = 1;
	

	myShader.unbind();


	while (!window.isCloseRequested()) {
		window.clear();

		myShader.bind();
		mesh.draw();

	

		window.update();

		if(GetAsyncKeyState(VK_UP)) {
			scale+=.2;
		}
		if(GetAsyncKeyState(VK_DOWN)) {
			scale-=.2;
		}
		glUniform1f(loc, scale);
	}
	mesh.destroy();
	myShader.unbind();
	myShader.destroy();


}
