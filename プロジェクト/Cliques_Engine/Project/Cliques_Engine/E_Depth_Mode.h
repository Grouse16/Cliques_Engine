//����������������������������������������������//
// �ڍ�   �F�[�x�̏������ݕ��@�̒�`
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_E_DEPTH_MODE_H_FILE
#define D_INCLUDE_GUARD_E_DEPTH_MODE_H_FILE


// �� �l�[���X�y�[�X �� //

// �[�x�X�e���V���̒�`�p�̏����Ăяo�����߂̖��O
namespace RENDERING::INFORM::DEPTH_STENCIL
{
	// �� �� �� //

	// �[�x�̏������ݕ��@�̒�`
	enum class E_DEPTH_MODE : unsigned char
	{
		e_NO,	// �[�x�͖���
		e_ZERO,	// �[�x�͗L���A���̐[�x�l���O�̕����ɂ̂ݏ�������
		e_ONE,	// �[�x�͗L���A�S�Ă͈̔͂ɏ�������
	};
}

#endif // !D_INCLUDE_GUARD_E_DEPTH_MODE_H_FILE

