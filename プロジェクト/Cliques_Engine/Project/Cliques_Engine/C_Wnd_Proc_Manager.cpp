////
// Ú×   FEBhEvV[Wð§ä·é½ßÌVXe
// à¾   F
// ì¬Ò Fûüâ´½
////


//  OSm  //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS


//  t@CÐç«  //
#include "C_Wnd_Proc_Manager.h"


//  l[Xy[XÌÈª  //
using namespace OS::WINDOWS::PROC;


//  Ïé¾  //
WNDPROC C_Wnd_Proc_Manager::m_add_Game_apk_wnd_proc = nullptr;	// EBhEvV[WÌAhXðÂ


//  Ö  //

//== pubN ==//

//-- Zb^ --//

//===============//
// Ú×   FQ[pÌEBhEvV[WðÝè·é
// ø   Fvoid
// ßèl FWNDPROC EBhEvV[WÖÌAhX
//===============//
void C_Wnd_Proc_Manager::M_Set_Game_APK_Wnd_Proc(WNDPROC in_proc)
{
	m_add_Game_apk_wnd_proc = in_proc;

	return;
}


//-- Qb^ --//

//===============//
// Ú×   FQ[pÌEBhEvV[WðÔ·
// ø   Fvoid
// ßèl FWNDPROC EBhEvV[WÖÌAhX
//===============//
WNDPROC C_Wnd_Proc_Manager::M_Get_Game_APK_Wnd_Proc(void)
{
	return m_add_Game_apk_wnd_proc;
}


#endif // OS_IS_WINDOWS
