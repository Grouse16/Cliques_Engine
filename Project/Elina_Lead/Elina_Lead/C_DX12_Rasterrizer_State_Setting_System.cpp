//����������������������������������������������//
// �ڍ�   �F���X�^���C�U�ݒ�p�̃N���X
// ����   �F���X�^���C�U�̐ݒ�p�̏������܂Ƃ߂邽�߂̃N���X
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_DX12_Rasterizer_State_Setting_System.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �ݒ� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�������Ƀ��X�^���C�U�̐ݒ���s��
// ����   �FD3D12_GRAPHICS_PIPELINE_STATE_DESC & �p�C�v���C���ݒ�p���, const C_Create_Rendering_Graphics_Setting_Inform & �����_�����O�����p���(const)
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Rasterizer_State_Setting_System::M_Rasterizer_Setting(D3D12_GRAPHICS_PIPELINE_STATE_DESC & in_pipeline_state_setting_desc, const RENDERING::GRAPHICS::CREATE::S_Create_Rendering_Graphics_Setting_Inform & in_create_inform)
{
    //-��- �\�����[�h�ɂ���Đݒ���e�𕪊� -��-//
    switch (in_create_inform.rasterizer_data.draw_mode)
    {
        // �ʏ�ʂ�̕`��
    case RENDERING::INFORM::RASTERIZER::E_DRAW_MODE::e_NORMAL:
    default:
        in_pipeline_state_setting_desc.RasterizerState.FillMode = D3D12_FILL_MODE::D3D12_FILL_MODE_SOLID;
        break;

        // ���C���[�t���[���\���i�ӂ̂ݕ`��j
    case RENDERING::INFORM::RASTERIZER::E_DRAW_MODE::e_WIRE_FRAME:
        in_pipeline_state_setting_desc.RasterizerState.FillMode = D3D12_FILL_MODE::D3D12_FILL_MODE_WIREFRAME;
        break;
    }


    //-��- �J�����O���@�̎w��ɂ���Đݒ���e�𕪊� -��-//
    switch (in_create_inform.rasterizer_data.mesh_culling)
    {
        // �J�����O�͂��Ȃ�
    case RENDERING::INFORM::RASTERIZER::E_MESH_CULLING::e_ALWAYS:
        in_pipeline_state_setting_desc.RasterizerState.CullMode = D3D12_CULL_MODE::D3D12_CULL_MODE_NONE;
        break;

        // ���ʂ��J�����O
    case RENDERING::INFORM::RASTERIZER::E_MESH_CULLING::e_FRONT:
        in_pipeline_state_setting_desc.RasterizerState.CullMode = D3D12_CULL_MODE::D3D12_CULL_MODE_NONE;
        break;

        // �O�ʂ��J�����O
    case RENDERING::INFORM::RASTERIZER::E_MESH_CULLING::e_BACK:
        in_pipeline_state_setting_desc.RasterizerState.CullMode = D3D12_CULL_MODE::D3D12_CULL_MODE_NONE;
        break;
    }


    //-��- �\�����̕����ɂ���Đݒ���e�𕪊� -��-//
    switch (in_create_inform.rasterizer_data.mesh_front)
    {
        // ���v��肪�\����
    case RENDERING::INFORM::RASTERIZER::E_MESH_FRONT::e_CLOCK_WISE:
        in_pipeline_state_setting_desc.RasterizerState.FrontCounterClockwise = FALSE;
        break;

        // �����v��肪�\����
    case RENDERING::INFORM::RASTERIZER::E_MESH_FRONT::e_ANTI_CLOCK_WISE:
        in_pipeline_state_setting_desc.RasterizerState.FrontCounterClockwise = TRUE;
        break;
    }


    //-��- �[�x�Ɋւ���l��ݒ� -��-//

    // �s�N�Z���ɑ΂���[�x�o�C�A�X(���s���l�������I�ɉ��Z)
    in_pipeline_state_setting_desc.RasterizerState.DepthBias = in_create_inform.rasterizer_data.depth_value.depth_bias;

    // �s�N�Z���̐[�x�o�C�A�X�̍ő�l
    in_pipeline_state_setting_desc.RasterizerState.DepthBiasClamp = in_create_inform.rasterizer_data.depth_value.depth_max;

    // �[�x�o�C�A�X�̍ő�l���ݒ肳��Ă���Ƃ��̂ݐ[�x�l�̃N���b�s���O�L��
    if (in_pipeline_state_setting_desc.RasterizerState.DepthBiasClamp > 0.0f)
    {
        in_pipeline_state_setting_desc.RasterizerState.DepthClipEnable = TRUE;
    }
    // �ݒ肳��Ă��Ȃ��Ȃ疳��
    else
    {
        in_pipeline_state_setting_desc.RasterizerState.DepthClipEnable = FALSE;
    }

    // �X�Ε\���̂��߂̃X���[�v�\�����x
    in_pipeline_state_setting_desc.RasterizerState.SlopeScaledDepthBias = in_create_inform.rasterizer_data.depth_value.depth_slope;


    //-��- �A���`�G�C���A�V���O�̕��@�ɂ���Đݒ�𕪊� -��-//
    switch (in_create_inform.rasterizer_data.antialiasing)
    {
        // �s�N�Z���ɂ����
    case RENDERING::INFORM::RASTERIZER::E_ANTIALIASING::e_PIXEL:

        // �l�p�`��(TRUE)���A���t�@��(FALSE)���ǂ����̃A���`�G�C���A�V���O�A���S���Y�����g�p���邩
        in_pipeline_state_setting_desc.RasterizerState.MultisampleEnable = TRUE;

        // ����A���`�G�C���A�V���O��L���ɂ��邩�ǂ���
        in_pipeline_state_setting_desc.RasterizerState.AntialiasedLineEnable = FALSE;
        break;

        // �A���t�@�l�ɂ���ԁ@�iDirectX�ɃA���`�G�C���A�V���O�����Ȃ��Ƃ������ڂ͂Ȃ��j
    case RENDERING::INFORM::RASTERIZER::E_ANTIALIASING::e_ALPHA:
    case RENDERING::INFORM::RASTERIZER::E_ANTIALIASING::e_DONT:
    default:

        // �l�p�`��(TRUE)���A���t�@��(FALSE)���ǂ����̃A���`�G�C���A�V���O�A���S���Y�����g�p���邩
        in_pipeline_state_setting_desc.RasterizerState.MultisampleEnable = FALSE;

        // �ӊ�ł̃A���`�G�C���A�V���O��L���ɂ��邩�ǂ���
        in_pipeline_state_setting_desc.RasterizerState.AntialiasedLineEnable = FALSE;
        break;

        // �ӊ�ł̕��
    case RENDERING::INFORM::RASTERIZER::E_ANTIALIASING::e_LINE:

        // �l�p�`��(TRUE)���A���t�@��(FALSE)���ǂ����̃A���`�G�C���A�V���O�A���S���Y�����g�p���邩
        in_pipeline_state_setting_desc.RasterizerState.MultisampleEnable = FALSE;

        // ����A���`�G�C���A�V���O��L���ɂ��邩�ǂ���
        in_pipeline_state_setting_desc.RasterizerState.AntialiasedLineEnable = FALSE;
        break;
    }


    // UAV�̃��X�^���C�Y�ŋ�������T���v����
    in_pipeline_state_setting_desc.RasterizerState.ForcedSampleCount = in_create_inform.sampling_setting.sampling_count;


    //-��- �ێ�I�ȃ��X�^���C�Y���s������ݒ� -��-//
    switch (in_create_inform.rasterizer_data.flg_conservative)
    {
        // ����
    case false:
    default:
        in_pipeline_state_setting_desc.RasterizerState.ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE::D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;
        break;

        // �L��
    case true:
        in_pipeline_state_setting_desc.RasterizerState.ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE::D3D12_CONSERVATIVE_RASTERIZATION_MODE_ON;
        break;
    }

	return;
}
