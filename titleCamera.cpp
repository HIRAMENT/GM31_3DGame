#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "scene.h"
#include "titleCamera.h"

TitleCamera::TitleCamera(Scene * scene, D3DXVECTOR3 pos, int drawpriority)
	: Camera(scene, pos, drawpriority)
{
	scene->Add(this);
}
