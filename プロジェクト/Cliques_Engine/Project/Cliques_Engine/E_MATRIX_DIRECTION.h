//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：マトリクスの行と方向の関係を表す列挙
// 説明   ：回転から生成されたマトリクスの回転要素を取得するために使用する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_MATRIX_DIRECTION_H_FILE
#define D_INCLUDE_GUARD_E_MATRIX_DIRECTION_H_FILE


// ☆ ネームスペース ☆ //

// マトリクス系統のシステム呼び出すための名前
namespace MATH::MATRIX
{
	// ☆ 列挙 ☆ //

	// マトリクスの行と方向の関係を表す列挙
	enum class E_MATRIX_DIRECTION : char
	{
		e_SIDE_VECTOR = 0,			// 横方向（＋が右方向）
		e_VERTICAL_VECTOR = 1,			// 縦方向（＋が上方向）
		e_FRONT_VECTOR = 2,			// 前後方向（＋が前方向）
		e_TRANSLATION_VECTOR = 3,	// 平行方向
	};
}


#endif // !D_INCLUDE_GUARD_E_MATRIX_DIRECTION_H_FILE

