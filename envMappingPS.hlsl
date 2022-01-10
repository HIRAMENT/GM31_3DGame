#include "common.hlsl"

// DirectXのテクスチャ設定を受け継ぐ
Texture2D g_Texture : register(t0);
Texture2D g_TextureEnv : register(t1);

// DirectXのサンプラーステート設定を受け継ぐ
SamplerState g_SamplerState : register(s0);

void main(in PS_IN In, out float4 outDiffuse : SV_Target)
{
	// 1.ピクセルの法線を正規化
	float4 normal = normalize(In.Normal);

	// 2.視線ベクトルを作成して正規化
	float3 eyev = In.WorldPosition.xyz - CameraPosition.xyz;
	eyev = normalize(eyev);	

	// 3.反射ベクトルを作成して正規化
	float3 refv = reflect(eyev, normal.xyz);
	refv = normalize(refv);	

	// 4.反射ベクトルから環境マッピング用のテクスチャ座標を作成
	float2 envTexCood = float2(0,0);
	envTexCood.x = -refv.x * 0.5f + 0.5f;
	envTexCood.y = -refv.y * 0.5f + 0.5f;

	// 5.スフィアマップとベーステクスチャを加算して出力
	float4 EnvTex = g_TextureEnv.SampleBias(g_SamplerState, envTexCood, 1.0f);
	float4 BaseTex = g_Texture.Sample(g_SamplerState, In.TexCoord);
	outDiffuse.rgb = EnvTex + BaseTex;

	// 6.α値の処理
	outDiffuse.a = In.Diffuse.a * BaseTex.a;
}