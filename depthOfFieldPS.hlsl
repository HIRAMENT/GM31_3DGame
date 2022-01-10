
#include "common.hlsl"


Texture2D		g_Texture : register( t0 );
SamplerState	g_SamplerState : register( s0 );


void main(in PS_IN In, out float4 outDiffuse : SV_Target)
{
	uint wid, hei;

	g_Texture.GetDimensions(wid, hei);

	float dw = 1.0f / wid;
	float dh = 1.0f / hei;
	float2 ei[9] = { float2(-dw, -dh),float2(0, -dh), float2(dw, -dh),float2(-dw, 0), float2(0, 0), float2(dw, 0), float2(-dw, dh), float2(0, dh), float2(dw, dh) };

	float2 center = In.TexCoord;

	float3 s = float3(0.0f, 0.0f, 0.0f);
	for (int i = 0; i < 9; i++){
		s += g_Texture.Sample(g_SamplerState, center + ei[i]).rgb;
	}

	//float len = length(In.Position.xyz - CameraPosition.xyz);
	outDiffuse.rgb = float3(s / 9);
	outDiffuse.a = g_Texture.Sample(g_SamplerState, In.TexCoord).a;
	if (outDiffuse.a <= 0.01f)
	{
		discard;
	}
}
