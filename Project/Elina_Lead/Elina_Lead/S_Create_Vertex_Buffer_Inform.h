//����������������������������������������������//
// �ڍ�   �F���_���𐶐����邽�߂̏��̍\����
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_CREATE_VERTEX_BUFFER_INFORM_H_FILE
#define D_INCLUDE_GUARD_C_CREATE_VERTEX_BUFFER_INFORM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>


// �� �l�[���X�y�[�X �� //

// �O���t�B�b�N�𐧌䂷��V�X�e���̏��𐶐����邽�߂̏����Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS::CREATE
{
	// �� �\���� �� //
	
	// ���_���𐶐����邽�߂̏��̍\����
	struct S_Create_Vertex_Buffer_Inform
	{
		int size_of_vertex = 0;	// ���_����̃T�C�Y
		int vertex_sum = 0;		// ���_��
	};
}


#endif // !D_INCLUDE_GUARD_C_CREATE_VERTEX_BUFFER_INFORM_H_FILE
