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

//==�� �p�u���b�N ��==//

//-��- �ݒ� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�[�x�X�e���V���𖳌��ɂ��鎞�̐ݒ�
// ����   �FD3D12_GRAPHICS_PIPELINE_STATE_DESC & �p�C�v���C�������p���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Stencil_State_Setting_System::M_Disabled_Depth_Stencil(D3D12_GRAPHICS_PIPELINE_STATE_DESC & in_pso_desc)
{
    // �[�x�X�e���V����L���ɂ��邩�ǂ���
    in_pso_desc.DepthStencilState.DepthEnable = false;

    // �[�x�X�e���V���o�b�t�@�ւ̏������݂��s�����ǂ���
    in_pso_desc.DepthStencilState.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ZERO;

    // �����^�C�����V�����I�u�W�F�N�g�������̃f�[�^�Ɣ�r������@
    in_pso_desc.DepthStencilState.DepthFunc = D3D12_COMPARISON_FUNC_ALWAYS;

    // �X�e���V���e�X�g��L���ɂ��邩�ǂ���
    in_pso_desc.DepthStencilState.StencilEnable = false;

    // �X�e���V���f�[�^�ǂݎ�莞�̐ݒ�
    in_pso_desc.DepthStencilState.StencilReadMask = D3D12_DEFAULT_STENCIL_READ_MASK;

    // �X�e���V���f�[�^�������ݎ��̐ݒ�
    in_pso_desc.DepthStencilState.StencilWriteMask = D3D12_DEFAULT_STENCIL_WRITE_MASK;

    // �[�x�X�e���V���ɑ��郊�\�[�X�̃f�[�^�`��
    in_pso_desc.DSVFormat = DXGI_FORMAT_D32_FLOAT;

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
