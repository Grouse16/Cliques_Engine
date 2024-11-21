//����������������������������������������������//
// �ڍ�   �F�E�B���h�E�Y�p�̃��O���o�͂���N���X�̒�`
// ����   �F�f�o�b�O�p�Ƀ��O���L�^����V�X�e�����E�B���h�E�Y�p�Ɍ`������
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �f�o�b�O���̂ݗL�� �� //
#ifdef _DEBUG

// �� �E�B���h�E�Y���ł̎��s���̂ݗL�� �� //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS


// �� �t�@�C���Ђ炫 �� //
#include <string>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>
#include <conio.h>

#include "C_Windows_Console_Log_System.h"
#include "C_Text_And_File_Manager.h"
#include "C_OS_User_System.h"
#include "E_CONSOLE_LOG_TAGS.h"
#include "E_CONSOLE_LOG_COLOR.h"
#include "Console_Debug_Log_Names.h"
#include "GCC_Or_MSVC_Macro.h"
#include "Challenge_Mode_Macro.h"


// �f�o�b�O���̓��������[�N���o
#define _CRTDBG_MAP_ALLOC


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace DEBUGGER::LOG::CONSOLE::WINDOWS;


// �� �l�[���X�y�[�X �� //

// Windows�p�̃R���\�[���V�X�e���Ɏg�p����萔�Q���Ăяo�����߂̖��O
namespace LOCALSPACE::CONSTANT_DATAS
{
	// �� �萔 �� //
	const char * con_DEBUG_FOLDER_PATH = "DEBUG_DATA/DEBUG_LOG";	// �f�o�b�O�f�[�^�ۑ���̃p�X

