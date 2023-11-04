//����������������������������������������������//
// �ڍ�   �F�[�x�X�e���V���̒�`���s���t�@�C��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_DEPTH_STENCIL_INFORM_H_FILE
#define D_INCLUDE_GUARD_DEPTH_STENCIL_INFORM_H_FILE


// �� �l�[���X�y�[�X �� //

// �[�x�X�e���V���̒�`�p�̏����Ăяo�����߂̖��O
namespace RENDERING::INFORM::DEPTH_STENCIL
{
	// �� �� �� //

	// �[�x�̏������ݕ��@�̗�
	enum class E_DEPTH_MODE : unsigned char
	{
		e_NO,	// �[�x�͖���
		e_ZERO,	// �[�x�͗L�������f�[�^���������܂Ȃ�
		e_ONE,	// �[�x����������
	};

	// �[�x�̏������݃��[���̗�
	enum class E_DEPTH_WRITE_RULE : unsigned char
	{
		e_DONT,		// �������܂Ȃ�
		e_ALWAYS,	// ��ɏ�������
		e_EQUAL,	// ��r���Ɠ����l�̎��̂ݏ�������
		e_GREATER,	// ��r���̒l�𒴂��鎞�̂ݏ�������
		e_LESS,		// ��r���̒l�����̎��̂ݏ�������
		e_LESS_EQUAL,		// ��r���̒l�ȉ��̎��̂ݏ�������
		e_GREATERE_EQUAL,	// ��r���̒l�ȏ�̎��̂ݏ�������
	};

	// �X�e���V�����L����������������
	enum class E_STENCIL_IS : bool
	{
		e_NO_ACTIVE = false,	// ����
		e_ACTIVE = true,		// �L��
	};
}

#endif // !D_INCLUDE_GUARD_DEPTH_STENCIL_INFORM_H_FILE

