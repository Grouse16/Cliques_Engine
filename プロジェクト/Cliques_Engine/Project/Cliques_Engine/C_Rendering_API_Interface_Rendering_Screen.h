//����������������������������������������������//
// �ڍ�   �F�����_�����OAPI�̃����_�����O��ʗp�V�X�e���̃C���^�[�t�F�[�X
// ����   �F�����_�����O��ʂɑ΂��铮��݂̂��܂Ƃ߂Ē񋟂���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_RENDERING_SCREEN_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_RENDERING_SCREEN_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>

#include "C_Rendering_Screen_Data_Base.h"
#include "S_Create_Render_Screen_Inform.h"
#include "C_Texture_Map.h"


// �� �l�[���X�y�[�X �� //

// �����_�����OAPI�p�̃C���^�[�t�F�[�X���Ăяo�����߂̖��O
namespace RENDERING::API::RENDER_INTERFACE
{
	// �� �N���X �� //

	// �����_�����OAPI�̃����_�����O��ʃV�X�e���ւ̓�����s���N���X
	class C_Rendering_API_Interface_Rendering_Screen
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �֐� �� //

		//-��- ������ -��-//

		// �C���X�^���X���h�~�̂��߂ɃR���X�g���N�^�B�����č폜
		C_Rendering_API_Interface_Rendering_Screen(void) = delete;


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- ���� -��-//

		// �����_�����O��ʃV�X�e���̉���@�����F�ݒ��̃����_�����O��ʂ̎Q��, �����_�����O��ʂ𐶐����邽�߂̏��̎Q�Ɓiconst�j�@�߂�l�F�������̂�true
		static bool M_Create_Rendering_Screen(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & , const RENDERING::API::CREATE::S_Create_Render_Screen_Inform & );


		//-��- ��� -��-//

		// �����_�����O��ʂ̍폜��ʒm����@�����F�폜���ꂽ�����_�����O��ʂ̃A�h���X�iconst�j
		static void M_Notice_Rendering_Screen_Deleted(const RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base * );


		//-��- �N���A -��-//

		// �����_�����O��ʂ̃N���A����@�����F�N���A���郌���_�����O��ʔԍ�, �N���A���郌���_�����O��ʃV�X�e���̎Q��
		static void M_Clear_Rendering_Screen(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & );


		//-��- �`�� -��-//

		// �w�肳�ꂽ�����_�����O��ʂ�`���ɃZ�b�g�@�����F�ݒ��̃����_�����O��ʂ̎Q��
		static void M_Set_Rendering_Screen_To_Draw_Screen(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & );

		// ���C���̃����_�����O��ʂ�`���ɂ���
		static void M_Set_Main_Rendering_Screen_To_Draw(void);

		// �w�肳�ꂽ�����_�����O��ʂ��e�N�X�`�����\�[�X�X���b�g�ɃZ�b�g�@�����F�ݒ��̃X���b�g�ԍ�, �ݒ肷���ʂ̔ԍ�, �ݒ��̃����_�����O��ʂ̎Q��
		static void M_Set_Rendering_Screen_To_Texture_Resource_Slot(int, int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & );

		// ���C���̕\�����̃����_�����O��ʂ��w�肳�ꂽ�e�N�X�`���X���b�g�ɃZ�b�g����@�����F�ݒ��̃e�N�X�`���̃X���b�g�ԍ�
		static void M_Set_Main_Front_Rendering_Screen_To_Texture_Slot(int);

		// ���C���̕`�揑�����ݒ��̃����_�����O��ʂ��w�肳�ꂽ�e�N�X�`���X���b�g�ɃZ�b�g����@�����F�ݒ��̃e�N�X�`���̃X���b�g�ԍ�
		static void M_Set_Main_Back_Rendering_Screen_To_Texture_Slot(int);


		//-��- �e�N�X�`�� -��-//

		// �w�肳�ꂽ�����_�����O��ʂ̃f�[�^���e�N�X�`���Ɉڂ��@�����F�ݒ肷�郌���_�����O��ʔԍ�, �����_�����O��ʃV�X�e���̎Q��, �ݒ��̃e�N�X�`���̎Q��
		static void M_Save_Rendering_Screen_To_Texture(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & , ASSET::TEXTURE::C_Texture_Map & );

		// ���C���̃����_�����O��ʂ̃f�[�^���e�N�X�`���Ɉڂ��@�����F�ݒ��̃e�N�X�`���̎Q��
		static void M_Save_Main_Rendering_Screen_To_Texture(ASSET::TEXTURE::C_Texture_Map & );


		//-��- ���\�[�X�ݒ� -��-//

		// �����_�����O��ʂ̃f�[�^��ǂݎ��\�ɂ���@�����F�ݒ肷�郌���_�����O��ʔԍ�, �����_�����O��ʃV�X�e���̎Q��
		static void M_Set_Rendering_Screen_Can_Readable(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & );
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_RENDERING_SCREEN_H_FILE
