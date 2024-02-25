//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：マウスのクリック状態を指定する列挙の定義
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_MOUSE_CLICK_STATE_H_FILE
#define D_INCLUDE_GUARD_E_MOUSE_CLICK_STATE_H_FILE


// OS制御用システムを呼び出すための名前
namespace OS
{
	// ☆ 列挙 ☆ //

	// マウスのクリック状態を指定する列挙
	enum class E_MOUSE_CLICK_STATE
	{
		e_NON,			// 何もしていない
		e_CLICK,		// クリック中
		e_DOUBLE_CLICK,	// ダブルクリック中
	};
}


#endif // !D_INCLUDE_GUARD_E_MOUSE_CLICK_STATE_H_FILE

