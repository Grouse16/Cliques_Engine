//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ラスタライザの表示モードの定義
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_DRAW_MODE_H_FILE
#define D_INCLUDE_GUARD_E_DRAW_MODE_H_FILE


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
}


#endif // !D_INCLUDE_GUARD_E_DRAW_MODE_H_FILE

