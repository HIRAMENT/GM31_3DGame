#include "common.hlsl"

// DirectX�̃e�N�X�`���ݒ���󂯌p��
Texture2D g_Texture : register(t0);

// DirectX�̃T���v���[�X�e�[�g�ݒ���󂯌p��
SamplerState g_SamplerState : register(s0);

void main(in PS_IN In, out float4 outDiffuse : SV_Target)
{

	float4 normal = normalize(In.Normal);	// �s�N�Z���̖@���𐳋K��
	float light = -dot(normal.xyz, Light.Direction.xyz);	// ���邳�v�Z

	// ���̃s�N�Z���Ɏg����e�N�X�`���̐F���擾
	outDiffuse = g_Texture.Sample(g_SamplerState, In.TexCoord);
	outDiffuse.rgb *= (light * In.Diffuse.rbg);	// �e�N�X�`�� * ���邳 * ���_�F
	outDiffuse.a *= In.Diffuse.a;				// ���_�F��a�����̂܂܎g��

	// (����ȍ~�̓u�����t�H�����ʔ���)
	float3 eyev = In.WorldPosition.xyz - CameraPosition.xyz;	// �����x�N�g��
	eyev = normalize(eyev);										// ���K������

	// �������C�g
	float rim = dot(eyev, normal.xyz) + 1.0f;					// ���p����1.0�ɂȂ�
	rim = saturate(rim);										// �T�`�����[�g
	rim = pow(rim, 3) * 2.0f;
	outDiffuse.rgb += rim;
}