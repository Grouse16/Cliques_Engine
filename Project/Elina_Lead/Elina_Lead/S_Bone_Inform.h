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
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		std::string bone_name = "default";	// �{�[����

		DirectX::XMFLOAT4X4 offset_matrix = DirectX::XMFLOAT4X4();	// �I�t�Z�b�g�}�g���N�X�s��
	};
}


#endif // !D_INCLUDE_GUARD_S_BONE_INFORM_H_FILE
