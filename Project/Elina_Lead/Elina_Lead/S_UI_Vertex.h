//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：UI用の頂点の定義の構造体
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_UI_VERTEX_H_FILE
#define D_INCLUDE_GUARD_S_UI_VERTEX_H_FILE


// ☆ ファイルひらき ☆ //
#include "2D_Position_Data.h"
#include "C_Color.h"
#include "Texture_UV_Data.h"


// ☆ ネームスペース ☆ //

// 頂点データを呼び出すための名前
namespace DATA::VERTEX
{
	// ☆ 構造体 ☆ //

	// UI用の頂点の定義の構造体
	struct S_UI_Vertex
	{
		DATA::POSITION_2D::C_2D_Position position;	// ピクセルでの頂点座標

		DATA::COLOR::C_Color color;	// 色

		DATA::TEXTURE_UV::C_Texture_UV uv;	// テクスチャ座標
	};
}

#endif // !D_INCLUDE_GUARD_S_UI_VERTEX_H_FILE
