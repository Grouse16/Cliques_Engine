//����������������������������������������������//
// �ڍ�   �F�E�B���h�E�̋������`����C���^�[�t�F�[�X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_I_WINDOW_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_I_WINDOW_SYSTEM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <string>

#include "S_Window_Position.h"
#include "S_Window_Size.h"
#include "E_OS_KIND.h"


// �� �l�[���X�y�[�X �� //

// �E�B���h�E�p�̃C���^�[�t�F�[�X���Ăяo�����߂̖��O
namespace PLATFORM::WINDOW::INTERFACE
{
	// �� �N���X �� //

	// �E�B���h�E�̋������`����C���^�[�t�F�[�X
	class I_Window_System
	{
	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �R���X�g���N�^�ƃf�X�g���N�^ -��-//

		// �R���X�g���N�^
		I_Window_System(void) = default;

		// �f�X�g���N�^
		virtual ~I_Window_System(void) = default;


		//-��- ���� -��-//

		// �E�B���h�E�̐����@�߂�l�F�����ɐ���������
		virtual bool M_Create_Window(void) = 0;

		
		//-��- ������ -��-//

		// �E�B���h�E�̏������@�߂�l�F�������ɐ���������
		virtual bool M_Init_Window(void) = 0;

		
		//-��- �폜 -��-//

		// �E�B���h�E�̍폜�@�߂�l�F�폜�ɐ���������
		virtual bool M_Delete_Window(void) = 0;


		//-��- �X�V -��-//

		// �E�B���h�E�̍X�V�@�߂�l�F�X�V�ɐ���������
		virtual bool M_Update_Window(void) = 0;


		//-��- �L���Ɩ��� -��-//

		// �E�B���h�E��L���ɂ���@�߂�l�F�L���ɐ���������
		virtual bool M_Enable_Window(void) = 0;

		// �E�B���h�E�𖳌��ɂ���@�߂�l�F�����ɐ���������
		virtual bool M_Disable_Window(void) = 0;


		//-��- �\�� -��-//

		// �E�B���h�E��\�ɏo���@�߂�l�F�\�ɏo���̂ɐ���������
		virtual bool M_Bring_To_Front_Window(void) = 0;

		// �E�B���h�E��\������@�߂�l�F�\���ɐ���������
		virtual bool M_Show_Window(void) = 0;

		// �E�B���h�E���\���ɂ���@�߂�l�F��\���ɐ���������
		virtual bool M_Hide_Window(void) = 0;


		//-��- �g���k�� -��-//

		// �E�B���h�E���g������@�߂�l�F�g���ɐ���������
		virtual bool M_Expand_Window(void) = 0;

		// �E�B���h�E���k������@�߂�l�F�k���ɐ���������
		virtual bool M_Shrink_Window(void) = 0;


		//-��- �Z�b�^ -��-//

		// �E�B���h�E�̍��W��ݒ肷��@�����F�E�B���h�E�̍��W
		virtual void M_Set_Window_Position(const PLATFORM::WINDOW::DATA::S_Window_Position & ) = 0;

		// �E�B���h�E�̃T�C�Y��ݒ肷��@�����F�E�B���h�E�̃T�C�Y
		virtual void M_Set_Window_Size(const PLATFORM::WINDOW::DATA::S_Window_Size & ) = 0;

		// �E�B���h�E����ݒ肷��@�����F�E�B���h�E��
		virtual void M_Set_Window_Name(const std::wstring & ) = 0;


		//-��- �Q�b�^ -��-//

		// �E�B���h�E�̃v���b�g�t�H�[���������f�[�^��Ԃ��@�߂�l�F�v���b�g�t�H�[���������f�[�^
		virtual PLATFORM::E_OS_KIND M_Get_Platform(void) = 0;

		// �E�B���h�E���ʗp�̃f�[�^��Ԃ��@�߂�l�F�E�B���h�E���ʗp�̃f�[�^
		virtual void * M_Get_Window_Handle(void) = 0;

		// �E�B���h�E�̍��W��Ԃ��@�߂�l�F�E�B���h�E�̍��W
		virtual const PLATFORM::WINDOW::DATA::S_Window_Position & M_Get_Window_Position(void) = 0;

		// �E�B���h�E�̃T�C�Y��Ԃ��@�߂�l�F�E�B���h�E�̃T�C�Y
		virtual const PLATFORM::WINDOW::DATA::S_Window_Size & M_Get_Window_Size(void) = 0;

		// �E�B���h�E����Ԃ��@�߂�l�F�E�B���h�E��
		virtual const std::wstring & M_Get_Window_Name(void) = 0;

		// �E�B���h�E���L������Ԃ��@�߂�l�F�E�B���h�E���L�����ǂ���
		virtual bool M_Is_Window_Enable(void) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_I_WINDOW_SYSTEM_H_FILE
