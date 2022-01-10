#include "common.hlsl"

// DirectXのテクスチャ設定を受け継ぐ
Texture2D g_Texture : register(t0);

// DirectXのサンプラーステート設定を受け継ぐ
SamplerState g_SamplerState : register(s0);

void main(in PS_IN In, out float4 outDiffuse : SV_Target)
{

	float4 normal = normalize(In.Normal);	// ピクセルの法線を正規化
	float light = -dot(normal.xyz, Light.Direction.xyz);	// 明るさ計算

	// このピクセルに使われるテクスチャの色を取得
	outDiffuse = g_Texture.Sample(g_SamplerState, In.TexCoord);
	outDiffuse.rgb *= (light * In.Diffuse.rbg);	// テクスチャ * 明るさ * 頂点色
	outDiffuse.a *= In.Diffuse.a;				// 頂点色のaをそのまま使う

	// (これ以降はブリンフォン鏡面反射)
	float3 eyev = In.WorldPosition.xyz - CameraPosition.xyz;	// 視線ベクトル
	eyev = normalize(eyev);										// 正規化する

	// リムライト
	float rim = dot(eyev, normal.xyz) + 1.0f;					// 直角時が1.0になる
	rim = saturate(rim);										// サチュレート
	rim = pow(rim, 3) * 2.0f;
	outDiffuse.rgb += rim;
}