//����������������������������������������������//
// �ڍ�   �F�t���[�g�S�����Ǘ�����N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Float_4.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace MATH::FORMAT;


// �� �N���X �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4::C_Float_4(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Fxyzw�̃p�����[�^�����ɃZ�b�g����R���X�g���N�^
// ����   �Ffloat x�ɃZ�b�g����l, float y�ɃZ�b�g����l, float z�ɃZ�b�g����l, float w�ɃZ�b�g����l
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4::C_Float_4(float in_x, float in_y, float in_z, float in_w)
{
	x = in_x;
	y = in_y;
	z = in_z;
	w = in_w;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4::~C_Float_4(void)
{
	return;
}


//==�� �I�y���[�^ ��==//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_4�Ƃ�=���Z
// ����   �FC_Float_4 �������t���[�g4�l
// �߂�l �FC_Float_4 ������ʂ̃t���[�g4�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4 C_Float_4::operator=(C_Float_4 in_equal_float_4)
{
	x = in_equal_float_4.x;
	y = in_equal_float_4.y;
	z = in_equal_float_4.z;
	w = in_equal_float_4.w;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_4�Ƃ́{���Z
// ����   �FC_Float_4 ���Z����t���[�g4�l
// �߂�l �FC_Float_4 ���Z���ʂ̃t���[�g4�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4 C_Float_4::operator+(C_Float_4 in_plus_float_4)
{
	return C_Float_4(x + in_plus_float_4.x, y + in_plus_float_4.y, z + in_plus_float_4.z, w + in_plus_float_4.w);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_4�Ƃ�-���Z
// ����   �FC_Float_4 ���Z����t���[�g4�l
// �߂�l �FC_Float_4 ���Z���ʂ̃t���[�g4�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4 C_Float_4::operator-(C_Float_4 in_minus_float_4)
{
	return C_Float_4(x - in_minus_float_4.x, y - in_minus_float_4.y, z - in_minus_float_4.z, w - in_minus_float_4.w);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_4�Ƃ́~���Z
// ����   �FC_Float_4 ��Z����t���[�g4�l
// �߂�l �FC_Float_4 ��Z���ʂ̃t���[�g4�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4 C_Float_4::operator*(C_Float_4 in_multiple_float_4)
{
	return C_Float_4(x * in_multiple_float_4.x, y * in_multiple_float_4.y, z * in_multiple_float_4.z, w * in_multiple_float_4.w);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_4�Ƃ�/���Z
// ����   �FC_Float_4 ���Z����t���[�g4�l
// �߂�l �FC_Float_4 ���Z���ʂ̃t���[�g4�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4 C_Float_4::operator/(C_Float_4 in_division_float_4)
{
	return C_Float_4(x / in_division_float_4.x, y / in_division_float_4.y, z / in_division_float_4.z, w / in_division_float_4.w);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_4�Ƃ�%���Z
// ����   �FC_Float_4 ��]�Z����t���[�g4�l
// �߂�l �FC_Float_4 ��]�Z���ʂ̃t���[�g4�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4 C_Float_4::operator%(C_Float_4 in_surplus_float_4)
{
	return C_Float_4((x - (int)(x / in_surplus_float_4.x)), (y - (int)(y / in_surplus_float_4.y)), (z - (int)(z / in_surplus_float_4.z)), (w - (int)(w / in_surplus_float_4.w)));
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_4�Ƃ́{=���Z
// ����   �FC_Float_4 ���Z�������t���[�g4�l
// �߂�l �FC_Float_4 ���Z������ʂ̃t���[�g4�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4 C_Float_4::operator+=(C_Float_4 in_plus_equal_float_4)
{
	x += in_plus_equal_float_4.x;
	y += in_plus_equal_float_4.y;
	z += in_plus_equal_float_4.z;
	w += in_plus_equal_float_4.w;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_4�Ƃ�-=���Z
// ����   �FC_Float_4 ���Z�������t���[�g4�l
// �߂�l �FC_Float_4 ���Z������ʂ̃t���[�g4�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4 C_Float_4::operator-=(C_Float_4 in_minus_equal_float_4)
{
	x -= in_minus_equal_float_4.x;
	y -= in_minus_equal_float_4.y;
	z -= in_minus_equal_float_4.z;
	w -= in_minus_equal_float_4.w;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_4�Ƃ́~=���Z
// ����   �FC_Float_4 ��Z�������t���[�g4�l
// �߂�l �FC_Float_4 ��Z������ʂ̃t���[�g4�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4 C_Float_4::operator*=(C_Float_4 in_multiple_equal_float_4)
{
	x *= in_multiple_equal_float_4.x;
	y *= in_multiple_equal_float_4.y;
	z *= in_multiple_equal_float_4.z;
	w *= in_multiple_equal_float_4.w;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_4�Ƃ�/=���Z
// ����   �FC_Float_4 ���Z�������t���[�g4�l
// �߂�l �FC_Float_4 ���Z������ʂ̃t���[�g4�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4 C_Float_4::operator/=(C_Float_4 in_divide_equal_float_4)
{
	x /= in_divide_equal_float_4.x;
	y /= in_divide_equal_float_4.y;
	z /= in_divide_equal_float_4.z;
	w /= in_divide_equal_float_4.w;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_4�Ƃ�%=���Z
// ����   �FC_Float_4 ��]�Z�������t���[�g4�l
// �߂�l �FC_Float_4 ��]�Z������ʂ̃t���[�g4�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4 C_Float_4::operator%=(C_Float_4 in_surplus_equal_float_4)
{
	x = x - (int)(x / in_surplus_equal_float_4.x);
	y = y - (int)(y / in_surplus_equal_float_4.y);
	z = z - (int)(z / in_surplus_equal_float_4.z);
	w = w - (int)(w / in_surplus_equal_float_4.w);

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ�=���Z
// ����   �Ffloat �������t���[�g�l
// �߂�l �FC_Float_4 ������ʂ̃t���[�g4�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4 C_Float_4::operator=(float in_equal_float)
{
	return C_Float_4(in_equal_float, in_equal_float, in_equal_float, in_equal_float);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ́{���Z
// ����   �Ffloat ���Z����t���[�g�l
// �߂�l �FC_Float_4 ���Z���ʂ̃t���[�g4�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4 C_Float_4::operator+(float in_plus_float)
{
	return C_Float_4(x + in_plus_float, y + in_plus_float, z + in_plus_float, w + in_plus_float);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ�-���Z
// ����   �Ffloat ���Z����t���[�g�l
// �߂�l �FC_Float_4 ���Z���ʂ̃t���[�g4�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4 C_Float_4::operator-(float in_minus_float)
{
	return C_Float_4(x - in_minus_float, y - in_minus_float, z - in_minus_float, w - in_minus_float);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ́~���Z
// ����   �Ffloat ��Z����t���[�g�l
// �߂�l �FC_Float_4 ��Z���ʂ̃t���[�g4�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4 C_Float_4::operator*(float in_multiple_float)
{
	return C_Float_4(x * in_multiple_float, y * in_multiple_float, w * in_multiple_float, z * in_multiple_float);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ�/���Z
// ����   �Ffloat ���Z����t���[�g�l
// �߂�l �FC_Float_4 ���Z���ʂ̃t���[�g4�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4 MATH::FORMAT::C_Float_4::operator/(float in_divide_float)
{
	return C_Float_4(x / in_divide_float, y / in_divide_float, w / in_divide_float, z / in_divide_float);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ�%���Z
// ����   �Ffloat ��]�Z����t���[�g�l
// �߂�l �FC_Float_4 ��]�Z���ʂ̃t���[�g4�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4 C_Float_4::operator%(float in_surplus_float)
{
	return C_Float_4((x - (int)(x / in_surplus_float)), (y - (int)(y / in_surplus_float)), (z - (int)(z / in_surplus_float)), (w - (int)(w / in_surplus_float)));
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ́{=���Z
// ����   �Ffloat ���Z�������t���[�g�l
// �߂�l �FC_Float_4 ���Z������ʂ̃t���[�g4�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4 C_Float_4::operator+=(float in_plus_equal_float)
{
	x += in_plus_equal_float;
	y += in_plus_equal_float;
	z += in_plus_equal_float;
	w += in_plus_equal_float;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ�-=���Z
// ����   �Ffloat ���Z�������t���[�g�l
// �߂�l �FC_Float_4 ���Z������ʂ̃t���[�g4�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4 C_Float_4::operator-=(float in_minus_equal_float)
{
	x -= in_minus_equal_float;
	y -= in_minus_equal_float;
	z -= in_minus_equal_float;
	w -= in_minus_equal_float;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ́~=���Z
// ����   �Ffloat ��Z�������t���[�g�l
// �߂�l �FC_Float_4 ��Z������ʂ̃t���[�g4�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4 C_Float_4::operator*=(float in_multiple_equal_float)
{
	x *= in_multiple_equal_float;
	y *= in_multiple_equal_float;
	z *= in_multiple_equal_float;
	w *= in_multiple_equal_float;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ�/=���Z
// ����   �Ffloat ���Z�������t���[�g�l
// �߂�l �FC_Float_4 ���Z������ʂ̃t���[�g4�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4 C_Float_4::operator/=(float in_divide_equal_float)
{
	x /= in_divide_equal_float;
	y /= in_divide_equal_float;
	z /= in_divide_equal_float;
	w /= in_divide_equal_float;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ�%=���Z
// ����   �Ffloat ��]�Z�������t���[�g�l
// �߂�l �FC_Float_4 ��]�Z������ʂ̃t���[�g4�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_4 C_Float_4::operator%=(float in_surplus_equal_float)
{
	x = x - (int)(x / in_surplus_equal_float);
	y = y - (int)(y / in_surplus_equal_float);
	z = z - (int)(z / in_surplus_equal_float);
	w = w - (int)(w / in_surplus_equal_float);

	return *this;
}

