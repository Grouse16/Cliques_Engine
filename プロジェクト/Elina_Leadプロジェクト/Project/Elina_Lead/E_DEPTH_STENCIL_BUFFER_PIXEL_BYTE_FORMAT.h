//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：深度ステンシルバッファのピクセルのバイトフォーマットを指定する列挙
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_E_DEPTH_STENCIL_BUFFER_PIXEL_BYTE_FORMAT_H_FILE
#define D_INCLUDE_E_DEPTH_STENCIL_BUFFER_PIXEL_BYTE_FORMAT_H_FILE


// ☆ ネームスペース ☆ //

// 深度ステンシルバッファ用の情報を呼び出すための名前
namespace RENDERING::INFORM::DEPTH_STENCIL
{
	// ☆ 列挙 ☆ //

	// 深度ステンシルバッファのピクセルのバイトフォーマットを指定する列挙
	enum class E_DEPTH_STENCIL_BUFFER_PIXEL_BYTE_FORMAT : unsigned char
	{
		e_2_BYTE,	// ２バイト
		e_4_BYTE,	// ４バイト
	};
}



#endif // !D_INCLUDE_E_DEPTH_STENCIL_BUFFER_PIXEL_BYTE_FORMAT_H_FILE

