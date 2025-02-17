//����������������������������������������������//
// �ڍ�   �F�ʏ�̃V�X�e����OS���g�p���邽�߂̃��C���[
// ����   �FOS�̏�����������f�[�^�̕ύX���s��Ȃ��N���X�͂��̃V�X�e�������OS���g�p����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_OS_User_System.h"
#include "C_OS_Management_System_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace OS;


// �� �N���X �� //

//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̎��Ԃ��X�V����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_OS_User_System::M_Update_Time(void)
{
	OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Update_Time();

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�T�C�Y�̃f�[�^�̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �FS_Window_Size_Data & �E�B���h�E�T�C�Y�̃f�[�^�̎Q��(const)
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const S_Window_Size_Data & C_OS_User_System::M_Get_Window_Size(void)
{
	return OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Get_Window_Size();
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�̃A�X�y�N�g���Ԃ�
// ����   �Fvoid
// �߂�l �Ffloat �A�X�y�N�g��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
float C_OS_User_System::M_Get_Window_Aspect_Ratio(void)
{
	return OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Get_Aspect_Ratio();
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E���W�̃f�[�^�̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �Fconst S_Window_Position & �E�B���h�E���W�̃f�[�^�̎Q��(const)
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const S_Window_Position & C_OS_User_System::M_Get_Window_Position(void)
{
	return OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Get_Window_Position();
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�}�E�X�̏��̃f�[�^�̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �Fconst S_Mouse_State & �}�E�X�̏��̃f�[�^�̎Q��(const)
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const S_Mouse_State & C_OS_User_System::M_Get_Mouse_State(void)
{
	return OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Get_Mouse_State();
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�^�C�g����Ԃ�
// ����   �Fvoid
// �߂�l �Fwstring �E�B���h�E�^�C�g��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::wstring C_OS_User_System::M_Get_Window_Title(void)
{
	return OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Get_Window_Title_Name();
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̓����̃f�[�^�̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �Fconst S_Day_And_Time_Inform & ���݂̓����̃f�[�^�̎Q��(const)
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const S_Day_And_Time_Inform & C_OS_User_System::M_Get_Now_Day_And_Time(void)
{
	return OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Get_Now_Day_And_Time();
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̋N��������̃~���b�P�ʂł̌o�ߎ��Ԃ�Ԃ�
// ����   �Fvoid
// �߂�l �Funsigned __int64 �o�ߎ���
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
unsigned __int64 C_OS_User_System::M_Get_Now_Time_Millisecond_By_Start_Application(void)
{
	return OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Get_Now_Milli_Second_By_Start_Application();
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�̃n���h���ԍ���A���ʔԍ���Ԃ�
// ����   �Fvoid
// �߂�l �Fvoid * �E�B���h�E�̃n���h���ԍ���A���ʔԍ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void * C_OS_User_System::M_Get_Window_Handle_Or_Identify(void)
{
	return OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Get_Window_Handle_Or_Identify();
}


// �� �ύX �� //

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�^�C�g���̕ύX
// ����   �Fwstring �ύX��̃E�B���h�E�^�C�g��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_OS_User_System::M_Change_Window_Title(std::wstring in_change_title_name)
{
	OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Change_Window_Title(in_change_title_name);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���b�Z�[�W�{�b�N�X�̕\��
// ����   �Fwstring �\������^�C�g��, wstring �\�����郁�b�Z�[�W, unsigned int ���b�Z�[�W�{�b�N�X�̎��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
int C_OS_User_System::M_Create_Massage_Box(std::wstring in_massage_title, std::wstring in_massage_text, unsigned int in_massage_kind)
{
	return OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Create_Massage_Box(in_massage_title, in_massage_text, in_massage_kind);
}
