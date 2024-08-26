//����������������������������������������������//
// �ڍ�   �F�E�B���h�E�Y�̋@�\���g�����߂̃N���X
// ����   �F�E�B���h�E�ݒ�⃁�b�Z�[�W�������s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_WINDOWS_SYSTEM_H
#define D_INCLUDE_GUARD_C_WINDOWS_SYSTEM_H


// �� OS���m �� //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS


// �� �t�@�C���Ђ炫 �� //
#include <Windows.h>
#include <memory>
#include <string>

#include "C_OS_Management_System_Base.h"


// �� �l�[���X�y�[�X �� //

// �E�B���h�E�Y�p�̃V�X�e�����Ăяo�����߂̖��O
namespace OS::WINDOWS
{
	// �� �N���X �� //

	// �E�B���h�E�YOS����V�X�e���̃N���X
	class C_Windows_OS_Management_System : public OS::BASE::C_OS_Management_System_Base
	{
		//==��  �v���C�x�[�g  ��==//
	private:

		// �� �\���� �� //

		// �ϐ������܂����߂̍\����
		struct SPr_Variable
		{
			// �E�B���h�E�p���̍\����
			struct S_WND
			{
				HWND h_my_wind = nullptr;	// ���E�B���h�E�̃n���h��

				MSG msg_of_wnd = MSG();	// �E�B���h�E�̏����p�̕ϐ�

			} s_wnd;	// �E�B���h�E

			int m_cmd_show = 0;	// ��ʂɃE�B���h�E��\�����邽�߂̒l

		} mpr_variable;	// ���̃N���X�̕ϐ����Ăяo�����߂̖��O


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^�A�ʏ�̕��@�ŃC���X�^���X���o���Ȃ�����
		C_Windows_OS_Management_System(void);

		// �E�B���h�E�𐶐����鏈��
		bool M_Create_Window(void);

		
		//-��- ���� -��-//

		// �}�E�X���͂̍X�V
		void M_Mouse_Input_Update(void);


		//==��  �p�u���b�N  ��==//
	public:

		// �� �֐� �� //

		//-��-  �������ƏI����  -��-//

		// �E�B���h�E�Y�p�̃V�X�e���𐶐�����
		static void M_Create_Windows_System(void);

		// �E�B���h�E�Y�@�\�̏������p�����A�����FHINSTANCE& �C���X�^���X�n���h��, int& �R�}���h�ԍ�
		bool M_Set_Up(void) override;

		// �f�X�g���N�^
		~C_Windows_OS_Management_System(void);

		// ���������
		void M_Release(void) override;


		//-��- �X�V -��-//

		// �E�B���h�E�̍X�V�������Ȃ�
		void M_Update(void) override;

		// �E�B���h�E�̃T�C�Y�̍X�V���s��
		void M_Window_Size_Update(void) override;

		// ���Ԃ��X�V����
		void M_Update_Time(void) override;


		//-��- �Z�b�^ -��-//

		// �E�B���h�E�̏����R�}���h�ԍ����Z�b�g�@�����F�R�}���h�ԍ�
		static void M_Set_Cmd_Show(int);


		//-��- �Q�b�^ -��-//

		// ���E�B���h�E�̃n���h����Ԃ�
		static HWND M_Get_Window_Handle(void);


		//-��- �E�B���h�E�@�\ -��-//

		// �E�B���h�E�̃^�C�g����ҏW����@�����F�Z�b�g����^�C�g����(const)
		void M_Change_Window_Title(const std::wstring &) override;

		// ���b�Z�[�W�{�b�N�X��\������@�����F�^�C�g��(const), �\�����e(const), ���b�Z�[�W�{�b�N�X�̎��
		int M_Create_Massage_Box(const std::wstring &, const std::wstring &, unsigned int) override;
	};
}


#endif // OS_IS_WINDOWS
#endif // !D_INCLUDE_GUARD_C_WINDOWS_SYSTEM_H


//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��

