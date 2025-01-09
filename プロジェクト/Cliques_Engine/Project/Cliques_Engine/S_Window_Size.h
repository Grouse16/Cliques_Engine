//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ウィンドウのサイズの型の定義
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_WINDOW_SIZE_H_FILE
#define D_INCLUDE_GUARD_S_WINDOW_SIZE_H_FILE


// ☆ ネームスペース ☆ //

// ウィンドウ用のデータを呼び出すための名前
namespace PLATFORM::WINDOW::DATA
{
	// ☆ 構造体 ☆ //

	// ウィンドウのサイズ
	struct S_Window_Size
	{
		int width = 0;	// 画面横のサイズ
		int height = 0;	// 画面縦のサイズ
	};
}


#endif // !D_INCLUDE_GUARD_S_WINDOW_SIZE_H_FILE
