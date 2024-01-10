//����������������������������������������������//
// �ڍ�   �F3D���f���̃N���X
// ����   �F3D���f���̎擾����`��A�A�j���[�V�����̎��s�܂ł��s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_3D_MODEL_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_3D_MODEL_SYSTEM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>
#include <memory>
#include <string>
#include <DirectXMath.h>

#include "C_Mesh_Data.h"
#include "C_Transform.h"
#include "C_Object_Vertex_System.h"
#include "S_3D_Model_Vertex.h"


// �� �l�[���X�y�[�X �� //

// 3D���f�����Ăяo�����߂̖��O
namespace ASSET::MODEL
{
	// �� �N���X �� //

	// 3D���f���̃N���X
	class C_3D_Model_System
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //
		
		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			RENDERING::CAPSULE::C_Object_Vertex_System<DATA::VERTEX::S_3D_Model_Vertex> vertex_system;	// ���_�f�[�^���Ǘ�����N���X

			std::vector<ASSET::MESH::C_Mesh_Data> mesh_list;	// ���b�V���̊Ǘ��p��񃊃X�g

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_3D_Model_System(void);

		//�f�X�g���N�^
		~C_3D_Model_System(void);

		// �������̉�����s��
		void M_Release(void);


		//-��- ���[�h -��-//

		// �w�肳�ꂽ�p�X��3D���f�������[�h����@�����F3D���f���܂ł̃p�X�@�߂�l�F�������̂�true
		bool M_Load_3D_Model_By_Path(std::string);


		//-��- �Q�b�^ -��-//

		// �w�肳�ꂽ���O�̃��b�V�����̃A�h���X��Ԃ��@�����F�T�����b�V���̖��O�@�߂�l�F���O����v�������b�V���̃A�h���X�A��v���Ȃ�������nullptr��Ԃ�
		ASSET::MESH::C_Mesh_Data * M_Get_Mesh_Data_By_Name(std::string);

		// ���b�V�����̃��X�g�̎Q�Ƃ�Ԃ��@�߂�l�F���b�V�����̃��X�g�̎Q��
		std::vector<ASSET::MESH::C_Mesh_Data> & M_Get_Mesh_Inform_List(void);


		//-��- �`�� -��-//

		// 3D���f����`�悷��
		void M_Draw_Model(void);

		// 3D���f������w�肳�ꂽ���b�V�����̂ݕ`�悷��@�����F�`�悷�郁�b�V�����i�������肷��j
		void M_Draw_Meshes_By_Name(std::string);

		// �}�e���A����ݒ肹���ɁA3D���f����`�悷��i�`��O�Ƀ}�e���A�����Z�b�g����Ƃ��p�j
		void M_Draw_Model_Do_Not_Use_Material(void);

		// �}�e���A����ݒ肹���ɁA3D���f������w�肳�ꂽ���b�V�����̂ݕ`�悷��i�`��O�Ƀ}�e���A�����Z�b�g����Ƃ��p�j�@�����F�`�悷�郁�b�V�����i�������肷��j
		void M_Draw_Meshes_By_Name_Do_Not_Use_Material(std::string);


		//-��- �萔�o�b�t�@ -��-//

		// ���[���h �r���[ �v���W�F�N�V���������C���J���������ɒ萔�o�b�t�@�ɃZ�b�g����A�g�����X�t�H�[�����󂯎��@�����F�g�����X�t�H�[���̎Q�Ɓiconst�j
		void M_Set_World_View_Projection_With_Main_Camera_By_Transform(const MATH::C_Transform & );

		// ���[���h �r���[ �v���W�F�N�V���������C���J���������ɒ萔�o�b�t�@�ɃZ�b�g����A���[���h�}�g���N�X���󂯎��@�����F���[���h�}�g���N�X�̎Q�Ɓiconst�j
		void M_Set_World_View_Projection_With_Main_Camera_By_World_Matrix(const DirectX::XMMATRIX &);
	};
}


#endif // !D_INCLUDE_GUARD_C_3D_MODEL_SYSTEM_H_FILE





































//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��
