//����������������������������������������������//
// �ڍ�   �F�T���v�����O�ݒ�p�̃N���X
// ����   �F�T���v�����O�ݒ�p�̏������܂Ƃ߂邽�߂̃N���X
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_DX12_Sampling_Setting_System.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �ݒ� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�T���v�����O�ݒ���܂Ƃ߂čs��
// ����   �F�����FD3D12_GRAPHICS_PIPELINE_STATE_DESC & �p�C�v���C�������p���, UINT �T���v�����O��, UINT �N�I���e�B, UINT �m�[�h��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Sampling_Setting_System::M_Sampling_Setting(D3D12_GRAPHICS_PIPELINE_STATE_DESC & in_pso_desc, UINT in_sampling_count, UINT in_quality, UINT in_node_sum)
{
    // �P�s�N�Z���ɑ΂��ă����_�����O�T���v����p�ӂ��鐔
    in_pso_desc.SampleDesc.Count = in_sampling_count;

    // �掿�̃��x���A�����Ɖ掿���ǂ��Ȃ邪�p�t�H�[�}���X�������Ȃ�
    in_pso_desc.SampleDesc.Quality = in_quality;

    // �p�C�v���C���ɓK������m�[�h(GPU�╨���A�_�v�^�[)�̐�
    in_pso_desc.NodeMask = in_node_sum;

	return;
}
