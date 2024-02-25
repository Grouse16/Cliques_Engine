//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：フロート３つ分を管理するクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Float_3.h"


// ☆ ネームスペースの省略 ☆ //
using namespace MATH::FORMAT;


// ☆ 関数 ☆ //

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3::C_Float_3(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：xyzのパラメータを順にセットするコンストラクタ
// 引数   ：float xにセットする値, float yにセットする値, float zにセットする値
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3::C_Float_3(float in_x, float in_y, float in_z)
{
	x = in_x;
	y = in_y;
	z = in_z;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3::~C_Float_3(void)
{
}


//-☆- オペレータ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_3との=演算
// 引数   ：C_Float_3 代入するフロート3値
// 戻り値 ：C_Float_3 代入結果のフロート3値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3 C_Float_3::operator=(C_Float_3 in_equal_float_3)
{
	x = in_equal_float_3.x;
	y = in_equal_float_3.y;
	z = in_equal_float_3.z;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_3との＋演算
// 引数   ：C_Float_3 加算するフロート3値
// 戻り値 ：C_Float_3 加算結果のフロート3値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3 C_Float_3::operator+(C_Float_3 in_plus_float_3)
{
	return C_Float_3(x + in_plus_float_3.x, y + in_plus_float_3.y, z + in_plus_float_3.z);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_3との-演算
// 引数   ：C_Float_3 減算するフロート3値
// 戻り値 ：C_Float_3 減算結果のフロート3値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3 C_Float_3::operator-(C_Float_3 in_minus_float_3)
{
	return C_Float_3(x - in_minus_float_3.x, y - in_minus_float_3.y, z - in_minus_float_3.z);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_3との×演算
// 引数   ：C_Float_3 乗算するフロート3値
// 戻り値 ：C_Float_3 乗算結果のフロート3値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3 C_Float_3::operator*(C_Float_3 in_multiple_float_3)
{
	return C_Float_3(x * in_multiple_float_3.x, y * in_multiple_float_3.y, z * in_multiple_float_3.z);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_3との/演算
// 引数   ：C_Float_3 除算するフロート3値
// 戻り値 ：C_Float_3 除算結果のフロート3値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3 C_Float_3::operator/(C_Float_3 in_division_float_3)
{
	return C_Float_3(x / in_division_float_3.x, y / in_division_float_3.y, z / in_division_float_3.z);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_3との%演算
// 引数   ：C_Float_3 剰余算するフロート3値
// 戻り値 ：C_Float_3 剰余算結果のフロート3値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3 C_Float_3::operator%(C_Float_3 in_surplus_float_3)
{
	return C_Float_3((x - (int)(x / in_surplus_float_3.x)), (y - (int)(y / in_surplus_float_3.y)), (z - (int)(z / in_surplus_float_3.z)));
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_3との＋=演算
// 引数   ：C_Float_3 加算代入するフロート3値
// 戻り値 ：C_Float_3 加算代入結果のフロート3値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3 C_Float_3::operator+=(C_Float_3 in_plus_equal_float_3)
{
	x += in_plus_equal_float_3.x;
	y += in_plus_equal_float_3.y;
	z += in_plus_equal_float_3.z;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_3との-=演算
// 引数   ：C_Float_3 減算代入するフロート3値
// 戻り値 ：C_Float_3 減算代入結果のフロート3値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3 C_Float_3::operator-=(C_Float_3 in_minus_equal_float_3)
{
	x -= in_minus_equal_float_3.x;
	y -= in_minus_equal_float_3.y;
	z -= in_minus_equal_float_3.z;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_3との×=演算
// 引数   ：C_Float_3 乗算代入するフロート3値
// 戻り値 ：C_Float_3 乗算代入結果のフロート3値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3 C_Float_3::operator*=(C_Float_3 in_multiple_equal_float_3)
{
	x *= in_multiple_equal_float_3.x;
	y *= in_multiple_equal_float_3.y;
	z *= in_multiple_equal_float_3.z;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_3との/=演算
// 引数   ：C_Float_3 除算代入するフロート3値
// 戻り値 ：C_Float_3 除算代入結果のフロート3値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3 C_Float_3::operator/=(C_Float_3 in_divide_equal_float_3)
{
	x /= in_divide_equal_float_3.x;
	y /= in_divide_equal_float_3.y;
	z /= in_divide_equal_float_3.z;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_3との%=演算
// 引数   ：C_Float_3 剰余算代入するフロート3値
// 戻り値 ：C_Float_3 剰余算代入結果のフロート3値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3 C_Float_3::operator%=(C_Float_3 in_surplus_equal_float_3)
{
	x = x - (int)(x / in_surplus_equal_float_3.x);
	y = y - (int)(y / in_surplus_equal_float_3.y);
	z = z - (int)(z / in_surplus_equal_float_3.z);

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの=演算
// 引数   ：float 代入するフロート値
// 戻り値 ：C_Float_3 代入結果のフロート3値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3 C_Float_3::operator=(float in_equal_float)
{
	x = in_equal_float;
	y = in_equal_float;
	z = in_equal_float;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの＋演算
// 引数   ：float 加算するフロート値
// 戻り値 ：C_Float_3 加算結果のフロート3値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3 C_Float_3::operator+(float in_plus_float)
{
	return C_Float_3(x + in_plus_float, y + in_plus_float, z + in_plus_float);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの-演算
// 引数   ：float 減算するフロート値
// 戻り値 ：C_Float_3 減算結果のフロート3値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3 C_Float_3::operator-(float in_minus_float)
{
	return C_Float_3(x - in_minus_float, y - in_minus_float, z - in_minus_float);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの×演算
// 引数   ：float 乗算するフロート値
// 戻り値 ：C_Float_3 乗算結果のフロート3値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3 C_Float_3::operator*(float in_multiple_float)
{
	return C_Float_3(x * in_multiple_float, y * in_multiple_float, z * in_multiple_float);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの/演算
// 引数   ：float 除算するフロート値
// 戻り値 ：C_Float_3 除算結果のフロート3値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3 C_Float_3::operator/(float in_division_float)
{
	return C_Float_3(x / in_division_float, y / in_division_float, z / in_division_float);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの%演算
// 引数   ：float 剰余算するフロート値
// 戻り値 ：C_Float_3 剰余算結果のフロート3値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3 C_Float_3::operator%(float in_surplus_float)
{
	return C_Float_3((x - (int)(x / in_surplus_float)), (y - (int)(y / in_surplus_float)), (z - (int)(z / in_surplus_float)));
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの＋=演算
// 引数   ：float 加算代入するフロート値
// 戻り値 ：C_Float_3 加算代入結果のフロート3値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3 C_Float_3::operator+=(float in_plus_equal_float)
{
	x += in_plus_equal_float;
	y += in_plus_equal_float;
	z += in_plus_equal_float;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの-=演算
// 引数   ：float 減算代入するフロート値
// 戻り値 ：C_Float_3 減算代入結果のフロート3値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3 C_Float_3::operator-=(float in_minus_equal_float)
{
	x -= in_minus_equal_float;
	y -= in_minus_equal_float;
	z -= in_minus_equal_float;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの×=演算
// 引数   ：float 乗算代入するフロート値
// 戻り値 ：C_Float_3 乗算代入結果のフロート3値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3 C_Float_3::operator*=(float in_multiple_equal_float)
{
	x *= in_multiple_equal_float;
	y *= in_multiple_equal_float;
	z *= in_multiple_equal_float;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの/=演算
// 引数   ：float 除算代入するフロート値
// 戻り値 ：C_Float_3 除算代入結果のフロート3値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3 C_Float_3::operator/=(float in_divide_equal_float)
{
	x /= in_divide_equal_float;
	y /= in_divide_equal_float;
	z /= in_divide_equal_float;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの%=演算
// 引数   ：float 剰余算代入するフロート値
// 戻り値 ：C_Float_3 剰余算代入結果のフロート3値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_3 C_Float_3::operator%=(float in_surplus_equal_float)
{
	x = x - (int)(x / in_surplus_equal_float);
	y = y - (int)(y / in_surplus_equal_float);
	z = z - (int)(z / in_surplus_equal_float);

	return *this;
}
