#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "shader.h"
#include "model.h"
#include "rock.h"
#include "scene.h"
#include "shadow.h"
#include "obb.h"


Rock::Rock(Scene * scene, D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scale, int drawPriority)
	: GameObject(scene, ObjectType::eObRock, drawPriority)
{
	SetPosition(pos);
	SetRotation(rot);
	SetScale(scale);

	m_Obb = new OBB(m_Position, {1.5f * scale.x,1.5f* scale.y,1.5f* scale.z }, m_Rotation);
	m_Shadow = new Shadow(scene, { pos.x, 0.f,pos.z }, { 1.0f * scale.x,1.0f * scale.z }, 2);

	scene->Add(this);
}

void Rock::Init()
{
}

void Rock::Uninit()
{
}

void Rock::Update()
{
}

void Rock::Draw()
{
	// 入力レイアウト設定 fvfs
	Renderer::GetInstance()->GetDeviceContext()->IASetInputLayout(Shader::GetInstance()->GetVertexLayputLighting());

	// シェーダー設定
	Renderer::GetInstance()->GetDeviceContext()->VSSetShader(Shader::GetInstance()->GetVertexShaderLighting(), NULL, 0);		// 描画するものごとに変えられる
	Renderer::GetInstance()->GetDeviceContext()->PSSetShader(Shader::GetInstance()->GetPixelShaderLighting(), NULL, 0);

	// マトリクス設定
	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, GetScale().x, GetScale().y, GetScale().z);
	D3DXMatrixRotationYawPitchRoll(&rot, GetRotation().y, GetRotation().x, GetRotation().z);
	D3DXMatrixTranslation(&trans, GetPosition().x, GetPosition().y, GetPosition().z);
	world = scale * rot * trans;
	Renderer::GetInstance()->SetWorldMatrix(&world);

	ResourceData::GetInstance()->GetModelResource(ResourceTag::mRock)->Draw();
}
