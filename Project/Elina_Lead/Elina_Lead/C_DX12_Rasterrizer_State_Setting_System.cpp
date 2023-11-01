//����������������������������������������������//
// �ڍ�   �F���X�^���C�U�ݒ�p�̃N���X
// ����   �F���X�^���C�U�̐ݒ�p�̏������܂Ƃ߂邽�߂̃N���X
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_DX12_Rasterrizer_State_Setting_System.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �ݒ� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�Ⴂ�R�X�g�Ń��X�^���C�Y����ۂ̐ݒ���s��
// ����   �FD3D12_GRAPHICS_PIPELINE_STATE_DESC & �p�C�v���C�������p���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Rasterrizer_State_Setting_System::M_Law_Cost_Setting(D3D12_GRAPHICS_PIPELINE_STATE_DESC & in_pso_desc)
{
    // �����_�����O���ʂ���ʂɔ��f����Ƃ��̃��[�h
    in_pso_desc.RasterizerState.FillMode = D3D12_FILL_MODE_SOLID;

    // ��(�O�p�`)�̕����ɂ���ĕ\�����邩���Ȃ������w�肷��
    in_pso_desc.RasterizerState.CullMode = D3D12_CULL_MODE_NONE;

    // �����v����\�A���v���𗠂Ɣ��肷�邩�ǂ���
    in_pso_desc.RasterizerState.FrontCounterClockwise = false;

    // �s�N�Z���ɑ΂���[�x�o�C�A�X(���s���\��)
    in_pso_desc.RasterizerState.DepthBias = D3D12_DEFAULT_DEPTH_BIAS;

    // �s�N�Z���̐[�x�o�C�A�X�̍ő�l
    in_pso_desc.RasterizerState.DepthBiasClamp = D3D12_DEFAULT_DEPTH_BIAS_CLAMP;

    // �X�Ε\���̂��߂̃X�J���[
    in_pso_desc.RasterizerState.SlopeScaledDepthBias = D3D12_DEFAULT_SLOPE_SCALED_DEPTH_BIAS;

    // �����ɂ��N���b�s���O(�F�̂͂ݏo���̖h�~)�����邩�ǂ����̃t���O
    in_pso_desc.RasterizerState.DepthClipEnable = true;

    // �l�p�`��(TRUE)���A���t�@��(FALSE)���ǂ����̃A���`�G�C���A�V���O�A���S���Y�����g�p���邩
    in_pso_desc.RasterizerState.MultisampleEnable = false;

    // ����A���`�G�C���A�V���O��L���ɂ��邩�ǂ���
    in_pso_desc.RasterizerState.AntialiasedLineEnable = false;

    // UAV�̃��X�^���C�Y�ŋ�������T���v����
    in_pso_desc.RasterizerState.ForcedSampleCount = 0;

    // �ێ�I�ȃ��X�^���C�Y���s�����ǂ���(�ێ炩������)
    in_pso_desc.RasterizerState.ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;

	return;
}
