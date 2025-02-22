////
// Ú×   FOíÞÌFîñÔÌÏ·ðs¤NX
// à¾   FOíÞÌFÆÍAC_Color C_Half_Color C_1_Byte_ColorÌ±Æ
// ì¬Ò Fûüâ´½
////


//  l[Xy[XÌÈª  //
#include "C_Color_Converter.h"


//  l[Xy[XÌÈª  //
using namespace DATA::COLOR;


//  Ö  //

//== pubN ==//

//-- 4oCgFÖÌÏ· --//

//===============//
// Ú×   F1oCgF©ç4oCgFÖÌÏ·
// ø   FC_1_Byte_Color & 1oCgFÌQÆ
// ßèl FC_Color 4oCgF
//===============//
C_Color C_Color_Converter::M_Convert_1_Byte_Color_To_Color(const C_1_Byte_Color & in_convert_by)
{
	//  Ïé¾  //
	C_Color result_convert;	// Ï·Ê


	result_convert.m_r = in_convert_by.m_r / 255.0f;
	result_convert.m_g = in_convert_by.m_g / 255.0f;
	result_convert.m_b = in_convert_by.m_b / 255.0f;
	result_convert.m_a = in_convert_by.m_a / 255.0f;
	
	return result_convert;
}


//===============//
// Ú×   F2oCgF©ç4oCgFÖÌÏ·
// ø   FC_1_Byte_Color & 2oCgFÌQÆ
// ßèl FC_Color 4oCgF
//===============//
C_Color C_Color_Converter::M_Convert_Half_Color_To_Color(const C_Half_Color & in_convert_by)
{
	//  Ïé¾  //
	C_Color result_convert;	// Ï·Ê


	result_convert.m_r = DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_r);
	result_convert.m_g = DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_g);
	result_convert.m_b = DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_b);
	result_convert.m_a = DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_a);

	return result_convert;
}


//-- 2oCgFÖÌÏ· --//

//===============//
// Ú×   F1oCgF©ç2oCgFÖÌÏ·
// ø   FC_1_Byte_Color & 1oCgFÌQÆ
// ßèl FC_Half_Color 2oCgF
//===============//
C_Half_Color C_Color_Converter::M_Convert_1_Byte_Color_To_Half_Color(const C_1_Byte_Color & in_convert_by)
{
	//  Ïé¾  //
	C_Half_Color result_convert;	// Ï·Ê


	result_convert.m_r = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_r / 255.0f);
	result_convert.m_g = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_g / 255.0f);
	result_convert.m_b = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_b / 255.0f);
	result_convert.m_a = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_a / 255.0f);

	return result_convert;
}


//===============//
// Ú×   F4oCgF©ç2oCgFÖÌÏ·
// ø   FC_Color & 4oCgFÌQÆ
// ßèl FC_Half_Color 2oCgF
//===============//
C_Half_Color C_Color_Converter::M_Convert_Color_To_Half_Color(const C_Color & in_convert_by)
{
	//  Ïé¾  //
	C_Half_Color result_convert;	// Ï·Ê


	result_convert.m_r = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_r);
	result_convert.m_g = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_g);
	result_convert.m_b = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_b);
	result_convert.m_a = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_a);

	return result_convert;
}


//-- 1oCgFÖÌÏ· --//

//===============//
// Ú×   F2oCgF©ç1oCgFÖÌÏ·
// ø   FC_Half_Color & 2oCgFÌQÆ
// ßèl FC_1_Byte_Color 1oCgF
//===============//
C_1_Byte_Color C_Color_Converter::M_Convert_Half_Color_To_1_Byte_Color(const C_Half_Color & in_convert_by)
{
	//  Ïé¾  //
	C_1_Byte_Color result_convert;	// Ï·Ê


	result_convert.m_r = (unsigned char)(DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_r) * 255.0f);
	result_convert.m_g = (unsigned char)(DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_g) * 255.0f);
	result_convert.m_b = (unsigned char)(DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_b) * 255.0f);
	result_convert.m_a = (unsigned char)(DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_a) * 255.0f);

	return result_convert;
}


//===============//
// Ú×   F4oCgF©ç1oCgFÖÌÏ·
// ø   FC_Color & 4oCgFÌQÆ
// ßèl FC_1_Byte_Color 1oCgF
//===============//
C_1_Byte_Color C_Color_Converter::M_Convert_Color_To_1_Byte_Color(const C_Color & in_convert_by)
{
	//  Ïé¾  //
	C_1_Byte_Color result_convert;	// Ï·Ê
	
	
	result_convert.m_r = (unsigned char)(in_convert_by.m_r * 255.0f);
	result_convert.m_g = (unsigned char)(in_convert_by.m_g * 255.0f);
	result_convert.m_b = (unsigned char)(in_convert_by.m_b * 255.0f);
	result_convert.m_a = (unsigned char)(in_convert_by.m_a * 255.0f);

	return result_convert;
}
