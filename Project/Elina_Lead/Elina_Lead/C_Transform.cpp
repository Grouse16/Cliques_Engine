//����������������������������������������������//
// �ڍ�   �F�I�u�W�F�N�g�̍��W�A��]�A�傫���̐ݒ�
// ����   �F���O���g�����X�t�H�[���Ƃ���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Transform.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace MATH;


// �� �֐� �� //

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Transform::C_Transform(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Transform::~C_Transform(void)
{
	return;
}


//-��- �ړ� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������Ă��������O���Ƃ��Ĉړ����s��
// ����   �F�ړ���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Transform::M_Move(DirectX::XMFLOAT3 in_move_value)
{
	position.M_Move_By_Direction(quaternion.M_Get_Rotation_Matrix(), in_move_value);

	return;
}


//-��- �s��ϊ� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���[���h�ϊ��s��ɕϊ����ĕԂ�
// ����   �FXMMATRIX & �ϊ��f�[�^�̐ݒ��̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Transform::M_Generate_World_Matrix(DirectX::XMMATRIX & put_set_matrix) const
{
	// �ϊ��s��𐶐����ăZ�b�g����
	put_set_matrix =

		// �X�P�[��
		scale.M_Get_Scale_Matrix()
		*

		// ��]
		quaternion.M_Get_Rotation_Matrix() 
		*

		// �ʒu���W
		position.M_Get_Position_Matrix();
	
	return;
}


