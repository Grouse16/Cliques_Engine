//����������������������������������������������//
// �ڍ�   �F�ʂ̃J�����O�̕`���̒�`
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_E_MESH_CULLING_H_FILE
#define D_INCLUDE_GUARD_E_MESH_CULLING_H_FILE


// �� �l�[���X�y�[�X �� //

// ���X�^���C�U��`�p�̏����Ăяo�����߂̖��O
namespace RENDERING::INFORM::RASTERIZER
{
	// �� �� �� //

	// �ʂ̃J�����O�̕`���̗�
	enum class E_MESH_CULLING : unsigned char
	{
		e_ALWAYS,	// ��ɕ`��
		e_FRONT,	// �\�ʂ̂ݕ`��
		e_BACK,		// ���ʂ̂ݕ`��
	};
}


#endif // !D_INCLUDE_GUARD_E_MESH_CULLING_H_FILE

