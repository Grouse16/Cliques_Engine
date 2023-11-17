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

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG



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
		M_Release();
		m_this.mpr_variable.game_scene.reset(new C_Scene_Title());
		GAME::STATE::C_Game_State_Manager::M_Set_Now_Game_Scene_Name(L"TITLE");

		return true;
	}

	// �Q�[���V�[��
	if (in_load_scene == "GAME")
	{
		M_Release();
		m_this.mpr_variable.game_scene.reset(new C_Scene_Game());
		GAME::STATE::C_Game_State_Manager::M_Set_Now_Game_Scene_Name(L"GAME");

		return true;
	}


	// �f�o�b�O���̓V�[����������Ȃ��������Ƃ��������O���o���S�Ă̏������~�߂�
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "���̃V�[���͂���܂���F" + in_load_scene);
	DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

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
