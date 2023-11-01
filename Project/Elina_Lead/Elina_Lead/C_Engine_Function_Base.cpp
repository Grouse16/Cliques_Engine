//����������������������������������������������//
// �ڍ�   �F�C�x���g�w��p�̊��C���X�^���X�̒�`
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Engine_Function_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::FUNCTION;


// �� �֐� �� //

//==�� �v���e�N�g ��==//

//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[���O�̍X�V
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Function_Base::M_Before_Event_Update(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[����̍X�V
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Function_Base::M_After_Event_Update(void)
{
	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[���O�̍X�V�̗D��x���x����ݒ肷��
// ����   �Fint �ݒ肷��D��x
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Function_Base::M_Set_Before_Update_Priority(int in_set_priority)
{
	mpr_variable.before_update_priority = in_set_priority;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[����̍X�V�̗D��x���x����ݒ肷��
// ����   �Fint �ݒ肷��D��x
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Function_Base::M_Set_After_Update_Priority(int in_set_priority)
{
	mpr_variable.after_update_priority = in_set_priority;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[���O�̕`��̗D��x���x����ݒ肷��
// ����   �Fint �ݒ肷��D��x
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Function_Base::M_Set_Before_Draw_Priority(int in_set_priority)
{
	mpr_variable.before_draw_priority = in_set_priority;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[����̕`��̗D��x���x����ݒ肷��
// ����   �Fint �ݒ肷��D��x
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Function_Base::M_Set_After_Draw_Priority(int in_set_priority)
{
	mpr_variable.after_draw_priority = in_set_priority;

	return;
}


//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Engine_Function_Base::C_Engine_Function_Base(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Engine_Function_Base::~C_Engine_Function_Base(void)
{
	return;
}


//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[����̃C�x���g�̍X�V
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Function_Base::M_Call_Event_Before_Scene_Process(void)
{
	// �҂����Ԃ�����Ȃ�Ă΂�Ă��ҋ@
	if (mpr_variable.update_period_time > 0.0f)
	{
		return;
	}


	// �V�[�������O�̍X�V����
	M_Before_Event_Update();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[����̃C�x���g�̍X�V
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Function_Base::M_Call_Event_After_Scene_Process(void)
{
	// �҂����Ԃ�����Ȃ�Ă΂�Ă��ҋ@
	if (mpr_variable.update_period_time > 0.0f)
	{
		return;
	}


	// �V�[��������̍X�V����
	M_After_Event_Update();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[���O�ɍs���o�͏���
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Function_Base::M_Draw_Before_Scene_Process(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[����ɍs���o�͏���
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Function_Base::M_After_Draw_Process(void)
{
	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�C�x���g���s�̎�����ݒ肷��
// ����   �Ffloat �ݒ肷�鎟�̎��s�܂ł̑҂�����
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Function_Base::M_Set_Update_Period_Time(float in_set_period)
{
	mpr_variable.update_period_time = in_set_period;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�@�\���I�������邩�ǂ�����ݒ肷��
// ����   �Fbool �ݒ肷��I�����邩�ǂ����̃t���O
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Engine_Function_Base::M_Set_Flg_End_Function(bool in_set_flg_end_function)
{
	mpr_variable.flg_function_end = in_set_flg_end_function;

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[���O�̍X�V�̗D��x�̃��x����Ԃ�
// ����   �Fvoid
// �߂�l �Fconst int & �D��x�̒l�̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const int & C_Engine_Function_Base::M_Get_Before_Update_Priority(void)
{
	return mpr_variable.before_update_priority;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[����̍X�V�̗D��x�̃��x����Ԃ�
// ����   �Fvoid
// �߂�l �Fconst int & �D��x�̒l�̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const int & C_Engine_Function_Base::M_Get_After_Update_Priority(void)
{
	return mpr_variable.after_update_priority;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[���O�̕`��̗D��x�̃��x����Ԃ�
// ����   �Fvoid
// �߂�l �Fconst int & �D��x�̒l�̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const int & C_Engine_Function_Base::M_Get_Before_Draw_Priority(void)
{
	return mpr_variable.before_draw_priority;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[����̕`��̗D��x�̃��x����Ԃ�
// ����   �Fvoid
// �߂�l �Fconst int & �D��x�̒l�̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const int & C_Engine_Function_Base::M_Get_After_Draw_Priority(void)
{
	return mpr_variable.after_draw_priority;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�@�\���I�����邩�ǂ����̃t���O��Ԃ�
// ����   �Fvoid
// �߂�l �Fconst bool & �@�\���I�����邩�ǂ����̃t���O�̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const bool & C_Engine_Function_Base::M_Get_Flg_End_Function(void)
{
	return mpr_variable.flg_function_end;
}
