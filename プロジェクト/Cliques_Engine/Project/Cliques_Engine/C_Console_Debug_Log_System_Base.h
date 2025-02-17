//����������������������������������������������//
// �ڍ�   �F���O���R���\�[���ƃt�@�C���ɏo�͂���N���X
// ����   �F�f�o�b�O�p�Ƀ��O���L�^����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_CONSOLE_DEBUG_LOG_SYSTEM
#define D_INCLUDE_GUARD_C_CONSOLE_DEBUG_LOG_SYSTEM


// �� �t�@�C���Ђ炫 �� //
#include <memory>
#include <string>

#include "E_CONSOLE_LOG_TAGS.h"
#include "E_CONSOLE_LOG_COLOR.h"


// �� �l�[���X�y�[�X �� //

// �f�o�b�O���O�̃R���\�[���̊��N���X���Ăяo�����߂̖��O
namespace DEBUGGER::LOG::CONSOLE::BASE
{
	// �� �N���X �� //

	// �f�o�b�O���O�o�͗p�V�X�e���̊��N���X
	class C_Console_Debug_Log_System_Base
	{
		//==�� �v���e�N�g ��==//
	protected:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct Pr_Variable
		{
			FILE * console_file = nullptr;	// �R���\�[���̏o�͐�

			int text_color = 0;	// �R���\�[���̃e�L�X�g�̐F
			int color_back = 0;	// �R���\�[���̔w�i�F

			bool initialized = false;	// ���������ꂽ���ǂ����̃t���O

		} static mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O

		static std::unique_ptr<C_Console_Debug_Log_System_Base> m_this;	// ���O�V�X�e���p�N���X�̎��́i�V���O���g���j


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^�A�C���X�^���X���h�~�̂��߂ɉB��
		C_Console_Debug_Log_System_Base(void);

		// �f�X�g���N�^
		virtual ~C_Console_Debug_Log_System_Base(void);

		// �f�o�b�O�V�X�e���̏������Ɛ���
		virtual void M_Init_Debug(void) = 0;

		// �f�o�b�O���O�V�X�e�����폜����
		virtual void M_Delete_Console_Debug_Log_System(void) = 0;

		// �f�o�b�O���O�V�X�e�����������
		static void M_Release(void);


		//-��- �Q�b�^ -��-//

		// �R���\�[�����O�V�X�e���̃C���X�^���X�̃A�h���X��Ԃ��@�߂�l�F�R���\�[�����O�V�X�e���̎Q��
		static C_Console_Debug_Log_System_Base * M_Get_Console_Debug_Log_System(void);


		//-��- ���O�o�� -��-//

		// �w�肳�ꂽ�������ݒ肳�ꂽ�t�@�C�����ŏo�͂���@�����F���O�̎��, �L�^����t�@�C����, �L�^���e
		virtual void M_Print_Log(TAGS::E_CONSOLE_LOG_TAGS, std::string, std::string) = 0;

		// �������~�߂ă��O���o��
		virtual void M_Stop_Update_And_Log_Present(void) = 0;

		// �R���\�[���̃��O������������
		virtual void M_Console_Log_Flush(void) = 0;

		// �R���\�[���̕����J���[��ύX����@�����F�ݒ肷��F�ԍ�
		virtual void M_Set_Console_Text_Color(COLOR::E_CONSOLE_LOG_COLOR) = 0;

		// �R���\�[���̔w�i�J���[��ύX����@�����F�ݒ肷��F�ԍ�
		virtual void M_Set_Console_Back_Ground_Color(COLOR::E_CONSOLE_LOG_COLOR) = 0;

		// �R���\�[���̕����Ɣw�i�J���[��ύX����@�����F�����̐F, �w�i�̐F
		virtual void M_Set_Console_Color_Text_And_Back(COLOR::E_CONSOLE_LOG_COLOR, COLOR::E_CONSOLE_LOG_COLOR) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_CONSOLE_DEBUG_LOG_SYSTEM


//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��

