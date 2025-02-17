//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ゲームの入力判定を定義するための名前を設定している
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_Game_INPUT_COLLISION_NAME_H_FILE
#define D_INCLUDE_GUARD_E_Game_INPUT_COLLISION_NAME_H_FILE


// ☆ ネームスペース ☆ //

// ゲームの入力判定の共通の名前の定義を呼び出すための名前
namespace GAME::INPUT::COLLISION::NAME
{
	constexpr wchar_t con_Game_INPUT_COLLISION_INITIALIZED_NAME[] = L"NOTHING";	// ゲームの当たり判定の初期名
}


#endif // !D_INCLUDE_GUARD_E_Game_INPUT_COLLISION_NAME_H_FILE
