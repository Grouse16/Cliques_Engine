//����������������������������������������������//
// �ڍ�   �F�Q�[���̋@�\�𐧌䂷��N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include <algorithm>

#include "C_Game_Function_Manager.h"
#include "Game_Function_Include_List.h"


// �� �f�o�b�O���Ȃ珉�����̐�������ю��s�����m �� //
#if _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG



// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::FUNCTION;


// �� �ϐ��錾 �� //

// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
C_Game_Function_Manager::SPR_Variable C_Game_Function_Manager::mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O

C_Game_Function_Manager C_Game_Function_Manager::m_this;	// ���g���Ăяo�����߂̖��O


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Game_Function_Manager::C_Game_Function_Manager(void)
{
	return;
}


//-��- �@�\ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�@�\�̐������s��
// ����   �Fstring ��������@�\�̎��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Function_Manager::M_Create_Function_By_Kind(std::string in_create_kind)
{
	// �� �ϐ��錾 �� //
	GAME::FUNCTION::C_Game_Function_Base * new_function_address = nullptr;	// �V�����@�\�̃A�h���X
	

	// �� �w�肳�ꂽ��ނɂ���Đ������e�𕪊� �� //

	// �܂��Ȃ�
	if (in_create_kind == "non")
	{

	}

	// ���O���݂���Ȃ�������G���[
	else
	{
		// �� �f�o�b�O���Ȃ琶���ł��Ȃ��������Ƃ����m �� //
#if _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_CREATE_FUNCTION, "�@�\�̐����Ɏ��s�@�w�肳�ꂽ�^�C�v�F��" + in_create_kind + "���@�͌�����܂���ł����B����`�̋@�\�A����уX�y���~�X�̉\��������܂��B");
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return;
	}


	// �������̃��X�g�ɐV�����������ꂽ�@�\��ǉ�
	M_Set_Before_Update_Func_To_List(new_function_address);
	M_Set_After_Update_Func_To_List(new_function_address);
	M_Set_After_Draw_Func_To_List(new_function_address);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[�������O�ɍX�V����@�\��ǉ�
// ����   �FC_Game_Function_Base * �ǉ�����@�\�̃A�h���X
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Function_Manager::M_Set_Before_Update_Func_To_List(GAME::FUNCTION::C_Game_Function_Base * in_add_function)
{
	// �V�[���O�̍X�V���s��Ȃ��Ȃ�ǉ����Ȃ�
	if (in_add_function->M_Get_Before_Update_Priority() < 0)
	{
		return;
	}


	// �z��ɐ������ꂽ���߂̋@�\��ǉ�
	mpr_variable.before_func_update_list.reserve(mpr_variable.before_func_update_list.size() + 1);
	mpr_variable.before_func_update_list.emplace_back(in_add_function);


	// �D��x�����ɍ~���Ƀ\�[�g����
	std::sort
	(
		mpr_variable.before_func_update_list.begin(),	// �\�[�g�̊J�n
		mpr_variable.before_func_update_list.end(),		// �\�[�g�̂����

		// �����_���A�E�̗v�f�����̗v�f�����l���傫����΁A���Ԃ����ւ���
		[](GAME::FUNCTION::C_Game_Function_Base * & l_vec, GAME::FUNCTION::C_Game_Function_Base * & r_vec)
		{
			return l_vec->M_Get_Before_Update_Priority() >= r_vec->M_Get_Before_Update_Priority();
		}
	);

	return;
}

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[��������ɍX�V����@�\��ǉ�
// ����   �FC_Game_Function_Base * �ǉ�����@�\�̃A�h���X
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Function_Manager::M_Set_After_Update_Func_To_List(GAME::FUNCTION::C_Game_Function_Base * in_add_function)
{
	// �V�[����̍X�V���s��Ȃ��Ȃ�ǉ����Ȃ�
	if (in_add_function->M_Get_After_Update_Priority() < 0)
	{
		return;
	}


	// �z��ɐ������ꂽ���߂̋@�\��ǉ�
	mpr_variable.after_func_update_list.reserve(mpr_variable.after_func_update_list.size() + 1);
	mpr_variable.after_func_update_list.emplace_back(in_add_function);


	// �D��x�����ɍ~���Ƀ\�[�g����
	std::sort
	(
		mpr_variable.after_func_update_list.begin(),	// �\�[�g�̊J�n
		mpr_variable.after_func_update_list.end(),		// �\�[�g�̂����

		// �����_���A�E�̗v�f�����̗v�f�����l���傫����΁A���Ԃ����ւ���
		[](GAME::FUNCTION::C_Game_Function_Base * & left_function, GAME::FUNCTION::C_Game_Function_Base * & right_function)
		{
			return left_function->M_Get_Before_Update_Priority() >= right_function->M_Get_Before_Update_Priority();
		}
	);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[����ɕ`�悷��@�\��ǉ�����
// ����   �FC_Game_Function_Base * �ǉ�����@�\�̃A�h���X
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Function_Manager::M_Set_After_Draw_Func_To_List(GAME::FUNCTION::C_Game_Function_Base * in_add_function)
{
	// �V�[����̍X�V���s��Ȃ��Ȃ�ǉ����Ȃ�
	if (in_add_function->M_Get_After_Draw_Priority() < 0)
	{
		return;
	}


	// �z��ɐ������ꂽ���߂̋@�\��ǉ�
	mpr_variable.after_func_draw_list.reserve(mpr_variable.after_func_draw_list.size() + 1);
	mpr_variable.after_func_draw_list.emplace_back(in_add_function);


	// �D��x�����ɏ����Ƀ\�[�g����
	std::sort
	(
		mpr_variable.after_func_draw_list.begin(),	// �\�[�g�̊J�n
		mpr_variable.after_func_draw_list.end(),	// �\�[�g�̂����

		// �����_���A���̗v�f���E�̗v�f�����l���傫����΁A���Ԃ����ւ���
		[](GAME::FUNCTION::C_Game_Function_Base * & left_function, GAME::FUNCTION::C_Game_Function_Base * & right_function)
		{
			return left_function->M_Get_After_Draw_Priority() <= right_function->M_Get_After_Draw_Priority();
		}
	);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�A�h���X�̋@�\�����ׂĂ̓o�^����폜����
// ����   �FC_Game_Function_Base * �폜����@�\�̃A�h���X
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Function_Manager::M_Erase_This_Function_On_All_List(GAME::FUNCTION::C_Game_Function_Base * in_delete_function)
{
	// �� �����_�� �� //

	// �x�N�^�[����@�\�폜�p�̔�����s�������_��
	auto delete_lambda = [] (GAME::FUNCTION::C_Game_Function_Base * & in_function)
	{
		return in_function->M_Get_Flg_End_Function();
	};


	// �@�\�����ꂼ��̃��X�g����폜����
	mpr_variable.before_func_update_list.erase(std::remove_if(mpr_variable.function_list.begin(), mpr_variable.function_list.end(), delete_lambda), mpr_variable.function_list.end());
	mpr_variable.before_func_update_list.shrink_to_fit();
	mpr_variable.after_func_update_list.erase(std::remove_if(mpr_variable.function_list.begin(), mpr_variable.function_list.end(), delete_lambda), mpr_variable.function_list.end());
	mpr_variable.after_func_draw_list.shrink_to_fit();
	mpr_variable.before_func_draw_list.erase(std::remove_if(mpr_variable.function_list.begin(), mpr_variable.function_list.end(), delete_lambda), mpr_variable.function_list.end());
	mpr_variable.before_func_draw_list.shrink_to_fit();
	mpr_variable.after_func_draw_list.erase(std::remove_if(mpr_variable.function_list.begin(), mpr_variable.function_list.end(), delete_lambda), mpr_variable.function_list.end());
	mpr_variable.after_func_draw_list.shrink_to_fit();

	return;
}


//==�� �p�u���b�N ��==//

//-��- �I���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Game_Function_Manager::~C_Game_Function_Manager(void)
{
	M_Release_Memory();

	return;
}

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Function_Manager::M_Release_Memory(void)
{
	// �@�\�̏����w��p�̃��X�g�̃��������������
	mpr_variable.before_func_update_list.clear();
	mpr_variable.before_func_update_list.shrink_to_fit();
	mpr_variable.after_func_update_list.clear();
	mpr_variable.after_func_update_list.shrink_to_fit();
	mpr_variable.before_func_draw_list.clear();
	mpr_variable.before_func_draw_list.shrink_to_fit();
	mpr_variable.after_func_draw_list.clear();
	mpr_variable.after_func_draw_list.shrink_to_fit();


	// �@�\�̃��X�g�̃��������������
	for (GAME::FUNCTION::C_Game_Function_Base * & now_func : mpr_variable.function_list)
	{
		if (now_func != nullptr)
		{
			delete[] now_func;
			now_func = nullptr;
		}
	}


	mpr_variable.function_list.clear();
	mpr_variable.function_list.shrink_to_fit();


	// �@�\�������߂�����������
	mpr_variable.function_create_kind_list.clear();
	mpr_variable.function_create_kind_list.shrink_to_fit();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[�������O�̋@�\�̍X�V���s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Function_Manager::M_Before_Scene_Update(void)
{
	for (GAME::FUNCTION::C_Game_Function_Base * & now_function : mpr_variable.before_func_update_list)
	{
		now_function->M_Call_Event_Before_Scene_Process();
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[��������̋@�\�̍X�V���s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Function_Manager::M_After_Scene_Update(void)
{
	for (GAME::FUNCTION::C_Game_Function_Base * & now_function : mpr_variable.after_func_update_list)
	{
		now_function->M_Call_Event_After_Scene_Process();
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[��������̋@�\�̕`����s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Function_Manager::M_After_Scene_Draw_Update(void)
{
	for (GAME::FUNCTION::C_Game_Function_Base * & now_function : mpr_variable.after_func_draw_list)
	{
		now_function->M_After_Draw_Process();
	}

	return;
}


//-��- �@�\ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�폜�̃t���O���������@�\������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Function_Manager::M_Delete_Function(void)
{
	// �폜�̃t���O�������Ă���v�f������
	for (GAME::FUNCTION::C_Game_Function_Base * & now_function : mpr_variable.function_list)
	{
		if (now_function != nullptr)
		{
			if (now_function->M_Get_Flg_End_Function() == true)
			{
				M_Erase_This_Function_On_All_List(now_function);

				delete[] now_function;
				now_function = nullptr;
			}
		}
	}

	// ������ꂽ�z����폜
	mpr_variable.function_list.erase(std::remove(mpr_variable.function_list.begin(), mpr_variable.function_list.end(), nullptr), mpr_variable.function_list.end());
	mpr_variable.function_list.shrink_to_fit();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F��������v���̂������@�\��S�Đ�������
// ����   �Fvoid
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Game_Function_Manager::M_Execute_Create_Function_By_List(void)
{
	// ��������@�\���Ȃ���Ή������Ȃ�
	if (mpr_variable.function_create_kind_list.size() <= 0)
	{
		return true;
	}


	// �����v���̂������@�\��S�Đ���
	for (std::string & create_kind : mpr_variable.function_create_kind_list)
	{
		M_Create_Function_By_Kind(create_kind);
	}


	// �������������v�����폜
	mpr_variable.function_create_kind_list.clear();
	mpr_variable.function_create_kind_list.shrink_to_fit();

	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�@�\�̐�����v������
// ����   �Fstring ��������@�\�̎��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Function_Manager::M_Command_Create_Function(std::string in_creat_kind)
{
	mpr_variable.function_create_kind_list.reserve(mpr_variable.function_create_kind_list.size() + 1);
	mpr_variable.function_create_kind_list.emplace_back(in_creat_kind);

	return;
}

