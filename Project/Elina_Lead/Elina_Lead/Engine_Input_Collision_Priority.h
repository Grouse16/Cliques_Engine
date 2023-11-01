//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：エンジンの入力判定を行う当たり判定の優先度
// 説明   ：重なっているときに優先度が高いほうが入力の判定を受け付ける
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_ENGINE_INPUT_COLLISION_PRIORITY
#define D_INCLUDE_GUARD_ENGINE_INPUT_COLLISION_PRIORITY


// ☆ ネームスペース ☆ //

// エンジンの当たり判定の入力のシステムを呼び出すための名前
namespace GAME::INPUT::COLLISION
{
	// ☆ 定数 ☆ //

	// エンジンの当たり判定の優先度の順序をまとめた列挙
	enum class E_ENGINE_INPUT_COLLISION_PRIORITY
	{
		e_FRAME,	// フレーム部分のボックス
		e_TAB,		// タブのボックス
	};
}


#endif // !D_INCLUDE_GUARD_ENGINE_INPUT_COLLISION_PRIORITY

