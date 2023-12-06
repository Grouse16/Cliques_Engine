//����������������������������������������������//
// �ڍ�   �F�[�x�X�e���V���o�b�t�@�̒��ۉ����C���[�ƂȂ���N���X
// ����   �F�h���N���X�͐[�x�X�e���V���o�b�t�@�����悤���鎞�ɁA�e�����_�����OAPI���ƂɕK�v�ȏ������N���X�Ƃ��č쐬����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_RENDERING_DEPTH_STENCIL_BUFFER_BASE_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_DEPTH_STENCIL_BUFFER_BASE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_Texture_Map.h"


// �� �l�[���X�y�[�X �� //

// �O���t�B�b�N�𐧌䂷��V�X�e���̏����Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS::INSTANCE
{
	// �� �N���X �� //

	// �[�x�X�e���V���o�b�t�@�̒��ۉ����C���[�ƂȂ���N���X
	class C_Rendering_Depth_Stencil_Buffer_Base
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Rendering_Depth_Stencil_Buffer_Base(void);
		
		// �f�X�g���N�^
		virtual ~C_Rendering_Depth_Stencil_Buffer_Base(void);

		// �������̉��
		virtual void M_Release(void) = 0;


		//-��- �摜 -��-//

		// �[�x�X�e���V���o�b�t�@��ʂ��e�N�X�`���摜�Ƃ��ĕۑ�����@�����F�ۑ���̃e�N�X�`����ʂ̎Q�Ɓ@�߂�l�F�������̂�true
		virtual bool M_Save_Screen_For_Texture(ASSET::TEXTURE::C_Texture_Map & ) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_DEPTH_STENCIL_BUFFER_BASE_H_FILE

