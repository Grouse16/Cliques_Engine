//����������������������������������������������//
// �ڍ�   �F�����_�����O�X�N���[���𐶐����邽�߂̏��̃V�X�e��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_S_CREATE_RENDER_SCREEN_INFORM
#define D_INCLUDE_GUARD_S_CREATE_RENDER_SCREEN_INFORM


// �� �t�@�C���Ђ炫 �� //
#include "E_RENDERING_SCREEN_FORMAT.h"
#include "E_SCREEN_TEXTURE_SETTING.h"


// �� �l�[���X�y�[�X �� //

// �O���t�B�b�N�𐧌䂷��V�X�e���̏��𐶐����邽�߂̏����Ăяo�����߂̖��O
namespace RENDERING::API::CREATE
{
	// �� �\���� �� //

	// �����_�����O�X�N���[���𐶐����邽�߂̏��̃V�X�e��
	struct S_Create_Render_Screen_Inform
	{
		RENDERING::INFORM::RENDERING_SCREEN::E_RENDERING_SCREEN_FORMAT m_rendering_screen_format = RENDERING::INFORM::RENDERING_SCREEN::E_RENDERING_SCREEN_FORMAT::e_2_BYTE;	// �����_�����O�摜�̉�f�̌^

		RENDERING::API::CREATE::E_SCREEN_TEXTURE_SETTING m_screen_texture_setting = RENDERING::API::CREATE::E_SCREEN_TEXTURE_SETTING::e_TEXTURE_2D;	// �����_�����O�摜�̃e�N�X�`���̐ݒ�

		int m_screen_buffer_sum = 1;		// ��������X�N���[���o�b�t�@��
	};
}

#endif // !D_INCLUDE_GUARD_S_CREATE_RENDER_SCREEN_INFORM

