//����������������������������������������������//
// �ڍ�   �F�G���W���p�̃E�B���h�E�v���V�[�W���̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_WND_PROC_FOR_ENGINE_APK
#define D_INCLUDE_GUARD_C_WND_PROC_FOR_ENGINE_APK


// �� OS���m �� //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS


// �� �t�@�C���Ђ炫 �� //
#include <Windows.h>


// �� �l�[���X�y�[�X �� //

// �E�B���h�E�Y�p�̃V�X�e�����Ăяo�����߂̖��O
namespace OS::WINDOWS::PROC
{
	// �� �N���X �� //

	// �E�B���h�E�v���V�[�W���𐧌䂷�邽�߂̃V�X�e��
	class C_Wnd_Proc_For_Engine_APK
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //
		static C_Wnd_Proc_For_Engine_APK m_this;	// ���g�̃C���X�^���X(�V���O���g�����Ɏg�p)


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^
		C_Wnd_Proc_For_Engine_APK(void);

	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �E�B���h�E�Y -��-//

		// �E�B���h�E�v���V�[�W��
		static LRESULT CALLBACK Wnd_Proc(HWND, UINT, WPARAM, LPARAM);
	};
}


#endif // OS_IS_WINDOWS
#endif // !D_INCLUDE_GUARD_C_WND_PROC_FOR_ENGINE_APK



//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��

