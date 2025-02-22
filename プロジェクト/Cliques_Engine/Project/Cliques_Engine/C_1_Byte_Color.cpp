////
// Ú×   FPoCgÌJ[Ì\¢Ì
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_1_Byte_Color.h"


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
C_1_Byte_Color::C_1_Byte_Color(void)
{
	return;
}


//===============//
// Ú×   FO`PÅFðÝè·éÌRXgN^
// ø   Ffloat Ô, float Î, float Â, float §¾x
// ßèl FÈµ
//===============//
C_1_Byte_Color::C_1_Byte_Color(float in_red, float in_green, float in_blue, float in_alpha)
{
	m_r = (unsigned char)(in_red * 255);
	m_g = (unsigned char)(in_green * 255);
	m_b = (unsigned char)(in_blue * 255);
	m_a = (unsigned char)(in_alpha * 255);

	return;
}


//===============//
// Ú×   FO`QTTÅFðÝè·éÌRXgN^
// ø   Fint Ô, int Î, int Â, int §¾x
// ßèl FÈµ
//===============//
C_1_Byte_Color::C_1_Byte_Color(int in_red, int in_blue, int in_green, int in_alpha)
{
	m_r = in_red;
	m_g = in_green;
	m_b = in_blue;
	m_a = in_alpha;

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_1_Byte_Color::~C_1_Byte_Color(void)
{
	return;
}


//-- Zb^ --//

//===============//
// Ú×   FO`PÅFÌÝèðs¤
// ø   Ffloat Ô, float Î, float Â, float §¾x
// ßèl Fvoid
//===============//
void C_1_Byte_Color::M_Set_Color_By_0_1(float in_red, float in_green, float in_blue, float in_alpha)
{
	m_r = (unsigned char)(in_red * 255);
	m_g = (unsigned char)(in_green * 255);
	m_b = (unsigned char)(in_blue * 255);
	m_a = (unsigned char)(in_alpha * 255);

	return;
}


//===============//
// Ú×   FO`QTTÅFÌÝèðs¤
// ø   Ffloat Ô, float Î, float Â, float §¾x
// ßèl Fvoid
//===============//
void C_1_Byte_Color::M_Set_Color_By_0_255(int in_red, int in_blue, int in_green, int in_alpha)
{
	m_r = in_red;
	m_g = in_green;
	m_b = in_blue;
	m_a = in_alpha;

	return;
}


//-- Iy[^[ --//

//===============//
// Ú×   FF¯mÌ|¯Z
// ø   FC_1_Byte_Color Fîñ
// ßèl FC_1_Byte_Color FîñÌ|¯ZÊ
//===============//
C_1_Byte_Color C_1_Byte_Color::operator*(C_1_Byte_Color in_color)
{
	//  Ïé¾  //
	C_1_Byte_Color result_color;	// ÊÌF

	
	result_color.m_r = m_r * in_color.m_r;
	result_color.m_g = m_g * in_color.m_g;
	result_color.m_b = m_b * in_color.m_b;
	result_color.m_a = m_a * in_color.m_a;

	return result_color;
}


//===============//
// Ú×   FF¯mÌ|¯Z
// ø   FC_1_Byte_Color Fîñ
// ßèl Fvoid
//===============//
void C_1_Byte_Color::operator=(C_1_Byte_Color in_color)
{
	m_r = in_color.m_r;
	m_g = in_color.m_g;
	m_b = in_color.m_b;
	m_a = in_color.m_a;

	return;
}

