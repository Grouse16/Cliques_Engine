//����������������������������������������������//
// �ڍ�   �F�s�N�Z���P�ʂŎl�p�`��\���V�X�e��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_S_RECT_H_FILE
#define D_INCLUDE_GUARD_S_RECT_H_FILE


// �� �l�[���X�y�[�X �� //

// �s�N�Z���͈͂�ݒ肷���`���Ăяo�����߂̖��O
namespace DATA::RECTSETTING
{
	// �� �\���� �� //
	
	// �s�N�Z���P�ʂŎl�p�`��\���p�����[�^�̍\����
	struct S_Rect
	{
		// �� �ϐ��錾 �� //
		int left_x = 0;		// ���[�̂��s�N�Z�����W
		int right_x = 0;	// �E�[�̂��s�N�Z�����W
		int top_y = 0;		// ��[�̂��s�N�Z�����W
		int bottom_y = 0;	// ���[�̂��s�N�Z�����W
	};
}


#endif // !D_INCLUDE_GUARD_S_RECT_H_FILE
