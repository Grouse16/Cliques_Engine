////
// Ú×   FT[hp[eBÌàÌOtBbNð§ä·éVXeÌîêNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Rendering_API_Base.h"


//  l[Xy[X  //
using namespace RENDERING::API::BASE;


//  Ïé¾  //
std::unique_ptr <C_Rendering_API_Base> C_Rendering_API_Base::m_this;	// NXÌCX^XpAhXAåÉ|[tBY»Égp


//  Ö  //

//== pubN ==//

//-- I¹ --//

//===============//
// Ú×   F_OpÌAPIðI¹·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Rendering_API_Base::M_Delete_API(void)
{
	if (m_this != nullptr)
	{
		m_this.reset();
		m_this = nullptr;
	}

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Rendering_API_Base::~C_Rendering_API_Base(void)
{
	return;
}


//-- Qb^ --//

//===============//
// Ú×   F±ÌNXÌÀÌÌAhXðÔ·
// ø   Fvoid
// ßèl FC_Rendering_API_Base * _OAPIîêNXÌAhX
//===============//
C_Rendering_API_Base * C_Rendering_API_Base::M_Get_Instance(void)
{
	return m_this.get();
}
