////
// Ú×   Fæð\¦·éUIÌNXiUIÌR|[lgj
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_UIC_TEXT_BOX
#define D_INCLUDE_GUARD_C_UIC_TEXT_BOX


//  t@CÐç«  //
#include <string>

#include "C_UI_Component_Base.h"
#include "C_Material_User.h"
#include "C_Object_Vertex_System.h"
#include "C_Vertex_Index_System.h"
#include "S_UI_Vertex.h"
#include "S_Rect.h"


//  l[Xy[X  //

// UIÌR|[lgðÄÑo·½ßÌ¼O
namespace GAME::UI_COMPONENT
{
	//  NX  //

	// æð\¦·éUIÌNX
	class C_UIC_Text_Box : GAME::UI_COMPONENT::BASE::C_UI_Component_Base
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //

		// vCx[gÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			ASSET::MATERIAL::C_Material_User material;	// }eA

			RENDERING::CAPSULE::C_Object_Vertex_System<DATA::VERTEX::S_UI_Vertex> vertex_system;	// UIÌ¸_pÌVXe

			RENDERING::CAPSULE::C_Vertex_Index_System index_system;	// ¸_CfbNXVXe

		} mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O


		//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// RXgN^
		C_UIC_Text_Box(void);

		// fXgN^
		~C_UIC_Text_Box(void);


		//-- [h --//

		// wè³ê½¼OÌeNX`ð[h·é@øF[h·éeNX`¼
		void M_Load_Texture(std::string);


		//-- XV --//

		// XVðs¤
		void M_Update(void) override;


		//-- `æ --//

		// `æðs¤
		void M_Draw(void) override;


		//-- ÀW --//

		// UIÌÀWðZbg·é@øFZbgÊuÌlp`i¶ºªOCEãªPj
		void M_Set_UI_Position(DATA::RECTSETTING::S_Rect);


		//-- J[ --//

		// FðÝè·é@øFF
		void M_Set_Color(DATA::COLOR::C_Color);
	};
}


#endif // !D_INCLUDE_GUARD_C_UIC_TEXT_BOX

