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

#include "HUD.h"
#include "../Engine/Texture.h"

int main() {

	HUD hud = HUD();

	std::cout << "Setting up\n";

	Window window = Window();

	window.create();
	hud.setupHUD(window.window);

	window.show();

	Texture brickTexture("./textures/brick.png");


	Shader myShader = Shader::load("./shaders/vertex.fs", "./shaders/fragment.fs");

	myShader.setup();

	int programID = myShader.getProgramID();

	std::cout << "programID " << programID << std::endl;


	std::vector<float> positions = {
		-1, -1, 0,
		1, -1, 0,
		0, 1, 0,


	};

	std::vector<unsigned int> indices = {
		0, 1, 2
	};
	std::vector<float> textCoords = {
		0, 1,
		1, 1,
		1, 0,
		0, 0
	};

	
	Mesh mesh(positions, indices, textCoords, &brickTexture);

	myShader.bind();
	GLuint loc = glGetUniformLocation(myShader.getProgramID(), "texture_sampler");
	std::cout << "loc: " << loc << std::endl;
	glUniform1i(loc, 0);

	myShader.unbind();


	while (!window.isCloseRequested()) {
		window.clear();


		myShader.bind();
		mesh.draw();
		myShader.unbind();
		hud.drawHUD();


		window.update();


	}

	mesh.destroy();
	brickTexture.destory();
	myShader.unbind();
	myShader.destroy();


}
