//����������������������������������������������//
// �ڍ�   �F�X�g���[�~���O�o�͗p�o�b�t�@�̊��N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_DX12_Streaming_Output_Buffer_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::API::DX12::DX12_TOOL;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�X�g���[�~���O�o�͗p�o�b�t�@���g�p���Ȃ����̏��������s��
// ����   �FD3D12_GRAPHICS_PIPELINE_STATE_DESC & �p�C�v���C�������p���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Streaming_Output_Buffer_Base::M_Do_Not_Use_Setting(D3D12_GRAPHICS_PIPELINE_STATE_DESC & in_pipeline_desc)
{
    // �X�g���[�~���O�o�̓X���b�g�̒��_�o�b�t�@�̒��_�v�f�p�̍\���̂̔z��̃A�h���X
    in_pipeline_desc.StreamOutput.pSODeclaration = nullptr;

    // ��L�A���_�o�b�t�@�̒��_�v�f�p�̍\���̂̔z��̔z��
    in_pipeline_desc.StreamOutput.NumEntries = 0;

    // ���_�̃X�g���C�h(�s�b�`)�̔z��̃A�h���X�i�o�b�t�@�̗v�f�̃T�C�Y�j
    in_pipeline_desc.StreamOutput.pBufferStrides = nullptr;

    // ��L�A���_�̃X�g���C�h(�s�b�`)�̔z��̔z��
    in_pipeline_desc.StreamOutput.NumStrides = 0;

    // ���X�^���C�U�[�ɑ���X�g���[���o�̓o�b�t�@�̉�ʔԍ�(�C���f�b�N�X�ԍ�)
    in_pipeline_desc.StreamOutput.RasterizedStream = 0;

	return;
}
