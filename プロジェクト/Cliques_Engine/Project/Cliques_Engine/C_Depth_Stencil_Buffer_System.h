//����������������������������������������������//
// �ڍ�   �F�[�x�X�e���V���o�b�t�@�̏����~���ɐݒ肵�A�����_�����O���邽�߂̃V�X�e��
// ����   �F�[�x�X�e���V���o�b�t�@�̃����_�����O���J�v�Z��������
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_DEPTH_STENCIL_BUFFER_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_DEPTH_STENCIL_BUFFER_SYSTEM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>

#include "C_Rendering_Depth_Stencil_Buffer_Base.h"
#include  "E_DEPTH_STENCIL_BUFFER_PIXEL_BYTE_FORMAT.h"


// �� �l�[���X�y�[�X �� //

// �`��Ɏg�p����V�X�e�����Ăяo�����߂̖��O
namespace RENDERING::CAPSULE
{
	// �� �N���X �� //

	// �[�x�X�e���V���o�b�t�@�p�̃V�X�e��
	class C_Depth_Stencil_Buffer_System
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��ϐ�
		struct SPr_Variable
		{
			std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> depth_stencil_buffer;	// �[�x�X�e���V���o�b�t�@�V�X�e��

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Depth_Stencil_Buffer_System(void);

		// �f�X�g���N�^
		~C_Depth_Stencil_Buffer_System(void);

		// ���������������
		void M_Release(void);


		//-��- ���[�h -��-//

		// �[�x�X�e���V���o�b�t�@�����[�h����@�����F�[�x�X�e���V���o�b�t�@�̃o�C�g�t�H�[�}�b�g�@�߂�l�F�������̂�true
		bool M_Load_Depth_Stencil_Buffer(RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_BYTE_FORMAT);


		//-��- �`�� -��-//

		// �[�x�X�e���V���o�b�t�@���N���A����
		void M_Clear_Depth_Stencil_Buffer(void);

		// �[�x�X�e���V���o�b�t�@���w�肳�ꂽ�e�N�X�`���X���b�g�ɃZ�b�g����@�����F�e�N�X�`���X���b�g�ԍ�
		void M_Set_Depth_Stencil_Buffer_To_Texture_Slot(int);

		// �[�x�X�e���V���o�b�t�@�������_�����O��Ƃ��Đݒ肷��
		void M_Set_Depth_Stencil_Buffer_To_Render_Target(void);
		
		// �[�x�X�e���V���o�b�t�@���e�N�X�`���ɕϊ�����@�����F�ݒ��̃e�N�X�`���̎Q��
		void M_Save_Depth_Stencil_Buffer_To_Texture(ASSET::TEXTURE::C_Texture_Map & );

		// �[�x�X�e���V���o�b�t�@�����C���̐[�x�X�e���V���o�b�t�@�ɖ߂�
		void M_Reset_Draw_Depth_Stencil_Buffer(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_DEPTH_STENCIL_BUFFER_SYSTEM_H_FILE

