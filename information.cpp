#include "main.h"
#include "information.h"
#include "ImGUI/imgui.h"
#include <Psapi.h>
#include <Pdh.h>

#pragma comment(lib, "pdh.lib")

float Information::GetFPS() const
{
	return ImGui::GetIO().Framerate;
}

float Information::GetMemory() const
{
	HANDLE hProc = GetCurrentProcess();
	PROCESS_MEMORY_COUNTERS_EX pmc;
	BOOL isSuccess = GetProcessMemoryInfo(
		hProc,
		(PROCESS_MEMORY_COUNTERS*)&pmc,
		sizeof(pmc));
	CloseHandle(hProc);

	return pmc.WorkingSetSize;
}

float Information::GetCPU() const
{

	return 0.0f;
}

void Information::Display()
{
	ImGui::SetNextWindowSize(ImVec2(150, 75), ImGuiCond_Once);
	ImGui::Begin("Information");

	ImGui::Text("FPS"); ImGui::SameLine();
	ImGui::Text("%f", GetFPS());

	ImGui::Text("MEMORY"); ImGui::SameLine();
	ImGui::Text("%f", GetMemory());

	ImGui::End();
}
