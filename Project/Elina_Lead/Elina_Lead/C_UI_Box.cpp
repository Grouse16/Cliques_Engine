//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：四角形のUIの図形定義用のデータ
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "UI_Figure_Data.h"


// ☆ ネームスペースの省略 ☆ //
using namespace DATA::FIGURE::UI;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 更新 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：UI用の四角形をレクトから設定する
// 引数   ：S_Rect & 設置位置
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_UI_Box::M_Set_Constant_Pixel_By_Rect(RECTSETTING::S_Rect & in_set_rect)
{
	m_box_pos = in_set_rect;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：色を全ての頂点に設定する
// 引数   ：COLOR & 色
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_UI_Box::M_Set_UI_Box_Color(DATA::COLOR::C_Color & in_color)
{
	m_box_color = in_color;

	return;
}
