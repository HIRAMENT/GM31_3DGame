#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "scene.h"
#include "titleCamera.h"

TitleCamera::TitleCamera(Scene * scene, D3DXVECTOR3 pos, int drawpriority)
	: Camera(scene, pos, drawpriority)
{
	scene->Add(this);
}

void TitleCamera::Update()
{
}
