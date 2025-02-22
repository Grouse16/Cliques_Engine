////
// Ú×   FQ[ÌüÍ»èðÆé½è»è
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Game_Input_Collision_Manager.h"


//  l[Xy[XÌÈª  //
using namespace GAME::INPUT::COLLISION;


//  Ö  //

//== vCx[g ==//


//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Game_Input_Collision::C_Game_Input_Collision(void)
{
	C_Game_Input_Collision_Manager::M_Add_Input_Box_Address_To_List(this);

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Game_Input_Collision::~C_Game_Input_Collision(void)
{
	C_Game_Input_Collision_Manager::M_Delete_Input_Box_Address_From_List(this);

	return;
}


//-- Zb^ --//

//===============//
// Ú×   F{bNXÌ¼OðZbg·é
// ø   Fwstring Ýè·é{bNX¼
// ßèl Fvoid
//===============//
void C_Game_Input_Collision::M_Set_Box_Name(std::wstring in_set_name)
{
	mpr_variable.collision_name = in_set_name;

	return;
}


//===============//
// Ú×   F½è»èðLøÉ·é©Ç¤©ðZbg·é
// ø   Fbool trueÅANeBuÉ·é
// ßèl Fvoid
//===============//
void C_Game_Input_Collision::M_Set_Is_Active(bool in_set_active_state)
{
	mpr_variable.is_active = in_set_active_state;

	return;
}


//===============//
// Ú×   F½è»èÌDæxðZbg·é
// ø   Fint Ýè·éDæx
// ßèl Fvoid
//===============//
void C_Game_Input_Collision::M_Set_Priority(int in_set_priority)
{
	mpr_variable.priority = in_set_priority;

	return;
}


//-- Qb^ --//

//===============//
// Ú×   F½è»èÌ¼Oðæ¾·é
// ø   Fconst wstring & »ÝÌ½è»èÌ¼OÌÏÌQÆ(const)
// ßèl Fvoid
//===============//
const std::wstring & C_Game_Input_Collision::M_Get_Collision_Name(void) const
{
	return mpr_variable.collision_name;
}


//===============//
// Ú×   F½è»èðLøÉ·é©Ç¤©ðæ¾·é
// ø   Fvoid
// ßèl Fbool trueÈçANeBu
//===============//
bool C_Game_Input_Collision::M_Get_Is_Active(void) const
{
	return mpr_variable.is_active;
}


//===============//
// Ú×   F»ÝÌ½è»èÌDæxðÔ·
// ø   Fvoid
// ßèl Fint ½è»èÌDæx
//===============//
int C_Game_Input_Collision::M_Get_Priority(void) const
{
	return mpr_variable.priority;
}


//-- óÔÌJÚ --//

//===============//
// Ú×   F½à³êÄ¢È¢óÔÖJÚ
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Input_Collision::M_Change_State_Command_Not_Hit(void)
{
	//  OñÌüÍ»èÌóÔÉæÁÄªò  //
	switch (mpr_variable.collision_state)
	{
	// NbNüÍÈçAüÍI¹ð·é
	case E_Game_Input_Collision_State::e_CLICK_START:
	case E_Game_Input_Collision_State::e_CLICK_DOING:
		mpr_variable.collision_state = E_Game_Input_Collision_State::e_CLICK_END;
		break;

	// _uNbNÈçAüÍI¹ð·é
	case E_Game_Input_Collision_State::e_DOUBLE_CLICK_START:
	case E_Game_Input_Collision_State::e_DOUBLE_CLICK_DOING:
		mpr_variable.collision_state = E_Game_Input_Collision_State::e_DOUBLE_CLICK_END;
		break;

	// hbOüÍÍAhbOüÍðI¹·é
	case E_Game_Input_Collision_State::e_DRAG_START:
	case E_Game_Input_Collision_State::e_DRAG_DOING:
		mpr_variable.collision_state = E_Game_Input_Collision_State::e_DRAG_END;
		break;

	// dÈÁÄ¢é©AÊíóÔÉßéÆ«ÍAÊíóÔÉß·
	default:
		mpr_variable.collision_state = E_Game_Input_Collision_State::e_NOT_HIT;
		break;
	}

	return;
}


//===============//
// Ú×   FJ[\ªdÈÁÄ¢éóÔÖJÚ
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Input_Collision::M_Change_State_Command_Overed(void)
{
	//  OñÌüÍ»èÌóÔÉæÁÄªò  //
	switch (mpr_variable.collision_state)
	{
		// NbNüÍÈçAüÍI¹ð·é
	case E_Game_Input_Collision_State::e_CLICK_START:
	case E_Game_Input_Collision_State::e_CLICK_DOING:
		mpr_variable.collision_state = E_Game_Input_Collision_State::e_CLICK_END;
		break;

		// _uNbNÈçAüÍI¹ð·é
	case E_Game_Input_Collision_State::e_DOUBLE_CLICK_START:
	case E_Game_Input_Collision_State::e_DOUBLE_CLICK_DOING:
		mpr_variable.collision_state = E_Game_Input_Collision_State::e_DOUBLE_CLICK_END;
		break;

		// hbOüÍÍAhbOüÍðI¹·é
	case E_Game_Input_Collision_State::e_DRAG_START:
	case E_Game_Input_Collision_State::e_DRAG_DOING:
		mpr_variable.collision_state = E_Game_Input_Collision_State::e_DRAG_END;
		break;

		// ÊíóÔ©AÊíóÔÉßéóÔÈçdÈÁÄ¢éóÔÉÈé
	default:
		mpr_variable.collision_state = E_Game_Input_Collision_State::e_OVERED;
		break;
	}

	return;
}


//===============//
// Ú×   FNbNÌóÔÖJÚ
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Input_Collision::M_Change_State_Command_Clicking(void)
{
	//  OñÌüÍ»èÌóÔÉæÁÄªò  //
	switch (mpr_variable.collision_state)
	{
		// NbNüÍ³êÄ¢È¢óÔÈçNbNüÍðnßé
	default:
		mpr_variable.collision_state = E_Game_Input_Collision_State::e_CLICK_START;
		break;

		// NbNüÍJn¶ÈçNbNüÍð±s
	case E_Game_Input_Collision_State::e_CLICK_START:
		mpr_variable.collision_state = E_Game_Input_Collision_State::e_CLICK_DOING;
		break;

		// NbNüÍÍ½àµÈ¢(defaultp)
	case E_Game_Input_Collision_State::e_CLICK_DOING:
		break;
	}

	return;
}


//===============//
// Ú×   F_uNbNÌóÔÖJÚ
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Input_Collision::M_Change_State_Command_Double_Clicking(void)
{
	//  OñÌüÍ»èÌóÔÉæÁÄªò  //
	switch (mpr_variable.collision_state)
	{
		// _uNbNüÍ³êÄ¢È¢óÔÈç_uNbNüÍðnßé
	default:
		mpr_variable.collision_state = E_Game_Input_Collision_State::e_DOUBLE_CLICK_START;
		break;

		// _uNbNüÍJnÈç_uNbNüÍð±s
	case E_Game_Input_Collision_State::e_DOUBLE_CLICK_START:
		mpr_variable.collision_state = E_Game_Input_Collision_State::e_DOUBLE_CLICK_DOING;
		break;

		// _uNbNüÍÍ½àµÈ¢(defaultp)
	case E_Game_Input_Collision_State::e_DOUBLE_CLICK_DOING:
		break;
	}

	return;
}


//===============//
// Ú×   FhbOÌóÔÖJÚ
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Input_Collision::M_Change_State_Command_Dragging(void)
{
	//  OñÌüÍ»èÌóÔÉæÁÄªò  //
	switch (mpr_variable.collision_state)
	{
		// hbOüÍ³êÄ¢È¢óÔÈçhbOüÍðnßé
	default:
		mpr_variable.collision_state = E_Game_Input_Collision_State::e_DRAG_START;
		break;

		// hbOüÍJnÈçhbOüÍð±s
	case E_Game_Input_Collision_State::e_DRAG_START:
		mpr_variable.collision_state = E_Game_Input_Collision_State::e_DRAG_DOING;
		break;

		// hbOüÍÍ½àµÈ¢(defaultp)
	case E_Game_Input_Collision_State::e_DRAG_DOING:
		break;
	}

	return;
}


//===============//
// Ú×   FhbOÉJ[\ªdÈÁÄ¢éóÔÖJÚ
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Input_Collision::M_Change_State_Command_Dragging_Over(void)
{
	//  OñÌüÍ»èÌóÔÉæÁÄªò  //
	switch (mpr_variable.collision_state)
	{
		// hbOüÍÉ©³ÈÁÄ¢È¢óÔÈçhbOüÍÉdÈÁÄ¢éóÔðwè
	default:
		mpr_variable.collision_state = E_Game_Input_Collision_State::e_DRAG_OVERED;
		break;

		// hbOüÍÉdÈÁÄ¢é»èÍ½àµÈ¢(defaultp)
	case E_Game_Input_Collision_State::e_DRAG_OVERED:
		break;
	}

	return;
}


//===============//
// Ú×   FhbOÉ½è»èÌãÅhbv³ê½±Æð¦·
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Game_Input_Collision::M_Change_State_Command_Drag_Dropped(void)
{
	//  OñÌüÍ»èÌóÔÉæÁÄªò  //
	switch (mpr_variable.collision_state)
	{
		// hbv³ê½óÔÅÈ¢ÈçóÔÈçhbv³ê½óÔðwè
	default:
		mpr_variable.collision_state = E_Game_Input_Collision_State::e_DRAG_OVER_DROPPED;
		break;

		// hbv³ê½óÔÉÈÁÄ¢éÈç½àµÈ¢(defaultp)
	case E_Game_Input_Collision_State::e_DRAG_OVER_DROPPED:
		break;
	}

	return;
}


