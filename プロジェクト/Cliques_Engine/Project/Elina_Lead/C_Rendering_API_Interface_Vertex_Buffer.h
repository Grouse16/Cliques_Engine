//����������������������������������������������//
// �ڍ�   �F�����_�����OAPI�̒��_�o�b�t�@�p�V�X�e���̃C���^�[�t�F�[�X
// ����   �F���_�o�b�t�@�ɑ΂��铮��݂̂��܂Ƃ߂Ē񋟂���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_VERTEX_BUFFER_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_VERTEX_BUFFER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>

#include "C_Rendering_Vertex_Buffer_Setting_Inform_Base.h"
#include "S_Create_Vertex_Buffer_Inform.h"


// �� �l�[���X�y�[�X �� //

// �����_�����OAPI�p�̃C���^�[�t�F�[�X���Ăяo�����߂̖��O
namespace RENDERING::API::RENDER_INTERFACE
{
	// �� �N���X �� //

	// �����_�����OAPI�̒��_�o�b�t�@�ւ̓�����s���N���X
	class C_Rendering_API_Interface_Vertex_Buffer
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �֐� �� //

		//-��- ������ -��-//

		// �C���X�^���X���h�~�̂��߂ɃR���X�g���N�^�B�����č폜
		C_Rendering_API_Interface_Vertex_Buffer(void) = delete;


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- ���� -��-//

		// ���_�f�[�^�p�̏��𐶐�����@�����F�ݒ��̒��_�o�b�t�@�̎Q��,�@�������邽�߂̏��̎Q�Ɓiconst�j
		static void M_Create_Vertex_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & , const RENDERING::API::CREATE::S_Create_Vertex_Buffer_Inform & );


		//-��- �`�� -��-//

		// ���_�f�[�^��`��p�ɃZ�b�g����@�����F�Z�b�g���钸�_�o�b�t�@
		static void M_Set_Vertex_Buffer_To_Draw(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & );

		// ���_�o�b�t�@�����ɕ`������s����@�����F�`�悷�钸�_�o�b�t�@
		static void M_Draw_By_Vertex_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & );
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_VERTEX_BUFFER_H_FILE
