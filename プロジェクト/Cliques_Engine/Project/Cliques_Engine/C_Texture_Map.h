////
// Ú×   FeNX`Ì}bvðè`·éîñ
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_S_TEXTURE_MAP_H_FILE
#define D_INCLUDE_GUARD_S_TEXTURE_MAP_H_FILE


//  t@CÐç«  //
#include <vector>
#include <string>

#include "C_Color.h"
#include "S_Rect.h"
#include "C_Half_Color.h"


//  l[Xy[X  //

// eNX`pÌè`ðÄÑo·½ßÌ¼O
namespace ASSET::TEXTURE
{
	//  NX  //

	// eNX`Ì}bvpÌNX
	class C_Texture_Map
	{
	//== vCx[g ==//
	private:

		//  Ïé¾  //

		// vCx[gÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			std::vector<DATA::COLOR::C_Color> texture_map;	// eNX`pÌ}bvAOñÚÍ¶ºÆ·éi0,0ð¶ºÉµ½Ù¤ªtop>bottomÉÈéÌÅª©èâ·¢j
			
			int texture_size_x = 0;	// ¡ÌeNX`ÌTCY
			int texture_size_y = 0;	// cÌeNX`ÌTCY

		} mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O


	//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Texture_Map(void);

		// eNX`}bvð¶¬·é@øF¡ÌsNZ, cÌsNZ
		void M_Create_Texture_Map(int, int);

		// fXgN^
		~C_Texture_Map(void);

		// eNX`}bvðí·é
		void M_Delete_Map(void);


		//-- }bv --//

		// eNX`}bvÌTCYðÏX·é@øFg£ãÌ¡ÌsNZ, g£ãÌcÌsNZ
		void M_Map_Variable_Size_Change(int, int);


		//-- «Ý --//

		// SÄðêFÅú»@ø:«ÞF
		void M_Flush_All_Color(DATA::COLOR::C_Color &);

		// wè³ê½ÍÍÉFð«Þ@øF«ÞF, «ÞÍÍ
		void M_Set_Color(DATA::COLOR::C_Color &, DATA::RECTSETTING::S_Rect &);

		// wè³ê½êÉFð¼Ú«Þ@øF«ÞF, «ÞÀW, «ÞÀW
		void M_Set_Color_At_Point(const DATA::COLOR::C_Color &, int, int);


		//-- Qb^ --//

		// ¡ÌeNX`pÌ}bvðÔ·@ßèlFeNX`pÌ}bvÌQÆiOñÚª¶ºÈÌÅÓj
		std::vector<DATA::COLOR::C_Color> & M_Get_Texture_Map(void);

		// ¡ÌsNZTCYðÔ·@ßèlF¡Ìl
		int M_Get_Width_Size(void);

		// cÌsNZTCYðÔ·@ßèlFcÌl
		int M_Get_Height_Size(void);
	};
}


#endif // !D_INCLUDE_GUARD_S_TEXTURE_MAP_H_FILE



