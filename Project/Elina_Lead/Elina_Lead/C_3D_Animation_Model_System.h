//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�������f���̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_3D_ANIMATION_MODEL_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_3D_ANIMATION_MODEL_SYSTEM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_Animative_Mesh.h"
#include "S_Bone_Inform.h"


// �� �l�[���X�y�[�X �� //

// �A�j���[�V�����ł���3D���f�����Ăяo�����߂̖��O
namespace ASSET::ANIMATION::MODEL
{
	// �� �N���X �� //

	// �A�j���[�V�������f���̃V�X�e��
	class C_3D_Animation_Model_System
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �\���� �� //

		// ���b�V�����Ǘ����邽�߂̃f�[�^�̍\����
		struct S_Animative_Mesh_Data_Inform
		{
			std::unique_ptr<ASSET::ANIMATION::MESH::C_Animative_Mesh> mesh_data = nullptr;	// ���b�V���f�[�^

			std::string name = "default";	// ���b�V����
		};


		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::vector<S_Animative_Mesh_Data_Inform> mesh_inform_list;	// ���b�V���̊Ǘ��p��񃊃X�g

			std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> bone_list;	// �{�[���̃��X�g

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_3D_Animation_Model_System(void);

		//�f�X�g���N�^
		~C_3D_Animation_Model_System(void);

		// �������̉�����s��
		void M_Release(void);


		//-��- ���[�h -��-//

		// �w�肳�ꂽ�p�X��3D�A�j���[�V�������f�������[�h����@�����F3D�A�j���[�V�������f���܂ł̃p�X�@�߂�l�F�������̂�true
		bool M_Load_3D_Animation_Model_By_Path(std::string);

		// �w�肳�ꂽ�p�X�̃A�j���[�V�����f�[�^�����[�h����@�����F�A�j���[�V�����f�[�^�܂ł̃p�X�@�߂�l�F�������̂�true
		bool M_Load_Animation_Data_By_Path(std::string);


		//-��- �Q�b�^ -��-//

		// �w�肳�ꂽ���O�̃��b�V�����̃A�h���X��Ԃ��@�����F�T�����b�V���̖��O�@�߂�l�F���O����v�������b�V���̃A�h���X�A��v���Ȃ�������nullptr��Ԃ�
		S_Animative_Mesh_Data_Inform * M_Get_Mesh_Data_By_Name(std::string);

		// ���b�V�����̃��X�g�̎Q�Ƃ�Ԃ��@�߂�l�F���b�V�����̃��X�g�̎Q��
		std::vector<S_Animative_Mesh_Data_Inform> & M_Get_Mesh_Inform_List(void);


		//-��- �`�� -��-//

		// 3D���f����`�悷��
		void M_Draw_3D_Model(void);

		// 3D���f������w�肳�ꂽ���b�V�����̂ݕ`�悷��@�����F�`�悷�郁�b�V�����i�������肷��j
		void M_Draw_Meshes_By_Name(std::string);
	};
}


#endif // !D_INCLUDE_GUARD_C_3D_ANIMATION_MODEL_SYSTEM_H_FILE
