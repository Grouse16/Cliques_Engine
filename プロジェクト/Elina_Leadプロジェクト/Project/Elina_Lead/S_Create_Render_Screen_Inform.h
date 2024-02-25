//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリングスクリーンを生成するための情報のシステム
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_CREATE_RENDER_SCREEN_INFORM
#define D_INCLUDE_GUARD_S_CREATE_RENDER_SCREEN_INFORM


// ☆ ファイルひらき ☆ //
#include "E_RENDERING_SCREEN_FORMAT.h"
#include "E_SCREEN_TEXTURE_SETTING.h"


// ☆ ネームスペース ☆ //

// グラフィックを制御するシステムの情報を生成するための情報を呼び出すための名前
namespace RENDERING::API::CREATE
{
	// ☆ 構造体 ☆ //

	// レンダリングスクリーンを生成するための情報のシステム
	struct S_Create_Render_Screen_Inform
	{
		RENDERING::INFORM::RENDERING_SCREEN::E_RENDERING_SCREEN_FORMAT m_rendering_screen_format = RENDERING::INFORM::RENDERING_SCREEN::E_RENDERING_SCREEN_FORMAT::e_2_BYTE;	// レンダリング画像の画素の型

		RENDERING::API::CREATE::E_SCREEN_TEXTURE_SETTING m_screen_texture_setting = RENDERING::API::CREATE::E_SCREEN_TEXTURE_SETTING::e_TEXTURE_2D;	// レンダリング画像のテクスチャの設定

		int m_screen_buffer_sum = 1;		// 生成するスクリーンバッファ数
	};
}

#endif // !D_INCLUDE_GUARD_S_CREATE_RENDER_SCREEN_INFORM

