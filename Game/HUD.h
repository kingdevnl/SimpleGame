#pragma once
#include <GLFW/glfw3.h>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl2.h>

class HUD {
private:
	const float DISTANCE = 10.0f;
	const int corner = 0;
public:
	HUD() {}

	inline void setupHUD(GLFWwindow* window) {
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		(void)io;
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL2_Init();
		ImGui::StyleColorsDark();

		std::cout << "ImGui loaded.\n";


	}

	inline void drawHUD() {


		ImGuiIO& io = ImGui::GetIO();

		ImGui_ImplOpenGL2_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImVec2 window_pos = ImVec2((corner & 1) ? io.DisplaySize.x - DISTANCE : DISTANCE,
		                           (corner & 2) ? io.DisplaySize.y - DISTANCE : DISTANCE);
		ImVec2 window_pos_pivot = ImVec2((corner & 1) ? 1.0f : 0.0f, (corner & 2) ? 1.0f : 0.0f);
		ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always, window_pos_pivot);
		ImGui::SetNextWindowBgAlpha(0.35f);


		ImGui::Begin("Hud", (bool*)true, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDecoration);
		float color;
		
		ImGui::Text("SimpleGame");
		ImGui::End();
		ImGui::EndFrame();

		ImGui::Render();
		ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

	}

};
