//����������������������������������������������//
// �ڍ�   �F�G���[���O���t�@�C���Ƃ��ďo�͂���N���X
// ����   �F�f�o�b�O�p�ɑ��݂���G���[���Ƀ��O���t�H���_�Ƃ��ċL�^����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_ERROR_LOG_SYSTEM
#define D_INCLUDE_GUARD_C_ERROR_LOG_SYSTEM


// �� �t�@�C���Ђ炫 �� //
#include <string>


// �� �l�[���X�y�[�X �� //

// �f�o�b�O�p�̃V�X�e���̃��O�V�X�e�����Ăяo�����߂̖��O
namespace DEBUGGER::LOG
{
	// �� �萔 �� //

	// ���O�̎��ʗp�ԍ�
	enum class E_LOG_TAGS
	{
		//-��- �V�X�e�� -��-//
		e_SET_UP = 0,	// ��������
		e_SHUT_DOWN,	// �V���b�g�_�E����


		//-��- �A�v���P�[�V���� -��-//
		e_OBJECT,			// �I�u�W�F�N�g�ɂ�郍�O
		e_GAME_RENDERING,	// �Q�[����̕`��ɂ�郍�O
		e_UI				// UI�ɂ�郍�O
	};

	// ���O�̕\���J���[�ݒ�p�̔ԍ�
	enum class E_LOG_COLOR
	{
		e_WHITE,	// ��
		e_BLACK,	// ��
		e_BLUE,		// ��
		e_GREEN,	// ��
		e_RED,		// ��
		e_PURPLE,	// ��
	};


	// ���O�Ɏg�p���镶������܂Ƃ߂��\����
	namespace ALL_LOG_NAME
	{
		// ���C���V�X�e���p�̃��O������
		namespace MAIN_SYSTEM
		{
			constexpr char con_CONSOLE_CREATED[] = "Console_Created";		// �R���\�[���̐����������̃��O�^�C�g��
			constexpr char con_SET_UP_SUCCEEDED[] = "WIN_DX12_SET_UP_SUCCEEDED";	// �E�B���h�E�Y��DX12�̃V�X�e���̃Z�b�g�A�b�v�������̃��O�^�C�g��
			constexpr char con_ALL_SET_UP_SUCCEEDED[] = "ALL_SET_UP_CLEAR";	// �S�ẴZ�b�g�A�b�v�ɐ��������Ƃ��̃��O
			constexpr char con_END[] = "APK_END";	// �A�v���P�[�V�����I�����̃��O�^�C�g��
		};

		// �Q�[���p�̃��O������
		namespace GAME_SYSTEM
		{
			constexpr char con_GAME_INIT[] = "GAME_INIT";					// �����グ���O
			constexpr char con_GAME_INIT_ERROR[] = "GAME_INIT_ERROR";		// �����グ���s���̃��O
			constexpr char con_GAME_SHADER_ERROR[] = "SHADER_ERROR";		// �V�F�[�_�[�̐������s��
			constexpr char con_GAME_CREATE_FUNCTION[] = "CREATE_FUNCTION";	// �@�\�̐���
		};

		// �Q�[���̕`��V�X�e���p�̃��O������
		namespace GAME_RENDERING
		{
			constexpr char con_INIT[] = "GAME_RENDERING_INIT";		// �����グ���O
			constexpr char con_RENDERING_ERROR[] = "GAME_RENDERING";		// �����_�����O�n���̏����ł̃G���[
			constexpr char con_ERROR[] = "GAME_RENDERING_ERROR";	// �G���[���O
		};

		// �A�v���P�[�V�����̃G���[���O
		namespace APK_LOG
		{
			constexpr char con_MANAGERS_ERROR[] = "MANAGER-ERRORS";	// �E�B���h�E�Y�̃Z�b�g�A�b�v�������̃��O�^�C�g��
		};

		// �E�B���h�E�Y�p�̃��O������
		namespace WINDOWS
		{
			constexpr char con_SET_UP_SUCCEEDED[] = "Windows_Set_Up_Succeeded";	// �E�B���h�E�Y�̃Z�b�g�A�b�v�������̃��O�^�C�g��
		};

		// DX12�p�̃��O������
		namespace DX12
		{
			constexpr char con_SET_UP_SUCCEEDED[] = "DX12_Set_Up_Succeeded";	// �E�B���h�E�Y�̃Z�b�g�A�b�v�������̃��O�^�C�g��
			constexpr char con_SET_UP_FAILED[] = "DX12_Set_Up_Failed";		// �E�B���h�E�Y�̃Z�b�g�A�b�v���s���̃��O�^�C�g��

			constexpr char con_DEVICE_DELETED[] = "DX12_Device_Deleted";	// �f�o�C�X���폜���ꂽ���̃��O�^�C�g��
		};
	};


	// �� �N���X �� //

	// �G���[���O���t�@�C���Ƃ��ďo�͂���N���X
	class C_Log_System
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct Pr_Variable
		{
			FILE* console_file = nullptr;	// �R���\�[���̏o�͐�

			int color_text = 0;	// �R���\�[���̃e�L�X�g�̐F
			int color_back = 0;	// �R���\�[���̔w�i�F

			bool initialized = false;	// ���������ꂽ���ǂ����̃t���O

		} static mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O

		static C_Log_System m_this;	// ���O�V�X�e���p�N���X�̎��́i�V���O���g���j


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^�A�C���X�^���X���h�~�̂��߂ɉB��
		C_Log_System(void);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �f�o�b�O�V�X�e���̏�����
		static void M_Init_Debug(void);

		// �f�X�g���N�^�A�C���X�^���X���h�~�̂��߂ɉB��
		~C_Log_System(void);


		//-��- ���O�o�� -��-//

		// �w�肳�ꂽ�������ݒ肳�ꂽ�t�@�C�����ŏo�͂���A���� E_LOG_TAGS ���O�̎��, string �L�^����t�@�C����, string �L�^���e
		static void M_Print_Log(E_LOG_TAGS, std::string, std::string);

		// �������~�߂ă��O���o��
		static void M_Stop_Update_And_Log_Present(void);

		// �R���\�[���̃��O������������
		static void M_Console_LOG_Flush(void);

		// �R���\�[���̕����J���[��ύX����A���� E_LOG_COLOR �ݒ肷��F�ԍ�
		static void M_Set_Console_Text_Color(E_LOG_COLOR);

		// �R���\�[���̔w�i�J���[��ύX����A���� E_LOG_COLOR �ݒ肷��F�ԍ�
		static void M_Set_Console_Back_Ground_Color(E_LOG_COLOR);

		// �R���\�[���̕����Ɣw�i�J���[��ύX����A���� E_LOG_COLOR �����̐F, �w�i�̐F
		static void M_Set_Console_Color_Text_And_Back(E_LOG_COLOR, E_LOG_COLOR);
	};
}


#endif // !D_INCLUDE_GUARD_C_ERROR_LOG_SYSTEM


//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��

