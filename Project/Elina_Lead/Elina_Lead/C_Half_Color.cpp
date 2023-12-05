//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：２バイトの色を定義する構造体
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ネームスペースの省略 ☆ //
#include "C_Half_Color.h"


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
C_Half_Color::C_Half_Color(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：０～１で色を設定する時のコンストラクタ
// 引数   ：float 赤, float 緑, float 青, float 透明度
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Half_Color::C_Half_Color(float in_red, float in_green, float in_blue, float in_alpha)
{
	m_r = DirectX::PackedVector::XMConvertFloatToHalf(in_red);
	m_g = DirectX::PackedVector::XMConvertFloatToHalf(in_green);
	m_b = DirectX::PackedVector::XMConvertFloatToHalf(in_blue);
	m_a = DirectX::PackedVector::XMConvertFloatToHalf(in_alpha);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：０～２５５で色を設定する時のコンストラクタ
// 引数   ：int 赤, int 緑, int 青, int 透明度
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Half_Color::C_Half_Color(int in_red, int in_green, int in_blue, int in_alpha)
{
	m_r = DirectX::PackedVector::XMConvertFloatToHalf(in_red / 255.0f);
	m_g = DirectX::PackedVector::XMConvertFloatToHalf(in_green / 255.0f);
	m_b = DirectX::PackedVector::XMConvertFloatToHalf(in_blue / 255.0f);
	m_a = DirectX::PackedVector::XMConvertFloatToHalf(in_alpha / 255.0f);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Half_Color::~C_Half_Color(void)
{
	return;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：０～１で色を設定する時のコンストラクタ
// 引数   ：float 赤, float 緑, float 青, float 透明度
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Half_Color::M_Set_Color_By_0_1(float in_red, float in_green, float in_blue, float in_alpha)
{
	m_r = DirectX::PackedVector::XMConvertFloatToHalf(in_red);
	m_g = DirectX::PackedVector::XMConvertFloatToHalf(in_green);
	m_b = DirectX::PackedVector::XMConvertFloatToHalf(in_blue);
	m_a = DirectX::PackedVector::XMConvertFloatToHalf(in_alpha);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：０～２５５で色を設定する時のコンストラクタ
// 引数   ：int 赤, int 緑, int 青, int 透明度
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Half_Color::M_Set_Color_By_0_255(int in_red, int in_green, int in_blue, int in_alpha)
{
	m_r = DirectX::PackedVector::XMConvertFloatToHalf(in_red / 255.0f);
	m_g = DirectX::PackedVector::XMConvertFloatToHalf(in_green / 255.0f);
	m_b = DirectX::PackedVector::XMConvertFloatToHalf(in_blue / 255.0f);
	m_a = DirectX::PackedVector::XMConvertFloatToHalf(in_alpha / 255.0f);

	return;
}


//-☆- オペレーター -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：色同士の掛け算
// 引数   ：C_Half_Color 色情報
// 戻り値 ：C_Half_Color 色情報の掛け算結果
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Half_Color C_Half_Color::operator*(C_Half_Color in_color)
{
	// ☆ 変数宣言 ☆ //
	C_Half_Color result_value;	// 結果の色情報


	result_value.m_r = m_r * in_color.m_r;
	result_value.m_g = m_g * in_color.m_g;
	result_value.m_b = m_b * in_color.m_b;
	result_value.m_a = m_a * in_color.m_a;

	return result_value;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：色を設定する
// 引数   ：C_Half_Color 色情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Half_Color::operator=(C_Half_Color in_color)
{
	m_r = in_color.m_r;
	m_g = in_color.m_g;
	m_b = in_color.m_b;
	m_a = in_color.m_a;

	return;
}

