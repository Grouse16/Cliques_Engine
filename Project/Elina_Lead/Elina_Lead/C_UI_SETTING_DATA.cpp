//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：UI設定用の変数群
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "UI_Figure_Data.h"


// ☆ ネームスペースの省略 ☆ //
using namespace DATA::FIGURE::UI;


// ☆ 変数宣言 ☆ //
C_UI_SETTING_DATA C_UI_SETTING_DATA::m_this;	// 自身を定義するための変数

float C_UI_SETTING_DATA::ui_width;
float C_UI_SETTING_DATA::ui_height;
float C_UI_SETTING_DATA::aspect_x;
float C_UI_SETTING_DATA::aspect_y;
float C_UI_SETTING_DATA::percent_of_aspect_x;
float C_UI_SETTING_DATA::percent_of_aspect_y;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- 初期化 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_UI_SETTING_DATA::C_UI_SETTING_DATA(void)
{
	ui_width = 1920;
	ui_height = 1080;

	aspect_x = 16;
	aspect_y = 9;

	percent_of_aspect_x = aspect_x / (aspect_x + aspect_y);
	percent_of_aspect_y = aspect_y / (aspect_x + aspect_y);

	return;
}