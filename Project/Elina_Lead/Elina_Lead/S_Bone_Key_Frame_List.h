//����������������������������������������������//
// �ڍ�   �F�{�[���̃L�[�̏��̔z��̍\����
// ����   �F�L�[�̃��X�g�͂��ꂼ�ꑍ�����قȂ邱�Ƃ�����̂ŁA�������z��ŊǗ�����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_S_BONE_KEY_FRAME_LIST_H_FILE
#define D_INCLUDE_GUARD_S_BONE_KEY_FRAME_LIST_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>

#include "S_Key_Frame.h"


// �� �l�[���X�y�[�X �� //

// �{�[���̏����Ăяo�����߂̖��O
namespace ASSET::ANIMATION::BONE
{
	// �� �\���� �� //

	// �{�[���̃L�[�̏��̔z��̍\����
	struct S_Bone_Key_Frame_List
	{
		std::vector<ASSET::ANIMATION::DATA::S_Key_Frame> position_key_list;	// �ʒu���W�̃L�[�̃��X�g
		std::vector<ASSET::ANIMATION::DATA::S_Key_Frame> scale_key_list;	// �X�P�[���̃L�[�̃��X�g

		std::vector<ASSET::ANIMATION::DATA::S_Quaternion_Key_Frame> quaternion_key_list;	// �N�H�[�^�j�I���i��]���j�̃L�[�̃��X�g
	};
}


#endif // !D_INCLUDE_GUARD_S_BONE_KEY_FRAME_LIST_H_FILE

