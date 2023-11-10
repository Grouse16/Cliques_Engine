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
			RENDERING::CAPSULE::C_Object_Vertex_System<DATA::VERTEX::S_3D_Model_Vertex> vertex_setting;	// ���_�p�V�X�e��
			
			ASSET::MATERIAL::C_Material_User material;	// �}�e���A���f�[�^

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Mesh_Data(void);

		// �f�X�g���N�^
		~C_Mesh_Data(void);


		//-��- �ݒ� -��-//

		// ���_���w�肳�ꂽ���������@�����F�������钸�_��
		void M_Creat_Vertex_List(int);

		// ���_�C���f�b�N�X���w�肳�ꂽ���������@�����F�������钸�_�C���f�b�N�X��
		void M_Creat_Index_List(int);

		// ���_�o�b�t�@�ƒ��_�C���f�b�N�X�o�b�t�@�𐶐�����@�����_�f�[�^�ƒ��_�C���f�b�N�X��K�v�Ȑ������������Ă�����s���邱��
		void M_Creat_Vertex_Buffer_And_Index_Buffer(void);

		// ���_�C���f�b�N�X�f�[�^�𒸓_�C���f�b�N�X�o�b�t�@�ɐݒ肷��
		void M_Attach_Index_Data_To_Buffer(void);

		// ���_�f�[�^�𒸓_�o�b�t�@�ɐݒ肷��
		void M_Attach_Vertex_Data_To_Buffer(void);

		// ���_�f�[�^�݂̂��폜����i���_�o�b�t�@�ɐݒ��A�ҏW���Ȃ��Ȃ玝���Ă����K�v���Ȃ��j
		void M_Delete_Vertex_Data(void);

		// ���_�C���f�b�N�X�f�[�^�݂̂��폜����i���_�C���f�b�N�X�o�b�t�@�ɐݒ��A�ҏW���Ȃ��Ȃ玝���Ă����K�v���Ȃ��j
		void M_Delete_Index_Data(void);

		// �w�肳�ꂽ���O�̃}�e���A�������[�h����@�����F�}�e���A�����@�߂�l�F�������̂�true
		bool M_Load_Material_By_Name(std::string);


		//-��- �Q�b�^ -��-//

		// ���_�f�[�^�̃��X�g�̎Q�Ƃ�Ԃ��@�߂�l�F���_�f�[�^�̃��X�g�̎Q��
		std::vector<DATA::VERTEX::S_3D_Model_Vertex> & M_Get_Vertex_Data_List(void);

		// ���_�C���f�b�N�X�f�[�^�̃��X�g�̎Q�Ƃ�Ԃ��@�߂�l�F���_�C���f�b�N�X�f�[�^�̃��X�g�̎Q��
		std::vector<unsigned __int32> & M_Get_Index_Data_List(void);

		// ���݂̃}�e���A�����[�U�[�̎Q�Ƃ�Ԃ��@�߂�l�F�}�e���A�����[�U�[�̎Q�Ƃ�Ԃ�
		ASSET::MATERIAL::C_Material_User & M_Get_Material_User(void);


		//-��- �`�� -��-//

		// ���b�V���̕`������s����
		void M_Draw_Mesh(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_MESH_DATA_H_FILE

