//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：三種類の色情報間の変換を行うクラス
// 説明   ：三種類の色とは、C_Color C_Half_Color C_1_Byte_Colorのこと
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ネームスペースの省略 ☆ //
#include "C_Color_Converter.h"


// ☆ ネームスペースの省略 ☆ //
using namespace DATA::COLOR;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 4バイト色への変換 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：1バイト色から4バイト色への変換
// 引数   ：C_1_Byte_Color & 1バイト色の参照
// 戻り値 ：C_Color 4バイト色
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Color C_Color_Converter::M_Convert_1_Byte_Color_To_Color(const C_1_Byte_Color & in_convert_by)
{
	// ☆ 変数宣言 ☆ //
	C_Color result_convert;	// 変換結果


	result_convert.m_r = in_convert_by.m_r / 255.0f;
	result_convert.m_g = in_convert_by.m_g / 255.0f;
	result_convert.m_b = in_convert_by.m_b / 255.0f;
	result_convert.m_a = in_convert_by.m_a / 255.0f;
	
	return result_convert;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：2バイト色から4バイト色への変換
// 引数   ：C_1_Byte_Color & 2バイト色の参照
// 戻り値 ：C_Color 4バイト色
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Color C_Color_Converter::M_Convert_Half_Color_To_Color(const C_Half_Color & in_convert_by)
{
	// ☆ 変数宣言 ☆ //
	C_Color result_convert;	// 変換結果


	result_convert.m_r = DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_r);
	result_convert.m_g = DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_g);
	result_convert.m_b = DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_b);
	result_convert.m_a = DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_a);

	return result_convert;
}


//-☆- 2バイト色への変換 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：1バイト色から2バイト色への変換
// 引数   ：C_1_Byte_Color & 1バイト色の参照
// 戻り値 ：C_Half_Color 2バイト色
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Half_Color C_Color_Converter::M_Convert_1_Byte_Color_To_Half_Color(const C_1_Byte_Color & in_convert_by)
{
	// ☆ 変数宣言 ☆ //
	C_Half_Color result_convert;	// 変換結果


	result_convert.m_r = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_r / 255.0f);
	result_convert.m_g = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_g / 255.0f);
	result_convert.m_b = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_b / 255.0f);
	result_convert.m_a = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_a / 255.0f);

	return result_convert;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：4バイト色から2バイト色への変換
// 引数   ：C_Color & 4バイト色の参照
// 戻り値 ：C_Half_Color 2バイト色
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Half_Color C_Color_Converter::M_Convert_Color_To_Half_Color(const C_Color & in_convert_by)
{
	// ☆ 変数宣言 ☆ //
	C_Half_Color result_convert;	// 変換結果


	result_convert.m_r = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_r);
	result_convert.m_g = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_g);
	result_convert.m_b = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_b);
	result_convert.m_a = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_a);

	return result_convert;
}


//-☆- 1バイト色への変換 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：2バイト色から1バイト色への変換
// 引数   ：C_Half_Color & 2バイト色の参照
// 戻り値 ：C_1_Byte_Color 1バイト色
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_1_Byte_Color C_Color_Converter::M_Convert_Half_Color_To_1_Byte_Color(const C_Half_Color & in_convert_by)
{
	// ☆ 変数宣言 ☆ //
	C_1_Byte_Color result_convert;	// 変換結果


	result_convert.m_r = DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_r) * 255.0f;
	result_convert.m_g = DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_g) * 255.0f;
	result_convert.m_b = DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_b) * 255.0f;
	result_convert.m_a = DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_a) * 255.0f;

	return result_convert;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：4バイト色から1バイト色への変換
// 引数   ：C_Color & 4バイト色の参照
// 戻り値 ：C_1_Byte_Color 1バイト色
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_1_Byte_Color C_Color_Converter::M_Convert_Color_To_1_Byte_Color(const C_Color & in_convert_by)
{
	// ☆ 変数宣言 ☆ //
	C_1_Byte_Color result_convert;	// 変換結果
	
	
	result_convert.m_r = in_convert_by.m_r * 255.0f;
	result_convert.m_g = in_convert_by.m_g * 255.0f;
	result_convert.m_b = in_convert_by.m_b * 255.0f;
	result_convert.m_a = in_convert_by.m_a * 255.0f;

	return result_convert;
}
