//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�����p�̃��b�V���̃N���X
// ����   �F�A�j���[�V�����u�����h�p�̒萔�o�b�t�@�����V�X�e����ǉ��������b�V���V�X�e���N���X
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_ANIMATIVE_MESH_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATIVE_MESH_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_Vertex_Index_System.h"
#include "C_Material_User.h"


// �� �l�[���X�y�[�X �� //

// �A�j���[�V�������郁�b�V�����Ăяo�����߂̖��O
namespace ASSET::ANIMATION::MESH
{
	// �� �N���X �� //
	
	// �A�j���[�V�����p�̃��b�V���̃N���X
	class C_Animative_Mesh
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			RENDERING::CAPSULE::C_Vertex_Index_System m_vertex_index_system;	// ���_�C���f�b�N�X�V�X�e��

			ASSET::MATERIAL::C_Material_User material;	// �}�e���A���f�[�^

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Animative_Mesh(void);

		// �f�X�g���N�^
		~C_Animative_Mesh(void);

		// ���������������
		void M_Release(void);


		//-��- ���_�C���f�b�N�X -��-//

		// ���_�C���f�b�N�X���w�肳�ꂽ���������@�����F�������钸�_�C���f�b�N�X��
		void M_Create_Index_List(int);

		// ���_�C���f�b�N�X�f�[�^�𒸓_�C���f�b�N�X�o�b�t�@�ɐݒ肷��
		void M_Attach_Index_Data_To_Buffer(void);

		// ���_�C���f�b�N�X�f�[�^�݂̂��폜����i���_�C���f�b�N�X�o�b�t�@�ɐݒ��A�ҏW���Ȃ��Ȃ玝���Ă����K�v���Ȃ��j
		void M_Delete_Index_Data(void);


		//-��- ���[�h -��-//

		// �w�肳�ꂽ���O�̃}�e���A�������[�h����@�����F�}�e���A�����@�߂�l�F�������̂�true
		bool M_Load_Material_By_Name(std::string);


		//-��- �Q�b�^ -��-//

		// ���_�C���f�b�N�X�f�[�^�̃��X�g�̎Q�Ƃ�Ԃ��@�߂�l�F���_�C���f�b�N�X�f�[�^�̃��X�g�̎Q��
		std::vector<unsigned int> & M_Get_Index_Data_List(void);

		// ���݂̃}�e���A�����[�U�[�̎Q�Ƃ�Ԃ��@�߂�l�F�}�e���A�����[�U�[�̎Q�Ƃ�Ԃ�
		ASSET::MATERIAL::C_Material_User & M_Get_Material_User(void);


		//-��- �`�� -��-//

		// ���b�V���̕`������s����
		void M_Draw_Mesh(void);

		// �}�e���A���̐ݒ�������ɖʂ̕`��̂ݍs���i�O���Ń}�e���A����ݒ肵�Ă���`�悷��Ƃ��p�j
		void m_Draw_Mesh_Do_Not_Set_Material(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATIVE_MESH_H_FILE
