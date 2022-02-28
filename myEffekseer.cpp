#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "scene.h"
#include "myEffekseer.h"
#include "camera.h"
#include "effectData.h"

void MyEffekseer::Init()
{
	m_Renderer = CreateRenderer();
	m_Manager = CreateManager(m_Renderer);
}

void MyEffekseer::Uninit()
{
	m_Renderer.Reset();
	m_Manager.Reset();
}

void MyEffekseer::Update()
{
	Camera* camera = Manager::GetInstance()->GetScene()->GetGameObject<Camera>(ObjectType::eObCamera);
	Effekseer::Matrix44 ProMatrix, ViewMatrix;


	if (camera != nullptr)
	{
		// 投影行列を設定
		ProMatrix = ConversionMatrix(camera->GetProjectionMatrix());
		m_Renderer->SetProjectionMatrix(ProMatrix);

		// カメラ行列を設定
		ViewMatrix = ConversionMatrix(camera->GetViewMatrix());
		m_Renderer->SetCameraMatrix(ViewMatrix);
	}
	else
	{
		//投影行列を設定
		m_Renderer->SetProjectionMatrix(::Effekseer::Matrix44().PerspectiveFovRH(
			90.0f / 180.0f * 3.14f, (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 1.0f, 500.0f));
		// カメラ行列を設定
		m_Renderer->SetCameraMatrix(
			::Effekseer::Matrix44().LookAtRH({0.0f,0.0f,-10.0f}, ::Effekseer::Vector3D(0.0f, 0.0f, 0.0f), ::Effekseer::Vector3D(0.0f, 1.0f, 0.0f)));
	}


	m_Manager->Update();
	m_Renderer->SetTime(m_Renderer->GetTime() + (1 / 60));
}

void MyEffekseer::Draw()
{
	m_Renderer->BeginRendering();
	m_Manager->Draw();
	m_Renderer->EndRendering();
}

EffekseerRendererDX11::RendererRef MyEffekseer::CreateRenderer()
{
	ID3D11Device* d3D11Device = Renderer::GetInstance()->GetDevice();
	ID3D11DeviceContext* d3D11DeviceContext = Renderer::GetInstance()->GetDeviceContext();
	auto renderer = EffekseerRendererDX11::Renderer::Create(d3D11Device, d3D11DeviceContext, 8000);
	return renderer;
}

Effekseer::ManagerRef MyEffekseer::CreateManager(EffekseerRendererDX11::RendererRef renderer)
{
	auto manager = Effekseer::Manager::Create(8000);

	// 描画モジュールの設定
	manager->SetSpriteRenderer(renderer->CreateSpriteRenderer());
	manager->SetRibbonRenderer(renderer->CreateRibbonRenderer());
	manager->SetRingRenderer(renderer->CreateRingRenderer());
	manager->SetTrackRenderer(renderer->CreateTrackRenderer());
	manager->SetModelRenderer(renderer->CreateModelRenderer());
	manager->SetTextureLoader(renderer->CreateTextureLoader());
	manager->SetModelLoader(renderer->CreateModelLoader());
	manager->SetMaterialLoader(renderer->CreateMaterialLoader());
	manager->SetCurveLoader(Effekseer::MakeRefPtr<Effekseer::CurveLoader>());

	return manager;
}

int MyEffekseer::Play(EffectData* data, D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	auto playHandol = m_Manager->Play(data->GetEffect(), pos.x, pos.y, pos.z);
	m_Manager->SetScale(playHandol, data->GetScale().x, data->GetScale().y, data->GetScale().z);
	m_Manager->SetRotation(playHandol, rot.x, rot.y, rot.z );
	return playHandol;
}

void MyEffekseer::Stop(int handle)
{
	m_Manager->StopEffect(handle);
}

Effekseer::EffectRef MyEffekseer::CreateEffect(std::u16string fileName)
{
	auto effect = Effekseer::Effect::Create(m_Manager, fileName.c_str());
	return effect;
}

Effekseer::Matrix44 MyEffekseer::ConversionMatrix(D3DXMATRIX matrix)
{
	Effekseer::Matrix44 effmatrix;
	effmatrix.Values[0][0] = matrix._11;
	effmatrix.Values[0][1] = matrix._12;
	effmatrix.Values[0][2] = matrix._13;
	effmatrix.Values[0][3] = matrix._14;
	effmatrix.Values[1][0] = matrix._21;
	effmatrix.Values[1][1] = matrix._22;
	effmatrix.Values[1][2] = matrix._23;
	effmatrix.Values[1][3] = matrix._24;
	effmatrix.Values[2][0] = matrix._31;
	effmatrix.Values[2][1] = matrix._32;
	effmatrix.Values[2][2] = matrix._33;
	effmatrix.Values[2][3] = matrix._34;
	effmatrix.Values[3][0] = matrix._41;
	effmatrix.Values[3][1] = matrix._42;
	effmatrix.Values[3][2] = matrix._43;
	effmatrix.Values[3][3] = matrix._44;
	return effmatrix;
}
