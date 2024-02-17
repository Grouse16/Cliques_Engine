//����������������������������������������������//
// �ڍ�   �F�����_�����OAPI�̃����_�����O�ݒ�̃C���^�[�t�F�[�X
// ����   �F�����_�����O�ݒ�ɑ΂��铮��݂̂��܂Ƃ߂Ē񋟂���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_RENDERING_SETTING_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_RENDERING_SETTING_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>

#include "C_Rendering_Graphics_Setting_Inform_Base.h"
#include "S_Create_Rendering_Graphics_Setting_Inform.h"


// �� �l�[���X�y�[�X �� //

// �����_�����OAPI�p�̃C���^�[�t�F�[�X���Ăяo�����߂̖��O
namespace RENDERING::API::RENDER_INTERFACE
{
	// �� �N���X �� //

	// �����_�����OAPI�̃����_�����O�ݒ�ւ̓�����s���N���X
	class C_Rendering_API_Interface_Rendering_Setting
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �֐� �� //

		//-��- ������ -��-//

		// �C���X�^���X���h�~�̂��߂ɃR���X�g���N�^�B�����č폜
		C_Rendering_API_Interface_Rendering_Setting(void) = delete;


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- ���� -��-//

		// �����_�����O�ݒ�̐����@�����F�ݒ��̃����_�����O�ݒ�̎Q��, �����p�̏��̎Q�Ɓiconst�j�@�߂�l�F�������̂�true
		static bool M_Create_Rendering_Setting(std::unique_ptr <RENDERING::API::INSTANCE::C_Rendering_Graphics_Setting_Inform_Base> & , const RENDERING::API::CREATE::S_Create_Rendering_Graphics_Setting_Inform & );


		//-��- �`�� -��-//

		// �����_�����O�ݒ��`��p�ɃZ�b�g����@�����F�Z�b�g���郌���_�����O�ݒ�̎Q��
		static void M_Set_Rendering_Setting_To_Draw(std::unique_ptr <RENDERING::API::INSTANCE::C_Rendering_Graphics_Setting_Inform_Base> & );
	};
}

#endif // !D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_RENDERING_SETTING_H_FILE