	constexpr int con_BLACK = 0;	// ���F
	constexpr int con_GRAY = FOREGROUND_INTENSITY;	// �D�F
	constexpr int con_WHITE = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;	// ���F
	constexpr int con_LIGHT_WHITE = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;	// ���邢���F
	constexpr int con_RED = FOREGROUND_RED;		// �ԐF
	constexpr int con_PINK = FOREGROUND_RED | FOREGROUND_INTENSITY;		// �s���N
	constexpr int con_GREEN = FOREGROUND_GREEN;	// �ΐF
	constexpr int con_LIGHT_GREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY;	// ���ΐF
	constexpr int con_BLUE = FOREGROUND_BLUE;	// �F
	constexpr int con_LIGHT_BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY;	// ���F
	constexpr int con_PURPLE = FOREGROUND_RED | FOREGROUND_BLUE;	// ���F
	constexpr int con_LIGHT_PURPLE = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;	// ���邢���F
	constexpr int con_YELLOW = FOREGROUND_RED | FOREGROUND_GREEN;	// ���F
	constexpr int con_LIGHT_YELLOW = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;	// ���邢���F
	constexpr int con_CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE;	// �V�A���i���j
	constexpr int con_LIGHT_CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;	// ���邢�V�A���i���j
}


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^�A�C���X�^���X���h�~�̂��߂ɉB��
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Windows_Console_Log_System::C_Windows_Console_Log_System(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�o�b�O�V�X�e���̏�����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_Console_Log_System::M_Init_Debug(void)
{
	// �A�Z���u���`�������W��
#ifdef  D_ASM_CHALLENGE

	// GCC�ł̃R���p�C����
#ifdef D_GCC_COMPILE & D_ASM_CHALLENGE

	// ���łɏ���������Ă���Δ�����
	asm volatile
		(
			"cmpb $1, %0\n"			// initialized �� true (1) ���ǂ������r
			"ret\n"					// initialized �� true �̏ꍇ�̓��^�[��
			:						// �o�̓I�y�����h
	: "m" (mpr_variable.initialized) // ���̓I�y�����h
		);

	// MSVC�ł̃R���p�C����
#elif D_MSVC_COMPILE

	// ���łɏ���������Ă���Δ�����
	__asm
	{
		mov al, mpr_variable.initialized // initialized �� AL ���W�X�^�Ƀ��[�h
		cmp al, 1                       // true (1) �Ɣ�r
		ret                             // true �̏ꍇ�̓��^�[��
	}

#endif

	// �A�Z���u���`�������W���ł͂Ȃ���
#else

	// ���łɏ���������Ă���Δ�����
	if (mpr_variable.initialized == true)
	{
		return;
	}

#endif //  D_ASM_CHALLENGE


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
	if (_setmode(_fileno(stdout), _O_TEXT) == -1)
	{
		return;
	}


	// �Ȃ�ƂȂ��J�b�R�����F��ݒ肷��
	DEBUGGER::LOG::CONSOLE::WINDOWS::C_Windows_Console_Log_System::M_Set_Console_Color_Text_And_Back(COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);

	// ���O�̐����ɐ����������Ƃ����O�Ƃ��Ďc��
	M_Print_Log(TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, ALL_LOG_NAME::MAIN_SYSTEM::con_CONSOLE_CREATED, "�f�o�b�O�p�R���\�[���y�уV�X�e���̐����ɐ���");

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FWindows�p�̃R���\�[�����O�V�X�e���𐶐�����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_Console_Log_System::M_Create_Windows_Console_Debug_Log_System(void)
{
	// �� �ϐ��錾 �� //
	C_Windows_Console_Log_System * new_windows_console_log_system = new C_Windows_Console_Log_System();	// �E�B���h�E�Y�p�̃R���\�[�����O�V�X�e��


	// �f�o�b�O�V�X�e���̏�����
	new_windows_console_log_system->M_Init_Debug();

	// �V���O���g���̃C���X�^���X�𐶐�
	m_this.reset(new_windows_console_log_system);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Windows_Console_Log_System::~C_Windows_Console_Log_System(void)
{
	M_Delete_Console_Debug_Log_System();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�o�b�O���O�V�X�e�����폜����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_Console_Log_System::M_Delete_Console_Debug_Log_System(void)
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
// ����   �FC_Console_Debug_Log_System_Base::E_CONSOLE_LOG_TAGS ���O�̎��, string �L�^����t�@�C����, string �L�^���e
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_Console_Log_System::M_Print_Log(TAGS::E_CONSOLE_LOG_TAGS in_tag, std::string in_file_name, std::string in_print_log)
{
	// �� �ϐ��錾 �� //
	SYSTEM::TEXT::C_Text_And_File_Manager file_user_system;	// �t�@�C������p�V�X�e��

	OS::S_Day_And_Time_Inform now_time_and_day;	// ���ԂƓ��t

	std::string log_file_path;	// �o�͂��郍�O�^�C�g��
	std::string print_log;	// �o�͂��郍�O


	// ���݂̎��ԏ����擾
	OS::C_OS_User_System::M_Update_Time();
	now_time_and_day = OS::C_OS_User_System::M_Get_Now_Day_And_Time();


	// �o�͂��郍�O�̓��t��ݒ�
	log_file_path += std::to_string(now_time_and_day.year)		// �N�̕\��
		+ "-" + std::to_string(now_time_and_day.month)		// ���̕\��
		+ "-" + std::to_string(now_time_and_day.day) + "/";	// ���̕\��


	// �� ���O�̎��ʔԍ��ɂ���ĕʁX�̏���t�� �� //
	switch (in_tag)
	{
		//-��- �V�X�e�� -��-//

		//  �Z�b�g�A�b�v  //
	case TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP:
		log_file_path += "SYSTEM_00-SET_UP-";
		break;

		//  �V���b�g�_�E����  //
	case TAGS::E_CONSOLE_LOG_TAGS::e_SHUT_DOWN:
		log_file_path += "SYSTEM_01-SHUT_DOWN-";
		break;


		//-��- �A�v���P�[�V���� -��-//

		//  �I�u�W�F�N�g  //
	case TAGS::E_CONSOLE_LOG_TAGS::e_OBJECT:
		log_file_path += "APPLICATION_00-OBJECT-";
		break;

		//  �Q�[���̕`��p�V�X�e��  //
	case TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING:
		log_file_path += "APPLICATION_01-GAME_RENDERING-";
		break;

		//  UI  //
	case TAGS::E_CONSOLE_LOG_TAGS::e_UI:
		log_file_path += "APPLICATION_02-UI-";
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
	std::wcout << std::endl << log_file_path.c_str() << std::endl << print_log.c_str();


	// �f�[�^���L������
	file_user_system.M_Set_File_Path
	(
		((std::string)LOCALSPACE::CONSTANT_DATAS::con_DEBUG_FOLDER_PATH
		+ "/" + log_file_path
		+ "/" + (std::string)(in_file_name) + ".txt").c_str()
	);
	file_user_system.M_Input_This_Data((print_log + "\n\0").c_str());
	file_user_system.M_Add_Data_To_Now_File();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[�����݂邽�߂ɏ������~�߂ē��̓o�b�t�@��S�ăN���A��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_Console_Log_System::M_Stop_Update_And_Log_Present(void)
{
	// �� �萔 �� //
	constexpr int con_ENTER = 13;	// Enter�̃A�X�L�[�R�[�h


	// �� �ϐ��錾 �� //
	bool inputted_enter = false;	// Enter�������ꂽ���ǂ���


	// �o�b�t�@�̓��e����ʂɏo��
	std::wcout << std::flush;

	// Enter��҂��Ƃ�\������
	std::cout << std::endl;
	std::cout << "Press Enter to continue...";
	
	// Enter���������܂őҋ@����
	while (inputted_enter == false)
	{
		// �L�[�{�[�h�̓��͂��`�F�b�N
		if (_kbhit())
		{
			// Enter�L�[�̃A�X�L�[�R�[�h�����͂��ꂽ��iEnter�̓��͂���������j���[�v�𔲂���
			if (_getch() == con_ENTER)
			{
				inputted_enter = true;
			}
		}
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[���̃��O������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_Console_Log_System::M_Console_Log_Flush(void)
{
	// �� �萔 �� //
	constexpr int con_LINE_SUM = 50;	// ��ʂ��N���A���邽�߂̋�s�̐�


	// �F�����ɖ߂�
	M_Set_Console_Text_Color(COLOR::E_CONSOLE_LOG_COLOR::e_WHITE);
	M_Set_Console_Back_Ground_Color(COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	
	// ��s���o�͂��ĉ�ʂ��N���A�����悤�Ɍ�����
	for (int l_write_line = 0; l_write_line < con_LINE_SUM; ++l_write_line)
	{
		std::cout << std::endl;
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[���̕����J���[��ύX����
// ����   �FE_CONSOLE_LOG_COLOR �ݒ肷��F�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_Console_Log_System::M_Set_Console_Text_Color(COLOR::E_CONSOLE_LOG_COLOR in_set_color)
{
	// �� �ϐ��錾 �� //
	int & color_data = mpr_variable.text_color;	// �F�f�[�^�̐ݒ��̎Q��


	// �{�ƃz�[���y�[�W https://learn.microsoft.com/ja-JP/windows/console/console-screen-buffers#character-attributes

	// �� �����J���[�ύX��ݒ� �� //
	switch (in_set_color)
	{
		//  ��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_BLACK:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_BLACK;
		break;

		//  �O���[  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_GRAY:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_GRAY;
		break;

		//  ��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_WHITE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_WHITE;
		break;

		//  ���邢��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_WHITE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_WHITE;
		break;

		//  ��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_RED:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_RED;
		break;

		//  �s���N  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_PINK:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_PINK;
		break;

		//  ��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_GREEN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_GREEN;
		break;

		//  ���邢��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_GREEN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_GREEN;
		break;

		//  ��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_BLUE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_BLUE;
		break;

		//  ���邢��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_BLUE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_BLUE;
		break;

		//  ��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_PURPLE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_PURPLE;
		break;

		//  ���邢��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_PURPLE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_PURPLE;
		break;

		//  ��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_YELLOW:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_YELLOW;
		break;

		//  ���邢��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_YELLOW:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_YELLOW;
		break;

		//  �V�A��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_CYAN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_CYAN;
		break;

		//  ���邢�V�A��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_CYAN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_CYAN;
		break;
	}


	// �F�̍X�V
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), mpr_variable.text_color | mpr_variable.color_back);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[���̔w�i�J���[��ύX����
// ����   �FE_CONSOLE_LOG_COLOR �ݒ肷��F�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_Console_Log_System::M_Set_Console_Back_Ground_Color(COLOR::E_CONSOLE_LOG_COLOR in_set_color)
{
	// �� �ϐ��錾 �� //
	int & color_data = mpr_variable.color_back;	// �F�f�[�^�̐ݒ��̎Q��


	// �� �����J���[�ύX��ݒ� �� //
	switch (in_set_color)
	{
		//  ��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_BLACK:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_BLACK;
		break;

		//  �O���[  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_GRAY:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_GRAY;
		break;

		//  ��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_WHITE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_WHITE;
		break;

		//  ���邢��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_WHITE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_WHITE;
		break;

		//  ��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_RED:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_RED;
		break;

		//  �s���N  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_PINK:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_PINK;
		break;

		//  ��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_GREEN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_GREEN;
		break;

		//  ���邢��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_GREEN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_GREEN;
		break;

		//  ��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_BLUE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_BLUE;
		break;

		//  ���邢��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_BLUE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_BLUE;
		break;

		//  ��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_PURPLE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_PURPLE;
		break;

		//  ���邢��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_PURPLE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_PURPLE;
		break;

		//  ��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_YELLOW:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_YELLOW;
		break;

		//  ���邢��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_YELLOW:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_YELLOW;
		break;

		//  �V�A��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_CYAN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_CYAN;
		break;

		//  ���邢�V�A��  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_CYAN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_CYAN;
		break;
	}


	// �F�̍X�V
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), mpr_variable.text_color | mpr_variable.color_back);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���\�[���̔w�i�J���[��ύX����
// ����   �FE_CONSOLE_LOG_COLOR �e�L�X�g�̐F�ԍ�, E_CONSOLE_LOG_COLOR �w�i�̐F�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Windows_Console_Log_System::M_Set_Console_Color_Text_And_Back(COLOR::E_CONSOLE_LOG_COLOR in_txt_color, COLOR::E_CONSOLE_LOG_COLOR in_back_color)
{
	M_Set_Console_Text_Color(in_txt_color);
	M_Set_Console_Back_Ground_Color(in_back_color);

	return;
}


#endif // D_OS_IS_WINDOWS

#endif // _DEBUG

