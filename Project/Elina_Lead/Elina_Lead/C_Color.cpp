//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：色定義用のファイル
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Color.h"


// ☆ ネームスペースの省略 ☆ //
using namespace DATA::COLOR;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Color::C_Color(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：０～１で色を設定する時のコンストラクタ
// 引数   ：float 赤, float 緑, float 青, float 透明度
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Color::C_Color(float in_r, float in_g, float in_b, float in_a)
{
	m_r = in_r;
	m_g = in_g;
	m_b = in_b;
	m_a = in_a;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：０～２５５で色を設定する時のコンストラクタ
// 引数   ：int 赤, int 緑, int 青, int 透明度
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Color::C_Color(int in_r, int in_g, int in_b, int in_a)
{
	m_r = in_r / 255.0f;
	m_g = in_g / 255.0f;
	m_b = in_b / 255.0f;
	m_a = in_a / 255.0f;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Color::~C_Color(void)
{
	return;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：０～１で色の設定を行う
// 引数   ：float 赤, float 緑, float 青, float 透明度
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Color::M_Set_Color_By_0_1(float in_r, float in_g, float in_b, float in_a)
{
	m_r = in_r;
	m_g = in_g;
	m_b = in_b;
	m_a = in_a;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：０～２５５で色の設定を行う
// 引数   ：int 赤, int 緑, int 青, int 透明度
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Color::M_Set_Color_By_0_255(int in_r, int in_g, int in_b, int in_a)
{
	m_r = in_r / static_cast<float>(255);
	m_g = in_g / static_cast<float>(255);
	m_b = in_b / static_cast<float>(255);
	m_a = in_a / static_cast<float>(255);

	return;
}


//-☆- オペレーター -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：色同士の掛け算
// 引数   ：C_Color 色情報
// 戻り値 ：C_Color 色情報の掛け算結果
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Color C_Color::operator*(C_Color in_color)
{
	// ☆ 変数宣言 ☆ //
	C_Color result;	// 計算結果


	// 色を合成する
	result.m_r = in_color.m_r * m_r;
	result.m_g = in_color.m_g * m_g;
	result.m_b = in_color.m_b * m_b;
	result.m_a = in_color.m_a * m_a;

	return result;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：色を設定する
// 引数   ：C_Color 色情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Color::operator=(C_Color in_color)
{
	// 色をセットする
	m_r = in_color.m_r;
	m_g = in_color.m_g;
	m_b = in_color.m_b;
	m_a = in_color.m_a;

	return;
}

