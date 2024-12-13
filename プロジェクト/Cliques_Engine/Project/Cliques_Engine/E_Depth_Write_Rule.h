//����������������������������������������������//
// �ڍ�   �F�[�x�̏������݃��[���̒�`
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_E_DEPTH_WRITE_RULE_H_FILE
#define D_INCLUDE_GUARD_E_DEPTH_WRITE_RULE_H_FILE


// �� �l�[���X�y�[�X �� //

// �[�x�X�e���V���̒�`�p�̏����Ăяo�����߂̖��O
namespace RENDERING::INFORM::DEPTH_STENCIL
{
	// �� �� �� //

	// �[�x�̏������݃��[���̒�`
	enum class E_DEPTH_WRITE_RULE : unsigned char
	{
		e_DONT,			// �������܂Ȃ�
		e_ALWAYS,		// ��ɏ�������
		e_EQUAL,		// ��r���Ɠ����l�̎��̂ݏ�������
		e_NOT_EQUAL,	// ��r���ƈႤ�l�̎��̂ݏ�������
		e_GREATER,		// ��r���̒l�𒴂��鎞�̂ݏ�������
		e_LESS,			// ��r���̒l�����̎��̂ݏ�������

		e_LESS_EQUAL,		// ��r���̒l�ȉ��̎��̂ݏ�������
		e_GREATERE_EQUAL,	// ��r���̒l�ȏ�̎��̂ݏ�������
	};
}

#endif // !D_INCLUDE_GUARD_E_DEPTH_WRITE_RULE_H_FILE

