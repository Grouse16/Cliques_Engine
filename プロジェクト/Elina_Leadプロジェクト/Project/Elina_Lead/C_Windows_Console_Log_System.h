//����������������������������������������������//
// �ڍ�   �F�E�B���h�E�Y�p�̃R���\�[�����O�V�X�e���̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_WINDOWS_CONSOLE_LOG_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_WINDOWS_CONSOLE_LOG_SYSTEM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_Console_Debug_Log_System_Base.h"


// �� �l�[���X�y�[�X �� //

// �E�B���h�E�Y�p�̃R���\�[�����O�p�V�X�e�����Ăяo�����߂̖��O
namespace DEBUGGER::LOG::CONSOLE::WINDOWS
{
	// �� �N���X �� //

	// �E�B���h�E�Y�p�R���\�[���f�o�b�O���O�o�̓V�X�e��
	class C_Windows_Console_Log_System : public DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//
		
		// �R���X�g���N�^
		C_Windows_Console_Log_System(void);

		// �f�o�b�O�V�X�e���̏������Ɛ���
		void M_Init_Debug(void) override;

		// Windows�p�̃R���\�[�����O�V�X�e���𐶐�����
		static void M_Create_Windows_Console_Debug_Log_System(void);

		// �f�X�g���N�^
		~C_Windows_Console_Log_System(void) override;

		// �f�o�b�O���O�V�X�e�����폜����
		void M_Delete_Console_Debug_Log_System(void) override;


		//-��- ���O�o�� -��-//

		// �w�肳�ꂽ�������ݒ肳�ꂽ�t�@�C�����ŏo�͂���@�����F���O�̎��, �L�^����t�@�C����, �L�^���e
		void M_Print_Log(TAGS::E_CONSOLE_LOG_TAGS, std::string, std::string) override;

		// �������~�߂ă��O���o��
		void M_Stop_Update_And_Log_Present(void) override;

		// �R���\�[���̃��O������������
		void M_Console_Log_Flush(void) override;

		// �R���\�[���̕����J���[��ύX����@�����F�ݒ肷��F�ԍ�
		void M_Set_Console_Text_Color(COLOR::E_CONSOLE_LOG_COLOR) override;

		// �R���\�[���̔w�i�J���[��ύX����@�����F�ݒ肷��F�ԍ�
		void M_Set_Console_Back_Ground_Color(COLOR::E_CONSOLE_LOG_COLOR) override;

		// �R���\�[���̕����Ɣw�i�J���[��ύX����@�����F�����̐F, �w�i�̐F
		void M_Set_Console_Color_Text_And_Back(COLOR::E_CONSOLE_LOG_COLOR, COLOR::E_CONSOLE_LOG_COLOR) override;
	};
}


#endif //!D_INCLUDE_GUARD_C_WINDOWS_CONSOLE_LOG_SYSTEM_H_FILE

