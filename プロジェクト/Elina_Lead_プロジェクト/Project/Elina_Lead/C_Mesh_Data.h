//����������������������������������������������//
// �ڍ�   �F���b�V���̃f�[�^�Ǘ��p�̃V�X�e���̃N���X
// ����   �F���_�Ⓒ�_�C���f�b�N�X���̊Ǘ����s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_MESH_DATA_H_FILE
#define D_INCLUDE_GUARD_C_MESH_DATA_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <string>

#include "C_Object_Vertex_System.h"
#include "S_3D_Model_Vertex.h"
#include "C_Material_User.h"
#include "C_Vertex_Index_System.h"


// �� �l�[���X�y�[�X �� //

// ���b�V���̃V�X�e�����Ăяo�����߂̖��O
namespace ASSET::MESH
{
	// �� �N���X �� //

	// ���b�V���̃f�[�^�Ǘ��p�̃V�X�e���̃N���X
	class C_Mesh_Data
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			RENDERING::CAPSULE::C_Vertex_Index_System vertex_index_system;	// ���_�C���f�b�N�X�V�X�e��
			
			ASSET::MATERIAL::C_Material_User material;	// �}�e���A���f�[�^

			std::string name = "default";	// ���b�V����

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Mesh_Data(void);

		// �f�X�g���N�^
		~C_Mesh_Data(void);

		// �������̉�����s��
		void M_Release(void);


		//-��- �ݒ� -��-//

		// ���_�C���f�b�N�X���w�肳�ꂽ���������@�����F�������钸�_�C���f�b�N�X��
		void M_Create_Index_List(int);

		// ���_�C���f�b�N�X�f�[�^�𒸓_�C���f�b�N�X�o�b�t�@�ɐݒ肷��
		void M_Attach_Index_Data_To_Buffer(void);

		// ���_�C���f�b�N�X�f�[�^�݂̂��폜����i���_�C���f�b�N�X�o�b�t�@�ɐݒ��A�ҏW���Ȃ��Ȃ玝���Ă����K�v���Ȃ��j
		void M_Delete_Index_Data(void);

		// �w�肳�ꂽ���O�̃}�e���A�������[�h����@�����F�}�e���A�����@�߂�l�F�������̂�true
		bool M_Load_Material_By_Name(std::string);


		//-��- �Z�b�^ -��-//

		// ���b�V������ݒ肷��@�����F�ݒ肷�郁�b�V����
		void M_Set_Mesh_Name(std::string);


		//-��- �Q�b�^ -��-//

		// ���_�C���f�b�N�X�f�[�^�̃��X�g�̎Q�Ƃ�Ԃ��@�߂�l�F���_�C���f�b�N�X�f�[�^�̃��X�g�̎Q��
		std::vector<unsigned int> & M_Get_Index_Data_List(void);

		// ���݂̃}�e���A�����[�U�[�̎Q�Ƃ�Ԃ��@�߂�l�F�}�e���A�����[�U�[�̎Q�Ƃ�Ԃ�
		ASSET::MATERIAL::C_Material_User & M_Get_Material_User(void);

		// ���b�V������Ԃ��@�߂�l�F���b�V����
		std::string M_Get_Mesh_Name(void);


		//-��- �`�� -��-//

		// ���b�V���̕`������s����
		void M_Draw_Mesh(void);

		// �}�e���A���̐ݒ�������ɖʂ̕`��̂ݍs���i�O���Ń}�e���A����ݒ肵�Ă���`�悷��Ƃ��p�j
		void M_Draw_Mesh_Do_Not_Set_Material(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_MESH_DATA_H_FILE

