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

#include "E_MOUSE_CLICK_STATE.h"
#include "S_Window_Size_Data.h"
#include "S_Mouse_State.h"
#include "S_Window_Position.h"
#include "S_Day_And_Time_Inform.h"


// �� �l�[���X�y�[�X �� //

// OS�̊��N���X���Ăяo�����߂̖��O
namespace OS::BASE
{
	// �� �N���X �� //

	// OS����V�X�e���̊��N���X
	class C_OS_Management_System_Base
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //
		OS::S_Window_Size_Data m_size_of_window;	// �E�B���h�E�̃T�C�Y

		OS::S_Window_Position m_position_window;	// �E�B���h�E�̈ʒu���W

		OS::S_Mouse_State m_mouse_state;	// �}�E�X���W

		std::wstring m_title_name = L"Elina Lead";	// �E�B���h�E�^�C�g����

		S_Day_And_Time_Inform m_now_day_and_time;	// ���݂̎���

		unsigned __int64 m_now_time_by_start_in_milli_second;	// ���s����Ă���̃~���b�P�ʂł̌o�ߎ���


	//==�� �v���e�N�g ��==//
	protected:

		// �� �ϐ��錾 �� //
		static std::unique_ptr<C_OS_Management_System_Base> m_this_instance;	// �C���X�^���X���p�v���C�x�[�g�ϐ�

		static bool m_flg_os_active;	// OS���I��������t���O


		// �� �֐� �� //

		//-��- �Z�b�^ -��-//

		// �E�B���h�E�̃^�C�g�������Z�b�g����@�����F�Z�b�g����E�B���h�E�^�C�g��
		void M_Set_Window_Title_Name(std::wstring);

		// ���݂̎��Ԃ��Z�b�g����@�����F�Z�b�g���錻�݂̎���
		void M_Set_Now_Day_And_Time(const S_Day_And_Time_Inform & );

		// ���s����Ă���̃~���b�P�ʂł̌o�ߎ��Ԃ̃Z�b�^�@�����F�Z�b�g����o�ߎ���
		void M_Set_Now_Time_By_Start_In_Milli_Second(unsigned __int64);


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_OS_Management_System_Base(void);

		// OS�̏��������s��
		virtual bool M_Set_Up(void) = 0;

		// ���������
		virtual void M_Release(void) = 0;

		// OS�V�X�e�����폜����
		static void M_Delete_OS_System(void);

		// �f�X�g���N�^
		virtual ~C_OS_Management_System_Base(void);


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
		void M_Set_Window_Position_Variable(S_Window_Position & );

		// ���N���b�N�̃t���O���Z�b�g����@�����F�N���b�N�̏��
		void M_Set_Left_Click_State(E_MOUSE_CLICK_STATE);

		// �E�N���b�N�̃t���O���Z�b�g����@�����F�N���b�N�̏��
		void M_Set_Right_Click_State(E_MOUSE_CLICK_STATE);

		// ���N���b�N�̃t���O���Z�b�g����@�����F�N���b�N�̏��
		void M_Set_Center_Click_State(E_MOUSE_CLICK_STATE);


		//-��- �Q�b�^ -��-//

		// OS�p�V�X�e���̃C���X�^���X�̃A�h���X��Ԃ�
		static C_OS_Management_System_Base * M_Get_Instance(void);

		// OS�̃V�X�e������~�������ǂ�����Ԃ�
		static bool M_Get_OS_Active(void);

		// �E�B���h�E�̃T�C�Y��Ԃ��@�߂�l�F�E�B���h�E�T�C�Y
		const S_Window_Size_Data & M_Get_Window_Size(void) const;

		// �E�B���h�E�̃A�X�y�N�g���Ԃ��@�߂�l�F�A�X�y�N�g��
		float M_Get_Aspect_Ratio(void) const;

		// �E�B���h�E�̍��W��Ԃ��@�߂�l�F�E�B���h�E���W
		const S_Window_Position & M_Get_Window_Position(void) const;

		// �}�E�X�̏�Ԃ�Ԃ��@�߂�l�F�}�E�X�̏��
		const S_Mouse_State & M_Get_Mouse_State(void) const;

		// ���݂̎��Ԃ̎Q�Ƃ�Ԃ��@�߂�l�F���݂̎��Ԃ̎Q��(const)
		const S_Day_And_Time_Inform & M_Get_Now_Day_And_Time(void) const;

		// �o�ߎ��Ԃ��~���b�P�ʂŎ擾����@�߂�l�F�擾��̎��ԕϐ��̎Q��
		unsigned __int64 M_Get_Now_Milli_Second_By_Start_Application(void) const;

		// �E�B���h�E�̃^�C�g������Ԃ��@�߂�l�F�E�B���h�E�^�C�g����
		std::wstring M_Get_Window_Title_Name(void) const;


		//-��- �E�B���h�E�@�\ -��-//

		// �E�B���h�E�̃^�C�g����ҏW����@�����F�Z�b�g����^�C�g����(const)
		virtual void M_Change_Window_Title(const std::wstring & ) = 0;

		// ���b�Z�[�W�{�b�N�X��\������@�����F�^�C�g��(const), �\�����e(const), ���b�Z�[�W�{�b�N�X�̎��
		virtual int M_Create_Massage_Box(const std::wstring &, const std::wstring &, unsigned int ) = 0;
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
