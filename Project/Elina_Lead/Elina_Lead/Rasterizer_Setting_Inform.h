//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ラスタライザ設定の定義を行うファイル
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_RASTERIZER_SETTING_INFORM_H_FILE
#define D_INCLUDE_GUARD_RASTERIZER_SETTING_INFORM_H_FILE


// ☆ ネームスペース ☆ //

// ラスタライザ定義用の情報を呼び出すための名前
namespace RENDERING::INFORM::RASTERIZER
{
	// ☆ 列挙 ☆ //

	// 表示モードの列挙
	enum class E_DRAW_MODE : unsigned char
	{
		e_NORMAL,		// 通常表示
		e_WIRE_FRAME,	// 辺のみ表示
	};

	// 面のカリングの描画基準の列挙
	enum class E_MESH_CULLING : unsigned char
	{
		e_ALWAYS,	// 常に描画
		e_FRONT,	// 表面のみ描画
		e_BACK,		// 裏面のみ描画
	};

	// 表面の基準の列挙
	enum class E_MESH_FRONT : unsigned char
	{
		e_ANTI_CLOCK_WISE,	// 反時計回りの面が表面
		e_CLOCK_WISE,		// 時計回りの面が表面
	};

	// アンチエイリアシングの方法の列挙
	enum class E_ANTIALIASING : unsigned char
	{
		e_DONT,		// 無効
		e_ALPHA,	// アルファ値で行う
		e_PIXEL,	// 四辺形で色を分散して行う
		e_LINE,		// 辺にアンチエイリアシングをかける
	};


	// ☆ 構造体 ☆ //

	// 奥行きの値の設定を行うための構造体
	struct S_Depth_Setting_Value
	{
		int depth_value = 0;		// 奥行き値
		float depth_max = 0.0f;		// 奥行きの最大値　0.0fで奥行き無効
		float depth_slope = 0.0f;	// 奥行き調整値
	};
}


#endif // !D_INCLUDE_GUARD_RASTERIZER_SETTING_INFORM_H_FILE

