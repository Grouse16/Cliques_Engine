//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：フロート３つ分を管理するクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Float_2.h"


// ☆ ネームスペースの省略 ☆ //
using namespace MATH::FORMAT;


// ☆ 関数 ☆ //

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2::C_Float_2(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：xyのパラメータを順にセットするコンストラクタ
// 引数   ：float xにセットする値, float yにセットする値
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2::C_Float_2(float in_x, float in_y)
{
	x = in_x;
	y = in_y;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2::~C_Float_2(void)
{
}


//-☆- オペレータ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_2との=演算
// 引数   ：C_Float_2 代入するフロート2値
// 戻り値 ：C_Float_2 代入結果のフロート2値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2 C_Float_2::operator=(C_Float_2 in_equal_float_2)
{
	x = in_equal_float_2.x;
	y = in_equal_float_2.y;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_2との＋演算
// 引数   ：C_Float_2 加算するフロート2値
// 戻り値 ：C_Float_2 加算結果のフロート2値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2 C_Float_2::operator+(C_Float_2 in_plus_float_2)
{
	return C_Float_2(x + in_plus_float_2.x, y + in_plus_float_2.y);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_2との-演算
// 引数   ：C_Float_2 減算するフロート2値
// 戻り値 ：C_Float_2 減算結果のフロート2値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2 C_Float_2::operator-(C_Float_2 in_minus_float_2)
{
	return C_Float_2(x - in_minus_float_2.x, y - in_minus_float_2.y);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_2との×演算
// 引数   ：C_Float_2 乗算するフロート2値
// 戻り値 ：C_Float_2 乗算結果のフロート2値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2 C_Float_2::operator*(C_Float_2 in_multiple_float_2)
{
	return C_Float_2(x * in_multiple_float_2.x, y * in_multiple_float_2.y);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_2との/演算
// 引数   ：C_Float_2 除算するフロート2値
// 戻り値 ：C_Float_2 除算結果のフロート2値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2 C_Float_2::operator/(C_Float_2 in_division_float_2)
{
	return C_Float_2(x / in_division_float_2.x, y / in_division_float_2.y);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_2との%演算
// 引数   ：C_Float_2 剰余算するフロート2値
// 戻り値 ：C_Float_2 剰余算結果のフロート2値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2 C_Float_2::operator%(C_Float_2 in_surplus_float_2)
{
	return C_Float_2((x - (int)(x / in_surplus_float_2.x)), (y - (int)(y / in_surplus_float_2.y)));
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_2との＋=演算
// 引数   ：C_Float_2 加算代入するフロート2値
// 戻り値 ：C_Float_2 加算代入結果のフロート2値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2 C_Float_2::operator+=(C_Float_2 in_plus_equal_float_2)
{
	x += in_plus_equal_float_2.x;
	y += in_plus_equal_float_2.y;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_2との-=演算
// 引数   ：C_Float_2 減算代入するフロート2値
// 戻り値 ：C_Float_2 減算代入結果のフロート2値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2 C_Float_2::operator-=(C_Float_2 in_minus_equal_float_2)
{
	x -= in_minus_equal_float_2.x;
	y -= in_minus_equal_float_2.y;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_2との×=演算
// 引数   ：C_Float_2 乗算代入するフロート2値
// 戻り値 ：C_Float_2 乗算代入結果のフロート2値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2 C_Float_2::operator*=(C_Float_2 in_multiple_equal_float_2)
{
	x *= in_multiple_equal_float_2.x;
	y *= in_multiple_equal_float_2.y;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_2との/=演算
// 引数   ：C_Float_2 除算代入するフロート2値
// 戻り値 ：C_Float_2 除算代入結果のフロート2値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2 C_Float_2::operator/=(C_Float_2 in_divide_equal_float_2)
{
	x /= in_divide_equal_float_2.x;
	y /= in_divide_equal_float_2.y;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：C_Float_2との%=演算
// 引数   ：C_Float_2 剰余算代入するフロート2値
// 戻り値 ：C_Float_2 剰余算代入結果のフロート2値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2 C_Float_2::operator%=(C_Float_2 in_surplus_equal_float_2)
{
	x = x - (int)(x / in_surplus_equal_float_2.x);
	y = y - (int)(y / in_surplus_equal_float_2.y);

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの=演算
// 引数   ：float 代入するフロート値
// 戻り値 ：C_Float_2 代入結果のフロート2値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2 C_Float_2::operator=(float in_equal_float)
{
	x = in_equal_float;
	y = in_equal_float;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの＋演算
// 引数   ：float 加算するフロート値
// 戻り値 ：C_Float_2 加算結果のフロート2値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2 C_Float_2::operator+(float in_plus_float)
{
	return C_Float_2(x + in_plus_float, y + in_plus_float);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの-演算
// 引数   ：float 減算するフロート値
// 戻り値 ：C_Float_2 減算結果のフロート2値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2 C_Float_2::operator-(float in_minus_float)
{
	return C_Float_2(x - in_minus_float, y - in_minus_float);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの×演算
// 引数   ：float 乗算するフロート値
// 戻り値 ：C_Float_2 乗算結果のフロート2値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2 C_Float_2::operator*(float in_multiple_float)
{
	return C_Float_2(x * in_multiple_float, y * in_multiple_float);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの/演算
// 引数   ：float 除算するフロート値
// 戻り値 ：C_Float_2 除算結果のフロート2値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2 C_Float_2::operator/(float in_division_float)
{
	return C_Float_2(x / in_division_float, y / in_division_float);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの%演算
// 引数   ：float 剰余算するフロート値
// 戻り値 ：C_Float_2 剰余算結果のフロート2値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2 C_Float_2::operator%(float in_surplus_float)
{
	return C_Float_2((x - (int)(x / in_surplus_float)), (y - (int)(y / in_surplus_float)));
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの＋=演算
// 引数   ：float 加算代入するフロート値
// 戻り値 ：C_Float_2 加算代入結果のフロート2値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2 C_Float_2::operator+=(float in_plus_equal_float)
{
	x += in_plus_equal_float;
	y += in_plus_equal_float;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの-=演算
// 引数   ：float 減算代入するフロート値
// 戻り値 ：C_Float_2 減算代入結果のフロート2値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2 C_Float_2::operator-=(float in_minus_equal_float)
{
	x -= in_minus_equal_float;
	y -= in_minus_equal_float;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの×=演算
// 引数   ：float 乗算代入するフロート値
// 戻り値 ：C_Float_2 乗算代入結果のフロート2値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2 C_Float_2::operator*=(float in_multiple_equal_float)
{
	x *= in_multiple_equal_float;
	y *= in_multiple_equal_float;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの/=演算
// 引数   ：float 除算代入するフロート値
// 戻り値 ：C_Float_2 除算代入結果のフロート2値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2 C_Float_2::operator/=(float in_divide_equal_float)
{
	x /= in_divide_equal_float;
	y /= in_divide_equal_float;

	return *this;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：floatとの%=演算
// 引数   ：float 剰余算代入するフロート値
// 戻り値 ：C_Float_2 剰余算代入結果のフロート2値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Float_2 C_Float_2::operator%=(float in_surplus_equal_float)
{
	x = x - (int)(x / in_surplus_equal_float);
	y = y - (int)(y / in_surplus_equal_float);

	return *this;
}
