////
// Ú×   Flp`ÌUIÌ}`è`pÌf[^
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "UI_Figure_Data.h"


//  l[Xy[XÌÈª  //
using namespace DATA::FIGURE::UI;


//  Ö  //

//== pubN ==//

//-- XV --//

//===============//
// Ú×   FUIpÌlp`ðNg©çÝè·é
// ø   FS_Rect & ÝuÊu
// ßèl Fvoid
//===============//
void C_UI_Box::M_Set_Constant_Pixel_By_Rect(RECTSETTING::S_Rect & in_set_rect)
{
	m_box_pos = in_set_rect;

	return;
}


//===============//
// Ú×   FFðSÄÌ¸_ÉÝè·é
// ø   FCOLOR & F
// ßèl Fvoid
//===============//
void C_UI_Box::M_Set_UI_Box_Color(DATA::COLOR::C_Color & in_color)
{
	m_box_color = in_color;

	return;
}
