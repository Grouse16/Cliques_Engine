//����������������������������������������������//
// �ڍ�   �F�ό`���Ȃ����f���̃R���|�[�l���g�̃V�X�e��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_STATIC_MODEL_COMPONENT
#define D_INCLUDE_GUARD_C_STATIC_MODEL_COMPONENT


// �� �t�@�C���Ђ炫 �� //
#include <string>

#include "C_Component_Base.h"
#include "C_3D_Model_User.h"
#include "C_Transform.h"
#include "C_Material_User.h"


// �� �l�[���X�y�[�X �� //

// ���f���p�R���|�[�l���g���Ăяo�����߂̖��O
namespace GAME::COMPONENT::MODEL_COMPONENT
{
	// �� �N���X �� //

	// �ό`���Ȃ����f���̃R���|�[�l���g�N���X
	class C_Static_Model_Component : public GAME::COMPONENT::BASE::C_Component_Base
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			ASSET::MODEL::C_3D_Model_User model_system;	// 3D���f���V�X�e��
			
			MATH::C_Transform transform;	// ���f���̐ݒu�ʒu�i���[�J�����W�j

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Static_Model_Component(void);

		// �f�X�g���N�^
		~C_Static_Model_Component(void);


		//-��- ���[�h -��-//

		// �w�肳�ꂽ���O�̃��f�������[�h����@�����F���[�h���郂�f�����@�߂�l�F�������̂�true
		bool M_Load_Model_By_Name(std::string);


		//-��- �Q�b�^ -��-//

		// ���[�J�����W�̎Q�Ƃ�Ԃ��@�߂�l�F���[�J�����W�̎Q��
		MATH::C_Transform & M_Get_Transform(void);

		// ���f���V�X�e���̃A�h���X��Ԃ��@�߂�l�F���f���V�X�e���̃A�h���X
		ASSET::MODEL::C_3D_Model_User * M_Get_Model_Address(void);


		//-��- �`�� -��-//

		// �`����s��
		void M_Draw();
	};
}


#endif // !D_INCLUDE_GUARD_C_STATIC_MODEL_COMPONENT
