//����������������������������������������������//
// �ڍ�   �FOS�̃V�X�e���𐧌䂷�邽�߂̊��N���X
// ����   �FOS�̋����Ȃǂ��w�肷��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_OS_Management_System_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace OS::BASE;


// �� �ϐ��錾 �� //
std::unique_ptr<C_OS_Management_System_Base> C_OS_Management_System_Base::m_this_instance;	// �C���X�^���X�����邽�߂̎���

bool C_OS_Management_System_Base::m_flg_os_active = false;	// OS���I���������ǂ����̃t���O


// �� �֐� �� //

//==�� �v���e�N�g ��==//

//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�̃^�C�g�������Z�b�g����
// ����   �Fwstring �Z�b�g����E�B���h�E�^�C�g��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_OS_Management_System_Base::M_Set_Window_Title_Name(std::wstring in_set_window_title)
{
	m_title_name = in_set_window_title;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̎��Ԃ��Z�b�g����
// ����   �Fconst S_Day_And_Time_Inform & �Z�b�g���鎞��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_OS_Management_System_Base::M_Set_Now_Day_And_Time(const S_Day_And_Time_Inform & in_set_time)
{
	m_now_day_and_time = in_set_time;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���s����Ă���̃~���b�P�ʂł̌o�ߎ��Ԃ̃Z�b�^
// ����   �Funsigned __int64 �Z�b�g����o�ߎ���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_OS_Management_System_Base::M_Set_Now_Time_By_Start_In_Milli_Second(unsigned __int64 in_set_time)
{
	m_now_time_by_start_in_milli_second = in_set_time;

	return;
}


//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_OS_Management_System_Base::C_OS_Management_System_Base(void)
{
	m_flg_os_active = true;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FOS�V�X�e�����폜����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_OS_Management_System_Base::M_Delete_OS_System(void)
{
	m_this_instance.reset();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_OS_Management_System_Base::~C_OS_Management_System_Base(void)
{
	m_this_instance.reset();

	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�}�E�X���W���Z�b�g����
// ����   �Fint �����W, int �����W
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_OS_Management_System_Base::M_Set_Mouse_Position_Variable(int in_set_x, int in_set_y)
{
	m_mouse_state.x = in_set_x;
	m_mouse_state.y = in_set_y;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F��ʃT�C�Y���Z�b�g����
// ����   �Fint ����, int �c��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_OS_Management_System_Base::M_Set_Window_Size_Variable(int in_width, int in_height)
{
	m_size_of_window.width = (in_width != 0) * in_width + (in_width == 0) * 1;
	m_size_of_window.height = (in_height != 0) * in_height + (in_height == 0) * 1;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�̍��W���Z�b�g����
// ����   �FS_Window_Position & �E�B���h�E���W
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_OS_Management_System_Base::M_Set_Window_Position_Variable(S_Window_Position & in_window_pos)
{
	m_position_window = in_window_pos;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���N���b�N�̃t���O���Z�b�g����
// ����   �FE_MOUSE_CLICK_STATE �N���b�N�̏��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_OS_Management_System_Base::M_Set_Left_Click_State(E_MOUSE_CLICK_STATE in_set_state)
{
	m_mouse_state.left_click = in_set_state;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�N���b�N�̃t���O���Z�b�g����
// ����   �FE_MOUSE_CLICK_STATE �N���b�N�̏��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_OS_Management_System_Base::M_Set_Right_Click_State(E_MOUSE_CLICK_STATE in_set_state)
{
	m_mouse_state.right_click = in_set_state;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���N���b�N�̃t���O���Z�b�g����
// ����   �FE_MOUSE_CLICK_STATE �N���b�N�̏��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_OS_Management_System_Base::M_Set_Center_Click_State(E_MOUSE_CLICK_STATE in_set_state)
{
	m_mouse_state.center_click = in_set_state;

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FOS�p�V�X�e���̃C���X�^���X�̃A�h���X��Ԃ�
// ����   �Fvoid
// �߂�l �FC_OS_Management_System_Base * OS�V�X�e���̃A�h���X
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_OS_Management_System_Base * C_OS_Management_System_Base::M_Get_Instance(void)
{
	return m_this_instance.get();
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FOS�̃V�X�e������~�������ǂ�����Ԃ�
// ����   �Fvoid
// �߂�l �F�I�����̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_OS_Management_System_Base::M_Get_OS_Active(void)
{
	return m_flg_os_active;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�̃T�C�Y��Ԃ�
// ����   �Fvoid
// �߂�l �Fconst S_Window_Size_Data & �E�B���h�E�̃T�C�Y
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const OS::S_Window_Size_Data & C_OS_Management_System_Base::M_Get_Window_Size(void) const
{
	return m_size_of_window;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�̃A�X�y�N�g���Ԃ�
// ����   �Fvoid
// �߂�l �Ffloat �A�X�y�N�g��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
float C_OS_Management_System_Base::M_Get_Aspect_Ratio(void) const
{
	return static_cast<float>(m_size_of_window.width) / static_cast<float>(m_size_of_window.height);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�̈ʒu��Ԃ�
// ����   �Fvoid
// �߂�l �Fconst S_Window_Position & �E�B���h�E�̍��W
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const OS::S_Window_Position & C_OS_Management_System_Base::M_Get_Window_Position(void) const
{
	return m_position_window;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�}�E�X�̏�Ԃ�Ԃ�
// ����   �Fvoid
// �߂�l �Fconst S_Window_Position & �}�E�X�̏��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const OS::S_Mouse_State & C_OS_Management_System_Base::M_Get_Mouse_State(void)  const
{
	return m_mouse_state;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̎��Ԃ̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �Fconst S_Day_And_Time_Inform & ���݂̎��Ԃ̎Q��(const)
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const OS::S_Day_And_Time_Inform & C_OS_Management_System_Base::M_Get_Now_Day_And_Time(void) const
{
	return m_now_day_and_time;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�o�ߎ��Ԃ��~���b�P�ʂŎ擾����
// ����   �Fvoid
// �߂�l �Funsigned __int64 �擾��̎��ԕϐ��̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
unsigned __int64 C_OS_Management_System_Base::M_Get_Now_Milli_Second_By_Start_Application(void) const
{
	return m_now_time_by_start_in_milli_second;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�̃^�C�g������Ԃ�
// ����   �Fvoid
// �߂�l �Fwstring �E�B���h�E�^�C�g����
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::wstring C_OS_Management_System_Base::M_Get_Window_Title_Name(void) const
{
	return m_title_name;
}




