////
// Ú×   FDX12Ì[xXeVobt@VXe
// à¾   F[xXeVobt@pÌf[^ðÇ·é
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include <directxpackedvector.h>

#include "C_DX12_Depth_Stencil_Buffer_System.h"
#include "E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE.h"
#include "C_Half_Color.h"

#include "C_Console_Log_Interface.h"


//  l[Xy[XÌÈª  //
using namespace RENDERING::API::DX12::DX12_INSTANCE;


//  Ö  //

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_DX12_Depth_Stencil_Buffer_System::C_DX12_Depth_Stencil_Buffer_System(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_DX12_Depth_Stencil_Buffer_System::~C_DX12_Depth_Stencil_Buffer_System(void)
{
	M_Release();

	return;
}


//===============//
// Ú×   Fððú·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_DX12_Depth_Stencil_Buffer_System::M_Release(void)
{
	m_data.depth_stencil_buffer.Reset();
	m_data.heap.Reset();
}


//-- æ --//

//===============//
// Ú×   F[xXeVobt@æÊðeNX`æÆµÄÛ¶·é
// ø   FC_Texture_Map & Û¶æÌeNX`æÊÌQÆ
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_DX12_Depth_Stencil_Buffer_System::M_Save_Screen_For_Texture(ASSET::TEXTURE::C_Texture_Map & in_texture_map)
{
	//  Ïé¾  //
	D3D12_RESOURCE_DESC resource_inform = m_data.depth_stencil_buffer->GetDesc();	// \[XÌîñ

	void * get_mapped_data = nullptr;	// æ¾µ½eNX`f[^


	// [xXeVobt@Ìf[^ðæ¾A¸sµ½çG[Å²¯é
	if (FAILED(m_data.depth_stencil_buffer->Map(0, nullptr, &get_mapped_data)))
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_RENDERING::con_RENDERING_ERROR, "[xXeVæÌæ¾É¸sµÜµ½");
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}

	// KvÈeNX`TCYð¶¬
	in_texture_map.M_Create_Texture_Map((int)RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE::e_WIDTH_SIZE, (int)RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE::e_HEIGHT_SIZE);


	// oCgÌÝèÉí¹ÄeNX`Ìf[^ðÚ·
	switch (resource_inform.Format)
	{
		// QoCgÌÇÝæè
	case DXGI_FORMAT::DXGI_FORMAT_D16_UNORM:
	{
		//  Ïé¾  //
		DirectX::PackedVector::HALF * get_depth_data = reinterpret_cast<DirectX::PackedVector::HALF * >(get_mapped_data);	// [xf[^i}bvÌf[^ðhalf_float^ÅÇÝÖ¦)

		std::vector<DATA::COLOR::C_Color> & texture_map = in_texture_map.M_Get_Texture_Map();	// eNX`}bvÖÌQÆ


		// eNX`Ìf[^ðÚ·
		for (int now_depth_pixel = 0; now_depth_pixel < (int)RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE::e_ALL_SIZE; now_depth_pixel++)
		{
			//  Ïé¾  //
			float color_data = DirectX::PackedVector::XMConvertHalfToFloat(get_depth_data[now_depth_pixel]);	// FÌf[^


			// eNX`Ìf[^ðÚ·
			texture_map[now_depth_pixel].m_r = color_data;
			texture_map[now_depth_pixel].m_g = color_data;
			texture_map[now_depth_pixel].m_b = color_data;
			texture_map[now_depth_pixel].m_a = 1.0f;
		}
	}
	return true;

	// SoCgÌÇÝæè
	case DXGI_FORMAT::DXGI_FORMAT_D32_FLOAT:
	{
		//  Ïé¾  //
		float * get_depth_data = reinterpret_cast<float*>(get_mapped_data);	// [xf[^i}bvÌf[^ðfloat^ÅÇÝÖ¦)

		std::vector<DATA::COLOR::C_Color> & texture_map = in_texture_map.M_Get_Texture_Map();	// eNX`}bvÖÌQÆ


		// eNX`Ìf[^ðÚ·
		for (int now_depth_pixel = 0; now_depth_pixel < (int)RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE::e_ALL_SIZE; now_depth_pixel++)
		{
			// eNX`Ìf[^ðÚ·
			texture_map[now_depth_pixel].m_r = get_depth_data[now_depth_pixel];
			texture_map[now_depth_pixel].m_g = get_depth_data[now_depth_pixel];
			texture_map[now_depth_pixel].m_b = get_depth_data[now_depth_pixel];
			texture_map[now_depth_pixel].m_a = 1.0f;
		}
	}
	return true;
	}

	// ^ª³øÈÌÅG[
	return false;
}
