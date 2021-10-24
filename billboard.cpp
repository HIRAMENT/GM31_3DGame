#include "main.h"
#include "renderer.h"
#include "shader.h"
#include "texture.h"
#include "scene.h"
#include "billboard.h"
#include "camera.h"


Billboard::Billboard(Scene * scene, D3DXVECTOR3 pos, D3DXVECTOR2 size, ResourceTag tag, bool centered, int drawPriority)
	: GameObject(scene, ObjectType::eObBillboard, drawPriority)
	, m_TextureTag(tag)
	, m_Size(size)
{
	if (centered)
	{
		m_Vertex[0].Position = D3DXVECTOR3(-size.x * 0.5f, size.y * 0.5f, 0.0f);
		m_Vertex[0].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_Vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		m_Vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

		m_Vertex[1].Position = D3DXVECTOR3(size.x * 0.5f, size.y * 0.5f, 0.0f);
		m_Vertex[1].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_Vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		m_Vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

		m_Vertex[2].Position = D3DXVECTOR3(-size.x * 0.5f, -size.y * 0.5f, 0.0f);
		m_Vertex[2].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_Vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		m_Vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		m_Vertex[3].Position = D3DXVECTOR3(size.x * 0.5f, -size.y * 0.5f, 0.0f);
		m_Vertex[3].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_Vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		m_Vertex[3].TexCoord = D3DXVECTOR2(1.0f, 1.0f);
	}
	else
	{
		m_Vertex[0].Position = D3DXVECTOR3(0.0f, size.y, 0.0f);
		m_Vertex[0].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_Vertex[0].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		m_Vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);

		m_Vertex[1].Position = D3DXVECTOR3(size.x, size.y, 0.0f);
		m_Vertex[1].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_Vertex[1].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		m_Vertex[1].TexCoord = D3DXVECTOR2(1.0f, 0.0f);

		m_Vertex[2].Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_Vertex[2].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_Vertex[2].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		m_Vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);

		m_Vertex[3].Position = D3DXVECTOR3(size.x, 0.0f, 0.0f);
		m_Vertex[3].Normal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_Vertex[3].Diffuse = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
		m_Vertex[3].TexCoord = D3DXVECTOR2(1.0f, 1.0f);
	}


	// ���_�o�b�t�@�쐬
	D3D11_BUFFER_DESC bd{};
	bd.Usage = D3D11_USAGE_DYNAMIC;
	bd.ByteWidth = sizeof(VERTEX_3D) * 4;		// �o�b�t�@�̃T�C�Y�w��
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;	// ���̃o�b�t�@�̐����p�̂���
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	D3D11_SUBRESOURCE_DATA sd{};
	sd.pSysMem = m_Vertex;

	Renderer::GetInstance()->GetDevice()->CreateBuffer(&bd, &sd, &m_VertexBuffer);

	m_TexHorCount = ResourceData::GetInstance()->GetTextureResource(tag)->GetSideNumber();
	m_TexVerCount = ResourceData::GetInstance()->GetTextureResource(tag)->GetVerNumber();
	m_TexAllCount = m_TexHorCount * m_TexVerCount;

	m_AnimationCount = 0;
	m_AnimationSpeed = 0.0f;
	m_SliddValue = 0.0f;
	m_SlideMove = 0.0f;
	m_VariaRatio = 0.0f;

	m_SlideOn = false;
	m_Display = true;

	m_Position = pos;
	m_Rotation = { 0.0f,0.0f, 0.0f };
	m_Scale = { 1.0f,1.0f, 1.0f };
	scene->Add(this);
}

void Billboard::Init()
{
}

void Billboard::Uninit()
{
	m_VertexBuffer->Release();
}

void Billboard::Update()
{
	if (m_SlideOn && Slide())
	{
		m_SlideOn = false;
		m_SlideMove = 0.0f;
		m_AnimationSpeed = 0.0f;
	}

	if (m_TexAllCount > 1)
	{
		m_AnimationCount++;
		AnimationTexture();
	}
	if (m_AnimationCount >= m_TexAllCount)
	{
		SetDestroy();
		return;
	}
}

