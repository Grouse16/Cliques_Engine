//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：深度の書き込み方法の定義
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_DEPTH_MODE_H_FILE
#define D_INCLUDE_GUARD_E_DEPTH_MODE_H_FILE


// ☆ ネームスペース ☆ //

// 深度ステンシルの定義用の情報を呼び出すための名前
namespace RENDERING::INFORM::DEPTH_STENCIL
{
	// ☆ 列挙 ☆ //

	// 深度の書き込み方法の定義
	enum class E_DEPTH_MODE : unsigned char
	{
		e_NO,	// 深度は無効
		e_ZERO,	// 深度は有効、元の深度値が０の部分にのみ書き込む
		e_ONE,	// 深度は有効、全ての範囲に書き込む
	};
}

#endif // !D_INCLUDE_GUARD_E_DEPTH_MODE_H_FILE

