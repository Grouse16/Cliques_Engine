//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：四角形の頂点設定用の配列番号
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_E_BOX_VERTEX_SETTING_H_FILE
#define D_INCLUDE_GUARD_E_BOX_VERTEX_SETTING_H_FILE


// ☆ ネームスペース ☆ //

// 頂点設定用のデータを呼び出すための名前
namespace DATA::VERTEX::SETTING
{
	// ☆ 定数 ☆ //

	// 四角形の頂点設定用の配列番号
	enum class E_BOX_VERTEX_SETTING
	{
		e_LEFT_TOP,		// 左上頂点
		e_RIGHT_TOP,	// 右上頂点
		e_RIGHT_BOTTOM,	// 右下頂点
		e_LEFT_BOTTOM,	// 左下頂点

		e_SUM	// 頂点の総数
	};


	// インデックスバッファの設定用番号の列挙
	enum class E_BOX_INDEX_SETTING
	{
		e_INDEX_1 = (int)E_BOX_VERTEX_SETTING::e_LEFT_TOP,		// 三角形１の左上頂点
		e_INDEX_2 = (int)E_BOX_VERTEX_SETTING::e_RIGHT_TOP,	// 三角形１の右上頂点
		e_INDEX_3 = (int)E_BOX_VERTEX_SETTING::e_RIGHT_BOTTOM,	// 三角形１の右下頂点

		e_INDEX_4 = (int)E_BOX_VERTEX_SETTING::e_LEFT_TOP,		// 三角形２の左上頂点
		e_INDEX_5 = (int)E_BOX_VERTEX_SETTING::e_RIGHT_BOTTOM,	// 三角形２の右下頂点
		e_INDEX_6 = (int)E_BOX_VERTEX_SETTING::e_LEFT_BOTTOM,	// 三角形２の左下頂点

		e_SUM,	// インデックスの総数
	};
}

#endif // !D_INCLUDE_GUARD_E_BOX_VERTEX_SETTING_H_FILE
