#pragma once

#include "singleton.h"
#include <unordered_map>



struct VERTEX_3D
{
    D3DXVECTOR3 Position;
    D3DXVECTOR3 Normal;
    D3DXVECTOR4 Diffuse;
    D3DXVECTOR2 TexCoord;
};



struct MATERIAL
{
	D3DXCOLOR	Ambient;
	D3DXCOLOR	Diffuse;
	D3DXCOLOR	Specular;
	D3DXCOLOR	Emission;
	float		Shininess;
	float		Dummy[3];
};



struct LIGHT
{
	BOOL		Enable;
	BOOL		Dummy[3];
	D3DXVECTOR4	Direction;
	D3DXCOLOR	Diffuse;
	D3DXCOLOR	Ambient;
};

enum class BlendMode {
	NONE,
	NORMAL,			// �A���t�@�u�����h
	ADDITION,		// ���Z����
	ADDITIONALPHA,	// ���Z����(����)
	SUBTRACTION,	// ���Z����
	MULTIPLE,		// ��Z����
	BLENDMODE_MAX
};

// �`��̕����݂̂��Ǘ�����N���X
class Renderer : public Singleton<Renderer>
{
private:

	// �����o�ϐ��̓n���K���A���L�@���g���Ă���B
	//  �ł��ŋ߂͎g���ĂȂ��炵���B(�J�[�\�����킹��΃����o�ϐ����Ƃ����ɂ킩�邩��)
	//  ���������̂𖽖��K��(�R�[�f�B���O���[���A�P�[�X)�Ƃ��� (�v���W�F�N�g�œ��ꂷ�邱�Ƃ����)
	// �@�L�������P�[�X�E�p�X�J���P�[�X�E�X�l�[�N�P�[�X �Ȃǂ��낢��Ȏ�ނ�����
	static D3D_FEATURE_LEVEL       m_FeatureLevel;

	static ID3D11Device*           m_Device;
	static ID3D11DeviceContext*    m_DeviceContext;
	static IDXGISwapChain*         m_SwapChain;
	static ID3D11RenderTargetView* m_RenderTargetView;
	static ID3D11DepthStencilView* m_DepthStencilView;

	static ID3D11Buffer*			m_WorldBuffer;
	static ID3D11Buffer*			m_ViewBuffer;
	static ID3D11Buffer*			m_ProjectionBuffer;
	static ID3D11Buffer*			m_MaterialBuffer;
	static ID3D11Buffer*			m_LightBuffer;
	ID3D11Buffer*					m_CameraBuffer;
	ID3D11Buffer*					m_ParameterBuffer;


	static ID3D11DepthStencilState* m_DepthStateEnable;
	static ID3D11DepthStencilState* m_DepthStateDisable;

	std::unordered_map<BlendMode, ID3D11BlendState*> m_BlendState;




public:
	friend class Singleton<Renderer>;

	void Init();
	void Uninit();
	void Begin();		// 
	void End();			// 

	void SetDepthEnable(bool Enable);
	void SetWorldViewProjection2D();
	void SetWorldMatrix(D3DXMATRIX* WorldMatrix);
	void SetViewMatrix(D3DXMATRIX* ViewMatrix);
	void SetProjectionMatrix(D3DXMATRIX* ProjectionMatrix);
	void SetMaterial(MATERIAL Material);
	void SetLight(LIGHT Light);
	void SetCameraPosition(D3DXVECTOR3 pos);
	void SetParameter(D3DXVECTOR4 parameter);
	void SetRenderBlend(BlendMode mode);

	ID3D11Device* GetDevice( void ){ return m_Device; }
	ID3D11DeviceContext* GetDeviceContext( void ){ return m_DeviceContext; }

	void CreateVertexShader(ID3D11VertexShader** VertexShader, ID3D11InputLayout** VertexLayout, const char* FileName);
	void CreatePixelShader(ID3D11PixelShader** PixelShader, const char* FileName);

protected:
	Renderer(){}
	virtual ~Renderer(){}
};
