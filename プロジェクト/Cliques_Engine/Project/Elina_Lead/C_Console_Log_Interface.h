//����������������������������������������������//
// �ڍ�   �F�R���\�[�����O���o�͂��邽�߂̃C���^�[�t�F�[�X
// ����   �F�R���\�[�����O�̐����⏉�����A�o�́A������ȗ������A�ˑ��֌W��؂藣�����߂̃C���^�[�t�F�[�X
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_CONSOLE_LOG_INTERFACE_H_FILE
#define D_INCLUDE_GUARD_C_CONSOLE_LOG_INTERFACE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <string>	// ������

#include "E_CONSOLE_LOG_TAGS.h"			// �R���\�[�����O�̃^�O
#include "E_CONSOLE_LOG_COLOR.h"		// �R���\�[�����O�̐F
#include "Console_Debug_Log_Names.h"	// ���O��


// �� �l�[���X�y�[�X �� //

// �R���\�[�����O�p�̃V�X�e�����Ăяo�����߂̖��O
namespace DEBUGGER::LOG::CONSOLE
{
	// �� �N���X �� //

	// �R���\�[�����O���o�͂��邽�߂̃C���^�[�t�F�[�X
	class C_Console_Log_Interface
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^�A�C���X�^���X���h�~�̂��߂ɉB��
		C_Console_Log_Interface(void);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �f�o�b�O���O�N���X�𐶐�����A�n�r��r���h���̐ݒ�ŕ��򂷂�
		static void M_Create_And_Initialize_Console_Log_System(void);

		// �f�o�b�O���O�V�X�e�����폜����
		static void M_Delete_Console_Log_System(void);


		//-��- �o�� -��-//

		// �w�肳�ꂽ�������ݒ肳�ꂽ�t�@�C�����ŏo�͂���@�����F���O�̎��, �L�^����t�@�C����, �L�^���e
		static void M_Print_Log(TAGS::E_CONSOLE_LOG_TAGS, std::string, std::string);

		// �������~�߂ă��O���o��
		static void M_Stop_Update_And_Log_Present(void);

		// �R���\�[����ʂɏo�͒��̃��O���t���b�V���i�������j����
		static void M_Console_LOG_Flush(void);


		//-��- �F -��-//

		// �R���\�[���̕����J���[��ύX����@�����F�ݒ肷��F�ԍ�
		static void M_Set_Console_Text_Color(COLOR::E_CONSOLE_LOG_COLOR);

		// �R���\�[���̔w�i�J���[��ύX����@�����F�ݒ肷��F�ԍ�
		static void M_Set_Console_Back_Ground_Color(COLOR::E_CONSOLE_LOG_COLOR);

		// �R���\�[���̕����Ɣw�i�J���[��ύX����@�����F�����̐F, �w�i�̐F
		static void M_Set_Console_Color_Text_And_Back(COLOR::E_CONSOLE_LOG_COLOR, COLOR::E_CONSOLE_LOG_COLOR);
	};
}


#endif // !D_INCLUDE_GUARD_C_CONSOLE_LOG_INTERFACE_H_FILE
