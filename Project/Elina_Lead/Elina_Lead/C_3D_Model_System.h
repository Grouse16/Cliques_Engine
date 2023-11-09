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

#include "C_Mesh_Data.h"


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

		// �� �\���� �� //

		// ���b�V�����Ǘ����邽�߂̃f�[�^�̍\����
		struct S_Mesh_Data_Inform
		{
			std::unique_ptr<ASSET::MESH::C_Mesh_Data> mesh_list = nullptr;	// ���b�V���f�[�^

			std::string mesh_name = "default";	// ���b�V����
		};


		// �� �ϐ��錾 �� //
		
		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::vector<S_Mesh_Data_Inform> mesh_inform_list;	// ���b�V���̊Ǘ��p��񃊃X�g
		};
	};
}

#endif // !D_INCLUDE_GUARD_C_3D_MODEL_SYSTEM_H_FILE
