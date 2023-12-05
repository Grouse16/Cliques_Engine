//����������������������������������������������//
// �ڍ�   �F�O��ނ̐F���Ԃ̕ϊ����s���N���X
// ����   �F�O��ނ̐F�Ƃ́AC_Color C_Half_Color C_1_Byte_Color�̂���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �l�[���X�y�[�X�̏ȗ� �� //
#include "C_Color_Converter.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace DATA::COLOR;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- 4�o�C�g�F�ւ̕ϊ� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F1�o�C�g�F����4�o�C�g�F�ւ̕ϊ�
// ����   �FC_1_Byte_Color & 1�o�C�g�F�̎Q��
// �߂�l �FC_Color 4�o�C�g�F
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Color C_Color_Converter::M_Convert_1_Byte_Color_To_Color(const C_1_Byte_Color & in_convert_by)
{
	// �� �ϐ��錾 �� //
	C_Color result_convert;	// �ϊ�����


	result_convert.m_r = in_convert_by.m_r / 255.0f;
	result_convert.m_g = in_convert_by.m_g / 255.0f;
	result_convert.m_b = in_convert_by.m_b / 255.0f;
	result_convert.m_a = in_convert_by.m_a / 255.0f;
	
	return result_convert;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F2�o�C�g�F����4�o�C�g�F�ւ̕ϊ�
// ����   �FC_1_Byte_Color & 2�o�C�g�F�̎Q��
// �߂�l �FC_Color 4�o�C�g�F
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Color C_Color_Converter::M_Convert_Half_Color_To_Color(const C_Half_Color & in_convert_by)
{
	// �� �ϐ��錾 �� //
	C_Color result_convert;	// �ϊ�����


	result_convert.m_r = DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_r);
	result_convert.m_g = DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_g);
	result_convert.m_b = DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_b);
	result_convert.m_a = DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_a);

	return result_convert;
}


//-��- 2�o�C�g�F�ւ̕ϊ� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F1�o�C�g�F����2�o�C�g�F�ւ̕ϊ�
// ����   �FC_1_Byte_Color & 1�o�C�g�F�̎Q��
// �߂�l �FC_Half_Color 2�o�C�g�F
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Half_Color C_Color_Converter::M_Convert_1_Byte_Color_To_Half_Color(const C_1_Byte_Color & in_convert_by)
{
	// �� �ϐ��錾 �� //
	C_Half_Color result_convert;	// �ϊ�����


	result_convert.m_r = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_r / 255.0f);
	result_convert.m_g = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_g / 255.0f);
	result_convert.m_b = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_b / 255.0f);
	result_convert.m_a = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_a / 255.0f);

	return result_convert;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F4�o�C�g�F����2�o�C�g�F�ւ̕ϊ�
// ����   �FC_Color & 4�o�C�g�F�̎Q��
// �߂�l �FC_Half_Color 2�o�C�g�F
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Half_Color C_Color_Converter::M_Convert_Color_To_Half_Color(const C_Color & in_convert_by)
{
	// �� �ϐ��錾 �� //
	C_Half_Color result_convert;	// �ϊ�����


	result_convert.m_r = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_r);
	result_convert.m_g = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_g);
	result_convert.m_b = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_b);
	result_convert.m_a = DirectX::PackedVector::XMConvertFloatToHalf(in_convert_by.m_a);

	return result_convert;
}


//-��- 1�o�C�g�F�ւ̕ϊ� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F2�o�C�g�F����1�o�C�g�F�ւ̕ϊ�
// ����   �FC_Half_Color & 2�o�C�g�F�̎Q��
// �߂�l �FC_1_Byte_Color 1�o�C�g�F
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_1_Byte_Color C_Color_Converter::M_Convert_Half_Color_To_1_Byte_Color(const C_Half_Color & in_convert_by)
{
	// �� �ϐ��錾 �� //
	C_1_Byte_Color result_convert;	// �ϊ�����


	result_convert.m_r = DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_r) * 255.0f;
	result_convert.m_g = DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_g) * 255.0f;
	result_convert.m_b = DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_b) * 255.0f;
	result_convert.m_a = DirectX::PackedVector::XMConvertHalfToFloat(in_convert_by.m_a) * 255.0f;

	return result_convert;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F4�o�C�g�F����1�o�C�g�F�ւ̕ϊ�
// ����   �FC_Color & 4�o�C�g�F�̎Q��
// �߂�l �FC_1_Byte_Color 1�o�C�g�F
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_1_Byte_Color C_Color_Converter::M_Convert_Color_To_1_Byte_Color(const C_Color & in_convert_by)
{
	// �� �ϐ��錾 �� //
	C_1_Byte_Color result_convert;	// �ϊ�����
	
	
	result_convert.m_r = in_convert_by.m_r * 255.0f;
	result_convert.m_g = in_convert_by.m_g * 255.0f;
	result_convert.m_b = in_convert_by.m_b * 255.0f;
	result_convert.m_a = in_convert_by.m_a * 255.0f;

	return result_convert;
}
