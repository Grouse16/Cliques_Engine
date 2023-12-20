//����������������������������������������������//
// �ڍ�   �F�{�[���̃f�[�^�̃N���X
// ����   �F�ݒ肳�ꂽ�����}�g���N�X�ɕϊ����邱�Ƃ��s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Bone_Data.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::ANIMATION::BONE;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �}�g���N�X -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̃{�[�������}�g���N�X�ɕϊ������l�������ɃZ�b�g����
// ����   �FXMFLOAT4X4 & �ݒ��̃}�g���N�X���̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Bone_Data::M_Set_Bone_Matrix_Data(DirectX::XMFLOAT4X4 & out_matrix) const
{
    DirectX::XMStoreFloat4x4
    (
        // �ݒ��}�g���N�X�s��
        &out_matrix,

        // �X�P�[��
        DirectX::XMMatrixScaling(scale.x, scale.y, scale.z) * 

        // �N�H�[�^�j�I���i��]�j
        DirectX::XMMatrixRotationQuaternion(quaternion) *

        // �|�W�V����
        DirectX::XMMatrixTranslation(position.x, position.y, position.z)
    );

    return;
}
