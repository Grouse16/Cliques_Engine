//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：カラーとテクスチャを必要とするUIのテクスチャ用ピクセルシェーダー
// 説明   ：uv座標が-10ならカラーを割り当てる
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 構造体 ☆ //

// ピクセルシェーダーに入ってくる情報
struct S_PS_IN
{
    float4 position : SV_POSITION;  // 位置座標
    float4 color : COLOR0;          // 色
    float2 uv : TEXCOORD0;     // UV座標
};


// ☆ テクスチャ ☆ //

// テクスチャハンドル
Texture2D<float4> tex_color : register(t0);


// ☆ 静的サンプラー ☆ //

// サンプラーハンドル
SamplerState samp0 : register(s0);


// ☆ メイン関数 ☆ //
float4 ps_main(S_PS_IN in_ps) : SV_TARGET
{
    // ☆ 変数宣言 ☆ //
    float4 out_color = in_ps.color;   // 色
    
    
    // テクスチャカラーを混ぜる
    out_color *= tex_color.Sample(samp0, in_ps.uv);
	
    
    // カラーを出力
    return out_color;
}

