//����������������������������������������������//
// �ڍ�   �F�摜��\������UI�̃N���X�iUI�̃R���|�[�l���g�j
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_UIC_TEXT_BOX
#define D_INCLUDE_GUARD_C_UIC_TEXT_BOX


// �� �t�@�C���Ђ炫 �� //
#include <string>

#include "C_UI_Component_Base.h"
#include "C_Material_User.h"
#include "C_Object_Vertex_System.h"
#include "C_Vertex_Index_System.h"
#include "S_UI_Vertex.h"
#include "S_Rect.h"


// �� �l�[���X�y�[�X �� //

// UI�̃R���|�[�l���g���Ăяo�����߂̖��O
namespace GAME::UI_COMPONENT
{
	// �� �N���X �� //

	// �摜��\������UI�̃N���X
	class C_UIC_Text_Box : GAME::UI_COMPONENT::BASE::C_UI_Component_Base
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			ASSET::MATERIAL::C_Material_User material;	// �}�e���A��

			RENDERING::CAPSULE::C_Object_Vertex_System<DATA::VERTEX::S_UI_Vertex> vertex_system;	// UI�̒��_�p�̃V�X�e��

			RENDERING::CAPSULE::C_Vertex_Index_System index_system;	// ���_�C���f�b�N�X�V�X�e��

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_UIC_Text_Box(void);

		// �f�X�g���N�^
		~C_UIC_Text_Box(void);


		//-��- ���[�h -��-//

		// �w�肳�ꂽ���O�̃e�N�X�`�������[�h����@�����F���[�h����e�N�X�`����
		void M_Load_Texture(std::string);


		//-��- �X�V -��-//

		// �X�V���s��
		void M_Update(void) override;


		//-��- �`�� -��-//

		// �`����s��
		void M_Draw(void) override;


		//-��- ���W -��-//

		// UI�̍��W���Z�b�g����@�����F�Z�b�g�ʒu�̎l�p�`�i�������O�C�E�オ�P�j
		void M_Set_UI_Position(DATA::RECTSETTING::S_Rect);


		//-��- �J���[ -��-//

		// �F��ݒ肷��@�����F�F
		void M_Set_Color(DATA::COLOR::C_Color);
	};
}


#endif // !D_INCLUDE_GUARD_C_UIC_TEXT_BOX

