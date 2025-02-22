////
// Ú×   FUIÌ}`è`pÌf[^
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "UI_Figure_Data.h"
#include "C_OS_User_System.h"


//  l[Xy[XÌÈª  //
using namespace DATA::FIGURE::UI;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Scale_Constant_UI::C_Scale_Constant_UI(void)
{
	m_box_color.m_r = 1.0f;
	m_box_color.m_g = 1.0f;
	m_box_color.m_b = 1.0f;
	m_box_color.m_a = 1.0f;

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Scale_Constant_UI::~C_Scale_Constant_UI(void)
{
	return;
}


//-- XV --//

//===============//
// Ú×   FîÆÈéêðwè·é
// ø   FE_Scale_Base_Position îÆÈéêðwè·é
// ßèl Fvoid
//===============//
void C_Scale_Constant_UI::M_Set_Scale_Base_Position(E_Scale_Base_Position in_base_position)
{
	m_base_position = in_base_position;

	return;
}


//-- XV --//

//===============//
// Ú×   FUIpÌlp`ðNg©çÝè·é
// ø   FS_Rect & ÝuÊu
// ßèl Fvoid
//===============//
void C_Scale_Constant_UI::M_Set_Constant_Pixel_By_Rect(DATA::RECTSETTING::S_Rect & in_set_rect)
{
	m_constant_pixel_pos = in_set_rect;

	return;
}


//===============//
// Ú×   FXP[ðsNZÀWÉí¹éXVðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Scale_Constant_UI::M_Scale_Update(void)
{
	//  Ïé¾  //
	const OS::S_Window_Size_Data & now_window_size = OS::C_OS_User_System::M_Get_Window_Size();   // »ÝÌEBhETCY
	

	// îÆÈéêÉæÁÄ¶EÌÊuðÝè
	switch (m_base_position)
	{
		// êÔ¶ðîÉ·é
	case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_LEFT_TOP:
	case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_LEFT_BOTTOM:
		m_box_pos.left_x = m_constant_pixel_pos.left_x / now_window_size.width;
		m_box_pos.right_x = m_constant_pixel_pos.right_x / now_window_size.width;
		break;

		// êÔEðîÉ·é
	case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_RIGHT_TOP:
	case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_RIGHT_BOTTOM:
		m_box_pos.left_x = (now_window_size.width - m_constant_pixel_pos.left_x) / now_window_size.width;
		m_box_pos.right_x = (now_window_size.width - m_constant_pixel_pos.right_x) / now_window_size.width;
		break;
	}

	// îÆÈéêÉæÁÄãºÌÊuðÝè
	switch (m_base_position)
	{
		// êÔãðîÉ·é
	case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_LEFT_TOP:
	case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_RIGHT_TOP:
		m_box_pos.top_y = (now_window_size.height - m_constant_pixel_pos.top_y) / now_window_size.height;
		m_box_pos.bottom_y = (now_window_size.height - m_constant_pixel_pos.bottom_y) / now_window_size.height;
		break;

		// êÔºðîÉ·é
	case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_LEFT_BOTTOM:
	case DATA::FIGURE::UI::C_Scale_Constant_UI::E_Scale_Base_Position::e_RIGHT_BOTTOM:
		m_box_pos.top_y = m_constant_pixel_pos.top_y / now_window_size.height;
		m_box_pos.bottom_y = m_constant_pixel_pos.bottom_y / now_window_size.height;
		break;
	}


	// æÊÌÝèÉí¹é
	m_box_pos.left_x = m_box_pos.left_x * 2 - 1;
	m_box_pos.right_x = m_box_pos.right_x * 2 - 1;
	m_box_pos.top_y = m_box_pos.top_y * 2 - 1;
	m_box_pos.bottom_y = m_box_pos.bottom_y * 2 - 1;

	return;
}


