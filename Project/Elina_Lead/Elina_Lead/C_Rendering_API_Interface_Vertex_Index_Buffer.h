//����������������������������������������������//
// �ڍ�   �F�����_�����OAPI�̒��_�C���f�b�N�X�o�b�t�@�p�V�X�e���̃C���^�[�t�F�[�X
// ����   �F���_�C���f�b�N�X�o�b�t�@�ɑ΂��铮��݂̂��܂Ƃ߂Ē񋟂���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_API_INTERFACE_INDEX_BUFFER_H_FILE
#define D_INCLUDE_GUARD_API_INTERFACE_INDEX_BUFFER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>

#include "C_Rendering_Index_Buffer_Setting_Inform_Base.h"
#include "S_Create_Index_Buffer_Inform.h"


// �� �l�[���X�y�[�X �� //

// �����_�����OAPI�p�̃C���^�[�t�F�[�X���Ăяo�����߂̖��O
namespace RENDERING::API::RENDER_INTERFACE
{
	// �� �N���X �� //

	// ���_�C���f�b�N�X�o�b�t�@�ւ̓�����s���N���X
	class C_Rendering_API_Interface_Vertex_Index_Buffer
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �֐� �� //

		//-��- ������ -��-//

		// �C���X�^���X���h�~�̂��߂ɃR���X�g���N�^�B�����č폜
		C_Rendering_API_Interface_Vertex_Index_Buffer(void) = delete;


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- ���� -��-//

		// ���_�C���f�b�N�X�f�[�^�p�̏��𐶐�����@�����F�ݒ��̒��_�C���f�b�N�X�o�b�t�@�̎Q��, ���_�C���f�b�N�X�o�b�t�@�����p�̏��̎Q�Ɓiconst�j
		static void M_Create_Index_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> &, const RENDERING::API::CREATE::S_Create_Index_Buffer_Inform & );


		//-��- �`�� -��-//

		// ���_�C���f�b�N�X�o�b�t�@�����Ɏw�肳�ꂽ���_�C���f�b�N�X�Ԃ̕`����s���@�����F�`�悷�钸�_�C���f�b�N�X�o�b�t�@�̎Q��, �`��J�n�ʒu�̒��_�C���f�b�N�X�ԍ�, �`��I���ʒu�̒��_�C���f�b�N�X�ԍ�
		static void M_Draw_By_Index_Buffer_By_Range(std::unique_ptr < RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & , int, int);

		// ���_�C���f�b�N�X�o�b�t�@�����ɕ`����s���@�����F�`�悷�钸�_�C���f�b�N�X�o�b�t�@�̎Q��
		static void M_Draw_By_Index_Buffer(std::unique_ptr < RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & );

		// ���_�C���f�b�N�X�o�b�t�@���Z�b�g����@�����F���_�C���f�b�N�X�f�[�^�ݒ�p���̎Q��
		static void M_Set_Index_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & );

		// �Z�b�g���ꂽ���_�C���f�b�N�X�o�b�t�@�����ɕ`����s��
		static void M_Draw_Command_By_Set_Index_Buffer(void);

		// �Z�b�g���ꂽ���_�C���f�b�N�X�o�b�t�@�����Ɏw�肳�ꂽ�C���f�b�N�X�Ԃ̕`����s���@�����F�`����J�n����C���f�b�N�X�ԍ�, �`��I���̃C���f�b�N�X�ԍ�
		static void M_Draw_Command_By_Set_Index_Buffer_By_Range(int, int);
	};
}


#endif // !D_INCLUDE_GUARD_API_INTERFACE_INDEX_BUFFER_H_FILE
