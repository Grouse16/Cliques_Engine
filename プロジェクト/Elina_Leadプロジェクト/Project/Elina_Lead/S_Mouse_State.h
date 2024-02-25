//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：マウス情報用の型の定義
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_MOUSE_STATE_H_FILE
#define D_INCLUDE_GUARD_S_MOUSE_STATE_H_FILE


// ☆ ファイルひらき ☆ //
#include "E_Mouse_Click_State.h"


// ☆ ネームスペース ☆ //

// OS制御用システムを呼び出すための名前
namespace OS
{
	// ☆ 構造体 ☆//

	// マウス座標用の構造体
	struct S_Mouse_State
	{
		E_MOUSE_CLICK_STATE left_click = E_MOUSE_CLICK_STATE::e_NON;	// 左クリックの状態
		E_MOUSE_CLICK_STATE center_click = E_MOUSE_CLICK_STATE::e_NON;	// 中クリックの状態
		E_MOUSE_CLICK_STATE right_click = E_MOUSE_CLICK_STATE::e_NON;	// 右クリックの状態

		int x = 0;	// マウス座標ｘ
		int y = 0;	// マウス座標ｙ
	};
}


#endif // !D_INCLUDE_GUARD_S_MOUSE_STATE_H_FILE
