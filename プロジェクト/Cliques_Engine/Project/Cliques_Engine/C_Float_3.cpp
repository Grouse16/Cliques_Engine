////
// Ú×   Ft[gRÂªðÇ·éNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Float_3.h"


//  l[Xy[XÌÈª  //
using namespace MATH::FORMAT;


//  Ö  //

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Float_3::C_Float_3(void)
{
	return;
}


//===============//
// Ú×   FxyzÌp[^ðÉZbg·éRXgN^
// ø   Ffloat xÉZbg·él, float yÉZbg·él, float zÉZbg·él
// ßèl FÈµ
//===============//
C_Float_3::C_Float_3(float in_x, float in_y, float in_z)
{
	x = in_x;
	y = in_y;
	z = in_z;

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Float_3::~C_Float_3(void)
{
}


//-- Iy[^ --//

//===============//
// Ú×   FC_Float_3ÆÌ=Z
// ø   FC_Float_3 ãü·ét[g3l
// ßèl FC_Float_3 ãüÊÌt[g3l
//===============//
C_Float_3 C_Float_3::operator=(C_Float_3 in_equal_float_3)
{
	x = in_equal_float_3.x;
	y = in_equal_float_3.y;
	z = in_equal_float_3.z;

	return *this;
}


//===============//
// Ú×   FC_Float_3ÆÌ{Z
// ø   FC_Float_3 ÁZ·ét[g3l
// ßèl FC_Float_3 ÁZÊÌt[g3l
//===============//
C_Float_3 C_Float_3::operator+(C_Float_3 in_plus_float_3)
{
	return C_Float_3(x + in_plus_float_3.x, y + in_plus_float_3.y, z + in_plus_float_3.z);
}


//===============//
// Ú×   FC_Float_3ÆÌ-Z
// ø   FC_Float_3 ¸Z·ét[g3l
// ßèl FC_Float_3 ¸ZÊÌt[g3l
//===============//
C_Float_3 C_Float_3::operator-(C_Float_3 in_minus_float_3)
{
	return C_Float_3(x - in_minus_float_3.x, y - in_minus_float_3.y, z - in_minus_float_3.z);
}


//===============//
// Ú×   FC_Float_3ÆÌ~Z
// ø   FC_Float_3 æZ·ét[g3l
// ßèl FC_Float_3 æZÊÌt[g3l
//===============//
C_Float_3 C_Float_3::operator*(C_Float_3 in_multiple_float_3)
{
	return C_Float_3(x * in_multiple_float_3.x, y * in_multiple_float_3.y, z * in_multiple_float_3.z);
}


//===============//
// Ú×   FC_Float_3ÆÌ/Z
// ø   FC_Float_3 Z·ét[g3l
// ßèl FC_Float_3 ZÊÌt[g3l
//===============//
C_Float_3 C_Float_3::operator/(C_Float_3 in_division_float_3)
{
	return C_Float_3(x / in_division_float_3.x, y / in_division_float_3.y, z / in_division_float_3.z);
}


//===============//
// Ú×   FC_Float_3ÆÌ%Z
// ø   FC_Float_3 è]Z·ét[g3l
// ßèl FC_Float_3 è]ZÊÌt[g3l
//===============//
C_Float_3 C_Float_3::operator%(C_Float_3 in_surplus_float_3)
{
	return C_Float_3((x - (int)(x / in_surplus_float_3.x)), (y - (int)(y / in_surplus_float_3.y)), (z - (int)(z / in_surplus_float_3.z)));
}


//===============//
// Ú×   FC_Float_3ÆÌ{=Z
// ø   FC_Float_3 ÁZãü·ét[g3l
// ßèl FC_Float_3 ÁZãüÊÌt[g3l
//===============//
C_Float_3 C_Float_3::operator+=(C_Float_3 in_plus_equal_float_3)
{
	x += in_plus_equal_float_3.x;
	y += in_plus_equal_float_3.y;
	z += in_plus_equal_float_3.z;

	return *this;
}


//===============//
// Ú×   FC_Float_3ÆÌ-=Z
// ø   FC_Float_3 ¸Zãü·ét[g3l
// ßèl FC_Float_3 ¸ZãüÊÌt[g3l
//===============//
C_Float_3 C_Float_3::operator-=(C_Float_3 in_minus_equal_float_3)
{
	x -= in_minus_equal_float_3.x;
	y -= in_minus_equal_float_3.y;
	z -= in_minus_equal_float_3.z;

	return *this;
}


//===============//
// Ú×   FC_Float_3ÆÌ~=Z
// ø   FC_Float_3 æZãü·ét[g3l
// ßèl FC_Float_3 æZãüÊÌt[g3l
//===============//
C_Float_3 C_Float_3::operator*=(C_Float_3 in_multiple_equal_float_3)
{
	x *= in_multiple_equal_float_3.x;
	y *= in_multiple_equal_float_3.y;
	z *= in_multiple_equal_float_3.z;

	return *this;
}


//===============//
// Ú×   FC_Float_3ÆÌ/=Z
// ø   FC_Float_3 Zãü·ét[g3l
// ßèl FC_Float_3 ZãüÊÌt[g3l
//===============//
C_Float_3 C_Float_3::operator/=(C_Float_3 in_divide_equal_float_3)
{
	x /= in_divide_equal_float_3.x;
	y /= in_divide_equal_float_3.y;
	z /= in_divide_equal_float_3.z;

	return *this;
}


//===============//
// Ú×   FC_Float_3ÆÌ%=Z
// ø   FC_Float_3 è]Zãü·ét[g3l
// ßèl FC_Float_3 è]ZãüÊÌt[g3l
//===============//
C_Float_3 C_Float_3::operator%=(C_Float_3 in_surplus_equal_float_3)
{
	x = x - (int)(x / in_surplus_equal_float_3.x);
	y = y - (int)(y / in_surplus_equal_float_3.y);
	z = z - (int)(z / in_surplus_equal_float_3.z);

	return *this;
}


//===============//
// Ú×   FfloatÆÌ=Z
// ø   Ffloat ãü·ét[gl
// ßèl FC_Float_3 ãüÊÌt[g3l
//===============//
C_Float_3 C_Float_3::operator=(float in_equal_float)
{
	x = in_equal_float;
	y = in_equal_float;
	z = in_equal_float;

	return *this;
}


//===============//
// Ú×   FfloatÆÌ{Z
// ø   Ffloat ÁZ·ét[gl
// ßèl FC_Float_3 ÁZÊÌt[g3l
//===============//
C_Float_3 C_Float_3::operator+(float in_plus_float)
{
	return C_Float_3(x + in_plus_float, y + in_plus_float, z + in_plus_float);
}


//===============//
// Ú×   FfloatÆÌ-Z
// ø   Ffloat ¸Z·ét[gl
// ßèl FC_Float_3 ¸ZÊÌt[g3l
//===============//
C_Float_3 C_Float_3::operator-(float in_minus_float)
{
	return C_Float_3(x - in_minus_float, y - in_minus_float, z - in_minus_float);
}


//===============//
// Ú×   FfloatÆÌ~Z
// ø   Ffloat æZ·ét[gl
// ßèl FC_Float_3 æZÊÌt[g3l
//===============//
C_Float_3 C_Float_3::operator*(float in_multiple_float)
{
	return C_Float_3(x * in_multiple_float, y * in_multiple_float, z * in_multiple_float);
}


//===============//
// Ú×   FfloatÆÌ/Z
// ø   Ffloat Z·ét[gl
// ßèl FC_Float_3 ZÊÌt[g3l
//===============//
C_Float_3 C_Float_3::operator/(float in_division_float)
{
	return C_Float_3(x / in_division_float, y / in_division_float, z / in_division_float);
}


//===============//
// Ú×   FfloatÆÌ%Z
// ø   Ffloat è]Z·ét[gl
// ßèl FC_Float_3 è]ZÊÌt[g3l
//===============//
C_Float_3 C_Float_3::operator%(float in_surplus_float)
{
	return C_Float_3((x - (int)(x / in_surplus_float)), (y - (int)(y / in_surplus_float)), (z - (int)(z / in_surplus_float)));
}


//===============//
// Ú×   FfloatÆÌ{=Z
// ø   Ffloat ÁZãü·ét[gl
// ßèl FC_Float_3 ÁZãüÊÌt[g3l
//===============//
C_Float_3 C_Float_3::operator+=(float in_plus_equal_float)
{
	x += in_plus_equal_float;
	y += in_plus_equal_float;
	z += in_plus_equal_float;

	return *this;
}


//===============//
// Ú×   FfloatÆÌ-=Z
// ø   Ffloat ¸Zãü·ét[gl
// ßèl FC_Float_3 ¸ZãüÊÌt[g3l
//===============//
C_Float_3 C_Float_3::operator-=(float in_minus_equal_float)
{
	x -= in_minus_equal_float;
	y -= in_minus_equal_float;
	z -= in_minus_equal_float;

	return *this;
}


//===============//
// Ú×   FfloatÆÌ~=Z
// ø   Ffloat æZãü·ét[gl
// ßèl FC_Float_3 æZãüÊÌt[g3l
//===============//
C_Float_3 C_Float_3::operator*=(float in_multiple_equal_float)
{
	x *= in_multiple_equal_float;
	y *= in_multiple_equal_float;
	z *= in_multiple_equal_float;

	return *this;
}


//===============//
// Ú×   FfloatÆÌ/=Z
// ø   Ffloat Zãü·ét[gl
// ßèl FC_Float_3 ZãüÊÌt[g3l
//===============//
C_Float_3 C_Float_3::operator/=(float in_divide_equal_float)
{
	x /= in_divide_equal_float;
	y /= in_divide_equal_float;
	z /= in_divide_equal_float;

	return *this;
}


//===============//
// Ú×   FfloatÆÌ%=Z
// ø   Ffloat è]Zãü·ét[gl
// ßèl FC_Float_3 è]ZãüÊÌt[g3l
//===============//
C_Float_3 C_Float_3::operator%=(float in_surplus_equal_float)
{
	x = x - (int)(x / in_surplus_equal_float);
	y = y - (int)(y / in_surplus_equal_float);
	z = z - (int)(z / in_surplus_equal_float);

	return *this;
}
