// Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "../Engine/Shader.h"
#include "../Engine/Mesh.h"
#include "../Engine/Window.h"
#include <experimental/filesystem>
#include <Windows.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "HUD.h"
#include "../Engine/Texture.h"

int main() {


	HUD hud = HUD();

	std::cout << "Setting up\n";

	Window window = Window();

	window.create();
	hud.setupHUD(window.window);

	window.show();

	Texture brickTexture("./res/textures/brick.png");


	Shader myShader = Shader::load("./res/shaders/vertex.fs", "./res/shaders/fragment.fs");

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

	glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);


	Mesh mesh(positions, indices, textCoords, &brickTexture);


	myShader.bind();
	myShader.setUniform1f("texture_sampler", 0);
	myShader.setUniformMat4f("MVP", proj);


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
