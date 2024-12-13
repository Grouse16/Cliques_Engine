//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：深度ステンシルの定義を行うファイル
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_STENCIL_ACTIVATE_SETTING_H_FILE
#define D_INCLUDE_GUARD_E_STENCIL_ACTIVATE_SETTING_H_FILE


// ☆ ネームスペース ☆ //

// 深度ステンシルの定義用の情報を呼び出すための名前
namespace RENDERING::INFORM::DEPTH_STENCIL
{
	// ☆ 列挙 ☆ //

	// ステンシルが有効か無効を示す列挙
	enum class E_STENCIL_ACTIVATE_SETTING : bool
	{
		e_NO_ACTIVE = false,	// 無効
		e_ACTIVE = true,		// 有効
	};
}

#endif // !D_INCLUDE_GUARD_DEPTH_STENCIL_INFORM_H_FILE

