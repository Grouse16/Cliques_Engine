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
#include "C_Animation_Data_System.h"


// �� �l�[���X�y�[�X �� //

// �A�j���[�V�����ł���3D���f�����Ăяo�����߂̖��O
namespace ASSET::ANIMATION_MODEL
{
	// �� �N���X �� //

	// �A�j���[�V�������f���̃V�X�e��
	class C_3D_Animation_Model_System
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �\���� �� //

		// �A�j���[�V�������f���̓���o�b�t�@�̃X���b�g�̔ԍ����܂Ƃ߂��\����
		struct S_Unique_Buffer_Slot
		{
			int transform = 0;			// �g�����X�t�H�[��
			
			int ambient_light = 0;		// �A���r�G���g���C�g
			int directional_light = 0;	// �f�B���N�V���i�����C�g
			int point_light = 0;		// �|�C���g���C�g
			int spot_light = 0;			// �X�|�b�g���C�g
			int area_light = 0;			// �G���A���C�g

			int bone = 0;				// �{�[��

			int main_texture = 0;	// ���C���ƂȂ�e�N�X�`��
		};

		// ���b�V�����Ǘ����邽�߂̃f�[�^�̍\����
		struct S_Animative_Mesh_Data_Inform
		{
			std::unique_ptr<ASSET::ANIMATION::MESH::C_Animative_Mesh> mesh_data = nullptr;	// ���b�V���f�[�^

			std::string name = "default";	// ���b�V����

			S_Unique_Buffer_Slot unique_buffer_number;	// ����ȃo�b�t�@�ԍ�
		};

		// �A�j���[�V�������Ǘ����邽�߂̃f�[�^�̍\����
		struct S_Animation_Data_Inform
		{
			std::unique_ptr<ASSET::ANIMATION_SYSTEM::C_Animation_Data_System> animation_data = nullptr;	// �A�j���[�V�����f�[�^

			std::string name = "default";	// �A�j���[�V�����f�[�^��
		};


		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::vector<S_Animative_Mesh_Data_Inform> mesh_inform_list;	// ���b�V���̊Ǘ��p��񃊃X�g

			std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> bone_list;	// �{�[�����̃��X�g

			std::vector<S_Animation_Data_Inform> animation_data_list;	// �A�j���[�V�����f�[�^�̃��X�g

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

		// �w�肳�ꂽ���O�̃A�j���[�V�����f�[�^�����[�h����@�����F���[�h����A�j���[�V�����f�[�^���@�߂�l�F�������̂�true
		bool M_Load_Animation_Data_By_Path(std::string);


		//-��- �Q�b�^ -��-//

		// �w�肳�ꂽ���O�̃��b�V���f�[�^���̃A�h���X��Ԃ��@�����F�T�����b�V���̖��O�@�߂�l�F���O����v�������b�V���̃A�h���X�A��v���Ȃ�������nullptr��Ԃ�
		ASSET::ANIMATION::MESH::C_Animative_Mesh * M_Get_Mesh_Data_By_Name(std::string);

		// ���b�V�����̃��X�g�̎Q�Ƃ�Ԃ��@�߂�l�F���b�V�����̃��X�g�̎Q��
		std::vector<S_Animative_Mesh_Data_Inform> & M_Get_Mesh_Inform_List(void);

		// �w�肳�ꂽ���O�̃A�j���[�V�����f�[�^���̃A�h���X��Ԃ��@�����F�T���A�j���[�V�����f�[�^�̖��O�@�߂�l�F���O����v�����A�j���[�V�����̃A�h���X�A��v���Ȃ�������nullptr��Ԃ�
		const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * M_Get_Animation_Data_By_Name(std::string);

		// �A�j���[�V�������̃��X�g�̎Q�Ƃ�Ԃ��@�߂�l�F�A�j���[�V�������̃��X�g�̎Q��
		const std::vector<S_Animation_Data_Inform> & M_Get_Animation_Inform_List(void);

		// �{�[�����̃��X�g��Ԃ��@�߂�l�F�{�[�����̃��X�g�̎Q��(const)
		const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & M_Get_Bone_Inform_List(void);


		//-��- �`�� -��-//

		// �{�[���̃}�g���N�X���}�e���A���ɃZ�b�g����@�����F�Z�b�g����{�[���}�g���N�X�z��̎Q��(const)
		void M_Set_Bone_Matrix(const std::vector<DirectX::XMFLOAT4X4> &);

		// 3D���f����`�悷��
		void M_Draw_3D_Model(void);

		// 3D���f������w�肳�ꂽ�A�j���[�V�������̂ݕ`�悷��@�����F�`�悷��A�j���[�V�������i�������肷��j
		void M_Draw_Meshes_By_Name(std::string);
	};
}


#endif // !D_INCLUDE_GUARD_C_3D_ANIMATION_MODEL_SYSTEM_H_FILE

