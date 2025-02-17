//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：OSの種類を指定する列挙の定義
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_PLATFORM_NUMBER_H_FILE
#define D_INCLUDE_GUARD_E_PLATFORM_NUMBER_H_FILE


// ☆ ネームスペース ☆ //

// プラットフォームで分岐する初期化と解放を制御するクラスを呼び出すための名前
namespace PLATFORM
{
	// OSの種類を指定する列挙
	enum class E_OS_KIND
	{
		e_WINDOWS,	// ウィンドウズ
		e_MAC,		// マック
		e_LINUX,	// リナックス
		e_UNIX,		// ユニックス
		e_UNKNOWN,	// 識別不可
	};
}


#endif // !D_INCLUDE_GUARD_E_PLATFORM_NUMBER_H_FILE

