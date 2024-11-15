//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ウィンドウの座標の型の定義
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_WINDOW_POSITION_H_FILE
#define D_INCLUDE_GUARD_S_WINDOW_POSITION_H_FILE


// ☆ ネームスペース ☆ //

// OSの基底クラスを呼び出すための名前
namespace OS
{
	// ☆ 構造体 ☆//

	// ウィンドウの座標の構造体
	struct S_Window_Position
	{
		int position_left_x = 0;	// ウィンドウの左端
		int position_right_x = 0;	// ウィンドウの右端
		int position_top_y = 0;		// ウィンドウの上端
		int position_bottom_y = 0;	// ウィンドウの下橋
	};
}


#endif // !D_INCLUDE_GUARD_S_WINDOW_POSITION_H_FILE
