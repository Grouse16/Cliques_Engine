//����������������������������������������������//
// �ڍ�   �FUI�ݒ�p�̕ϐ��Q
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "UI_Figure_Data.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace DATA::FIGURE::UI;


// �� �ϐ��錾 �� //
C_UI_SETTING_DATA C_UI_SETTING_DATA::m_this;	// ���g���`���邽�߂̕ϐ�

float C_UI_SETTING_DATA::ui_width;
float C_UI_SETTING_DATA::ui_height;
float C_UI_SETTING_DATA::aspect_x;
float C_UI_SETTING_DATA::aspect_y;
float C_UI_SETTING_DATA::percent_of_aspect_x;
float C_UI_SETTING_DATA::percent_of_aspect_y;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_UI_SETTING_DATA::C_UI_SETTING_DATA(void)
{
	ui_width = 1920;
	ui_height = 1080;

	aspect_x = 16;
	aspect_y = 9;

	percent_of_aspect_x = aspect_x / (aspect_x + aspect_y);
	percent_of_aspect_y = aspect_y / (aspect_x + aspect_y);

	return;
}