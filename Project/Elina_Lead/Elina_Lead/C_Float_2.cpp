//����������������������������������������������//
// �ڍ�   �F�t���[�g�R�����Ǘ�����N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Float_2.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace MATH::FORMAT;


// �� �֐� �� //

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2::C_Float_2(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Fxy�̃p�����[�^�����ɃZ�b�g����R���X�g���N�^
// ����   �Ffloat x�ɃZ�b�g����l, float y�ɃZ�b�g����l
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2::C_Float_2(float in_x, float in_y)
{
	x = in_x;
	y = in_y;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2::~C_Float_2(void)
{
}


//-��- �I�y���[�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_2�Ƃ�=���Z
// ����   �FC_Float_2 �������t���[�g2�l
// �߂�l �FC_Float_2 ������ʂ̃t���[�g2�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2 C_Float_2::operator=(C_Float_2 in_equal_float_2)
{
	x = in_equal_float_2.x;
	y = in_equal_float_2.y;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_2�Ƃ́{���Z
// ����   �FC_Float_2 ���Z����t���[�g2�l
// �߂�l �FC_Float_2 ���Z���ʂ̃t���[�g2�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2 C_Float_2::operator+(C_Float_2 in_plus_float_2)
{
	return C_Float_2(x + in_plus_float_2.x, y + in_plus_float_2.y);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_2�Ƃ�-���Z
// ����   �FC_Float_2 ���Z����t���[�g2�l
// �߂�l �FC_Float_2 ���Z���ʂ̃t���[�g2�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2 C_Float_2::operator-(C_Float_2 in_minus_float_2)
{
	return C_Float_2(x - in_minus_float_2.x, y - in_minus_float_2.y);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_2�Ƃ́~���Z
// ����   �FC_Float_2 ��Z����t���[�g2�l
// �߂�l �FC_Float_2 ��Z���ʂ̃t���[�g2�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2 C_Float_2::operator*(C_Float_2 in_multiple_float_2)
{
	return C_Float_2(x * in_multiple_float_2.x, y * in_multiple_float_2.y);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_2�Ƃ�/���Z
// ����   �FC_Float_2 ���Z����t���[�g2�l
// �߂�l �FC_Float_2 ���Z���ʂ̃t���[�g2�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2 C_Float_2::operator/(C_Float_2 in_division_float_2)
{
	return C_Float_2(x / in_division_float_2.x, y / in_division_float_2.y);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_2�Ƃ�%���Z
// ����   �FC_Float_2 ��]�Z����t���[�g2�l
// �߂�l �FC_Float_2 ��]�Z���ʂ̃t���[�g2�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2 C_Float_2::operator%(C_Float_2 in_surplus_float_2)
{
	return C_Float_2((x - (int)(x / in_surplus_float_2.x)), (y - (int)(y / in_surplus_float_2.y)));
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_2�Ƃ́{=���Z
// ����   �FC_Float_2 ���Z�������t���[�g2�l
// �߂�l �FC_Float_2 ���Z������ʂ̃t���[�g2�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2 C_Float_2::operator+=(C_Float_2 in_plus_equal_float_2)
{
	x += in_plus_equal_float_2.x;
	y += in_plus_equal_float_2.y;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_2�Ƃ�-=���Z
// ����   �FC_Float_2 ���Z�������t���[�g2�l
// �߂�l �FC_Float_2 ���Z������ʂ̃t���[�g2�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2 C_Float_2::operator-=(C_Float_2 in_minus_equal_float_2)
{
	x -= in_minus_equal_float_2.x;
	y -= in_minus_equal_float_2.y;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_2�Ƃ́~=���Z
// ����   �FC_Float_2 ��Z�������t���[�g2�l
// �߂�l �FC_Float_2 ��Z������ʂ̃t���[�g2�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2 C_Float_2::operator*=(C_Float_2 in_multiple_equal_float_2)
{
	x *= in_multiple_equal_float_2.x;
	y *= in_multiple_equal_float_2.y;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_2�Ƃ�/=���Z
// ����   �FC_Float_2 ���Z�������t���[�g2�l
// �߂�l �FC_Float_2 ���Z������ʂ̃t���[�g2�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2 C_Float_2::operator/=(C_Float_2 in_divide_equal_float_2)
{
	x /= in_divide_equal_float_2.x;
	y /= in_divide_equal_float_2.y;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_2�Ƃ�%=���Z
// ����   �FC_Float_2 ��]�Z�������t���[�g2�l
// �߂�l �FC_Float_2 ��]�Z������ʂ̃t���[�g2�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2 C_Float_2::operator%=(C_Float_2 in_surplus_equal_float_2)
{
	x = x - (int)(x / in_surplus_equal_float_2.x);
	y = y - (int)(y / in_surplus_equal_float_2.y);

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ�=���Z
// ����   �Ffloat �������t���[�g�l
// �߂�l �FC_Float_2 ������ʂ̃t���[�g2�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2 C_Float_2::operator=(float in_equal_float)
{
	x = in_equal_float;
	y = in_equal_float;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ́{���Z
// ����   �Ffloat ���Z����t���[�g�l
// �߂�l �FC_Float_2 ���Z���ʂ̃t���[�g2�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2 C_Float_2::operator+(float in_plus_float)
{
	return C_Float_2(x + in_plus_float, y + in_plus_float);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ�-���Z
// ����   �Ffloat ���Z����t���[�g�l
// �߂�l �FC_Float_2 ���Z���ʂ̃t���[�g2�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2 C_Float_2::operator-(float in_minus_float)
{
	return C_Float_2(x - in_minus_float, y - in_minus_float);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ́~���Z
// ����   �Ffloat ��Z����t���[�g�l
// �߂�l �FC_Float_2 ��Z���ʂ̃t���[�g2�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2 C_Float_2::operator*(float in_multiple_float)
{
	return C_Float_2(x * in_multiple_float, y * in_multiple_float);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ�/���Z
// ����   �Ffloat ���Z����t���[�g�l
// �߂�l �FC_Float_2 ���Z���ʂ̃t���[�g2�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2 C_Float_2::operator/(float in_division_float)
{
	return C_Float_2(x / in_division_float, y / in_division_float);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ�%���Z
// ����   �Ffloat ��]�Z����t���[�g�l
// �߂�l �FC_Float_2 ��]�Z���ʂ̃t���[�g2�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2 C_Float_2::operator%(float in_surplus_float)
{
	return C_Float_2((x - (int)(x / in_surplus_float)), (y - (int)(y / in_surplus_float)));
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ́{=���Z
// ����   �Ffloat ���Z�������t���[�g�l
// �߂�l �FC_Float_2 ���Z������ʂ̃t���[�g2�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2 C_Float_2::operator+=(float in_plus_equal_float)
{
	x += in_plus_equal_float;
	y += in_plus_equal_float;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ�-=���Z
// ����   �Ffloat ���Z�������t���[�g�l
// �߂�l �FC_Float_2 ���Z������ʂ̃t���[�g2�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2 C_Float_2::operator-=(float in_minus_equal_float)
{
	x -= in_minus_equal_float;
	y -= in_minus_equal_float;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ́~=���Z
// ����   �Ffloat ��Z�������t���[�g�l
// �߂�l �FC_Float_2 ��Z������ʂ̃t���[�g2�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2 C_Float_2::operator*=(float in_multiple_equal_float)
{
	x *= in_multiple_equal_float;
	y *= in_multiple_equal_float;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ�/=���Z
// ����   �Ffloat ���Z�������t���[�g�l
// �߂�l �FC_Float_2 ���Z������ʂ̃t���[�g2�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2 C_Float_2::operator/=(float in_divide_equal_float)
{
	x /= in_divide_equal_float;
	y /= in_divide_equal_float;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ�%=���Z
// ����   �Ffloat ��]�Z�������t���[�g�l
// �߂�l �FC_Float_2 ��]�Z������ʂ̃t���[�g2�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_2 C_Float_2::operator%=(float in_surplus_equal_float)
{
	x = x - (int)(x / in_surplus_equal_float);
	y = y - (int)(y / in_surplus_equal_float);

	return *this;
}
