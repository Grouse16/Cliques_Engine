//����������������������������������������������//
// �ڍ�   �F�u�����h�X�e�[�g�ݒ�p�̃N���X
// ����   �F�u�����h�X�e�[�g�̐ݒ�p�̏������܂Ƃ߂邽�߂̃N���X
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_DX12_Blend_State_Setting_System.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE;


// �� �֐� ��//

//==�� �v���C�x�[�g ��==//

//-��- �ݒ� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�ʏ�`�掞�̃u�����h��o�^
// ����   �FD3D12_RENDER_TARGET_BLEND_DESC & �o�^��̃u�����h�ݒ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Blend_State_Setting_System::M_Attach_Normal_Blend_Setting(D3D12_RENDER_TARGET_BLEND_DESC & in_blend_setting)
{
	// �u�����h���L����
	in_blend_setting.BlendEnable = true;

	// �_�����삪�L����������
	in_blend_setting.LogicOpEnable = false;

	
	//-��- RGB�F -��-//

	// �s�N�Z���V�F�[�_�[�̏o�͐F�̐ݒ�
	in_blend_setting.SrcBlend = D3D12_BLEND::D3D12_BLEND_SRC_COLOR;

	// �����_�[�^�[�Q�b�g�̐F�̎g�p���@
	in_blend_setting.DestBlend = D3D12_BLEND::D3D12_BLEND_DEST_COLOR;


	//-��- ���l -��-//

	// �s�N�Z���V�F�[�_�[�̏o�̓��l�̐ݒ�
	in_blend_setting.SrcBlendAlpha = D3D12_BLEND::D3D12_BLEND_SRC_ALPHA;

	// �����_�[�^�[�Q�b�g�̃��l�̎g�p���@
	in_blend_setting.DestBlendAlpha = D3D12_BLEND::D3D12_BLEND_DEST_ALPHA;


	//-��- �_�����Z�I�v�V���� -��-//
	in_blend_setting.LogicOp = D3D12_LOGIC_OP_CLEAR;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�ʏ�`��Ń��l�݂̂P�Œ�̃u�����h��o�^
// ����   �FD3D12_RENDER_TARGET_BLEND_DESC & �o�^��̃u�����h�ݒ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Blend_State_Setting_System::M_Attach_Normal_And_One_Alpha_Blend_Setting(D3D12_RENDER_TARGET_BLEND_DESC & in_blend_setting)
{
	// �u�����h���L����
	in_blend_setting.BlendEnable = true;

	// �_�����삪�L����������
	in_blend_setting.LogicOpEnable = false;


	//-��- RGB�F -��-//

	// �s�N�Z���V�F�[�_�[�̏o�͐F�̐ݒ�
	in_blend_setting.SrcBlend = D3D12_BLEND::D3D12_BLEND_SRC_COLOR;

	// �����_�[�^�[�Q�b�g�̐F�̎g�p���@
	in_blend_setting.DestBlend = D3D12_BLEND::D3D12_BLEND_DEST_COLOR;


	//-��- ���l -��-//

	// �s�N�Z���V�F�[�_�[�̏o�̓��l�̐ݒ�
	in_blend_setting.SrcBlendAlpha = D3D12_BLEND::D3D12_BLEND_ONE;

	// �����_�[�^�[�Q�b�g�̃��l�̎g�p���@
	in_blend_setting.DestBlendAlpha = D3D12_BLEND::D3D12_BLEND_DEST_ALPHA;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���Z�����̕`��Ńu�����h��o�^
// ����   �FD3D12_RENDER_TARGET_BLEND_DESC & �o�^��̃u�����h�ݒ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Blend_State_Setting_System::M_Attach_Invert_Blend_Setting(D3D12_RENDER_TARGET_BLEND_DESC & in_blend_setting)
{
	// �u�����h���L����
	in_blend_setting.BlendEnable = true;

	// �_�����삪�L����������
	in_blend_setting.LogicOpEnable = false;


	//-��- RGB�F -��-//

	// �s�N�Z���V�F�[�_�[�̏o�͐F�̐ݒ�
	in_blend_setting.SrcBlend = D3D12_BLEND::D3D12_BLEND_INV_SRC_COLOR;

	// �����_�[�^�[�Q�b�g�̐F�̎g�p���@
	in_blend_setting.DestBlend = D3D12_BLEND::D3D12_BLEND_DEST_COLOR;


	//-��- ���l -��-//

	// �s�N�Z���V�F�[�_�[�̏o�̓��l�̐ݒ�
	in_blend_setting.SrcBlendAlpha = D3D12_BLEND::D3D12_BLEND_INV_DEST_ALPHA;

	// �����_�[�^�[�Q�b�g�̃��l�̎g�p���@
	in_blend_setting.DestBlendAlpha = D3D12_BLEND::D3D12_BLEND_DEST_ALPHA;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���Z�����̕`��Ń��l�݂̂P�Œ�̃u�����h��o�^
// ����   �FD3D12_RENDER_TARGET_BLEND_DESC & �o�^��̃u�����h�ݒ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Blend_State_Setting_System::M_Attach_Invert_And_One_Alpha_Blend_Setting(D3D12_RENDER_TARGET_BLEND_DESC & in_blend_setting)
{
	// �u�����h���L����
	in_blend_setting.BlendEnable = true;

	// �_�����삪�L����������
	in_blend_setting.LogicOpEnable = false;


	//-��- RGB�F -��-//

	// �s�N�Z���V�F�[�_�[�̏o�͐F�̐ݒ�
	in_blend_setting.SrcBlend = D3D12_BLEND::D3D12_BLEND_INV_SRC_COLOR;

	// �����_�[�^�[�Q�b�g�̐F�̎g�p���@
	in_blend_setting.DestBlend = D3D12_BLEND::D3D12_BLEND_DEST_COLOR;


	//-��- ���l -��-//

	// �s�N�Z���V�F�[�_�[�̏o�̓��l�̐ݒ�
	in_blend_setting.SrcBlendAlpha = D3D12_BLEND::D3D12_BLEND_ONE;

	// �����_�[�^�[�Q�b�g�̃��l�̎g�p���@
	in_blend_setting.DestBlendAlpha = D3D12_BLEND::D3D12_BLEND_DEST_ALPHA;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�[�^�[�Q�b�g�ɏ������ގ��̃t�H�[�}�b�g�𐶐��p�̏�񂩂犄��o���ĕԂ�
// ����   �FC_Create_Rendering_Graphics_Setting_Inform::S_Blend_Setting_Create_Data & �u�����h�ݒ�̐����p�f�[�^(const)
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
DXGI_FORMAT RENDERING::GRAPHICS::DX12::DX12INSTANCE::C_DX12_Blend_State_Setting_System::M_Get_Write_Rendering_Graph_Format_By_Create_Inform(const RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform::S_Blend_Setting_Create_Data & in_blend_setting)
{
	//-��- �������ގ��̐F���ɂ���ĕ��� -��-//
	switch (in_blend_setting.draw_color)
	{
		// R�̂�
	case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_COLOR::e_R:

		// �������ރf�[�^�̌`���ŕ���
		switch (in_blend_setting.draw_format)
		{
			// �P�o�C�g��UINT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_1_UINT:
			return DXGI_FORMAT::DXGI_FORMAT_R8_UINT;

			// �Q�o�C�g��UINT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_2_UINT:
			return DXGI_FORMAT::DXGI_FORMAT_R16_UINT;

			// �S�o�C�g��UINT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_4_UINT:
			return DXGI_FORMAT::DXGI_FORMAT_R32_UINT;

			// �Q�o�C�g��FLOAT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_2_FLOAT:
		default:
			return DXGI_FORMAT::DXGI_FORMAT_R16_FLOAT;

			// �S�o�C�g��FLOAT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_4_FLOAT:
			return DXGI_FORMAT::DXGI_FORMAT_R32_FLOAT;
		}
		

		// RG�̂�
	case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_COLOR::e_RG:

		// �������ރf�[�^�̌`���ŕ���
		switch (in_blend_setting.draw_format)
		{
			// �P�o�C�g��UINT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_1_UINT:
			return DXGI_FORMAT::DXGI_FORMAT_R8G8_UINT;

			// �Q�o�C�g��UINT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_2_UINT:
			return DXGI_FORMAT::DXGI_FORMAT_R16G16_UINT;

			// �S�o�C�g��UINT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_4_UINT:
			return DXGI_FORMAT::DXGI_FORMAT_R32G32_UINT;

			// �Q�o�C�g��FLOAT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_2_FLOAT:
		default:
			return DXGI_FORMAT::DXGI_FORMAT_R16G16_FLOAT;

			// �S�o�C�g��FLOAT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_4_FLOAT:
			return DXGI_FORMAT::DXGI_FORMAT_R32G32_FLOAT;
		}

		break;


		// RGBA�S��
	case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_COLOR::e_RGBA:
	default:

		// �������ރf�[�^�̌`���ŕ���
		switch (in_blend_setting.draw_format)
		{
			// �P�o�C�g��UINT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_1_UINT:
			return DXGI_FORMAT::DXGI_FORMAT_R8G8B8A8_UINT;

			// �Q�o�C�g��UINT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_2_UINT:
			return DXGI_FORMAT::DXGI_FORMAT_R16G16B16A16_UINT;

			// �S�o�C�g��UINT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_4_UINT:
			return DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_UINT;

			// �Q�o�C�g��FLOAT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_2_FLOAT:
		default:
			return DXGI_FORMAT::DXGI_FORMAT_R16G16B16A16_FLOAT;

			// �S�o�C�g��FLOAT
		case RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_4_FLOAT:
			return DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_FLOAT;
		}

		break;
	}

	return DXGI_FORMAT::DXGI_FORMAT_R16G16B16A16_FLOAT;
}


