//����������������������������������������������//
// �ڍ�   �F�A���`�G�C���A�V���O�̕��@�̒�`
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_E_ANTIALIASING_H_FILE
#define D_INCLUDE_GUARD_E_ANTIALIASING_H_FILE


// �� �l�[���X�y�[�X �� //

// ���X�^���C�U��`�p�̏����Ăяo�����߂̖��O
namespace RENDERING::INFORM::RASTERIZER
{
	// �� �� �� //

	// �A���`�G�C���A�V���O�̕��@�̗�
	enum class E_ANTIALIASING : unsigned char
	{
		e_DONT,		// ����
		e_ALPHA,	// �A���t�@�l�ōs��
		e_PIXEL,	// �l�ӌ`�ŐF�𕪎U���čs��
		e_LINE,		// �ӂɃA���`�G�C���A�V���O��������
	};
}


#endif // !D_INCLUDE_GUARD_E_ANTIALIASING_H_FILE

