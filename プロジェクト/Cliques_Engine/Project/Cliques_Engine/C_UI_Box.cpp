//����������������������������������������������//
// �ڍ�   �F�l�p�`��UI�̐}�`��`�p�̃f�[�^
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "UI_Figure_Data.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace DATA::FIGURE::UI;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FUI�p�̎l�p�`�����N�g����ݒ肷��
// ����   �FS_Rect & �ݒu�ʒu
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_UI_Box::M_Set_Constant_Pixel_By_Rect(RECTSETTING::S_Rect & in_set_rect)
{
	m_box_pos = in_set_rect;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�F��S�Ă̒��_�ɐݒ肷��
// ����   �FCOLOR & �F
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_UI_Box::M_Set_UI_Box_Color(DATA::COLOR::C_Color & in_color)
{
	m_box_color = in_color;

	return;
}
