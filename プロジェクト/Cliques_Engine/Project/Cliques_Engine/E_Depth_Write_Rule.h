//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：深度の書き込みルールの定義
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_DEPTH_WRITE_RULE_H_FILE
#define D_INCLUDE_GUARD_E_DEPTH_WRITE_RULE_H_FILE


// ☆ ネームスペース ☆ //

// 深度ステンシルの定義用の情報を呼び出すための名前
namespace RENDERING::INFORM::DEPTH_STENCIL
{
	// ☆ 列挙 ☆ //

	// 深度の書き込みルールの定義
	enum class E_DEPTH_WRITE_RULE : unsigned char
	{
		e_DONT,			// 書き込まない
		e_ALWAYS,		// 常に書き込む
		e_EQUAL,		// 比較元と同じ値の時のみ書き込む
		e_NOT_EQUAL,	// 比較元と違う値の時のみ書き込む
		e_GREATER,		// 比較元の値を超える時のみ書き込む
		e_LESS,			// 比較元の値未満の時のみ書き込む

		e_LESS_EQUAL,		// 比較元の値以下の時のみ書き込む
		e_GREATERE_EQUAL,	// 比較元の値以上の時のみ書き込む
	};
}

#endif // !D_INCLUDE_GUARD_E_DEPTH_WRITE_RULE_H_FILE

