//����������������������������������������������//
// �ڍ�   �F�����_�����OAPI�̒萔���\�[�X�p�V�X�e���̃C���^�[�t�F�[�X
// ����   �F�萔�o�b�t�@�ɑ΂��铮��݂̂��܂Ƃ߂Ē񋟂���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_CONSTANT_RESOURCE_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_CONSTANT_RESOURCE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>

#include "C_Rendering_Constant_Buffer_Setting_Inform_Base.h"
#include "S_Create_Constant_Buffer_Inform.h"


// �� �l�[���X�y�[�X �� //

// �����_�����OAPI�p�̃C���^�[�t�F�[�X���Ăяo�����߂̖��O
namespace RENDERING::API::RENDER_INTERFACE
{
	// �� �N���X �� //

	// �����_�����OAPI�̒萔�o�b�t�@�ւ̓�����s���N���X
	class C_Rendering_API_Interface_Constant_Resource
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �֐� �� //

		//-��- ������ -��-//

		// �C���X�^���X���h�~�̂��߂ɃR���X�g���N�^�B�����č폜
		C_Rendering_API_Interface_Constant_Resource(void) = delete;


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- ���� -��-//

		// �萔���\�[�X�p�̏��𐶐�����@�����F�ݒ��̒萔���\�[�X�̎Q��, �萔���\�[�X�𐶐����邽�߂̏��̎Q�Ɓiconst�j
		static void M_Create_Constant_Resource(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Constant_Buffer_Setting_Inform_Base> & , const RENDERING::API::CREATE::S_Create_Constant_Buffer_Inform & );

		
		//-��- �`�� -��-//

		// �萔���\�[�X��`��p�ɃZ�b�g����@�����F�萔���\�[�X�p�`��ݒ�̎Q��
		static void M_Set_Constant_Resource_To_Draw(RENDERING::API::INSTANCE::S_Constant_Buffer_Drawing_Setting & );

		// �w�肳�ꂽ�ԍ��̃��\�[�X�X���b�g�ɒ萔�f�[�^���Z�b�g����@�����F�Z�b�g����萔���\�[�X�̎Q��, �Z�b�g��̃��\�[�X�X���b�g�ԍ�
		static void M_Set_Constant_Resource_To_Draw_By_Slot_Index(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Constant_Buffer_Setting_Inform_Base> & , int);
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_CONSTANT_RESOURCE_H_FILE
