//����������������������������������������������//
// �ڍ�   �F�e�N�X�`���̃}�b�v���`������
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Texture_Map.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::TEXTURE;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Texture_Map::C_Texture_Map(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`���}�b�v�𐶐�����
// ����   �Fint �����̃s�N�Z����, int �c���̃s�N�Z����
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Map::M_Create_Texture_Map(int in_side_pixel, int in_vert_pixel)
{
	// �T�C�Y���}�C�i�X�l���w�肳�ꂽ�疳��
	if (in_side_pixel < 0 || in_vert_pixel < 0)
	{
		return;
	}


	// �� �ϐ��錾 �� //
	DATA::COLOR::C_Color flush_color(1.0f, 1.0f, 1.0f, 1.0f);	// �摜�̐F�����������邽�߂̐F�ݒ�


	// ���݂̃f�[�^�͏���
	M_Delete_Map();


	// �T�C�Y���Z�b�g
	mpr_variable.texture_size_x = in_side_pixel;
	mpr_variable.texture_size_y = in_vert_pixel;


	// �T�C�Y���̃������̊m�ہi�����ȏ�Ԃō쐬�j
	mpr_variable.texture_map.resize(mpr_variable.texture_size_x * mpr_variable.texture_size_y);
	M_Flush_All_Color(flush_color);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Texture_Map::~C_Texture_Map(void)
{
	M_Delete_Map();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`���}�b�v���폜����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Map::M_Delete_Map(void)
{
	mpr_variable.texture_map.clear();
	mpr_variable.texture_map.shrink_to_fit();
	mpr_variable.texture_size_x = 0;
	mpr_variable.texture_size_y = 0;

	return;
}


//-��- �}�b�v -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`���}�b�v�̃T�C�Y��ύX����
// ����   �Fint �ύX��̉����̃s�N�Z����, int �ύX��̏c���̃s�N�Z����
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Map::M_Map_Variable_Size_Change(int in_extend_x_size, int in_extend_y_size)
{
	// �� �ϐ��錾 �� //
	std::vector<DATA::COLOR::C_Color> then_texture_map;	// �g����̃f�[�^�ƂȂ�e�N�X�`���}�b�v

	int then_size_x = mpr_variable.texture_size_x;	// �g���O�̂��ł̃T�C�Y
	int then_size_y = mpr_variable.texture_size_y;	// �g���O�̂��ł̃T�C�Y

	int then_map_size = (int)mpr_variable.texture_map.size();	// �g���O�̃}�b�v�̃T�C�Y

	
	// �g���O�̏��𕜌��p�Ɉڂ�
	then_texture_map.resize(then_map_size);
	for (int l_pixel_num = 0; l_pixel_num < then_map_size; l_pixel_num++)
	{
		then_texture_map[l_pixel_num] = mpr_variable.texture_map[l_pixel_num];
	}


	// �}�b�v���g������
	mpr_variable.texture_size_x = 
		(mpr_variable.texture_size_x >= in_extend_x_size) * mpr_variable.texture_size_x 
		+
		(mpr_variable.texture_size_x < in_extend_x_size) * in_extend_x_size;

	mpr_variable.texture_size_y =
		(mpr_variable.texture_size_y >= in_extend_y_size) * mpr_variable.texture_size_y
		+
		(mpr_variable.texture_size_y < in_extend_y_size) * in_extend_y_size;
	mpr_variable.texture_map.resize(mpr_variable.texture_size_x * mpr_variable.texture_size_y);
	

	// ���܂ł̏���ێ������܂ܐV���������݂̂�����������
	for (int l_pixel_y = 0; l_pixel_y < mpr_variable.texture_size_y; l_pixel_y++)
	{
		// ���ł��܂܂ŕێ������񂪂���͈͂Ȃ�A���ŕێ�����͈͂̔�����s��
		if (l_pixel_y < then_size_y)
		{
			for (int l_pixel_x = 0; l_pixel_x < mpr_variable.texture_size_x; l_pixel_x++)
			{
				// �� �ϐ��錾 �� //
				int map_write_pos = l_pixel_y * mpr_variable.texture_size_x + l_pixel_x;	// �������ލ��W


				// ���ł��܂܂łŕێ������񂪂���͈͂Ȃ�A���܂ł̔z�񂩂�����ڂ��Ă���
				if (l_pixel_x < then_size_x)
				{
					mpr_variable.texture_map[map_write_pos] = then_texture_map[l_pixel_y * then_size_x + l_pixel_x];
				}

				// �ێ�����͈͊O�Ȃ珉�����F������
				else
				{
					mpr_variable.texture_map[map_write_pos].m_r = 1.0f;
					mpr_variable.texture_map[map_write_pos].m_g = 1.0f;
					mpr_variable.texture_map[map_write_pos].m_b = 1.0f;
					mpr_variable.texture_map[map_write_pos].m_a = 1.0f;
				}
			}
		}

		// ���ŕێ�����͈͊O�Ȃ珉�����F����������
		else
		{
			for (int l_pixel_x = 0; l_pixel_x < mpr_variable.texture_size_x; l_pixel_x++)
			{
				// �� �ϐ��錾 �� //
				int map_write_pos = l_pixel_y * mpr_variable.texture_size_x + l_pixel_x;	// �������ލ��W


				mpr_variable.texture_map[map_write_pos].m_r = 1.0f;
				mpr_variable.texture_map[map_write_pos].m_g = 1.0f;
				mpr_variable.texture_map[map_write_pos].m_b = 1.0f;
				mpr_variable.texture_map[map_write_pos].m_a = 1.0f;
			}
		}
	}

	return;
}


//-��- �������� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�S�Ă���F�ŏ�����
// ����   �FC_Color & �������ސF
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Map::M_Flush_All_Color(DATA::COLOR::C_Color & in_flush_color)
{
	for(int row_y = 0; row_y < mpr_variable.texture_size_y; row_y++)
	{
		// �� �ϐ��錾 �� //
		int row_plus = row_y * mpr_variable.texture_size_x;	// �ݒ�ʒu�̏c�񕪂ł��炷��


		for (int len_x = 0; len_x < mpr_variable.texture_size_x; len_x++)
		{
			mpr_variable.texture_map[row_plus + len_x] = in_flush_color;
		}
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�͈͂ɐF����������
// ����   �FC_Color & �������ސF, S_Recto & �������ޔ͈�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Map::M_Set_Color(DATA::COLOR::C_Color & in_set_color, DATA::RECTSETTING::S_Rect & in_rect_range)
{
	// �w��͈͂������Ȃ甲����
	if (in_rect_range.right_x <= 0 || in_rect_range.top_y <= 0)
	{
		return;
	}


	// �� �ϐ��錾 �� //
	int x_start = in_rect_range.left_x - 1;	// ���ł̏������ݔ͈͂̏��
	int x_limit = in_rect_range.right_x;	// ���ł̏������ݔ͈͂̏��

	int y_start = in_rect_range.bottom_y - 1;	// �c�ł̏������ݔ͈͂̏��
	int y_limit = in_rect_range.top_y;	// �c�ł̏������ݔ͈͂̏��


	// �� �}�b�v�̕����������Ȃ炻�������ɂ��� �� //
	x_limit = (x_limit > mpr_variable.texture_size_x) * mpr_variable.texture_size_x + (x_limit <= mpr_variable.texture_size_x) * x_limit;
	y_limit = (y_limit > mpr_variable.texture_size_y) * mpr_variable.texture_size_y + (y_limit <= mpr_variable.texture_size_y) * y_limit;

	
	// �� �������݊J�n�ʒu���͈͓��ɏo�Ȃ��悤�ɒ������� �� //
	x_start = x_start >= 0 * x_start;
	y_start = y_start >= 0 * y_start;


	// �w�肳�ꂽ�͈͂���������
	for (int row_y = x_start; row_y < y_limit; row_y++)
	{
		// �� �ϐ��錾 �� //
		int row_plus = row_y * mpr_variable.texture_size_x;	// �ݒ�ʒu�̏c�񕪂ł��炷��


		for (int len_x = y_start; len_x < x_limit; len_x++)
		{
			mpr_variable.texture_map[row_plus + len_x] = in_set_color;
		}
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�ꏊ�ɐF�𒼐ڏ�������
// ����   �Fconst C_Color & �������ސF, int �������ލ��W��, int �������ލ��W��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Map::M_Set_Color_At_Point(const DATA::COLOR::C_Color & in_set_color, int in_set_pos_x, int in_set_pos_y)
{
	// �͈͊O���w�肳�ꂽ�珈�������Ȃ�
	if (in_set_pos_x <= 0 || in_set_pos_y <= 0)
	{
		return;
	}


	// �h��ʒu��1�n�܂�Ŏw��ł���悤�ɒ���
	in_set_pos_x -= 1;
	in_set_pos_y -= 1;


	// �Z�b�g����͈͂����̃e�N�X�`���T�C�Y�𒴂���Ȃ�z�񐔂𒲐�����
	if (in_set_pos_x >= mpr_variable.texture_size_x || in_set_pos_y >= mpr_variable.texture_size_y)
	{
		M_Map_Variable_Size_Change(in_set_pos_x, in_set_pos_y);
	}


	// �� �ϐ��錾 �� //
	int set_pos = mpr_variable.texture_size_x * in_set_pos_y + in_set_pos_x;	// �F��ݒ肷��z��ԍ�


	// �F��ݒ�
	mpr_variable.texture_map[set_pos].m_r = in_set_color.m_r;
	mpr_variable.texture_map[set_pos].m_g = in_set_color.m_g;
	mpr_variable.texture_map[set_pos].m_b = in_set_color.m_b;
	mpr_variable.texture_map[set_pos].m_a = in_set_color.m_a;

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���̃e�N�X�`���p�̃}�b�v��Ԃ�
// ����   �Fvoid
// �߂�l �Fvector<C_Color> �e�N�X�`���p�̃}�b�v�̎Q�Ɓi�O��ڂ������Ȃ̂Œ��Ӂj
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::vector<DATA::COLOR::C_Color> & C_Texture_Map::M_Get_Texture_Map(void)
{
	return mpr_variable.texture_map;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����̃s�N�Z���T�C�Y��Ԃ�
// ����   �Fvoid
// �߂�l �F�߂�l�F�����̒l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
int C_Texture_Map::M_Get_Width_Size(void)
{
	return mpr_variable.texture_size_x;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�c���̃s�N�Z���T�C�Y��Ԃ�
// ����   �Fvoid
// �߂�l �F�߂�l�F�c���̒l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
int C_Texture_Map::M_Get_Height_Size(void)
{
	return mpr_variable.texture_size_y;
}




