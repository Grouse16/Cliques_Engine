//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�������u�����h�Đ�����N���X
// ����   �F�u�����h���I�������ۂ̃V���O���g���A�j���[�V�����Ɠ���ւ��邽�߂̏��̓A�j���[�V�����X�e�[�^�X���ɃZ�b�g�����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Animation_Algorithm_Blend_Play.h"
#include "C_Bone_Data.h"
#include "C_Game_Time_Manager.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::ANIMATION::ALGORITHM;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �FS_Animation_Status & �A�j���[�V�����X�e�[�^�X�̎Q��, const C_Animation_Data_System * �u�����h���̃A�j���[�V����(const), const C_Animation_Data_System * �u�����h��̃A�j���[�V����(const)
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Algorithm_Blend_Play::C_Animation_Algorithm_Blend_Play(ASSET::ANIMATION::S_Animation_Status & in_set_animation_status, const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * in_animation_from, const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * in_animation_to) : m_animation_status(in_set_animation_status)
{
	// �A�j���[�V�������̃X�e�[�^�X�̐ݒ�
	animation_from_time = m_animation_status.animation_time;
	m_from_animation = in_animation_from;
	m_animation_status.flg_animation_end = false;

	// �A�j���[�V������̃X�e�[�^�X�̐ݒ�
	m_to_animation = in_animation_to;
	m_animation_status.animation_time = 0.0f;
	m_animation_status.animation_blend_percent = 0.0f;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Algorithm_Blend_Play::~C_Animation_Algorithm_Blend_Play(void)
{
	return;
}


//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�������Ԃ̍X�V
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Algorithm_Blend_Play::M_Animation_Time_Update(void)
{
	// �A�j���[�V�����̎��Ԃ̍X�V���s��
	M_Animation_Time_Base_Update(m_animation_status, m_to_animation->M_Get_Animation_Time());


	// �A�j���[�V�����u�����h����100%�����Ȃ�A�u�����h���̃A�j���[�V�����̎��Ԃ̌v�Z���s���A���Ԍo�߂ɍ��킹�ău�����h����������
	if (m_animation_status.animation_blend_percent <= 1.0f)
	{
		// �� �ϐ��錾 �� //
		float blend_up_value = (GAME::TIME::C_Game_Time_Manager::M_Get_Game_Second() * m_animation_status.animation_speed) / m_animation_status.need_blend_time;	// �u�����h���̏㏸��


		// �u�����h���̃A�j���[�V�������Ԃ̍X�V���s��
		M_Animation_Blend_Time_Update(m_animation_status, animation_from_time, m_from_animation->M_Get_Animation_Time());

		// �o�ߎ��ԂŃu�����h�������Z
		m_animation_status.animation_blend_percent =
			(m_animation_status.animation_blend_percent >= 1.0f)
			+
			(m_animation_status.animation_blend_percent < 1.0f) * (m_animation_status.animation_blend_percent + blend_up_value);
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�����̍X�V
// ����   �Fvector<XMFLOAT4X4> & �X�V��������{�[���̃}�g���N�X�̔z��̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Algorithm_Blend_Play::M_Animation_Update(std::vector<DirectX::XMFLOAT4X4> & out_set_matrix)
{
	// �� �ϐ��錾 �� //
	std::vector<ASSET::ANIMATION::BONE::C_Bone_Data> bone_data_list;	// �{�[���̃f�[�^�̃��X�g


	// �u�����h���ăA�j���[�V�������Đ�����
	m_from_animation->M_Set_Bone_Key(animation_from_time, bone_data_list);
	m_to_animation->M_Blend_Bone_Key(m_animation_status.animation_time, m_animation_status.animation_blend_percent, bone_data_list);


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
// �߂�l �Fconst C_Animation_Data_System * ���݂̃A�j���[�V�����̃A�h���X(const)
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * C_Animation_Algorithm_Blend_Play::M_Get_Now_Animation(void)
{
	return m_to_animation;
}
