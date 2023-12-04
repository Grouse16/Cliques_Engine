//����������������������������������������������//
// �ڍ�   �F�F��`�p�̃t�@�C��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Color.h"


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
C_Color::C_Color(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�O�`�P�ŐF��ݒ肷�鎞�̃R���X�g���N�^
// ����   �Ffloat ��, float ��, float ��, float �����x
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Color::C_Color(float in_r, float in_g, float in_b, float in_a)
{
	m_r = in_r;
	m_g = in_g;
	m_b = in_b;
	m_a = in_a;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�O�`�Q�T�T�ŐF��ݒ肷�鎞�̃R���X�g���N�^
// ����   �Fint ��, int ��, int ��, int �����x
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Color::C_Color(int in_r, int in_g, int in_b, int in_a)
{
	m_r = in_r / 255.0f;
	m_g = in_g / 255.0f;
	m_b = in_b / 255.0f;
	m_a = in_a / 255.0f;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Color::~C_Color(void)
{
	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�O�`�P�ŐF�̐ݒ���s��
// ����   �Ffloat ��, float ��, float ��, float �����x
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Color::M_Set_Color_By_0_1(float in_r, float in_g, float in_b, float in_a)
{
	m_r = in_r;
	m_g = in_g;
	m_b = in_b;
	m_a = in_a;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�O�`�Q�T�T�ŐF�̐ݒ���s��
// ����   �Fint ��, int ��, int ��, int �����x
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Color::M_Set_Color_By_0_255(int in_r, int in_g, int in_b, int in_a)
{
	m_r = in_r / static_cast<float>(255);
	m_g = in_g / static_cast<float>(255);
	m_b = in_b / static_cast<float>(255);
	m_a = in_a / static_cast<float>(255);

	return;
}


//-��- �I�y���[�^�[ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�F���m�̊|���Z
// ����   �FC_Color �F���
// �߂�l �FC_Color �F���̊|���Z����
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Color C_Color::operator*(C_Color in_color)
{
	// �� �ϐ��錾 �� //
	C_Color result;	// �v�Z����


	// �F����������
	result.m_r = in_color.m_r * m_r;
	result.m_g = in_color.m_g * m_g;
	result.m_b = in_color.m_b * m_b;
	result.m_a = in_color.m_a * m_a;

	return result;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�F��ݒ肷��
// ����   �FC_Color �F���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Color::operator=(C_Color in_color)
{
	// �F���Z�b�g����
	m_r = in_color.m_r;
	m_g = in_color.m_g;
	m_b = in_color.m_b;
	m_a = in_color.m_a;

	return;
}

