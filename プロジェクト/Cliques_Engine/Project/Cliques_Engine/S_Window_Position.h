//����������������������������������������������//
// �ڍ�   �F�E�B���h�E�̍��W�̌^�̒�`
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_S_WINDOW_POSITION_H_FILE
#define D_INCLUDE_GUARD_S_WINDOW_POSITION_H_FILE


// �� �l�[���X�y�[�X �� //

// OS�̊��N���X���Ăяo�����߂̖��O
namespace OS
{
	// �� �\���� ��//

	// �E�B���h�E�̍��W�̍\����
	struct S_Window_Position
	{
		int position_left_x = 0;	// �E�B���h�E�̍��[
		int position_right_x = 0;	// �E�B���h�E�̉E�[
		int position_top_y = 0;		// �E�B���h�E�̏�[
		int position_bottom_y = 0;	// �E�B���h�E�̉���
	};
}


#endif // !D_INCLUDE_GUARD_S_WINDOW_POSITION_H_FILE
