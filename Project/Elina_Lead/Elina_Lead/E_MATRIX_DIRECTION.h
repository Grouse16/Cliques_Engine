//����������������������������������������������//
// �ڍ�   �F�}�g���N�X�̍s�ƕ����̊֌W��\����
// ����   �F��]���琶�����ꂽ�}�g���N�X�̉�]�v�f���擾���邽�߂Ɏg�p����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_E_MATRIX_DIRECTION_H_FILE
#define D_INCLUDE_GUARD_E_MATRIX_DIRECTION_H_FILE


// �� �l�[���X�y�[�X �� //

// �}�g���N�X�n���̃V�X�e���Ăяo�����߂̖��O
namespace MATH::MATRIX
{
	// �� �� �� //

	// �}�g���N�X�̍s�ƕ����̊֌W��\����
	enum class E_MATRIX_DIRECTION : char
	{
		e_SIDE_VECTOR = 0,			// �������i�{���E�����j
		e_VERTICAL_VECTOR = 1,			// �c�����i�{��������j
		e_FRONT_VECTOR = 2,			// �O������i�{���O�����j
		e_TRANSLATION_VECTOR = 3,	// ���s����
	};
}


#endif // !D_INCLUDE_GUARD_E_MATRIX_DIRECTION_H_FILE

