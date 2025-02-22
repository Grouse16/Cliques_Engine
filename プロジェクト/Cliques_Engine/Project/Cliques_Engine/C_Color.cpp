////
// Ú×   FFè`pÌt@C
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Color.h"


//  l[Xy[XÌÈª  //
using namespace DATA::COLOR;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Color::C_Color(void)
{
	return;
}


//===============//
// Ú×   FO`PÅFðÝè·éÌRXgN^
// ø   Ffloat Ô, float Î, float Â, float §¾x
// ßèl Fvoid
//===============//
C_Color::C_Color(float in_r, float in_g, float in_b, float in_a)
{
	m_r = in_r;
	m_g = in_g;
	m_b = in_b;
	m_a = in_a;

	return;
}


//===============//
// Ú×   FO`QTTÅFðÝè·éÌRXgN^
// ø   Fint Ô, int Î, int Â, int §¾x
// ßèl Fvoid
//===============//
C_Color::C_Color(int in_r, int in_g, int in_b, int in_a)
{
	m_r = in_r / 255.0f;
	m_g = in_g / 255.0f;
	m_b = in_b / 255.0f;
	m_a = in_a / 255.0f;

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Color::~C_Color(void)
{
	return;
}


//-- Zb^ --//

//===============//
// Ú×   FO`PÅFÌÝèðs¤
// ø   Ffloat Ô, float Î, float Â, float §¾x
// ßèl Fvoid
//===============//
void C_Color::M_Set_Color_By_0_1(float in_r, float in_g, float in_b, float in_a)
{
	m_r = in_r;
	m_g = in_g;
	m_b = in_b;
	m_a = in_a;

	return;
}


//===============//
// Ú×   FO`QTTÅFÌÝèðs¤
// ø   Fint Ô, int Î, int Â, int §¾x
// ßèl Fvoid
//===============//
void C_Color::M_Set_Color_By_0_255(int in_r, int in_g, int in_b, int in_a)
{
	m_r = in_r / static_cast<float>(255);
	m_g = in_g / static_cast<float>(255);
	m_b = in_b / static_cast<float>(255);
	m_a = in_a / static_cast<float>(255);

	return;
}


//-- Iy[^[ --//

//===============//
// Ú×   FF¯mÌ|¯Z
// ø   FC_Color Fîñ
// ßèl FC_Color FîñÌ|¯ZÊ
//===============//
C_Color C_Color::operator*(C_Color in_color)
{
	//  Ïé¾  //
	C_Color result;	// vZÊ


	// Fð¬·é
	result.m_r = in_color.m_r * m_r;
	result.m_g = in_color.m_g * m_g;
	result.m_b = in_color.m_b * m_b;
	result.m_a = in_color.m_a * m_a;

	return result;
}


//===============//
// Ú×   FFðÝè·é
// ø   FC_Color Fîñ
// ßèl Fvoid
//===============//
void C_Color::operator=(C_Color in_color)
{
	// FðZbg·é
	m_r = in_color.m_r;
	m_g = in_color.m_g;
	m_b = in_color.m_b;
	m_a = in_color.m_a;

	return;
}

