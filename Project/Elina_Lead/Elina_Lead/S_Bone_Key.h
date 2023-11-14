//����������������������������������������������//
// �ڍ�   �F�{�[���̃L�[�̏��̍\����
// ����   �F�L�[�t���[���̍ŏI�I�ȃA�j���[�V�����u�����h���ʂ��󂯎�邽�߂̍\����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_S_BONE_KEY_H_FILE
#define D_INCLUDE_GUARD_S_BONE_KEY_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>

#include "S_Key_Frame.h"


// �� �l�[���X�y�[�X �� //

// �{�[���̏����Ăяo�����߂̖��O
namespace ASSET::ANIMATION::BONE
{
	// �� �\���� �� //

	// �{�[���̃L�[�̏��̍\����
	struct S_Bone_Key
	{
		DirectX::XMFLOAT3 position_key;	// �ʒu���W�̃L�[
		DirectX::XMFLOAT3 scale_key;	// �X�P�[���̃L�[

		DirectX::XMVECTOR quaternion_key = DirectX::XMQuaternionIdentity();	// �N�H�[�^�j�I���i��]���j�̃L�[
	};
}


#endif // !D_INCLUDE_GUARD_S_BONE_KEY_H_FILE

