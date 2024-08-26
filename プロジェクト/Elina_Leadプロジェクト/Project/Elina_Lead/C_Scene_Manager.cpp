//����������������������������������������������//
// �ڍ�   �F�V�[���𐧌䂷�邽�߂̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Scene_Manager.h"
#include "C_Scene_Title.h"
#include "C_Scene_Game.h"
#include "C_Game_State_Manager.h"
#include "C_Game_Instance_Manager.h"

#include "C_Log_System.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::SCENE::MANAGER;


// �� �X�^�e�B�b�N�ϐ� �� //
C_Scene_Manager C_Scene_Manager::m_this;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- �I���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Scene_Manager::C_Scene_Manager(void)
{
	return;
}


//-��- �V�[���J�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[���J�ڎ��ɕK�v�ȃV�X�e��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Scene_Manager::M_Scene_Change_Option(void)
{
	if (m_this.mpr_variable.game_scene)
	{
		m_this.mpr_variable.game_scene->M_Release();
		GAME::INSTANCE::C_Game_Instance_Manager::M_Instance_Destroy_On_Scene_Change();
	}

	return;
}


//==�� �p�u���b�N ��==//

//-��- �I���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Scene_Manager::~C_Scene_Manager(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������̉�����s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Scene_Manager::M_Release(void)
{
	if (m_this.mpr_variable.game_scene)
	{
		m_this.mpr_variable.game_scene->M_Release();
		m_this.mpr_variable.game_scene.reset();
	}

	return;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���O����V�[�������[�h����
// ����   �Fstring ���[�h����V�[����
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Scene_Manager::M_Scene_Load(std::string in_load_scene)
{
	// �^�C�g���V�[��
	if (in_load_scene == "TITLE")
	{
		M_Scene_Change_Option();
		GAME::STATE::C_Game_State_Manager::M_Set_Now_Game_Scene_Name(L"TITLE");
		m_this.mpr_variable.game_scene.reset(new C_Scene_Title());

		return true;
	}

	// �Q�[���V�[��
	if (in_load_scene == "GAME")
	{
		M_Scene_Change_Option();
		GAME::STATE::C_Game_State_Manager::M_Set_Now_Game_Scene_Name(L"GAME");
		m_this.mpr_variable.game_scene.reset(new C_Scene_Game());

		return true;
	}

	
	// �V�[�����Ȃ��Ȃ炻�̂��Ƃ�Ԃ�
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "���̃V�[���͂���܂���F" + in_load_scene);
	DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();

	// �V�[����������Ȃ�����
	return false;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̃V�[���̃A�h���X��Ԃ�
// ����   �Fvoid
// �߂�l �FC_Scene_Base * ���݂̃V�[���̃A�h���X
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
GAME::SCENE::BASE::C_Scene_Base * C_Scene_Manager::M_Get_Scene(void)
{
	return m_this.mpr_variable.game_scene.get();
}
