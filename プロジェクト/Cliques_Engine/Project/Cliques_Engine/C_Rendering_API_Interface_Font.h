//����������������������������������������������//
// �ڍ�   �F�����_�����OAPI�̃t�H���g�f�[�^�p�V�X�e���̃C���^�[�t�F�[�X
// ����   �F�t�H���g�ɑ΂��铮��݂̂��܂Ƃ߂Ē񋟂���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_FONT_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_FONT_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>

#include "C_Rendering_Font_Inform_Base.h"
#include "S_Create_Font_Data_Inform.h"
#include "S_Make_Font_To_Graph_Pakage.h"


// �� �l�[���X�y�[�X �� //

// �����_�����OAPI�p�̃C���^�[�t�F�[�X���Ăяo�����߂̖��O
namespace RENDERING::API::RENDER_INTERFACE
{
	// �� �N���X �� //

	// �����_�����OAPI�̃t�H���g�V�X�e���ւ̓�����s���N���X
	class C_Rendering_API_Interface_Font
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �֐� �� //

		//-��- ������ -��-//

		// �C���X�^���X���h�~�̂��߂ɃR���X�g���N�^�B�����č폜
		C_Rendering_API_Interface_Font(void) = delete;


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- ���[�h -��-//

		// �t�H���g���w�肳�ꂽ�t�H���g�������Ƀ��[�h����@�����F�ݒ��̃t�H���g�V�X�e���̎Q��, �t�H���g�𐶐����邽�߂̏��̎Q�Ɓiconst�j�@�߂�l�F�������̂�true
		static bool M_Load_Font(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Font_Inform_Base> & , const RENDERING::API::CREATE::S_Create_Font_Data_Inform & );


		//-��- �Z�b�^ -��-//

		// �n���ꂽ�������ɕ�������}�b�v�ɃZ�b�g����@�����F�t�H���g�f�[�^���e�N�X�`���}�b�v�Ɉڂ����߂̏��
		static void M_Set_Font_Map(PAKAGE::FONT::S_Make_Font_To_Graph_Package & );
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_FONT_H_FILE
