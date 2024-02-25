//����������������������������������������������//
// �ڍ�   �F�t���[�g�R�����Ǘ�����N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Float_3.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace MATH::FORMAT;


// �� �֐� �� //

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3::C_Float_3(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Fxyz�̃p�����[�^�����ɃZ�b�g����R���X�g���N�^
// ����   �Ffloat x�ɃZ�b�g����l, float y�ɃZ�b�g����l, float z�ɃZ�b�g����l
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3::C_Float_3(float in_x, float in_y, float in_z)
{
	x = in_x;
	y = in_y;
	z = in_z;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3::~C_Float_3(void)
{
}


//-��- �I�y���[�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_3�Ƃ�=���Z
// ����   �FC_Float_3 �������t���[�g3�l
// �߂�l �FC_Float_3 ������ʂ̃t���[�g3�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3 C_Float_3::operator=(C_Float_3 in_equal_float_3)
{
	x = in_equal_float_3.x;
	y = in_equal_float_3.y;
	z = in_equal_float_3.z;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_3�Ƃ́{���Z
// ����   �FC_Float_3 ���Z����t���[�g3�l
// �߂�l �FC_Float_3 ���Z���ʂ̃t���[�g3�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3 C_Float_3::operator+(C_Float_3 in_plus_float_3)
{
	return C_Float_3(x + in_plus_float_3.x, y + in_plus_float_3.y, z + in_plus_float_3.z);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_3�Ƃ�-���Z
// ����   �FC_Float_3 ���Z����t���[�g3�l
// �߂�l �FC_Float_3 ���Z���ʂ̃t���[�g3�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3 C_Float_3::operator-(C_Float_3 in_minus_float_3)
{
	return C_Float_3(x - in_minus_float_3.x, y - in_minus_float_3.y, z - in_minus_float_3.z);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_3�Ƃ́~���Z
// ����   �FC_Float_3 ��Z����t���[�g3�l
// �߂�l �FC_Float_3 ��Z���ʂ̃t���[�g3�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3 C_Float_3::operator*(C_Float_3 in_multiple_float_3)
{
	return C_Float_3(x * in_multiple_float_3.x, y * in_multiple_float_3.y, z * in_multiple_float_3.z);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_3�Ƃ�/���Z
// ����   �FC_Float_3 ���Z����t���[�g3�l
// �߂�l �FC_Float_3 ���Z���ʂ̃t���[�g3�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3 C_Float_3::operator/(C_Float_3 in_division_float_3)
{
	return C_Float_3(x / in_division_float_3.x, y / in_division_float_3.y, z / in_division_float_3.z);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_3�Ƃ�%���Z
// ����   �FC_Float_3 ��]�Z����t���[�g3�l
// �߂�l �FC_Float_3 ��]�Z���ʂ̃t���[�g3�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3 C_Float_3::operator%(C_Float_3 in_surplus_float_3)
{
	return C_Float_3((x - (int)(x / in_surplus_float_3.x)), (y - (int)(y / in_surplus_float_3.y)), (z - (int)(z / in_surplus_float_3.z)));
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_3�Ƃ́{=���Z
// ����   �FC_Float_3 ���Z�������t���[�g3�l
// �߂�l �FC_Float_3 ���Z������ʂ̃t���[�g3�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3 C_Float_3::operator+=(C_Float_3 in_plus_equal_float_3)
{
	x += in_plus_equal_float_3.x;
	y += in_plus_equal_float_3.y;
	z += in_plus_equal_float_3.z;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_3�Ƃ�-=���Z
// ����   �FC_Float_3 ���Z�������t���[�g3�l
// �߂�l �FC_Float_3 ���Z������ʂ̃t���[�g3�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3 C_Float_3::operator-=(C_Float_3 in_minus_equal_float_3)
{
	x -= in_minus_equal_float_3.x;
	y -= in_minus_equal_float_3.y;
	z -= in_minus_equal_float_3.z;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_3�Ƃ́~=���Z
// ����   �FC_Float_3 ��Z�������t���[�g3�l
// �߂�l �FC_Float_3 ��Z������ʂ̃t���[�g3�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3 C_Float_3::operator*=(C_Float_3 in_multiple_equal_float_3)
{
	x *= in_multiple_equal_float_3.x;
	y *= in_multiple_equal_float_3.y;
	z *= in_multiple_equal_float_3.z;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_3�Ƃ�/=���Z
// ����   �FC_Float_3 ���Z�������t���[�g3�l
// �߂�l �FC_Float_3 ���Z������ʂ̃t���[�g3�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3 C_Float_3::operator/=(C_Float_3 in_divide_equal_float_3)
{
	x /= in_divide_equal_float_3.x;
	y /= in_divide_equal_float_3.y;
	z /= in_divide_equal_float_3.z;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FC_Float_3�Ƃ�%=���Z
// ����   �FC_Float_3 ��]�Z�������t���[�g3�l
// �߂�l �FC_Float_3 ��]�Z������ʂ̃t���[�g3�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3 C_Float_3::operator%=(C_Float_3 in_surplus_equal_float_3)
{
	x = x - (int)(x / in_surplus_equal_float_3.x);
	y = y - (int)(y / in_surplus_equal_float_3.y);
	z = z - (int)(z / in_surplus_equal_float_3.z);

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ�=���Z
// ����   �Ffloat �������t���[�g�l
// �߂�l �FC_Float_3 ������ʂ̃t���[�g3�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3 C_Float_3::operator=(float in_equal_float)
{
	x = in_equal_float;
	y = in_equal_float;
	z = in_equal_float;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ́{���Z
// ����   �Ffloat ���Z����t���[�g�l
// �߂�l �FC_Float_3 ���Z���ʂ̃t���[�g3�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3 C_Float_3::operator+(float in_plus_float)
{
	return C_Float_3(x + in_plus_float, y + in_plus_float, z + in_plus_float);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ�-���Z
// ����   �Ffloat ���Z����t���[�g�l
// �߂�l �FC_Float_3 ���Z���ʂ̃t���[�g3�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3 C_Float_3::operator-(float in_minus_float)
{
	return C_Float_3(x - in_minus_float, y - in_minus_float, z - in_minus_float);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ́~���Z
// ����   �Ffloat ��Z����t���[�g�l
// �߂�l �FC_Float_3 ��Z���ʂ̃t���[�g3�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3 C_Float_3::operator*(float in_multiple_float)
{
	return C_Float_3(x * in_multiple_float, y * in_multiple_float, z * in_multiple_float);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ�/���Z
// ����   �Ffloat ���Z����t���[�g�l
// �߂�l �FC_Float_3 ���Z���ʂ̃t���[�g3�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3 C_Float_3::operator/(float in_division_float)
{
	return C_Float_3(x / in_division_float, y / in_division_float, z / in_division_float);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ�%���Z
// ����   �Ffloat ��]�Z����t���[�g�l
// �߂�l �FC_Float_3 ��]�Z���ʂ̃t���[�g3�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3 C_Float_3::operator%(float in_surplus_float)
{
	return C_Float_3((x - (int)(x / in_surplus_float)), (y - (int)(y / in_surplus_float)), (z - (int)(z / in_surplus_float)));
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ́{=���Z
// ����   �Ffloat ���Z�������t���[�g�l
// �߂�l �FC_Float_3 ���Z������ʂ̃t���[�g3�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3 C_Float_3::operator+=(float in_plus_equal_float)
{
	x += in_plus_equal_float;
	y += in_plus_equal_float;
	z += in_plus_equal_float;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ�-=���Z
// ����   �Ffloat ���Z�������t���[�g�l
// �߂�l �FC_Float_3 ���Z������ʂ̃t���[�g3�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3 C_Float_3::operator-=(float in_minus_equal_float)
{
	x -= in_minus_equal_float;
	y -= in_minus_equal_float;
	z -= in_minus_equal_float;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ́~=���Z
// ����   �Ffloat ��Z�������t���[�g�l
// �߂�l �FC_Float_3 ��Z������ʂ̃t���[�g3�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3 C_Float_3::operator*=(float in_multiple_equal_float)
{
	x *= in_multiple_equal_float;
	y *= in_multiple_equal_float;
	z *= in_multiple_equal_float;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ�/=���Z
// ����   �Ffloat ���Z�������t���[�g�l
// �߂�l �FC_Float_3 ���Z������ʂ̃t���[�g3�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3 C_Float_3::operator/=(float in_divide_equal_float)
{
	x /= in_divide_equal_float;
	y /= in_divide_equal_float;
	z /= in_divide_equal_float;

	return *this;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ�%=���Z
// ����   �Ffloat ��]�Z�������t���[�g�l
// �߂�l �FC_Float_3 ��]�Z������ʂ̃t���[�g3�l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float_3 C_Float_3::operator%=(float in_surplus_equal_float)
{
	x = x - (int)(x / in_surplus_equal_float);
	y = y - (int)(y / in_surplus_equal_float);
	z = z - (int)(z / in_surplus_equal_float);

	return *this;
}
