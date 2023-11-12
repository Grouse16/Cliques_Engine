//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�����p�̒��_�f�[�^�̍\����
// ����   �F�A�j���[�V��������3D���f���ɕK�v�Ȓ��_�f�[�^�݂̂��܂Ƃ߂��\����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_S_3D_ANIMATION_MODEL_VERTEX_H_FILE
#define D_INCLUDE_GUARD_S_3D_ANIMATION_MODEL_VERTEX_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "Color_Data.h"
#include "C_Float_4.h"
#include "C_Float_3.h"
#include "C_Float_2.h"


// �� �l�[���X�y�[�X �� //

// ���_�f�[�^���Ăяo�����߂̖��O
namespace DATA::VERTEX
{
	// �� �\���� �� //	

	// �A�j���[�V�����p���_�f�[�^�̍\����
	struct S_3D_Animation_Model_Vertex
	{
		MATH::FORMAT::C_Float_3 vertex;	// ���_���W

		MATH::FORMAT::C_Float_2 uv;	// UV���W

		DATA::COLOR::C_Color color;	// �J���[

		MATH::FORMAT::C_Float_3 normal;	// �@���x�N�g��

		MATH::FORMAT::C_Float_3 tangent;	// �^���W�F���g�x�N�g���i�ڐ��j

		MATH::FORMAT::C_Float_3 binormal_tangent;	// �o�C�m�[�}���^���W�F���g�x�N�g���i�]�@���j

		int bone_index[4] = { 0, 0, 0, 0 };	// �{�[���̃C���f�b�N�X�̃��X�g

		MATH::FORMAT::C_Float_4 bone_weight;	// �E�F�C�g�l�i�{�[������̉e���ʁj
	};
}


#endif // !D_INCLUDE_GUARD_S_3D_ANIMATION_MODEL_VERTEX_H_FILE
