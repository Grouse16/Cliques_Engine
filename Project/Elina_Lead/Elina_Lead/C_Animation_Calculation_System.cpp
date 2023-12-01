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
#include "C_Animation_Algorithm_Blend_And_Loop.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::ANIMATION::CALCULATOR;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- �u�����h���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�u�����h�I�����m�F���A�Ή������A�j���[�V���������ɓ���ւ���
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Calculation_System::M_Check_Blend_End_And_Animation_Setting(void)
{
	// �u�����h���������Ă���Ȃ番����u�����h��ɑJ�ڂ��镪������s
	if (mpr_variable.animation_status.need_blend_time >= 1.0f)
	{
		// �� �u�����h��̋����ŏ����𕪊� �� //
		switch (mpr_variable.blend_after)
		{
			//--�� �ʏ�̍Đ��ɑJ�ڂ��� ��--//
		case E_ANIMATION_BLENDED_AFTER::e_PLAY_ANIMATION:
			M_Play_Animation(mpr_variable.animation_algorithm->M_Get_Now_Animation());
			break;

			//--�� ���[�v�Đ��ɑJ�ڂ��� ��--//
		case E_ANIMATION_BLENDED_AFTER::e_LOOP_ANIMATION:
			M_Loop_Play_Animation(mpr_variable.animation_algorithm->M_Get_Now_Animation());
			break;

			//--�� �u�����h���Ă��Ȃ��Ƃ� ��--//
		case E_ANIMATION_BLENDED_AFTER::e_NOT_BLENDING_NOW:
		default:
			break;
		}
	}

	return;
}


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


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�u�����h�ɂ����鎞�Ԃ��Z�b�g����
// ����   �Ffloat �Z�b�g����u�����h�ɂ����鎞��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Calculation_System::M_Set_Need_Blend_Time(float in_set_need_blend_time)
{
	mpr_variable.animation_status.need_blend_time = in_set_need_blend_time;

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


//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�������Ԃ̌o�߂��s��
// ����   �Ffloat �o�߂����鎞��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Calculation_System::M_Update_Time(float in_pass_time)
{
	mpr_variable.animation_status.passed_time = 
		in_pass_time 
		* mpr_variable.animation_status.animation_speed
		* (1.0f - 2.0f * mpr_variable.animation_status.flg_animation_reverse);

	return;
}


//-��- �A�j���[�V���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�n���ꂽ�A�j���[�V�������Đ�����
// ����   �Fconst C_Animation_Data_System * �Đ�����A�j���[�V�����f�[�^�̃A�h���X(const)
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Calculation_System::M_Play_Animation(const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * in_play_animation)
{
	mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Play(mpr_variable.animation_status, in_play_animation));
	mpr_variable.blend_after = E_ANIMATION_BLENDED_AFTER::e_NOT_BLENDING_NOW;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�n���ꂽ�A�j���[�V���������[�v�Đ�����
// ����   �Fconst C_Animation_Data_System * ���[�v�Đ�����A�j���[�V�����f�[�^�̃A�h���X(const)
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Calculation_System::M_Loop_Play_Animation(const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * in_loop_play_animation)
{
	mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Loop_Play(mpr_variable.animation_status, in_loop_play_animation));
	mpr_variable.blend_after = E_ANIMATION_BLENDED_AFTER::e_NOT_BLENDING_NOW;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�n���ꂽ�A�j���[�V�������u�����h���čĐ�����
// ����   �Fconst C_Animation_Data_System * �Đ�����A�j���[�V�����f�[�^�̃A�h���X�i�u�����h��j(const)
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Calculation_System::M_Blend_Play_Animation(const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * in_blend_play_animation)
{
	// �� �ϐ��錾 �� //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * now_animation_data = mpr_variable.animation_algorithm->M_Get_Now_Animation();	// ���݂̃A�j���[�V�����̃f�[�^�i�u�����h���j


	// �u�����h���̃A�j���[�V����������Ȃ�A�u�����h�A�j���[�V�������J�n
	if (now_animation_data)
	{
		mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Blend_Play(mpr_variable.animation_status, now_animation_data, in_blend_play_animation));
		mpr_variable.blend_after = E_ANIMATION_BLENDED_AFTER::e_PLAY_ANIMATION;
	}

	// �u�����h���̃A�j���[�V�������Ȃ��Ȃ�ʏ�̃A�j���[�V�������s��
	else
	{
		mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Play(mpr_variable.animation_status, in_blend_play_animation));
		mpr_variable.blend_after = E_ANIMATION_BLENDED_AFTER::e_NOT_BLENDING_NOW;
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�n���ꂽ�A�j���[�V�������u�����h��A���[�v�Đ�����
// ����   �Fconst C_Animation_Data_System * �Đ�����A�j���[�V�����f�[�^�̃A�h���X�i�u�����h��j(const)
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Calculation_System::M_Blend_Loop_Play_Animation(const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * in_blend_loop_animation)
{
	// �� �ϐ��錾 �� //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * now_animation_data = mpr_variable.animation_algorithm->M_Get_Now_Animation();	// ���݂̃A�j���[�V�����̃f�[�^�i�u�����h���j


	// �u�����h���̃A�j���[�V����������Ȃ�A�u�����h�A�j���[�V�������J�n
	if (now_animation_data)
	{
		mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Blend_And_Loop(mpr_variable.animation_status, now_animation_data, in_blend_loop_animation));
		mpr_variable.blend_after = E_ANIMATION_BLENDED_AFTER::e_LOOP_ANIMATION;
	}

	// �u�����h���̃A�j���[�V�������Ȃ��Ȃ烋�[�v�A�j���[�V�������s��
	else
	{
		mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Loop_Play(mpr_variable.animation_status, in_blend_loop_animation));
		mpr_variable.blend_after = E_ANIMATION_BLENDED_AFTER::e_NOT_BLENDING_NOW;
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�z��ɃA�j���[�V�������ʂ̃{�[���}�g���N�X�z��̃f�[�^���Z�b�g����
// ����   �Fvector<XMFLOAT4X4> & �ݒ��̃{�[���}�g���N�X�z��̃f�[�^�̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Calculation_System::M_Create_Animation_Bone_Matrix(std::vector<DirectX::XMFLOAT4X4> & out_bone_matrix_list)
{
	// �{�[���f�[�^�p�̔z����m�ۂ���
	out_bone_matrix_list.clear();
	out_bone_matrix_list.shrink_to_fit();
	out_bone_matrix_list.resize(mpr_variable.animation_status.bone_sum);

	mpr_variable.animation_algorithm->M_Animation_Time_Update();
	mpr_variable.animation_algorithm->M_Animation_Update(out_bone_matrix_list);

	// �A�j���[�V�����u�����h���ł���΁A�u�����h���������^�C�~���O�Œʏ�̃A�j���[�V�����ɖ߂�i�u�����h�̏��������𔲂����o�[�W�����ɓ���ւ���j
	M_Check_Blend_End_And_Animation_Setting();

	return;
}
