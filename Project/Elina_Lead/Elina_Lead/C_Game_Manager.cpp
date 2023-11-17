//����������������������������������������������//
// �ڍ�   �F�Q�[���̃V�X�e������p�̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include <algorithm>

#include "C_Game_Manager.h"
#include "C_OS_System_Base.h"
#include "C_Rendering_Graphics_API_Base.h"
#include "C_Game_Function_Manager.h"
#include "C_Game_State_Manager.h"
#include "C_APK_Manager.h"
#include "C_Game_Input_Manager.h"
#include "C_Game_Input_Collision_Manager.h"
#include "C_Game_Time_Manager.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


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
// �߂�l �F�Ȃ�
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
	const std::wstring & executed_scene_name = GAME::STATE::C_Game_State_Manager::M_Get_Execute_Change_Game_Scene_Name();	// �ύX�v���̂������V�[�����̎Q��


	// �ύX�v�����Ȃ��Ȃ�X���[
	if (executed_scene_name == GAME::STATE::con_Invalid_Scene_Name)
	{
		return;
	}

	// �ύX�悪���݂Ɠ����Ȃ�ύX����
	if (GAME::STATE::C_Game_State_Manager::M_Get_Now_Game_Scene_Name() == executed_scene_name)
	{
		GAME::STATE::C_Game_State_Manager::M_Set_Execute_Change_Game_Scene_Name(executed_scene_name);

		return;
	}


	// �� �ύX��V�[��������K�v�ȋ@�\�̐������s�� �� //

	// �^�C�g���V�[��
	if (executed_scene_name == L"TITLE")
	{

	}

	// �Q�[���V�[��
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
// �ڍ�   �F�V�[���̏����O�ɍs���Q�[�����̏���
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Manager::M_Init(void)
{
	// �� �f�o�b�O���Ȃ珉�����J�n�����m �� //
#if _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "-��-��-��-��-��-��-��- �Q�[���̏��������J�n -��-��-��-��-��-��-��-");
#endif

	// �Q�[���̋��ʏ����܂Ƃ߂�V�X�e���𐶐�����
	GAME::STATE::C_Game_State_Manager::M_Init();

	// �Q�[���̓��̓V�X�e���𐶐�����
	GAME::INPUT::COLLISION::C_Game_Input_Collision_Manager::M_Init();
	GAME::INPUT::C_Game_Input_Manager::M_Init();

	// �Q�[���̎��ԃV�X�e���𐶐�����
	GAME::TIME::C_Game_Time_Manager::M_Init();

	// �A�v���P�[�V�����V�X�e���̏��������s��
	M_Set_Game_Exist_Flg(GAME::APPLICATION::C_APK_Manager::M_Init());


	// �������Ɏ��s�����玸�s�����m����
	if (M_Get_Game_Exist_Flg() == false)
	{
		// �� �f�o�b�O���Ȃ珉�����̎��s�����m �� //
#if _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_RED);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "-��-��-��-��-��-��-��- �Q�[���̏������Ɏ��s -��-��-��-��-��-��-��-");
#endif // _DEBUG

		return;
	}


	// �� �f�o�b�O���Ȃ珉�����̐��������m �� //
#if _DEBUG
	// �������ɐ��������琬�������m����
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "-��-��-��-��-��-��-��- �Q�[���̏������ɐ��� -��-��-��-��-��-��-��-");
#endif //_DEBUG


	// �A�N�e�B�u��Ԃ��w��
	mpr_variable.flg_game_activate = true;
	M_Set_Game_Exist_Flg(true);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^�A�g�p���Ă��郁�������������
