//����������������������������������������������//
// �ڍ�   �F���f���̕`��ݒ�p�̃V�X�e��
// ����   �F�`��Ɏg�p����}�e���A���Ƃ��̃}�e���A���ŕ`�悷�郁�b�V���ꗗ������
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_S_MODEL_DRAW_COMMAND_H_FILE
#define D_INCLUDE_GUARD_S_MODEL_DRAW_COMMAND_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>
#include <string>

#include "C_Material_User.h"


// �� �l�[���X�y�[�X �� //

// ���f���p�̃V�X�e�����Ăяo�����߂̖��O
namespace ASSET::MODEL_SYSTEM
{
	// �� �� �� //

	// ���f���̕`��I�v�V�������w�肷���
	enum class E_MODEL_DRAW_OPTION : char
	{
		e_NATURAL_DRAW,			// �ʏ�`��
		e_MATERIAL_ORIGINAL,	// �}�e���A�����Z�b�g���ĕ`��
		e_SELECT_MESH,			// ���b�V�����w�肵�ĕ`��
		e_SELECT_MESH_AND_MATERIAL_ORIGINAL,	// ���b�V�����w�肵�������Ń}�e���A�����Z�b�g���ĕ`��
	};


	// �� �\���� �� //

	// ���f���̕`��ݒ�
	struct S_Model_Draw_Command
	{
		ASSET::MATERIAL::C_Material_User material_data;	// �`��Ɏg���}�e���A���̃f�[�^

		std::vector<std::string> mesh_name_list;	// ���̃}�e���A���ŕ`�悷�郁�b�V�����̃��X�g

		E_MODEL_DRAW_OPTION model_draw_option = E_MODEL_DRAW_OPTION::e_NATURAL_DRAW;	// ���f���̕`����@���w�肷��t���O
	};
}


#endif // !D_INCLUDE_GUARD_S_MODEL_DRAW_COMMAND_H_FILE

