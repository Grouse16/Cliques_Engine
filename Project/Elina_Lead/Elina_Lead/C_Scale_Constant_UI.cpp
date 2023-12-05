//����������������������������������������������//
// �ڍ�   �FUI�̐}�`��`�p�̃f�[�^
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "UI_Figure_Data.h"
#include "C_OS_System_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace DATA::FIGURE::UI;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Scale_Constant_UI::C_Scale_Constant_UI(void)
{
    m_box_color.m_r = 1.0f;
    m_box_color.m_g = 1.0f;
    m_box_color.m_b = 1.0f;
    m_box_color.m_a = 1.0f;

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Scale_Constant_UI::~C_Scale_Constant_UI(void)
{
    return;
}


//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F��ƂȂ�ꏊ���w�肷��
// ����   �FE_Scale_Base_Position ��ƂȂ�ꏊ���w�肷��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Scale_Constant_UI::M_Set_Scale_Base_Position(E_Scale_Base_Position in_base_position)
{
    m_base_position = in_base_position;

    return;
}


//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FUI�p�̎l�p�`�����N�g����ݒ肷��
// ����   �FS_Rect & �ݒu�ʒu
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Scale_Constant_UI::M_Set_Constant_Pixel_By_Rect(DATA::RECTSETTING::S_Rect & in_set_rect)
{
    m_constant_pixel_pos = in_set_rect;

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�X�P�[�����s�N�Z�����W�ɍ��킹��X�V���s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Scale_Constant_UI::M_Scale_Update(void)
{
    // �� �ϐ��錾 �� //
    const OS::S_Window_Size_Data & now_window_size = OS::C_OS_System_Base::M_Get_Instance()->M_Get_Window_Size();   // ���݂̃E�B���h�E�T�C�Y
    

    // ��ƂȂ�ꏊ�ɂ���č��E�̈ʒu��ݒ�
    switch (m_base_position)
    {
        // ��ԍ�����ɂ���
    case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_LEFT_TOP:
    case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_LEFT_BOTTOM:
        m_box_pos.left_x = m_constant_pixel_pos.left_x / now_window_size.width;
        m_box_pos.right_x = m_constant_pixel_pos.right_x / now_window_size.width;
        break;

        // ��ԉE����ɂ���
    case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_RIGHT_TOP:
    case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_RIGHT_BOTTOM:
        m_box_pos.left_x = (now_window_size.width - m_constant_pixel_pos.left_x) / now_window_size.width;
        m_box_pos.right_x = (now_window_size.width - m_constant_pixel_pos.right_x) / now_window_size.width;
        break;
    }

    // ��ƂȂ�ꏊ�ɂ���ď㉺�̈ʒu��ݒ�
    switch (m_base_position)
    {
        // ��ԏ����ɂ���
    case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_LEFT_TOP:
    case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_RIGHT_TOP:
        m_box_pos.top_y = (now_window_size.height - m_constant_pixel_pos.top_y) / now_window_size.height;
        m_box_pos.bottom_y = (now_window_size.height - m_constant_pixel_pos.bottom_y) / now_window_size.height;
        break;

        // ��ԉ�����ɂ���
    case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_LEFT_BOTTOM:
    case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_RIGHT_BOTTOM:
        m_box_pos.top_y = m_constant_pixel_pos.top_y / now_window_size.height;
        m_box_pos.bottom_y = m_constant_pixel_pos.bottom_y / now_window_size.height;
        break;
    }


    // ��ʂ̐ݒ�ɍ��킹��
    m_box_pos.left_x = m_box_pos.left_x * 2.0f - 1.0f;
    m_box_pos.right_x = m_box_pos.right_x * 2.0f - 1.0f;
    m_box_pos.top_y = m_box_pos.top_y * 2.0f - 1.0f;
    m_box_pos.bottom_y = m_box_pos.bottom_y * 2.0f - 1.0f;

	return;
}


