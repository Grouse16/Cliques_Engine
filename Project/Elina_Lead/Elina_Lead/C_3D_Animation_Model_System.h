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
#include "C_Transform.h"
#include "C_Object_Vertex_System.h"
#include "S_3D_Animation_Model_Vertex.h"


// �� �l�[���X�y�[�X �� //

// �A�j���[�V�����ł���3D���f�����Ăяo�����߂̖��O
namespace ASSET::ANIMATION_MODEL
{
	// �� �N���X �� //

	// �A�j���[�V�������f���̃V�X�e��
	class C_3D_Animation_Model_System
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			RENDERING::CAPSULE::C_Object_Vertex_System<DATA::VERTEX::S_3D_Animation_Model_Vertex> vertex_system;	// ���_�f�[�^���Ǘ�����N���X

			std::vector<ASSET::ANIMATION::MESH::C_Animative_Mesh> mesh_list;	// ���b�V���f�[�^

			std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> bone_list;	// �{�[�����̃��X�g

			std::vector<ASSET::ANIMATION_SYSTEM::C_Animation_Data_System> animation_data_list;	// �A�j���[�V�����f�[�^�̃��X�g

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
		bool M_Load_Animation_Data_By_Name(std::string);


		//-��- �Q�b�^ -��-//

		// �w�肳�ꂽ���O�̃��b�V���f�[�^���̃A�h���X��Ԃ��@�����F�T�����b�V���̖��O�@�߂�l�F���O����v�������b�V���̃A�h���X�A��v���Ȃ�������nullptr��Ԃ�
		ASSET::ANIMATION::MESH::C_Animative_Mesh * M_Get_Mesh_Data_By_Name(std::string);

		// ���b�V�����̃��X�g�̎Q�Ƃ�Ԃ��@�߂�l�F���b�V�����̃��X�g�̎Q��
		std::vector<ASSET::ANIMATION::MESH::C_Animative_Mesh> & M_Get_Mesh_Inform_List(void);

		// �w�肳�ꂽ���O�̃A�j���[�V�����f�[�^���̃A�h���X��Ԃ��@�����F�T���A�j���[�V�����f�[�^�̖��O�@�߂�l�F���O����v�����A�j���[�V�����̃A�h���X�A��v���Ȃ�������nullptr��Ԃ�
		const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * M_Get_Animation_Data_By_Name(std::string);

		// �A�j���[�V�����V�X�e���̃��X�g�̎Q�Ƃ�Ԃ��@�߂�l�F�A�j���[�V�����V�X�e���̃��X�g�̎Q��
		const std::vector<ASSET::ANIMATION_SYSTEM::C_Animation_Data_System> & M_Get_Animation_Inform_List(void);

		// �w�肳�ꂽ���O�̃{�[�����̃A�h���X��Ԃ��@�����F�T���{�[���̖��O�@�߂�l�F���O����v�����{�[���̃A�h���X�A��v���Ȃ�������nullptr��Ԃ�
		const ASSET::ANIMATION::BONE::S_Bone_Inform* M_Get_Bone_Inform_By_Name(std::string);

		// �{�[�����̃��X�g��Ԃ��@�߂�l�F�{�[�����̃��X�g�̎Q��(const)
		const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & M_Get_Bone_Inform_List(void);


		//-��- �`�� -��-//

		// 3D���f����`�悷��
		void M_Draw_3D_Model(void);

		// 3D���f������w�肳�ꂽ�A�j���[�V�������̂ݕ`�悷��@�����F�`�悷��A�j���[�V�������i�������肷��j
		void M_Draw_Meshes_By_Name(std::string);

		// �}�e���A����ݒ肹���ɁA3D���f����`�悷��i�`��O�Ƀ}�e���A�����Z�b�g����Ƃ��p�j
		void M_Draw_3D_Model_Do_Not_Use_Material(void);

		// �}�e���A����ݒ肹���ɁA3D���f������w�肳�ꂽ���b�V�����̂ݕ`�悷��i�`��O�Ƀ}�e���A�����Z�b�g����Ƃ��p�j�@�����F�`�悷�郁�b�V�����i�������肷��j
		void M_Draw_Meshes_By_Name_Do_Not_Use_Material(std::string);


		//-��- �萔�o�b�t�@ -��-//

		// �{�[���̃}�g���N�X���}�e���A���ɃZ�b�g����@�����F�Z�b�g����{�[���}�g���N�X�z��̎Q��(const)
		void M_Set_Bone_Matrix(const std::vector<DirectX::XMFLOAT4X4> & );

		// ���[���h �r���[ �v���W�F�N�V���������C���J���������ɒ萔�o�b�t�@�ɃZ�b�g����@�����F�g�����X�t�H�[���̎Q�Ɓiconst�j
		void M_Set_World_View_Projection_With_Main_Camera_By_Transform(const MATH::C_Transform & );

		// ���[���h �r���[ �v���W�F�N�V���������C���J���������ɒ萔�o�b�t�@�ɃZ�b�g����A���[���h�}�g���N�X���󂯎��@�����F���[���h�}�g���N�X�̎Q�Ɓiconst�j
		void M_Set_World_View_Projection_With_Main_Camera_By_World_Matrix(const DirectX::XMMATRIX & );
	};
}


#endif // !D_INCLUDE_GUARD_C_3D_ANIMATION_MODEL_SYSTEM_H_FILE



































//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��
