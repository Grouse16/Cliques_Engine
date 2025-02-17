//����������������������������������������������//
// �ڍ�   �FDX12�̒��_�o�b�t�@�̃Z�b�g�p�f�[�^�̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Rendering_Vertex_Buffer_Setting_Inform_Base.h"
#include "C_DX12_Vertex_Setting_Inform.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::API::DX12::DX12_INSTANCE;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_DX12_Vertex_Setting_Inform::C_DX12_Vertex_Setting_Inform(void)
{

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_DX12_Vertex_Setting_Inform::~C_DX12_Vertex_Setting_Inform(void)
{

	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�f�[�^���Z�b�g����
// ����   �Fvoid * ���_�f�[�^�̃A�h���X
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Vertex_Setting_Inform::M_Set_Vertex_Setting(void * in_vertex_add)
{
    // �� �ϐ��錾 �� //
    UINT8 * add_map = nullptr; // ���_�f�[�^�������ݐ�̃}�b�v�A�h���X


    // �}�b�v�����o���Ȃ�������G���[���o���Ĕ�����
    if (FAILED(m_vertex_buffer_data->Map(0, nullptr, reinterpret_cast<void**>(&add_map))))
    {
        return;
    }


    // �}�b�v�ɒ��_������������
    memcpy(add_map, in_vertex_add, m_vertex_buffer_view.SizeInBytes);


    // �}�b�v�����
    m_vertex_buffer_data->Unmap(0, nullptr);

	return;
}

