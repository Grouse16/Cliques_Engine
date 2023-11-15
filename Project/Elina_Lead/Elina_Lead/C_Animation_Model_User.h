//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�������f�����g�p���邽�߂̃V�X�e��
// ����   �F�A�j���[�V�������f���}�l�[�W���[�Ƃ̑�����B�����A�ȒP�Ɏg�p�ł���悤�ɃJ�v�Z��������@�A�j���[�V�����̎��s���s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_MODEL_USER
#define D_INCLUDE_GUARD_C_ANIMATION_MODEL_USER


// �� �t�@�C���Ђ炫 �� //
#include <memory>

#include "C_3D_Animation_Model_System.h"
#include "C_Animation_Calculator_Base.h"


// �� �l�[���X�y�[�X �� //

// �A�j���[�V�������f�����g�p����V�X�e�����Ăяo�����߂̖��O
namespace ASSET::ANIMATION_MODEL
{
	// �� �N���X �� //

	// �A�j���[�V�������f�����g�p���邽�߂̃V�X�e��
	class C_Animation_Model_User
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			ASSET::ANIMATION_MODEL::C_3D_Animation_Model_System * animation_model = nullptr;	// �g�p����A�j���[�V�������f���܂ł̃A�h���X

			std::unique_ptr<ASSET::ANIMATION::CALCULATOR::C_Animation_Calculator_Base> animation_calculator = nullptr;	// �A�j���[�V�����̌v�Z�V�X�e��

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Animation_Model_User(void);

		// �f�X�g���N�^
		~C_Animation_Model_User(void);

		// �������̉�����s��
		void M_Release(void);


		//-��- ���[�h -��-//

		// �w�肳�ꂽ���O�̃A�j���[�V�������f����ǂݍ��ށ@�����F���[�h����A�j���[�V�������f����
		void M_Load_Animation_Model(std::string);


		//-��- �X�V -��-//

		// �A�j���[�V�����̍X�V���s��
		void M_Animation_Update(void);


		//-��- �`�� -��-//

		// ���̃A�j���[�V�������f����`�悷��
		void M_Animation_Model_Draw(void);


		//-��- �Q�b�^ -��-//

		// ���݂̃A�j���[�V�������f����Ԃ��@�߂�l�F���݂̃A�j���[�V�������f���ւ̃A�h���X
		ASSET::ANIMATION_MODEL::C_3D_Animation_Model_System * M_Get_Animation_Model_Address(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_MODEL_USER
