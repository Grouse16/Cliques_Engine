//����������������������������������������������//
// �ڍ�   �F�[�x�X�e���V���ݒ�p�̃N���X
// ����   �F�[�x�X�e���V���̐ݒ�p�̏������܂Ƃ߂邽�߂̃N���X
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_DX12_Stencil_State_Setting_System.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- �ݒ� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���ƈ�v�����[�x�l�̏������ݕ��@��Ԃ�
// ����   �FE_DEPTH_WRITE_RULE �[�x�l�������݃��[��
// �߂�l �FD3D12_COMPARISON_FUNC �[�x�l�̏������ݕ��@
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
D3D12_COMPARISON_FUNC C_DX12_Stencil_State_Setting_System::M_Get_Depth_Write_Option(RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE in_write_rule)
{
    //-��- �������ގ��̃��[���ɂ���Đݒ�𕪊� -��-//
    switch (in_write_rule)
    {
        // �������܂Ȃ�
    case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_DONT:
    default:
        return D3D12_COMPARISON_FUNC::D3D12_COMPARISON_FUNC_NEVER;

        // �S�ď㏑������
    case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_ALWAYS:
        return D3D12_COMPARISON_FUNC::D3D12_COMPARISON_FUNC_ALWAYS;

        // ���̒l�Ɠ������Ƃ�
    case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_EQUAL:
        return D3D12_COMPARISON_FUNC::D3D12_COMPARISON_FUNC_EQUAL;

        // ���̒l�ƈႤ�Ƃ�
    case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_NOT_EQUAL:
        return D3D12_COMPARISON_FUNC::D3D12_COMPARISON_FUNC_NOT_EQUAL;

        // ���̒l�����傫���Ƃ�
    case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_GREATER:
        return D3D12_COMPARISON_FUNC::D3D12_COMPARISON_FUNC_GREATER;

        // ���̒l�����������Ƃ�
    case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_LESS:
        return D3D12_COMPARISON_FUNC::D3D12_COMPARISON_FUNC_LESS;

        // ���̒l�ȏ�̂Ƃ�
    case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_GREATERE_EQUAL:
        return D3D12_COMPARISON_FUNC::D3D12_COMPARISON_FUNC_GREATER_EQUAL;

        // ���̒l�ȉ��̂Ƃ�
    case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_LESS_EQUAL:
        return D3D12_COMPARISON_FUNC::D3D12_COMPARISON_FUNC_LESS_EQUAL;
    }
}


//==�� �p�u���b�N ��==//

//-��- �ݒ� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�[�x�X�e���V���𐶐��p�������Ƃɐݒ肷��
// ����   �FD3D12_GRAPHICS_PIPELINE_STATE_DESC & �p�C�v���C���ݒ�p���, const C_Create_Rendering_Graphics_Setting_Inform & �����_�����O�����p���(const)
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Stencil_State_Setting_System::M_Depth_Stencil_Setting(D3D12_GRAPHICS_PIPELINE_STATE_DESC & in_pipeline_state_setting_desc, const RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform & in_create_inform)
{
    //-��- �[�x�̃��[�h�ɂ���Đݒ�𕪊� -��-//
    switch (in_create_inform.depth_stencil_data.mode)
    {
        // �[�x�𖳌�
    case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE::e_NO:
    default:

        // �[�x��L���ɂ��邩�ǂ���
        in_pipeline_state_setting_desc.DepthStencilState.DepthEnable = FALSE;

        // �[�x�o�b�t�@�ւ̏������݂��s�����ǂ���
        in_pipeline_state_setting_desc.DepthStencilState.DepthWriteMask = D3D12_DEPTH_WRITE_MASK::D3D12_DEPTH_WRITE_MASK_ZERO;

        break;

        // �ύX�ł���͈͂��O�Ɏw��
    case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE::e_ZERO:

        // �[�x��L���ɂ��邩�ǂ���
        in_pipeline_state_setting_desc.DepthStencilState.DepthEnable = TRUE;

        // �㏑�����邱�Ƃ��ł���͈�
        in_pipeline_state_setting_desc.DepthStencilState.DepthWriteMask = D3D12_DEPTH_WRITE_MASK::D3D12_DEPTH_WRITE_MASK_ZERO;

        break;

        // �ύX�ł���͈͂��P�Ɏw��
    case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE::e_ONE:

        // �[�x��L���ɂ��邩�ǂ���
        in_pipeline_state_setting_desc.DepthStencilState.DepthEnable = TRUE;

        // �㏑�����邱�Ƃ��ł���͈�
        in_pipeline_state_setting_desc.DepthStencilState.DepthWriteMask = D3D12_DEPTH_WRITE_MASK::D3D12_DEPTH_WRITE_MASK_ALL;

        break;
    }

    
    // �[�x�̏������ݕ��@���w��
    in_pipeline_state_setting_desc.DepthStencilState.DepthFunc = M_Get_Depth_Write_Option(in_create_inform.depth_stencil_data.write_rule);


    //-��- �X�e���V����L���ɂ��邩�ǂ����Őݒ�𕪊� -��-//
    switch (in_create_inform.depth_stencil_data.stencil_activate)
    {
        // ����
    case RENDERING::INFORM::DEPTH_STENCIL::E_STENCIL_IS::e_NO_ACTIVE:

        in_pipeline_state_setting_desc.DepthStencilState.StencilEnable = FALSE;
        break;

        // �L��
    case RENDERING::INFORM::DEPTH_STENCIL::E_STENCIL_IS::e_ACTIVE:

        in_pipeline_state_setting_desc.DepthStencilState.StencilEnable = TRUE;
        break;
    }

    // �X�e���V���f�[�^�ǂݎ�莞�̐ݒ�
    in_pipeline_state_setting_desc.DepthStencilState.StencilReadMask = D3D12_DEFAULT_STENCIL_READ_MASK;

    // �X�e���V���f�[�^�������ݎ��̐ݒ�
    in_pipeline_state_setting_desc.DepthStencilState.StencilWriteMask = D3D12_DEFAULT_STENCIL_WRITE_MASK;

    // �[�x�X�e���V���ɑ��郊�\�[�X�̃f�[�^�`��
    in_pipeline_state_setting_desc.DSVFormat = DXGI_FORMAT::DXGI_FORMAT_D32_FLOAT;

	return;
}


//-��- �e�X�g�ݒ� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�[�x�X�e���V���𖳌��ɂ��鎞�̐ݒ�
// ����   �FD3D12_DEPTH_STENCILOP_DESC & �p�C�v���C�������p���̃X�e���V���e�X�g�ݒ蕔��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Stencil_State_Setting_System::M_Test_Keep_Setting(D3D12_DEPTH_STENCILOP_DESC & in_stencil_op)
{
    // �X�e���V���e�X�g���s�����Ƃ��ɂǂ����邩
    in_stencil_op.StencilFailOp = D3D12_STENCIL_OP_KEEP;

    // �[�x�e�X�g�Ɏ��s�����Ƃ��ɂǂ����邩
    in_stencil_op.StencilDepthFailOp = D3D12_STENCIL_OP_KEEP;

    // �X�e���V���Ɛ[�x�����̃e�X�g�����������Ƃ��ɂǂ����邩
    in_stencil_op.StencilPassOp = D3D12_STENCIL_OP_KEEP;

    // �V�����X�e���V���f�[�^�ƍ��̃f�[�^�̔�r���@
    in_stencil_op.StencilFunc = D3D12_COMPARISON_FUNC_ALWAYS;

    return;
}
