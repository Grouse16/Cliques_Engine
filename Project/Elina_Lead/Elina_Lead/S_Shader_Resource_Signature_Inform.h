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
	// �� �� �� //

	// ���\�[�X�̎��
	enum class E_RESOURCE_KIND : char
	{
		e_CONSTANT_BUFFER,	// �萔�o�b�t�@
		e_TEXTURE,			// �e�N�X�`��
	};


	// �� �\���� �� //

	// �萔�o�b�t�@�̃��\�[�X���̍\����
	struct S_Constant_Resource_Inform
	{
		E_SHADER_KIND shader_kind = E_SHADER_KIND::e_ALL;	// �ݒ��̃V�F�[�_�[�̎��

		std::string resource_name = "default";	// �萔�o�b�t�@�̖��O

		int array_sum = 0;	// �萔�o�b�t�@�̔z��

		bool flg_data_creation = false;	// �f�[�^�𐶐����邩�ǂ����̃t���O

		int slot_number = 0;	// �X���b�g�ԍ�
	};


	// �e�N�X�`���o�b�t�@�̃��\�[�X���̍\����
	struct S_Texture_Resource_Inform
	{
		E_SHADER_KIND shader_kind = E_SHADER_KIND::e_ALL;	// �ݒ��̃V�F�[�_�[�̎��

		std::string resource_name = "default";	// �e�N�X�`���̖��O
		std::string initialize_texture_name = "default";	// �������[�h����e�N�X�`����

		int slot_number = 0;	// �X���b�g�ԍ�
	};


	// �����_�����O��ʂ̃��\�[�X���̍\����
	struct S_Screen_Resource_Inform
	{
		E_SHADER_KIND shader_kind = E_SHADER_KIND::e_ALL;	// �ݒ��̃V�F�[�_�[�̎��

		std::string resource_name = "default";	// �e�N�X�`���̖��O

		int slot_number = 0;	// �X���b�g�ԍ�
	};


	// �[�x�X�e���V���̃��\�[�X���̍\����
	struct S_Depth_Stencil_Resource_Inform
	{
		E_SHADER_KIND shader_kind = E_SHADER_KIND::e_ALL;	// �ݒ��̃V�F�[�_�[�̎��

		std::string resource_name = "default";	// �e�N�X�`���̖��O

		int slot_number = 0;	// �X���b�g�ԍ�
	};


	// �T���v���[�̃��\�[�X���̍\����
	struct S_Sampler_Resource_Inform
	{
		E_SHADER_KIND shader_kind = E_SHADER_KIND::e_ALL;	// �ݒ��̃V�F�[�_�[�̎��

		std::string uv_setting = "";	// UV�̎g�p���@
	};


	// �X���b�g�̏��̍\����
	struct S_Resource_Slot_Inform
	{
		E_RESOURCE_KIND resource_kind = E_RESOURCE_KIND::e_CONSTANT_BUFFER;	// ���\�[�X�̎��

		E_SHADER_KIND shader_kind = E_SHADER_KIND::e_ALL;	// �ݒ��̃V�F�[�_�[�̎��
	};


	// ���\�[�X�̏����܂Ƃ߂��\����
	struct S_Resource_Inform_List
	{
		std::vector<S_Constant_Resource_Inform> constant_list;	// �萔�o�b�t�@�̏�񃊃X�g

		std::vector<S_Texture_Resource_Inform> texture_list;	// �e�N�X�`���̏�񃊃X�g

		std::vector<S_Screen_Resource_Inform> screen_list;	// �����_�����O��ʂ̏�񃊃X�g

		std::vector<S_Depth_Stencil_Resource_Inform> depth_stencil_list;	// �[�x�X�e���V���̏�񃊃X�g

		std::vector<S_Sampler_Resource_Inform> sampler_list;	// �T���v���[�̏�񃊃X�g

		std::vector<S_Resource_Slot_Inform> slot_list;	// �X���b�g�̏�񃊃X�g
	};
}


#endif // !D_INCLUDE_GUARD_S_SHADER_SIGNATURE_INFORM