void Billboard::Draw()
{
	if (m_Display)
	{
		// ���_�f�[�^�̏�������
		D3D11_MAPPED_SUBRESOURCE msr;
		Renderer::GetInstance()->GetDeviceContext()->Map(m_VertexBuffer, 0,
			D3D11_MAP_WRITE_DISCARD, 0, &msr);

		VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;

		vertex[0].Position = m_Vertex[0].Position;
		vertex[0].Normal = m_Vertex[0].Normal;
		vertex[0].Diffuse = m_Vertex[0].Diffuse;
		vertex[0].TexCoord = m_Vertex[0].TexCoord;

		vertex[1].Position = m_Vertex[1].Position;
		vertex[1].Normal = m_Vertex[1].Normal;
		vertex[1].Diffuse = m_Vertex[1].Diffuse;
		vertex[1].TexCoord = m_Vertex[1].TexCoord;

		vertex[2].Position = m_Vertex[2].Position;
		vertex[2].Normal = m_Vertex[2].Normal;
		vertex[2].Diffuse = m_Vertex[2].Diffuse;
		vertex[2].TexCoord = m_Vertex[2].TexCoord;

		vertex[3].Position = m_Vertex[3].Position;
		vertex[3].Normal = m_Vertex[3].Normal;
		vertex[3].Diffuse = m_Vertex[3].Diffuse;
		vertex[3].TexCoord = m_Vertex[3].TexCoord;

		Renderer::GetInstance()->GetDeviceContext()->Unmap(m_VertexBuffer, 0);

		// ���̓��C�A�E�g�ݒ� fvfs
		Renderer::GetInstance()->GetDeviceContext()->IASetInputLayout(Shader::GetInstance()->GetVertexLayputUnlit());

		// �V�F�[�_�[�ݒ�
		Renderer::GetInstance()->GetDeviceContext()->VSSetShader(Shader::GetInstance()->GetVertexShaderUnlit(), NULL, 0);		// �`�悷����̂��Ƃɕς�����
		Renderer::GetInstance()->GetDeviceContext()->PSSetShader(Shader::GetInstance()->GetPixelShaderUnlit(), NULL, 0);

		// �J�����̃r���[�}�g���N�X�̎擾
		Camera* camera = GetScene()->GetGameObject<Camera>(ObjectType::eObCamera);
		D3DXMATRIX view = camera->GetViewMatrix();

		// �r���[�̋t�s��
		D3DXMATRIX invView;
		D3DXMatrixInverse(&invView, nullptr, &view);
		invView._41 = 0.0f;
		invView._42 = 0.0f;
		invView._43 = 0.0f;

		// �}�g���N�X�ݒ�
		D3DXMATRIX world, scale, trans;
		D3DXMatrixScaling(&scale, GetScale().x, GetScale().y, GetScale().z);
		D3DXMatrixTranslation(&trans, GetPosition().x, GetPosition().y, GetPosition().z);
		world = scale * invView * trans;
		Renderer::GetInstance()->SetWorldMatrix(&world);

		// ���_�o�b�t�@�ݒ�
		UINT stride = sizeof(VERTEX_3D);
		UINT offset = 0;
		Renderer::GetInstance()->GetDeviceContext()->IASetVertexBuffers(0, 1, &m_VertexBuffer, &stride, &offset);

		// �}�e���A���ݒ�
		MATERIAL material;
		ZeroMemory(&material, sizeof(material));
		material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		Renderer::GetInstance()->SetMaterial(material);

		// �e�N�X�`���ݒ�
		Renderer::GetInstance()->GetDeviceContext()->PSSetShaderResources(0, 1, ResourceData::GetInstance()->GetTextureResource(m_TextureTag)->GetTexture());	// �e�N�X�`���Ȃǂ����\�[�X�g�ǂ�ł���

		// �v���~�e�B�u�g�|���W�ݒ�
		Renderer::GetInstance()->GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);	// ������O�ɕς���Ă��邪�A�`��̕��@��ݒ肵�Ă��邾��

		// �|���S���`��
		Renderer::GetInstance()->GetDeviceContext()->Draw(4, 0);	// �����������_���ɂȂ��Ă���̂Œ���
	}
}

void Billboard::SetAlpha(float alpha)
{
	for (int i = 0; i < 4; i++)
	{
		m_Vertex[i].Diffuse.w = alpha;
	}
}

void Billboard::SetColor(float r, float g, float b)
{
	m_Vertex[0].Diffuse = D3DXVECTOR4(r / 255, g / 255, b / 255, 1.0f);
	m_Vertex[1].Diffuse = D3DXVECTOR4(r / 255, g / 255, b / 255, 1.0f);
	m_Vertex[2].Diffuse = D3DXVECTOR4(r / 255, g / 255, b / 255, 1.0f);
	m_Vertex[3].Diffuse = D3DXVECTOR4(r / 255, g / 255, b / 255, 1.0f);
}

void Billboard::AnimationTexture()
{
	float x = (1.0f / m_TexHorCount) * (m_AnimationCount % m_TexHorCount);
	float y = (1.0f / m_TexVerCount) * (m_AnimationCount / m_TexHorCount);

	m_Vertex[0].TexCoord = D3DXVECTOR2(x, y);
	m_Vertex[1].TexCoord = D3DXVECTOR2(x + (1.0f / m_TexHorCount), y);
	m_Vertex[2].TexCoord = D3DXVECTOR2(x, y + (1.0f / m_TexVerCount));
	m_Vertex[3].TexCoord = D3DXVECTOR2(x + (1.0f / m_TexHorCount), y + (1.0f / m_TexVerCount));
}

void Billboard::StartSlide(int maxcapa, int capa, int speed)
{
	m_SlideOn = true;
	m_VariaRatio = 1.0f - (float)capa / (float)maxcapa;
	m_SlideMove = m_VariaRatio - m_SliddValue;
	m_AnimationSpeed = speed;
}

bool Billboard::Slide()
{
	m_SliddValue += m_SlideMove / ((1.0f - m_AnimationSpeed) * 10);
	if (m_SliddValue >= m_VariaRatio) { m_SliddValue = m_VariaRatio; }

	m_Vertex[0].Position = D3DXVECTOR3(0.0f, m_Size.y, 0.0f);
	m_Vertex[0].TexCoord = D3DXVECTOR2(0.0f, 0.0f);
	m_Vertex[1].Position = D3DXVECTOR3(m_Size.x * (1.0f - m_SliddValue), m_Size.y, 0.0f);
	m_Vertex[1].TexCoord = D3DXVECTOR2(1.0f * (1.0f - m_SliddValue), 0.0f);
	m_Vertex[2].Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Vertex[2].TexCoord = D3DXVECTOR2(0.0f, 1.0f);
	m_Vertex[3].Position = D3DXVECTOR3(m_Size.x * (1.0f - m_SliddValue), 0.0f, 0.0f);
	m_Vertex[3].TexCoord = D3DXVECTOR2(1.0f * (1.0f - m_SliddValue), 1.0f);

	if (m_SliddValue == m_VariaRatio)
	{
		return true;
	}
	else
	{
		return false;
	}
}
