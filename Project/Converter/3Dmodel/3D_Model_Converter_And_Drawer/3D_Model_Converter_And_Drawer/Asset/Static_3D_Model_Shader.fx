// ☆ 構造体 ☆ //

// 頂点シェーダーに渡される情報の構造体
struct S_VS_IN
{
	float4 position : POSITION;	// 位置座標

	float2 uv : TEXCOORD0;		// uv座標

	float4 color : COLOR;		// 頂点カラー
	
	float3 normal : NORMAL;		// 法線ベクトル
	float3 tangent : TANGENT;	// タンジェントベクトル
	float3 bi_normal : BINORMAL;	// 従法線ベクトル
};


// ピクセルシェーダーに渡される情報の構造体
struct S_PS_IN
{
	float4 position : SV_POSITION;	// 位置座標
	
	float2 uv : TEXCOORD0;		// uv座標
	
	float4 color : COLOR0;	// 頂点カラー
	
	float3 normal : NORMAL;		// 法線ベクトル
	float3 tangent : TANGENT;	// タンジェントベクトル
	float3 bi_normal : BINORMAL;	// 従法線ベクトル
};


// ワールド行列、ビュー行列、射影行列の情報の構造体
struct S_WVP_MATRIX
{
	float4x4 world_matrix;		// ワールド行列
    float4x4 view_matrix;		// ビュー行列
    float4x4 projection_matrix; // 射影行列
};


// ☆ 定数バッファ ☆ //

// ワールド行列、ビュー行列、射影行列の情報の定数バッファ
cbuffer CB_WVP_MATRIX : register(b0)
{
    S_WVP_MATRIX cb_wvp;
};


// ☆ テクスチャー ☆ //
Texture2D main_color_texture : register(t0);	// メインとなる色のテクスチャ


// ☆ サンプラー ☆ //
sampler main_color_texture_sampler : register(s0);	// メインとなる色のテクスチャのサンプラー


// ☆ 関数 ☆ //

// 頂点シェーダー
S_PS_IN VS(S_VS_IN vs_input)
{
	// ☆ 変数宣言 ☆ //
	S_PS_IN vs_output;	// ピクセルシェーダーに渡す情報の構造体
	
	
	// ワールド行列、ビュー行列、射影行列を掛け合わせる
    vs_output.position = mul(cb_wvp.world_matrix, vs_input.position);
    vs_output.position = mul(cb_wvp.view_matrix, vs_output.position);
    vs_output.position = mul(cb_wvp.projection_matrix, vs_output.position);
	
	
	// uv座標を設定
    vs_output.uv = vs_input.uv;
	
	// 色を設定
    vs_output.color = vs_input.color;
	
	// 法線ベクトルを設定
    vs_output.normal = vs_input.normal;
	
	// タンジェントベクトルを設定
    vs_output.tangent = vs_input.tangent;
	
	// 従法線ベクトルを設定
    vs_output.bi_normal = vs_input.bi_normal;
	
	// 計算した情報を返す
    return vs_output;
}


// ピクセルシェーダー
float4 PS(S_PS_IN ps_input) : SV_Target
{
    return ps_input.color * main_color_texture.Sample(main_color_texture_sampler, ps_input.uv);
}
