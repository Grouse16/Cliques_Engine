//����������������������������������������������//
// �ڍ�   �F���O���o�͂���N���X
// ����   �F�f�o�b�O�p�Ƀ��O���L�^����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �f�o�b�O���̂ݗL�� �� //
#if _DEBUG


// �� �t�@�C���Ђ炫 �� //
#include <string>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <atlstr.h>

#include "C_Log_System.h"
#include "C_Text_And_File_Manager.h"
#include "C_OS_System_Base.h"


// �f�o�b�O���̓��������[�N���o
#define _CRTDBG_MAP_ALLOC


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace DEBUGGER::LOG;


// �� �ϐ��錾 �� //
C_Log_System C_Log_System::m_this;	// ���N���X�ւ̃A�N�Z�X�p�̕ϐ�
C_Log_System::Pr_Variable C_Log_System::mpr_variable;	// �v���C�x�[�g�ϐ��ւ̃A�N�Z�X�p�̕ϐ�


// �� �萔 �� //
const char* con_DEBUG_FOLDER_PATH = "DEBUG_DATA/DEBUG_LOG";	// �f�o�b�O�f�[�^�ۑ���̃p�X


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Log_System::C_Log_System(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	return;
}


//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�o�b�O�V�X�e���̏�����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Log_System::M_Init_Debug(void)
{
	// ����������Ă���Δ�����
	if (mpr_variable.initialized == true)
	{
		return;
	}

	// ���������ꂽ���Ƃ��L�^
	mpr_variable.initialized = true;

	// �R���\�[����ʂ�����������
	FreeConsole();


	// �R���\�[����ʂ���������
	AllocConsole();
	AttachConsole(ATTACH_PARENT_PROCESS);


	// �R���\�[���̃f�[�^�t�@�C�������
	_wfreopen_s(&mpr_variable.console_file, L"CONOUT$", L"w+", stdout);

	// �o�͂̕����R�[�h�w��Ahttps://learn.microsoft.com/en-us/cpp/c-runtime-library/translation-mode-constants?view=msvc-170
	{int stab = _setmode(_fileno(stdout), _O_TEXT);}


	// �Ȃ�ƂȂ��J�b�R�����F��ݒ肷��
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);


	// ���O���������������O�Ƃ��Ďc��
	M_Print_Log(E_LOG_TAGS::e_SET_UP, ALL_LOG_NAME::MAIN_SYSTEM::con_CONSOLE_CREATED, "�f�o�b�O�p�R���\�[���y�уV�X�e���̐����ɐ���(Create C_Log_System & Console�FSucceeded)");

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Log_System::~C_Log_System(void)
{
	// �R���\�[����ʂ��폜����
	FreeConsole();


	// �t�@�C�������
	if (mpr_variable.console_file != nullptr)
	{
		fclose(mpr_variable.console_file);
	}

	return;
}


