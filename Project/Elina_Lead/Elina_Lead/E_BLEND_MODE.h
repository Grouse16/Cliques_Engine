//����������������������������������������������//
// �ڍ�   �F�u�����h���[�h�̒�`���s���t�@�C��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_E_BLEND_MODE_H_FILE
#define D_INCLUDE_GUARD_E_BLEND_MODE_H_FILE


// �� �l�[���X�y�[�X �� //

// �u�����h���[�h��`�p�̏����Ăяo�����߂̖��O
namespace RENDERING::INFORM::BLEND_MODE
{
	// �� �� �� //

	// �u�����h���[�h���`�����
	enum class E_BLEND_MODE
	{
		e_NORMAL,			// �ʏ�`��
		e_NORMAL_NOT_ALPHA,	// ���l���g�p�����ɕ`��

		e_INVERT,			// ���Z�����ŕ`��
		e_INVERT_NOT_ALPHA,	// ���l���g�p�����Ɍ��Z�����ŕ`��
	};
}


#endif // !D_INCLUDE_GUARD_E_BLEND_MODE_H_FILE

