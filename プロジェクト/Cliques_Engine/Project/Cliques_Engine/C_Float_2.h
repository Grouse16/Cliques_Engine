////
// Ú×   Ft[gQÂªðÇ·éNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_FLOAT_2_H_FILE
#define D_INCLUDE_GUARD_C_FLOAT_2_H_FILE


//  l[Xy[X  //

// wnÌ^ðÄÑo·½ßÌ¼O
namespace MATH::FORMAT
{
	//  NX  //

	// t[gQÂªðÇ·éNX
	class C_Float_2
	{
		//== pubN ==//
	public:

		//  Ïé¾  //
		float u = 0.0f;
		float v = 0.0f;


		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Float_2(void);

		// xyðÉZbg·éRXgN^@øFxÉZbg·él, yÉZbg·él
		C_Float_2(float, float);

		// fXgN^
		~C_Float_2(void);


		//-- Iy[^ --//

		// C_Float_2ÆÌ=Z@øFãü·ét[g2l@ßèlFãüÊÌt[g2l
		C_Float_2 operator= (C_Float_2);

		// C_Float_2ÆÌ{Z@øFÁZ·ét[g2l@ßèlFÁZÊÌt[g2l
		C_Float_2 operator+ (C_Float_2);

		// C_Float_2ÆÌ-Z@øF¸Z·ét[g2l@ßèlF¸ZÊÌt[g2l
		C_Float_2 operator- (C_Float_2);

		// C_Float_2ÆÌ~Z@øFæZ·ét[g2l@ßèlFæZÊÌt[g2l
		C_Float_2 operator* (C_Float_2);

		// C_Float_2ÆÌ/Z@øFZ·ét[g2l@ßèlFZÊÌt[g2l
		C_Float_2 operator/ (C_Float_2);

		// C_Float_2ÆÌ%Z@øFè]Z·ét[g2l@ßèlFè]ZÊÌt[g2l
		C_Float_2 operator% (C_Float_2);

		// C_Float_2ÆÌ{=Z@øFÁZãü·ét[g2l@ßèlFÁZãüÊÌt[g2l
		C_Float_2 operator+= (C_Float_2);

		// C_Float_2ÆÌ-=Z@øF¸Zãü·ét[g2l@ßèlF¸ZãüÊÌt[g2l
		C_Float_2 operator-= (C_Float_2);

		// C_Float_2ÆÌ~=Z@øFæZãü·ét[g2l@ßèlFæZãüÊÌt[g2l
		C_Float_2 operator*= (C_Float_2);

		// C_Float_2ÆÌ/=Z@øFZãü·ét[g2l@ßèlFZãüÊÌt[g2l
		C_Float_2 operator/= (C_Float_2);

		// C_Float_2ÆÌ%=Z@øFè]Zãü·ét[g2l@ßèlFè]ZãüÊÌt[g2l
		C_Float_2 operator%= (C_Float_2);

		// floatÆÌ=Z@øFãü·ét[gl@ßèlFãüÊÌt[g2l
		C_Float_2 operator= (float);

		// floatÆÌ{Z@øFÁZ·ét[gl@ßèlFÁZÊÌt[g2l
		C_Float_2 operator+ (float);

		// floatÆÌ-Z@øF¸Z·ét[gl@ßèlF¸ZÊÌt[g2l
		C_Float_2 operator- (float);

		// floatÆÌ~Z@øFæZ·ét[gl@ßèlFæZÊÌt[g2l
		C_Float_2 operator* (float);

		// floatÆÌ/Z@øFZ·ét[gl@ßèlFZÊÌt[g2l
		C_Float_2 operator/ (float);

		// floatÆÌ%Z@øFè]Z·ét[gl@ßèlFè]ZÊÌt[g2l
		C_Float_2 operator% (float);

		// floatÆÌ{=Z@øFÁZãü·ét[gl@ßèlFÁZãüÊÌt[g2l
		C_Float_2 operator+= (float);

		// floatÆÌ-=Z@øF¸Zãü·ét[gl@ßèlF¸ZãüÊÌt[g2l
		C_Float_2 operator-= (float);

		// floatÆÌ~=Z@øFæZãü·ét[gl@ßèlFæZãüÊÌt[g2l
		C_Float_2 operator*= (float);

		// floatÆÌ/=Z@øFZãü·ét[gl@ßèlFZãüÊÌt[g2l
		C_Float_2 operator/= (float);

		// floatÆÌ%=Z@øFè]Zãü·ét[gl@ßèlFè]ZãüÊÌt[g2l
		C_Float_2 operator%= (float);
	};
}


#endif // !D_INCLUDE_GUARD_C_FLOAT_2_H_FILE

