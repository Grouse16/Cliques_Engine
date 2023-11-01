

// ☆ ファイルひらき ☆ //
#include "C_Float4.h"


// ☆ ネームスペースの省略 ☆ //
using namespace MATH;


// ☆ クラス ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float4::C_Float4(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：xyzwのパラメータを順にセットするコンストラクタ
// 引数   ：float xにセットする値, float yにセットする値, float zにセットする値, float wにセットする値
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float4::C_Float4(float in_x, float in_y, float in_z, float in_w)
{
	x = in_x;
	y = in_y;
	z = in_z;
	w = in_w;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：xyzのパラメータを順にセットするコンストラクタ
// 引数   ：float xにセットする値, float yにセットする値, float zにセットする値
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float4::C_Float4(float in_x, float in_y, float in_z)
{
	x = in_x;
	y = in_y;
	z = in_z;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：xyのパラメータを順にセットするコンストラクタ
// 引数   ：float xにセットする値, float yにセットする値
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float4::C_Float4(float in_x, float in_y)
{
	x = in_x;
	y = in_y;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：xのパラメータを順にセットするコンストラクタ
// 引数   ：float xにセットする値
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float4::C_Float4(float in_x)
{
	x = in_x;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float4::~C_Float4(void)
{
	return;
}


//==☆ オペレータ ☆==//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：Float4とのイコール演算
// 引数   ：C_Float4 & 代入するフロート4値
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Float4::operator=(C_Float4 & in_float4)
{
	x = in_float4.x;
	y = in_float4.y;
	z = in_float4.z;
	w = in_float4.w;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：Float4とのイコール演算
// 引数   ：C_Float4 代入するフロート4値
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Float4::operator=(C_Float4 in_float4)
{
	x = in_float4.x;
	y = in_float4.y;
	z = in_float4.z;
	w = in_float4.w;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：Float4との＋演算
// 引数   ：C_Float4 & 加算するフロート4値
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float4 C_Float4::operator+(C_Float4 & in_float4)
{
	return C_Float4(x + in_float4.x, y + in_float4.y, z + in_float4.z, w + in_float4.w);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：Float4との＋演算
// 引数   ：C_Float4 加算するフロート4値
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float4 C_Float4::operator+(C_Float4 in_float4)
{
	return C_Float4(x + in_float4.x, y + in_float4.y, z + in_float4.z, w + in_float4.w);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの＋演算
// 引数   ：float & 加算するフロート値
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float4 C_Float4::operator+(float & in_float)
{
	return C_Float4(x + in_float, y + in_float, z + in_float, w + in_float);
}

