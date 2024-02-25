//����������������������������������������������//
// �ڍ�   �F�}�E�X���p�̌^�̒�`
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_S_MOUSE_STATE_H_FILE
#define D_INCLUDE_GUARD_S_MOUSE_STATE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "E_Mouse_Click_State.h"


// �� �l�[���X�y�[�X �� //

// OS����p�V�X�e�����Ăяo�����߂̖��O
namespace OS
{
	// �� �\���� ��//

	// �}�E�X���W�p�̍\����
	struct S_Mouse_State
	{
		E_MOUSE_CLICK_STATE left_click = E_MOUSE_CLICK_STATE::e_NON;	// ���N���b�N�̏��
		E_MOUSE_CLICK_STATE center_click = E_MOUSE_CLICK_STATE::e_NON;	// ���N���b�N�̏��
		E_MOUSE_CLICK_STATE right_click = E_MOUSE_CLICK_STATE::e_NON;	// �E�N���b�N�̏��

		int x = 0;	// �}�E�X���W��
		int y = 0;	// �}�E�X���W��
	};
}


#endif // !D_INCLUDE_GUARD_S_MOUSE_STATE_H_FILE
