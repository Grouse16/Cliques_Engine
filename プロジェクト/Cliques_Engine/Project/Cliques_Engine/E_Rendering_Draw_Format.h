//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ピクセルシェーダーの出力値のバイト数およびデータ型の定義の列挙
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_RENDERING_DRAW_FORMAT_H_FILE
#define D_INCLUDE_GUARD_E_RENDERING_DRAW_FORMAT_H_FILE


// ☆ ネームスペース ☆ //

// ブレンド定義用の情報を呼び出すための名前
namespace RENDERING::INFORM::BLEND
{
	// ☆ 列挙 ☆ //

	// ピクセルシェーダーの出力値のバイト数およびデータ型の定義
	enum class E_RENDERING_DRAW_FORMAT
	{
		e_BYTE_1_UINT,	// １バイトのUINT
		e_BYTE_2_UINT,	// ２バイトのUINT
		e_BYTE_4_UINT,	// ４バイトのUINT

		e_BYTE_2_FLOAT,	// ２バイトのFLOAT
		e_BYTE_4_FLOAT,	// ４バイトのFLOAT
	};
}


#endif // !D_INCLUDE_GUARD_E_RENDERING_DRAW_FORMAT_H_FILE

