////
// Ú×   Ft[gSÂªðÇ·éNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Float_4.h"


//  l[Xy[XÌÈª  //
using namespace MATH::FORMAT;


//  NX  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Float_4::C_Float_4(void)
{
	return;
}


//===============//
// Ú×   FxyzwÌp[^ðÉZbg·éRXgN^
// ø   Ffloat xÉZbg·él, float yÉZbg·él, float zÉZbg·él, float wÉZbg·él
// ßèl FÈµ
//===============//
C_Float_4::C_Float_4(float in_x, float in_y, float in_z, float in_w)
{
	x = in_x;
	y = in_y;
	z = in_z;
	w = in_w;

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Float_4::~C_Float_4(void)
{
	return;
}


//== Iy[^ ==//

//===============//
// Ú×   FC_Float_4ÆÌ=Z
// ø   FC_Float_4 ãü·ét[g4l
// ßèl FC_Float_4 ãüÊÌt[g4l
//===============//
C_Float_4 C_Float_4::operator=(C_Float_4 in_equal_float_4)
{
	x = in_equal_float_4.x;
	y = in_equal_float_4.y;
	z = in_equal_float_4.z;
	w = in_equal_float_4.w;

	return *this;
}


//===============//
// Ú×   FC_Float_4ÆÌ{Z
// ø   FC_Float_4 ÁZ·ét[g4l
// ßèl FC_Float_4 ÁZÊÌt[g4l
//===============//
C_Float_4 C_Float_4::operator+(C_Float_4 in_plus_float_4)
{
	return C_Float_4(x + in_plus_float_4.x, y + in_plus_float_4.y, z + in_plus_float_4.z, w + in_plus_float_4.w);
}


//===============//
// Ú×   FC_Float_4ÆÌ-Z
// ø   FC_Float_4 ¸Z·ét[g4l
// ßèl FC_Float_4 ¸ZÊÌt[g4l
//===============//
C_Float_4 C_Float_4::operator-(C_Float_4 in_minus_float_4)
{
	return C_Float_4(x - in_minus_float_4.x, y - in_minus_float_4.y, z - in_minus_float_4.z, w - in_minus_float_4.w);
}


//===============//
// Ú×   FC_Float_4ÆÌ~Z
// ø   FC_Float_4 æZ·ét[g4l
// ßèl FC_Float_4 æZÊÌt[g4l
//===============//
C_Float_4 C_Float_4::operator*(C_Float_4 in_multiple_float_4)
{
	return C_Float_4(x * in_multiple_float_4.x, y * in_multiple_float_4.y, z * in_multiple_float_4.z, w * in_multiple_float_4.w);
}


//===============//
// Ú×   FC_Float_4ÆÌ/Z
// ø   FC_Float_4 Z·ét[g4l
// ßèl FC_Float_4 ZÊÌt[g4l
//===============//
C_Float_4 C_Float_4::operator/(C_Float_4 in_division_float_4)
{
	return C_Float_4(x / in_division_float_4.x, y / in_division_float_4.y, z / in_division_float_4.z, w / in_division_float_4.w);
}


//===============//
// Ú×   FC_Float_4ÆÌ%Z
// ø   FC_Float_4 è]Z·ét[g4l
// ßèl FC_Float_4 è]ZÊÌt[g4l
//===============//
C_Float_4 C_Float_4::operator%(C_Float_4 in_surplus_float_4)
{
	return C_Float_4((x - (int)(x / in_surplus_float_4.x)), (y - (int)(y / in_surplus_float_4.y)), (z - (int)(z / in_surplus_float_4.z)), (w - (int)(w / in_surplus_float_4.w)));
}


//===============//
// Ú×   FC_Float_4ÆÌ{=Z
// ø   FC_Float_4 ÁZãü·ét[g4l
// ßèl FC_Float_4 ÁZãüÊÌt[g4l
//===============//
C_Float_4 C_Float_4::operator+=(C_Float_4 in_plus_equal_float_4)
{
	x += in_plus_equal_float_4.x;
	y += in_plus_equal_float_4.y;
	z += in_plus_equal_float_4.z;
	w += in_plus_equal_float_4.w;

	return *this;
}


//===============//
// Ú×   FC_Float_4ÆÌ-=Z
// ø   FC_Float_4 ¸Zãü·ét[g4l
// ßèl FC_Float_4 ¸ZãüÊÌt[g4l
//===============//
C_Float_4 C_Float_4::operator-=(C_Float_4 in_minus_equal_float_4)
{
	x -= in_minus_equal_float_4.x;
	y -= in_minus_equal_float_4.y;
	z -= in_minus_equal_float_4.z;
	w -= in_minus_equal_float_4.w;

	return *this;
}


//===============//
// Ú×   FC_Float_4ÆÌ~=Z
// ø   FC_Float_4 æZãü·ét[g4l
// ßèl FC_Float_4 æZãüÊÌt[g4l
//===============//
C_Float_4 C_Float_4::operator*=(C_Float_4 in_multiple_equal_float_4)
{
	x *= in_multiple_equal_float_4.x;
	y *= in_multiple_equal_float_4.y;
	z *= in_multiple_equal_float_4.z;
	w *= in_multiple_equal_float_4.w;

	return *this;
}


//===============//
// Ú×   FC_Float_4ÆÌ/=Z
// ø   FC_Float_4 Zãü·ét[g4l
// ßèl FC_Float_4 ZãüÊÌt[g4l
//===============//
C_Float_4 C_Float_4::operator/=(C_Float_4 in_divide_equal_float_4)
{
	x /= in_divide_equal_float_4.x;
	y /= in_divide_equal_float_4.y;
	z /= in_divide_equal_float_4.z;
	w /= in_divide_equal_float_4.w;

	return *this;
}


//===============//
// Ú×   FC_Float_4ÆÌ%=Z
// ø   FC_Float_4 è]Zãü·ét[g4l
// ßèl FC_Float_4 è]ZãüÊÌt[g4l
//===============//
C_Float_4 C_Float_4::operator%=(C_Float_4 in_surplus_equal_float_4)
{
	x = x - (int)(x / in_surplus_equal_float_4.x);
	y = y - (int)(y / in_surplus_equal_float_4.y);
	z = z - (int)(z / in_surplus_equal_float_4.z);
	w = w - (int)(w / in_surplus_equal_float_4.w);

	return *this;
}


//===============//
// Ú×   FfloatÆÌ=Z
// ø   Ffloat ãü·ét[gl
// ßèl FC_Float_4 ãüÊÌt[g4l
//===============//
C_Float_4 C_Float_4::operator=(float in_equal_float)
{
	return C_Float_4(in_equal_float, in_equal_float, in_equal_float, in_equal_float);
}


//===============//
// Ú×   FfloatÆÌ{Z
// ø   Ffloat ÁZ·ét[gl
// ßèl FC_Float_4 ÁZÊÌt[g4l
//===============//
C_Float_4 C_Float_4::operator+(float in_plus_float)
{
	return C_Float_4(x + in_plus_float, y + in_plus_float, z + in_plus_float, w + in_plus_float);
}


//===============//
// Ú×   FfloatÆÌ-Z
// ø   Ffloat ¸Z·ét[gl
// ßèl FC_Float_4 ¸ZÊÌt[g4l
//===============//
C_Float_4 C_Float_4::operator-(float in_minus_float)
{
	return C_Float_4(x - in_minus_float, y - in_minus_float, z - in_minus_float, w - in_minus_float);
}


//===============//
// Ú×   FfloatÆÌ~Z
// ø   Ffloat æZ·ét[gl
// ßèl FC_Float_4 æZÊÌt[g4l
//===============//
C_Float_4 C_Float_4::operator*(float in_multiple_float)
{
	return C_Float_4(x * in_multiple_float, y * in_multiple_float, w * in_multiple_float, z * in_multiple_float);
}


//===============//
// Ú×   FfloatÆÌ/Z
// ø   Ffloat Z·ét[gl
// ßèl FC_Float_4 ZÊÌt[g4l
//===============//
C_Float_4 MATH::FORMAT::C_Float_4::operator/(float in_divide_float)
{
	return C_Float_4(x / in_divide_float, y / in_divide_float, w / in_divide_float, z / in_divide_float);
}


//===============//
// Ú×   FfloatÆÌ%Z
// ø   Ffloat è]Z·ét[gl
// ßèl FC_Float_4 è]ZÊÌt[g4l
//===============//
C_Float_4 C_Float_4::operator%(float in_surplus_float)
{
	return C_Float_4((x - (int)(x / in_surplus_float)), (y - (int)(y / in_surplus_float)), (z - (int)(z / in_surplus_float)), (w - (int)(w / in_surplus_float)));
}


//===============//
// Ú×   FfloatÆÌ{=Z
// ø   Ffloat ÁZãü·ét[gl
// ßèl FC_Float_4 ÁZãüÊÌt[g4l
//===============//
C_Float_4 C_Float_4::operator+=(float in_plus_equal_float)
{
	x += in_plus_equal_float;
	y += in_plus_equal_float;
	z += in_plus_equal_float;
	w += in_plus_equal_float;

	return *this;
}


//===============//
// Ú×   FfloatÆÌ-=Z
// ø   Ffloat ¸Zãü·ét[gl
// ßèl FC_Float_4 ¸ZãüÊÌt[g4l
//===============//
C_Float_4 C_Float_4::operator-=(float in_minus_equal_float)
{
	x -= in_minus_equal_float;
	y -= in_minus_equal_float;
	z -= in_minus_equal_float;
	w -= in_minus_equal_float;

	return *this;
}


//===============//
// Ú×   FfloatÆÌ~=Z
// ø   Ffloat æZãü·ét[gl
// ßèl FC_Float_4 æZãüÊÌt[g4l
//===============//
C_Float_4 C_Float_4::operator*=(float in_multiple_equal_float)
{
	x *= in_multiple_equal_float;
	y *= in_multiple_equal_float;
	z *= in_multiple_equal_float;
	w *= in_multiple_equal_float;

	return *this;
}


//===============//
// Ú×   FfloatÆÌ/=Z
// ø   Ffloat Zãü·ét[gl
// ßèl FC_Float_4 ZãüÊÌt[g4l
//===============//
C_Float_4 C_Float_4::operator/=(float in_divide_equal_float)
{
	x /= in_divide_equal_float;
	y /= in_divide_equal_float;
	z /= in_divide_equal_float;
	w /= in_divide_equal_float;

	return *this;
}


//===============//
// Ú×   FfloatÆÌ%=Z
// ø   Ffloat è]Zãü·ét[gl
// ßèl FC_Float_4 è]ZãüÊÌt[g4l
//===============//
C_Float_4 C_Float_4::operator%=(float in_surplus_equal_float)
{
	x = x - (int)(x / in_surplus_equal_float);
	y = y - (int)(y / in_surplus_equal_float);
	z = z - (int)(z / in_surplus_equal_float);
	w = w - (int)(w / in_surplus_equal_float);

	return *this;
}