//==�� �p�u���b�N ��==//

//-��- �ݒ� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�������ƂɃu�����h�̐ݒ���s��
// ����   �FD3D12_GRAPHICS_PIPELINE_STATE_DESC & �ݒ��̃p�C�v���C���X�e�[�g���, const C_Creat_Rendering_Graphics_Setting_Inform & �����_�����O�ݒ萶���p�̏��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Blend_State_Setting_System::M_Set_Blend_State_By_Inform(D3D12_GRAPHICS_PIPELINE_STATE_DESC & in_pipeline_state_desc, const RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform & in_creat_inform)
{
	// �� �萔 �� //
	const char con_RENDER_TARGET_SUM = 8;	// �ݒ�\�ȃ����_�[�^�[�Q�b�g��

	
	// �� �ϐ��錾 �� //
	int use_render_target_sum = in_creat_inform.blend_setting.size();	// �g�p���郌���_�[�^�[�Q�b�g��


	// �����_�[�^�[�Q�b�g�̍ő吔�𒴂��Ȃ��悤�ɂ���
	use_render_target_sum =
		use_render_target_sum > con_RENDER_TARGET_SUM * con_RENDER_TARGET_SUM
		+
		use_render_target_sum <= con_RENDER_TARGET_SUM * use_render_target_sum;


	// �����_�[�^�[�Q�b�g�����̃u�����h�ݒ���s��
	for (int l_now_render_target_setting = 0; l_now_render_target_setting < con_RENDER_TARGET_SUM; l_now_render_target_setting++)
	{
		//-��- �w�肳�ꂽ�u�����h�̃��[�h�Őݒ���e�𕪊� -��-//
		switch (in_creat_inform.blend_setting[l_now_render_target_setting].blend_mode)
		{
			// �ʏ�ʂ�̕`��
		case RENDERING::INFORM::BLEND::E_BLEND_MODE::e_NORMAL:
		default:
			M_Attach_Normal_Blend_Setting(in_pipeline_state_desc.BlendState.RenderTarget[l_now_render_target_setting]);
			break;

			// �ʏ�ʂ�̕`��Ń��l�݂̂P�ŌŒ�
		case RENDERING::INFORM::BLEND::E_BLEND_MODE::e_NORMAL_NOT_ALPHA:
			M_Attach_Normal_And_One_Alpha_Blend_Setting(in_pipeline_state_desc.BlendState.RenderTarget[l_now_render_target_setting]);
			break;

			// ���Z�����̕`��
		case RENDERING::INFORM::BLEND::E_BLEND_MODE::e_INVERT:
			M_Attach_Invert_Blend_Setting(in_pipeline_state_desc.BlendState.RenderTarget[l_now_render_target_setting]);
			break;

			// ���Z�����̕`��Ń��l�݂̂P�ŌŒ�
		case RENDERING::INFORM::BLEND::E_BLEND_MODE::e_INVERT_NOT_ALPHA:
			M_Attach_Invert_And_One_Alpha_Blend_Setting(in_pipeline_state_desc.BlendState.RenderTarget[l_now_render_target_setting]);
			break;
		}


		//-��- �w�肳�ꂽ�������Ńu�����h�I�v�V�����̐ݒ�𕪊� -��-//
		switch (in_creat_inform.blend_setting[l_now_render_target_setting].blend_option)
		{
			// �s�N�Z���V�F�[�_�[�̐F�����Z
		case RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_ADD:
		default:
			in_pipeline_state_desc.BlendState.RenderTarget[l_now_render_target_setting].BlendOp = D3D12_BLEND_OP::D3D12_BLEND_OP_ADD;
			break;

			// �s�N�Z���V�F�[�_�[�̐F�����Z
		case RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_SUB:
			in_pipeline_state_desc.BlendState.RenderTarget[l_now_render_target_setting].BlendOp = D3D12_BLEND_OP::D3D12_BLEND_OP_SUBTRACT;
			break;

			// �s�N�Z���V�F�[�_�[�̐F�����݂̐F�Ō��Z
		case RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_SUB_PIX:
			in_pipeline_state_desc.BlendState.RenderTarget[l_now_render_target_setting].BlendOp = D3D12_BLEND_OP::D3D12_BLEND_OP_REV_SUBTRACT;
			break;

			// ���݂̐F�ƃs�N�Z���V�F�[�_�[�̐F���r�����Ƃ��̍ő�l
		case RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_MAX:
			in_pipeline_state_desc.BlendState.RenderTarget[l_now_render_target_setting].BlendOp = D3D12_BLEND_OP::D3D12_BLEND_OP_MAX;
			break;

			// ���݂̐F�ƃs�N�Z���V�F�[�_�[�̐F���r�����Ƃ��̍ő�l
		case RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_MIN:
			in_pipeline_state_desc.BlendState.RenderTarget[l_now_render_target_setting].BlendOp = D3D12_BLEND_OP::D3D12_BLEND_OP_MIN;
			break;
		}


		// �����_�[�^�[�Q�b�g�摜�ɏ������ނƂ��̃t�H�[�}�b�g��ݒ�
		in_pipeline_state_desc.RTVFormats[l_now_render_target_setting] = M_Get_Write_Rendering_Graph_Format_By_Create_Inform(in_creat_inform.blend_setting[l_now_render_target_setting]);
	}


	// �����_�[�^�[�Q�b�g�ɑ���Ȃ����\�[�X�͂��ׂď����l�ɂ���(���Ȃ���΃G���[)
	for (int l_now_format_setting = use_render_target_sum; l_now_format_setting < 8; l_now_format_setting++)
	{
		in_pipeline_state_desc.RTVFormats[l_now_format_setting] = DXGI_FORMAT::DXGI_FORMAT_UNKNOWN;
	}

	return;
}
