//����������������������������������������������//
// �ڍ�   �F�t�H���g�f�[�^�𐳊m�Ɏg�����߂̃V�X�e��
// ����   �F�t�H���g�̓ǂݍ��݂���`��܂ł��s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Font_Draw_System.h"
#include "C_Rendering_Graphics_API_Base.h"
#include "S_Make_Font_To_Graph_Pakage.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace DATA::FONT;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̃e�L�X�g�ɉ����ĉ摜�𐶐�����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Font_Draw_System::M_Creat_Texture_On_Now_Text(void)
{
	// �� �ϐ��錾 �� //
	int text_size = (int)mpr_variable.now_draw_text.size();	// ������

	PAKAGE::FONT::S_Make_Font_To_Graph_Package make_font_setting;	// �t�H���g�f�[�^�̐ݒ�p���


	// ���̃Z�b�g
	make_font_setting.attach_font_data = &mpr_variable.font_data;
	make_font_setting.tex_map_data = &mpr_variable.texture_data.M_Get_Texture_Map();


	// �����̏������݈ʒu�ݒ�
	make_font_setting.draw_rect.left_x = 1;
	make_font_setting.draw_rect.right_x = mpr_variable.font_size;

	make_font_setting.draw_rect.top_y = mpr_variable.font_size;
	make_font_setting.draw_rect.bottom_y = 1;


	// �ꕶ���Â摜�ɃZ�b�g���Ă���
	for (int l_text_elem = 0; l_text_elem < text_size; l_text_elem++)
	{
		// ���s���͌��݂̍s�����X�V
		if (mpr_variable.now_draw_text[l_text_elem] == L'\n')
		{
			make_font_setting.draw_rect.left_x = 1;
			make_font_setting.draw_rect.right_x = mpr_variable.font_size;

			make_font_setting.draw_rect.bottom_y += mpr_variable.font_size + mpr_variable.span_size;
			make_font_setting.draw_rect.top_y += mpr_variable.font_size + mpr_variable.span_size;
		}

		// �󔒁i���p�͊Ԋu��������j
		else if (mpr_variable.now_draw_text[l_text_elem] == L' ')
		{
			make_font_setting.draw_rect.left_x += mpr_variable.font_size / 2;
			make_font_setting.draw_rect.right_x += mpr_variable.font_size / 2;
		}

		// �󔒁i�S�p�͎��̕����܂ŃX���[�j
		else if (mpr_variable.now_draw_text[l_text_elem] == L'�@')
		{
			make_font_setting.draw_rect.left_x += mpr_variable.font_size;
			make_font_setting.draw_rect.right_x += mpr_variable.font_size;
		}

		// �ʏ�̕�����Ȃ�摜�ɕ�������������
		else
		{
			make_font_setting.text_code = mpr_variable.now_draw_text[l_text_elem];

			RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Set_Font_To_Texture_Map(make_font_setting);

			make_font_setting.draw_rect.left_x += mpr_variable.font_size + mpr_variable.span_size;
			make_font_setting.draw_rect.right_x += mpr_variable.font_size + mpr_variable.span_size;
		}
	}

	// GPU�Ƀe�N�X�`���}�b�v���e�N�X�`���o�b�t�@�փZ�b�g
	mpr_variable.texture_data.M_Creat_Texture_Resource_By_Texture_Map();


	// �}�b�v��ۑ����Ȃ��Ȃ�摜�}�b�v���폜
	if (mpr_variable.flg_save_map == false)
	{
		mpr_variable.texture_data.M_Delete_Map();
	}

	return;
}


//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Font_Draw_System::C_Font_Draw_System(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Font_Draw_System::~C_Font_Draw_System(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�t�H���g�f�[�^������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Font_Draw_System::M_Reset(void)
{
	mpr_variable.font_data.reset();
	mpr_variable.texture_data.M_Delete();

	mpr_variable.font_size = 60;

	return;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃t�H���g���擾����(PC�ɑ��݂��Ă��鎞�̂ݓ���)
// ����   �Fstd::wstring �t�H���g��, int �t�H���g�̃s�N�Z���T�C�Y
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Font_Draw_System::M_Load_Font_By_Font_Name(std::wstring in_load_font_name, int in_font_pixel_size)
{
	// �� �ϐ��錾 �� //
	RENDERING::GRAPHICS::CREAT::C_Creat_Font_Data_Inform creat_setting;	// �����p���


	// �������Ă���f�[�^�͍폜����
	M_Reset();


	// �t�H���g�f�[�^�����p���̐ݒ�
	creat_setting.m_width = in_font_pixel_size;
	creat_setting.m_height = in_font_pixel_size;
	creat_setting.m_font_name = in_load_font_name;


	// �t�H���g�����[�h����
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Creat_Font_Data(mpr_variable.font_data, creat_setting);

	return true;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�`��ʒu��ݒ肷��
// ����   �Fint �t�H���g�T�C�Y
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Font_Draw_System::M_Set_Font_Size(int in_font_size)
{
	mpr_variable.font_size = in_font_size;
	mpr_variable.font_data->M_Resize(in_font_size, in_font_size);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�`��ʒu��ݒ肷��
// ����   �Fint �t�H���g�T�C�Y
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Font_Draw_System::M_Set_Span(int in_span)
{
	mpr_variable.span_size = in_span;

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`���f�[�^�̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �FC_Texture_Data_System & �e�N�X�`���[�f�[�^�̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
RENDERING::CAPSULE::C_Texture_Data_System & C_Font_Draw_System::M_Get_Texture_Data(void)
{
	return mpr_variable.texture_data;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�L�X�g����摜�𐶐�����
// ����   �Fconst wstring �ݒ肷��e�L�X�g
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Font_Draw_System::M_Creat_Graph_By_Text(const std::wstring in_set_string)
{
	mpr_variable.now_draw_text = in_set_string;
	M_Creat_Texture_On_Now_Text();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�ݒ肳�ꂽ�e�L�X�g�ɂ��摜��������x��������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Font_Draw_System::M_Recreate_Graph(void)
{
	M_Creat_Texture_On_Now_Text();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�C���f�b�N�X�w��p�̎��ʖ����Z�b�g����
// ����   �Fconst std::string �ݒ肷�鎯�ʖ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Font_Draw_System::M_Set_Signature_Name(const std::string in_set_string)
{
	mpr_variable.texture_data.M_Set_Data_Signature_Name(in_set_string);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�K������V�F�[�_�[�̎�ނ�ݒ肷��
// ����   �Fconst E_SHADER_KIND �ݒ肷����
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Font_Draw_System::M_Set_Attach_Shader_Kind(const ASSET::SHADER::E_SHADER_KIND in_set_kind)
{
	mpr_variable.texture_data.M_Set_Attach_Shader_Kind(in_set_kind);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���̃e�N�X�`���̃f�[�^��GPU�֑���
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Font_Draw_System::M_Attach_To_Shader(void)
{
	mpr_variable.texture_data.M_Attach_To_Shader();

	return;
}

