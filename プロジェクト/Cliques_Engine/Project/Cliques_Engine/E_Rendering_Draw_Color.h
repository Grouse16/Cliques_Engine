//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリング画面に出力する色の種類の列挙
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_RENDERING_DRAW_COLOR_H_FILE
#define D_INCLUDE_GUARD_E_RENDERING_DRAW_COLOR_H_FILE


// ☆ ネームスペース ☆ //

// ブレンド定義用の情報を呼び出すための名前
namespace RENDERING::INFORM::BLEND
{
	// ☆ 列挙 ☆ //

	// レンダリング画像に書き込む色の種類数の列挙
	enum class E_RENDERING_DRAW_COLOR
	{
		e_R,	// 赤のみ
		e_RG,	// 赤と緑
		e_RGBA,	// 赤と緑と青とα値
	};
}


#endif // !D_INCLUDE_GUARD_E_RENDERING_DRAW_COLOR_H_FILE

