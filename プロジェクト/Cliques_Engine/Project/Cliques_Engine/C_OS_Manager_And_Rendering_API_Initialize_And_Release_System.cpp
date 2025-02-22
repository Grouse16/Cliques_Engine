////
// Ú×   FOtBbNXAPIðú»·é½ßÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_OS_Manager_And_Rendering_API_Initialize_And_Release_System.h"
#include "C_OS_Management_System_Base.h"
#include "Platform_Detector_Macro.h"
#include "C_Platform_Detection_System.h"
#include "C_Rendering_API_Interface_Initialize_And_Release.h"


//  }N  //

//  EBhEYOSÌÌÝDirectXðLø»  //
#ifdef D_OS_IS_WINDOWS
#include "C_Windows_OS_Management_System.h"
#endif // D_OS_IS_WINDOWS


//  l[Xy[XÌÈª  //
using namespace PLATFORM;


//  Ö  //

//== vCx[g ==//

//-- ú» --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::C_OS_Manager_And_Rendering_API_Initialize_And_Release_System(void)
{
	return;
}


//-- ¶¬ --//

//===============//
// Ú×   FOS§äVXeÌú»ðs¤
// ø   Fvoid
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Init_OS(void)
{
	return OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Set_Up();
}


//===============//
// Ú×   F_OAPIÌú»ðs¤
// ø   Fvoid
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Init_Rendering_API(void)
{
	//  ú»·éAPIÉæÁÄªò  //
	switch (PLATFORM::DETECTION::C_Platform_Detection_System::M_Get_Rendering_API_Number())
	{
		//  EBhEYOSÌÌÝDirectXðLø»  //
#ifdef D_OS_IS_WINDOWS

	//  DX11  //
	case PLATFORM::E_RENDERING_API_KIND::e_DX11:

		break;

		//  DX12  //
	case PLATFORM::E_RENDERING_API_KIND::e_DX12:

		// DX12Ì¶¬
		RENDERING::API::RENDER_INTERFACE::C_Rendering_API_Interface_Initialize_And_Release::M_Create_DX12();

		// _OAPIÌú»
		return RENDERING::API::RENDER_INTERFACE::C_Rendering_API_Interface_Initialize_And_Release::M_Initialize_Rendering_API();

#endif // D_OS_IS_WINDOWS


		//  Vulkan  //
	case PLATFORM::E_RENDERING_API_KIND::e_VULKAN:


		break;

		//  wèªÈ¢ÍOpenGLÅN®  //
		//  OpenGL  //
	case PLATFORM::E_RENDERING_API_KIND::e_OPENGL:
	default:

		// _OAPIªOpenGLÅ é±Æð¦·
		PLATFORM::DETECTION::C_Platform_Detection_System::M_Set_Rendering_API_Number(PLATFORM::E_RENDERING_API_KIND::e_OPENGL);

		break;
	}

	// ú»Æ¶¬É¸s
	return false;
}


//== pubN ==//

//-- ¶¬ --//

//===============//
// Ú×   FOS§äVXeÌ¶¬ðs¤
// ø   FE_RENDERING_API_KIND gp·éAPIÌíÞÖÌQÆ
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Create_OS(E_RENDERING_API_KIND in_use_api_kind)
{
	//  EBhEYñÎÍOpenGLÉØèÖ¦é  //
	if ((in_use_api_kind == E_RENDERING_API_KIND::e_DX12 || in_use_api_kind == E_RENDERING_API_KIND::e_DX11) && PLATFORM::DETECTION::C_Platform_Detection_System::M_Get_Platform_Number() != PLATFORM::E_OS_KIND::e_WINDOWS)
	{
		in_use_api_kind = E_RENDERING_API_KIND::e_OPENGL;
	}


	//  ú»·éAPIÉæÁÄªò  //
	switch (in_use_api_kind)
	{
		//  EBhEYOSÌÌÝDirectXðLø»  //
#ifdef D_OS_IS_WINDOWS

	//  DX11  //
	case E_RENDERING_API_KIND::e_DX11:

		// EBhEYpVXeÌ¶¬
		OS::WINDOWS::C_Windows_OS_Management_System::M_Create_Windows_System();

		// _OAPIªDX11Å é±Æð¦·
		PLATFORM::DETECTION::C_Platform_Detection_System::M_Set_Rendering_API_Number(PLATFORM::E_RENDERING_API_KIND::e_DX11);

		break;

		//  DX12  //
	case E_RENDERING_API_KIND::e_DX12:

		// EBhEYpVXeÌ¶¬
		OS::WINDOWS::C_Windows_OS_Management_System::M_Create_Windows_System();

		// _OAPIªDX12Å é±Æð¦·
		PLATFORM::DETECTION::C_Platform_Detection_System::M_Set_Rendering_API_Number(PLATFORM::E_RENDERING_API_KIND::e_DX12);

		break;

#endif // D_OS_IS_WINDOWS

		//  OpenGL  //
	case E_RENDERING_API_KIND::e_OPENGL:


		// _OAPIªOpenGLÅ é±Æð¦·
		PLATFORM::DETECTION::C_Platform_Detection_System::M_Set_Rendering_API_Number(PLATFORM::E_RENDERING_API_KIND::e_OPENGL);

		break;


		//  Vulkan  //
	case E_RENDERING_API_KIND::e_VULKAN:


		break;

		//  ÈÉà¶¬Å«È©Á½ÌÅG[ðoµÄI¹  //
	default:
		return false;
		break;
	}

	// ú»É¬÷
	return true;
}


//===============//
// Ú×   FOS§äVXeÆ_OAPIð¶¬·é
// ø   Fvoid
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Init_OS_Management_System_And_Create_Rendering_API(void)
{
	// OS§äVXeÌú»@¸sÅG[ðoµÄ²¯é
	if (M_Init_OS() == false)
	{
		return false;
	}


	// _OAPIÌú»ðs¤@¸sÅG[ðoµÄ²¯é
	if (M_Init_Rendering_API() == false)
	{
		return false;
	}

	return true;
}


//-- I¹ --//

//===============//
// Ú×   FOS§äVXeÆ_OAPIððú·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Release_OS_Management_System_And_Rendering_API(void)
{
	// _OAPIÌðú
	RENDERING::API::RENDER_INTERFACE::C_Rendering_API_Interface_Initialize_And_Release::M_Release_Rendering_API();
	
	// OSÌðú
	if (OS::BASE::C_OS_Management_System_Base::M_Get_Instance() != nullptr)
	{
		OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Release();
		OS::BASE::C_OS_Management_System_Base::M_Delete_OS_System();
	}

	return;
}

