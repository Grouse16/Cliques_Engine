//����������������������������������������������//
// �ڍ�   �F�L�[�t���[�����̍\����
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_S_KEY_FRAME_H_FILE
#define D_INCLUDE_GUARD_S_KEY_FRAME_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <DirectXMath.h>

#include "C_Quaternion.h"


// �� �l�[���X�y�[�X �� //

// �A�j���[�V�����f�[�^���Ăяo�����߂̖��O
namespace ASSET::ANIMATION_SYSTEM
{
	// �� �\���� �� //

	// �L�[�t���[�����
	struct S_Key_Frame
	{
		DirectX::XMFLOAT3 key_value = DirectX::XMFLOAT3();	// �L�[�l

		float time_of_frame = 0.0f;	// �t���[���̎���
	};


	// ��]�p�̃L�[�t���[�����
	struct S_Quaternion_Key_Frame
	{
		MATH::QUATERNION::C_Quaternion quaternion;	// �N�H�[�^�j�I���V�X�e��

		float time_of_frame = 0.0f;	// �t���[���̎���

	};	// ��]�̂݃N�I�[�^�j�I���Ŏl�v�f�����邽�ߕ����Ă���
}


#endif // !D_INCLUDE_GUARD_S_KEY_FRAME_H_FILE
