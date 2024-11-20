//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリング画像の型の定義
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GAURD_E_RENDERING_SCREEN_FORMAT_H_FILE
#define D_INCLUDE_GAURD_E_RENDERING_SCREEN_FORMAT_H_FILE


// ☆ ネームスペース ☆ //

// レンダリング画像用の定義を呼び出すための名前
namespace RENDERING::INFORM::RENDERING_SCREEN
{
	// ☆ 列挙 ☆ //
	
	// レンダリング画像の型を設定するための列挙
	enum class E_RENDERING_SCREEN_FORMAT : char
	{
		e_2_BYTE,	// RGBAそれぞれ２バイト
	};
}


#endif // !D_INCLUDE_GAURD_E_RENDERING_SCREEN_FORMAT_H_FILE

