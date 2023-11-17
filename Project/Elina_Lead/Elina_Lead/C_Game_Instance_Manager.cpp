//����������������������������������������������//
// �ڍ�   �F�Q�[����̃C���X�^���X�𐧌䂷��N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Game_Instance_Manager.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::INSTANCE;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��// 
C_Game_Instance_Manager::C_Game_Instance_Manager(void)
{
	return;
}


//-��- �폜 -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�Q�[����̑S�ẴC���X�^���X�̂Ȃ�����A�폜�̃t���O�������Ă�����̂�����
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��// 
void C_Game_Instance_Manager::M_All_Instance_Destroy_Update(void)
{
	// �� �ϐ��錾 �� //
	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & actor_list_system_list =	// �A�N�^�[�Ǘ��p���X�g�̃��X�g
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::ACTOR::LIST::C_Actor_List>::M_Get_List_Of_All_Instance_List();

	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & ui_list_system_list =	// UI�Ǘ��p���X�g�̃��X�g
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::UI::LIST::C_User_Interface_List>::M_Get_List_Of_All_Instance_List();

	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & sound_list_system_list =	// �T�E���h�Ǘ��p���X�g�̃��X�g
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::SOUND::LIST::C_Sound_List>::M_Get_List_Of_All_Instance_List();

	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * > & post_effect_list_system_list =	// �|�X�g�G�t�F�N�g�Ǘ��p���X�g�̃��X�g
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::POST_EFFECT::LIST::C_Post_Effect_List>::M_Get_List_Of_All_Instance_List();


	// �폜�t���O�̗����Ă���A�N�^�[�̍폜
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * actor_list : actor_list_system_list)
	{
		actor_list->M_Delete_Instance_Execute();
	}

	// �폜�t���O�̗����Ă���UI�̍폜
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * ui_list : ui_list_system_list)
	{
		ui_list->M_Delete_Instance_Execute();
	}

	// �폜�t���O�̗����Ă���T�E���h�̍폜
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * sound_list : sound_list_system_list)
	{
		sound_list->M_Delete_Instance_Execute();
	}

	// �폜�t���O�̗����Ă���|�X�g�G�t�F�N�g�̍폜
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * post_effect_list : post_effect_list_system_list)
	{
		post_effect_list->M_Delete_Instance_Execute();
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�S�ẴC���X�^���X���폜����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Instance_Manager::M_Delete_All_Instance(void)
{
	// �� �ϐ��錾 �� //
	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* > & actor_list_system_list =	// �A�N�^�[�Ǘ��p���X�g�̃��X�g
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::ACTOR::LIST::C_Actor_List>::M_Get_List_Of_All_Instance_List();

	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* > & ui_list_system_list =	// UI�Ǘ��p���X�g�̃��X�g
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::UI::LIST::C_User_Interface_List>::M_Get_List_Of_All_Instance_List();

	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* > & sound_list_system_list =	// �T�E���h�Ǘ��p���X�g�̃��X�g
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::SOUND::LIST::C_Sound_List>::M_Get_List_Of_All_Instance_List();

	std::vector<SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* > & post_effect_list_system_list =	// �|�X�g�G�t�F�N�g�Ǘ��p���X�g�̃��X�g
		SYSTEM::LIST::BASE::C_List_Divided_By_Class_Overall_Base<GAME::INSTANCE::POST_EFFECT::LIST::C_Post_Effect_List>::M_Get_List_Of_All_Instance_List();


	// �A�N�^�[�̍폜
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* actor_list : actor_list_system_list)
	{
		actor_list->M_Delete_Instance_Execute();
	}

	// UI�̍폜
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* ui_list : ui_list_system_list)
	{
		ui_list->M_Delete_Instance_Execute();
	}

	// �T�E���h�̍폜
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* sound_list : sound_list_system_list)
	{
		sound_list->M_Delete_Instance_Execute();
	}

	// �|�X�g�G�t�F�N�g�̍폜
	for (SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base* post_effect_list : post_effect_list_system_list)
	{
		post_effect_list->M_Delete_Instance_Execute();
	}

	return;
}



