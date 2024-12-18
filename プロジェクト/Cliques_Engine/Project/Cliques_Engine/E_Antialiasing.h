//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アンチエイリアシングの方法の定義
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_ANTIALIASING_H_FILE
#define D_INCLUDE_GUARD_E_ANTIALIASING_H_FILE


// ☆ ネームスペース ☆ //

// ラスタライザ定義用の情報を呼び出すための名前
namespace RENDERING::INFORM::RASTERIZER
{
	// ☆ 列挙 ☆ //

	// アンチエイリアシングの方法の列挙
	enum class E_ANTIALIASING : unsigned char
	{
		e_DONT,		// 無効
		e_ALPHA,	// アルファ値で行う
		e_PIXEL,	// 四辺形で色を分散して行う
		e_LINE,		// 辺にアンチエイリアシングをかける
	};
}


#endif // !D_INCLUDE_GUARD_E_ANTIALIASING_H_FILE

