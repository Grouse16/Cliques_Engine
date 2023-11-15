

// �� �t�@�C���Ђ炫 �� //
#include "C_Animation_Algorithm_No_Animation.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::ANIMATION::ALGORITHM;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fconst vector<S_Bone_Inform> * �{�[���̏������̃A�h���X(const)
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Algorithm_No_Animation::C_Animation_Algorithm_No_Animation(const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & in_set_bone_inform_list) : m_bone_inform_list(in_set_bone_inform_list)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Algorithm_No_Animation::~C_Animation_Algorithm_No_Animation(void)
{
	return;
}


//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�������Ԃ̍X�V
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Algorithm_No_Animation::M_Animation_Time_Update(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�����̍X�V
// ����   �Fvector<XMFLOAT4X4> & �X�V��������{�[���̃}�g���N�X�̔z��̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Algorithm_No_Animation::M_Animation_Update(std::vector<DirectX::XMFLOAT4X4> & in_bone_matrix_list)
{
	// �����̃I�t�Z�b�g�}�g���N�X���Z�b�g����
	for (int l_bone_num = 0; l_bone_num < in_bone_matrix_list.size(); l_bone_num++)
	{
		in_bone_matrix_list[l_bone_num] = m_bone_inform_list[l_bone_num].offset_matrix;
	}

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̃A�j���[�V������Ԃ�
// ����   �Fvoid
// �߂�l �FC_Animation_Data_System * ���݂̃A�j���[�V�����̃A�h���X
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * C_Animation_Algorithm_No_Animation::M_Get_Now_Animation(void)
{
	return nullptr;
}
