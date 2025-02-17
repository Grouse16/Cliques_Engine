//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ピクセル単位で四角形を表すシステム
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_S_RECT_H_FILE
#define D_INCLUDE_GUARD_S_RECT_H_FILE


// ☆ ネームスペース ☆ //

// ピクセル範囲を設定する定義を呼び出すための名前
namespace DATA::RECTSETTING
{
	// ☆ 構造体 ☆ //
	
	// ピクセル単位で四角形を表すパラメータの構造体
	struct S_Rect
	{
		// ☆ 変数宣言 ☆ //
		int left_x = 0;		// 左端のｘピクセル座標
		int right_x = 0;	// 右端のｘピクセル座標
		int top_y = 0;		// 上端のｙピクセル座標
		int bottom_y = 0;	// 下端のｙピクセル座標
	};
}


#endif // !D_INCLUDE_GUARD_S_RECT_H_FILE
