//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�����̌v�Z�𐧌䂷��N���X
// ����   �F�{�[���}�g���N�X�ɑ΂���A�j���[�V�����̑�����s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Animation_Calculation_System.h"
#include "C_Animation_Algorithm_No_Animation.h"
#include "C_Animation_Algorithm_Play.h"
#include "C_Animation_Algorithm_Loop_Play.h"
#include "C_Animation_Algorithm_Blend_Play.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::ANIMATION::CALCULATOR;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fconst vector<S_Bone_Inform> & �{�[�����̃��X�g�̎Q��
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Calculation_System::C_Animation_Calculation_System(const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & in_bone_list) : mpr_variable((int)in_bone_list.size())
{
	// ������Ԃ̃{�[����ݒ肷��A���S���Y���𐶐�
	mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_No_Animation(in_bone_list));

	// ������Ԃ͍ŏ�����A�j���[�V�����I�����
	mpr_variable.animation_status.flg_animation_end = true;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Calculation_System::~C_Animation_Calculation_System(void)
{
	mpr_variable.animation_algorithm.reset();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�����̃X�e�[�^�X�̏�����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Calculation_System::M_Animation_Status_Reset(void)
{
	mpr_variable.animation_status.animation_time = 0.0f;
	mpr_variable.animation_status.animation_blend_percent = 0.0f;
	mpr_variable.animation_status.animation_speed = 1.0f;
	mpr_variable.animation_status.flg_animation_end = false;

	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̃A�j���[�V�������Ԃ��Z�b�g����
// ����   �Ffloat �Z�b�g����A�j���[�V��������
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Calculation_System::M_Set_Animation_Time(float in_set_animation_time)
{
	mpr_variable.animation_status.animation_time = in_set_animation_time;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̃A�j���[�V�������Ԃ��Z�b�g����
// ����   �Ffloat �Z�b�g����A�j���[�V�����̃X�s�[�h
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Calculation_System::M_Set_Animation_Speed(float in_set_speed)
{
	mpr_variable.animation_status.animation_speed = in_set_speed;

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�������I�����Ă��邩�ǂ�����Ԃ�
// ����   �Fvoid
// �߂�l �Fbool �A�j���[�V�����I���̃t���O
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Animation_Calculation_System::M_Get_Animation_Is_End(void)
{
	return mpr_variable.animation_status.flg_animation_end;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̃A�j���[�V�������Ԃ�Ԃ�
// ����   �Fvoid
// �߂�l �Ffloat ���݂̃A�j���[�V��������
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
float C_Animation_Calculation_System::M_Get_Animation_Time(void)
{
	return mpr_variable.animation_status.animation_time;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̃A�j���[�V�����̃X�s�[�h��Ԃ�
// ����   �Fvoid
// �߂�l �Ffloat ���݂̃A�j���[�V�����̃X�s�[�h
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
float C_Animation_Calculation_System::M_Get_Animation_Speed(void)
{
	return mpr_variable.animation_status.animation_speed;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̃A�j���[�V�����̃u�����h����Ԃ�
// ����   �Fvoid
// �߂�l �Ffloat ���݂̃A�j���[�V�����̃u�����h��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
float C_Animation_Calculation_System::M_Get_Animation_Blend_Percent(void)
{
	return mpr_variable.animation_status.animation_blend_percent;
}


//-��- �A�j���[�V���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�n���ꂽ�A�j���[�V�������Đ�����
// ����   �FC_Animation_Data_System * �Đ�����A�j���[�V�����f�[�^�̃A�h���X
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Calculation_System::M_Play_Animation(ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * in_play_animation)
{
	mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Play(mpr_variable.animation_status, in_play_animation));

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�n���ꂽ�A�j���[�V���������[�v�Đ�����
// ����   �FC_Animation_Data_System * ���[�v�Đ�����A�j���[�V�����f�[�^�̃A�h���X
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Calculation_System::M_Loop_Play_Animation(ASSET::ANIMATION_SYSTEM::C_Animation_Data_System* in_loop_play_animation)
{
	mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Loop_Play(mpr_variable.animation_status, in_loop_play_animation));

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�n���ꂽ�A�j���[�V�������u�����h���čĐ�����
// ����   �FC_Animation_Data_System * �Đ�����A�j���[�V�����f�[�^�̃A�h���X�i�u�����h��j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Calculation_System::M_Blend_Play_Animation(ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * in_blend_play_animation)
{
	// �� �ϐ��錾 �� //
	ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * now_animation_data = mpr_variable.animation_algorithm->M_Get_Now_Animation();	// ���݂̃A�j���[�V�����̃f�[�^�i�u�����h���j


	// �u�����h���̃A�j���[�V����������Ȃ�A�u�����h�A�j���[�V�������J�n
	if (now_animation_data)
	{
		mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Blend_Play(mpr_variable.animation_status, now_animation_data, in_blend_play_animation));
	}

	// �u�����h���̃A�j���[�V�������Ȃ��Ȃ�ʏ�̃A�j���[�V�������s��
	else
	{
		mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Play(mpr_variable.animation_status, in_blend_play_animation));
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�z��ɃA�j���[�V�������ʂ̃{�[���}�g���N�X�z��̃f�[�^���Z�b�g����
// ����   �Fvector<XMFLOAT4X4> & �ݒ��̃{�[���}�g���N�X�z��̃f�[�^�̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Calculation_System::M_Create_Animationed_Bone_Matrix(std::vector<DirectX::XMFLOAT4X4> & out_bone_matrix_list)
{
	// �{�[���f�[�^�p�̔z����m�ۂ���
	out_bone_matrix_list.clear();
	out_bone_matrix_list.shrink_to_fit();
	out_bone_matrix_list.resize(mpr_variable.animation_status.bone_sum);

	mpr_variable.animation_algorithm->M_Animation_Time_Update();
	mpr_variable.animation_algorithm->M_Animation_Update(out_bone_matrix_list);

	return;
}
