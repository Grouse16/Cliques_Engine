//����������������������������������������������//
// �ڍ�   �F�[�x�X�e���V���o�b�t�@�̃s�N�Z�������w�肷���
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE_H_FILE
#define D_INCLUDE_GUARD_E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE_H_FILE


// �� �l�[���X�y�[�X �� //

// �[�x�X�e���V���o�b�t�@�p�̏����Ăяo�����߂̖��O
namespace RENDERING::INFORM::DEPTH_STENCIL
{
	// �� �� �� //

	// �[�x�X�e���V���o�b�t�@�̃s�N�Z�������w�肷���
	enum class E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE : unsigned int
	{
		e_WIDTH_SIZE = 1920,	// �����̃s�N�Z����
		e_HEIGHT_SIZE = 1080,	// �c���̃s�N�Z����

		e_ALL_SIZE = e_WIDTH_SIZE * e_HEIGHT_SIZE,	// �S�̂̃T�C�Y
	};
}


#endif // !D_INCLUDE_GUARD_E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE_H_FILE

