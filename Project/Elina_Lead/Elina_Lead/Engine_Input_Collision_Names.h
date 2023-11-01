//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：エンジンの入力判定を定義するための名前を設定している
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_ENGINE_INPUT_COLLISION_NAME_H_FILE
#define D_INCLUDE_GUARD_E_ENGINE_INPUT_COLLISION_NAME_H_FILE


// ☆ ネームスペース ☆ //

// エンジンの入力判定の共通の名前の定義を呼び出すための名前
namespace GAME::INPUT::COLLISION::NAME
{
	constexpr wchar_t con_ENGINE_INPUT_COLLISION_INITIALIZED_NAME[] = L"NOTHING";	// エンジンの当たり判定の初期名
}


#endif // !D_INCLUDE_GUARD_E_ENGINE_INPUT_COLLISION_NAME_H_FILE
