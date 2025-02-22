////
// Ú×   FQoCgÌFðè`·é\¢Ì
// à¾   F
// ì¬Ò Fûüâ´½
////


//  l[Xy[XÌÈª  //
#include "C_Half_Color.h"


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
C_Half_Color::C_Half_Color(void)
{
	return;
}


//===============//
// Ú×   FO`PÅFðÝè·éÌRXgN^
// ø   Ffloat Ô, float Î, float Â, float §¾x
// ßèl FÈµ
//===============//
C_Half_Color::C_Half_Color(float in_red, float in_green, float in_blue, float in_alpha)
{
	m_r = DirectX::PackedVector::XMConvertFloatToHalf(in_red);
	m_g = DirectX::PackedVector::XMConvertFloatToHalf(in_green);
	m_b = DirectX::PackedVector::XMConvertFloatToHalf(in_blue);
	m_a = DirectX::PackedVector::XMConvertFloatToHalf(in_alpha);

	return;
}


//===============//
// Ú×   FO`QTTÅFðÝè·éÌRXgN^
// ø   Fint Ô, int Î, int Â, int §¾x
// ßèl FÈµ
//===============//
C_Half_Color::C_Half_Color(int in_red, int in_green, int in_blue, int in_alpha)
{
	m_r = DirectX::PackedVector::XMConvertFloatToHalf(in_red / 255.0f);
	m_g = DirectX::PackedVector::XMConvertFloatToHalf(in_green / 255.0f);
	m_b = DirectX::PackedVector::XMConvertFloatToHalf(in_blue / 255.0f);
	m_a = DirectX::PackedVector::XMConvertFloatToHalf(in_alpha / 255.0f);

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Half_Color::~C_Half_Color(void)
{
	return;
}


//-- Zb^ --//

//===============//
// Ú×   FO`PÅFðÝè·éÌRXgN^
// ø   Ffloat Ô, float Î, float Â, float §¾x
// ßèl Fvoid
//===============//
void C_Half_Color::M_Set_Color_By_0_1(float in_red, float in_green, float in_blue, float in_alpha)
{
	m_r = DirectX::PackedVector::XMConvertFloatToHalf(in_red);
	m_g = DirectX::PackedVector::XMConvertFloatToHalf(in_green);
	m_b = DirectX::PackedVector::XMConvertFloatToHalf(in_blue);
	m_a = DirectX::PackedVector::XMConvertFloatToHalf(in_alpha);

	return;
}


//===============//
// Ú×   FO`QTTÅFðÝè·éÌRXgN^
// ø   Fint Ô, int Î, int Â, int §¾x
// ßèl Fvoid
//===============//
void C_Half_Color::M_Set_Color_By_0_255(int in_red, int in_green, int in_blue, int in_alpha)
{
	m_r = DirectX::PackedVector::XMConvertFloatToHalf(in_red / 255.0f);
	m_g = DirectX::PackedVector::XMConvertFloatToHalf(in_green / 255.0f);
	m_b = DirectX::PackedVector::XMConvertFloatToHalf(in_blue / 255.0f);
	m_a = DirectX::PackedVector::XMConvertFloatToHalf(in_alpha / 255.0f);

	return;
}


//-- Iy[^[ --//

//===============//
// Ú×   FF¯mÌ|¯Z
// ø   FC_Half_Color Fîñ
// ßèl FC_Half_Color FîñÌ|¯ZÊ
//===============//
C_Half_Color C_Half_Color::operator*(C_Half_Color in_color)
{
	//  Ïé¾  //
	C_Half_Color result_value;	// ÊÌFîñ


	result_value.m_r = m_r * in_color.m_r;
	result_value.m_g = m_g * in_color.m_g;
	result_value.m_b = m_b * in_color.m_b;
	result_value.m_a = m_a * in_color.m_a;

	return result_value;
}


//===============//
// Ú×   FFðÝè·é
// ø   FC_Half_Color Fîñ
// ßèl Fvoid
//===============//
void C_Half_Color::operator=(C_Half_Color in_color)
{
	m_r = in_color.m_r;
	m_g = in_color.m_g;
	m_b = in_color.m_b;
	m_a = in_color.m_a;

	return;
}

