//����������������������������������������������//
// �ڍ�   �F�����_�����OAPI�̃e�X�N�`�����\�[�X�p�V�X�e���̃C���^�[�t�F�[�X
// ����   �F�e�X�N�`���o�b�t�@�ɑ΂��铮��݂̂��܂Ƃ߂Ē񋟂���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_TEXTURE_RESOURCE_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_TEXTURE_RESOURCE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <string>

#include "C_Rendering_Texture_Setting_Inform_Base.h"
#include "S_Create_Texture_Setting_Inform.h"
#include "C_Texture_Map.h"


// �� �l�[���X�y�[�X �� //

// �����_�����OAPI�p�̃C���^�[�t�F�[�X���Ăяo�����߂̖��O
namespace RENDERING::API::RENDER_INTERFACE
{
	// �� �N���X �� //

	// �����_�����OAPI�̃e�X�N�`�����\�[�X�ւ̓�����s���N���X
	class C_Rendering_API_Interface_Texture_Resource
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �֐� �� //

		//-��- ������ -��-//

		// �C���X�^���X���h�~�̂��߂ɃR���X�g���N�^�B�����č폜
		C_Rendering_API_Interface_Texture_Resource(void) = delete;


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- ���� -��-//

		// �e�X�N�`�����\�[�X�p�̏��𐶐�����@�����F�ݒ��̃e�X�N�`�����\�[�X�̎Q��, �e�X�N�`�����\�[�X�𐶐����邽�߂̏��̎Q�Ɓiconst�j�@�߂�l�F�������̂�true
		static bool M_Create_Texture_Resource(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Texture_Setting_Inform_Base> & , const RENDERING::API::CREATE::S_Create_Texture_Setting_Inform & );


		//-��- �`�� -��-//

		// �e�X�N�`�����\�[�X��`��p�ɃZ�b�g����@�����F�e�X�N�`�����\�[�X�p�`��ݒ�̎Q��
		static void M_Set_Texture_Resource_To_Draw(RENDERING::API::INSTANCE::S_Texture_Buffer_Drawing_Setting & );

		// �w�肳�ꂽ�ԍ��̃��\�[�X�X���b�g�Ƀe�X�N�`���f�[�^���Z�b�g����@�����F�Z�b�g����e�X�N�`�����\�[�X�̎Q��, �Z�b�g��̃��\�[�X�X���b�g�ԍ�
		static void M_Set_Texture_Resource_To_Draw_By_Slot_Index(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Texture_Setting_Inform_Base> & , int);


		//-��- ���[�h -��-//

		// �e�X�N�`�������[�h����@�����F���[�h����e�N�X�`���܂ł̃p�X, ���[�h��̃e�N�X�`���}�b�v�̎Q�Ɓ@�߂�l�F�������̂�true
		static bool M_Load_Texture(std::string, ASSET::TEXTURE::C_Texture_Map & );
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_TEXTURE_RESOURCE_H_FILE
