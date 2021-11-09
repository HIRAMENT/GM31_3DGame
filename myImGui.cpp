#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "ImGUI/imgui.h"
#include "ImGUI/imgui_impl_dx11.h"
#include "ImGUI/imgui_impl_win32.h"
#include "myImGui.h"

void MyImGui::Init()
{
	// ImGUI�̃Z�b�e�B���O
//IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	ImGui_ImplDX11_Init(Renderer::GetInstance()->GetDevice(), Renderer::GetInstance()->GetDeviceContext());
	ImGui_ImplWin32_Init(GetWindow());
	ImGui::StyleColorsDark();
}

void MyImGui::UpdateStart()
{
	// �t���[���̐���
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
}

void MyImGui::UpdateEnd()
{
	ImGui::EndFrame();
}

void MyImGui::Draw()
{
	// �`�揈��
	ImGui::Render();
	// �`�悷��f�[�^
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}

void MyImGui::Uninit()
{
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}


