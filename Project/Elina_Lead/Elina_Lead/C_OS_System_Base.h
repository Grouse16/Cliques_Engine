//����������������������������������������������//
// �ڍ�   �FOS�̃V�X�e���𐧌䂷�邽�߂̊��N���X
// ����   �FOS�̋����Ȃǂ��w�肷��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_OS_SYSTEM_BASE_H_FILE
#define D_INCLUDE_GUARD_C_OS_SYSTEM_BASE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>
#include <string>
#include <memory>


// �� �l�[���X�y�[�X �� //

// OS�̊��N���X���Ăяo�����߂̖��O
namespace OS
{
	// �� �񋓌^ �� //

	// �}�E�X�̃N���b�N��Ԃ��w�肷���
	enum class E_MOUSE_CLICK_STATE
	{
		e_NON,			// �������Ă��Ȃ�
		e_CLICK,		// �N���b�N��
		e_DOUBLE_CLICK,	// �_�u���N���b�N��
	};


	// �� �\���� ��//

	// �E�B���h�E�̃T�C�Y�w��p�̍\����
	struct S_Window_Size_Data
	{
		int width = 0;	// ��ʉ��̃T�C�Y
		int height = 0;	// ��ʏc�̃T�C�Y
	};

	// �}�E�X���W�p�̍\����
	struct S_Mouse_State
	{
		E_MOUSE_CLICK_STATE left_click = E_MOUSE_CLICK_STATE::e_NON;	// ���N���b�N�̏��
		E_MOUSE_CLICK_STATE center_click = E_MOUSE_CLICK_STATE::e_NON;	// ���N���b�N�̏��
		E_MOUSE_CLICK_STATE right_click = E_MOUSE_CLICK_STATE::e_NON;	// �E�N���b�N�̏��

		int x = 0;	// �}�E�X���W��
		int y = 0;	// �}�E�X���W��
	};

	// �E�B���h�E�̈ʒu���w�肷��\����
	struct S_Window_Position
	{
		int position_left_x = 0;	// �E�B���h�E�̍��[
		int position_right_x = 0;	// �E�B���h�E�̉E�[
		int position_top_y = 0;		// �E�B���h�E�̏�[
		int position_bottom_y = 0;	// �E�B���h�E�̉���
	};

	// ���t�Ǝ��ԏ��̍\����
	struct S_Time_Inform
	{
		int year = 0;	// �N
		int month = 0;	// ��
		int day = 0;	// ��

		int hour = 0;	// ��
		int minute = 0;	// ��
		int second = 0;	// �b
	};


	// �� �萔 �� //
	const std::wstring con_DEVICE_NAME = L"Elina Lead";	// �f�o�C�X��


	// �� �N���X �� //

	// OS�V�X�e���̊��N���X
	class C_OS_System_Base
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //
		OS::S_Window_Size_Data m_size_of_window;	// �E�B���h�E�̃T�C�Y

		OS::S_Window_Position m_position_window;	// �E�B���h�E�̈ʒu���W

		OS::S_Mouse_State m_mouse_state;	// �}�E�X���W


	//==�� �v���e�N�g ��==//
	protected:

		// �� �ϐ��錾 �� //
		static std::unique_ptr<C_OS_System_Base> m_this_instance;	// �C���X�^���X���p�v���C�x�[�g�ϐ�

		static bool m_flg_os_active;	// OS���I��������t���O


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_OS_System_Base(void);

		// OS�̏��������s��
		virtual bool M_Set_Up(void) = 0;

		// ���������
		virtual void M_Release(void) = 0;

		// OS�V�X�e�����폜����
		static void M_Delete_OS_System(void);

		// �f�X�g���N�^
		virtual ~C_OS_System_Base(void);


		//-��- �X�V -��-//

		// �X�V���s��
		virtual void M_Update(void) = 0;

		// �E�B���h�E�̃T�C�Y�̍X�V
		virtual void M_Window_Size_Update(void) = 0;


		//-��- �Z�b�^ -��-//

		// �}�E�X���W���Z�b�g����@�����F�����W, �����W
		void M_Set_Mouse_Position_Variable(int, int);

		// ��ʃT�C�Y���Z�b�g����@�����F����,�@�c��
		void M_Set_Window_Size_Variable(int, int);

		// �E�B���h�E�̍��W���Z�b�g����@�����F
		void M_Set_Window_Position_Variable(S_Window_Position&);

		// ���N���b�N�̃t���O���Z�b�g����@�����F�N���b�N�̏��
		void M_Set_Left_Click_State(E_MOUSE_CLICK_STATE);

		// �E�N���b�N�̃t���O���Z�b�g����@�����F�N���b�N�̏��
		void M_Set_Right_Click_State(E_MOUSE_CLICK_STATE);

		// ���N���b�N�̃t���O���Z�b�g����@�����F�N���b�N�̏��
		void M_Set_Center_Click_State(E_MOUSE_CLICK_STATE);


		//-��- �Q�b�^ -��-//

		// OS�p�V�X�e���̃C���X�^���X�̃A�h���X��Ԃ�
		static C_OS_System_Base * M_Get_Instance(void);

		// OS�̃V�X�e������~�������ǂ�����Ԃ�
		static bool M_Get_OS_Active(void);

		// �E�B���h�E�̃T�C�Y��Ԃ��@�߂�l�F�E�B���h�E�T�C�Y
		const S_Window_Size_Data & M_Get_Window_Size(void);

		// �E�B���h�E�̍��W��Ԃ��@�߂�l�F�E�B���h�E���W
		const S_Window_Position & M_Get_Window_Position(void);

		// �}�E�X�̏�Ԃ�Ԃ��@�߂�l�F�}�E�X�̏��
		const S_Mouse_State & M_Get_Mouse_State(void);

		// ���݂̎��Ԃ������̎Q�Ɛ�ɓn��
		virtual void M_Get_Now_Time(S_Time_Inform & ) = 0;

		// �o�ߎ��Ԃ��~���b�P�ʂŎ擾����@�����F�擾��̎��ԕϐ��̎Q��
		virtual void M_Get_Now_Milli_Second(unsigned __int64 & ) = 0;


		//-��- �E�B���h�E�@�\ -��-//

		// �E�B���h�E�̃^�C�g����ҏW����@�����Fconst std::wstring & �Z�b�g����^�C�g����
		virtual void M_Set_Window_Title(const std::wstring & ) = 0;

		// ���b�Z�[�W�{�b�N�X��\������(�E�B���h�E�n���h����K�v�Ƃ��邽��)�@�����Fconst std::wstring �^�C�g��, const std::wstring �\�����e, const unsigned int ���b�Z�[�W�{�b�N�X�̎��
		virtual int M_Create_Massage_Box(const std::wstring &, const std::wstring &, const unsigned int ) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_OS_SYSTEM_BASE_H_FILE


//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��
