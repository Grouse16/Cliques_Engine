////
// Ú×   Ft[gRÂªðÇ·éNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Float_2.h"


//  l[Xy[XÌÈª  //
using namespace MATH::FORMAT;


//  Ö  //

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Float_2::C_Float_2(void)
{
	return;
}


//===============//
// Ú×   FxyÌp[^ðÉZbg·éRXgN^
// ø   Ffloat xÉZbg·él, float yÉZbg·él
// ßèl FÈµ
//===============//
C_Float_2::C_Float_2(float in_x, float in_y)
{
	u = in_x;
	v = in_y;

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Float_2::~C_Float_2(void)
{
}


//-- Iy[^ --//

//===============//
// Ú×   FC_Float_2ÆÌ=Z
// ø   FC_Float_2 ãü·ét[g2l
// ßèl FC_Float_2 ãüÊÌt[g2l
//===============//
C_Float_2 C_Float_2::operator=(C_Float_2 in_equal_float_2)
{
	u = in_equal_float_2.u;
	v = in_equal_float_2.v;

	return *this;
}


//===============//
// Ú×   FC_Float_2ÆÌ{Z
// ø   FC_Float_2 ÁZ·ét[g2l
// ßèl FC_Float_2 ÁZÊÌt[g2l
//===============//
C_Float_2 C_Float_2::operator+(C_Float_2 in_plus_float_2)
{
	return C_Float_2(u + in_plus_float_2.u, v + in_plus_float_2.v);
}


//===============//
// Ú×   FC_Float_2ÆÌ-Z
// ø   FC_Float_2 ¸Z·ét[g2l
// ßèl FC_Float_2 ¸ZÊÌt[g2l
//===============//
C_Float_2 C_Float_2::operator-(C_Float_2 in_minus_float_2)
{
	return C_Float_2(u - in_minus_float_2.u, v - in_minus_float_2.v);
}


//===============//
// Ú×   FC_Float_2ÆÌ~Z
// ø   FC_Float_2 æZ·ét[g2l
// ßèl FC_Float_2 æZÊÌt[g2l
//===============//
C_Float_2 C_Float_2::operator*(C_Float_2 in_multiple_float_2)
{
	return C_Float_2(u * in_multiple_float_2.u, v * in_multiple_float_2.v);
}


//===============//
// Ú×   FC_Float_2ÆÌ/Z
// ø   FC_Float_2 Z·ét[g2l
// ßèl FC_Float_2 ZÊÌt[g2l
//===============//
C_Float_2 C_Float_2::operator/(C_Float_2 in_division_float_2)
{
	return C_Float_2(u / in_division_float_2.u, v / in_division_float_2.v);
}


//===============//
// Ú×   FC_Float_2ÆÌ%Z
// ø   FC_Float_2 è]Z·ét[g2l
// ßèl FC_Float_2 è]ZÊÌt[g2l
//===============//
C_Float_2 C_Float_2::operator%(C_Float_2 in_surplus_float_2)
{
	return C_Float_2((u - (int)(u / in_surplus_float_2.u)), (v - (int)(v / in_surplus_float_2.v)));
}


//===============//
// Ú×   FC_Float_2ÆÌ{=Z
// ø   FC_Float_2 ÁZãü·ét[g2l
// ßèl FC_Float_2 ÁZãüÊÌt[g2l
//===============//
C_Float_2 C_Float_2::operator+=(C_Float_2 in_plus_equal_float_2)
{
	u += in_plus_equal_float_2.u;
	v += in_plus_equal_float_2.v;

	return *this;
}


//===============//
// Ú×   FC_Float_2ÆÌ-=Z
// ø   FC_Float_2 ¸Zãü·ét[g2l
// ßèl FC_Float_2 ¸ZãüÊÌt[g2l
//===============//
C_Float_2 C_Float_2::operator-=(C_Float_2 in_minus_equal_float_2)
{
	u -= in_minus_equal_float_2.u;
	v -= in_minus_equal_float_2.v;

	return *this;
}


//===============//
// Ú×   FC_Float_2ÆÌ~=Z
// ø   FC_Float_2 æZãü·ét[g2l
// ßèl FC_Float_2 æZãüÊÌt[g2l
//===============//
C_Float_2 C_Float_2::operator*=(C_Float_2 in_multiple_equal_float_2)
{
	u *= in_multiple_equal_float_2.u;
	v *= in_multiple_equal_float_2.v;

	return *this;
}


//===============//
// Ú×   FC_Float_2ÆÌ/=Z
// ø   FC_Float_2 Zãü·ét[g2l
// ßèl FC_Float_2 ZãüÊÌt[g2l
//===============//
C_Float_2 C_Float_2::operator/=(C_Float_2 in_divide_equal_float_2)
{
	u /= in_divide_equal_float_2.u;
	v /= in_divide_equal_float_2.v;

	return *this;
}


//===============//
// Ú×   FC_Float_2ÆÌ%=Z
// ø   FC_Float_2 è]Zãü·ét[g2l
// ßèl FC_Float_2 è]ZãüÊÌt[g2l
//===============//
C_Float_2 C_Float_2::operator%=(C_Float_2 in_surplus_equal_float_2)
{
	u = u - (int)(u / in_surplus_equal_float_2.u);
	v = v - (int)(v / in_surplus_equal_float_2.v);

	return *this;
}


//===============//
// Ú×   FfloatÆÌ=Z
// ø   Ffloat ãü·ét[gl
// ßèl FC_Float_2 ãüÊÌt[g2l
//===============//
C_Float_2 C_Float_2::operator=(float in_equal_float)
{
	u = in_equal_float;
	v = in_equal_float;

	return *this;
}


//===============//
// Ú×   FfloatÆÌ{Z
// ø   Ffloat ÁZ·ét[gl
// ßèl FC_Float_2 ÁZÊÌt[g2l
//===============//
C_Float_2 C_Float_2::operator+(float in_plus_float)
{
	return C_Float_2(u + in_plus_float, v + in_plus_float);
}


//===============//
// Ú×   FfloatÆÌ-Z
// ø   Ffloat ¸Z·ét[gl
// ßèl FC_Float_2 ¸ZÊÌt[g2l
//===============//
C_Float_2 C_Float_2::operator-(float in_minus_float)
{
	return C_Float_2(u - in_minus_float, v - in_minus_float);
}


//===============//
// Ú×   FfloatÆÌ~Z
// ø   Ffloat æZ·ét[gl
// ßèl FC_Float_2 æZÊÌt[g2l
//===============//
C_Float_2 C_Float_2::operator*(float in_multiple_float)
{
	return C_Float_2(u * in_multiple_float, v * in_multiple_float);
}


//===============//
// Ú×   FfloatÆÌ/Z
// ø   Ffloat Z·ét[gl
// ßèl FC_Float_2 ZÊÌt[g2l
//===============//
C_Float_2 C_Float_2::operator/(float in_division_float)
{
	return C_Float_2(u / in_division_float, v / in_division_float);
}


//===============//
// Ú×   FfloatÆÌ%Z
// ø   Ffloat è]Z·ét[gl
// ßèl FC_Float_2 è]ZÊÌt[g2l
//===============//
C_Float_2 C_Float_2::operator%(float in_surplus_float)
{
	return C_Float_2((u - (int)(u / in_surplus_float)), (v - (int)(v / in_surplus_float)));
}


//===============//
// Ú×   FfloatÆÌ{=Z
// ø   Ffloat ÁZãü·ét[gl
// ßèl FC_Float_2 ÁZãüÊÌt[g2l
//===============//
C_Float_2 C_Float_2::operator+=(float in_plus_equal_float)
{
	u += in_plus_equal_float;
	v += in_plus_equal_float;

	return *this;
}


//===============//
// Ú×   FfloatÆÌ-=Z
// ø   Ffloat ¸Zãü·ét[gl
// ßèl FC_Float_2 ¸ZãüÊÌt[g2l
//===============//
C_Float_2 C_Float_2::operator-=(float in_minus_equal_float)
{
	u -= in_minus_equal_float;
	v -= in_minus_equal_float;

	return *this;
}


//===============//
// Ú×   FfloatÆÌ~=Z
// ø   Ffloat æZãü·ét[gl
// ßèl FC_Float_2 æZãüÊÌt[g2l
//===============//
C_Float_2 C_Float_2::operator*=(float in_multiple_equal_float)
{
	u *= in_multiple_equal_float;
	v *= in_multiple_equal_float;

	return *this;
}


//===============//
// Ú×   FfloatÆÌ/=Z
// ø   Ffloat Zãü·ét[gl
// ßèl FC_Float_2 ZãüÊÌt[g2l
//===============//
C_Float_2 C_Float_2::operator/=(float in_divide_equal_float)
{
	u /= in_divide_equal_float;
	v /= in_divide_equal_float;

	return *this;
}


//===============//
// Ú×   FfloatÆÌ%=Z
// ø   Ffloat è]Zãü·ét[gl
// ßèl FC_Float_2 è]ZãüÊÌt[g2l
//===============//
C_Float_2 C_Float_2::operator%=(float in_surplus_equal_float)
{
	u = u - (int)(u / in_surplus_equal_float);
	v = v - (int)(v / in_surplus_equal_float);

	return *this;
}
