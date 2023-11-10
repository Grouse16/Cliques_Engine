//����������������������������������������������//
// �ڍ�   �F�G���W���̃V�X�e������p�̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include <algorithm>

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG

#include "C_Game_Manager.h"
#include "C_OS_System_Base.h"
#include "C_Rendering_Graphics_API_Base.h"
#include "C_Engine_Function_Manager.h"
#include "C_Game_State_Manager.h"

#include "Engine_Function_Name.h"

#include "C_APK_Manager.h"

#include "C_Engine_Input_Manager.h"
#include "C_Engine_Input_Collision_Manager.h"

#include "C_Game_Time_Manager.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME;


// �� �ϐ��錾 �� //
C_Game_Manager C_Game_Manager::m_this;	// ���N���X�ւ̃A�N�Z�X�p�̕ϐ�

C_Game_Manager::SPr_Variable C_Game_Manager::mpr_variable;		// ���N���X�̕ϐ��ւ̃A�N�Z�X�p�̕ϐ�


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^�A������Ԃ̎w��ƃC�x���g�̐������s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Game_Manager::C_Game_Manager(void)
{

	return;
}


//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�[�^�̍X�V���s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Manager::M_Data_Update(void)
{
	// �� �ϐ��錾 �� //
	const std::wstring & executed_scene_name = GAME::STATE::C_Game_State_Manager::M_Get_Execute_Change_Engine_Scene_Name();	// �ύX�v���̂������V�[�����̎Q��


	// �ύX�v�����Ȃ��Ȃ�X���[
	if (executed_scene_name == GAME::STATE::con_Invalid_Scene_Name)
	{
		return;
	}

	// �ύX�悪���݂Ɠ����Ȃ�ύX����
	if (GAME::STATE::C_Game_State_Manager::M_Get_Now_Engine_Scene_Name() == executed_scene_name)
	{
		GAME::STATE::C_Game_State_Manager::M_Set_Execute_Change_Engine_Scene_Name(executed_scene_name);

		return;
	}


	// �� �ύX��V�[��������K�v�ȋ@�\�̐������s�� �� //

	// �Q�[����ʗp�̃V�[��
	if (executed_scene_name == L"GAME")
	{

	}

	// �w�肳�ꂽ�V�[�������݂��Ȃ�
	else
	{
		// �f�o�b�O���͂Ȃ����Ƃ�����
#ifdef _DEBUG

#endif // _DEBUG
	}


	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�^�C�g���̍X�V
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Manager::M_Window_Title_Update(void)
{
	// �f�o�b�O���̂ݕύX
#ifdef _DEBUG
	
	// �� �ϐ��錾 �� //
	std::wstring new_title;	// �V�����^�C�g���̕�����


	new_title = OS::con_DEVICE_NAME + L"    fps : "
		+ 
		std::to_wstring(TIME::C_Game_Time_Manager::M_Get_FPS()) + L"/" + std::to_wstring(TIME::C_Game_Time_Manager::M_Get_Frame_Rate())
		+
		L"�@speed:" + std::to_wstring(TIME::C_Game_Time_Manager::M_Get_Delta_Second());
	OS::C_OS_System_Base::M_Get_Instance()->M_Set_Window_Title(new_title);

#endif	// _DEBUG

	return;
}


//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�[���̏����O�ɍs���G���W�����̏���
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Manager::M_Init(void)
{
	// �� �f�o�b�O���Ȃ珉�����J�n�����m �� //
#if _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "-��-��-��-��-��-��-��- �G���W���̏��������J�n -��-��-��-��-��-��-��-");
#endif

	// �G���W���̓��̓V�X�e���𐶐�����
	GAME::INPUT::COLLISION::C_Engine_Input_Collision_Manager::M_Init();
	GAME::INPUT::C_Engine_Input_Manager::M_Init();

	// �G���W���̎��ԃV�X�e���𐶐�����
	GAME::TIME::C_Game_Time_Manager::M_Init();

	// ���L�f�[�^�̏�����
	GAME::STATE::C_Game_State_Manager::M_Init();
	GAME::STATE::C_Game_State_Manager::M_Set_Execute_Change_Engine_Scene_Name(L"GAME");
	M_Data_Update();


	// ��{�����̐��������s
	GAME::FUNCTION::C_Engine_Function_Manager::M_Command_Create_Function(GAME::FUNCTION::NAME::BASE::con_FRAME_WORK);
	if (GAME::FUNCTION::C_Engine_Function_Manager::M_Execute_Create_Function_By_List() == false)
	{
		// �� �f�o�b�O���Ȃ珉�����̐�������ю��s�����m �� //
#if _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_RED);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "-��-��-��-��-��-��-��- �G���W���̏������Ɏ��s -��-��-��-��-��-��-��-");
#endif // _DEBUG

		 M_Set_Engine_Exist_Flg(false);

		return;
	}

	// �������Ɏ��s�����玸�s�����m����
	if (M_Get_Engine_Exist_Flg() == false)
	{
		// �� �f�o�b�O���Ȃ珉�����̎��s�����m �� //
#if _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_RED);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "-��-��-��-��-��-��-��- �G���W���̏������Ɏ��s -��-��-��-��-��-��-��-");
#endif // _DEBUG

		return;
	}


	// �� �f�o�b�O���Ȃ珉�����̐��������m �� //
#if _DEBUG
	// �������ɐ��������琬�������m����
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "-��-��-��-��-��-��-��- �G���W���̏������ɐ��� -��-��-��-��-��-��-��-");
#endif //_DEBUG


	// �A�N�e�B�u��Ԃ��w��
	mpr_variable.flg_engine_activate = true;
	M_Set_Engine_Exist_Flg(true);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^�A�g�p���Ă��郁�������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Game_Manager::~C_Game_Manager(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Manager::M_Release(void)
{
	// �A�v���P�[�V�����̏I��������
	mpr_variable.flg_engine_activate = false;
	M_Set_Engine_Exist_Flg(false);

	// �A�v���P�[�V�����̉��
	APPLICATION::C_APK_Manager::M_Release();

	// �Q�[���p�V�X�e�����폜
	GAME::FUNCTION::C_Engine_Function_Manager::M_Release_Memory();
	GAME::INPUT::C_Engine_Input_Manager::M_Release();
	GAME::INPUT::COLLISION::C_Engine_Input_Collision_Manager::M_Release();
	GAME::TIME::C_Game_Time_Manager::M_Release();
	GAME::STATE::C_Game_State_Manager::M_Release();

	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�G���W���𑶍݂��Ă����Ԃ��ǂ�����ݒ肷��
// ����   �Ftrue�͐���ɑ��݂��Ă���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Manager::M_Set_Engine_Exist_Flg(bool in_set_exist)
{
	mpr_variable.flg_engine_exist = in_set_exist;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�G���W�����ғ������ǂ�����ݒ肷��
// ����   �Ftrue�͐���ɑ��݂��Ă���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Manager::M_Set_Engine_Activate_Flg(bool in_set_active)
{
	mpr_variable.flg_engine_activate = in_set_active;

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�G���W���𑶍݂��Ă����Ԃ��ǂ������擾����
// ����   �Ftrue�͐���ɑ��݂��Ă���
// �߂�l �F�I�����̏ꍇ�́Atrue
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Game_Manager::M_Get_Engine_Exist_Flg(void)
{
	return mpr_variable.flg_engine_exist;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�G���W�����A�N�e�B�u��Ԃ��ǂ�����Ԃ�
// ����   �Fvoid
// �߂�l �F�A�N�e�B�u���̏ꍇ�́Atrue
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Game_Manager::M_Get_Engine_Active_Flg(void)
{
	return mpr_variable.flg_engine_activate;
}


//-��- ���s -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�G���W���̏��������s����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Manager::M_Executes_Process(void)
{
	//======�� ���s�m�F ��======//

	// �G���W�������݂��Ă��Ȃ����ғ����łȂ��Ȃ���s���Ȃ�
	if ((M_Get_Engine_Active_Flg() & M_Get_Engine_Exist_Flg()) == false)
	{
		return;
	}


	//======�� �X�^�[�g ��======//

	// OS�̍X�V�@���łɍX�V���Ȃ�X���[
	if (mpr_variable.flg_OS_active_now == false)
	{
		mpr_variable.flg_OS_active_now = true;
		OS::C_OS_System_Base::M_Get_Instance()->M_Update();

		// OS���I�����Ă�����G���W�����I������
		if (OS::C_OS_System_Base::M_Get_OS_Active() == false)
		{
			M_Set_Engine_Exist_Flg(false);

			return;
		}
		mpr_variable.flg_OS_active_now = false;
	}

	// ���Ԃ̍X�V
	GAME::TIME::C_Game_Time_Manager::M_Time_Update();

	// �E�B���h�E�^�C�g�����X�V
	M_Window_Title_Update();



	//======�� ���� ��======//

	// �Q�[���̓���
	GAME::INPUT::C_Engine_Input_Manager::M_Update();

	// �V�[���̓���
	APPLICATION::C_APK_Manager::M_APK_Input();



	//======�� �X�V ��======//

	// �V�[���X�V�O�̋@�\�̍X�V
	GAME::FUNCTION::C_Engine_Function_Manager::M_Before_Scene_Update();

	// �V�[���X�V
	APPLICATION::C_APK_Manager::M_APK_Update();

	// �V�[���X�V��̋@�\�̍X�V
	GAME::FUNCTION::C_Engine_Function_Manager::M_After_Scene_Update();



	//======�� �`�� ��======//

	//  �����_�����O�V�X�e���̕`�揀��  //
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Rendering_Start();


	// �V�[���`��O�̋@�\�̕`��
	GAME::FUNCTION::C_Engine_Function_Manager::M_Before_Scene_Draw();

	// �V�[���̕`��
	APPLICATION::C_APK_Manager::M_APK_Draw();

	// �V�[���`���̋@�\�̕`��
	GAME::FUNCTION::C_Engine_Function_Manager::M_After_Scene_Draw();


	//  �����_�����O�I���Ɖ�ʏo��  //
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Rendering_End_And_Swap_Screen();



	//======�� ���̃t���[���ւ̏��� ��======//

	// �K�v�̂Ȃ��@�\�̍폜
	GAME::FUNCTION::C_Engine_Function_Manager::M_Delete_Function();

	// �K�v�ȋ@�\�̐���
	GAME::FUNCTION::C_Engine_Function_Manager::M_Execute_Create_Function_By_List();

	// �G���W���̋��L�f�[�^�̍X�V
	M_Data_Update();

	// �t���[���̏I�����̍X�V
	GAME::TIME::C_Game_Time_Manager::M_Frame_End_Update();

	return;
}
