////
// Ú×   FDX12Ì_OXN[i_OææjÌVXe
// à¾   F_[^[Qbgr[Æ[xXeVr[ðÇ·é
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include <DirectXMath.h>

#include "C_DX12_Rendering_Screen_System.h"
#include "C_Half_Color.h"
#include "C_1_Byte_Color.h"
#include "C_Color_Converter.h"

#include "C_Console_Log_Interface.h"


//  l[Xy[XÌÈª  //
using namespace RENDERING::API::DX12::DX12_INSTANCE;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_DX12_Rendering_Screen_System::C_DX12_Rendering_Screen_System(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_DX12_Rendering_Screen_System::~C_DX12_Rendering_Screen_System(void)
{
	return;
}


//===============//
// Ú×   FðJú·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_DX12_Rendering_Screen_System::M_Release(void)
{
	m_render_target_view.buffer_list.clear();
	m_render_target_view.buffer_list.shrink_to_fit();
	
	return;
}


//-- æ --//

//===============//
// Ú×   Fwè³ê½ÔÌ_OæÊðeNX`æÆµÄÛ¶·é
// ø   Fint _OæÊÔ, C_Texture_Map & Û¶æÌeNX`æÊÌQÆ
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_DX12_Rendering_Screen_System::M_Save_Screen_For_Texture(int in_screen_number, ASSET::TEXTURE::C_Texture_Map & in_to_texture)
{
	// ÍÍOðwè³ê½çG[ðoµÄ²¯é
	if (0 < in_screen_number || in_screen_number <= m_rendering_screen_sum)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_RENDERING::con_RENDERING_ERROR, "XN[æÔÉÍÍOðwè³êÜµ½");
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}


	//  Ïé¾  //
	D3D12_RESOURCE_DESC render_target_view_inform = m_render_target_view.buffer_list[in_screen_number].render_buffer->GetDesc();	// _[^[Qbgr[Ìîñ

	int texture_width = (int)render_target_view_inform.Width;	// æÌ¡
	int texture_height = (int)render_target_view_inform.Height;	// æÌc

	void * map_data = nullptr;	// }bvÉæÁÄæ¾µ½f[^


	// _[^[Qbgr[Ìf[^ðæ¾Aæ¾É¸sµ½çG[Å²¯é
	if (FAILED(m_render_target_view.buffer_list[in_screen_number].render_buffer.Get()->Map(0, nullptr, &map_data)))
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_RENDERING::con_RENDERING_ERROR, "XN[æÌæ¾É¸sµÜµ½");
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}

	// æfÌ^ÉæÁÄªò
	switch (render_target_view_inform.Format)
	{
		// æfÌFîñÍRGB»ê¼êPoCgÌæðæ¾iO`QTTj
	case DXGI_FORMAT::DXGI_FORMAT_B8G8R8A8_UNORM:
		{
			//  Ïé¾  //
			DATA::COLOR::C_1_Byte_Color * texture_color = nullptr;	// RGBAðSÄO`QTTÅó¯æêé^

			int pixel_sum = texture_width * texture_height;	// æÌæf


			// ^ÌðßðÏX
			texture_color = static_cast<DATA::COLOR::C_1_Byte_Color * >(map_data);

			// eNX`pÌ}bvð¶¬·é
			in_to_texture.M_Create_Texture_Map(texture_width, texture_height);


			//  Ïé¾  //
			std::vector<DATA::COLOR::C_Color> & texture_map = in_to_texture.M_Get_Texture_Map();	// eNX`Ì}bvðæ¾·é


			// eNX`pÌ}bvÉlðÚ·
			for (int l_now_pixel_number = 0; l_now_pixel_number < pixel_sum; l_now_pixel_number++)
			{
				// sNZÉFðhÁÄ¢­
				texture_map[l_now_pixel_number] = DATA::COLOR::C_Color_Converter::M_Convert_1_Byte_Color_To_Color(texture_color[l_now_pixel_number]);
			}

			// _[^[Qbgr[Ìf[^ðÂ¶ÄI¹
			m_render_target_view.buffer_list[in_screen_number].render_buffer.Get()->Unmap(0, nullptr);
		}
		return true;

		// æfÌFîñÍRGBA»ê¼êQoCgÅ éi-1.0`1.0j
	case DXGI_FORMAT::DXGI_FORMAT_R16G16B16A16_FLOAT:
		{
			//  Ïé¾  //
			DATA::COLOR::C_Half_Color * texture_color = nullptr;	// RGBAðSÄO`QTTÅó¯æêé^

			int pixel_sum = texture_width * texture_height;	// æÌæf


			// ^ÌðßðÏX
			texture_color = static_cast<DATA::COLOR::C_Half_Color * >(map_data);

			// eNX`pÌ}bvð¶¬·é
			in_to_texture.M_Create_Texture_Map(texture_width, texture_height);


			//  Ïé¾  //
			std::vector<DATA::COLOR::C_Color> & texture_map = in_to_texture.M_Get_Texture_Map();	// eNX`Ì}bvðæ¾·é


			// eNX`pÌ}bvÉlðÚ·
			for (int l_now_pixel_number = 0; l_now_pixel_number < pixel_sum; l_now_pixel_number++)
			{
				// sNZÉFðhÁÄ¢­
				texture_map[l_now_pixel_number] = DATA::COLOR::C_Color_Converter::M_Convert_Half_Color_To_Color(texture_color[l_now_pixel_number]);
			}

			// _[^[Qbgr[Ìf[^ðÂ¶ÄI¹
			m_render_target_view.buffer_list[in_screen_number].render_buffer.Get()->Unmap(0, nullptr);
		}
		return true;

		// æfÌFîñÍRGBA»ê¼êSoCgÅ éi-1.0`1.0j
	case DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_FLOAT:
		{
			//  Ïé¾  //
			DATA::COLOR::C_Color * texture_color = nullptr;	// RGBAðSÄO`QTTÅó¯æêé^

			int pixel_sum = texture_width * texture_height;	// æÌæf


			// ^ÌðßðÏX
			texture_color = static_cast<DATA::COLOR::C_Color * >(map_data);

			// eNX`pÌ}bvð¶¬·é
			in_to_texture.M_Create_Texture_Map(texture_width, texture_height);


			//  Ïé¾  //
			std::vector<DATA::COLOR::C_Color> & texture_map = in_to_texture.M_Get_Texture_Map();	// eNX`Ì}bvðæ¾·é


			// eNX`pÌ}bvÉlðÚ·
			for (int l_now_pixel_number = 0; l_now_pixel_number < pixel_sum; l_now_pixel_number++)
			{
				// sNZÉFðhÁÄ¢­
				texture_map[l_now_pixel_number] = texture_color[l_now_pixel_number];
			}

			// _[^[Qbgr[Ìf[^ðÂ¶ÄI¹
			m_render_target_view.buffer_list[in_screen_number].render_buffer.Get()->Unmap(0, nullptr);
		}
		return true;
	}

	// eNX`ÌíÞªs¾ÈçG[Å²¯é
	return false;
}


//-- Qb^ --//

//===============//
// Ú×   F_OæÊðÔ·
// ø   Fvoid
// ßèl Fint _OæÊ
//===============//
int C_DX12_Rendering_Screen_System::M_Get_Rendering_Screen_Sum(void)
{
	return m_rendering_screen_sum;
}

