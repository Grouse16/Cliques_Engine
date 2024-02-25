//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ブレンド設定の定義を行うファイル
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
	// ブレンドモードを定義する列挙
	enum class E_BLEND_MODE
	{
		e_NORMAL,			// 通常描画
		e_NORMAL_NOT_ALPHA,	// α値を使用せずに描画
		
		e_INVERT,			// 減算方式で描画
		e_INVERT_NOT_ALPHA,	// α値を使用せずに減算方式で描画
	};

	// ピクセルシェーダーとレンダリング画像の色の混ぜ方を指定する列挙
	enum class E_BLEND_OPTION
	{
		e_ADD,		// ピクセルシェーダーの色を加算
		e_SUB,		// ピクセルシェーダーの色を減算
		e_SUB_PIX,	// ピクセルシェーダーの色を現在の色で減算
		e_MAX,		// 現在の色とピクセルシェーダーの色を比較したときの最大値
		e_MIN,		// 現在の色とピクセルシェーダーの色を比較したときの最小値
	};

	// レンダリング画像に書き込むピクセルのデータ形式の列挙
	enum class E_RENDERING_DRAW_FORMAT
	{
		e_BYTE_1_UINT,	// １バイトのUINT
		e_BYTE_2_UINT,	// ２バイトのUINT
		e_BYTE_4_UINT,	// ４バイトのUINT

		e_BYTE_2_FLOAT,	// ２バイトのFLOAT
		e_BYTE_4_FLOAT,	// ４バイトのFLOAT
	};

	// レンダリング画像に書き込む色の種類数の列挙
	enum class E_RENDERING_DRAW_COLOR
	{
		e_R,	// 赤のみ
		e_RG,	// 赤と緑
		e_RGBA,	// 赤と緑と青とα値
	};

}


#endif // !D_INCLUDE_GUARD_E_BLEND_MODE_H_FILE

