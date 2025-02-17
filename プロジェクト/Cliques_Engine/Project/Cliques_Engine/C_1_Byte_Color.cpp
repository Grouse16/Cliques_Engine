//����������������������������������������������//
// �ڍ�   �F�P�o�C�g�̃J���[�̍\����
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_1_Byte_Color.h"


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
C_1_Byte_Color::C_1_Byte_Color(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�O�`�P�ŐF��ݒ肷�鎞�̃R���X�g���N�^
// ����   �Ffloat ��, float ��, float ��, float �����x
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_1_Byte_Color::C_1_Byte_Color(float in_red, float in_green, float in_blue, float in_alpha)
{
	m_r = (unsigned char)(in_red * 255);
	m_g = (unsigned char)(in_green * 255);
	m_b = (unsigned char)(in_blue * 255);
	m_a = (unsigned char)(in_alpha * 255);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�O�`�Q�T�T�ŐF��ݒ肷�鎞�̃R���X�g���N�^
// ����   �Fint ��, int ��, int ��, int �����x
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_1_Byte_Color::C_1_Byte_Color(int in_red, int in_blue, int in_green, int in_alpha)
{
	m_r = in_red;
	m_g = in_green;
	m_b = in_blue;
	m_a = in_alpha;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_1_Byte_Color::~C_1_Byte_Color(void)
{
	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�O�`�P�ŐF�̐ݒ���s��
// ����   �Ffloat ��, float ��, float ��, float �����x
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_1_Byte_Color::M_Set_Color_By_0_1(float in_red, float in_green, float in_blue, float in_alpha)
{
	m_r = (unsigned char)(in_red * 255);
	m_g = (unsigned char)(in_green * 255);
	m_b = (unsigned char)(in_blue * 255);
	m_a = (unsigned char)(in_alpha * 255);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�O�`�Q�T�T�ŐF�̐ݒ���s��
// ����   �Ffloat ��, float ��, float ��, float �����x
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_1_Byte_Color::M_Set_Color_By_0_255(int in_red, int in_blue, int in_green, int in_alpha)
{
	m_r = in_red;
	m_g = in_green;
	m_b = in_blue;
	m_a = in_alpha;

	return;
}


//-��- �I�y���[�^�[ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�F���m�̊|���Z
// ����   �FC_1_Byte_Color �F���
// �߂�l �FC_1_Byte_Color �F���̊|���Z����
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_1_Byte_Color C_1_Byte_Color::operator*(C_1_Byte_Color in_color)
{
	// �� �ϐ��錾 �� //
	C_1_Byte_Color result_color;	// ���ʂ̐F

	
	result_color.m_r = m_r * in_color.m_r;
	result_color.m_g = m_g * in_color.m_g;
	result_color.m_b = m_b * in_color.m_b;
	result_color.m_a = m_a * in_color.m_a;

	return result_color;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�F���m�̊|���Z
// ����   �FC_1_Byte_Color �F���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_1_Byte_Color::operator=(C_1_Byte_Color in_color)
{
	m_r = in_color.m_r;
	m_g = in_color.m_g;
	m_b = in_color.m_b;
	m_a = in_color.m_a;

	return;
}

