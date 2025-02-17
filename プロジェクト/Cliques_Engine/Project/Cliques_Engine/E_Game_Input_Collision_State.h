//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ゲームの入力判定の状態を指定する列挙
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_Game_INPUT_COLLISION_STATE_H_FILE
#define D_INCLUDE_GUARD_E_Game_INPUT_COLLISION_STATE_H_FILE


// ☆ ネームスペース ☆ //

// ゲームの入力系統を呼び出すための名前
namespace GAME::INPUT::COLLISION
{
	// ☆ 列挙 ☆ //

	// ゲームの入力判定の状態を指定する列挙
	enum class E_Game_Input_Collision_State
	{
		e_NOT_HIT,		// カーソルに触れていない
		
		e_OVERED,		// カーソルが上にある
		
		e_CLICK_START,	// クリックが開始された
		e_CLICK_DOING,	// クリック中
		e_CLICK_END,	// クリック終了
		
		e_DOUBLE_CLICK_START,	// ダブルクリック開始
		e_DOUBLE_CLICK_DOING,	// ダブルクリック中
		e_DOUBLE_CLICK_END,		// ダブルクリック終了

		e_DRAG_START,	// ドラッグ開始時
		e_DRAG_DOING,	// ドラッグ中
		e_DRAG_END,		// ドラッグ終了

		e_DRAG_OVERED,			// 他の入力判定のドラッグ操作中にカーソルが重なっている
		e_DRAG_OVER_DROPPED,	// 他の入力判定のドラッグ操作中に上でカーソルを離された
	};
}


#endif // !D_INCLUDE_GUARD_E_Game_INPUT_COLLISION_STATE_H_FILE
