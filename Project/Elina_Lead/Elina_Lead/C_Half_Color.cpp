//����������������������������������������������//
// �ڍ�   �F�Q�o�C�g�̐F���`����\����
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �l�[���X�y�[�X�̏ȗ� �� //
#include "C_Half_Color.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace DATA::COLOR;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Half_Color::C_Half_Color(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�O�`�P�ŐF��ݒ肷�鎞�̃R���X�g���N�^
// ����   �Ffloat ��, float ��, float ��, float �����x
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Half_Color::C_Half_Color(float in_red, float in_green, float in_blue, float in_alpha)
{
	m_r = DirectX::PackedVector::XMConvertFloatToHalf(in_red);
	m_g = DirectX::PackedVector::XMConvertFloatToHalf(in_green);
	m_b = DirectX::PackedVector::XMConvertFloatToHalf(in_blue);
	m_a = DirectX::PackedVector::XMConvertFloatToHalf(in_alpha);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�O�`�Q�T�T�ŐF��ݒ肷�鎞�̃R���X�g���N�^
// ����   �Fint ��, int ��, int ��, int �����x
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Half_Color::C_Half_Color(int in_red, int in_green, int in_blue, int in_alpha)
{
	m_r = DirectX::PackedVector::XMConvertFloatToHalf(in_red / 255.0f);
	m_g = DirectX::PackedVector::XMConvertFloatToHalf(in_green / 255.0f);
	m_b = DirectX::PackedVector::XMConvertFloatToHalf(in_blue / 255.0f);
	m_a = DirectX::PackedVector::XMConvertFloatToHalf(in_alpha / 255.0f);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Half_Color::~C_Half_Color(void)
{
	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�O�`�P�ŐF��ݒ肷�鎞�̃R���X�g���N�^
// ����   �Ffloat ��, float ��, float ��, float �����x
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Half_Color::M_Set_Color_By_0_1(float in_red, float in_green, float in_blue, float in_alpha)
{
	m_r = DirectX::PackedVector::XMConvertFloatToHalf(in_red);
	m_g = DirectX::PackedVector::XMConvertFloatToHalf(in_green);
	m_b = DirectX::PackedVector::XMConvertFloatToHalf(in_blue);
	m_a = DirectX::PackedVector::XMConvertFloatToHalf(in_alpha);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�O�`�Q�T�T�ŐF��ݒ肷�鎞�̃R���X�g���N�^
// ����   �Fint ��, int ��, int ��, int �����x
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Half_Color::M_Set_Color_By_0_255(int in_red, int in_green, int in_blue, int in_alpha)
{
	m_r = DirectX::PackedVector::XMConvertFloatToHalf(in_red / 255.0f);
	m_g = DirectX::PackedVector::XMConvertFloatToHalf(in_green / 255.0f);
	m_b = DirectX::PackedVector::XMConvertFloatToHalf(in_blue / 255.0f);
	m_a = DirectX::PackedVector::XMConvertFloatToHalf(in_alpha / 255.0f);

	return;
}


//-��- �I�y���[�^�[ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�F���m�̊|���Z
// ����   �FC_Half_Color �F���
// �߂�l �FC_Half_Color �F���̊|���Z����
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Half_Color C_Half_Color::operator*(C_Half_Color in_color)
{
	// �� �ϐ��錾 �� //
	C_Half_Color result_value;	// ���ʂ̐F���


	result_value.m_r = m_r * in_color.m_r;
	result_value.m_g = m_g * in_color.m_g;
	result_value.m_b = m_b * in_color.m_b;
	result_value.m_a = m_a * in_color.m_a;

	return result_value;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�F��ݒ肷��
// ����   �FC_Half_Color �F���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Half_Color::operator=(C_Half_Color in_color)
{
	m_r = in_color.m_r;
	m_g = in_color.m_g;
	m_b = in_color.m_b;
	m_a = in_color.m_a;

	return;
}

