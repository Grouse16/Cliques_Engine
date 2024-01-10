//����������������������������������������������//
// �ڍ�   �FDX12�̒��_�C���f�b�N�X�o�b�t�@�̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_DX12_Index_Setting_Inform.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_DX12_Index_Setting_Inform::C_DX12_Index_Setting_Inform(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_DX12_Index_Setting_Inform::~C_DX12_Index_Setting_Inform(void)
{
	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�C���f�b�N�X�f�[�^���Z�b�g����
// ����   �Fconst vector<unsigned int> & �ݒ肷��C���f�b�N�X�f�[�^�̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Index_Setting_Inform::M_Set_Index_Setting(const std::vector<unsigned int> & in_set_index_data)
{
    // �� �ϐ��錾 �� //
    void * get_map_address = nullptr; // ���_�f�[�^�������ݐ�̃}�b�v�A�h���X


    // �� �C���f�b�N�X�o�b�t�@�f�[�^��ݒ� �� //

    // �� �f�[�^�̃A�h���X����� �� //    // ����Ɏ��s�����珈�����~
    if (FAILED(m_index_buffer_data->Map(0, nullptr, reinterpret_cast<void**>(&get_map_address))))
    {
        return;
    }


    // �� �ϐ��錾 �� //
    unsigned int * buffer_data = static_cast<unsigned int * >(get_map_address);    // �������ݐ�o�b�t�@�i�P�o�C�g�I�t�Z�b�g�j

    int write_index_sum = 0;    // �������ރC���f�b�N�X��


    // �����������Ƃ��Ă���C���f�b�N�X�����C���f�b�N�X�o�b�t�@�̃T�C�Y�𒴂��Ă�����C���f�b�N�X�o�b�t�@�̃T�C�Y���܂ŏ�������
    if (m_index_sum < in_set_index_data.size())
    {
		write_index_sum = m_index_sum;
	}

    // �����������Ƃ��Ă���C���f�b�N�X�����C���f�b�N�X�o�b�t�@�̃T�C�Y�𒴂��Ă��Ȃ������珑���������Ƃ��Ă���C���f�b�N�X�����܂ŏ�������
    else
    {
		write_index_sum = in_set_index_data.size();
	}

    // �C���f�b�N�X�o�b�t�@�Ƀf�[�^����������
    for (int index = 0; index < write_index_sum; index++)
    {
        buffer_data[index] = in_set_index_data[index];
    }

    // �}�b�s���O����
    m_index_buffer_data->Unmap(0, nullptr);
    get_map_address = nullptr;
    buffer_data = nullptr;

	return;
}

