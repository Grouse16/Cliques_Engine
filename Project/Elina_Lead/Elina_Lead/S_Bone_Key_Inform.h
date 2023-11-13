//����������������������������������������������//
// �ڍ�   �F�{�[���̃L�[�̏��̍\����
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_S_BONE_KEY_INFORM_H_FILE
#define D_INCLUDE_GUARD_S_BONE_KEY_INFORM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>

#include "S_Key_Frame.h"


// �� �l�[���X�y�[�X �� //

// �{�[���̏����Ăяo�����߂̖��O
namespace ASSET::ANIMATION::BONE
{
	// �� �\���� �� //

	// �{�[���̃L�[�̏��̍\����
	struct S_Bone_Key_Inform
	{
		std::vector<ASSET::ANIMATION::DATA::S_Key_Frame> position_key_list;	// �ʒu���W�̃L�[�̃��X�g
		std::vector<ASSET::ANIMATION::DATA::S_Key_Frame> scale_key_list;	// �X�P�[���̃L�[�̃��X�g

		std::vector<ASSET::ANIMATION::DATA::S_Rotation_Key_Frame> rotation_key_list;	// ��]�̃L�[�̃��X�g

		int bone_index = 0;	// �{�[���̃C���f�b�N�X�ԍ�
	};
}


#endif // !D_INCLUDE_GUARD_S_BONE_KEY_INFORM_H_FILE

