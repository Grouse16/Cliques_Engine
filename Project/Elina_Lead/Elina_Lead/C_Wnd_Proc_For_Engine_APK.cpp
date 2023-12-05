//����������������������������������������������//
// �ڍ�   �F�Q�[���p�̃E�B���h�E�v���V�[�W���̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� OS���m �� //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS


// �� �t�@�C���Ђ炫 �� //
#include "C_Wnd_Proc_For_Game_APK.h"
#include "C_Wnd_Proc_Manager.h"
#include "C_OS_System_Base.h"
#include "C_Game_Manager.h"

#include <windowsx.h>


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace OS::WINDOWS::PROC;


// �� �ϐ��錾 �� //
C_Wnd_Proc_For_Game_APK C_Wnd_Proc_For_Game_APK::m_this;	// ���g���C���X�^���X�����邽�߂̕ϐ�


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Wnd_Proc_For_Game_APK::C_Wnd_Proc_For_Game_APK(void)
{
	// �E�B���h�E�v���V�[�W�����Z�b�g
	OS::WINDOWS::PROC::C_Wnd_Proc_Manager::M_Set_Game_APK_Wnd_Proc(Wnd_Proc);

	return;
}


//==�� �p�u���b�N ��==//

//-��- �V�X�e���p -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�̏������s���v���V�[�W��
// ����   �FHWND ���A�v���̃E�B���h�E���, UINT ���[�U�[�̓��͏��, WPARAM ���z�C�[�����̓��͏��, LPARAM �}�E�X�Ȃǂ̓��͏��
// �߂�l �FLRESULT �������ʂ�Ԃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
LRESULT CALLBACK C_Wnd_Proc_For_Game_APK::Wnd_Proc(HWND in_h_wnd, UINT in_msg, WPARAM in_w_param, LPARAM in_l_param)
{
	// �� �ϐ��錾 �� //
	LRESULT window_update_result = DefWindowProc(in_h_wnd, in_msg, in_w_param, in_l_param);	// �E�B���h�E�̍X�V����


	// �I������Ă��炱�̏������s��Ȃ��悤�Ɏ~�߂�
	if (in_h_wnd == NULL || in_msg == WM_QUIT)
	{
		return 0;
	}


	// uMsg�i���̊֐��̑�2�����j���A���[�U�[�����ID���
	switch (in_msg)
	{
		// �� �I���n�� �� //

		// �����ꂩ�̃L�[�������ꂽ�Ƃ�
	case WM_KEYDOWN:

		//  �I���̃{�^��  //
		if (LOWORD(in_w_param) == VK_ESCAPE)
		{
			DestroyWindow(in_h_wnd);  // �gWM_DESTROY�h���b�Z�[�W�𑗂�
		}

		break;

		// �E�B���h�E�j���̃��b�Z�[�W
	case WM_DESTROY:
		PostQuitMessage(0);	// �gWM_QUIT�h���b�Z�[�W�𑗂�@���@�A�v���I��

		break;

		// x�{�^��
	case WM_CLOSE:
		DestroyWindow(in_h_wnd);  // �gWM_DESTROY�h���b�Z�[�W�𑗂�

		break;

		// ���N���b�N
	case WM_LBUTTONDOWN:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Left_Click_State(OS::E_MOUSE_CLICK_STATE::e_CLICK);

		break;

		// ���N���b�N�I��
	case WM_LBUTTONUP:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Left_Click_State(OS::E_MOUSE_CLICK_STATE::e_NON);

		break;

		// ���_�u���N���b�N
	case WM_LBUTTONDBLCLK:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Left_Click_State(OS::E_MOUSE_CLICK_STATE::e_DOUBLE_CLICK);

		break;

		// �E�N���b�N
	case WM_RBUTTONDOWN:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Right_Click_State(OS::E_MOUSE_CLICK_STATE::e_CLICK);

		break;

		// �E�N���b�N�I��
	case WM_RBUTTONUP:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Right_Click_State(OS::E_MOUSE_CLICK_STATE::e_NON);

		break;

		// �E�_�u���N���b�N
	case WM_RBUTTONDBLCLK:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Right_Click_State(OS::E_MOUSE_CLICK_STATE::e_DOUBLE_CLICK);

		break;

		// ���N���b�N
	case WM_MBUTTONDOWN:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Center_Click_State(OS::E_MOUSE_CLICK_STATE::e_CLICK);

		break;

		// ���N���b�N�I��
	case WM_MBUTTONUP:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Center_Click_State(OS::E_MOUSE_CLICK_STATE::e_NON);

		break;

		// ���_�u���N���b�N
	case WM_MBUTTONDBLCLK:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Center_Click_State(OS::E_MOUSE_CLICK_STATE::e_DOUBLE_CLICK);

		break;


		// �E�B���h�E�̃T�C�Y�ύX��
	case WM_SIZING:

		// �E�B���h�E�T�C�Y���X�V���Ă�����x���������s
		OS::C_OS_System_Base::M_Get_Instance()->M_Window_Size_Update();
		GAME::C_Game_Manager::M_Executes_Process();

		break;


		// �E�B���h�E�̈ړ���
	case WM_MOVE:

		// �E�B���h�E�T�C�Y���X�V���Ă�����x���������s
		OS::C_OS_System_Base::M_Get_Instance()->M_Window_Size_Update();
		GAME::C_Game_Manager::M_Executes_Process();

		break;


		// �E�B���h�E�̃T�C�Y�ύX������
	case WM_SIZE:

		// �� �T�C�Y�̕ύX���e�ɂ���ĕ��� �� //
		switch (in_w_param)
		{
			//  �T�C�Y�ύX��  //
		case SIZE_RESTORED:

			// �E�B���h�E�T�C�Y���X�V���Ă�����x���������s
			OS::C_OS_System_Base::M_Get_Instance()->M_Window_Size_Update();
			GAME::C_Game_Manager::M_Executes_Process();

			break;


			//  �ő剻���ꂽ��  //
		case SIZE_MAXIMIZED:

			// �E�B���h�E�T�C�Y���X�V���Ă�����x���������s
			OS::C_OS_System_Base::M_Get_Instance()->M_Window_Size_Update();
			GAME::C_Game_Manager::M_Executes_Process();

			break;

			//  ���̑��̃��b�Z�[�W�͔������Ȃ�  //
		default:
			break;
		}

		break;


		//  �g��G���Ă��邾���̎�  //
	case WM_WINDOWPOSCHANGED:

		// �E�B���h�E�T�C�Y���X�V���Ă�����x���������s
		OS::C_OS_System_Base::M_Get_Instance()->M_Window_Size_Update();
		GAME::C_Game_Manager::M_Executes_Process();

		break;

		// ���̑��̎��͉������Ȃ�
	default:
		break;
	}

	return window_update_result;
}


#endif // OS_IS_WINDOWS

