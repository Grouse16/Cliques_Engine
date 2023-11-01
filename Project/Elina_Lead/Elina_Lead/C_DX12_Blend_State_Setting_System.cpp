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

//==�� �p�u���b�N ��==//

//-��- �ݒ� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�̃T�C�Y�̍X�V���s��
// ����   �FD3D12_GRAPHICS_PIPELINE_STATE_DESC & �p�C�v���C���X�e�[�g�̐����p���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Blend_State_Setting_System::M_Set_All_Color_Add_Blend_To_PSO(D3D12_GRAPHICS_PIPELINE_STATE_DESC & in_pso_desc)
{
    // �� �ϐ��錾 �� //
    int sum_rendertarget = _countof(in_pso_desc.BlendState.RenderTarget);   // �����_�[�^�[�Q�b�g��


    // �u�����h�X�e�[�g��S�ď�����
    for (int loop_x = 0; loop_x < sum_rendertarget; loop_x++)
    {
        // �� ��Ԑݒ� �� //

        // �u�����h�̗L������
        in_pso_desc.BlendState.RenderTarget[loop_x].BlendEnable = TRUE;

        // �_�����Z�̗L�������i�u�����h�ƃ��W�b�N�����𓯎���TRUE�ɂ��Ă͂Ȃ�Ȃ��j
        in_pso_desc.BlendState.RenderTarget[loop_x].LogicOpEnable = FALSE;


        // �� RGB�l �� //

        // �s�N�Z���V�F�[�_�[���o�͂���RGB�l�̑���i�㏑������F�̑���̒�`�j
        in_pso_desc.BlendState.RenderTarget[loop_x].SrcBlend = D3D12_BLEND_SRC_ALPHA;

        // �����_�[�^�[�Q�b�g�̍���RGB�l�̑���i�㏑������鑤�̐F�̑���̒�`�j
        in_pso_desc.BlendState.RenderTarget[loop_x].DestBlend = D3D12_BLEND_INV_SRC_ALPHA;

        // SRC(�㏑�����鑤)��DEST(�㏑������鑤)��RGB�l����������@
        in_pso_desc.BlendState.RenderTarget[loop_x].BlendOp = D3D12_BLEND_OP_ADD;


        // �� ���l �� //

        // �s�N�Z���V�F�[�_�[���o�͂������l�̑���i�㏑������F�̑���̒�`�j
        in_pso_desc.BlendState.RenderTarget[loop_x].SrcBlendAlpha = D3D12_BLEND_ONE;

        // �����_�[�^�[�Q�b�g�̍��̃��l�̑���i�㏑������鑤�̐F�̑���̒�`�j
        in_pso_desc.BlendState.RenderTarget[loop_x].DestBlendAlpha = D3D12_BLEND_ZERO;

        // SRC(�㏑�����鑤)��DEST(�㏑������鑤)�̃��l����������@
        in_pso_desc.BlendState.RenderTarget[loop_x].BlendOpAlpha = D3D12_BLEND_OP_ADD;


        // �� �_������ �� //

        // �����_�[�^�[�Q�b�g�ɑ΂���_������̎w��
        in_pso_desc.BlendState.RenderTarget[loop_x].LogicOp = D3D12_LOGIC_OP_NOOP;


        // �� �}�X�N �� //

        // �u�����h���ɏ������݉\�ȐF���w�肷��
        in_pso_desc.BlendState.RenderTarget[loop_x].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
    }


	return;
}
