

// �� �t�@�C���Ђ炫 �� //
#include "C_Float4.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace MATH;


// �� �N���X �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float4::C_Float4(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Fxyzw�̃p�����[�^�����ɃZ�b�g����R���X�g���N�^
// ����   �Ffloat x�ɃZ�b�g����l, float y�ɃZ�b�g����l, float z�ɃZ�b�g����l, float w�ɃZ�b�g����l
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float4::C_Float4(float in_x, float in_y, float in_z, float in_w)
{
	x = in_x;
	y = in_y;
	z = in_z;
	w = in_w;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Fxyz�̃p�����[�^�����ɃZ�b�g����R���X�g���N�^
// ����   �Ffloat x�ɃZ�b�g����l, float y�ɃZ�b�g����l, float z�ɃZ�b�g����l
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float4::C_Float4(float in_x, float in_y, float in_z)
{
	x = in_x;
	y = in_y;
	z = in_z;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Fxy�̃p�����[�^�����ɃZ�b�g����R���X�g���N�^
// ����   �Ffloat x�ɃZ�b�g����l, float y�ɃZ�b�g����l
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float4::C_Float4(float in_x, float in_y)
{
	x = in_x;
	y = in_y;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Fx�̃p�����[�^�����ɃZ�b�g����R���X�g���N�^
// ����   �Ffloat x�ɃZ�b�g����l
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float4::C_Float4(float in_x)
{
	x = in_x;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float4::~C_Float4(void)
{
	return;
}


//==�� �I�y���[�^ ��==//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FFloat4�Ƃ̃C�R�[�����Z
// ����   �FC_Float4 & �������t���[�g4�l
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Float4::operator=(C_Float4 & in_float4)
{
	x = in_float4.x;
	y = in_float4.y;
	z = in_float4.z;
	w = in_float4.w;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FFloat4�Ƃ̃C�R�[�����Z
// ����   �FC_Float4 �������t���[�g4�l
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Float4::operator=(C_Float4 in_float4)
{
	x = in_float4.x;
	y = in_float4.y;
	z = in_float4.z;
	w = in_float4.w;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FFloat4�Ƃ́{���Z
// ����   �FC_Float4 & ���Z����t���[�g4�l
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float4 C_Float4::operator+(C_Float4 & in_float4)
{
	return C_Float4(x + in_float4.x, y + in_float4.y, z + in_float4.z, w + in_float4.w);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FFloat4�Ƃ́{���Z
// ����   �FC_Float4 ���Z����t���[�g4�l
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float4 C_Float4::operator+(C_Float4 in_float4)
{
	return C_Float4(x + in_float4.x, y + in_float4.y, z + in_float4.z, w + in_float4.w);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �Ffloat�Ƃ́{���Z
// ����   �Ffloat & ���Z����t���[�g�l
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Float4 C_Float4::operator+(float & in_float)
{
	return C_Float4(x + in_float, y + in_float, z + in_float, w + in_float);
}

