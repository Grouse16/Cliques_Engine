////
// Ú×   FUIÝèpÌÏQ
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "UI_Figure_Data.h"


//  l[Xy[XÌÈª  //
using namespace DATA::FIGURE::UI;


//  Ïé¾  //
C_UI_SETTING_DATA C_UI_SETTING_DATA::m_this;	// ©gðè`·é½ßÌÏ

float C_UI_SETTING_DATA::ui_width;
float C_UI_SETTING_DATA::ui_height;
float C_UI_SETTING_DATA::aspect_x;
float C_UI_SETTING_DATA::aspect_y;
float C_UI_SETTING_DATA::percent_of_aspect_x;
float C_UI_SETTING_DATA::percent_of_aspect_y;


//  Ö  //

//== vCx[g ==//

//-- ú» --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
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