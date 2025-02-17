//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：深度ステンシルバッファを生成するための情報
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_CREATE_DEPTH_STENCIL_BUFFER_INFORM_H_FILE
#define D_INCLUDE_GUARD_S_CREATE_DEPTH_STENCIL_BUFFER_INFORM_H_FILE


// ☆ ファイルひらき ☆ //
#include "E_DEPTH_STENCIL_BUFFER_PIXEL_BYTE_FORMAT.h"


// ☆ ネームスペース ☆ //

// レンダリングAPIに使用するシステムを生成するための情報
namespace RENDERING::API::CREATE
{
	// ☆ 構造体 ☆ //

	// 深度ステンシルバッファを生成するための情報
	struct S_Create_Depth_Stencil_Buffer_Inform
	{
		RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_BYTE_FORMAT m_byte_format = RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_BYTE_FORMAT::e_4_BYTE;	// ピクセルのバイト型
	};
}


#endif // !D_INCLUDE_GUARD_S_CREATE_DEPTH_STENCIL_BUFFER_INFORM_H_FILE

