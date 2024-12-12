//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：画面の書き込み方法を定義するデータ
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_BLEND_MODE_H_FILE
#define D_INCLUDE_GUARD_E_BLEND_MODE_H_FILE


// ☆ ネームスペース ☆ //

// ブレンド定義用の情報を呼び出すための名前
namespace RENDERING::INFORM::BLEND
{
	// 画面の書き込み方法を定義するデータ
	enum class E_BLEND_MODE
	{
		e_NORMAL,			// 通常描画
		e_NORMAL_NOT_ALPHA,	// α値を使用せずに描画

		e_INVERT,			// 減算方式で描画
		e_INVERT_NOT_ALPHA,	// α値を使用せずに減算方式で描画
	};
}


#endif // !D_INCLUDE_GUARD_E_BLEND_MODE_H_FILE

