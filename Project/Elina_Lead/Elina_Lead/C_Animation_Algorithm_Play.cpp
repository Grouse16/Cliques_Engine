//����������������������������������������������//
// �ڍ�   �F�ʏ�ɃA�j���[�V�������Đ�����N���X
// ����   �F��̃A�j���[�V�����������Ă���̍Đ��̂ݍs��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Animation_Algorithm_Play.h"
#include "C_Bone_Data.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::ANIMATION::ALGORITHM;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �FS_Animation_Status & �A�j���[�V�����X�e�[�^�X�̎Q��, C_Animation_Data_System * �A�j���[�V��������f�[�^�̃Z�b�g
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Algorithm_Play::C_Animation_Algorithm_Play(ASSET::ANIMATION::S_Animation_Status & in_set_animation_status, ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * in_set_animation_data) : m_animation_status(in_set_animation_status)
{
	m_now_animation = in_set_animation_data;
	m_animation_status.animation_blend_percent = 0.0f;


	// ���݂̃A�j���[�V�������Ԃ��V�����A�j���[�V�����̏I�����Ԃ𒴂���Ȃ璴���Ȃ��悤�ɒ���
	M_Guard_1_Over_2(m_animation_status.animation_time, in_set_animation_data->M_Get_Animation_Time());

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Algorithm_Play::~C_Animation_Algorithm_Play(void)
{
	return;
}


//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�������Ԃ̍X�V
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Algorithm_Play::M_Animation_Time_Update(void)
{
	// �A�j���[�V�����̎��Ԃ̍X�V���s��
	M_Animation_Time_Base_Update(m_animation_status, m_now_animation->M_Get_Animation_Time());

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�����̍X�V
// ����   �Fvector<XMFLOAT4X4> & �X�V��������{�[���̃}�g���N�X�̔z��̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Algorithm_Play::M_Animation_Update(std::vector<DirectX::XMFLOAT4X4> & out_set_matrix)
{
	// �� �ϐ��錾 �� //
	std::vector<ASSET::ANIMATION::BONE::C_Bone_Data> bone_data_list;	// �{�[���̃f�[�^�̃��X�g


	// �{�[���f�[�^�ɃA�j���[�V�����ɂ��{�[���f�[�^���󂯎��
	bone_data_list.resize(m_animation_status.bone_sum);
	m_now_animation->M_Set_Bone_Key(m_animation_status.animation_time, bone_data_list);


	// �{�[���f�[�^���}�g���N�X�ɕϊ����ăZ�b�g����
	for (int l_now_bone_num = 0; l_now_bone_num < m_animation_status.bone_sum; l_now_bone_num++)
	{
		bone_data_list[l_now_bone_num].M_Set_Bone_Matrix_Data(out_set_matrix[l_now_bone_num]);
	}

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̃A�j���[�V������Ԃ�
// ����   �Fvoid
// �߂�l �FC_Animation_Data_System * ���݂̃A�j���[�V�����̃A�h���X
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * C_Animation_Algorithm_Play::M_Get_Now_Animation(void)
{
	return m_now_animation;
}

