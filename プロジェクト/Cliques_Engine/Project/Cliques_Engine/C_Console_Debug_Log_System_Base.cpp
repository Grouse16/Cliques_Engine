////
// Ú×   FfobOOVXeÌîêNXpÌè`ðs¤t@C
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Console_Debug_Log_System_Base.h"


//  l[Xy[XÌÈª  //
using namespace DEBUGGER::LOG::CONSOLE::BASE;


//  ÃIÏé¾  //
std::unique_ptr<C_Console_Debug_Log_System_Base> C_Console_Debug_Log_System_Base::m_this;	// ©NXÖÌANZXpÌÏ

C_Console_Debug_Log_System_Base::Pr_Variable C_Console_Debug_Log_System_Base::mpr_variable;	// vCx[gÏÖÌANZXpÌÏ


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Console_Debug_Log_System_Base::C_Console_Debug_Log_System_Base(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Console_Debug_Log_System_Base::~C_Console_Debug_Log_System_Base(void)
{
	return;
}


//===============//
// Ú×   FfobOOVXeððú·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Console_Debug_Log_System_Base::M_Release(void)
{
	// ·ÅÉÈ¢êÍí·éKvÍÈ¢
	if (m_this == nullptr)
	{
		return;
	}

	// ðú·é
	m_this.release();

	return;
}


//-- Qb^ --//

//===============//
// Ú×   FR\[OVXeÌCX^XÌAhXðÔ·
// ø   Fvoid
// ßèl FC_Console_Debug_Log_System_Base * R\[OVXeÌQÆ
//===============//
C_Console_Debug_Log_System_Base * C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System(void)
{
	return m_this.get();
}
