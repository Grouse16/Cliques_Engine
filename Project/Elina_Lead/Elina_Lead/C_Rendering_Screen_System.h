//����������������������������������������������//
// �ڍ�   �F�����_�����O�摜���~���ɐݒ肵�A�g�p���邽�߂̃V�X�e��
// ����   �F�����_�����OAPI�Ƃ̘A�g��A���G�Ȓ��ۉ����C���[�̃V�X�e���̃J�v�Z�������s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#ifndef D_INCLUDE_GUARD_C_RENDERING_SCREEN_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_SCREEN_SYSTEM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>

#include "C_Rendering_Screen_System_Base.h"
#include "E_RENDERING_SCREEN_FORMAT.h"
#include "E_SCREEN_TEXTURE_SETTING.h"


// �� �l�[���X�y�[�X �� //

// �`��Ɏg�p����V�X�e�����Ăяo�����߂̖��O
namespace RENDERING::CAPSULE
{
	// �� �N���X �� //

	// �����_�����O��ʂ��g�p���邽�߂̃V�X�e��
	class C_Rendering_Screen_System
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::unique_ptr<RENDERING::GRAPHICS::INSTANCE::C_Rendering_Screen_System_Base> rendering_screen;	// �����_�����O���

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Rendering_Screen_System(void);

		// �f�X�g���N�^
		~C_Rendering_Screen_System(void);

		// �����_�����O��ʂ��폜����
		void M_Release(void);


		//-��- ���� -��-//

		// �����_�����O��ʂ𐶐�����@�����F��ʐ�, ��ʂ̃o�C�g��, ��ʂ̃e�N�X�`���ݒ�@�߂�l�F�������̂�true
		bool M_Create_Rendering_Screen(int, RENDERING::INFORM::RENDERING_SCREEN::E_RENDERING_SCREEN_FORMAT, RENDERING::GRAPHICS::CREATE::E_SCREEN_TEXTURE_SETTING);


		//-��- �e�N�X�`�� -��-//

		// �����_�����O��ʂ��e�N�X�`���摜�Ƃ��ĕۑ�����@�����F�����_�����O��ʔԍ�, �ۑ���̃e�N�X�`����ʂ̎Q��
		void M_Save_Screen_For_Texture(int, ASSET::TEXTURE::C_Texture_Map & );


		//-��- �`�� -��-//

		// �����_�����O�摜�������_�����O��Ƃ��Đݒ肷��@�����F�����_�����O��Ƃ��郌���_�����O�摜�ԍ�
		void M_Set_Render_Target(int);

		// ��ʂ��N���A����
		void M_Clear_Screen(void);

		// �w�肵����ʂ݂̂��N���A����@�����F�N���A�����ʔԍ�
		void M_Clear_Screen_By_Number(int);

		// �w�肳�ꂽ�e�N�X�`���̃X���b�g�ԍ��Ƀ����_�����O��ʂ̉摜���Z�b�g����@�����F�Z�b�g�����ʔԍ�, �Z�b�g����X���b�g�ԍ�
		void M_Set_Rendering_Screen_To_Texture_Slot(int, int);
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_SCREEN_SYSTEM_H_FILE

