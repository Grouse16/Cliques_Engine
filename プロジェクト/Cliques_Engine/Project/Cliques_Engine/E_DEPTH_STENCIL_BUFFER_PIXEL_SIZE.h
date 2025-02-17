//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：深度ステンシルバッファのピクセル数を指定する列挙
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE_H_FILE
#define D_INCLUDE_GUARD_E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE_H_FILE


// ☆ ネームスペース ☆ //

// 深度ステンシルバッファ用の情報を呼び出すための名前
namespace RENDERING::INFORM::DEPTH_STENCIL
{
	// ☆ 列挙 ☆ //

	// 深度ステンシルバッファのピクセル数を指定する列挙
	enum class E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE : unsigned int
	{
		e_WIDTH_SIZE = 1920,	// 横幅のピクセル数
		e_HEIGHT_SIZE = 1080,	// 縦幅のピクセル数

		e_ALL_SIZE = e_WIDTH_SIZE * e_HEIGHT_SIZE,	// 全体のサイズ
	};
}


#endif // !D_INCLUDE_GUARD_E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE_H_FILE

