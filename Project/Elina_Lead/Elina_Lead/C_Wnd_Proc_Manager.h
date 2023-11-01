//����������������������������������������������//
// �ڍ�   �F�E�B���h�E�v���V�[�W���𐧌䂷�邽�߂̃V�X�e��
// ����   �F�z�Q�Ƃ�����邽�߂Ɏg�p����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_WND_PROC_SYSTEM
#define D_INCLUDE_GUARD_C_WND_PROC_SYSTEM


// �� OS���m �� //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS


// �� �t�@�C���Ђ炫 �� //
#include <Windows.h>


// �� �l�[���X�y�[�X �� //

// �E�B���h�E�Y�n�����Ăяo�����߂̖��O
namespace OS::WINDOWS::PROC
{
	// �� �N���X �� //

	// �E�B���h�E�v���V�[�W������p�V�X�e��
	class C_Wnd_Proc_Manager
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //
		static WNDPROC m_add_engine_apk_wnd_proc;	// �G���W���A�v���P�[�V�����p�̃E�B���h�E�v���V�[�W���̃A�h���X


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �Z�b�^ -��-//

		// �G���W���p�̃E�B���h�E�v���V�[�W����Ԃ�
		static void M_Set_Engine_APK_Wnd_Proc(WNDPROC);


		//-��- �Q�b�^ -��-//

		// �G���W���p�̃E�B���h�E�v���V�[�W����Ԃ�
		static WNDPROC M_Get_Engine_APK_Wnd_Proc(void);
	};
}


#endif // OS_IS_WINDOWS
#endif // !D_INCLUDE_GUARD_C_WND_PROC_SYSTEM



//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��
