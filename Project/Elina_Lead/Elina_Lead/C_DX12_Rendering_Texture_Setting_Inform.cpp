//����������������������������������������������//
// �ڍ�   �FDX12�̃����_�����O�ݒ�p�f�[�^�̃Z�b�g�p�̃f�[�^�̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_DX12_Rendering_Texture_Setting_Inform.h"


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
C_DX12_Rendering_Texture_Setting_Inform::C_DX12_Rendering_Texture_Setting_Inform(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_DX12_Rendering_Texture_Setting_Inform::~C_DX12_Rendering_Texture_Setting_Inform(void)
{
	M_Delete();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Rendering_Texture_Setting_Inform::M_Delete(void)
{
	m_texture_data.Reset();
	m_texture_heap.Reset();
	m_pix_size_x = 0;
	m_pix_size_y = 0;

	return;
}


//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`���̃f�[�^���Z�b�g����
// ����   �Fconst vector<C_Color> & �ݒ肷��F�z��ւ̎Q��, int �e�N�X�`���̉���, int �e�N�X�`���̏c��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_Rendering_Texture_Setting_Inform::M_Set_Texture_Data(const std::vector<DATA::COLOR::C_Color> & in_texture_map, int in_width, int in_height)
{
	// �� �ϐ��錾 �� //
	int pixel_width = in_width;	// �����ł̃s�N�Z���T�C�Y
	int pixel_height = in_height;	// �c���ł̃s�N�Z���T�C�Y


	// �������ݔ͈͂̕����L���Ȃ玩�g�̃s�N�Z���T�C�Y�ɒ���
	if (pixel_width > m_pix_size_x)
	{
		pixel_width = m_pix_size_x;
	}

	if (pixel_height > m_pix_size_y)
	{
		pixel_height = m_pix_size_y;
	}


	//�T�u���\�[�X�ɏ�������
	m_texture_data->WriteToSubresource(0, nullptr, &in_texture_map[0], (pixel_width * 4), (pixel_height * 4));

	return;
}
