//����������������������������������������������//
// �ڍ�   �F�E�B���h�E�̐����p�̏����i�[����\����
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_S_CREATE_WINDOW_INFORMATION_H_FILE
#define D_INCLUDE_GUARD_S_CREATE_WINDOW_INFORMATION_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <string>

#include "S_Window_Position.h"
#include "S_Window_Size.h"


// �� �l�[���X�y�[�X �� //

// �E�B���h�E�p�̃f�[�^���Ăяo�����߂̖��O
namespace PLATFORM::WINDOW::CREATE
{
	// �� �\���� �� //

	// �E�B���h�E�̐����p�̏����i�[����\����
	struct S_Create_Window_Information
	{
		PLATFORM::WINDOW::DATA::S_Window_Position m_position;	// �������W
		
		PLATFORM::WINDOW::DATA::S_Window_Size m_size;	// �����T�C�Y

		std::wstring m_class_name = L"Default";	// �E�B���h�E�N���X��

		std::wstring m_name = L"Default";	// �E�B���h�E��

		std::wstring m_parent_name = L"Default";	// �e�E�B���h�E��

		std::wstring m_child_name = L"Default";	// �q�E�B���h�E��
	};
}



#endif // !D_INCLUDE_GUARD_S_CREATE_WINDOW_INFORMATION_H_FILE

