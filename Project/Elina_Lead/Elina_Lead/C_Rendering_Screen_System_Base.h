//����������������������������������������������//
// �ڍ�   �F�����_�����O�X�N���[���i�����_�����O��摜�j�̃f�[�^��ێ�����V�X�e���̊��N���X
// ����   �F�������ރ����_�����O��摜�̐ݒ��A�����_�����O��摜���摜�ɕϊ��܂��̓V�F�[�_�[�ɂ��摜�Ƃ��Ă̎g�p�����邽�߂̃����_�����O��摜���Ǘ�����
// �쐬�� �F���◴��
//����������������������������������������������//

 
// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_RENDERING_SCREEN_SYSTEM_BASE_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_SCREEN_SYSTEM_BASE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_Texture_Map.h"


// �� �l�[���X�y�[�X �� //

// �O���t�B�b�N�𐧌䂷��V�X�e���̏����Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS::INSTANCE
{
	// �� �N���X �� //

	// �����_�����O�X�N���[���i�����_�����O��摜�j�̃f�[�^��ێ�����V�X�e���̊��N���X
	class C_Rendering_Screen_System_Base
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Rendering_Screen_System_Base(void);

		// �f�X�g���N�^
		virtual ~C_Rendering_Screen_System_Base(void);

		// �������̉��
		virtual void M_Release(void) = 0;


		//-��- �摜 -��-//

		// �w�肳�ꂽ�ԍ��̃����_�����O��ʂ��e�N�X�`���摜�Ƃ��ĕۑ�����@�����F�����_�����O��ʔԍ�, �ۑ���̃e�N�X�`����ʂ̎Q�Ɓ@�߂�l�F�������̂�true
		virtual bool M_Save_Screen_For_Texture(int, ASSET::TEXTURE::C_Texture_Map & ) = 0;


		//-��- �Q�b�^ -��-//

		// �����_�����O��ʐ���Ԃ��@�߂�l�F�����_�����O��ʐ�
		virtual int M_Get_Rendering_Screen_Sum(void) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_SCREEN_SYSTEM_BASE_H_FILE

