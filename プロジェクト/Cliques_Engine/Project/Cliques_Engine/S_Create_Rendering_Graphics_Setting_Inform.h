//����������������������������������������������//
// �ڍ�   �F�`��p�C�v���C���p���𐶐����邽�߂̏��̍\����
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_CREATE_RENDERING_GRAPHICS_SETTING_INFORM_H_FILE
#define D_INCLUDE_GUARD_C_CREATE_RENDERING_GRAPHICS_SETTING_INFORM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>
#include <string>

#include "C_Shader_Setting.h"
#include "Blend_Setting_Inform.h"
#include "Depth_Stencil_Setting_Inform.h"
#include "Rasterizer_Setting_Inform.h"
#include "Depth_Stencil_Setting_Inform.h"
#include "Rendering_Another_Setting_Inform.h"


// �� �l�[���X�y�[�X �� //

// �O���t�B�b�N�𐧌䂷��V�X�e���̏��𐶐����邽�߂̏����Ăяo�����߂̖��O
namespace RENDERING::API::CREATE
{
	// �� �\���� �� //

	// �u�����h�ݒ�𐶐����邽�߂̃f�[�^�̍\����
	struct S_Blend_Setting_Create_Data
	{
		RENDERING::INFORM::BLEND::E_BLEND_MODE blend_mode = RENDERING::INFORM::BLEND::E_BLEND_MODE::e_NORMAL;	// �u�����h���[�h

		RENDERING::INFORM::BLEND::E_BLEND_OPTION blend_option = RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_ADD;	// �u�����h�̕��@

		RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT draw_format = RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_2_FLOAT;	// �`�掞�̏������݌`��

		RENDERING::INFORM::BLEND::E_RENDERING_DRAW_COLOR draw_color = RENDERING::INFORM::BLEND::E_RENDERING_DRAW_COLOR::e_RGBA;	// �������ނƂ��̐F��
	};

	// �[�x�X�e���V���ݒ�𐶐����邽�߂̃f�[�^�̍\����
	struct S_Depth_Stencil_Create_Data
	{
		RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE mode = RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE::e_NO;	// �[�x�̃��[�h

		RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE write_rule = RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_ALWAYS;	// �[�x�l�������݃��[��

		RENDERING::INFORM::DEPTH_STENCIL::E_STENCIL_IS stencil_activate = RENDERING::INFORM::DEPTH_STENCIL::E_STENCIL_IS::e_NO_ACTIVE;	// �X�e���V����L���ɂ��邩�ǂ���
	};

	// ���X�^���C�U�ݒ�𐶐����邽�߂̃f�[�^�̍\����
	struct S_Rasterizer_Create_Data
	{
		RENDERING::INFORM::RASTERIZER::E_DRAW_MODE draw_mode = RENDERING::INFORM::RASTERIZER::E_DRAW_MODE::e_NORMAL;	// �I�u�W�F�N�g�`�惂�[�h

		RENDERING::INFORM::RASTERIZER::E_MESH_CULLING mesh_culling = RENDERING::INFORM::RASTERIZER::E_MESH_CULLING::e_FRONT;	// �J�����O���Ɏc��ʂ�\���Ō��߂�

		RENDERING::INFORM::RASTERIZER::E_MESH_FRONT mesh_front = RENDERING::INFORM::RASTERIZER::E_MESH_FRONT::e_CLOCK_WISE;	// �ʂ̕\���������߂鎞�̒��_�̕`�揇

		RENDERING::INFORM::RASTERIZER::E_ANTIALIASING antialiasing = RENDERING::INFORM::RASTERIZER::E_ANTIALIASING::e_DONT;	// �A���`�G�C���A�V���O�̃��[�h

		RENDERING::INFORM::RASTERIZER::S_Depth_Setting_Value depth_value;	// �[�x���ݒ�p�̒l

		bool flg_conservative = false;	// �ێ�I�ȃ��X�^���C�Y���s�����ǂ����̃t���O�Atrue�ŕێ�I�ȃ��X�^���C�Y���s��
	};

	// �`��p�C�v���C���p���𐶐����邽�߂̏��̍\����
	struct S_Create_Rendering_Graphics_Setting_Inform
	{
		ASSET::SHADER::C_Shader_Setting * shader_setting = nullptr;	// �V�F�[�_�[�ݒ���

		S_Depth_Stencil_Create_Data depth_stencil_data;	// �[�x�X�e���V���̐����p�f�[�^

		S_Rasterizer_Create_Data rasterizer_data;	// ���X�^���C�U�ݒ�̐����p�f�[�^

		std::vector<S_Blend_Setting_Create_Data> blend_setting;	// �u�����h�ݒ�̐����p�f�[�^

		RENDERING::INFORM::SETTING::S_Sampling_Setting_Inform sampling_setting;	// �T���v�����O�̐ݒ�
	};
}


#endif // !D_INCLUDE_GUARD_C_CREATE_RENDERING_GRAPHICS_SETTING_INFORM_H_FILE
