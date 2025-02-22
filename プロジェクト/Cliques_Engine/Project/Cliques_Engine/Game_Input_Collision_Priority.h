//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ゲームの入力判定を行う当たり判定の優先度
// 説明   ：重なっているときに優先度が高いほうが入力の判定を受け付ける
// 作成者 ：��坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_Game_INPUT_COLLISION_PRIORITY
#define D_INCLUDE_GUARD_Game_INPUT_COLLISION_PRIORITY


// ☆ ネームスペース ☆ //

// ゲームの当たり判定の入力のシステムを呼び出すための名前
namespace GAME::INPUT::COLLISION
{
	// ☆ 定数 ☆ //

	// ゲームの当たり判定の優先度の順序をまとめた列挙
	enum class E_Game_INPUT_COLLISION_PRIORITY
	{
		e_FRAME,	// フレーム部分のボックス
		e_TAB,		// タブのボックス
	};
}


#endif // !D_INCLUDE_GUARD_Game_INPUT_COLLISION_PRIORITY

