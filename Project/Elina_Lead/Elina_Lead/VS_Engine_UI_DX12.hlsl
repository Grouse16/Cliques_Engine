//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：カラーとテクスチャを必要とするUIのテクスチャ用頂点シェーダー
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 構造体 ☆ //

// 頂点シェーダーに入ってくる情報
struct S_VS_IN
{
    float2 position : CLIQUES0; // 位置座標
    float4 color : CLIQUES1; // 色
    float2 uv : CLIQUES2; // テクスチャ
};

// 頂点シェーダーから出力する情報
struct S_VS_OUT
{
    float4 position : SV_POSITION;  // 位置座標
    float4 color : COLOR0;          // 色
    float2 uv : TEXCOORD0;          // UV座標
};


// ☆ メイン関数 ☆ //
S_VS_OUT vs_main(S_VS_IN in_vs)
{
	// ☆ 変数宣言 ☆ //
    S_VS_OUT out_vs; // 頂点シェーダーから渡す情報
    
    
	// 渡された情報のセット
    out_vs.position = float4(in_vs.position, 0.0f, 1.0f);
    out_vs.color = in_vs.color;
    out_vs.uv = in_vs.uv;
    

    // 出力結果を送る
    return out_vs;
}

