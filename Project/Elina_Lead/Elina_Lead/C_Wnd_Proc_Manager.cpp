//����������������������������������������������//
// �ڍ�   �F�E�B���h�E�v���V�[�W���𐧌䂷�邽�߂̃V�X�e��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� OS���m �� //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS


// �� �t�@�C���Ђ炫 �� //
#include "C_Wnd_Proc_Manager.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace OS::WINDOWS::PROC;


// �� �ϐ��錾 �� //
WNDPROC C_Wnd_Proc_Manager::m_add_engine_apk_wnd_proc = nullptr;	// �E�B���h�E�v���V�[�W���̃A�h���X������


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�G���W���p�̃E�B���h�E�v���V�[�W����ݒ肷��
// ����   �Fvoid
// �߂�l �FWNDPROC �E�B���h�E�v���V�[�W���֐��̃A�h���X
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Wnd_Proc_Manager::M_Set_Engine_APK_Wnd_Proc(WNDPROC in_proc)
{
	m_add_engine_apk_wnd_proc = in_proc;

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�G���W���p�̃E�B���h�E�v���V�[�W����Ԃ�
// ����   �Fvoid
// �߂�l �FWNDPROC �E�B���h�E�v���V�[�W���֐��̃A�h���X
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
WNDPROC C_Wnd_Proc_Manager::M_Get_Engine_APK_Wnd_Proc(void)
{
	return m_add_engine_apk_wnd_proc;
}


#endif // OS_IS_WINDOWS
