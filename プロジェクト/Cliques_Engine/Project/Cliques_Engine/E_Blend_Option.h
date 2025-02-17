//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ピクセルシェーダーの出力値の入力条件を定義するデータ
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_BLEND_OPTION_H_FILE
#define D_INCLUDE_GUARD_E_BLEND_OPTION_H_FILE


// ☆ ネームスペース ☆ //

// ブレンド定義用の情報を呼び出すための名前
namespace RENDERING::INFORM::BLEND
{
	// ☆ 列挙 ☆ //

	// ピクセルシェーダーとレンダリング画像の色の混ぜ方を指定する列挙
	enum class E_BLEND_OPTION
	{
		e_ADD,		// ピクセルシェーダーの色を加算
		e_SUB,		// ピクセルシェーダーの色を減算
		e_SUB_PIX,	// ピクセルシェーダーの色を現在の色で減算
		e_MAX,		// 現在の色とピクセルシェーダーの色を比較したときの最大値
		e_MIN,		// 現在の色とピクセルシェーダーの色を比較したときの最小値
	};
}


#endif // !D_INCLUDE_GUARD_E_BLEND_OPTION_H_FILE

