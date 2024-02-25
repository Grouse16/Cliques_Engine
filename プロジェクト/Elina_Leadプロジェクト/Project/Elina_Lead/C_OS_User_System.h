//����������������������������������������������//
// �ڍ�   �F�ʏ�̃V�X�e����OS���g�p���邽�߂̃��C���[
// ����   �FOS�̏�����������f�[�^�̕ύX���s��Ȃ��N���X�͂��̃V�X�e�������OS���g�p����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_OS_USER_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_OS_USER_SYSTEM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <string>

#include "S_Window_Size_Data.h"
#include "S_Window_Position.h"
#include "S_Mouse_State.h"
#include "S_Day_And_Time_Inform.h"


// �� �l�[���X�y�[�X �� //

// OS�̃V�X�e�����Ăяo�����߂̖��O
namespace OS
{
	// �� �N���X �� //

	// �ʏ�̃V�X�e����OS���g�p���邽�߂̃��C���[�̃N���X
	class C_OS_User_System
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �Q�b�^ -��-//

		// �E�B���h�E�T�C�Y�̃f�[�^�̎Q�Ƃ�Ԃ��@�߂�l�F�E�B���h�E�T�C�Y�̃f�[�^�̎Q��(const)
		static const S_Window_Size_Data & M_Get_Window_Size(void);

		// �E�B���h�E�̃A�X�y�N�g���Ԃ��@�߂�l�F�A�X�y�N�g��
		static float M_Get_Window_Aspect_Ratio(void);

		// �E�B���h�E���W�̃f�[�^�̎Q�Ƃ�Ԃ��@�߂�l�F�E�B���h�E���W�̃f�[�^�̎Q��(const)
		static const S_Window_Position & M_Get_Window_Position(void);

		// �}�E�X�̏��̃f�[�^�̎Q�Ƃ�Ԃ��@�߂�l�F�}�E�X�̏��̃f�[�^�̎Q��(const)
		static const S_Mouse_State & M_Get_Mouse_State(void);

		// �E�B���h�E�^�C�g����Ԃ��@�߂�l�F�E�B���h�E�^�C�g��
		static std::wstring M_Get_Window_Title(void);

		// ���݂̓����̃f�[�^�̎Q�Ƃ�Ԃ��@�߂�l�F���݂̓����̃f�[�^�̎Q��(const)
		static const S_Day_And_Time_Inform & M_Get_Now_Day_And_Time(void);

		// ���݂̋N��������̃~���b�P�ʂł̌o�ߎ��Ԃ�Ԃ��@�߂�l�F�o�ߎ���
		static unsigned __int64 M_Get_Now_Time_Millisecond_By_Start_Application(void);

		// �E�B���h�E�^�C�g���̕ύX�@�����F�ύX��̃E�B���h�E�^�C�g��
		static void M_Change_Window_Title(std::wstring);

		// ���b�Z�[�W�{�b�N�X�̕\���@�����F�\������^�C�g��, �\�����郁�b�Z�[�W, ���b�Z�[�W�{�b�N�X�̎��
		static int M_Create_Massage_Box(std::wstring, std::wstring, unsigned int);
	};
}


#endif // !D_INCLUDE_GUARD_C_OS_USER_SYSTEM_H_FILE

