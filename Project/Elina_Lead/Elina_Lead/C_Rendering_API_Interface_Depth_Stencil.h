//����������������������������������������������//
// �ڍ�   �F�����_�����OAPI�̐[�x�X�e���V���p�V�X�e���̃C���^�[�t�F�[�X
// ����   �F�[�x�X�e���V���ɑ΂��铮��݂̂��܂Ƃ߂Ē񋟂���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_DEPTH_STECIL_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_DEPTH_STECIL_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>

#include "C_Rendering_Depth_Stencil_Buffer_Base.h"
#include "S_Create_Depth_Stencil_Buffer_Inform.h"


// �� �l�[���X�y�[�X �� //

// �����_�����OAPI�p�̃C���^�[�t�F�[�X���Ăяo�����߂̖��O
namespace RENDERING::API::RENDER_INTERFACE
{
	// �� �N���X �� //

	// �����_�����OAPI�̃����_�����O��ʃV�X�e���ւ̓�����s���N���X
	class C_Rendering_API_Interface_Depth_Stencil
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �֐� �� //

		//-��- ������ -��-//

		// �C���X�^���X���h�~�̂��߂ɃR���X�g���N�^�B�����č폜
		C_Rendering_API_Interface_Depth_Stencil(void) = delete;


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- ���� -��-//

		// �[�x�X�e���V���o�b�t�@�𐶐�����@�����F�ݒ��̐[�x�X�e���V���o�b�t�@�̎Q��, �[�x�X�e���V���o�b�t�@�𐶐����邽�߂̏��̎Q�Ɓiconst�j�@�߂�l�F�������̂�true
		static bool M_Create_Depth_Stencil_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & , const RENDERING::API::CREATE::S_Create_Depth_Stencil_Buffer_Inform & );


		//-��- ��� -��-//

		// �[�x�X�e���V���o�b�t�@�̍폜��ʒm����@�����F�폜���ꂽ�[�x�X�e���V���o�b�t�@�̃A�h���X�iconst�j
		static void M_Notice_Depth_Stencil_Buffer_Deleted(const RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base * );

		// �[�x�X�e���V���o�b�t�@�����Z�b�g����
		static void M_Reset_Draw_Depth_Stencil_Buffer(void);


		//-��- �N���A -��-//

		// �[�x�X�e���V���o�b�t�@���N���A����@�����F�N���A����[�x�X�e���V���o�b�t�@�̎Q��
		static void M_Clear_Depth_Stencil_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & );


		//-��- �`�� -��-//

		// �[�x�X�e���V���o�b�t�@��`��p�ɃZ�b�g����@�����F�ݒ肷��[�x�X�e���V���o�b�t�@�̎Q��
		static void M_Set_Depth_Stencil_Buffer_To_Rendering(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & );

		// �[�x�X�e���V���o�b�t�@��GPU�p���\�[�X�̃e�N�X�`���X���b�g�ɃZ�b�g�@�����F�ݒ��̃X���b�g�ԍ�, �ݒ肷��[�x�X�e���V���o�b�t�@�̎Q��
		static void M_Set_Depth_Stencil_Buffer_To_Texture_Slot(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & );
	};
}

#endif // !D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_DEPTH_STECIL_H_FILE
