


// �� �t�@�C���Ђ炫 �� //
#include "C_DX12_Constant_Setting_Inform.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE;


// �� �N���X �� //

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�������ɒ萔�f�[�^�𐶐�����
// ����   �FC_Constant_Buffer_Setting_Inform_Base & �Z�b�g��̒萔�f�[�^, C_Creat_Constant_Buffer_Inform & �萔�f�[�^�����p���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_DX12_Constant_Setting_Inform::C_DX12_Constant_Setting_Inform(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�������ɒ萔�f�[�^�𐶐�����
// ����   �FC_Constant_Buffer_Setting_Inform_Base & �Z�b�g��̒萔�f�[�^, C_Creat_Constant_Buffer_Inform & �萔�f�[�^�����p���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_DX12_Constant_Setting_Inform::~C_DX12_Constant_Setting_Inform(void)
{
	m_constant_buffer_data.Reset();

	m_constant_buffer_heap.Reset();

	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�萔�o�b�t�@�Ɏw�肳�ꂽ�����Z�b�g����
// ����   �Fvoid * �Z�b�g����f�[�^, int �z��, int �Z�b�g����f�[�^�T�C�Y
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Constant_Setting_Inform::M_Set_Data_To_Buffer(void * in_set_data, int in_list_size, int in_data_size)
{
    // �� �ϐ��錾 �� //
    void * get_map_address = nullptr; // �萔�o�b�t�@�������ݐ�̃}�b�v�A�h���X
    
    
    // �}�b�v�����o���Ȃ�������G���[���o���Ĕ�����
    if (FAILED(m_constant_buffer_data->Map(0, nullptr, &get_map_address)))
    {
        return;
    }


    // �� �ϐ��錾 �� //
    unsigned char * buffer_data = static_cast<unsigned char *>(get_map_address);    // �������ݐ�o�b�t�@�i�P�o�C�g�I�t�Z�b�g�j


    // �}�b�v�ɒ萔������������
    for (int loop_x = 0; loop_x < in_list_size; loop_x++)
    {
        memcpy((buffer_data + 256 * loop_x), (static_cast<unsigned char * >(in_set_data) + in_list_size * in_data_size), in_data_size);
    }


    // �}�b�v�����
    m_constant_buffer_data->Unmap(0, nullptr);
    get_map_address = nullptr;
    buffer_data = nullptr;

    return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�萔�o�b�t�@�̃f�[�^�̃A�h���X��Ԃ��@���g�p���I�������K��Close���邱��
// ����   �Fvoid
// �߂�l �F�萔�o�b�t�@�̃f�[�^�̃A�h���X
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
unsigned char * C_DX12_Constant_Setting_Inform::M_Get_Constant_Buffer_Data_Address(void)
{
    // �� �ϐ��錾 �� //
    void * get_map_address = nullptr; // �萔�o�b�t�@�������ݐ�̃}�b�v�A�h���X

    // �萔�o�b�t�@�̃f�[�^���擾���ĕԂ�
    m_constant_buffer_data->Map(0, nullptr, &get_map_address);
    return (unsigned char*)get_map_address;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�萔�o�b�t�@�̃f�[�^���g�p�I������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Constant_Setting_Inform::M_Close_Constant_Buffer_Data_Address(void)
{
    // �萔�o�b�t�@�̃f�[�^�̎g�p���I������
    m_constant_buffer_data->Unmap(0, nullptr);

    return;
}



