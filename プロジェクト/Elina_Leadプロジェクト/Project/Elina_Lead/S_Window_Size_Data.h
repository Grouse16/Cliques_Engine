//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ウィンドウのサイズ用の型の定義
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_WINDOW_SIZE_DATA_H_FILE
#define D_INCLUDE_GUARD_S_WINDOW_SIZE_DATA_H_FILE


// ☆ ネームスペース ☆ //

// OS制御用システムを呼び出すための名前
namespace OS
{
	// ☆ 構造体 ☆ //

	// ウィンドウのサイズの構造体
	struct S_Window_Size_Data
	{
		int width = 0;	// 画面横のサイズ
		int height = 0;	// 画面縦のサイズ
	};
}


#endif // !D_INCLUDE_GUARD_S_WINDOW_SIZE_DATA_H_FILE
