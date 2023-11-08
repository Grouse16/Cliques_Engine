//����������������������������������������������//
// �ڍ�   �F3D���f���p�̒��_�t�H�[�}�b�g�̒�`
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_S_3D_MODEL_VERTEX_H_FILE
#define D_INCLUDE_GUARD_S_3D_MODEL_VERTEX_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_Float_3.h"
#include "C_Float_2.h"


// �� �l�[���X�y�[�X �� //

// ���_�f�[�^�p�V�X�e�����Ăяo�����߂̖��O
namespace DATA::VERTEX
{
	// �� �\���� �� //

	// 3D���f���p�̒��_���̃t�H�[�}�b�g
	struct S_3D_Model_Vertex
	{
		// �� �ϐ��錾 �� //
		MATH::FORMAT::C_Float_3 vertex;	// ���_���W

		MATH::FORMAT::C_Float_2 uv;	// UV���W

		MATH::FORMAT::C_Float_3 normal;	// �@���x�N�g��

		MATH::FORMAT::C_Float_3 tangent;	// �^���W�F���g�x�N�g���i�ڐ��j

		MATH::FORMAT::C_Float_3 binormal_tangent;	// �o�C�m�[�}���^���W�F���g�x�N�g���i�]�@���j
	};
}


#endif // !D_INCLUDE_GUARD_S_3D_MODEL_VERTEX_H_FILE
