//����������������������������������������������//
// �ڍ�   �F�s�N�Z���V�F�[�_�[�̏o�͒l�̃o�C�g������уf�[�^�^�̒�`�̗�
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_E_RENDERING_DRAW_FORMAT_H_FILE
#define D_INCLUDE_GUARD_E_RENDERING_DRAW_FORMAT_H_FILE


// �� �l�[���X�y�[�X �� //

// �u�����h��`�p�̏����Ăяo�����߂̖��O
namespace RENDERING::INFORM::BLEND
{
	// �� �� �� //

	// �s�N�Z���V�F�[�_�[�̏o�͒l�̃o�C�g������уf�[�^�^�̒�`
	enum class E_RENDERING_DRAW_FORMAT
	{
		e_BYTE_1_UINT,	// �P�o�C�g��UINT
		e_BYTE_2_UINT,	// �Q�o�C�g��UINT
		e_BYTE_4_UINT,	// �S�o�C�g��UINT

		e_BYTE_2_FLOAT,	// �Q�o�C�g��FLOAT
		e_BYTE_4_FLOAT,	// �S�o�C�g��FLOAT
	};
}


#endif // !D_INCLUDE_GUARD_E_RENDERING_DRAW_FORMAT_H_FILE

