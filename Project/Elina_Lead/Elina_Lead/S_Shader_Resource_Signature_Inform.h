//����������������������������������������������//
// �ڍ�   �F�V�F�[�_�[�̎��ʖ����Ǘ����邽�߂̍\���̂̐錾
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_S_SHADER_SIGNATURE_INFORM
#define D_INCLUDE_GUARD_S_SHADER_SIGNATURE_INFORM


// �� �t�@�C���Ђ炫 �� //
#include <vector>
#include <string>

#include "E_Shader_Kind.h"


// �� �l�[���X�y�[�X �� //

// �V�F�[�_�[�p�̒�`���Ăяo�����߂̖��O
namespace ASSET::SHADER
{
	// �� �\���� �� //

	// �萔�o�b�t�@�̎��ʗp�̏��̍\����
	struct S_Constant_Resource_Signature
	{
		std::string signature_name = "";	// ���ʗp�̖��O

		int array_sum = 0;	// �z��

		bool data_create_flg = false;	// �f�[�^�𐶐����邩�ǂ����̃t���O
	};

	// �e�N�X�`���o�b�t�@�̎��ʗp�̏��̍\����
	struct S_Texture_Resource_Signature
	{
		std::string signature_name = "";	// ���ʗp�̖��O
		std::string initialized_texture_name = "";	// �g�p����e�N�X�`����
	};


	// �V�F�[�_�[�̃��\�[�X�̎��ʖ����Ǘ����邽�߂̍\����
	struct S_Shader_Resource_Signature_Inform
	{
		std::vector<S_Constant_Resource_Signature> constant_data;	// �萔�o�b�t�@�f�[�^���ʗp�̏��

		std::vector<S_Texture_Resource_Signature> texture_data;	// �e�N�X�`���f�[�^�̎��ʗp�̏��

		int sampler_sum = 0;	// �T���v���[��
	};


	// ���ׂẴV�F�[�_�[�̃��\�[�X�̎��ʖ����܂Ƃ߂邽�߂̍\����
	struct S_All_Shader_Resource_Signatures
	{
		S_Shader_Resource_Signature_Inform all_shader_signature;	// �S�ẴV�F�[�_�[�ɋ��ʂ��郊�\�[�X���ʖ�

		S_Shader_Resource_Signature_Inform signature_list[(int)E_SHADER_KIND::e_ALL];	// �V�F�[�_�[�̃��\�[�X
	};
}


#endif // !D_INCLUDE_GUARD_S_SHADER_SIGNATURE_INFORM

