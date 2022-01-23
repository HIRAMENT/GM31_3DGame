#include "common.hlsl"

// DirectX�̃e�N�X�`���ݒ���󂯌p��
Texture2D g_Texture : register(t0);
Texture2D g_TextureEnv : register(t1);

// DirectX�̃T���v���[�X�e�[�g�ݒ���󂯌p��
SamplerState g_SamplerState : register(s0);

void main(in PS_IN In, out float4 outDiffuse : SV_Target)
{
	// 1.�s�N�Z���̖@���𐳋K��
	float4 normal = normalize(In.Normal);

	// 2.�����x�N�g�����쐬���Đ��K��
	float3 eyev = In.WorldPosition.xyz - CameraPosition.xyz;
	eyev = normalize(eyev);	

	// 3.���˃x�N�g�����쐬���Đ��K��
	float3 refv = reflect(eyev, normal.xyz);
	refv = normalize(refv);	

	// 4.���˃x�N�g��������}�b�s���O�p�̃e�N�X�`�����W���쐬
	float2 envTexCood = float2(0,0);
	envTexCood.x = -refv.x * 0.5f + 0.5f + Parameter.x;
	envTexCood.y = -refv.y * 0.5f + 0.5f + Parameter.y;

	// 5.�X�t�B�A�}�b�v�ƃx�[�X�e�N�X�`�������Z���ďo��
	float4 EnvTex = g_TextureEnv.SampleBias(g_SamplerState, envTexCood, 1.0f);
	float4 BaseTex = g_Texture.Sample(g_SamplerState, In.TexCoord);
	outDiffuse.rgb = EnvTex + BaseTex;

	// 6.���l�̏���
	outDiffuse.a = In.Diffuse.a * BaseTex.a;
}