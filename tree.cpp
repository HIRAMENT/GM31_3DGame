#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "shader.h"
#include "resource.h"
#include "model.h"
#include "shadow.h"
#include "scene.h"
#include "obb.h"
#include "tree.h"
#include "camera.h"


Tree::Tree(Scene * scene, D3DXVECTOR3 pos, D3DXVECTOR3 scale, int drawPriority)
	: Obstancle(scene, drawPriority)
{
	SetPosition(pos);
	SetRotation(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	SetScale(scale);

	m_Size = ResourceData::GetInstance()->GetModelResource(ResourceTag::mTree)->GetSize();
	m_Size.x = m_Size.z = m_Size.y * 0.2f;
	m_Adjust = D3DXVECTOR3(0.0f, m_Size.y / 2, 0.0f);

	m_Shadow = new Shadow(scene, { pos.x, 0.f,pos.z }, { 1.0f * scale.x,1.0f * scale.z }, 2);

	m_Obb = new OBB(m_Position, m_Size, m_Adjust, m_Rotation);

	m_Visble = true;
}

void Tree::Draw()
{
	Camera* camera = GetScene()->GetGameObject<Camera>(ObjectType::eObCamera);
	if (!camera->CheckView(m_Position, GetRight(), m_Scale)) {
		//m_Visble = true;
		return;
	}
	else
	{
		//m_Visble = false;
	}


	// 入力レイアウト設定 fvfs
	Renderer::GetInstance()->GetDeviceContext()->IASetInputLayout(Shader::GetInstance()->GetVertexLayout(ShaderType::LIGHTING));

	// シェーダー設定
	Renderer::GetInstance()->GetDeviceContext()->VSSetShader(Shader::GetInstance()->GetVertexShader(ShaderType::LIGHTING), NULL, 0);		// 描画するものごとに変えられる
	Renderer::GetInstance()->GetDeviceContext()->PSSetShader(Shader::GetInstance()->GetPixelShader(ShaderType::LIGHTING), NULL, 0);

	// マトリクス設定
	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, GetScale().x, GetScale().y, GetScale().z);
	D3DXMatrixRotationYawPitchRoll(&rot, GetRotation().y, GetRotation().x, GetRotation().z);
	D3DXMatrixTranslation(&trans, GetPosition().x, GetPosition().y, GetPosition().z);
	world = scale * rot * trans;
	Renderer::GetInstance()->SetWorldMatrix(&world);

	ResourceData::GetInstance()->GetModelResource(ResourceTag::mTree)->Draw();
}
