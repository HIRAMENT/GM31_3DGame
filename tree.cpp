#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "shader.h"
#include "resource.h"
#include "texture.h"
#include "polygon3D.h"
#include "shadow.h"
#include "scene.h"
#include "tree.h"

tree::tree(Scene * scene, D3DXVECTOR3 pos, D3DXVECTOR3 scale, int drawPriority)
	: GameObject(scene, ObjectType::eObTree, drawPriority)
{
	m_TreeUI = new Polygon3D(scene, pos, {scale.x, scale.y, 0.0f}, ResourceTag::tTree0, true, true, drawPriority);
	m_TreeUI->SetShaderType(ShaderType::UNLIT);
	m_Shadow = new Shadow(scene, { pos.x, 0.f,pos.z }, { 2.0f, 2.0f}, 1);

	scene->Add(this);
}

void tree::Uninit()
{
	m_TreeUI->SetDestroy();
	m_Shadow->SetDestroy();
}
