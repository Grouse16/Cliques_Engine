//����������������������������������������������//
// �ڍ�   �F�p�C�v���C���X�e�[�g�̏�Ԃ��󂯎�邽�߂̃L���b�V���p�̃V�X�e���̊��N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_DX12_Cached_PSO_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::API::DX12::DX12_TOOL;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �ݒ� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�X�g���[�~���O�o�͗p�o�b�t�@���g�p���Ȃ����̏��������s��
// ����   �FD3D12_GRAPHICS_PIPELINE_STATE_DESC & �p�C�v���C�������p���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Cached_PSO_Base::M_Cashe_Nothing(D3D12_GRAPHICS_PIPELINE_STATE_DESC & in_pso_desc)
{
    // �p�C�v���C���̏�Ԃ��󂯎��L���b�V���̃A�h���X
    in_pso_desc.CachedPSO.pCachedBlob = nullptr;

    // �p�C�v���C���̏�Ԃ��󂯎��L���b�V���̃T�C�Y
    in_pso_desc.CachedPSO.CachedBlobSizeInBytes = 0;

    // �f�o�b�O���[�h�ɂ��邩�ǂ����̃t���O
    in_pso_desc.Flags = D3D12_PIPELINE_STATE_FLAG_NONE;

	return;
}
