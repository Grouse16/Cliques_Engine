//����������������������������������������������//
// �ڍ�   �F�`��p�C�v���C���p���𐶐����邽�߂̏��̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_CREATE_RENDERING_GRAPHICS_SETTING_INFORM
#define D_INCLUDE_GUARD_C_CREATE_RENDERING_GRAPHICS_SETTING_INFORM


// �� �t�@�C���Ђ炫 �� //
#include <vector>
#include <string>

#include "C_Shader_Setting.h"
#include "E_BLEND_MODE.h"
#include "Depth_Stencil_Setting_Inform.h"
#include "Rasterizer_Setting_Inform.h"
#include "Depth_Stencil_Setting_Inform.h"
#include "Rendering_Another_Setting_Inform.h"


// �� �l�[���X�y�[�X �� //

// �O���t�B�b�N�𐧌䂷��V�X�e���̏��𐶐����邽�߂̏����Ăяo�����߂̖��O
namespace RENDERING::GRAPHICS::CREATE
{
	// �� �N���X �� //

	// �`��p�C�v���C���p���𐶐����邽�߂̏��̃N���X
	class C_Create_Rendering_Graphics_Setting_Inform
	{
	//==�� �p�u���b�N ��==//
	public:

		// �� �\���� �� //
		
		// �[�x�X�e���V���ݒ�𐶐����邽�߂̃f�[�^�̍\����
		struct S_Depth_Stencil_Create_Data
		{
			RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE mode = RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE::e_NO;	// �[�x�̃��[�h

			RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE write_rule = RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_DONT;	// �[�x�l�������݃��[��

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
		};

		// ���̑��ݒ�𐶐����邽�߂̃f�[�^�̍\����
		struct S_Another_Setting_Create_Data
		{
			std::vector<RENDERING::INFORM::BLEND_MODE::E_BLEND_MODE> blend_mode;	// �u�����h���[�h

			RENDERING::INFORM::SETTING::E_RENDERING_DRAW_FORMAT draw_format = RENDERING::INFORM::SETTING::E_RENDERING_DRAW_FORMAT::e_BYTE_2_FLOAT;	// �`�掞�̏������݌`��

			RENDERING::INFORM::SETTING::E_RENDERING_DRAW_COLOR draw_color = RENDERING::INFORM::SETTING::E_RENDERING_DRAW_COLOR::e_RGBA;	// �������ނƂ��̐F��
			
			RENDERING::INFORM::SETTING::S_Sampling_Setting_Inform sampling_setting;	// �T���v�����O�̐ݒ�
		};


		// �� �ϐ��錾 �� //
		ASSET::SHADER::C_Shader_Setting * shader_setting;	// �V�F�[�_�[�ݒ���

		S_Depth_Stencil_Create_Data depth_stencil_data;	// �[�x�X�e���V���̐����p�f�[�^

		S_Rasterizer_Create_Data rasterizer_data;	// ���X�^���C�U�ݒ�̐����p�f�[�^

		S_Another_Setting_Create_Data another_data;	// ���̑��Őݒ肷��f�[�^
	};
}


#endif // !D_INCLUDE_GUARD_C_CREATE_RENDERING_GRAPHICS_SETTING_INFORM
