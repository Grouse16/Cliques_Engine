//����������������������������������������������//
// �ڍ�   �F3D���f�����g�p���邽�߂̃V�X�e��
// ����   �F3D���f���g�p����3D���f������V�X�e���Ƃ̘A�����ȗ�������
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_3D_MODEL_USER_H_FILE
#define D_INCLUDE_GUARD_C_3D_MODEL_USER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_3D_Model_System.h"


// �� �l�[���X�y�[�X �� //

// 3D���f���p�̃V�X�e�����Ăяo�����߂̖��O
namespace ASSET::MODEL
{
	// �� �N���X �� //

	// 3D���f�����g�p���邽�߂̃V�X�e��
	class C_3D_Model_User
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			ASSET::MODEL::C_3D_Model_System * use_model_address = nullptr;	// �g�p���郂�f���܂ł̃A�h���X

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �v���C�x�[�g ��==//
	private:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_3D_Model_User(void);

		// �f�X�g���N�^
		~C_3D_Model_User(void);

		// �}�e���A�����������
		void M_Release(void);


		//-��- ���[�h -��-//

		// �w�肳�ꂽ���O��3D���f����ǂݍ��ށ@�����F���[�h����3D���f����
		void M_Load_3D_Model(std::string);


		//-��- �`�� -��-//

		// 3D���f����`�悷��
		void M_Draw_3D_Model(void);

		// �w�肳�ꂽ���O�̃��b�V���̂ݕ`�悷��@�����F�`�悷�郁�b�V����
		void M_Draw_3D_Model_Meshes_By_Mesh_Name(std::string);


		//-��- �Q�b�^ -��-//

		// ���݂�3D���f����Ԃ��@�߂�l�F���݂�3D���f���ւ̃A�h���X
		C_3D_Model_System * M_Get_3D_Model_Address(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_3D_MODEL_USER_H_FILE