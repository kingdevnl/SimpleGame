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
#include "test/test.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl2.h"
int main() {



	std::cout << "Setting up\n";

	Window window = Window();

	window.create();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(window.window, true);
	ImGui_ImplOpenGL2_Init();

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
		0, 1, 2
	};
	Mesh mesh(positions, indices);

	myShader.bind();


	float scale = 1;
	

	myShader.unbind();


	while (!window.isCloseRequested()) {
		window.clear();


		myShader.bind();
		mesh.draw();
		myShader.unbind();


		ImGui_ImplGlfw_NewFrame();
		ImGui_ImplOpenGL2_NewFrame();

		ImGui::NewFrame();
		ImGui::ShowDemoWindow((bool*)true);
		ImGui::EndFrame();

		ImGui::Render();
		ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

		window.update();

		
		
	}
	mesh.destroy();
	myShader.unbind();
	myShader.destroy();


}
