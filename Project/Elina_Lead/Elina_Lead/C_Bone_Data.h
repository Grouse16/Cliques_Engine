//����������������������������������������������//
// �ڍ�   �F�{�[���̃f�[�^�̃N���X
// ����   �F�ݒ肳�ꂽ�����}�g���N�X�ɕϊ����邱�Ƃ��s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_BONE_DATA_H_FILE
#define D_INCLUDE_GUARD_C_BONE_DATA_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <DirectXMath.h>

// �� �l�[���X�y�[�X �� //

// �{�[���̃V�X�e�����Ăяo�����߂̖��O
namespace ASSET::ANIMATION::BONE
{
	// �� �N���X �� //

	// �{�[���̃f�[�^�̃N���X
	class C_Bone_Data
	{
		//==�� �p�u���b�N ��==//
	public:

		// �� �ϐ��錾 �� //
		DirectX::XMFLOAT3 position;	// �ʒu���W
		DirectX::XMFLOAT3 scale;	// �X�P�[��

		DirectX::XMVECTOR quaternion = DirectX::XMQuaternionIdentity();	// �N�H�[�^�j�I���i��]���j


		// �� �֐� �� //

		//-��- �}�g���N�X -��-//

		// ���݂̃{�[�������}�g���N�X�ɕϊ������l�������ɃZ�b�g����@�����F�ݒ��̃}�g���N�X���̎Q��
		void M_Set_Bone_Matrix_Data(DirectX::XMFLOAT4X4 & ) const;
	};
}


#endif // !D_INCLUDE_GUARD_C_BONE_DATA_H_FILE
