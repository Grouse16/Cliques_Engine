//����������������������������������������������//
// �ڍ�   �F3D�A�j���[�V���������郂�f�����Ǘ�����V�X�e��
// ����   �F�����A�j���[�V�������f���̑��d���[�h��h���A���O�ɂ�郂�f���̊Ǘ����s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_MODEL_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_MODEL_MANAGER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>
#include <vector>

#include "C_Animation_Model_System.h"


// �� �l�[���X�y�[�X �� //

// �A�j���[�V�������f�����Ăяo�����߂̖��O
namespace ASSET::ANIMATION_MODEL::MANAGER
{
	// �� �N���X �� //

	// 3D�A�j���[�V���������郂�f�����Ǘ�����V�X�e��
	class C_Animation_Model_Manager
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �\���� �� //

		// �A�j���[�V�������郂�f���̊Ǘ��p�̏��̍\����
		struct S_Animation_Model_Inform
		{
			std::unique_ptr<ASSET::ANIMATION_MODEL::C_Animation_Model_System> animation_model = nullptr;	// �A�j���[�V�������f��

			std::string name = "DEFAULT";	// �A�j���[�V�������f����

			int user_sum = 0;	// ���̃A�j���[�V�������f�����g�p���Ă���C���X�^���X��
		};


		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::vector<S_Animation_Model_Inform> animation_model_inform_list;	// �A�j���[�V�������f�����̃��X�g

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O

		static C_Animation_Model_Manager m_this;	// �A�j���[�V�������f������p�V�X�e���̃V���O���g�����p�C���X�^���X


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^�A�V���O���g��������
		C_Animation_Model_Manager(void);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �I���� -��-//

		// �f�X�g���N�^
		~C_Animation_Model_Manager(void);

		// ���������������
		static void M_Release(void);


		//-��- �Q�b�^ -��-//

		// �w�肳�ꂽ�A�j���[�V�������f����Ԃ��@�����F�T���A�j���[�V�������f���̖��O�@�߂�l�F�w�肳�ꂽ�A�j���[�V�������f���ւ̃A�h���X�A�Ȃ����nullptr��Ԃ�
		static ASSET::ANIMATION_MODEL::C_Animation_Model_System * M_Get_Animation_Model_By_Name(std::string);


		//-��- ���[�h -��-//

		// �A�j���[�V�������f��������A�j���[�V�������f�������[�h����@�����F���[�h����A�j���[�V�������f�����@�߂�l�F���������A�j���[�V�������f���ւ̃A�h���X
		static ASSET::ANIMATION_MODEL::C_Animation_Model_System * M_Load_Animation_Model_By_Name(std::string);


		//-��- �폜 -��-//

		// �w�肳�ꂽ�A�j���[�V�������f���̏��L����������邱�Ƃ�ʒm����@�����F���L�����������A�j���[�V�������f���̃A�h���X�̎Q��
		static void M_Release_Animation_Model(ASSET::ANIMATION_MODEL::C_Animation_Model_System * &);
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_MODEL_MANAGER_H_FILE

