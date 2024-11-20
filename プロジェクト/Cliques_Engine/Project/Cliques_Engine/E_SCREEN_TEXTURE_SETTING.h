//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：スクリーン画面のテクスチャの設定
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_SCREEN_TEXTURE_SETTING_H_FILE
#define D_INCLUDE_GUARD_E_SCREEN_TEXTURE_SETTING_H_FILE


// ☆ ネームスペース ☆ //

// グラフィックを制御するシステムの情報を生成するための情報を呼び出すための名前
namespace RENDERING::API::CREATE
{
	// ☆ 列挙 ☆ //

	// スクリーン画面のテクスチャの設定を行うための列挙
	enum class E_SCREEN_TEXTURE_SETTING : char
	{
		e_BUFFER,		// バッファの設定
		e_TEXTURE_1D,	// 1次元テクスチャの設定
		e_TEXTURE_2D,	// 2次元テクスチャの設定
		e_TEXTURE_3D,	// 3次元テクスチャの設定
	};
}


#endif // !D_INCLUDE_GUARD_E_SCREEN_TEXTURE_SETTING_H_FILE


