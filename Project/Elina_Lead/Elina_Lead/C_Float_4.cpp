//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：フロート４つ分を管理するクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Float_4.h"


// ☆ ネームスペースの省略 ☆ //
using namespace MATH::FORMAT;


// ☆ クラス ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4::C_Float_4(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：xyzwのパラメータを順にセットするコンストラクタ
// 引数   ：float xにセットする値, float yにセットする値, float zにセットする値, float wにセットする値
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4::C_Float_4(float in_x, float in_y, float in_z, float in_w)
{
	x = in_x;
	y = in_y;
	z = in_z;
	w = in_w;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4::~C_Float_4(void)
{
	return;
}


//==☆ オペレータ ☆==//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_4との=演算
// 引数   ：C_Float_4 代入するフロート4値
// 戻り値 ：C_Float_4 代入結果のフロート4値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4 C_Float_4::operator=(C_Float_4 in_equal_float_4)
{
	x = in_equal_float_4.x;
	y = in_equal_float_4.y;
	z = in_equal_float_4.z;
	w = in_equal_float_4.w;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_4との＋演算
// 引数   ：C_Float_4 加算するフロート4値
// 戻り値 ：C_Float_4 加算結果のフロート4値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4 C_Float_4::operator+(C_Float_4 in_plus_float_4)
{
	return C_Float_4(x + in_plus_float_4.x, y + in_plus_float_4.y, z + in_plus_float_4.z, w + in_plus_float_4.w);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_4との-演算
// 引数   ：C_Float_4 減算するフロート4値
// 戻り値 ：C_Float_4 減算結果のフロート4値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4 C_Float_4::operator-(C_Float_4 in_minus_float_4)
{
	return C_Float_4(x - in_minus_float_4.x, y - in_minus_float_4.y, z - in_minus_float_4.z, w - in_minus_float_4.w);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_4との×演算
// 引数   ：C_Float_4 乗算するフロート4値
// 戻り値 ：C_Float_4 乗算結果のフロート4値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4 C_Float_4::operator*(C_Float_4 in_multiple_float_4)
{
	return C_Float_4(x * in_multiple_float_4.x, y * in_multiple_float_4.y, z * in_multiple_float_4.z, w * in_multiple_float_4.w);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_4との/演算
// 引数   ：C_Float_4 除算するフロート4値
// 戻り値 ：C_Float_4 除算結果のフロート4値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4 C_Float_4::operator/(C_Float_4 in_division_float_4)
{
	return C_Float_4(x / in_division_float_4.x, y / in_division_float_4.y, z / in_division_float_4.z, w / in_division_float_4.w);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_4との%演算
// 引数   ：C_Float_4 剰余算するフロート4値
// 戻り値 ：C_Float_4 剰余算結果のフロート4値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4 C_Float_4::operator%(C_Float_4 in_surplus_float_4)
{
	return C_Float_4((x - (int)(x / in_surplus_float_4.x)), (y - (int)(y / in_surplus_float_4.y)), (z - (int)(z / in_surplus_float_4.z)), (w - (int)(w / in_surplus_float_4.w)));
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_4との＋=演算
// 引数   ：C_Float_4 加算代入するフロート4値
// 戻り値 ：C_Float_4 加算代入結果のフロート4値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4 C_Float_4::operator+=(C_Float_4 in_plus_equal_float_4)
{
	x += in_plus_equal_float_4.x;
	y += in_plus_equal_float_4.y;
	z += in_plus_equal_float_4.z;
	w += in_plus_equal_float_4.w;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_4との-=演算
// 引数   ：C_Float_4 減算代入するフロート4値
// 戻り値 ：C_Float_4 減算代入結果のフロート4値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4 C_Float_4::operator-=(C_Float_4 in_minus_equal_float_4)
{
	x -= in_minus_equal_float_4.x;
	y -= in_minus_equal_float_4.y;
	z -= in_minus_equal_float_4.z;
	w -= in_minus_equal_float_4.w;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_4との×=演算
// 引数   ：C_Float_4 乗算代入するフロート4値
// 戻り値 ：C_Float_4 乗算代入結果のフロート4値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4 C_Float_4::operator*=(C_Float_4 in_multiple_equal_float_4)
{
	x *= in_multiple_equal_float_4.x;
	y *= in_multiple_equal_float_4.y;
	z *= in_multiple_equal_float_4.z;
	w *= in_multiple_equal_float_4.w;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_4との/=演算
// 引数   ：C_Float_4 除算代入するフロート4値
// 戻り値 ：C_Float_4 除算代入結果のフロート4値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4 C_Float_4::operator/=(C_Float_4 in_divide_equal_float_4)
{
	x /= in_divide_equal_float_4.x;
	y /= in_divide_equal_float_4.y;
	z /= in_divide_equal_float_4.z;
	w /= in_divide_equal_float_4.w;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_4との%=演算
// 引数   ：C_Float_4 剰余算代入するフロート4値
// 戻り値 ：C_Float_4 剰余算代入結果のフロート4値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4 C_Float_4::operator%=(C_Float_4 in_surplus_equal_float_4)
{
	x = x - (int)(x / in_surplus_equal_float_4.x);
	y = y - (int)(y / in_surplus_equal_float_4.y);
	z = z - (int)(z / in_surplus_equal_float_4.z);
	w = w - (int)(w / in_surplus_equal_float_4.w);

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの=演算
// 引数   ：float 代入するフロート値
// 戻り値 ：C_Float_4 代入結果のフロート4値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4 C_Float_4::operator=(float in_equal_float)
{
	return C_Float_4(in_equal_float, in_equal_float, in_equal_float, in_equal_float);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの＋演算
// 引数   ：float 加算するフロート値
// 戻り値 ：C_Float_4 加算結果のフロート4値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4 C_Float_4::operator+(float in_plus_float)
{
	return C_Float_4(x + in_plus_float, y + in_plus_float, z + in_plus_float, w + in_plus_float);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの-演算
// 引数   ：float 減算するフロート値
// 戻り値 ：C_Float_4 減算結果のフロート4値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4 C_Float_4::operator-(float in_minus_float)
{
	return C_Float_4(x - in_minus_float, y - in_minus_float, z - in_minus_float, w - in_minus_float);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの×演算
// 引数   ：float 乗算するフロート値
// 戻り値 ：C_Float_4 乗算結果のフロート4値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4 C_Float_4::operator*(float in_multiple_float)
{
	return C_Float_4(x * in_multiple_float, y * in_multiple_float, w * in_multiple_float, z * in_multiple_float);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの/演算
// 引数   ：float 除算するフロート値
// 戻り値 ：C_Float_4 除算結果のフロート4値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4 MATH::FORMAT::C_Float_4::operator/(float in_divide_float)
{
	return C_Float_4(x / in_divide_float, y / in_divide_float, w / in_divide_float, z / in_divide_float);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの%演算
// 引数   ：float 剰余算するフロート値
// 戻り値 ：C_Float_4 剰余算結果のフロート4値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4 C_Float_4::operator%(float in_surplus_float)
{
	return C_Float_4((x - (int)(x / in_surplus_float)), (y - (int)(y / in_surplus_float)), (z - (int)(z / in_surplus_float)), (w - (int)(w / in_surplus_float)));
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの＋=演算
// 引数   ：float 加算代入するフロート値
// 戻り値 ：C_Float_4 加算代入結果のフロート4値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4 C_Float_4::operator+=(float in_plus_equal_float)
{
	x += in_plus_equal_float;
	y += in_plus_equal_float;
	z += in_plus_equal_float;
	w += in_plus_equal_float;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの-=演算
// 引数   ：float 減算代入するフロート値
// 戻り値 ：C_Float_4 減算代入結果のフロート4値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4 C_Float_4::operator-=(float in_minus_equal_float)
{
	x -= in_minus_equal_float;
	y -= in_minus_equal_float;
	z -= in_minus_equal_float;
	w -= in_minus_equal_float;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの×=演算
// 引数   ：float 乗算代入するフロート値
// 戻り値 ：C_Float_4 乗算代入結果のフロート4値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4 C_Float_4::operator*=(float in_multiple_equal_float)
{
	x *= in_multiple_equal_float;
	y *= in_multiple_equal_float;
	z *= in_multiple_equal_float;
	w *= in_multiple_equal_float;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの/=演算
// 引数   ：float 除算代入するフロート値
// 戻り値 ：C_Float_4 除算代入結果のフロート4値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4 C_Float_4::operator/=(float in_divide_equal_float)
{
	x /= in_divide_equal_float;
	y /= in_divide_equal_float;
	z /= in_divide_equal_float;
	w /= in_divide_equal_float;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの%=演算
// 引数   ：float 剰余算代入するフロート値
// 戻り値 ：C_Float_4 剰余算代入結果のフロート4値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_4 C_Float_4::operator%=(float in_surplus_equal_float)
{
	x = x - (int)(x / in_surplus_equal_float);
	y = y - (int)(y / in_surplus_equal_float);
	z = z - (int)(z / in_surplus_equal_float);
	w = w - (int)(w / in_surplus_equal_float);

	return *this;
}

