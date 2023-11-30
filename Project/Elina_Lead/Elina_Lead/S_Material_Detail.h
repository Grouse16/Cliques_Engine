//����������������������������������������������//
// �ڍ�   �F�������p�̃f�[�^
// ����   �F�V�F�[�_�[��`�Ȃǃ}�e���A���ݒ��Material�@��������Material_Detail�Ƃ���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_S_MATERIAL_DETAIL_H_FILE
#define D_INCLUDE_GUARD_S_MATERIAL_DETAIL_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_Float_4.h"


// �� �l�[���X�y�[�X �� //

// �������̒�`���Ăяo�����߂̖��O
namespace DATA::MATERIAL_DETAIL
{
	// �� �\���� �� //

	// �������̍\����
	struct S_Material_Detail
	{
		MATH::FORMAT::C_Float_4 ambient;		// �A���r�G���g
		MATH::FORMAT::C_Float_4 diffuse;		// �f�B�t���[�Y
		MATH::FORMAT::C_Float_4 emission;		// �G�~�b�V����
		MATH::FORMAT::C_Float_4 reflection;		// ���t���N�V����
		MATH::FORMAT::C_Float_4 specular;		// �X�y�L�����[
		MATH::FORMAT::C_Float_4 transparent;	// �g�����X�y�A�����g
	};
}


#endif // !D_INCLUDE_GUARD_S_MATERIAL_DETAIL_H_FILE
