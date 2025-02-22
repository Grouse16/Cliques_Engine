////
// Ú×   FUIÌ}`è`pÌf[^
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_UI_FIGURE_DATA_H_FILE
#define D_INCLUDE_GUARD_UI_FIGURE_DATA_H_FILE


//  t@CÐç«  //
#include <d3d12.h>

#include "2D_Position_Data.h"
#include "C_Color.h"
#include "Texture_UV_Data.h"
#include "Figure_Base_Data.h"
#include "S_Rect.h"


//  l[Xy[X  //

// UInðÄÑo·½ßÌ¼O
namespace DATA::FIGURE::UI
{
	//  è  //

	// UIÌ}`Ì½ßÌlQ
	enum class E_UI_FIGURE_PARAMATOR
	{
		e_PICXCEL_BASE_SIZE = 1000,	// sNZÌîÆ·éå«³
	};


	//  Ïé¾  //

	// UIÝèpÌÏQ
	class C_UI_SETTING_DATA
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //
		static C_UI_SETTING_DATA m_this;	// IuWFNgè`pÌÏiVOg»j


		//  Ö  //

		//-- ú» --//

		// RXgN^
		C_UI_SETTING_DATA(void);


		//== pubN ==//
	public:

		//  Ïé¾  //
		static float ui_width;	// UIÌî{sNZÌ¡
		static float ui_height;	// UIÌî{sNZÌc

		static float aspect_x;	// AXyNgäÅÌ
		static float aspect_y;		// AXyNgäÅÌ

		static float percent_of_aspect_x;	// AXyNgäÌÌä¦
		static float percent_of_aspect_y;	// AXyNgäÌÌä¦

	};	// UIÝèpÌÏQðÄÑo·½ßÌ¼O


	//  NX  //

	// lp`ÌUIpÌNX
	class C_UI_Box : DATA::FIGURE::BASE::C_Figure_Base
	{
		//== pubN ==//
	public:

		//  Ïé¾  //
		RECTSETTING::S_Rect m_box_pos;	// lp`ÌÀW

		DATA::COLOR::C_Color m_box_color;	// lp`ÌF


		//  Ö  //

		//-- XV --//

		// UIpÌlp`ðNg©çÝè·é@øFRECT & ÝuÊu
		virtual void M_Set_Constant_Pixel_By_Rect(RECTSETTING::S_Rect & );

		// FðSÄÌ¸_ÉÝè·é@øFCOLOR & F
		void M_Set_UI_Box_Color(DATA::COLOR::C_Color & );


		//-- ú»ÆI¹ --//

		// RXgN^
		C_UI_Box(void) { return; }

		// fXgN^
		virtual ~C_UI_Box(void) { return; }
	};


	// `æ·ésNZÀWð®SÉÅèµ½lp`ÌUI
	class C_Scale_Constant_UI : public C_UI_Box
	{
		//== pubN ==//
	public:

		//  è  //

		// sNZÌTCYðÝè·éÆ«ÉîÆ·éêðÝè·é
		enum class E_Scale_Base_Position
		{
			e_LEFT_TOP,		// ¶ã
			e_LEFT_BOTTOM,	// ¶º

			e_RIGHT_TOP,	// Eã
			e_RIGHT_BOTTOM,	// Eº
		};


		//  Ïé¾  //
		DATA::RECTSETTING::S_Rect m_constant_pixel_pos;	// sNZÌÀW

		E_Scale_Base_Position m_base_position = E_Scale_Base_Position::e_LEFT_BOTTOM;	// ÅèÌîÆÈéêÌwè


		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Scale_Constant_UI(void);

		// fXgN^
		~C_Scale_Constant_UI(void);


		//-- Zb^ --//

		// îÆÈéêðwè·é@øFwè·éê
		void M_Set_Scale_Base_Position(E_Scale_Base_Position);


		//-- XV --//

		// UIpÌlp`ðNg©çÝè·é@øFRECT & ÝuÊu
		void M_Set_Constant_Pixel_By_Rect(RECTSETTING::S_Rect & ) override;
		
		// XP[ðsNZÀWÉí¹éXVðs¤
		void M_Scale_Update(void);
	};
}


#endif // !D_INCLUDE_GUARD_UI_FIGURE_DATA_H_FILE