//-��- ���O�o�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���O���o�͂���
// ����   �FC_Log_System::E_LOG_TAGS ���O�̎��, string �L�^����t�@�C����, string �L�^���e
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Log_System::M_Print_Log(E_LOG_TAGS in_tag, std::string in_file_name, std::string in_print_log)
{
	// ����������Ă��Ȃ���Ώ�����
	M_Init_Debug();


	// �� �ϐ��錾 �� //
	SYSTEM::TEXT::C_Text_And_File_Manager file_user_system;	// �t�@�C������p�V�X�e��

	OS::S_Time_Inform now_time_and_day;	// ���ԂƓ��t

	std::string log_title;	// �o�͂��郍�O�^�C�g��
	std::string print_log;	// �o�͂��郍�O


	// ���ԏ����f�[�^�ɕϊ�
	OS::C_OS_System_Base::M_Get_Instance()->M_Get_Now_Time(now_time_and_day);


	// �o�͂��郍�O�̓��t��ݒ�
	log_title += std::to_string(now_time_and_day.year)		// �N�̕\��
		+ "-" + std::to_string(now_time_and_day.month)		// ���̕\��
		+ "-" + std::to_string(now_time_and_day.day) + "/";	// ���̕\��


	// �� ���O�̎��ʔԍ��ɂ���ĕʁX�̏���t�� �� //
	switch (in_tag)
	{
		//-��- �V�X�e�� -��-//

		//  �Z�b�g�A�b�v  //
	case E_LOG_TAGS::e_SET_UP:
		log_title += "SYSTEM_00-SET_UP-";
		break;

		//  �V���b�g�_�E����  //
	case E_LOG_TAGS::e_SHUT_DOWN:
		log_title += "SYSTEM_01-SHUT_DOWN-";
		break;


		//-��- �A�v���P�[�V���� -��-//

		//  �I�u�W�F�N�g  //
	case E_LOG_TAGS::e_OBJECT:
		log_title += "APPLICATION_00-OBJECT-";
		break;

		//  �Q�[���̕`��p�V�X�e��  //
	case E_LOG_TAGS::e_GAME_RENDERING:
		log_title += "APPLICATION_01-GAME_RENDERING-";
		break;

		//  UI  //
	case E_LOG_TAGS::e_UI:
		log_title += "APPLICATION_02-UI-";
		break;


		//-��- �G���[ -��-//

		// ��O��
	default:
		break;
	}


	// �o�͂��郍�O��ݒ�
	print_log =
		std::to_string(now_time_and_day.hour) + "-hour."	// ����
		+ std::to_string(now_time_and_day.minute) + "-min."	// ��
		+ std::to_string(now_time_and_day.second) + "-sec\n"	// �b
		+ (std::string)(in_print_log)+"\n";				// ���O���e


	// �R���\�[���ɏ���\������
	std::wcout << std::endl << log_title.c_str() << std::endl << print_log.c_str();


	// �f�[�^���L������
	file_user_system.M_Set_File_Path(((std::string)con_DEBUG_FOLDER_PATH + "/" + log_title + "/" + (std::string)(in_file_name)+".txt").c_str());
	file_user_system.M_Input_This_Data((print_log + "\n\0").c_str());
	file_user_system.M_Add_Data_To_Now_File();
	
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[�����݂邽�߂ɏ������~�߂ē��̓o�b�t�@��S�ăN���A��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Log_System::M_Stop_Update_And_Log_Present(void)
{
	// �o�b�t�@�̓��e����ʂɏo��
	std::wcout << std::flush;

	// enter��҂�
	std::cout << "Press Enter to continue...";
	fflush(stdin);
	std::cin.get();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[���̃��O������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Log_System::M_Console_LOG_Flush(void)
{
	// �F�����ɖ߂�
	C_Log_System::M_Set_Console_Text_Color(E_LOG_COLOR::e_WHITE);
	C_Log_System::M_Set_Console_Back_Ground_Color(E_LOG_COLOR::e_BLACK);
	std::system("cls");

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[���̕����J���[��ύX����
// ����   �FE_LOG_COLOR �ݒ肷��F�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Log_System::M_Set_Console_Text_Color(E_LOG_COLOR in_set_color)
{
	// �{�ƃz�[���y�[�W https://learn.microsoft.com/ja-JP/windows/console/console-screen-buffers#character-attributes

	// �� �����J���[�ύX��ݒ� �� //
	switch (in_set_color)
	{
		//  ��  //
	case E_LOG_COLOR::e_WHITE:
		m_this.mpr_variable.color_text = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;
		break;

		//  ��  //
	case E_LOG_COLOR::e_BLACK:
		m_this.mpr_variable.color_text = 0;
		break;

		//  ��  //
	case E_LOG_COLOR::e_BLUE:
		m_this.mpr_variable.color_text = FOREGROUND_BLUE;
		break;

		//  ��  //
	case E_LOG_COLOR::e_GREEN:
		m_this.mpr_variable.color_text = FOREGROUND_GREEN;
		break;

		//  ��  //
	case E_LOG_COLOR::e_RED:
		m_this.mpr_variable.color_text = FOREGROUND_RED;
		break;

		//  ��  //
	case E_LOG_COLOR::e_PURPLE:
		m_this.mpr_variable.color_text = FOREGROUND_RED | FOREGROUND_BLUE;
		break;
	}


	// �F�̍X�V
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), m_this.mpr_variable.color_text | m_this.mpr_variable.color_back);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[���̔w�i�J���[��ύX����
// ����   �FE_LOG_COLOR �ݒ肷��F�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Log_System::M_Set_Console_Back_Ground_Color(E_LOG_COLOR in_set_color)
{
	// �� �w�i�J���[�ύX��ݒ� �� //
	switch (in_set_color)
	{
		//  ��  //
	case E_LOG_COLOR::e_WHITE:
		m_this.mpr_variable.color_back = BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED;
		break;

		//  ��  //
	case E_LOG_COLOR::e_BLACK:
		m_this.mpr_variable.color_back = 0;
		break;

		//  ��  //
	case E_LOG_COLOR::e_BLUE:
		m_this.mpr_variable.color_back = BACKGROUND_BLUE;
		break;

		//  ��  //
	case E_LOG_COLOR::e_GREEN:
		m_this.mpr_variable.color_back = BACKGROUND_GREEN;
		break;

		//  ��  //
	case E_LOG_COLOR::e_RED:
		m_this.mpr_variable.color_back = BACKGROUND_RED;
		break;

		//  ��  //
	case E_LOG_COLOR::e_PURPLE:
		m_this.mpr_variable.color_back = BACKGROUND_RED | BACKGROUND_BLUE;
		break;
	}


	// �F�̍X�V
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), m_this.mpr_variable.color_text | m_this.mpr_variable.color_back);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[���̔w�i�J���[��ύX����
// ����   �FE_LOG_COLOR �e�L�X�g�̐F�ԍ�, E_LOG_COLOR �w�i�̐F�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Log_System::M_Set_Console_Color_Text_And_Back(E_LOG_COLOR in_txt_color, E_LOG_COLOR in_back_color)
{
	M_Set_Console_Text_Color(in_txt_color);
	M_Set_Console_Back_Ground_Color(in_back_color);

	return;
}


#endif // _DEBUG

