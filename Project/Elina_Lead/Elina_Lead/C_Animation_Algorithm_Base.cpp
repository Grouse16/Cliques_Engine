//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�����̌v�Z�𐧌䂷��N���X�̊��N���X
// ����   �F�ǂ�ȃA�j���[�V���������邩�𕪊�ł͂Ȃ��A��������N���X�ɂ���ĕ���ł���悤�ɂ��邽�߂̒��ۉ����C���[�@�A�j���[�V�����̌v�Z�������Ȃ��Ȃ��Ƃ��͂�������̉�����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Animation_Algorithm_Base.h"
#include "C_Game_Time_Manager.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::ANIMATION::ALGORITHM;


// �� �֐� �� //

//==�� �v���e�N�g ��==//

//-��- �_�����Z -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�l�P���l�Q���傫���Ȃ�l�P�ɒl�Q���Z�b�g����A�����łȂ��Ȃ牽�����Ȃ�
// ����   �Ffloat & �l�P, float �l�Q
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
inline void C_Animation_Algorithm_Base::M_Guard_1_Over_2(float & out_value_1, float in_value_2)
{
	out_value_1 =
		(out_value_1 > in_value_2) * in_value_2
		+ 
		(out_value_1 <= in_value_2) * out_value_1;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�����̎��Ԃ̍Đ��Ƌt�Đ������s���A�A�j���[�V�����̏I�������肷��
// ����   �FS_Animation_Status & �A�j���[�V�����̏��̎Q��, float �A�j���[�V�����J�n����I���܂ł̎���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
inline void C_Animation_Algorithm_Base::M_Animation_Time_Base_Update(ASSET::ANIMATION::S_Animation_Status & out_animation_status, float in_animation_max_time)
{
	// �A�j���[�V�������Ԃ̍Đ��A�܂��͋t�Đ�
	out_animation_status.animation_time += GAME::TIME::C_Game_Time_Manager::M_Get_Game_Second() * out_animation_status.animation_speed * (1.0f - 2.0f * out_animation_status.flg_animation_reverse);


	// �A�j���[�V�����̏I�����Ԃ��߂��Ȃ��悤�ɂ���
	out_animation_status.animation_time =

		// �ʏ�Đ���
		(
			(out_animation_status.animation_time > in_animation_max_time) * in_animation_max_time
			+
			(out_animation_status.animation_time <= in_animation_max_time) * out_animation_status.animation_time
		) * !out_animation_status.flg_animation_reverse
		+
		// �t�Đ���
		(out_animation_status.animation_time >= 0.0f) * out_animation_status.animation_time * out_animation_status.flg_animation_reverse;

	// �I�����Ԃɓ��B���Ă�����A�j���[�V�����I���̃t���O�𗧂Ă�
	out_animation_status.flg_animation_reverse = 

		// �ʏ�Đ���
		(out_animation_status.animation_time >= in_animation_max_time) * !out_animation_status.flg_animation_reverse
		+
		// �t�Đ���
		(out_animation_status.animation_time <= 0.0f) * out_animation_status.flg_animation_reverse;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�u�����h���̎��Ԃ̍Đ��Ƌt�Đ����s��
// ����   �Fconst S_Animation_Status & �A�j���[�V�����̏��(const), �u�����h���̎��Ԃ̎Q��, �A�j���[�V�����J�n����I���܂ł̎���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
inline void C_Animation_Algorithm_Base::M_Animation_Blend_Time_Update(const ASSET::ANIMATION::S_Animation_Status & in_animation_status, float & out_blend_from_time, float in_animation_max_time)
{
	// �A�j���[�V�������Ԃ̍Đ��A�܂��͋t�Đ�
	out_blend_from_time += GAME::TIME::C_Game_Time_Manager::M_Get_Game_Second() * in_animation_status.animation_speed * (1.0f - 2.0f * in_animation_status.flg_animation_reverse);


	// �A�j���[�V�����̏I�����Ԃ��߂��Ȃ��悤�ɂ���
	out_blend_from_time =

		// �ʏ�Đ���
		(
			(out_blend_from_time > in_animation_max_time) * in_animation_max_time
			+
			(out_blend_from_time <= in_animation_max_time) * out_blend_from_time
			) * !in_animation_status.flg_animation_reverse
		+
		// �t�Đ���
		(out_blend_from_time >= 0.0f) * out_blend_from_time * in_animation_status.flg_animation_reverse;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���[�v����A�j���[�V�����̎��Ԃ̍Đ��Ƌt�Đ������s��
// ����   �FS_Animation_Status & �A�j���[�V�����̏��̎Q��, float �A�j���[�V�����J�n����I���܂ł̎���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
inline void C_Animation_Algorithm_Base::M_Loop_Animation_Time_Base_Update(ASSET::ANIMATION::S_Animation_Status & out_animation_status, float in_animation_max_time)
{
	// �Q�[�����Ԃɍ��킹�Ď��Ԍo�߂���
	out_animation_status.animation_time += GAME::TIME::C_Game_Time_Manager::M_Get_Game_Second() * out_animation_status.animation_speed * (1.0f - 2.0f * out_animation_status.flg_animation_reverse);

	// �A�j���[�V�����̏I�����Ԃ��߂��Ȃ��悤�ɂ���
	out_animation_status.animation_time =

		// �ʏ�Đ����̌v�Z
		(
			(out_animation_status.animation_time > in_animation_max_time) * (out_animation_status.animation_time - in_animation_max_time)
			+ (out_animation_status.animation_time <= in_animation_max_time) * out_animation_status.animation_time
			)
		* !out_animation_status.flg_animation_reverse
		+

		// �t�Đ����̌v�Z
		(
			(out_animation_status.animation_time < 0.0f) * (in_animation_max_time + out_animation_status.animation_time)
			+ (out_animation_status.animation_time >= 0.0f) * out_animation_status.animation_time
			)
		* out_animation_status.flg_animation_reverse;

	return;
}


//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Algorithm_Base::C_Animation_Algorithm_Base(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Algorithm_Base::~C_Animation_Algorithm_Base(void)
{
	return;
}
