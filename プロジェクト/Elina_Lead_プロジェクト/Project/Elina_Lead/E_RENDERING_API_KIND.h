//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリング用APIの種類を指定する列挙の定義
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_RENDERING_API_KIND_H_FILE
#define D_INCLUDE_GUARD_E_RENDERING_API_KIND_H_FILE


// ☆ ネームスペース ☆ //

// プラットフォームで分岐する初期化と解放を制御するクラスを呼び出すための名前
namespace PLATFORM
{
	// ☆ 列挙 ☆ //

	// レンダリング用APIの種類を指定する列挙
	enum class E_RENDERING_API_KIND
	{
		e_DX11,		// ダイレクトエックス１１
		e_DX12,		// ダイレクトエックス１２
		e_OPENGL,	// オープンGL
		e_VULKAN,	// バルカン
		e_UNKNOWN,	// 識別不可
	};
}


#endif // !D_INCLUDE_GUARD_E_RENDERING_API_KIND_H_FILE
