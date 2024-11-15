//����������������������������������������������//
// �ڍ�   �FUI�p�̒��_�̒�`�̍\����
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_S_UI_VERTEX_H_FILE
#define D_INCLUDE_GUARD_S_UI_VERTEX_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "2D_Position_Data.h"
#include "C_Color.h"
#include "Texture_UV_Data.h"


// �� �l�[���X�y�[�X �� //

// ���_�f�[�^���Ăяo�����߂̖��O
namespace DATA::VERTEX
{
	// �� �\���� �� //

	// UI�p�̒��_�̒�`�̍\����
	struct S_UI_Vertex
	{
		DATA::POSITION_2D::C_2D_Position position;	// �s�N�Z���ł̒��_���W

		DATA::COLOR::C_Color color;	// �F

		DATA::TEXTURE_UV::C_Texture_UV uv;	// �e�N�X�`�����W
	};
}

#endif // !D_INCLUDE_GUARD_S_UI_VERTEX_H_FILE
