//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：フォントデータを画像に変換する時に必要なデータをまとめたパッケージ構造体
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_MAKE_FONT_TO_GRAPH_PAKAGE
#define D_INCLUDE_GUARD_S_MAKE_FONT_TO_GRAPH_PAKAGE


// ☆ ファイルひらき ☆ //
#include <memory>
#include <vector>

#include "C_Rendering_Font_Inform_Base.h"
#include "S_Rect.h"
#include "C_Texture_Map.h"


// ☆ ネームスペース ☆ //

// パッケージ情報のうちフォント系統を呼び出すための名前
namespace PAKAGE::FONT
{
	// ☆ 定数 ☆ //

	// フォントのビットマップの諧調レベル
	enum class E_FONTBIT_MAP_LEVEL
	{
		e_4,	// 0~4
		e_16,	// 0~16
		e_64,	// 0~64
	};


	// ☆ クラス ☆ //

	// フォントデータを画像に変換する時に必要なデータをまとめたパッケージ構造体
	struct S_Make_Font_To_Graph_Package
	{
		std::unique_ptr<RENDERING::GRAPHICS::INSTANCE::C_Rendering_Font_Inform_Base> * attach_font_data = nullptr;	// 設定するフォントのデータ

		ASSET::TEXTURE::C_Texture_Map * tex_map_data = nullptr;	// テクスチャのデータ

		DATA::RECTSETTING::S_Rect draw_rect;	// テクスチャデータの描画範囲

		E_FONTBIT_MAP_LEVEL bit_map_level = E_FONTBIT_MAP_LEVEL::e_16;	// 設定するビットマップレベル

		wchar_t text_code = L'\0';	// 描画する文字
	};
}


#endif // !D_INCLUDE_GUARD_S_MAKE_FONT_TO_GRAPH_PAKAGE
