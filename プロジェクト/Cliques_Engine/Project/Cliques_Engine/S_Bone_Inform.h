//����������������������������������������������//
// �ڍ�   �F�{�[���̏��̍\����
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_S_BONE_INFORM_H_FILE
#define D_INCLUDE_GUARD_S_BONE_INFORM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <DirectXMath.h>
#include <string>


// �� �l�[���X�y�[�X �� //
namespace ASSET::ANIMATION::BONE
{
	// �� �N���X �� //

	// �{�[���̏��̍\����
	struct S_Bone_Inform
	{
		// �� �ϐ��錾 �� //
		DirectX::XMFLOAT4X4 offset_matrix = DirectX::XMFLOAT4X4();	// �I�t�Z�b�g�}�g���N�X�s��

		std::string bone_name = "default";	// �{�[����

		std::vector<int> children_bone_index_list;	// �q�{�[���̃C���f�b�N�X�̃��X�g

		int parent_bone_index = -1;	// �e�{�[���̃C���f�b�N�X
	};
}


#endif // !D_INCLUDE_GUARD_S_BONE_INFORM_H_FILE
