//����������������������������������������������//
// �ڍ�   �F3D���f���𐧌䂷�邽�߂̃N���X
// ����   �F3D���f�������d�Ń��[�h����Ȃ��悤�ɁA���[�h�ƃ������̉�����Ǘ�����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_3D_MODEL_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_3D_MODEL_MANAGER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>
#include <memory>

#include "C_3D_Model_System.h"


// �� �l�[���X�y�[�X �� //

// 3D���f���̐���p�V�X�e�����Ăяo�����߂̖��O
namespace ASSET::MODEL::MANAGER
{
	// �� �N���X �� //

	// 3D���f���𐧌䂷�邽�߂̃N���X
	class C_3D_Model_Manager
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �\���� �� //

		// 3D���f�����Ǘ����邽�߂̏��̍\����
		struct S_3D_Model_Inform
		{
			std::unique_ptr<ASSET::MODEL::C_3D_Model_System> model_data;	// ���f���̃f�[�^

			std::string name = "default";	// ����3D���f����

			int user_sum = 0;	// ����3D���f�����g�p����C���X�^���X��
		};


		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::vector <S_3D_Model_Inform> model_list;	// 3D���f���p�̃��X�g

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O

		static C_3D_Model_Manager m_this;	// ���N���X�̃C���X�^���X�i�V���O���g�����j


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^�A�V���O���g��������
		C_3D_Model_Manager(void);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �I���� -��-//

		// �f�X�g���N�^
		~C_3D_Model_Manager(void);

		// ���������������
		static void M_Release(void);


		//-��- �Q�b�^ -��-//

		// �w�肳�ꂽ3D���f����Ԃ��@�����F3D���f���̖��O�@�߂�l�F�w�肳�ꂽ3D���f���f�[�^�ւ̃A�h���X�A�Ȃ����nullptr��Ԃ�
		static ASSET::MODEL::C_3D_Model_System * M_Get_3D_Model_By_Name(std::string);


		//-��- ���[�h -��-//

		// 3D���f��������3D���f�������[�h����@�����F3D���f�����@�߂�l�F��������3D���f���f�[�^�ւ̃A�h���X
		static ASSET::MODEL::C_3D_Model_System * M_Load_3D_Model_By_Name(std::string);


		//-��- �폜 -��-//

		// �w�肳�ꂽ3D���f���ݒ�̏��L����������邱�Ƃ�ʒm����@�����F���L�����������3D���f���ݒ�̃A�h���X�̎Q��
		static void M_Release_3D_Model(ASSET::MODEL::C_3D_Model_System * &);
	};
}


#endif // !D_INCLUDE_GUARD_C_3D_MODEL_MANAGER_H_FILE