// ����   �Fvoid
// �߂�l �F�Ȃ�
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
	mpr_variable.flg_game_activate = false;
	M_Set_Game_Exist_Flg(false);

	// �A�v���P�[�V�����̉��
	GAME::APPLICATION::C_APK_Manager::M_Release();

	// �Q�[���p�V�X�e�����폜
	GAME::FUNCTION::C_Game_Function_Manager::M_Release_Memory();
	GAME::INPUT::C_Game_Input_Manager::M_Release();
	GAME::INPUT::COLLISION::C_Game_Input_Collision_Manager::M_Release();
	GAME::TIME::C_Game_Time_Manager::M_Release();
	GAME::STATE::C_Game_State_Manager::M_Release();

	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�Q�[���𑶍݂��Ă����Ԃ��ǂ�����ݒ肷��
// ����   �Ftrue�͐���ɑ��݂��Ă���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Manager::M_Set_Game_Exist_Flg(bool in_set_exist)
{
	mpr_variable.flg_game_exist = in_set_exist;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�Q�[�����ғ������ǂ�����ݒ肷��
// ����   �Ftrue�͐���ɑ��݂��Ă���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Manager::M_Set_Game_Activate_Flg(bool in_set_active)
{
	mpr_variable.flg_game_activate = in_set_active;

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�Q�[���𑶍݂��Ă����Ԃ��ǂ������擾����
// ����   �Ftrue�͐���ɑ��݂��Ă���
// �߂�l �F�I�����̏ꍇ�́Atrue
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Game_Manager::M_Get_Game_Exist_Flg(void)
{
	return mpr_variable.flg_game_exist;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�Q�[�����A�N�e�B�u��Ԃ��ǂ�����Ԃ�
// ����   �Fvoid
// �߂�l �F�A�N�e�B�u���̏ꍇ�́Atrue
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Game_Manager::M_Get_Game_Active_Flg(void)
{
	return mpr_variable.flg_game_activate;
}


//-��- ���s -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�Q�[���̏��������s����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Game_Manager::M_Executes_Process(void)
{
	//======�� ���s�m�F ��======//

	// �Q�[�������݂��Ă��Ȃ����ғ����łȂ��Ȃ���s���Ȃ�
	if ((M_Get_Game_Active_Flg() & M_Get_Game_Exist_Flg()) == false)
	{
		return;
	}


	//======�� �X�^�[�g ��======//

	// OS�̍X�V�@���łɍX�V���Ȃ�X���[
	if (mpr_variable.flg_OS_active_now == false)
	{
		mpr_variable.flg_OS_active_now = true;
		OS::C_OS_System_Base::M_Get_Instance()->M_Update();

		// OS���I�����Ă�����Q�[�����I������
		if (OS::C_OS_System_Base::M_Get_OS_Active() == false)
		{
			M_Set_Game_Exist_Flg(false);

			return;
		}
		mpr_variable.flg_OS_active_now = false;
	}

	// ���Ԃ̍X�V
	GAME::TIME::C_Game_Time_Manager::M_Time_Update();

	// �E�B���h�E�^�C�g�����X�V
	M_Window_Title_Update();



	//======�� ���� ��======//

	// �Q�[������V�X�e���̓���
	GAME::INPUT::C_Game_Input_Manager::M_Update();

	// �Q�[���̓���
	GAME::APPLICATION::C_APK_Manager::M_APK_Input();



	//======�� �X�V ��======//

	// �Q�[���X�V�O�̋@�\�̍X�V
	GAME::FUNCTION::C_Game_Function_Manager::M_Before_Scene_Update();

	// �Q�[���̍X�V
	GAME::APPLICATION::C_APK_Manager::M_APK_Update();

	// �Q�[���X�V��̋@�\�̍X�V
	GAME::FUNCTION::C_Game_Function_Manager::M_After_Scene_Update();



	//======�� �`�� ��======//

	//  �����_�����O�V�X�e���̕`�揀��  //
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Rendering_Start();

	// �Q�[���̕`��
	GAME::APPLICATION::C_APK_Manager::M_APK_Draw();

	// �Q�[���`���̋@�\�̍X�V
	GAME::FUNCTION::C_Game_Function_Manager::M_After_Scene_Draw_Update();


	//  �����_�����O�I���Ɖ�ʏo��  //
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Rendering_End_And_Swap_Screen();



	//======�� ���̃t���[���ւ̏��� ��======//

	// �K�v�̂Ȃ��@�\�̍폜
	GAME::FUNCTION::C_Game_Function_Manager::M_Delete_Function();

	// �K�v�ȋ@�\�̐���
	GAME::FUNCTION::C_Game_Function_Manager::M_Execute_Create_Function_By_List();

	// �Q�[���̋��L�f�[�^�̍X�V
	M_Data_Update();

	// �t���[���̏I�����̍X�V
	GAME::TIME::C_Game_Time_Manager::M_Frame_End_Update();

	return;
}
