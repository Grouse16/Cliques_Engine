////
// Ú×   FeNX`Ì}bvðè`·éîñ
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Texture_Map.h"


//  l[Xy[XÌÈª  //
using namespace ASSET::TEXTURE;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Texture_Map::C_Texture_Map(void)
{
	return;
}


//===============//
// Ú×   FeNX`}bvð¶¬·é
// ø   Fint ¡ÌsNZ, int cÌsNZ
// ßèl Fvoid
//===============//
void C_Texture_Map::M_Create_Texture_Map(int in_side_pixel, int in_vert_pixel)
{
	// TCYª}CiXlðwè³ê½ç³ø
	if (in_side_pixel < 0 || in_vert_pixel < 0)
	{
		return;
	}


	//  Ïé¾  //
	DATA::COLOR::C_Color flush_color(1.0f, 1.0f, 1.0f, 1.0f);	// æÌFðú»·é½ßÌFÝè


	// »ÝÌf[^ÍÁ·
	M_Delete_Map();


	// TCYðZbg
	mpr_variable.texture_size_x = in_side_pixel;
	mpr_variable.texture_size_y = in_vert_pixel;


	// TCYªÌÌmÛi§¾ÈóÔÅì¬j
	mpr_variable.texture_map.resize((size_t)mpr_variable.texture_size_x * (size_t)mpr_variable.texture_size_y);
	M_Flush_All_Color(flush_color);

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Texture_Map::~C_Texture_Map(void)
{
	M_Delete_Map();

	return;
}


//===============//
// Ú×   FeNX`}bvðí·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Texture_Map::M_Delete_Map(void)
{
	mpr_variable.texture_map.clear();
	mpr_variable.texture_map.shrink_to_fit();
	mpr_variable.texture_size_x = 0;
	mpr_variable.texture_size_y = 0;

	return;
}


//-- }bv --//

//===============//
// Ú×   FeNX`}bvÌTCYðÏX·é
// ø   Fint ÏXãÌ¡ÌsNZ, int ÏXãÌcÌsNZ
// ßèl Fvoid
//===============//
void C_Texture_Map::M_Map_Variable_Size_Change(int in_extend_x_size, int in_extend_y_size)
{
	//  Ïé¾  //
	std::vector<DATA::COLOR::C_Color> then_texture_map;	// g£ãÌf[^ÆÈéeNX`}bv

	int then_size_x = mpr_variable.texture_size_x;	// g£OÌÅÌTCY
	int then_size_y = mpr_variable.texture_size_y;	// g£OÌÅÌTCY

	int then_map_size = (int)mpr_variable.texture_map.size();	// g£OÌ}bvÌTCY

	
	// g£OÌîñð³pÉÚ·
	then_texture_map.resize(then_map_size);
	for (int l_pixel_num = 0; l_pixel_num < then_map_size; l_pixel_num++)
	{
		then_texture_map[l_pixel_num] = mpr_variable.texture_map[l_pixel_num];
	}


	// }bvðg£·é
	mpr_variable.texture_size_x = 
		(mpr_variable.texture_size_x >= in_extend_x_size) * mpr_variable.texture_size_x 
		+
		(mpr_variable.texture_size_x < in_extend_x_size) * in_extend_x_size;

	mpr_variable.texture_size_y =
		(mpr_variable.texture_size_y >= in_extend_y_size) * mpr_variable.texture_size_y
		+
		(mpr_variable.texture_size_y < in_extend_y_size) * in_extend_y_size;
	mpr_variable.texture_map.resize((size_t)mpr_variable.texture_size_x * (size_t)mpr_variable.texture_size_y);
	

	// ¡ÜÅÌîñðÛµ½ÜÜVµ¢ªÌÝðú»·é
	for (int l_pixel_y = 0; l_pixel_y < mpr_variable.texture_size_y; l_pixel_y++)
	{
		// Å¢ÜÜÅÛ·éîñª éÍÍÈçAÅÛ·éÍÍÌ»èàs¤
		if (l_pixel_y < then_size_y)
		{
			for (int l_pixel_x = 0; l_pixel_x < mpr_variable.texture_size_x; l_pixel_x++)
			{
				//  Ïé¾  //
				int map_write_pos = l_pixel_y * mpr_variable.texture_size_x + l_pixel_x;	// «ÞÀW


				// Å¢ÜÜÅÅÛ·éîñª éÍÍÈçA¡ÜÅÌzñ©çîñðÚµÄ­é
				if (l_pixel_x < then_size_x)
				{
					mpr_variable.texture_map[map_write_pos] = then_texture_map[(size_t)l_pixel_y * (size_t)then_size_x + (size_t)l_pixel_x];
				}

				// Û·éÍÍOÈçú»Fðüêé
				else
				{
					mpr_variable.texture_map[map_write_pos].m_r = 1.0f;
					mpr_variable.texture_map[map_write_pos].m_g = 1.0f;
					mpr_variable.texture_map[map_write_pos].m_b = 1.0f;
					mpr_variable.texture_map[map_write_pos].m_a = 1.0f;
				}
			}
		}

		// ÅÛ·éÍÍOÈçú»Fð«Þ
		else
		{
			for (int l_pixel_x = 0; l_pixel_x < mpr_variable.texture_size_x; l_pixel_x++)
			{
				//  Ïé¾  //
				int map_write_pos = l_pixel_y * mpr_variable.texture_size_x + l_pixel_x;	// «ÞÀW


				mpr_variable.texture_map[map_write_pos].m_r = 1.0f;
				mpr_variable.texture_map[map_write_pos].m_g = 1.0f;
				mpr_variable.texture_map[map_write_pos].m_b = 1.0f;
				mpr_variable.texture_map[map_write_pos].m_a = 1.0f;
			}
		}
	}

	return;
}


//-- «Þ --//

//===============//
// Ú×   FSÄðêFÅú»
// ø   FC_Color & «ÞF
// ßèl Fvoid
//===============//
void C_Texture_Map::M_Flush_All_Color(DATA::COLOR::C_Color & in_flush_color)
{
	for(int row_y = 0; row_y < mpr_variable.texture_size_y; row_y++)
	{
		//  Ïé¾  //
		int row_plus = row_y * mpr_variable.texture_size_x;	// ÝèÊuÌcñªÅ¸ç·Ê


		for (int len_x = 0; len_x < mpr_variable.texture_size_x; len_x++)
		{
			mpr_variable.texture_map[(size_t)row_plus + (size_t)len_x] = in_flush_color;
		}
	}

	return;
}


//===============//
// Ú×   Fwè³ê½ÍÍÉFð«Þ
// ø   FC_Color & «ÞF, S_Recto & «ÞÍÍ
// ßèl Fvoid
//===============//
void C_Texture_Map::M_Set_Color(DATA::COLOR::C_Color & in_set_color, DATA::RECTSETTING::S_Rect & in_rect_range)
{
	// wèÍÍª³øÈç²¯é
	if (in_rect_range.right_x <= 0 || in_rect_range.top_y <= 0)
	{
		return;
	}


	//  Ïé¾  //
	int x_start = in_rect_range.left_x - 1;	// ¡ÅÌ«ÝÍÍÌãÀ
	int x_limit = in_rect_range.right_x;	// ¡ÅÌ«ÝÍÍÌãÀ

	int y_start = in_rect_range.bottom_y - 1;	// cÅÌ«ÝÍÍÌãÀ
	int y_limit = in_rect_range.top_y;	// cÅÌ«ÝÍÍÌãÀ


	//  }bvÌûª¬³¢Èç»êðãÀÉ·é  //
	x_limit = (x_limit > mpr_variable.texture_size_x) * mpr_variable.texture_size_x + (x_limit <= mpr_variable.texture_size_x) * x_limit;
	y_limit = (y_limit > mpr_variable.texture_size_y) * mpr_variable.texture_size_y + (y_limit <= mpr_variable.texture_size_y) * y_limit;

	
	//  «ÝJnÊuªÍÍàÉoÈ¢æ¤É²®·é  //
	x_start = x_start >= 0 * x_start;
	y_start = y_start >= 0 * y_start;


	// wè³ê½ÍÍð«Þ
	for (int row_y = x_start; row_y < y_limit; row_y++)
	{
		//  Ïé¾  //
		int row_plus = row_y * mpr_variable.texture_size_x;	// ÝèÊuÌcñªÅ¸ç·Ê


		for (int len_x = y_start; len_x < x_limit; len_x++)
		{
			mpr_variable.texture_map[(size_t)row_plus + (size_t)len_x] = in_set_color;
		}
	}

	return;
}


//===============//
// Ú×   Fwè³ê½êÉFð¼Ú«Þ
// ø   Fconst C_Color & «ÞF, int «ÞÀW, int «ÞÀW
// ßèl Fvoid
//===============//
void C_Texture_Map::M_Set_Color_At_Point(const DATA::COLOR::C_Color & in_set_color, int in_set_pos_x, int in_set_pos_y)
{
	// ÍÍOðwè³ê½çðµÈ¢
	if (in_set_pos_x <= 0 || in_set_pos_y <= 0)
	{
		return;
	}


	// héÊuð1nÜèÅwèÅ«éæ¤É²®
	in_set_pos_x -= 1;
	in_set_pos_y -= 1;


	// Zbg·éÍÍª¡ÌeNX`TCYð´¦éÈçzñð²®·é
	if (in_set_pos_x >= mpr_variable.texture_size_x || in_set_pos_y >= mpr_variable.texture_size_y)
	{
		M_Map_Variable_Size_Change(in_set_pos_x, in_set_pos_y);
	}


	//  Ïé¾  //
	int set_pos = mpr_variable.texture_size_x * in_set_pos_y + in_set_pos_x;	// FðÝè·ézñÔ


	// FðÝè
	mpr_variable.texture_map[set_pos].m_r = in_set_color.m_r;
	mpr_variable.texture_map[set_pos].m_g = in_set_color.m_g;
	mpr_variable.texture_map[set_pos].m_b = in_set_color.m_b;
	mpr_variable.texture_map[set_pos].m_a = in_set_color.m_a;

	return;
}


//-- Qb^ --//

//===============//
// Ú×   F¡ÌeNX`pÌ}bvðÔ·
// ø   Fvoid
// ßèl Fvector<C_Color> eNX`pÌ}bvÌQÆiOñÚª¶ºÈÌÅÓj
//===============//
std::vector<DATA::COLOR::C_Color> & C_Texture_Map::M_Get_Texture_Map(void)
{
	return mpr_variable.texture_map;
}


//===============//
// Ú×   F¡ÌsNZTCYðÔ·
// ø   Fvoid
// ßèl FßèlF¡Ìl
//===============//
int C_Texture_Map::M_Get_Width_Size(void)
{
	return mpr_variable.texture_size_x;
}


//===============//
// Ú×   FcÌsNZTCYðÔ·
// ø   Fvoid
// ßèl FßèlFcÌl
//===============//
int C_Texture_Map::M_Get_Height_Size(void)
{
	return mpr_variable.texture_size_y;
}




