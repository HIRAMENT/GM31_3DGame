#include "common.hlsl"

void main(in VS_IN In, out PS_IN Out)
{
	// １頂点分のデータを受け取り、処理して、出力する

	// 頂点変換処理　この処理は必ず必要
	matrix wvp;									// 行列変数を作成
	wvp = mul(World, View);						// wvp = ワールド行列 * カメラ行列
	wvp = mul(wvp, Projection);					// wvp = wvp * プロジェクション行列
	Out.Position = mul(In.Position, wvp);		// 変換結果を出力する

	// 光源処理
	float4 worldNormal, normal;				// ｗの値を０にしてコピー (平行移動はしないため)
	normal = float4(In.Normal.xyz, 0.0f);	// 法線をワールド行列デ回転する
	worldNormal = mul(normal, World);		// 回転後の法線を正規化
	worldNormal = normalize(worldNormal);	// 回転後の法線出力 (In.Normalではなく回転後の法線を出力)
	Out.Normal = worldNormal;

	// 受け取ったこの頂点のディフューズを出力
	Out.Diffuse = In.Diffuse;

	// 頂点にテクスチャ座標を出力
	Out.TexCoord = In.TexCoord;

	// ワールド変換した頂点座標を出力
	Out.WorldPosition = mul(In.Position, World);
}