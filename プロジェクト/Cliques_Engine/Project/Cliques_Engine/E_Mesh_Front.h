//����������������������������������������������//
// �ڍ�   �F�\�ʂ̊�̒�`
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_E_MESH_FRONT_H_FILE
#define D_INCLUDE_GUARD_E_MESH_FRONT_H_FILE


// �� �l�[���X�y�[�X �� //

// ���X�^���C�U��`�p�̏����Ăяo�����߂̖��O
namespace RENDERING::INFORM::RASTERIZER
{
	// �� �� �� //

	// �\�ʂ̊�̗�
	enum class E_MESH_FRONT : unsigned char
	{
		e_ANTI_CLOCK_WISE,	// �����v���̖ʂ��\��
		e_CLOCK_WISE,		// ���v���̖ʂ��\��
	};
}


#endif // !D_INCLUDE_GUARD_E_MESH_FRONT_H_FILE

