//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：テクスチャの色を定義するファイル
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_TEX_COLOR
#define D_INCLUDE_GUARD_S_TEX_COLOR


// ☆ ネームスペース ☆ //

// テクスチャ用の定義を呼び出すための名前
namespace DATA::TEXTURE
{
	// ☆ 構造体 ☆ //

	// テクスチャ用のカラーの構造体
	struct S_Tex_Color
	{
		unsigned char r = 0;	// 赤
		unsigned char g = 0;	// 緑
		unsigned char b = 0;	// 青
		unsigned char a = 0;	// 透明度
	};
}


#endif // !D_INCLUDE_GUARD_S_TEX_COLOR
