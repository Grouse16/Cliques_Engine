////
// Ú×   FDX12Ì@\ðg¤½ßÌNX
// à¾   FDX12Ýèâ`æðs¤
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include <string>


//  OSm  //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS	// WindowsOSÌÌÝLø

#include "C_OS_User_System.h"
#include "C_DX12_System.h"
#include "C_DX12_Input_Layout_Setting_System.h"
#include "C_DX12_Streaming_Output_Buffer_Base.h"
#include "C_DX12_Blend_State_Setting_System.h"
#include "C_DX12_Rasterizer_State_Setting_System.h"
#include "C_DX12_Sampling_Setting_System.h"
#include "C_DX12_Stencil_State_Setting_System.h"
#include "C_DX12_Cached_PSO_Base.h"
#include "C_DX12_Font_Data_Set.h"
#include "S_Create_Render_Screen_Inform.h"
#include "E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE.h"
#include "C_DX12_Depth_Stencil_Buffer_System.h"

#include "C_Console_Log_Interface.h"


//  CuÐç«  //
#pragma comment (lib, "d3d12.lib")
#pragma comment (lib, "dxgi.lib")
#pragma comment (lib, "dxguid.lib")
#pragma comment (lib, "D3DCompiler.lib")


// @OVXepÌÛ  //
#ifndef D_TEXTURE_CHALLEGE
#include <DirectXTex.h>
#pragma comment (lib, "DirectXTex.lib")
#endif


//  l[Xy[XÌÈª  //
using namespace RENDERING::API::DX12;


//  CCÖ  //

//-- ú» --//

//===============//
// Ú×   Fobt@ð[NA·é
// ø   FC_Buffer * [NA·éobt@ÌQÆ, int NA·éoCg
// ßèl Fvoid
//===============//
template <class C_Buffer> inline void M_Buffer_Zero_Clear_System(C_Buffer * in_clear_buffer, int in_clear_data_byte)
{
	//  Ïé¾  //
	void * vertex_buffer_data = nullptr;    // ¸_obt@Ìf[^

	unsigned char * vertex_buffer_data_byte = nullptr;    // ¸_obt@Ìf[^ðPoCgÆµÄµ¤


	// obt@Ìf[^ðæ¾
	in_clear_buffer->Map(0, nullptr, &vertex_buffer_data);
	vertex_buffer_data_byte = reinterpret_cast<unsigned char * >(vertex_buffer_data);


	// f[^ðSÄ0Åú»·é
	for (int l_now_byte = 0; l_now_byte < in_clear_data_byte; l_now_byte++)
	{
		vertex_buffer_data_byte[l_now_byte] = 0;
	}

	// obt@ÌbNðð
	in_clear_buffer->Unmap(0, nullptr);

	return;
}


//-- Ýè --//

//===============//
// Ú×   F[gVOl`Ìp[^ÌÝèðs¤
// ø   Fvector<D3D12_ROOT_PARAMETER> & Ýèæ[gp[^[ÌQÆ, vector<D3D12_DESCRIPTOR_RANGE> & ÝèæÌWÌQÆ, D3D12_DESCRIPTOR_RANGE_TYPE Ýè·éíÞ, int WX^Ô, int VF[_[Ô
// ßèl Fvoid
//===============//
static inline void Inline_Set_Root_Parameter(std::vector<D3D12_ROOT_PARAMETER> & in_root_param, std::vector<D3D12_DESCRIPTOR_RANGE> & in_range, D3D12_DESCRIPTOR_RANGE_TYPE in_set_type, int register_num, int shader_num)
{
	//  Ïé¾  //
	int set_param_number = (int)in_root_param.size();    // ÝèæÌp[^ÌzñÔ
	int set_range_pos = (int)in_range.size();    // ÝèæÌWÔ


	// zñðKvÈ¾¯â·
	in_root_param.resize((size_t)(set_param_number + 1));
	in_range.resize((size_t)(set_range_pos + 1));

	// p[^ÌíÞ
	in_range[set_range_pos].RangeType = in_set_type;

	// ¢­ÂÌèobt@âeNX`ð±ÌWX^ÅÇ·é©izñj
	in_range[set_range_pos].NumDescriptors = 1;

	// VF[_[ÅÌWX^Ô
	in_range[set_range_pos].BaseShaderRegister = register_num;

	// WX^ÌXy[XÔ
	in_range[set_range_pos].RegisterSpace = 0;

	// WàÅ½oCgÚÉf[^ªé©
	in_range[set_range_pos].OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;


	//  p[^Ýè  //

	// XbgÌíÞ
	in_root_param[set_param_number].ParameterType = D3D12_ROOT_PARAMETER_TYPE::D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;

	// WÌzñ
	in_root_param[set_param_number].DescriptorTable.NumDescriptorRanges = 1;

	// WÌAhX
	in_root_param[set_param_number].DescriptorTable.pDescriptorRanges = &in_range[set_range_pos];

	// ÇÌVF[_[Å±ÌXbgðg¤©
	in_root_param[set_param_number].ShaderVisibility = (D3D12_SHADER_VISIBILITY)shader_num;

	return;
}


//===============//
// Ú×   F[gVOl`Ìp[^ÌÝèðs¤
// ø   Fvector<D3D12_STATIC_SAMPLER_DESC> & Tv[Ýèpîñ, int WX^Ô, int VF[_[Ô, D3D12_TEXTURE_ADDRESS_MODE UVÌgpû@
// ßèl Fvoid
//===============//
static inline void Inline_Set_Sampler_State(std::vector<D3D12_STATIC_SAMPLER_DESC> & in_sampler_desc, int in_register_num, int in_shader_num, D3D12_TEXTURE_ADDRESS_MODE in_address_mode)
{
	//  Ïé¾  //
	int set_static_number = (int)in_sampler_desc.size();    // ÝèæÌp[^ÌzñÔ


	// zñðKvÈ¾¯â·
	in_sampler_desc.resize((size_t)(set_static_number + 1));


	// tB^ÌIvV
	in_sampler_desc[set_static_number].Filter = D3D12_FILTER::D3D12_FILTER_MIN_MAG_MIP_LINEAR;

	// UÀWÌÌdû
	in_sampler_desc[set_static_number].AddressU = in_address_mode;

	// VÀWÌÌdû
	in_sampler_desc[set_static_number].AddressV = in_address_mode;

	// WÀWÌÌdû
	in_sampler_desc[set_static_number].AddressW = in_address_mode;

	// ~bv}bvxÌItZbg
	in_sampler_desc[set_static_number].MipLODBias = 0.0f;

	// tB^ªD3D12_FILTER_ANISOTROPICÜ½ÍD3D12_FILTER_COMPARISON_ANISOTROPICÌÆ«Égp³êéNvl
	in_sampler_desc[set_static_number].MaxAnisotropy = 16;

	// TvO³ê½f[^ðù¶ÌTvO f[^Æär·éÖðIÔ
	in_sampler_desc[set_static_number].ComparisonFunc = D3D12_COMPARISON_FUNC::D3D12_COMPARISON_FUNC_NEVER;

	// D3D12_TEXTURE_ADDRESS_MODE_BORDERªAddressUVWÉÝè³êÄ¢éÌ«EüÌF
	in_sampler_desc[set_static_number].BorderColor = D3D12_STATIC_BORDER_COLOR::D3D12_STATIC_BORDER_COLOR_TRANSPARENT_BLACK;

	// ~bv}bvxÌÚ×xÌÅál
	in_sampler_desc[set_static_number].MinLOD = 0.0f;

	// ~bv}bvxÌÚ×xÌÅl
	in_sampler_desc[set_static_number].MaxLOD = D3D12_FLOAT32_MAX;

	// VF[_[ÅÌWX^Ô
	in_sampler_desc[set_static_number].ShaderRegister = in_register_num;

	// WX^ÌXy[XÔ
	in_sampler_desc[set_static_number].RegisterSpace = 0;

	// ÇÌVF[_[©çANZXÅ«é©
	in_sampler_desc[set_static_number].ShaderVisibility = (D3D12_SHADER_VISIBILITY)in_shader_num;

	return;
}


//===============//
// Ú×   F[gVOl`fXNÉfBXNv^XbgÆTv[ðÝè·é
// ø   FD3D12_ROOT_SIGNATURE_DESC & [gVOl`ÌÝèpîñÌQÆ, vector<D3D12_ROOT_PARAMETER> & fBXNv^ÝèpîñÌQÆ, vector<D3D12_STATIC_SAMPLER_DESC> & Tv[ÝèpîñÌQÆ
// ßèl Fvoid
//===============//
static inline void Inline_Set_Parameters_And_Sampler_Desc_To_Root_Signature_Desc(D3D12_ROOT_SIGNATURE_DESC & in_root_signature, std::vector<D3D12_ROOT_PARAMETER> & in_parameter, std::vector<D3D12_STATIC_SAMPLER_DESC> & in_sampler)
{
	// fBXNv^îñª êÎfBXNv^XbgÆÅÌAhXðZbg
	if (in_parameter.size() > 0)
	{
		in_root_signature.NumParameters = (UINT)in_parameter.size();
		in_root_signature.pParameters = &in_parameter[0];
	}

	// È¯êÎ[NA·é
	else
	{
		in_root_signature.NumParameters = 0;
		in_root_signature.pParameters = nullptr;
	}


	// Tv[ª êÎTv[ÆÅÌAhXðZbg
	if (in_parameter.size() > 0)
	{
		in_root_signature.NumStaticSamplers = (UINT)in_parameter.size();
		in_root_signature.pStaticSamplers = &in_sampler[0];
	}

	// È¯êÎ[NA·é
	else
	{
		in_root_signature.NumStaticSamplers = 0;
		in_root_signature.pStaticSamplers = nullptr;
	}

	return;
}


//===============//
// Ú×   FVF[_[Ìf[^ðDX12pÌoCgR[hÉZbg·é
// ø   FD3D12_SHADER_BYTECODE & ZbgæÌoCgR[hÌQÆ, const C_Shader_Code * Zbg·éVF[_[R[h
// ßèl Fvoid
//===============//
static inline void Inline_Set_Shader_Data(D3D12_SHADER_BYTECODE & in_set_code, const ASSET::SHADER::C_Shader_Code * in_shader_code)
{
	// VF[_[ÌR[hªÈ¢Èç²¯é
	if (in_shader_code == nullptr)
	{
		return;
	}

	// oCgR[hÌAhXÆTCYðZbg
	in_set_code.pShaderBytecode = in_shader_code->M_Get_Compiled_Cord().get();
	in_set_code.BytecodeLength = in_shader_code->M_Get_Cord_Size();

	return;
}


//-- Ï· --//

//===============//
// Ú×   Fn³ê½¶ñðeNX`ÌUVgpû@ÉÏ·µÄÔ·
// ø   Fstring UVÌgpû@Ìwèp¶ñ
// ßèl FD3D12_TEXTURE_ADDRESS_MODE UVÌgpû@Ìñ
//===============//
static inline D3D12_TEXTURE_ADDRESS_MODE Inline_Get_Texture_Mode(std::string in_texture_address_mode_text)
{
	// UVªO`Pð´¦éÆJèÔµ\¦
	if (in_texture_address_mode_text == "WARP")
	{
		return D3D12_TEXTURE_ADDRESS_MODE::D3D12_TEXTURE_ADDRESS_MODE_WRAP;
	}

	// UVªO`Pð´¦éÆeNX`Ì[ÉB·é½ÑÉ½]µÄJèÔµ\¦
	else if (in_texture_address_mode_text == "MIRROR")
	{
		return D3D12_TEXTURE_ADDRESS_MODE::D3D12_TEXTURE_ADDRESS_MODE_MIRROR;
	}

	// UVªO`Pð´¦éÆUVð­§IÉO©PÉÝè
	else if (in_texture_address_mode_text == "CLAMP")
	{
		return D3D12_TEXTURE_ADDRESS_MODE::D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
	}

	// UVªO`Pð´¦éÆUVð­§IÉFðÔ·
	else if (in_texture_address_mode_text == "BORDER")
	{
		return D3D12_TEXTURE_ADDRESS_MODE::D3D12_TEXTURE_ADDRESS_MODE_BORDER;
	}

	// UVªO`Pð´¦éÆUVðêx½]µ½eNX`ªo»·éª»ÌãÍ½à\¦µÈ¢
	return D3D12_TEXTURE_ADDRESS_MODE::D3D12_TEXTURE_ADDRESS_MODE_MIRROR_ONCE;
}


//===============//
// Ú×   Fn³ê½¶ñðDX12ÌVF[_[ÌíÞÉÏ·µÄÔ·
// ø   FE_SHADER_KIND VF[_[ÌíÞ
// ßèl FD3D12_SHADER_VISIBILITY DX12ÌVF[_[ÌíÞ
//===============//
static inline D3D12_SHADER_VISIBILITY M_Convert_Shader_Kind_To_DX12_Shader_Kind(ASSET::SHADER::E_SHADER_KIND in_shader_kind)
{
	switch (in_shader_kind)
	{
	case ASSET::SHADER::E_SHADER_KIND::e_VERTEX:
		return D3D12_SHADER_VISIBILITY::D3D12_SHADER_VISIBILITY_VERTEX;
	case ASSET::SHADER::E_SHADER_KIND::e_HULL_TCS:
		return D3D12_SHADER_VISIBILITY::D3D12_SHADER_VISIBILITY_HULL;
	case ASSET::SHADER::E_SHADER_KIND::e_DOMAIN_TES:
		return D3D12_SHADER_VISIBILITY::D3D12_SHADER_VISIBILITY_DOMAIN;
	case ASSET::SHADER::E_SHADER_KIND::e_GEOMETRY:
		return D3D12_SHADER_VISIBILITY::D3D12_SHADER_VISIBILITY_GEOMETRY;
	case ASSET::SHADER::E_SHADER_KIND::e_PIXEL_FRAGMENT:
		return D3D12_SHADER_VISIBILITY::D3D12_SHADER_VISIBILITY_PIXEL;
	case ASSET::SHADER::E_SHADER_KIND::e_ALL:
		return D3D12_SHADER_VISIBILITY::D3D12_SHADER_VISIBILITY_ALL;
	}

	return D3D12_SHADER_VISIBILITY::D3D12_SHADER_VISIBILITY_ALL;
}


//  Ö  //

//== vCx[g ==//

//--  ú»  --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_DX12_System::C_DX12_System(void)
{
	return;
}


//===============//
// Ú×   FfoCXâ`æR}hA_OæÌÝèÌú»
// ø   Fvoid
// ßèl Fbool §¿ã°É¬÷µÄ¢½çtrue
//===============//
bool C_DX12_System::M_DirectX12_Init(void)
{
	// DX12VXeÌZbgAbvÌJnðm
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "--------DX12ÌZbgAbvJn--------");


	// DX12pÏQÌú»
	mpr_variable.reset(new C_DX12_System::SPr_Variable());


	// tFXÌÔðú»
	for (int l_now_fence_number = 0; l_now_fence_number < (int)E_DX12_PARAMATOR::e_RENDER_TARGET_BUFFER_SUM; l_now_fence_number++)
	{
		mpr_variable->s_command.fence_value[l_now_fence_number] = 1;
	}


	//  t@NgÌ¶¬  //  iSæÊ\¦JÚpVXej  // ¸sÅú»ðf
	if (M_Create_Factory() == false)
	{
		return false;
	}


	//  foCXÌ¶¬  //  i¼zA_v^[j  // ¸sÅú»ðf
	if (M_Create_Device() == false)
	{
		return false;
	}


	//  R}hAP[^[Ì¶¬  //  iGPUR}hÌXg[WèÄVXej  // ¸sÅú»ðf
	if (M_Create_Command_Allocator() == false)
	{
		return false;
	}


	//  R}hXgÌ¶¬  //  i`æ½ßÌXgÌJvZj  // ¸sÅú»ðf
	if (M_Create_Command_List() == false)
	{
		return false;
	}


	//  R}hL[Ì¶¬  //  i`æÀsVXej  // ¸sÅú»ðf
	if (M_Create_Command_Queue() == false)
	{
		return false;
	}


	//  tFXÌ¶¬  //  i`æ¯úpVXej  // ¸sÅú»ðf
	if (M_Create_Fence() == false)
	{
		return false;
	}


	//  Xbv`FCÌ¶¬  //  iæÊobt@ØèÖ¦pVXej  // ¸sÅú»ðf
	if (M_Create_Swap_Chain() == false)
	{
		return false;
	}


	//  _[^[Qbgr[Ì¶¬  //  i_OæÌæÊobt@ØèÖ¦pVXej  // ¸sÅú»ðf
	{
		//  Ïé¾  //
		RENDERING::API::DX12::DX12_INSTANCE::C_DX12_Rendering_Screen_System * rendering_screen_system = new RENDERING::API::DX12::DX12_INSTANCE::C_DX12_Rendering_Screen_System();    // Vµ¢_OæÌ_OæÊVXeÌAhX

		RENDERING::API::CREATE::S_Create_Render_Screen_Inform create_screen_inform;    // æÊobt@Ì¶¬pîñ


		// ¶¬·éXN[Ìîñ
		create_screen_inform.m_screen_buffer_sum = 2;	// ¶¬·éXN[obt@
		create_screen_inform.m_rendering_screen_format = RENDERING::INFORM::RENDERING_SCREEN::E_RENDERING_SCREEN_FORMAT::e_2_BYTE;  // f[^ÌoCgtH[}bg
		create_screen_inform.m_screen_texture_setting = RENDERING::API::CREATE::E_SCREEN_TEXTURE_SETTING::e_TEXTURE_2D;        // eNX`Ìdl

		// _OæÌæÊobt@Ì¶¬
		if (M_Create_Render_Target_View_Descriptor_Heap(rendering_screen_system, create_screen_inform) == false)
		{
			return false;
		}


		// _OæÌæÊobt@ÌÝè
		mpr_variable->s_render.main_rendering_screen.reset(rendering_screen_system);
	}


	// æÊðhèÂÔ·FðÝè
	mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_RED] = 0.0f;    // Ô
	mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_GREEN] = 0.8f;  // Î
	mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_BLUE] = 0.8f;   // Â
	mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_ALPHA] = 1.0f;  // ¿

	// _OAPIÍ¶ÝµÄ¢éÌÅI¹µÄ¢étOðº°é
	mpr_variable->flg_rendering_api_end = false;

	// \ÌæÊÌÔðZbg·é
	mpr_variable->s_command.num_front_screen = mpr_variable->s_command.num_back_screen;

	// `ææÌæÊðüè·é( æÊðwè)
	mpr_variable->s_command.num_back_screen = mpr_variable->s_frame_work.swap_chain->GetCurrentBackBufferIndex();

	// ¬÷µ½
	return true;
}


//-- t@NgfoCX --//

//===============//
// Ú×   Ft@Ngð¶¬·é(SæÊ\¦JÚpVXe)
// ø   Fvoid
// ßèl Fbool ¶¬ª¬÷µ½©Ç¤©ðÔ· ¬÷Åtrue
//===============//
bool C_DX12_System::M_Create_Factory(void)
{
	//  Ïé¾   //
	UINT flg_DXGI = 0;  // @\Ýèpîñ


	//  fobOpÝè
#ifdef _DEBUG

	//  Ïé¾  //
	ID3D12Debug * handle_debug_setting = nullptr;   // fobOpÝèÌAhX


	// fobOpîñæ¾
	D3D12GetDebugInterface(IID_PPV_ARGS(&handle_debug_setting));


	// fobOC[ðLø»
	if (handle_debug_setting != nullptr)
	{
		handle_debug_setting->EnableDebugLayer();
		handle_debug_setting->Release();
	}

	// fobOóÔðwè
	flg_DXGI |= DXGI_CREATE_FACTORY_DEBUG;

#endif

	// \¬ÝèpîñÌ¶¬
	if (FAILED(CreateDXGIFactory2(flg_DXGI, IID_PPV_ARGS(mpr_variable->s_frame_work.factory.ReleaseAndGetAddressOf()))))
	{

		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "t@NgÌ¶¬É¸s");
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;   // ¸sµ½çG[Å²¯é
	}

	
	// t@NgÌ¬÷ðm
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "t@NgÌ¶¬É¬÷");

	return true;
}


//===============//
// Ú×   FfoCXð¶¬·é(SæÊ\¦JÚpVXe)
// ø   Fvoid
// ßèl Fbool ¶¬ª¬÷µ½©Ç¤©ðÔ· ¬÷Åtrue
//===============//
bool C_DX12_System::M_Create_Device(void)
{
	//  èé¾  //
	constexpr int con_DX12_FEATURE_LEVEL_SUM = 5;    // »ÝÌdx12Ì@\x


	//  Ïé¾  //
	Microsoft::WRL::ComPtr<IDXGIAdapter> adapter;   // A_v^[ioÍæjîñ

	std::vector<D3D_FEATURE_LEVEL> can_attach_device_level_list_in_dx12;      // dx12ÅgpÂ\È@\xXg


	//  A_v^[ðæ¾  //   // ¸sÈçG[
	if (FAILED(mpr_variable->s_frame_work.factory->EnumAdapters(0, adapter.GetAddressOf())))
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "A_v^[Ìæ¾É¸s");
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}


	//  fobOÈç¬÷ð\¦  //
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "A_v^[Ìæ¾É¬÷");


	//  Ïé¾  //
	HRESULT device_creation_result = E_FAIL; // @\xæ¾ÌÌÊ

	int l_feature_num = 0;  // ¶¬ð·@\Ô


	//  foCX¶¬  //

	// DX12ÅgpÂ\È@\xðwè·éixÌ³Å~ÉÀ×éj
	can_attach_device_level_list_in_dx12.reserve(con_DX12_FEATURE_LEVEL_SUM);
	can_attach_device_level_list_in_dx12.emplace_back(D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_12_2);
	can_attach_device_level_list_in_dx12.emplace_back(D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_12_1);
	can_attach_device_level_list_in_dx12.emplace_back(D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_12_0);
	can_attach_device_level_list_in_dx12.emplace_back(D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_11_1);
	can_attach_device_level_list_in_dx12.emplace_back(D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_11_0);


	// ¶¬Â\Èxð©Â¯éÜÅJèÔ·
	for (l_feature_num = 0; l_feature_num < con_DX12_FEATURE_LEVEL_SUM && FAILED(device_creation_result); l_feature_num++)
	{
		device_creation_result = D3D12CreateDevice(adapter.Get(), can_attach_device_level_list_in_dx12[l_feature_num], IID_PPV_ARGS(&mpr_variable->s_frame_work.device));
	}


	// ÇÌ@\àìêÈ©Á½çG[Å²¯éiwindows7â8ÌêÍ±Ì®ÆÈéÂ\«ª¢j
	if (FAILED(device_creation_result))
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "foCXÌ¶¬É¸s");
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}


	// ¬÷ðOÉ\¦
	l_feature_num -= 1;
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
	(
		DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP,
		DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED,
		"foCXÌ¶¬É¬÷[íÊF" + M_Convert_D3D_FEATURE_LEVEL_Enum_To_String(can_attach_device_level_list_in_dx12[l_feature_num]));

	return true;
}


//-- R}h --//

//===============//
// Ú×   FR}hAP[^[ð¶¬·éiGPUR}hÌXg[WèÄVXej
// ø   Fvoid
// ßèl Fbool ¶¬ª¬÷µ½©Ç¤©ðÔ· ¬÷Åtrue
//===============//
bool C_DX12_System::M_Create_Command_Allocator(void)
{
	//  R}hAP[^ð¶¬  //  // ¸sÈçG[
	if (FAILED(mpr_variable->s_frame_work.device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE::D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(mpr_variable->s_command.allocator.GetAddressOf()))))
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "R}hAP[^Ì¶¬É¸s");
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;   // ¸sµ½çG[Å²¯é
	}


	// R}hAP[^Ì¶¬Ì¬÷ðm
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "R}hAP[^Ì¶¬É¬÷");


	// R}hAP[^Ìðú»
	mpr_variable->s_command.allocator->Reset();

	return true;
}


//===============//
// Ú×   FR}hXgð¶¬·éi`æ½ßÌXgÌJvZj
// ø   Fvoid
// ßèl Fbool ¶¬ª¬÷µ½©Ç¤©ðÔ· ¬÷Åtrue
//===============//
bool C_DX12_System::M_Create_Command_List(void)
{
	//  R}hXgÌ¶¬  //    // ¸sÈçG[
	if (FAILED(mpr_variable->s_frame_work.device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE::D3D12_COMMAND_LIST_TYPE_DIRECT, mpr_variable->s_command.allocator.Get(), nullptr, IID_PPV_ARGS(mpr_variable->s_command.list.GetAddressOf()))))
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "R}hXgÌ¶¬É¸s");
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;   // ¸sµ½çG[Å²¯é
	}


	// R}hXgÌ¶¬Ì¬÷ðm
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "R}hXgÌ¶¬É¬÷");

	// R}hXgðúóÔÉZbg
	mpr_variable->s_command.list->Close();

	return true;
}


//===============//
// Ú×   FR}hL[ð¶¬·éi`æÀsVXej
// ø   Fvoid
// ßèl Fbool ¶¬ª¬÷µ½©Ç¤©ðÔ· ¬÷Åtrue
//===============//
bool C_DX12_System::M_Create_Command_Queue(void)
{
	//  Ïé¾  //
	D3D12_COMMAND_QUEUE_DESC desc_command_queue;    // R}hL[¶¬pîñ


	// ú»
	ZeroMemory(&desc_command_queue, sizeof(desc_command_queue));

	// R}h«Ýû@ðwè
	desc_command_queue.Type = D3D12_COMMAND_LIST_TYPE::D3D12_COMMAND_LIST_TYPE_DIRECT;

	// DæxÝè
	desc_command_queue.Priority = 0;

	// GPU^CAEgÝè
	desc_command_queue.Flags = D3D12_COMMAND_QUEUE_FLAGS::D3D12_COMMAND_QUEUE_FLAG_NONE;

	// R}hL[ÉK·ém[h(GPUâ¨A_v^[)Ì
	desc_command_queue.NodeMask = 0;


	//  R}hL[ð¶¬  //         // ¸sÈçG[
	if (FAILED(mpr_variable->s_frame_work.device->CreateCommandQueue(&desc_command_queue, IID_PPV_ARGS(mpr_variable->s_command.queue.GetAddressOf()))))
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "R}hL[Ì¶¬É¸s");
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}


	// R}hL[Ì¶¬Ì¬÷ðm
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "R}hL[Ì¶¬É¬÷");

	return true;
}


//-- tFXXbv`FC --//

//===============//
// Ú×   FtFXð¶¬·éi`æ¯úpVXej
// ø   Fvoid
// ßèl Fbool ¶¬ª¬÷µ½©Ç¤©ðÔ· ¬÷Åtrue
//===============//
bool C_DX12_System::M_Create_Fence(void)
{
	// R}hL[pÌtFXðõ
	mpr_variable->s_render.fence_event = CreateEvent(NULL, FALSE, FALSE, NULL);


	//  tFXð¶¬  //   // ¸sÈçG[
	if (FAILED(mpr_variable->s_frame_work.device->CreateFence(0, D3D12_FENCE_FLAGS::D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(mpr_variable->s_render.queue_fence.GetAddressOf()))))
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "tFXÌ¶¬É¸s");
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}


	// tFXÌ¶¬Ì¬÷ðm
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "tFXÌ¶¬É¬÷");

	return true;
}


//===============//
// Ú×   FXbv`FCð¶¬·éiæÊobt@ØèÖ¦pVXej
// ø   Fvoid
// ßèl Fbool ¶¬ª¬÷µ½©Ç¤©ðÔ· ¬÷Åtrue
//===============//
bool C_DX12_System::M_Create_Swap_Chain(void)
{
	//  Ïé¾   //
	DXGI_SWAP_CHAIN_DESC desc_swap_chain;   // Xbv`FCÝèpîñ


	// ú»
	ZeroMemory(&desc_swap_chain, sizeof(desc_swap_chain));

	// obNobt@ÌtH[}bg
	desc_swap_chain.BufferDesc.Format = DXGI_FORMAT::DXGI_FORMAT_R16G16B16A16_FLOAT;

	// TvOpobt@
	desc_swap_chain.SampleDesc.Count = 1;

	// æÊÌCPUANZXû@Ýè
	desc_swap_chain.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

	// æÊ
	desc_swap_chain.BufferCount = (int)E_DX12_PARAMATOR::e_RENDER_TARGET_BUFFER_SUM;

	// EBhEÖÌnh
	desc_swap_chain.OutputWindow = reinterpret_cast<HWND>(OS::C_OS_User_System::M_Get_Window_Handle_Or_Identify());
	
	// EBhE[hÅ é©Ç¤©
	desc_swap_chain.Windowed = TRUE;

	// \¦ØÖãIvV
	desc_swap_chain.SwapEffect = DXGI_SWAP_EFFECT::DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;

	// Xbv`FC®ìIvV
	desc_swap_chain.Flags = DXGI_SWAP_CHAIN_FLAG::DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;


	//  Xbv`FCð¶¬  //      // ¸sÈçG[
	if (FAILED(mpr_variable->s_frame_work.factory->CreateSwapChain(mpr_variable->s_command.queue.Get(), &desc_swap_chain, (IDXGISwapChain**)mpr_variable->s_frame_work.swap_chain.GetAddressOf())))
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "Xbv`FCÌ¶¬É¸s");
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}


	//  fobOÈç¬÷ð\¦  //
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "Xbv`FCÌ¶¬É¬÷");

	return true;
}


//-- _O --//

//===============//
// Ú×   F_[^[Qbgr[ð¶¬·éi_OæÌæÊobt@ØèÖ¦pVXej
// ø   FC_DX12_Rendering_Screen_System * & DX12pÌÝèæÌ_OæÊÌQÆ, const S_Create_Render_Screen_Inform & _OæÊð¶¬·é½ßÌîñÌQÆiconstj
// ßèl Fbool ¶¬ª¬÷µ½©Ç¤©ðÔ· ¬÷Åtrue
//===============//
bool C_DX12_System::M_Create_Render_Target_View_Descriptor_Heap(RENDERING::API::DX12::DX12_INSTANCE::C_DX12_Rendering_Screen_System * & in_dx12_screen_system, const RENDERING::API::CREATE::S_Create_Render_Screen_Inform & in_create_rendering_screen_inform) const
{
	//  Ïé¾  //
	D3D12_DESCRIPTOR_HEAP_DESC desc_descriptor_heap;   // fXNv^q[vÝèpîñ

	DXGI_FORMAT set_pixel_format = DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_FLOAT;   // æfÌtH[}bg

	D3D12_RTV_DIMENSION render_target_view_texture = D3D12_RTV_DIMENSION::D3D12_RTV_DIMENSION_TEXTURE2D;   // eNX`Ìgpû@


	// wè³ê½æfÌ^Éí¹Ä_OæfÌ^ðÝè·é
	switch (in_create_rendering_screen_inform.m_rendering_screen_format)
	{
		// RGBASÄQoCgÃÂ
	case RENDERING::INFORM::RENDERING_SCREEN::E_RENDERING_SCREEN_FORMAT::e_2_BYTE:
	default:
		set_pixel_format = DXGI_FORMAT::DXGI_FORMAT_R16G16B16A16_FLOAT;
		break;
	}

	// _[^[Qbgr[ÌíÞðwè
	switch (in_create_rendering_screen_inform.m_screen_texture_setting)
	{
		// eNX`obt@Ìgp
	case RENDERING::API::CREATE::E_SCREEN_TEXTURE_SETTING::e_BUFFER:
		render_target_view_texture = D3D12_RTV_DIMENSION::D3D12_RTV_DIMENSION_BUFFER;
		break;

		// 1DeNX`ÆµÄgp
	case RENDERING::API::CREATE::E_SCREEN_TEXTURE_SETTING::e_TEXTURE_1D:
		render_target_view_texture = D3D12_RTV_DIMENSION::D3D12_RTV_DIMENSION_TEXTURE1D;
		break;

		// 2DeNX`ÆµÄgp
	case RENDERING::API::CREATE::E_SCREEN_TEXTURE_SETTING::e_TEXTURE_2D:
		render_target_view_texture = D3D12_RTV_DIMENSION::D3D12_RTV_DIMENSION_TEXTURE2D;
		break;

		// 3DeNX`ÆµÄgp
	case RENDERING::API::CREATE::E_SCREEN_TEXTURE_SETTING::e_TEXTURE_3D:
		render_target_view_texture = D3D12_RTV_DIMENSION::D3D12_RTV_DIMENSION_TEXTURE3D;
		break;
	}


	// ú»
	ZeroMemory(&desc_descriptor_heap, sizeof(desc_descriptor_heap));

	// q[vàÌfXNv^ÌíÞ
	desc_descriptor_heap.Type = D3D12_DESCRIPTOR_HEAP_TYPE::D3D12_DESCRIPTOR_HEAP_TYPE_RTV;

	// fXNv^Ì
	desc_descriptor_heap.NumDescriptors = in_create_rendering_screen_inform.m_screen_buffer_sum;

	// q[vIvV
	desc_descriptor_heap.Flags = D3D12_DESCRIPTOR_HEAP_FLAGS::D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

	// fXNv^ÉK·ém[h(GPUâ¨A_v^[)Ì
	desc_descriptor_heap.NodeMask = 0;


	//  _[^[Qbgq[vÌ¶¬  //     // ¸sÈçG[
	if (FAILED(mpr_variable->s_frame_work.device->CreateDescriptorHeap(&desc_descriptor_heap, IID_PPV_ARGS(in_dx12_screen_system->m_render_target_view.heap.GetAddressOf()))))
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "_[^[Qbgq[v¶¬É¸s");
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;   // ¸sµ½çG[Å²¯é
	}


	// _[^[Qbgq[vÌ¶¬Ì¬÷ðm
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "_[^[Qbgq[vÌ¶¬É¬÷");


	//  Ïé¾  //
	UINT byte_of_handle = mpr_variable->s_frame_work.device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV); // nhêÂªÉÎ·éoCg(AhX§äp)


	// SÄÌobt@É_[^[QbgðÝè
	in_dx12_screen_system->m_render_target_view.buffer_list.resize(in_create_rendering_screen_inform.m_screen_buffer_sum);
	for (UINT loop_x = 0; loop_x < (UINT)in_create_rendering_screen_inform.m_screen_buffer_sum; loop_x++)
	{
		// æÊÌobt@É_[^[Qbgðwè
		if (FAILED(mpr_variable->s_frame_work.swap_chain->GetBuffer(loop_x, IID_PPV_ARGS(in_dx12_screen_system->m_render_target_view.buffer_list[loop_x].render_buffer.GetAddressOf()))))
		{
			DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, ((std::string)"Buffer_Count:" + std::to_string(loop_x) + "-" + "_[^[QbgÌæ¾É¸s").c_str());
			DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

			return false;   // ¸sµ½çG[Å²¯é
		}


		// _[^[QbgÌæ¾Ì¬÷ðm
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, ((std::string)"_[^[QbgÌæ¾É¬÷" + "-buffer_count:" + std::to_string(loop_x)).c_str());


		//  Ïé¾  //
		D3D12_RENDER_TARGET_VIEW_DESC rtv_desc = D3D12_RENDER_TARGET_VIEW_DESC(); // _[^[Qbgr[¶¬pÌîñ


		// æfÌtH[}bgðÝè
		rtv_desc.Format = set_pixel_format;

		// _OæÌgpû@ðÝè
		rtv_desc.ViewDimension = render_target_view_texture;
		
		// ~bv}bvÌÝè
		rtv_desc.Texture2D.MipSlice = 0;
		rtv_desc.Texture2D.PlaneSlice = 0;

		// êÔÚÌfXNv^ÌAhXðwè
		in_dx12_screen_system->m_render_target_view.buffer_list[loop_x].handle = in_dx12_screen_system->m_render_target_view.heap->GetCPUDescriptorHandleForHeapStart();

		// ¡ÌfXNv^ÜÅ¸ç·
		in_dx12_screen_system->m_render_target_view.buffer_list[loop_x].handle.ptr += (SIZE_T)loop_x * (SIZE_T)byte_of_handle;

		// _[^[Qbgr[¶¬
		mpr_variable->s_frame_work.device->CreateRenderTargetView(in_dx12_screen_system->m_render_target_view.buffer_list[loop_x].render_buffer.Get(), &rtv_desc, in_dx12_screen_system->m_render_target_view.buffer_list[loop_x].handle);
	}


	// æÊðÝè
	in_dx12_screen_system->m_rendering_screen_sum = in_create_rendering_screen_inform.m_screen_buffer_sum;


	// _OæÊÌ¶¬Ì¬÷ðm
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "_OæÊÌ¶¬É¬÷");

	// ¶¬É¬÷µ½
	return true;
}


//===============//
// Ú×   F _OæÊðNA·é
// ø   FS_DX12_Render_Target_View & _[^[Qbgr[îñÌQÆ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Clear_Render_Target_View(int in_rendering_screen_number, RENDERING::API::DX12::DX12_INSTANCE::S_DX12_Render_Target_View & in_render_target_view) const
{
	// æÊÌ\[Xð_[^[QbgÉÝè
	M_Set_Resource_Barrier(in_rendering_screen_number, in_render_target_view, D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_RENDER_TARGET);

	// _[^[QbgÌæÊîñNA
	mpr_variable->s_command.list->ClearRenderTargetView(in_render_target_view.buffer_list[in_rendering_screen_number].handle, mpr_variable->s_frame_work.clear_color, 0, nullptr);

	return;
}


//===============//
// Ú×   FæÊÌÔÉæÁÄ_OæÊðZbg·é
// ø   Fint _OæÌÔ, S_DX12_Render_Target_View & _[^[Qbgr[îñÌQÆ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Set_Render_Target_View_By_Screen_Number(int in_rendering_screen_number, RENDERING::API::DX12::DX12_INSTANCE::S_DX12_Render_Target_View & in_render_target_view)
{
	// _OæÉ\[XoAðÝè
	M_Set_Resource_Barrier(in_rendering_screen_number, in_render_target_view, D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_RENDER_TARGET);

	// r[ÌoCh
	mpr_variable->s_command.list->OMSetRenderTargets(1, &in_render_target_view.buffer_list[in_rendering_screen_number].handle, TRUE, mpr_variable->s_render.now_depth_stencil_address_handle);
	mpr_variable->s_render.now_screen_address_handle = &in_render_target_view.buffer_list[in_rendering_screen_number].handle;
	mpr_variable->s_render.now_rendering_screen_sum = 1;

	return;
}


//===============//
// Ú×   F_OæÊðZbg·é
// ø   FC_DX12_Rendering_Screen_System * & _[^[Qbgr[îñÌQÆ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Set_Render_Target_View(RENDERING::API::DX12::DX12_INSTANCE::C_DX12_Rendering_Screen_System * & in_render_target_view)
{
	// _OæÉ\[XoAðÝè
	for (int l_now_screen_number = 0; l_now_screen_number < in_render_target_view->m_rendering_screen_sum; l_now_screen_number++)
	{
		M_Set_Resource_Barrier(l_now_screen_number, in_render_target_view->m_render_target_view, D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_RENDER_TARGET);
	}

	// r[ÌoCh
	mpr_variable->s_command.list->OMSetRenderTargets(in_render_target_view->m_rendering_screen_sum, &in_render_target_view->m_render_target_view.buffer_list[0].handle, TRUE, mpr_variable->s_render.now_depth_stencil_address_handle);
	mpr_variable->s_render.now_screen_address_handle = &in_render_target_view->m_render_target_view.buffer_list[0].handle;
	mpr_variable->s_render.now_rendering_screen_sum = in_render_target_view->m_rendering_screen_sum;

	return;
}


//-- [xXeVr[ --//

//===============//
// Ú×   F[xXeVr[ð¶¬·éi[xXeVKpæÌæÊobt@ÌØèÖ¦pVXej
// ø   FC_DX12_Depth_Stencil_Buffer_System * & DX12pÌ[xXeVobt@ÌAhXÌQÆ, const S_Create_Depth_Stencil_Buffer_Inform & [xXeVobt@ð¶¬·é½ßÌîñ
// ßèl Fbool ¶¬ª¬÷µ½©Ç¤©ðÔ· ¬÷Åtrue
//===============//
bool C_DX12_System::M_Create_Depth_Stencil_View_Descriptor_Heap(RENDERING::API::DX12::DX12_INSTANCE::C_DX12_Depth_Stencil_Buffer_System * & in_dx12_depth_stencil_buffer, const RENDERING::API::CREATE::S_Create_Depth_Stencil_Buffer_Inform & in_create_inform) const
{
	//  Ïé¾  //
	DXGI_FORMAT set_format = DXGI_FORMAT::DXGI_FORMAT_D32_FLOAT;   // [xXeVobt@ÌsNZÌoCg^ÌtH[}bg


	// oCg^ÌtH[}bgðÝè
	switch (in_create_inform.m_byte_format)
	{
		// QoCg
	case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_BYTE_FORMAT::e_2_BYTE:
			set_format = DXGI_FORMAT::DXGI_FORMAT_D16_UNORM;
			break;

		// SoCg
	case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_BYTE_FORMAT::e_4_BYTE:
		default:
			set_format = DXGI_FORMAT::DXGI_FORMAT_D32_FLOAT;
			break;
	}


	//  [xXeVq[v  //    //iÇpØ\¢j
	{
		//  Ïé¾  //
		D3D12_DESCRIPTOR_HEAP_DESC desc_descriptor_heap;   // fXNv^q[vÝèpîñ


		// ú»
		ZeroMemory(&desc_descriptor_heap, sizeof(desc_descriptor_heap));

		// q[vàÌfXNv^ÌíÞ
		desc_descriptor_heap.Type = D3D12_DESCRIPTOR_HEAP_TYPE::D3D12_DESCRIPTOR_HEAP_TYPE_DSV;

		// fXNv^Ì
		desc_descriptor_heap.NumDescriptors = 1;

		// q[vIvV
		desc_descriptor_heap.Flags = D3D12_DESCRIPTOR_HEAP_FLAGS::D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

		// fXNv^ÉK·ém[h(GPUâ¨A_v^[)Ì
		desc_descriptor_heap.NodeMask = 0;


		//  [xXeVq[vÌ¶¬  //     // ¸sÈçG[
		if (FAILED(mpr_variable->s_frame_work.device->CreateDescriptorHeap(&desc_descriptor_heap, IID_PPV_ARGS(in_dx12_depth_stencil_buffer->m_data.heap.GetAddressOf()))))
		{
			DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "[xXeVq[vÌ¶¬É¸s");
			DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

			return false;
		}
	}


	// [xXeVq[vÌ¶¬Ì¬÷ðm
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "[xXeVq[vÌ¶¬É¬÷");


	//  [xXeVobt@pq[v  //
	{
		//  Ïé¾  //
		D3D12_HEAP_PROPERTIES heap_propertie;   // q[vÌÝè

		D3D12_RESOURCE_DESC desc_resource;    // \[XÝè

		D3D12_CLEAR_VALUE clear_setting = {};   // [xXeVobt@NAÌp[^


		//  q[vÌÝè  //

		// ú»
		ZeroMemory(&heap_propertie, sizeof(heap_propertie));

		// q[vÌ®ìÌíÞ
		heap_propertie.Type = D3D12_HEAP_TYPE::D3D12_HEAP_TYPE_DEFAULT;

		// CPUÌªy[WOÉæÁÄ¡ÌÆµÄµíêÄ¢éÉÇÌæ¤É»ÌÉANZX·é©
		heap_propertie.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY::D3D12_CPU_PAGE_PROPERTY_UNKNOWN;

		// v[(N®ÉêCÉAvÅgp·éf[^ðmÛ·éê)ÌíÞðwè·é
		heap_propertie.MemoryPoolPreference = D3D12_MEMORY_POOL::D3D12_MEMORY_POOL_UNKNOWN;

		// q[vð¶¬·ém[h(GPUâ¨A_v^[)Ì
		heap_propertie.CreationNodeMask = 1;

		// \[Xª¶Ý·ém[hÌ(GPUâ¨A_v^[)Ì
		heap_propertie.VisibleNodeMask = heap_propertie.CreationNodeMask;


		//  \[XÌÝè  //

		// ú»
		ZeroMemory(&desc_resource, sizeof(desc_resource));

		// gp³êé\[XÌíÞ
		desc_resource.Dimension = D3D12_RESOURCE_DIMENSION::D3D12_RESOURCE_DIMENSION_TEXTURE2D;

		// Ýè·é\[XîñÌzuÔ
		desc_resource.Alignment = 0;

		// \[XÌ¡sNZ
		desc_resource.Width = (int)RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE::e_WIDTH_SIZE;

		// \[XÌcsNZ
		desc_resource.Height = (int)RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE::e_HEIGHT_SIZE;

		// \[XÌ[³AÜ½Ízñ
		desc_resource.DepthOrArraySize = 1;

		// MIPMAPx(±ÌlÉ¶ÄsNZª{ÉÈé)
		desc_resource.MipLevels = 0;

		// \[XªDX12¤ªpÓµ½^©Ç¤©
		desc_resource.Format = set_format;


		//  TvOÝè  //

		// TvOñ
		desc_resource.SampleDesc.Count = 1;

		// TvOÌNIeB
		desc_resource.SampleDesc.Quality = 0;


		// eNX`CAEgÌIvV
		desc_resource.Layout = D3D12_TEXTURE_LAYOUT::D3D12_TEXTURE_LAYOUT_UNKNOWN;

		// \[Xðì·é½ßÌIvV
		desc_resource.Flags = D3D12_RESOURCE_FLAGS::D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL | D3D12_RESOURCE_FLAGS::D3D12_RESOURCE_FLAG_DENY_SHADER_RESOURCE;



		//  [xXeVobt@NAÝè  //

		// NApÌÏÌf[^`®
		clear_setting.Format = set_format;

		// ú»p[xl
		clear_setting.DepthStencil.Depth = 1.0f;

		// ú»pXeVl
		clear_setting.DepthStencil.Stencil = 0;


		//  [xXeVobt@¶¬  //
		if (FAILED(mpr_variable->s_frame_work.device->CreateCommittedResource(&heap_propertie, D3D12_HEAP_FLAG_NONE, &desc_resource, D3D12_RESOURCE_STATE_DEPTH_WRITE, &clear_setting, IID_PPV_ARGS(&in_dx12_depth_stencil_buffer->m_data.depth_stencil_buffer))))
		{
			DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "[xXeVobt@Ì¶¬É¸s");
			DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

			return false;
		}
	}


	// [xXeVobt@Ì¶¬Ì¬÷ðm
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "[xXeVobt@Ì¶¬É¬÷");


	//  [xXeVr[  //
	{
		//  Ïé¾  //
		D3D12_DEPTH_STENCIL_VIEW_DESC dsv_desc = {};    //[xXeVr[Ýèpîñ


		// [xXeVobt@Ìf[^`®
		dsv_desc.Format = set_format;

		// [xXeVobt@Ì¡@ieNX``®j
		dsv_desc.ViewDimension = D3D12_DSV_DIMENSION::D3D12_DSV_DIMENSION_TEXTURE2D;

		// eNX`Ìgpû@
		dsv_desc.Flags = D3D12_DSV_FLAGS::D3D12_DSV_FLAG_NONE;


		// AhXÌæ¾
		in_dx12_depth_stencil_buffer->m_data.handle = in_dx12_depth_stencil_buffer->m_data.heap->GetCPUDescriptorHandleForHeapStart();

		//[xXeVr[¶¬
		mpr_variable->s_frame_work.device->CreateDepthStencilView(in_dx12_depth_stencil_buffer->m_data.depth_stencil_buffer.Get(), &dsv_desc, in_dx12_depth_stencil_buffer->m_data.handle);
	}

	return true;
}


//===============//
// Ú×   F[xXeVobt@ðZbg·é
// ø   FS_DX12_Depth_Stencil_Buffer & [xXeVobt@îñÌQÆ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Set_Depth_Stencil_View(RENDERING::API::DX12::DX12_INSTANCE::S_DX12_Depth_Stencil_Buffer & in_depth_stencil_buffer)
{
	mpr_variable->s_command.list->OMSetRenderTargets(mpr_variable->s_render.now_rendering_screen_sum, mpr_variable->s_render.now_screen_address_handle, TRUE, &in_depth_stencil_buffer.handle);
	mpr_variable->s_render.now_depth_stencil_address_handle = &in_depth_stencil_buffer.handle;

	return;
}


//===============//
// Ú×   F[xXeVobt@ðZbg·é
// ø   FS_DX12_Depth_Stencil_Buffer & [xXeVobt@îñÌQÆ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Clear_Depth_Stencil_View_Buffer(RENDERING::API::DX12::DX12_INSTANCE::S_DX12_Depth_Stencil_Buffer & in_depth_stencil_buffer) const
{
	// [xXeVÌú»
	mpr_variable->s_command.list->ClearDepthStencilView(in_depth_stencil_buffer.handle, D3D12_CLEAR_FLAGS::D3D12_CLEAR_FLAG_DEPTH, 1.0f, 0, 0, nullptr);
	mpr_variable->s_command.list->ClearDepthStencilView(in_depth_stencil_buffer.handle, D3D12_CLEAR_FLAGS::D3D12_CLEAR_FLAG_STENCIL, 1.0f, 0, 0, nullptr);

	return;
}


//-- ¸_obt@ --//

//===============//
// Ú×   F¸_obt@ð¶¬·é
// ø   FC_DX12_Vertex_Setting_Inform * & ZbgæÌ¸_f[^, const C_Create_Vertex_Buffer_Inform & ¸_f[^¶¬pîñ(const)
// ßèl Fvoid
//===============//
void C_DX12_System::M_Create_Vertex_Buffer(DX12_INSTANCE::C_DX12_Vertex_Setting_Inform * & in_dx12_vertex_inform, const CREATE::S_Create_Vertex_Buffer_Inform & in_create_inform) const
{
	//  Ïé¾  //
	D3D12_HEAP_PROPERTIES heap_properties;   // q[vÌÝè

	D3D12_RESOURCE_DESC desc_resource;    // \[XÝè


	//  q[vÌÝè  //

	// ú»
	ZeroMemory(&heap_properties, sizeof(heap_properties));

	// q[vÌ®ìÌíÞ
	heap_properties.Type = D3D12_HEAP_TYPE::D3D12_HEAP_TYPE_UPLOAD;

	// CPUÌªy[WOÉæÁÄ¡ÌÆµÄµíêÄ¢éÉÇÌæ¤É»ÌÉANZX·é©
	heap_properties.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY::D3D12_CPU_PAGE_PROPERTY_UNKNOWN;

	// v[(N®ÉêCÉAvÅgp·éf[^ðmÛ·éê)ÌíÞðwè·é
	heap_properties.MemoryPoolPreference = D3D12_MEMORY_POOL::D3D12_MEMORY_POOL_UNKNOWN;

	// q[vð¶¬·ém[h(GPUâ¨A_v^[)Ì
	heap_properties.CreationNodeMask = 0;

	// \[Xª¶Ý·ém[hÌ(GPUâ¨A_v^[)Ì
	heap_properties.VisibleNodeMask = heap_properties.CreationNodeMask;


	//  \[XÌÝè  //

	// ú»
	ZeroMemory(&desc_resource, sizeof(desc_resource));

	// gp³êé\[XÌíÞ
	desc_resource.Dimension = D3D12_RESOURCE_DIMENSION::D3D12_RESOURCE_DIMENSION_BUFFER;
	
	// Ýè·é\[XîñÌzuÔ
	desc_resource.Alignment = 0;

	// \[XÌoCg
	desc_resource.Width = (UINT64)(in_create_inform.size_of_vertex * in_create_inform.vertex_sum);

	// \[XÌzñÔ
	desc_resource.Height = 1;

	// \[XÌ[³AÜ½Ízñ
	desc_resource.DepthOrArraySize = 1;

	// MIPMAPx(±ÌlÉ¶ÄsNZª{ÉÈé)
	desc_resource.MipLevels = 1;

	// \[XªDX12¤ªpÓµ½^©Ç¤©
	desc_resource.Format = DXGI_FORMAT::DXGI_FORMAT_UNKNOWN;


	//  TvOÝè  //

	// TvOñ
	desc_resource.SampleDesc.Count = 1;

	// TvOÌNIeB
	desc_resource.SampleDesc.Quality = 0;


	// eNX`CAEgÌIvV
	desc_resource.Layout = D3D12_TEXTURE_LAYOUT::D3D12_TEXTURE_LAYOUT_ROW_MAJOR;

	// \[Xðì·é½ßÌIvV
	desc_resource.Flags = D3D12_RESOURCE_FLAGS::D3D12_RESOURCE_FLAG_NONE;


	// ¸_obt@ÌAhXÝèð¶¬(¸sÅG[ðoµÄ²¯é)
	if (FAILED(mpr_variable->s_frame_work.device->CreateCommittedResource
	(
		&heap_properties,
		D3D12_HEAP_FLAGS::D3D12_HEAP_FLAG_NONE,
		&desc_resource,
		D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(in_dx12_vertex_inform->m_vertex_buffer_data.GetAddressOf())))
		|| in_dx12_vertex_inform->m_vertex_buffer_data == nullptr
	)
	{
		return;
	}


	//  ¸_obt@Ýè  //

	// obt@ÌÀW
	in_dx12_vertex_inform->m_vertex_buffer_view.BufferLocation = in_dx12_vertex_inform->m_vertex_buffer_data->GetGPUVirtualAddress();

	// ¸_obt@ÌoCg
	in_dx12_vertex_inform->m_vertex_buffer_view.SizeInBytes = in_create_inform.size_of_vertex * in_create_inform.vertex_sum;

	// vfÌoCg
	in_dx12_vertex_inform->m_vertex_buffer_view.StrideInBytes = in_create_inform.size_of_vertex;


	// ¶¬µ½obt@ð[NA·é
	M_Buffer_Zero_Clear_System<ID3D12Resource>(in_dx12_vertex_inform->m_vertex_buffer_data.Get(), (int)desc_resource.Width);

	return;
}


//-- ¸_CfbNX --//

//===============//
// Ú×   F¸_CfbNXobt@ð¶¬·é
// ø   FC_DX12_Index_Setting_Inform * & ZbgæÌ¸_CfbNXf[^, const S_Create_Index_Buffer_Inform & ¸_CfbNXf[^¶¬pîñ(const)
// ßèl Fvoid
//===============//
void C_DX12_System::M_Create_Index_Buffer(DX12_INSTANCE::C_DX12_Index_Setting_Inform * & in_dx12_index_inform, const CREATE::S_Create_Index_Buffer_Inform & in_create_inform) const
{
	//  Ïé¾  //
	D3D12_HEAP_PROPERTIES heap_propertie;   // q[vÌÝè

	D3D12_RESOURCE_DESC desc_resource;    // \[XÝè

	int byte_size = in_create_inform.index_sum * sizeof(uint32_t);  // oCg


	//  q[vÌÝè  //

	// ú»
	ZeroMemory(&heap_propertie, sizeof(heap_propertie));

	// q[vÌ®ìÌíÞ
	heap_propertie.Type = D3D12_HEAP_TYPE::D3D12_HEAP_TYPE_UPLOAD;

	// CPUÌªy[WOÉæÁÄ¡ÌÆµÄµíêÄ¢éÉÇÌæ¤É»ÌÉANZX·é©
	heap_propertie.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY::D3D12_CPU_PAGE_PROPERTY_UNKNOWN;

	// v[(N®ÉêCÉAvÅgp·éf[^ðmÛ·éê)ÌíÞðwè·é
	heap_propertie.MemoryPoolPreference = D3D12_MEMORY_POOL::D3D12_MEMORY_POOL_UNKNOWN;

	// q[vð¶¬·ém[h(GPUâ¨A_v^[)Ì
	heap_propertie.CreationNodeMask = 0;

	// \[Xª¶Ý·ém[hÌ(GPUâ¨A_v^[)Ì
	heap_propertie.VisibleNodeMask = heap_propertie.CreationNodeMask;


	//  \[XÌÝè  //

	// ú»
	ZeroMemory(&desc_resource, sizeof(desc_resource));

	// gp³êé\[XÌíÞ
	desc_resource.Dimension = D3D12_RESOURCE_DIMENSION::D3D12_RESOURCE_DIMENSION_BUFFER;

	// Ýè·é\[XîñÌzñ
	desc_resource.Alignment = 0;

	// \[XÌoCg
	desc_resource.Width = byte_size;

	// \[XÌzñÔ
	desc_resource.Height = 1;

	// \[XÌ[³AÜ½Ízñ
	desc_resource.DepthOrArraySize = 1;

	// MIPMAPx(±ÌlÉ¶ÄsNZª{ÉÈé)
	desc_resource.MipLevels = 1;

	// \[XªDX12¤ªpÓµ½^©Ç¤©
	desc_resource.Format = DXGI_FORMAT::DXGI_FORMAT_R32_UINT;


	//  TvOÝè  //

	// TvOñ
	desc_resource.SampleDesc.Count = 1;

	// TvOÌNIeB
	desc_resource.SampleDesc.Quality = 0;


	// eNX`CAEgÌIvV
	desc_resource.Layout = D3D12_TEXTURE_LAYOUT::D3D12_TEXTURE_LAYOUT_ROW_MAJOR;

	// \[Xðì·é½ßÌIvV
	desc_resource.Flags = D3D12_RESOURCE_FLAGS::D3D12_RESOURCE_FLAG_NONE;


	// ¸_obt@ÌAhXÝèð¶¬(¸sÅG[ðoµÄ²¯é)
	if (FAILED(mpr_variable->s_frame_work.device->CreateCommittedResource
	(
		&heap_propertie,
		D3D12_HEAP_FLAGS::D3D12_HEAP_FLAG_NONE,
		&desc_resource,
		D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(in_dx12_index_inform->m_index_buffer_data.GetAddressOf())))
		|| in_dx12_index_inform->m_index_buffer_data == nullptr
	)
	{
		return;
	}


	// GPUÅÌAhXðüè
	in_dx12_index_inform->m_index_buffer_view.BufferLocation = in_dx12_index_inform->m_index_buffer_data->GetGPUVirtualAddress();

	// CfbNXobt@ÌoCg
	in_dx12_index_inform->m_index_buffer_view.SizeInBytes = byte_size;

	// CfbNXobt@Ìf[^`®
	in_dx12_index_inform->m_index_buffer_view.Format = DXGI_FORMAT::DXGI_FORMAT_R32_UINT;


	// ¶¬µ½obt@ð[NA·é
	M_Buffer_Zero_Clear_System<ID3D12Resource>(in_dx12_index_inform->m_index_buffer_data.Get(), (int)desc_resource.Width);

	return;
}


//-- èobt@ --//

//===============//
// Ú×   Fèobt@Ìq[vð¶¬·é
// ø   FC_DX12_Constant_Setting_Inform * & ÝèæÌèpÌf[^, const C_Create_Constant_Buffer_Inform & èpf[^¶¬pîñ(const)
// ßèl Fvoid
//===============//
void C_DX12_System::M_Create_Constant_Heap(DX12_INSTANCE::C_DX12_Constant_Setting_Inform * & in_dx12_constant_setting, const CREATE::S_Create_Constant_Buffer_Inform & in_create_inform) const
{
	//  Ïé¾  //
	D3D12_DESCRIPTOR_HEAP_DESC descriptor_heap_desc{};  // èobt@pÌq[vÌ¶¬pîñ


	// q[vÅÇ·éf[^ÌÇ
	descriptor_heap_desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE::D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;

	// f[^
	descriptor_heap_desc.NumDescriptors = in_create_inform.m_list_size;

	// VF[_[©çÒWÅ«é©Ç¤©
	descriptor_heap_desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAGS::D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

	// A_v^[Ìm[h
	descriptor_heap_desc.NodeMask = 0;


	// èobt@q[vÌ¶¬
	if (FAILED(mpr_variable->s_frame_work.device->CreateDescriptorHeap(&descriptor_heap_desc, IID_PPV_ARGS(&in_dx12_constant_setting->m_constant_buffer_heap))))
	{
		return;
	}

	return;
}


//===============//
// Ú×   Fèobt@Ìf[^ð¶¬·é
// ø   FC_DX12_Constant_Setting_Inform * & ÝèæÌèpÌf[^, const C_Create_Constant_Buffer_Inform & èpf[^¶¬pîñ(const)
// ßèl Fvoid
//===============//
void C_DX12_System::M_Create_Constant_Resource(DX12_INSTANCE::C_DX12_Constant_Setting_Inform * & in_dx12_constant_setting, const CREATE::S_Create_Constant_Buffer_Inform & in_create_inform) const
{
	//  è  //
	constexpr int con_CONSTANT_BUFFER_ONE_BYTE = 256;	// èobt@êÂªÌoCg


	//  èobt@f[^ð¶¬  //

		//  Ïé¾  //
	D3D12_HEAP_PROPERTIES constant_data_prop = D3D12_HEAP_PROPERTIES();   // èf[^¶¬pÌvpeBÝè

	D3D12_RESOURCE_DESC constant_data_desc = D3D12_RESOURCE_DESC();     // èobt@Ìf[^ÌÝè


	//  vpeBÝè  //

	// q[vÌ®ìÌíÞ
	constant_data_prop.Type = D3D12_HEAP_TYPE::D3D12_HEAP_TYPE_UPLOAD;

	// CPUÌªy[WOÉæÁÄ¡ÌÆµÄµíêÄ¢éÉÇÌæ¤É»ÌÉANZX·é©
	constant_data_prop.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY::D3D12_CPU_PAGE_PROPERTY_UNKNOWN;

	// v[(N®ÉêCÉAvÅgp·éf[^ðmÛ·éê)ÌíÞðwè·é
	constant_data_prop.MemoryPoolPreference = D3D12_MEMORY_POOL::D3D12_MEMORY_POOL_UNKNOWN;

	// q[vð¶¬·ém[h(GPUâ¨A_v^[)Ì
	constant_data_prop.CreationNodeMask = 1;

	// \[Xª¶Ý·ém[hÌ(GPUâ¨A_v^[)Ì
	constant_data_prop.VisibleNodeMask = 1;


	//  f[^Ýè  //

	// gp³êé\[XÌíÞ
	constant_data_desc.Dimension = D3D12_RESOURCE_DIMENSION::D3D12_RESOURCE_DIMENSION_BUFFER;

	// Ýè·é\[XîñÌzuÊuðwè
	constant_data_desc.Alignment = 0;

	// \[XÌoCg
	constant_data_desc.Width = con_CONSTANT_BUFFER_ONE_BYTE; // èobt@TCYÍ256oCgÅÈ¯êÎÈçÈ¢

	// \[XÌzñÔ
	constant_data_desc.Height = in_create_inform.m_list_size;

	// \[XÌ[³AÜ½Ízñ
	constant_data_desc.DepthOrArraySize = 1;

	// MIPMAPx(±ÌlÉ¶ÄsNZª{ÉÈé)
	constant_data_desc.MipLevels = 1;

	// \[XªDX12¤ªpÓµ½^©Ç¤©
	constant_data_desc.Format = DXGI_FORMAT::DXGI_FORMAT_UNKNOWN;


	//  TvOÝè  //

	// TvOñ
	constant_data_desc.SampleDesc.Count = 1;

	// TvOÌNIeB
	constant_data_desc.SampleDesc.Quality = 0;

	// eNX`CAEgÌIvV
	constant_data_desc.Layout = D3D12_TEXTURE_LAYOUT::D3D12_TEXTURE_LAYOUT_UNKNOWN;

	// \[Xðì·é½ßÌIvV
	constant_data_desc.Flags = D3D12_RESOURCE_FLAGS::D3D12_RESOURCE_FLAG_NONE;


	// èobt@Ìf[^ð¶¬
	if (FAILED(mpr_variable->s_frame_work.device->CreateCommittedResource(&constant_data_prop, D3D12_HEAP_FLAGS::D3D12_HEAP_FLAG_NONE, &constant_data_desc, D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_GENERIC_READ, nullptr, IID_PPV_ARGS(&in_dx12_constant_setting->m_constant_buffer_data))))
	{
		return;
	}


	//  èobt@r[ÌÝè  //

		//  Ïé¾  //
	D3D12_CONSTANT_BUFFER_VIEW_DESC constant_buffer_view_desc = {};  // èobt@r[¶¬pîñ


	// èobt@ÌGPUÅÌAhX
	constant_buffer_view_desc.BufferLocation = in_dx12_constant_setting->m_constant_buffer_data->GetGPUVirtualAddress();

	// oCg
	constant_buffer_view_desc.SizeInBytes = con_CONSTANT_BUFFER_ONE_BYTE * in_create_inform.m_list_size;


	// èobt@r[Ì¶¬
	mpr_variable->s_frame_work.device->CreateConstantBufferView(&constant_buffer_view_desc, in_dx12_constant_setting->m_constant_buffer_heap->GetCPUDescriptorHandleForHeapStart());


	// ¶¬µ½obt@ð[NA·é
	M_Buffer_Zero_Clear_System<ID3D12Resource>(in_dx12_constant_setting->m_constant_buffer_data.Get(), (int)constant_data_desc.Width);

	return;
}


//-- eNX` --//

//===============//
// Ú×   FeNX`pÌr[Æq[vð¶¬·é
// ø   FC_DX12_Rendering_Texture_Setting_Inform * & ÝèæÌeNX`pÌf[^, const C_Create_Texture_Setting_Inform & eNX`pf[^¶¬pîñ(const)
// ßèl Fvoid
//===============//
void C_DX12_System::M_Create_Texture_Resource_View_And_Heap(DX12_INSTANCE::C_DX12_Rendering_Texture_Setting_Inform * & in_dx12_texture_setting, const CREATE::S_Create_Texture_Setting_Inform & in_create_inform) const
{
	//  fBXNv^q[vÌ¶¬  //
	{
		//  Ïé¾  //
		D3D12_DESCRIPTOR_HEAP_DESC descriptor_heap_desc{};  // eNX`pÌq[vÌ¶¬pîñ


		// q[vÅÇ·éf[^ÌÇ
		descriptor_heap_desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE::D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;

		// f[^
		descriptor_heap_desc.NumDescriptors = 1;

		// VF[_[©çÒWÅ«é©Ç¤©
		descriptor_heap_desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAGS::D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

		// A_v^[Ìm[h
		descriptor_heap_desc.NodeMask = 0;


		// eNX`q[vÌ¶¬
		if (FAILED(mpr_variable->s_frame_work.device->CreateDescriptorHeap(&descriptor_heap_desc, IID_PPV_ARGS(&in_dx12_texture_setting->m_texture_heap))))
		{
			return;
		}
	}


	// @fBXNv^r[Ì¶¬  //
	{
		//  Ïé¾  //
		D3D12_SHADER_RESOURCE_VIEW_DESC resource_view_desc = {};  // eNX`p\[Xr[Ýèp\¢ÌÌÝè


		// f[^`®
		resource_view_desc.Format = DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_FLOAT;

		// \[XÌíÞ
		resource_view_desc.ViewDimension = D3D12_SRV_DIMENSION::D3D12_SRV_DIMENSION_TEXTURE2D;

		// MIPMAPx(±ÌlÉ¶ÄsNZª{ÉÈé)
		resource_view_desc.Texture2D.MipLevels = 1;

		// ~bv}bvªÅà×©¢Ì×©³
		resource_view_desc.Texture2D.MostDetailedMip = 0;

		// VF[_[ÖÌ}bsOû@
		resource_view_desc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;


		// r[ð¶¬·é
		mpr_variable->s_frame_work.device->CreateShaderResourceView(in_dx12_texture_setting->m_texture_data.Get(), &resource_view_desc, in_dx12_texture_setting->m_texture_heap->GetCPUDescriptorHandleForHeapStart());
	}

	return;
}


//===============//
// Ú×   FeNX`pÌf[^ð¶¬·é
// ø   FC_DX12_Rendering_Texture_Setting_Inform * & ÝèæÌeNX`pÌf[^, const C_Create_Texture_Setting_Inform & eNX`pf[^¶¬pîñ(const)
// ßèl FßèlF¬÷ÌÝtrue
//===============//
bool C_DX12_System::M_Create_Texture_Resource(DX12_INSTANCE::C_DX12_Rendering_Texture_Setting_Inform * & in_dx12_texture_setting, const CREATE::S_Create_Texture_Setting_Inform & in_create_inform) const
{
	//  Ïé¾  //
	D3D12_RESOURCE_DESC resource_desc_for_tex;  // eNX`¶¬pÌÝè
	
	D3D12_HEAP_PROPERTIES heap_properties_setting;    // q[vÝèpÌîñ


	// Ìú»
	ZeroMemory(&heap_properties_setting, sizeof(heap_properties_setting));
	ZeroMemory(&resource_desc_for_tex, sizeof(resource_desc_for_tex));
	
	
	//  q[vÌÝè  //

	// q[vÌ®ìÌíÞ
	heap_properties_setting.Type = D3D12_HEAP_TYPE::D3D12_HEAP_TYPE_CUSTOM;

	// CPUÌªy[WOÉæÁÄ¡ÌÆµÄµíêÄ¢éÉÇÌæ¤É»ÌÉANZX·é©
	heap_properties_setting.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY::D3D12_CPU_PAGE_PROPERTY_WRITE_BACK;

	// v[(N®ÉêCÉAvÅgp·éf[^ðmÛ·éê)ÌíÞðwè·é
	heap_properties_setting.MemoryPoolPreference = D3D12_MEMORY_POOL::D3D12_MEMORY_POOL_L0;

	// q[vð¶¬·ém[h(GPUâ¨A_v^[)Ì
	heap_properties_setting.CreationNodeMask = 1;

	// \[Xª¶Ý·ém[hÌ(GPUâ¨A_v^[)Ì
	heap_properties_setting.VisibleNodeMask = 1;


	//  \[XÌÝè  //

	// gp³êé\[XÌíÞ
	resource_desc_for_tex.Dimension = D3D12_RESOURCE_DIMENSION::D3D12_RESOURCE_DIMENSION_TEXTURE2D;

	// Ýè·é\[XîñÌzuÔ
	resource_desc_for_tex.Alignment = 0;

	// \[XÌoCg
	resource_desc_for_tex.Width = in_create_inform.pixel_width;
	in_dx12_texture_setting->m_pix_size_x = in_create_inform.pixel_width;

	// \[XÌzñÔ
	resource_desc_for_tex.Height = in_create_inform.pixel_height;
	in_dx12_texture_setting->m_pix_size_y = in_create_inform.pixel_height;

	// \[XÌ[³AÜ½Ízñ
	resource_desc_for_tex.DepthOrArraySize = 1;

	// MIPMAPx(±ÌlÉ¶ÄsNZª{ÉÈé)
	resource_desc_for_tex.MipLevels = 1;

	// \[XªDX12¤ªpÓµ½^©Ç¤©@P¸xt[gðÌp
	resource_desc_for_tex.Format = DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_FLOAT;

	//  TvOÝè  //

	// TvOñ
	resource_desc_for_tex.SampleDesc.Count = 1;

	// TvOÌNIeB
	resource_desc_for_tex.SampleDesc.Quality = 0;

	// eNX`CAEgÌIvV
	resource_desc_for_tex.Layout = D3D12_TEXTURE_LAYOUT::D3D12_TEXTURE_LAYOUT_UNKNOWN;

	// \[Xðì·é½ßÌIvV
	resource_desc_for_tex.Flags = D3D12_RESOURCE_FLAGS::D3D12_RESOURCE_FLAG_NONE;


	// \[Xð¶¬·é    // ¸sµ½çG[Å²¯é
	if (FAILED(mpr_variable->s_frame_work.device->CreateCommittedResource(&heap_properties_setting, D3D12_HEAP_FLAGS::D3D12_HEAP_FLAG_NONE, &resource_desc_for_tex, D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_GENERIC_READ, nullptr, IID_PPV_ARGS(in_dx12_texture_setting->m_texture_data.GetAddressOf()))))
	{
		return false;
	}


	// ¶¬µ½obt@ð[NA·é
	M_Buffer_Zero_Clear_System<ID3D12Resource>(in_dx12_texture_setting->m_texture_data.Get(), (int)resource_desc_for_tex.Width * (int)resource_desc_for_tex.Height);

	return true;
}


//-- [gVOl` --//

//===============//
// Ú×   F[gVOl`fXN©ç[gVOl`ðVACYµ¶¬·é
// ø   Fconst D3D12_ROOT_SIGNATURE_DESC & [gVOl`ðÝè·é½ßÌîñÌQÆ(const), ComPtr<ID3D12RootSignature> & [gVOl`ÌÝèæ
// ßèl Fvoid
//===============//
bool C_DX12_System::M_Serialize_And_Create_RootSignature_By_Desc(const D3D12_ROOT_SIGNATURE_DESC & in_root_signature_desc, Microsoft::WRL::ComPtr<ID3D12RootSignature> & in_root_signature) const
{
	//  Ïé¾  //
	ID3DBlob * root_signature_serialized_data = nullptr;    // [g¼¶¬ÌVACYf[^ð¾é


	//  [gVOl`¶¬pîñð\[XÆµÄVACY·é  //		// ¸sÅG[ðo·
	if (FAILED(D3D12SerializeRootSignature(&in_root_signature_desc, D3D_ROOT_SIGNATURE_VERSION::D3D_ROOT_SIGNATURE_VERSION_1, &root_signature_serialized_data, nullptr)))
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "[gVOl`ÌVACY»É¸sµÜµ½");
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}


	//  [gVOl`Ì¶¬  //	// ¸sÅG[ðo·
	if (FAILED(mpr_variable->s_frame_work.device->CreateRootSignature(0, root_signature_serialized_data->GetBufferPointer(), root_signature_serialized_data->GetBufferSize(), IID_PPV_ARGS((ID3D12RootSignature**)&in_root_signature))))
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "[gVOl`Ì¶¬É¸sµÜµ½");
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}


	// [gVOl`Ì¶¬Ì¬÷ðm
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "[gVOl`Ì¶¬É¬÷µÜµ½");

	return true;
}


//===============//
// Ú×   F[gVOl`ð¶¬·é
// ø   FC_DX12_Rendering_Graphics_Setting_Inform * & ZbgæÌ`æpCvCpf[^, const C_Create_Vertex_Buffer_Inform & `æpCvCpf[^¶¬pîñ(const)
// ßèl Fbool ¬÷Ítrue
//===============//
bool C_DX12_System::M_Create_Root_Signature(DX12_INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * & in_dx12_pipeline_inform, const CREATE::S_Create_Rendering_Graphics_Setting_Inform & in_create_inform) const
{
	//  Ïé¾  //
	D3D12_ROOT_SIGNATURE_DESC root_signature_desc;	// [g¼iVOl`j¶¬pîñ

	std::vector<D3D12_STATIC_SAMPLER_DESC> static_sampler_desc; // ÃITv[¶¬pîñ

	std::vector<D3D12_DESCRIPTOR_RANGE> range_setting_list;    // LqqÌÍÍðÝè·éîñ

	std::vector<D3D12_ROOT_PARAMETER> paramater_setting_list;  // eNX`âèobt@ðÝè·éêÌ¶¬pîñ


	// VF[_[É\[Xðè`·éifBXNv^ÆWATv[ð¶¬·éj
	M_Create_Descriptor_And_Sampler_By_Shaders_Inform(in_create_inform.shader_setting->M_Get_Resource_Inform(), paramater_setting_list, range_setting_list, static_sampler_desc);


	//  [gVOl`fXNÌÝè  //

	// ú»
	ZeroMemory(&root_signature_desc, sizeof(root_signature_desc));

	// [gVOl`fXNÉfBXNv^XbgÆTv[ðÝè·é
	Inline_Set_Parameters_And_Sampler_Desc_To_Root_Signature_Desc(root_signature_desc, paramater_setting_list, static_sampler_desc);

	// [g¼ÌCAEgIvV
	root_signature_desc.Flags = D3D12_ROOT_SIGNATURE_FLAGS::D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;


	//  [gVOl`Ì¶¬  //

	// [gVOl`ð¶¬µÄÊðÔ·
	return M_Serialize_And_Create_RootSignature_By_Desc(root_signature_desc, in_dx12_pipeline_inform->m_root_signature);
}


//-- pCvCXe[g --//

//===============//
// Ú×   FpCvCXe[gð¶¬·é
// ø   FC_DX12_Rendering_Graphics_Setting_Inform * & ZbgæÌ`æpCvCpf[^, const C_Create_Vertex_Buffer_Inform & `æpCvCpf[^¶¬pîñ(const)
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_DX12_System::M_Create_Pipeline_State(DX12_INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * & in_dx12_pipeline_inform, const CREATE::S_Create_Rendering_Graphics_Setting_Inform & in_create_inform) const
{
	//  Ïé¾  //
	RENDERING::API::DX12::DX12_INSTANCE::C_DX12_Input_Layout_Setting_System input_setting_system;    // üÍCAEgÝèpVXe

	D3D12_GRAPHICS_PIPELINE_STATE_DESC desc_pipeline_state; // pCvCÝèpîñ

	D3D12_SHADER_BYTECODE * add_shader_list[] =    // Ýè·éVF[_[ÌAhXÌXg
	{
		&desc_pipeline_state.VS,
		&desc_pipeline_state.HS,
		&desc_pipeline_state.DS,
		&desc_pipeline_state.GS,
		&desc_pipeline_state.PS,
	};


	// ú»
	ZeroMemory(&desc_pipeline_state, sizeof(desc_pipeline_state));


	//  [gVOl`ÌZbg  //
	desc_pipeline_state.pRootSignature = in_dx12_pipeline_inform->m_root_signature.Get();


	// VF[_[ÌíÞ²ÆÉwè³ê½ÔðZbg
	{
		//  Ïé¾  //
		const std::vector<ASSET::SHADER::C_Shader_User> & shader_user_list = in_create_inform.shader_setting->M_Get_Shader_Code_List(); // wè³ê½VF[_[ZbgÌR[hÌXg


		for (const ASSET::SHADER::C_Shader_User & now_shader_user : shader_user_list)
		{
			Inline_Set_Shader_Data(*add_shader_list[(int)now_shader_user.M_Get_Shader_Kind()], now_shader_user.M_Get_Shader_Code());
		}
	}

	// VF[_[ÌîñðÝè
	in_dx12_pipeline_inform->m_shader_setting = in_create_inform.shader_setting;


	//  üÍCAEgÌÝè  //
	input_setting_system.M_Create_Input_Layout_By_Create_Inform(desc_pipeline_state.InputLayout, in_create_inform.shader_setting->M_Get_Input_Layout());


	//  Xg[~OoÍobt@  //
	RENDERING::API::DX12::DX12_TOOL::C_DX12_Streaming_Output_Buffer_Base::M_Do_Not_Use_Setting(desc_pipeline_state);


	//  uhóÔÝè  //
	RENDERING::API::DX12::DX12_TOOL::C_DX12_Blend_State_Setting_System::M_Set_Blend_State_By_Inform(desc_pipeline_state, in_create_inform);


	//  _[^[QbgÅXV³êéTv  //
	desc_pipeline_state.SampleMask = UINT_MAX;


	//  X^CU[ÝèiæÏ·ÌÝèj  //
	RENDERING::API::DX12::DX12_TOOL::C_DX12_Rasterizer_State_Setting_System::M_Rasterizer_Setting(desc_pipeline_state, in_create_inform);


	//  [xXeVÝè  //
	RENDERING::API::DX12::DX12_TOOL::C_DX12_Stencil_State_Setting_System::M_Depth_Stencil_Setting(desc_pipeline_state, in_create_inform);


	//  \ü«ÌÊÌ[xXeVeXgÝè  //    // @üªJÌûðü¢Ä¢é©Ç¤©Å»è·é
	RENDERING::API::DX12::DX12_TOOL::C_DX12_Stencil_State_Setting_System::M_Test_Keep_Setting(desc_pipeline_state.DepthStencilState.FrontFace);


	//   ü«ÌÊÌ[xXeVeXgÝè  //    // @üªJÌûðü¢Ä¢é©Ç¤©Å»è·é
	RENDERING::API::DX12::DX12_TOOL::C_DX12_Stencil_State_Setting_System::M_Test_Keep_Setting(desc_pipeline_state.DepthStencilState.BackFace);


	//  }`TvOÝè  //
	RENDERING::API::DX12::DX12_TOOL::C_DX12_Sampling_Setting_System::M_Sampling_Setting(desc_pipeline_state, in_create_inform.sampling_setting.sampling_count, in_create_inform.sampling_setting.sampling_quality, 0);


	//  pCvCXe[gÌæ¾pÌÝè  //
	RENDERING::API::DX12::DX12_TOOL::C_DX12_Cached_PSO_Base::M_Cache_Nothing(desc_pipeline_state);


	//  pCvC¶¬  //  // G[Èç²¯é
	if (FAILED(mpr_variable->s_frame_work.device->CreateGraphicsPipelineState(&desc_pipeline_state, IID_PPV_ARGS(&in_dx12_pipeline_inform->m_pipeline_state_setting))))
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "pCvCXe[gÌ¶¬É¸sµÜµ½");
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}


	// pCvCXe[gÌ¶¬Ì¬÷ðm
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "pCvCXe[gÌ¶¬É¬÷µÜµ½");


	// ÝèpÌîñðN[Y
	input_setting_system.M_Close_Input_Layout_Inform();

	return true;
}


//===============//
// Ú×   FVF[_[É\[Xðè`·éifBXNv^ÆWATv[ð¶¬·éj
// ø   Fconst S_All_Shader_Resource_Signatures & VF[_[Ì\[X¯ÊîñÌQÆ, vector<D3D12_ROOT_PARAMETER> & fBXNv^ÝèpîñÌQÆ, vector<D3D12_DESCRIPTOR_RANGE> & WÌÝèpîñÌQÆ, vector<D3D12_STATIC_SAMPLER_DESC> & Tv[ÝèpîñÌQÆ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Create_Descriptor_And_Sampler_By_Shaders_Inform(const ASSET::SHADER::S_Resource_Inform_List & in_shader_inform, std::vector<D3D12_ROOT_PARAMETER> & in_root_param, std::vector<D3D12_DESCRIPTOR_RANGE> & in_range, std::vector<D3D12_STATIC_SAMPLER_DESC> & in_sampler) const
{
	//  Ïé¾  //
	int resource_register_number = 0;    // VF[_[ÌfBXNv^ÌJnWX^Ô
	int sampler_register_number = 0;      // VF[_[ÌTv[ÌJnWX^Ô
	

	// VF[_[Ìèobt@ªJèÔ·
	for (const ASSET::SHADER::S_Resource_Slot_Inform & l_now_slot : in_shader_inform.slot_list)
	{
		// \[XÌíÞÉæÁÄfBXNv^ÌíÞðÏ¦é
		switch (l_now_slot.resource_kind)
		{
			// èobt@
		case ASSET::SHADER::E_RESOURCE_KIND::e_CONSTANT_BUFFER:
			Inline_Set_Root_Parameter
			(
				in_root_param,
				in_range,
				D3D12_DESCRIPTOR_RANGE_TYPE::D3D12_DESCRIPTOR_RANGE_TYPE_CBV,
				resource_register_number,
				M_Convert_Shader_Kind_To_DX12_Shader_Kind(l_now_slot.shader_kind)
			);
			break;

			// eNX`
		case ASSET::SHADER::E_RESOURCE_KIND::e_TEXTURE:
			Inline_Set_Root_Parameter
			(
				in_root_param,
				in_range,
				D3D12_DESCRIPTOR_RANGE_TYPE::D3D12_DESCRIPTOR_RANGE_TYPE_SRV,
				resource_register_number,
				M_Convert_Shader_Kind_To_DX12_Shader_Kind(l_now_slot.shader_kind)
			);
			break;
		}

		resource_register_number += 1;
	}

	// Tv[ªJèÔ·
	for (const ASSET::SHADER::S_Sampler_Resource_Inform & l_now_sampler : in_shader_inform.sampler_list)
	{
		Inline_Set_Sampler_State
		(
			in_sampler, 
			sampler_register_number, 
			M_Convert_Shader_Kind_To_DX12_Shader_Kind(l_now_sampler.shader_kind),
			Inline_Get_Texture_Mode(l_now_sampler.uv_setting)
		);

		sampler_register_number += 1;
	}

	return;
}


//-- XV --//

//-- fobO --//

//===============//
// Ú×   FfobOÌÝs¤XV
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_DX12_System::M_Debug_Update(void) const
{
#ifdef _DEBUG
#endif // _DEBUG

	return;
}


//===============//
// Ú×   FG[Ì´öðOÉ\¦·é
// ø   FHRESULT G[R[h
// ßèl Fbool G[ÅÍÈ¢Æ«ÌÝtrue
//===============//
bool C_DX12_System::M_Display_Error_Message(HRESULT in_error_code) const
{
	// G[OàeÌQÆæ@https://learn.microsoft.com/ja-jp/windows/win32/direct3ddxgi/dxgi-error

	// G[R[hÉæÁÄG[Ì´öð\¦·é
	switch (in_error_code)
	{
		// ANZX ÌÛ
	case DXGI_ERROR_ACCESS_DENIED:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_ACCESS_DENIEDFANZX ðÁÄ¢È¢ÖÌìª­¶µAANZXªÛ³êÜµ½"
		);

		break;

		// ANZX Ìr¸
	case DXGI_ERROR_ACCESS_LOST:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_ACCESS_LOSTFANZX ðæ¾µ½ª½ç©Ì´öÉæèr¸µÄ¢é½ßAANZXªÛ³êÜµ½"
		);

		break;

		// ·ÅÉ¶¬ÏÝÌVXeâ Àð½dÅæ¾µæ¤Æµ½
	case DXGI_ERROR_ALREADY_EXISTS:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_ALREADY_EXISTSF·ÅÉ¶¬ÏÝÌVXeâ Àð½dÅæ¾µæ¤Æµ½½ßA¶¬É¸sµÜµ½"
		);
		
		break;

		// RecÛìðXbv`F[Éèú¤Å«È©Á½
	case DXGI_ERROR_CANNOT_PROTECT_CONTENT:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_CANNOT_PROTECT_CONTENTFXbv`F[Ìæ¾É¸sBOtBbNuªÃ¢hCo[Å éAÜ½ÍRecÛìÆÝ·«ÌÈ¢Xbv`F[ðgpµÜµ½"
		);
		
		break;

		// foCXÖÌì~XÉæèfoCXªZbg³ê½
	case DXGI_ERROR_DEVICE_HUNG:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_DEVICE_HUNGFfoCXÖÌì~XÉæèfoCXªZbg³êÜµ½"
		);
		
		break;

		// foCXÌr¸
	case DXGI_ERROR_DEVICE_REMOVED:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_DEVICE_REMOVEDFfoCXªÁ¦Üµ½"
		);
		
		break;

		// sKØÈ`®ÌR}hª­s³ê½
	case DXGI_ERROR_DEVICE_RESET:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_DEVICE_RESETFÀs³ê½R}hÌf[^ÉsKØÈàÌª èÜ·"
		);
		
		break;

		// hCo[ÌG[ÉæèAfoCXªZbg³ê½
	case DXGI_ERROR_DRIVER_INTERNAL_ERROR:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_DRIVER_INTERNAL_ERRORFhCo[ÌG[ÉæèAfoCXªZbg³êÜµ½"
		);

		break;

		// CxgÉæèæÊÌXVªf³ê½
	case DXGI_ERROR_FRAME_STATISTICS_DISJOINT:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_FRAME_STATISTICS_DISJOINTFCxgÉæèæÊÌXVªf³êÜµ½"
		);

		break;

		// OtBbNJ[hÈÇ`æXy[XÖÌèLðs¨¤Æµ½ªAùÉèL³êÄ¢é½ßÅ«È©Á½
	case DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USEFOtBbNJ[hÈÇ`æXy[XÖÌèLðs¨¤Æµ½ªAùÉèL³êÄ¢é½ßÅ«È©Á½"
		);

		break;

		// ³øÈp[^[âf[^ðwèµÄµÜÁ½
	case DXGI_ERROR_INVALID_CALL:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_INVALID_CALLF³øÈp[^[âf[^ðwèµÄµÜÁ½BR[hà©ç³íÅÍÈ¢lÉÈéVXeðTµC³·éKvª é"
		);

		break;

		// obt@[Ìf[^ª¬³¢½ßAf[^Ìæ¾ªÅ«È©Á½
	case DXGI_ERROR_MORE_DATA:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_MORE_DATAFobt@[Ìf[^ª¬³¢½ßAf[^Ìæ¾ªÅ«Ü¹ñÅµ½"
		);

		break;

		// IDXGIResource1::CreateSharedHandleÅwè³ê½¼OÍ·ÅÉgp³êÄ¢é
	case DXGI_ERROR_NAME_ALREADY_EXISTS:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_NAME_ALREADY_EXISTSFIDXGIResource1::CreateSharedHandleÅwè³ê½¼OÍ·ÅÉgp³êÄ¢Ü·"
		);

		break;

		// O[oJE^[\[XFhCo[Øc[ªhCo[ÉÎµÄÀs·éANVÌêðÄ·évîñ
		// JE^[\[XðQÆEgp·é±ÆªÅ«È¢óÔÅ Á½
	case DXGI_ERROR_NONEXCLUSIVE:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_NONEXCLUSIVEFO[oJE^[\[XðQÆEgp·é±ÆªÅ«Ü¹ñÅµ½"
		);

		break;

		// wè³ê½\[XÜ½ÍvÍ»ÝgpÅ«Ü¹ñ
	case DXGI_ERROR_NOT_CURRENTLY_AVAILABLE:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_NOT_CURRENTLY_AVAILABLEFwè³ê½\[XÜ½ÍvÍ»ÝgpÅ«Ü¹ñ"
		);

		break;

		// IDXGIObject::GetPrivateData ðÄÑo·Æ«An³ê½GUIDÍeÍÍOÅ·AIDXGIObject::SetPrivateData Ü½Í IDXGIObject::SetPrivateDataInterface Én³ê½àÌÅÍ èÜ¹ñB
	case DXGI_ERROR_NOT_FOUND:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_NOT_FOUNDFwè³ê½\[XÜ½Ívª©Â©èÜ¹ñÅµ½"
		);

		break;

		// [gfXNgbvNCAgÌÚ±ªØf³ê½
	case DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_REMOTE_CLIENT_DISCONNECTEDF[gfXNgbvNCAgÌÚ±ªØf³êÜµ½"
		);

		break;

		// [gfXNgbvÌªs«µÄ¢éAÜ½ÍÍÍOÖÌì
	case DXGI_ERROR_REMOTE_OUTOFMEMORY:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_REMOTE_OUTOFMEMORYF[gfXNgbvÌªs«AÜ½ÍÍÍOÖÌìªsíêÜµ½"
		);

		break;

		// Xbv`F[ÌoÍæÌj^[ªØfEÏX³ê½
	case DXGI_ERROR_RESTRICT_TO_OUTPUT_STALE:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_RESTRICT_TO_OUTPUT_STALEFXbv`F[ÌoÍæÌj^[ªØfEÏX³êÜµ½"
		);

		break;

		// SDKR|[lgª³mÉwè³êÄ¨ç¸AêvµÄ¢È¢
	case DXGI_ERROR_SDK_COMPONENT_MISSING:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_SDK_COMPONENT_MISSINGFSDKR|[lgª³mÉwè³êÄ¨ç¸AêvµÄ¢Ü¹ñ"
		);

		break;

		// [gfXNgbvÌT[rXÍ»ÝÚ±³êÄ¢È¢
	case DXGI_ERROR_SESSION_DISCONNECTED:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_SESSION_DISCONNECTEDF[gfXNgbvÌT[rXÍ»ÝÚ±³êÄ¢Ü¹ñ"
		);

		break;

		// v³ê½@\ÍAfoCXÜ½ÍhCo[ÅÍT|[g³êÄ¢È¢
	case DXGI_ERROR_UNSUPPORTED:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_UNSUPPORTEDFv³ê½@\ÍAfoCXÜ½ÍhCo[ÅÍT|[g³êÄ¢Ü¹ñ"
		);

		break;

		// Ì`æt[ªgpÂ\ÉÈéÜÅÌ^CAEgÔuÌì
	case DXGI_ERROR_WAS_STILL_DRAWING:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_WAS_STILL_DRAWINGFÌ`æt[ªgpÂ\ÉÈéÜÅÌ^CAEgÔuÌì"
		);

		break;

		// GPUªrW[óÔÅ é½ßAìªÀsÅ«È¢
	case DXGI_ERROR_WAIT_TIMEOUT:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"DXGI_ERROR_WAIT_TIMEOUTFGPUªrW[óÔÅ é½ßAìªÀsÅ«Ü¹ñ"
		);

		break;

		// G[ÍÈ©Á½
	case S_OK:
		return true;

		break;

		// ¢mÌG[
	default:
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_ERROR_CHECKING,
			"¢mÌG[ª­¶µÜµ½B±ÌG[îñÍo^³êÄ¢Ü¹ñ"
		);

		break;
	}

	// G[ÈÌÅfalseðÔ·
	return false;
}


//===============//
// Ú×   F\[X¯úpoAÌZbg
// ø   Fint ÝèæÌ_OæÊÌÔ, S_DX12_Render_Target_View & _[^[Qbgr[îñÌQÆ, D3D12_RESOURCE_STATES Ýè·é\[Xgpû@
// ßèl Fvoid
//===============//
void C_DX12_System::M_Set_Resource_Barrier(int in_rendering_screen_number, RENDERING::API::DX12::DX12_INSTANCE::S_DX12_Render_Target_View & in_render_target_view, D3D12_RESOURCE_STATES in_after) const
{
	// ÝèOÆÝèãÌgpû@ª¯¶Èç²¯é
	if (in_render_target_view.buffer_list[in_rendering_screen_number].now_resource_barrier == in_after)
	{
		return;
	}


	//  Ïé¾  //
	D3D12_RESOURCE_BARRIER desc_resource_barrier;   // \[XoAÝèpîñ


	// ú»
	ZeroMemory(&desc_resource_barrier, sizeof(desc_resource_barrier));

	// \[XoAÌíÞ
	desc_resource_barrier.Type = D3D12_RESOURCE_BARRIER_TYPE::D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;

	// \[XÖÌAhX
	desc_resource_barrier.Transition.pResource = in_render_target_view.buffer_list[in_rendering_screen_number].render_buffer.Get();

	// Tu\[XÌCfbNX
	desc_resource_barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;

	// ØèÖ¦OÌgp@Zbg
	desc_resource_barrier.Transition.StateBefore = in_render_target_view.buffer_list[in_rendering_screen_number].now_resource_barrier;

	// ØèÖ¦ãÌgp@Zbg
	desc_resource_barrier.Transition.StateAfter = in_after;


	// oAÌZbg
	mpr_variable->s_command.list->ResourceBarrier(1, &desc_resource_barrier);

	// oAÌL^
	in_render_target_view.buffer_list[in_rendering_screen_number].now_resource_barrier = in_after;
	
	return;
}


//===============//
// Ú×   FR}hÀsÒ¿
// ø   FID3D12Resource * \[XÖÌAhX, D3D12_RESOURCE_STATES Tu\[X­¶ÌOÌgp@, D3D12_RESOURCE_STATES Tu\[X­¶ÌãÌgp@
// ßèl Fvoid
//===============//
void C_DX12_System::M_Wait_For_Command_Queue(void)
{
	//  Ïé¾  //
	UINT64 result_fence = mpr_variable->s_command.fence_value[mpr_variable->s_command.num_back_screen]; // ÊÌtFXlðó¯æé


	// ¡ÌtFXlðó¯æé
	mpr_variable->s_command.queue->Signal(mpr_variable->s_render.queue_fence.Get(), result_fence);


	//  Ü¾R}hL[ªI¹µÄ¢È¢±ÆðmF·é  //
	if (mpr_variable->s_render.queue_fence->GetCompletedValue() < result_fence)
	{
		// ±ÌFenceÉ¨¢ÄAtFXlÉÈÁ½çtFXCxgðÀs·é±Æðwè
		mpr_variable->s_render.queue_fence->SetEventOnCompletion(result_fence, mpr_variable->s_render.fence_event);


		// Cxgª­Î·éÜÅÒÂ
		WaitForSingleObject(mpr_variable->s_render.fence_event, INFINITE);
	}


	// »èpÌtFXlðCNg
	mpr_variable->s_command.fence_value[mpr_variable->s_command.num_back_screen] += 1;

	return;
}


//===============//
// Ú×   Fr[|[gÆVU[ÌÝèðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_DX12_System::M_Set_Scissor_And_View_Port(void)
{
	//  Ïé¾  //
	const OS::S_Window_Size_Data & window_size = OS::C_OS_User_System::M_Get_Window_Size();  // EBhETCY


	//  r[|[gÝè  //

	// æÊTCY
	mpr_variable->s_frame_work.view_port.Width = (FLOAT)window_size.width;
	mpr_variable->s_frame_work.view_port.Height = (FLOAT)window_size.height;

	// æÊÌ¶ãÀW
	mpr_variable->s_frame_work.view_port.TopLeftX = 0.0f;
	mpr_variable->s_frame_work.view_port.TopLeftY = 0.0f;

	// [xÝè
	mpr_variable->s_frame_work.view_port.MinDepth = 0.0f;
	mpr_variable->s_frame_work.view_port.MaxDepth = 1.0f;


	//  VU[NgÝè  //

	// ÀWÝè
	mpr_variable->s_frame_work.scissor_rect.left = 0;
	mpr_variable->s_frame_work.scissor_rect.right = (LONG)mpr_variable->s_frame_work.view_port.Width;
	mpr_variable->s_frame_work.scissor_rect.top = 0;
	mpr_variable->s_frame_work.scissor_rect.bottom = (LONG)mpr_variable->s_frame_work.view_port.Height;


	// æÊTCYXV
	mpr_variable->s_command.list->RSSetViewports(1, &mpr_variable->s_frame_work.view_port);
	mpr_variable->s_command.list->RSSetScissorRects(1, &mpr_variable->s_frame_work.scissor_rect);

	return;
}


//===============//
// Ú×   F`æR}hîñðZbg·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_DX12_System::M_Reset_Command(void)
{
	// R}hAP[^Ìðú»µÄÄpÂ\É·é
	mpr_variable->s_command.allocator->Reset();

	// R}hXgðúóÔÉZbgi±êðµÈ¢Æ«ÝÂ\ÉÈçÈ¢j
	mpr_variable->s_command.list->Reset(mpr_variable->s_command.allocator.Get(), nullptr);

	return;
}


//-- ¯Êpîñ --//

//===============//
// Ú×   Fwè³ê½pCvCîñð³ÉVF[_[Ì\[X¯Ê¼ðZbg·é
// ø   Fconst C_DX12_Rendering_Graphics_Setting_Inform * & pCvCîñ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Set_Shader_Resource_Signature_By_Rendering_Setting(const DX12_INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * & in_rendering_setting)
{
	mpr_variable->shader_resource_list.release();
	mpr_variable->shader_resource_list.reset(&in_rendering_setting->m_shader_setting->M_Get_Resource_Inform());

	return;
}


//-- íÊ --//

//===============//
// Ú×   Fwè³ê½@\xð¶ñÉÏ··é
// ø   FD3D_FEATURE_LEVEL @\xwèpñ
// ßèl Fstd::string Ï·ãÌ¶ñ
//===============//
std::string C_DX12_System::M_Convert_D3D_FEATURE_LEVEL_Enum_To_String(D3D_FEATURE_LEVEL in_feature_level)
{
	//  @\xÅªò  //
	switch (in_feature_level)
	{
		// Rs[eBOêpf
	case D3D_FEATURE_LEVEL_1_0_CORE:
		return "D3D_FEATURE_LEVEL_1_0_CORE";

		// DirectX9
	case D3D_FEATURE_LEVEL_9_1:
		return "D3D_FEATURE_LEVEL_9_1";
	case D3D_FEATURE_LEVEL_9_2:
		return "D3D_FEATURE_LEVEL_9_2";
	case D3D_FEATURE_LEVEL_9_3:
		return "D3D_FEATURE_LEVEL_9_3";

		// DirectX10
	case D3D_FEATURE_LEVEL_10_0:
		return "D3D_FEATURE_LEVEL_10_0";
	case D3D_FEATURE_LEVEL_10_1:
		return "D3D_FEATURE_LEVEL_10_1";

		// DirectX11
	case D3D_FEATURE_LEVEL_11_0:
		return "D3D_FEATURE_LEVEL_11_0";
	case D3D_FEATURE_LEVEL_11_1:
		return "D3D_FEATURE_LEVEL_11_1";

		// DirectX12
	case D3D_FEATURE_LEVEL_12_0:
		return "D3D_FEATURE_LEVEL_12_0";
	case D3D_FEATURE_LEVEL_12_1:
		return "D3D_FEATURE_LEVEL_12_1";
	case D3D_FEATURE_LEVEL_12_2:
		return "D3D_FEATURE_LEVEL_12_2";
	}

	// ¢è`ÌÔ
	return "Undefined";
}


//==  pubN  ==//

//--  ú»ÆI¹  --//

//===============//
// Ú×   FDX12VXeÌú»
// ø   Fvoid
// ßèl Fbool §¿ã°É¬÷µÄ¢½çtrue
//===============//
bool C_DX12_System::M_Set_Up(void)
{
	// DX12VXeÌú»
	if (M_DirectX12_Init() == false)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "Error--------DX12ÌZbgAbv¸s--------Error");
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;	// ¸sÈçG[ðÔµÄ²¯é
	}


	// DX12VXeÌú»¬÷ðm
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "--------DX12ÌZbgAbv®¹--------");
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Console_LOG_Flush();

	// ¬÷µ½
	return true;
}


//===============//
// Ú×   FDX12ð¶¬·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_DX12_System::M_Create_DirectX12(void)
{
	//  ¶¬µÄZbg  //   // ùÉ¶¬µÄ¢½f[^ÍÁ³êé
	m_this.reset(new C_DX12_System());

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_DX12_System::M_Release(void)
{
	// ¢ðúÈçÎðú
	if (mpr_variable)
	{
		// VF[_[\[XXgÌí
		mpr_variable->shader_resource_list.release();

		// tFXÌI¹
		if (mpr_variable->s_render.fence_event != nullptr)
		{
			CloseHandle(mpr_variable->s_render.fence_event);
		}

		// oÌí
		mpr_variable.reset();
		mpr_variable = nullptr;
	}

	return;
}

//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_DX12_System::~C_DX12_System()
{
	M_Release();

	return;
}


//-- _O --//

//===============//
// Ú×   F`æJnpÌAR}hðú»µ æÊÌ\[Xð¯ú³¹_[^[QbgæÉwè·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_DX12_System::M_Rendering_Start(void)
{
	//  R}hú»  //
	M_Reset_Command();

	// r[|[gÆVU[ÌXV
	M_Set_Scissor_And_View_Port();

	// CÌ_OæÊÆ[xXeVobt@ðNAµÄZbg
	M_Set_Resource_Barrier(mpr_variable->s_command.num_back_screen, mpr_variable->s_render.main_rendering_screen->m_render_target_view, D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_RENDER_TARGET);
	M_Clear_Render_Target_View(mpr_variable->s_command.num_back_screen, mpr_variable->s_render.main_rendering_screen->m_render_target_view);
	
	return;
}


//===============//
// Ú×   FæÊðtbvµÄ`æ·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_DX12_System::M_Rendering_End_And_Swap_Screen(void)
{
	//  Ïé¾  //
	ID3D12CommandList * p_command_list = mpr_variable->s_command.list.Get();   // R}hXgÌAhXðn·½ßÉÏÉ·é

	HRESULT check_error_result = S_OK;	// G[`FbNÌÊ


	//  `æ½ßÌL^I¹  //

	// CÌ_OæÊðZbg
	M_Set_Main_Rendering_Screen_To_Rendering();

	// \[X¯úpÌoAðoÍpÉÏX (ÏXª®¹·éÜÅÒÂ)
	M_Set_Resource_Barrier(mpr_variable->s_command.num_back_screen, mpr_variable->s_render.main_rendering_screen->m_render_target_view, D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_PRESENT);

	// R}hXgÖÌL^I¹(±êðæÉsíÈ¢ÆÀs³¹é±ÆªoÈ¢)
	mpr_variable->s_command.list->Close();

	// R}hÀs
	mpr_variable->s_command.queue->ExecuteCommandLists(1, &p_command_list);

	//  æÊoÍ  //
	mpr_variable->s_frame_work.swap_chain->Present(1, 0);


	// `ææÌæÊðüè·é( æÊðwè)
	mpr_variable->s_command.num_back_screen = mpr_variable->s_frame_work.swap_chain->GetCurrentBackBufferIndex();

	// `æ®¹Ò¿
	M_Wait_For_Command_Queue();


	// fobOÌÝs¤XV
	M_Debug_Update();


	// foCXªí³êÄ¢é©Ç¤©ð`FbN
	check_error_result = mpr_variable->s_frame_work.device->GetDeviceRemovedReason();


	// foCXíoOÌ`FbNAÁ¦Ä¢½Èç_OAPIVXeÌI¹ð¦·
	if (FAILED(check_error_result))
	{
		// _OAPIÌI¹ð¦·
		mpr_variable->flg_rendering_api_end = true;

		// foCXªÁ¦½±Æð\¦
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::DX12::con_DEVICE_DELETED,
			"foCXªÁ¦½½ßAvP[VÌI¹ðÀs"
		);

		// G[Ì´öð\¦
		M_Display_Error_Message(check_error_result);

		// Oð\¦·é½ßÉêâ~
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();
	}

	return;
}


//-- _OÝè --//

//===============//
// Ú×   F`æpCvCpÌîñð¶¬·é
// ø   Fstd::unique_ptr<C_Rendering_Graphics_Setting_Inform_Base> & ÝèæÌpCvCîñ, const C_Create_Rendering_Graphics_Setting_Inform & ¶¬pÌîñ(const)
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_DX12_System::M_Create_Rendering_Graphics_Inform(std::unique_ptr<INSTANCE::C_Rendering_Graphics_Setting_Inform_Base> & in_pipeline_inform, const CREATE::S_Create_Rendering_Graphics_Setting_Inform & in_create_inform) const
{
	//  Ïé¾  //
	DX12_INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * dx12_pipeline_inform = new DX12_INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform(); // DX12pÌ`æpîñ


	//  [gVOl`Ýè  //@¸sµ½çG[Å²¯é
	if (M_Create_Root_Signature(dx12_pipeline_inform, in_create_inform) == false)
	{
		return false;
	}


	//  pCvCXe[g  //@¸sµ½çG[Å²¯é
	if (M_Create_Pipeline_State(dx12_pipeline_inform, in_create_inform) == false)
	{
		return false;
	}

	// f[^ðZbg
	in_pipeline_inform.reset(dx12_pipeline_inform);


	// _OÝèÌ¶¬Ì¬÷ðm
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "_OÝèÌ¶¬É¬÷");

	return true;
}


//===============//
// Ú×   FÌ`æÀsðJn·é
// ø   Fconst unique_ptr<C_Rendering_Graphics_Setting_Inform_Base> & Zbg·é_OÌÝèÌîñ(const)
// ßèl Fvoid
//===============//
void C_DX12_System::M_Rendering_Set_Rendering_Setting(const std::unique_ptr<INSTANCE::C_Rendering_Graphics_Setting_Inform_Base> & in_pipeline_inform)
{
	//  Ïé¾  //
	const DX12_INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * dx12_pipeline_inform = reinterpret_cast<const DX12_INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * > (in_pipeline_inform.get());   // `æpCvCpîñðDX12pÖLXgµ½ÊÌAhX


	// `æ·é}`ðÝè
	mpr_variable->s_command.list->IASetPrimitiveTopology(dx12_pipeline_inform->m_topology_type);

	// [gVOl`ÌZbg
	mpr_variable->s_command.list->SetGraphicsRootSignature(dx12_pipeline_inform->m_root_signature.Get());

	// pCvCXe[gðÝè·é
	mpr_variable->s_command.list->SetPipelineState(dx12_pipeline_inform->m_pipeline_state_setting.Get());


	// ¯ÊpîñðÝè·é
	M_Set_Shader_Resource_Signature_By_Rendering_Setting(dx12_pipeline_inform);

	return;
}


//-- _OæÊ --//

//===============//
// Ú×   F_OæÊð¶¬·é
// ø   Funique_ptr<C_Rendering_Screen_Data_Base> & ÝèæÌ_OæÊÌQÆ, S_Create_Render_Screen_Inform & _OæÊð¶¬·é½ßÌîñÌQÆiconstj
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_DX12_System::M_Create_Rendering_Screen(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & in_set_rendering_screen, const RENDERING::API::CREATE::S_Create_Render_Screen_Inform & in_create_screen) const
{
	//  Ïé¾  //
	DX12_INSTANCE::C_DX12_Rendering_Screen_System * dx12_rendering_screen = new DX12_INSTANCE::C_DX12_Rendering_Screen_System(); // DX12pÌ_OæÊ


	// _OæÊð¶¬·éA¸sµ½çG[Å²¯é
	if (M_Create_Render_Target_View_Descriptor_Heap(dx12_rendering_screen, in_create_screen) == false)
	{
		return false;
	}


	// DX12pÌ_OæÊðZbg
	in_set_rendering_screen.reset(dx12_rendering_screen);
	return true;
}


//===============//
// Ú×   F_OæÊðNA·é
// ø   Funique_ptr<C_Rendering_Screen_Data_Base> & NA·é_OæÊÔ, S_Create_Render_Screen_Inform & NA·é_OæÊVXeÌQÆiconstj
// ßèl Fbool ¬÷ÌÝtrue
//===============//
void C_DX12_System::M_Clear_Rendering_Screen(int in_rendering_screen_number, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & in_rendering_screen) const
{
	//  Ïé¾  //
	DX12_INSTANCE::C_DX12_Rendering_Screen_System * dx12_rendering_screen = reinterpret_cast<DX12_INSTANCE::C_DX12_Rendering_Screen_System*>(in_rendering_screen.get());   // _OæÊîñðDX12pÖLXgµ½ÊÌAhX


	// _OæÊð_OæÆµÄZbg
	M_Clear_Render_Target_View(in_rendering_screen_number, dx12_rendering_screen->m_render_target_view);

	return;
}


//===============//
// Ú×   F_OæÊð`ææÆµÄZbg·é
// ø   Funique_ptr<C_Rendering_Screen_Data_Base> & ÝèæÌ_OæÊÌQÆ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Set_Rendering_Screen_To_Render_Target(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & in_rendering_screen)
{
	//  Ïé¾  //
	DX12_INSTANCE::C_DX12_Rendering_Screen_System * dx12_rendering_screen = reinterpret_cast<DX12_INSTANCE::C_DX12_Rendering_Screen_System*>(in_rendering_screen.get());   // _OæÊîñðDX12pÖLXgµ½ÊÌAhX


	// _OæÊð_OæÆµÄZbg
	M_Set_Render_Target_View(dx12_rendering_screen);

	return;
}


//===============//
// Ú×   F_OæÊðwè³ê½eNX`ÌXbgÉZbg·é
// ø   Fint _OæÊÔ, int ÝèæÌeNX`ÌXbgÔ, unique_ptr<C_Rendering_Screen_Data_Base> & _OæÊVXeÌQÆ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Set_Rendering_Screen_To_Texture_Slot(int in_rendering_screen_number, int in_texture_slot_number, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & in_rendering_screen)
{
	//  Ïé¾  //
	DX12_INSTANCE::C_DX12_Rendering_Screen_System * dx12_rendering_screen = reinterpret_cast<DX12_INSTANCE::C_DX12_Rendering_Screen_System*>(in_rendering_screen.get());   // _OæÊîñðDX12pÖLXgµ½ÊÌAhX

	D3D12_GPU_DESCRIPTOR_HANDLE descriptor_handle = dx12_rendering_screen->m_render_target_view.heap->GetGPUDescriptorHandleForHeapStart();   // GPUÅÌ\[XÖÌnh

	UINT byte_of_handle = mpr_variable->s_frame_work.device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE::D3D12_DESCRIPTOR_HEAP_TYPE_RTV); // nhêÂªÉÎ·éoCg(AhX§äp)


	// _[^[Qbgr[ðVF[_[Ågp·éÝèÉÏX
	for (int l_now_screen_number = 0; l_now_screen_number < dx12_rendering_screen->m_rendering_screen_sum; l_now_screen_number++)
	{
		M_Set_Resource_Barrier(l_now_screen_number, dx12_rendering_screen->m_render_target_view, D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_ALL_SHADER_RESOURCE);
	}


	// eNX`pq[vÌZbg
	mpr_variable->s_command.list->SetDescriptorHeaps(1, &dx12_rendering_screen->m_render_target_view.heap);

	// wè³ê½_[^[Qbgr[ÜÅÚ®
	descriptor_handle.ptr += (UINT64)(byte_of_handle * (UINT)in_rendering_screen_number);

	// [gVOl`Éwè³ê½_[^[Qbgr[ðRt¯é
	mpr_variable->s_command.list->SetGraphicsRootDescriptorTable(in_texture_slot_number, descriptor_handle);

	return;
}


//===============//
// Ú×   F_OæÊÌf[^iæfzñjðæ¾Â\ÈóÔÉ·é
// ø   Fint Ýè·é_OæÊÔ, unique_ptr<C_Rendering_Screen_Data_Base> & _OæÊVXeÌQÆ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Set_Rendering_Screen_Can_Readable(int in_screen_number, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & in_rendering_screen)
{
	//  Ïé¾  //
	DX12_INSTANCE::C_DX12_Rendering_Screen_System * dx12_rendering_screen = reinterpret_cast<DX12_INSTANCE::C_DX12_Rendering_Screen_System*>(in_rendering_screen.get());   // _OæÊîñðDX12pÖLXgµ½ÊÌAhX


	M_Set_Resource_Barrier(in_screen_number, dx12_rendering_screen->m_render_target_view, D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_GENERIC_READ);

	return;
}


//===============//
// Ú×   FCÌ_OæÊÉß·
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_DX12_System::M_Set_Main_Rendering_Screen_To_Rendering(void)
{
	M_Set_Render_Target_View_By_Screen_Number(mpr_variable->s_command.num_back_screen, mpr_variable->s_render.main_rendering_screen->m_render_target_view);

	return;
}


//===============//
// Ú×   FCÌ\¦Ì_OæÊðwè³ê½eNX`XbgÉZbg·é
// ø   Fint ÝèæÌeNX`ÌXbgÔ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Set_Main_Front_Rendering_Screen_To_Texture_Slot(int in_set_slot)
{
	//  Ïé¾  //
	D3D12_GPU_DESCRIPTOR_HANDLE descriptor_handle = mpr_variable->s_render.main_rendering_screen->m_render_target_view.heap->GetGPUDescriptorHandleForHeapStart();   // GPUÅÌ\[XÖÌnh

	UINT byte_of_handle = mpr_variable->s_frame_work.device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE::D3D12_DESCRIPTOR_HEAP_TYPE_RTV); // nhêÂªÉÎ·éoCg(AhX§äp)


	// _[^[Qbgr[ðVF[_[Ågp·éÝèÉÏX
	for (int l_now_screen_number = 0; l_now_screen_number < mpr_variable->s_render.main_rendering_screen->m_rendering_screen_sum; l_now_screen_number++)
	{
		M_Set_Resource_Barrier(l_now_screen_number, mpr_variable->s_render.main_rendering_screen->m_render_target_view, D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_ALL_SHADER_RESOURCE);
	}


	// eNX`pq[vÌZbg
	mpr_variable->s_command.list->SetDescriptorHeaps(1, &mpr_variable->s_render.main_rendering_screen->m_render_target_view.heap);

	// wè³ê½_[^[Qbgr[ÜÅÚ®
	descriptor_handle.ptr += UINT64(byte_of_handle * (UINT)mpr_variable->s_command.num_front_screen);

	// [gVOl`Éwè³ê½_[^[Qbgr[ðRt¯é
	mpr_variable->s_command.list->SetGraphicsRootDescriptorTable(in_set_slot, descriptor_handle);

	return;
}


//===============//
// Ú×   FCÌ`æ«ÝÌ_OæÊðwè³ê½eNX`XbgÉZbg·é
// ø   Fint ÝèæÌeNX`ÌXbgÔ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Set_Main_Back_Rendering_Screen_To_Texture_Slot(int in_set_slot)
{
	//  Ïé¾  //
	D3D12_GPU_DESCRIPTOR_HANDLE descriptor_handle = mpr_variable->s_render.main_rendering_screen->m_render_target_view.heap->GetGPUDescriptorHandleForHeapStart();   // GPUÅÌ\[XÖÌnh

	UINT byte_of_handle = mpr_variable->s_frame_work.device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE::D3D12_DESCRIPTOR_HEAP_TYPE_RTV); // nhêÂªÉÎ·éoCg(AhX§äp)


	// _[^[Qbgr[ðVF[_[Ågp·éÝèÉÏX
	for (int l_now_screen_number = 0; l_now_screen_number < mpr_variable->s_render.main_rendering_screen->m_rendering_screen_sum; l_now_screen_number++)
	{
		M_Set_Resource_Barrier(l_now_screen_number, mpr_variable->s_render.main_rendering_screen->m_render_target_view, D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_ALL_SHADER_RESOURCE);
	}


	// eNX`pq[vÌZbg
	mpr_variable->s_command.list->SetDescriptorHeaps(1, &mpr_variable->s_render.main_rendering_screen->m_render_target_view.heap);

	// wè³ê½_[^[Qbgr[ÜÅÚ®
	descriptor_handle.ptr += (UINT64)(byte_of_handle * (UINT)mpr_variable->s_command.num_back_screen);

	// [gVOl`Éwè³ê½_[^[Qbgr[ðRt¯é
	mpr_variable->s_command.list->SetGraphicsRootDescriptorTable(in_set_slot, descriptor_handle);

	return;
}


//===============//
// Ú×   FCÌ_OæÊÌf[^ðeNX`ÉÚ·
// ø   FC_Texture_Map & ÝèæÌeNX`ÌQÆ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Save_Main_Rendering_Screen_To_Texture(ASSET::TEXTURE::C_Texture_Map & out_texture) const
{
	//  Ïé¾  //
	D3D12_RESOURCE_STATES before_state = mpr_variable->s_render.main_rendering_screen->m_render_target_view.buffer_list[mpr_variable->s_command.num_back_screen].now_resource_barrier;   // ÏXOÌ\[XoAÌóÔðæ¾


	// _[^[Qbgr[ðÇÝæèÂ\ÉÝè
	M_Set_Resource_Barrier(mpr_variable->s_command.num_back_screen, mpr_variable->s_render.main_rendering_screen->m_render_target_view, D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_GENERIC_READ);
	
	// CÌ_OæÊÌf[^ðeNX`ÉÚ·
	mpr_variable->s_render.main_rendering_screen->M_Save_Screen_For_Texture(mpr_variable->s_command.num_back_screen, out_texture);

	// _[^[Qbgr[ð³ÌóÔÉß·
	M_Set_Resource_Barrier(mpr_variable->s_command.num_back_screen, mpr_variable->s_render.main_rendering_screen->m_render_target_view, before_state);

	return;
}


//===============//
// Ú×   Fwè³ê½_OæÊÌf[^ðeNX`ÉÚ·
// ø   Fint Ýè·é_OæÊÔ, unique_ptr<C_Rendering_Screen_Data_Base> & _OæÊVXeÌQÆ, C_Texture_Map & ÝèæÌeNX`ÌQÆ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Save_Rendering_Screen_To_Texture(int in_rendering_screen_number, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & in_rendering_screen, ASSET::TEXTURE::C_Texture_Map & out_texture) const
{
	//  Ïé¾  //
	DX12_INSTANCE::C_DX12_Rendering_Screen_System * dx12_rendering_screen = reinterpret_cast<DX12_INSTANCE::C_DX12_Rendering_Screen_System*>(in_rendering_screen.get());   // _OæÊîñðDX12pÖLXgµ½ÊÌAhX

	D3D12_RESOURCE_STATES before_state = dx12_rendering_screen->m_render_target_view.buffer_list[in_rendering_screen_number].now_resource_barrier;   // ÏXOÌ\[XoAÌóÔðæ¾


	// _[^[Qbgr[ðÇÝæèÂ\ÉÝè
	M_Set_Resource_Barrier(in_rendering_screen_number, dx12_rendering_screen->m_render_target_view, D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_GENERIC_READ);

	// CÌ_OæÊÌf[^ðeNX`ÉÚ·
	mpr_variable->s_render.main_rendering_screen->M_Save_Screen_For_Texture(in_rendering_screen_number, out_texture);

	// _[^[Qbgr[ð³ÌóÔÉß·
	M_Set_Resource_Barrier(in_rendering_screen_number, dx12_rendering_screen->m_render_target_view, before_state);

	return;
}


//===============//
// Ú×   F_OæÊÌíðÊm·é
// ø   Fconst C_Rendering_Screen_Data_Base * í³ê½_OæÊÌAhXiconstj
// ßèl Fvoid
//===============//
void C_DX12_System::M_Notice_Rendering_Screen_Deleted(const RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base * in_delete_rendering_screen)
{
	//  Ïé¾  //
	const DX12_INSTANCE::C_DX12_Rendering_Screen_System * dx12_rendering_screen = reinterpret_cast<const DX12_INSTANCE::C_DX12_Rendering_Screen_System * >(in_delete_rendering_screen);   // _OæÊîñðDX12pÖLXgµ½ÊÌAhX


	// SÄÌæÊªTõµAêv·éàÌª êÎCÌæÊÉß·
	for (const RENDERING::API::DX12::DX12_INSTANCE::S_DX12_Render_Target_Buffer & l_now_render_target : dx12_rendering_screen->m_render_target_view.buffer_list)
	{
		if (mpr_variable->s_render.now_screen_address_handle == &l_now_render_target.handle)
		{
			M_Set_Main_Rendering_Screen_To_Rendering();
		}
	}

	return;
}


//-- [xXeVobt@ --//

//===============//
// Ú×   F[xXeVobt@ð¶¬·é
// ø   Funique_ptr<C_Rendering_Depth_Stencil_Buffer_Base> & ¶¬æÌ[xXeVobt@ÌQÆ, const S_Create_Depth_Stencil_Buffer_Inform & [xXeVobt@ð¶¬·é½ßÌîñÌQÆiconstj
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_DX12_System::M_Create_Depth_Stencil_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & in_depth_stencil_screen, const RENDERING::API::CREATE::S_Create_Depth_Stencil_Buffer_Inform & in_create_system) const
{
	//  Ïé¾  //
	DX12_INSTANCE::C_DX12_Depth_Stencil_Buffer_System * dx12_depth_stencil_screen = new DX12_INSTANCE::C_DX12_Depth_Stencil_Buffer_System(); // DX12pÌ[xXeVobt@


	// [xXeVobt@ð¶¬·éA¸sµ½çG[Å²¯é
	if (M_Create_Depth_Stencil_View_Descriptor_Heap(dx12_depth_stencil_screen, in_create_system) == false)
	{
		return false;
	}

	// Vµ¢[xXeVobt@ÉüêÖ¦é
	in_depth_stencil_screen.reset(dx12_depth_stencil_screen);
	return true;
}


//===============//
// Ú×   F[xXeVobt@ðNA·é
// ø   Funique_ptr<C_Rendering_Depth_Stencil_Buffer_Base> & NA·é[xXeVobt@ÌQÆ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Clear_Depth_Stencil_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & in_clear_depth_stencil_buffer) const
{
	//  Ïé¾  //
	DX12_INSTANCE::C_DX12_Depth_Stencil_Buffer_System * dx12_depth_stencil_screen = reinterpret_cast<DX12_INSTANCE::C_DX12_Depth_Stencil_Buffer_System * >(in_clear_depth_stencil_buffer.get()); // DX12pÌ[xXeVobt@


	// [xXeVobt@ðNA·é
	M_Clear_Depth_Stencil_View_Buffer(dx12_depth_stencil_screen->m_data);

	return;
}


//===============//
// Ú×   F[xXeVobt@ð`æpÉZbg·é
// ø   Funique_ptr<C_Rendering_Depth_Stencil_Buffer_Base> & Ýè·é[xXeVobt@ÌQÆ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Set_Depth_Stencil_Buffer_To_Rendering(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base>& in_depth_stencil)
{
	//  Ïé¾  //
	DX12_INSTANCE::C_DX12_Depth_Stencil_Buffer_System* dx12_depth_stencil_screen = reinterpret_cast<DX12_INSTANCE::C_DX12_Depth_Stencil_Buffer_System*>(in_depth_stencil.get()); // DX12pÌ[xXeVobt@


	// [xXeVobt@ðZbg·é
	M_Set_Depth_Stencil_View(dx12_depth_stencil_screen->m_data);

	return;
}


//===============//
// Ú×   F[xXeVobt@ðGPUp\[XÌeNX`XbgÉZbg
// ø   Fint ÝèæÌXbgÔ, unique_ptr<C_Rendering_Depth_Stencil_Buffer_Base> & Ýè·é[xXeVobt@ÌQÆ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Set_Depth_Stencil_Buffer_To_Texture_Slot(int in_texture_slot, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & in_depth_stencil)
{
	//  Ïé¾  //
	DX12_INSTANCE::C_DX12_Depth_Stencil_Buffer_System * dx12_depth_stencil_screen = reinterpret_cast<DX12_INSTANCE::C_DX12_Depth_Stencil_Buffer_System*>(in_depth_stencil.get()); // DX12pÌ[xXeVobt@


	// eNX`pq[vÌZbg
	mpr_variable->s_command.list->SetDescriptorHeaps(1, &dx12_depth_stencil_screen->m_data.heap);

	// [gVOl`ÉeNX`ðRt¯é
	mpr_variable->s_command.list->SetGraphicsRootDescriptorTable(in_texture_slot, dx12_depth_stencil_screen->m_data.heap->GetGPUDescriptorHandleForHeapStart());
	
	return;
}


//===============//
// Ú×   F[xXeVobt@ÌíðÊm·é
// ø   Fconst C_Rendering_Depth_Stencil_Buffer_Base * í³ê½[xXeVobt@ÌAhXiconstj
// ßèl Fvoid
//===============//
void C_DX12_System::M_Notice_Depth_Stencil_Buffer_Deleted(const RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base * in_deleted_depth_stencil_buffer)
{
	//  Ïé¾  //
	const DX12_INSTANCE::C_DX12_Depth_Stencil_Buffer_System * dx12_depth_stencil_screen = reinterpret_cast<const DX12_INSTANCE::C_DX12_Depth_Stencil_Buffer_System*>(in_deleted_depth_stencil_buffer); // DX12pÌ[xXeVobt@


	// »ÝgpÌ[xXeVobt@ªí³ê½êÍCÉß·
	if (mpr_variable->s_render.now_depth_stencil_address_handle == &dx12_depth_stencil_screen->m_data.handle)
	{
		M_Reset_Depth_Stencil_Buffer();
	}

	return;
}


//===============//
// Ú×   F[xXeVobt@ðZbg·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_DX12_System::M_Reset_Depth_Stencil_Buffer(void)
{
	mpr_variable->s_command.list->OMSetRenderTargets(mpr_variable->s_render.now_rendering_screen_sum, mpr_variable->s_render.now_screen_address_handle, TRUE, nullptr);
	mpr_variable->s_render.now_depth_stencil_address_handle = nullptr;

	return;
}


//-- ¸_obt@ --//

//===============//
// Ú×   Fwè³ê½îñð³É¸_f[^ð¶¬·é
// ø   Funique_ptr<C_Vertex_Buffer_Setting_Inform_Base> & ZbgæÌ¸_f[^, const C_Create_Vertex_Buffer_Inform & ¸_f[^¶¬pîñ(const)
// ßèl Fvoid
//===============//
void C_DX12_System::M_Create_Vertex_Inform(std::unique_ptr<INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base>& in_set_to, const CREATE::S_Create_Vertex_Buffer_Inform& in_create_inform) const
{
	//  Ïé¾  //
	DX12_INSTANCE::C_DX12_Vertex_Setting_Inform * dx12_vertex_inform = new DX12_INSTANCE::C_DX12_Vertex_Setting_Inform();   // DX12pÌ¸_pîñ


	// f[^ðZbg
	in_set_to.reset(dx12_vertex_inform);


	// ¸_obt@ð¶¬
	M_Create_Vertex_Buffer(dx12_vertex_inform, in_create_inform);

	return;
}


//===============//
// Ú×   F¸_obt@ðZbg·é
// ø   Fconst unique_ptr<C_Vertex_Buffer_Setting_Inform_Base> & Zbg·é¸_f[^(const)
// ßèl Fvoid
//===============//
void C_DX12_System::M_Set_Vertex_Buffer(const std::unique_ptr<INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base>& in_vertex_inform)
{
	//  Ïé¾  //
	const DX12_INSTANCE::C_DX12_Vertex_Setting_Inform * dx12_vertex_inform = reinterpret_cast<const DX12_INSTANCE::C_DX12_Vertex_Setting_Inform*> (in_vertex_inform.get());   // ¸_pîñðDX12pÖLXgµ½ÊÌAhX


	// ¸_obt@ðZbg·é
	mpr_variable->s_command.list->IASetVertexBuffers(0, 1, &dx12_vertex_inform->m_vertex_buffer_view);

	return;
}


//===============//
// Ú×   F¸_obt@ð³É`æðÀs·é
// ø   Fconst unique_ptr<C_Vertex_Buffer_Setting_Inform_Base> & `æ·é¸_f[^(const)
// ßèl Fvoid
//===============//
void C_DX12_System::M_Draw_Command_By_Vertex_Buffer(const std::unique_ptr<INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & in_draw_vertex)
{
	//  Ïé¾  //
	const DX12_INSTANCE::C_DX12_Vertex_Setting_Inform * dx12_vertex_inform = reinterpret_cast<const DX12_INSTANCE::C_DX12_Vertex_Setting_Inform*> (in_draw_vertex.get());   // ¸_pîñðDX12pÖLXgµ½ÊÌAhX


	// `æðÀs·é
	mpr_variable->s_command.list->IASetVertexBuffers(0, 1, &dx12_vertex_inform->m_vertex_buffer_view);
	mpr_variable->s_command.list->DrawInstanced(dx12_vertex_inform->m_vertex_sum, 1, 0, 0);
	
	return;
}


//-- ¸_CfbNX --//

//===============//
// Ú×   Fwè³ê½îñð³ÉCfbNXf[^ð¶¬·é
// ø   Funique_ptr<C_Rendering_Index_Buffer_Setting_Inform_Base> & ÝèæÌCfbNXîñ, const S_Create_Index_Buffer_Inform & ¶¬pÌîñ(const)
// ßèl Fvoid
//===============//
void C_DX12_System::M_Create_Index_Inform(std::unique_ptr<INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & in_index_data, const CREATE::S_Create_Index_Buffer_Inform & in_create_inform) const
{
	//  Ïé¾  //
	DX12_INSTANCE::C_DX12_Index_Setting_Inform * dx12_index_inform = new DX12_INSTANCE::C_DX12_Index_Setting_Inform();   // DX12pÌCfbNXpîñ


	// ¸_CfbNXobt@ð¶¬
	M_Create_Index_Buffer(dx12_index_inform, in_create_inform);

	// f[^ðZbg
	in_index_data.reset(dx12_index_inform);

	return;
}


//===============//
// Ú×   FCfbNXobt@ð³É`æðs¤
// ø   Funique_ptr<C_Rendering_Index_Buffer_Setting_Inform_Base> & CfbNXf[^Ýèpîñ(const)
// ßèl Fvoid
//===============//
void C_DX12_System::M_Draw_Command_By_Index_Buffer(const std::unique_ptr<INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & in_draw_index)
{
	//  Ïé¾  //
	const DX12_INSTANCE::C_DX12_Index_Setting_Inform * dx12_index_inform = reinterpret_cast<const DX12_INSTANCE::C_DX12_Index_Setting_Inform * >(in_draw_index.get());   // CfbNXpîñðDX12pÖLXgµ½ÊÌAhX


	// `æðÀs·é
	mpr_variable->s_command.list->IASetIndexBuffer(&dx12_index_inform->m_index_buffer_view);
	mpr_variable->s_command.list->DrawIndexedInstanced(dx12_index_inform->m_index_sum, 1, 0, 0, 0);

	return;
}


//===============//
// Ú×   FCfbNXobt@ð³Éwè³ê½CfbNXÔÌ`æðs¤
// ø   Funique_ptr<C_Rendering_Index_Buffer_Setting_Inform_Base> & CfbNXf[^Ýèpîñ(const), int `æðJn·éCfbNXÔ, int `æI¹ÌCfbNXÔ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Draw_Command_By_Index_Buffer_By_Range(const std::unique_ptr<INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & in_index_data, int in_index_draw_start, int in_index_draw_end)
{
	//  Ïé¾  //
	const DX12_INSTANCE::C_DX12_Index_Setting_Inform * dx12_index_inform = reinterpret_cast<const DX12_INSTANCE::C_DX12_Index_Setting_Inform * >(in_index_data.get());   // CfbNXpîñðDX12pÖLXgµ½ÊÌAhX


	// `æðÀs·é
	mpr_variable->s_command.list->IASetIndexBuffer(&dx12_index_inform->m_index_buffer_view);
	mpr_variable->s_command.list->DrawIndexedInstanced(in_index_draw_end - in_index_draw_start, 1, in_index_draw_start, 0, 0);

	return;
}


//===============//
// Ú×   F¸_CfbNXobt@ðZbg·é
// ø   Funique_ptr<C_Rendering_Index_Buffer_Setting_Inform_Base> & ¸_CfbNXf[^Ýèpîñ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Set_Index_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & in_set_index_inform)
{
	//  Ïé¾  //
	const DX12_INSTANCE::C_DX12_Index_Setting_Inform * dx12_index_inform = reinterpret_cast<const DX12_INSTANCE::C_DX12_Index_Setting_Inform * >(in_set_index_inform.get());   // CfbNXpîñðDX12pÖLXgµ½ÊÌAhX


	// CfbNXobt@ðZbg·é
	mpr_variable->s_command.list->IASetIndexBuffer(&dx12_index_inform->m_index_buffer_view);
	mpr_variable->s_command.was_setting_vertex_index_sum = dx12_index_inform->m_index_sum;

	return;
}


//===============//
// Ú×   FZbg³ê½¸_CfbNXobt@ð³É`æðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_DX12_System::M_Draw_Command_By_Set_Index_Buffer(void)
{
	mpr_variable->s_command.list->DrawIndexedInstanced(mpr_variable->s_command.was_setting_vertex_index_sum, 1, 0, 0, 0);

	return;
}


//===============//
// Ú×   FZbg³ê½¸_CfbNXobt@ð³Éwè³ê½CfbNXÔÌ`æðs¤
// ø   Fint `æðJn·éCfbNXÔ, int `æI¹ÌCfbNXÔ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Draw_Command_By_Set_Index_Buffer_By_Range(int in_start_index_number, int in_end_index_number)
{
	mpr_variable->s_command.list->DrawIndexedInstanced(in_end_index_number - in_start_index_number, 1, in_start_index_number, 0, 0);

	return;
}


//-- èobt@ --//

//===============//
// Ú×   Fwè³ê½îñð³Éèf[^ð¶¬·é
// ø   Funique_ptr<C_Constant_Buffer_Setting_Inform_Base> & ZbgæÌèf[^, const C_Create_Constant_Buffer_Inform & èf[^¶¬pîñ(const)
// ßèl Fvoid
//===============//
void C_DX12_System::M_Create_Constant_Inform(std::unique_ptr<INSTANCE::C_Rendering_Constant_Buffer_Setting_Inform_Base> & in_constant_inform, const CREATE::S_Create_Constant_Buffer_Inform & in_create_inform) const
{
	//  Ïé¾  //
	DX12_INSTANCE::C_DX12_Constant_Setting_Inform* dx12_constant_inform = new DX12_INSTANCE::C_DX12_Constant_Setting_Inform();   // DX12pÌèpîñ


	//  èobt@Ìq[vð¶¬  //
	M_Create_Constant_Heap(dx12_constant_inform, in_create_inform);

	//  èobt@Ìf[^ð¶¬  //
	M_Create_Constant_Resource(dx12_constant_inform, in_create_inform);


	// f[^ðZbg
	in_constant_inform.reset(dx12_constant_inform);

	return;
}


//===============//
// Ú×   Fèf[^ðZbg·é
// ø   FS_Constant_Buffer_Drawing_Setting & Zbg·éèf[^îñ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Rendering_Set_Constant_Buffer(INSTANCE::S_Constant_Buffer_Drawing_Setting & in_constant_inform)
{
	//  Ïé¾  //
	DX12_INSTANCE::C_DX12_Constant_Setting_Inform * dx12_constant_inform = reinterpret_cast<DX12_INSTANCE::C_DX12_Constant_Setting_Inform * >(in_constant_inform.add_constant_buffer);   // `æpîñðDX12pÖLXgµ½ÊÌAhX

	int slot_number = 0;    // èobt@ÝèæÌXbgÔ

	bool flg_slot_exist = false;    // Xbgð­©Å«½©Ç¤©ÌtO


	// èobt@Ì\[XðTõµA©Â©Á½çXbgÔðwè
	for (const ASSET::SHADER::S_Constant_Resource_Inform & l_constant_list : mpr_variable->shader_resource_list->constant_list)
	{
		// VF[_[ÌíÞÆ\[X¼ªêvµ½çXbgÔðæ¾µA­©ÌtOð§Äé
		if (l_constant_list.shader_kind == in_constant_inform.add_attach_shader_kind)
		{
			if (l_constant_list.resource_name == *in_constant_inform.add_signature_name)
			{
				flg_slot_exist = true;
				slot_number = l_constant_list.slot_number;
				break;
			}
		}
	}


	// XbgªÝÂ©çÈ©Á½ç²¯é
	if (flg_slot_exist == false)
	{
		return;
	}


	// èobt@pq[vÌZbg
	mpr_variable->s_command.list->SetDescriptorHeaps(1, &dx12_constant_inform->m_constant_buffer_heap);

	// [gVOl`Éèobt@ðRt¯é
	mpr_variable->s_command.list->SetGraphicsRootDescriptorTable(slot_number, dx12_constant_inform->m_constant_buffer_heap->GetGPUDescriptorHandleForHeapStart());

	return;
}


//===============//
// Ú×   Fwè³ê½CfbNXÔÌXbgÉèf[^ðZbg·é
// ø   Funique_ptr<C_Constant_Buffer_Setting_Inform_Base> & èobt@f[^, int ZbgæÌCfbNXÔ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Rendering_Set_Constant_Buffer_By_Index(std::unique_ptr<INSTANCE::C_Rendering_Constant_Buffer_Setting_Inform_Base> & in_constant_buffer, int in_set_index_slot_num)
{
	//  Ïé¾  //
	DX12::DX12_INSTANCE::C_DX12_Constant_Setting_Inform * dx12_constant_buffer = reinterpret_cast<DX12::DX12_INSTANCE::C_DX12_Constant_Setting_Inform * >(in_constant_buffer.get());    // èobt@îñðDX12pÖLXgµ½ÊÌAhX


	// èobt@pq[vÌZbg
	mpr_variable->s_command.list->SetDescriptorHeaps(1, &dx12_constant_buffer->m_constant_buffer_heap);

	// [gVOl`Éèobt@ðRt¯é
	mpr_variable->s_command.list->SetGraphicsRootDescriptorTable(in_set_index_slot_num, dx12_constant_buffer->m_constant_buffer_heap->GetGPUDescriptorHandleForHeapStart());

	return;
}


//-- eNX` --//

//===============//
// Ú×   FeNX`pÌîñð¶¬·é
// ø   Funique_ptr<C_Rendering_Texture_Setting_Inform_Base> & ÝèæÌpCvCîñ, const C_Create_Texture_Setting_Inform & ¶¬pÌîñ(const)
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_DX12_System::M_Create_Texture_Inform(std::unique_ptr<INSTANCE::C_Rendering_Texture_Setting_Inform_Base> & in_texture_inform, const CREATE::S_Create_Texture_Setting_Inform & in_create_inform) const
{
	//  Ïé¾  //
	DX12_INSTANCE::C_DX12_Rendering_Texture_Setting_Inform* dx12_texture_inform = new DX12_INSTANCE::C_DX12_Rendering_Texture_Setting_Inform(); // DX12pÌ`æpîñ


	//  eNX`pf[^Ì¶¬  //@// ¸sµ½çG[Å²¯é
	if (M_Create_Texture_Resource(dx12_texture_inform, in_create_inform) == false)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "eNX`q[vÌ¶¬É¸s");
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}


	//  q[vð¶¬  //
	M_Create_Texture_Resource_View_And_Heap(dx12_texture_inform, in_create_inform);


	// f[^ðZbg
	in_texture_inform.reset(dx12_texture_inform);


	// eNX`pf[^Ì¶¬Ì¬÷ðm
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "eNX`pf[^Ì¶¬É¬÷");

	return true;
}


//===============//
// Ú×   FeNX`f[^ðZbg·é
// ø   FS_Texture_Buffer_Drawing_Setting & Zbg·éeNX`f[^îñ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Rendering_Set_Texture(INSTANCE::S_Texture_Buffer_Drawing_Setting & in_texture_inform)
{
	//  Ïé¾  //
	DX12_INSTANCE::C_DX12_Rendering_Texture_Setting_Inform * dx12_texture_inform = reinterpret_cast<DX12_INSTANCE::C_DX12_Rendering_Texture_Setting_Inform*>(in_texture_inform.add_texture_data); // `æpîñðDX12pÖLXgµ½ÊÌAhX

	int slot_number = 0;    // eNX`f[^ÝèæÌXbgÔ

	bool flg_slot_exist = false;    // Xbgð­©Å«½©Ç¤©ÌtO


	// eNX`obt@Ì\[XðTõµA©Â©Á½çXbgÔðwè
	for (const ASSET::SHADER::S_Texture_Resource_Inform & l_texture_list : mpr_variable->shader_resource_list->texture_list)
	{
		// VF[_[ÌíÞÆ\[X¼ªêvµ½çXbgÔðæ¾µA­©ÌtOð§Äé
		if (l_texture_list.shader_kind == in_texture_inform.attach_shader_kind)
		{
			if (l_texture_list.resource_name == *in_texture_inform.add_signature_name)
			{
				flg_slot_exist = true;
				slot_number = l_texture_list.slot_number;
				break;
			}
		}
	}


	// XbgªÝÂ©çÈ©Á½ç²¯é
	if (flg_slot_exist == false)
	{
		return;
	}


	// eNX`ÌÇpÌØ\¢ðZbg·é
	mpr_variable->s_command.list->SetDescriptorHeaps(1, &dx12_texture_inform->m_texture_heap);

	// [gVOl`ÆeNX`pÌf[^ðRÃ¯é
	mpr_variable->s_command.list->SetGraphicsRootDescriptorTable(slot_number, dx12_texture_inform->m_texture_heap->GetGPUDescriptorHandleForHeapStart());

	return;
}


//===============//
// Ú×   Fwè³ê½CfbNXÔÌXbgÉeNX`Ìf[^ðZbg·é
// ø   Funique_ptr<C_Rendering_Texture_Setting_Inform_Base> & eNX`f[^, int ZbgæÌCfbNXÔ
// ßèl Fvoid
//===============//
void C_DX12_System::M_Rendering_Set_Texture_By_Index(std::unique_ptr<INSTANCE::C_Rendering_Texture_Setting_Inform_Base> & in_texture, int in_set_index_slot_num)
{
	//  Ïé¾  //
	DX12::DX12_INSTANCE::C_DX12_Rendering_Texture_Setting_Inform * dx12_texture = reinterpret_cast<DX12::DX12_INSTANCE::C_DX12_Rendering_Texture_Setting_Inform * >(in_texture.get());    // eNX`îñðDX12pÖLXgµ½ÊÌAhX


	// eNX`pq[vÌZbg
	mpr_variable->s_command.list->SetDescriptorHeaps(1, &dx12_texture->m_texture_heap);

	// [gVOl`ÉeNX`ðRt¯é
	mpr_variable->s_command.list->SetGraphicsRootDescriptorTable(in_set_index_slot_num, dx12_texture->m_texture_heap->GetGPUDescriptorHandleForHeapStart());

	return;
}


//-- tHg --//

//===============//
// Ú×   FtHgðtHg¼ð³É[h·é
// ø   Funique_ptr<C_Rendering_Font_Inform_Base> & ÝèæÌtHgîñp[^, const C_Create_Font_Data_Inform & ¶¬pÌîñ(const)
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_DX12_System::M_Create_Font_Data(std::unique_ptr<INSTANCE::C_Rendering_Font_Inform_Base> & in_font_data, const CREATE::S_Create_Font_Data_Inform & in_create_inform) const
{
	//  Ïé¾  //
	HFONT handle_font = NULL;   // tHgÌnh

	LOGFONTW log_font_data =  // tHgÝèpÌf[^
	{
		//-- TCYâ`óÌÝè --// 
		in_create_inform.m_height,   // tHgÌZâ¶Ì³
		0,                          // tHgÌ¶Ì
		0,                          // ¶ðX¯éûü
		0,                          // î{üÆä×½Æ«Ì²ÅÌpx
		0,                          // tHgÌ¾³ÌÝèiOÅftHgj

		//-- ÌÌÝè --//
		FALSE,              // ÎÌtHg©Ç¤©ÌtO
		FALSE,              // ºüt«tHg©Ç¤©ÌtO
		FALSE,              // æèÁµüt«tHg©Ç¤©ÌtO
		SHIFTJIS_CHARSET,   // ¶ZbgÌíÞ

		//-- ¸xÌÝè --//
		OUT_TT_ONLY_PRECIS,         // tHgÌ¸xi¡ÜÅÌÝèÉÇê¾¯ÀÈÊÉÈé©j
		CLIP_DEFAULT_PRECIS,        // NbsOÌ¸x
		PROOF_QUALITY,              // oÍÌi¿
		DEFAULT_PITCH | FF_MODERN,  // tHgÌsb`Æt@~(tHgÌfUCû@Ìè`)

		// tHg¼
		(WCHAR)*in_create_inform.m_font_name.data()
	};

	// tHgÌnhðÇÝÞ
	handle_font = CreateFontIndirectW(&log_font_data);
	

	// tHgnhÌæ¾É¸sµ½çG[ð¦µÄ²¯é
	if (handle_font == NULL)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Text_Color(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, "tHgnhÌ¶¬É¸s", "DX12_FONT_SYSTEM");
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}


	// eXgÍ®¹µ½ÌÅ»óÅKvÌÈ¢f[^Íí
	DeleteObject(handle_font);
	handle_font = NULL;


	//-- ¬÷µÄ¢½ço^ --//

	//  Ïé¾  //
	DX12_INSTANCE::C_DX12_Font_Data_Set * new_font_data_handler = new DX12_INSTANCE::C_DX12_Font_Data_Set();   // Vµ¢tHgf[^pÌÝè


	// tHg¼
	new_font_data_handler->m_log_font = log_font_data;


	//-- o^ --//
	in_font_data.reset(new_font_data_handler);

	return true;
}


//===============//
// Ú×   Fn³ê½îñð³É¶ð}bvÉZbg·é
// ø   FS_Make_Font_To_Graph_Package & tHg©çæðìé½ßÌpbP[Wîñ
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_DX12_System::M_Set_Font_To_Texture_Map(PAKAGE::FONT::S_Make_Font_To_Graph_Package & in_set_inform) const
{
	//  è  //
	constexpr MAT2 texture_uv_setting_mat = { {0,1},{0,0},{0,0},{0,1} };   // eNX`ÀWwèpÌñ³zñR[h


	//  Ïé¾  //
	DX12_INSTANCE::C_DX12_Font_Data_Set * dx12_font_data = reinterpret_cast<DX12_INSTANCE::C_DX12_Font_Data_Set * >(in_set_inform.attach_font_data->get());   // cwPQptHgf[^ÖÌÏ·

	HFONT handle_font = NULL;   // tHgÌnh


	// tHgÌnhðÇÝÞ
	handle_font = CreateFontIndirectW(&dx12_font_data->m_log_font);


	// tHgnhÌæ¾É¸sµ½çG[ð¦µÄ²¯é
	if (handle_font == NULL)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Text_Color(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, "DX12_FONT_SYSTEM", "tHgÌ¶¬É¸sAàµ­ÍtHgîñªÝè³êÄ¢È¢½ßA±ÌtHgîñðgp·éÍÅ«Ü¹ñÅµ½");
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}


	//  Ïé¾  //
	HDC handle_device_context = GetDC(NULL);   // EBhEÌfoCXReLXg

	TEXTMETRIC txt_met;  // eLXgÌÝè

	HFONT old_font_handle = NULL;  // ±ÌtHgf[^ðKp·éOÉÝè³êÄ¢½nh

	int FLG_GRAY_SETTING = GGO_GRAY4_BITMAP;  // rbg}bvÌæ~²wèpÌtO

	int num_grad = 0;   // K²ÌÅål


	// tHgÌæ¾
	old_font_handle = (HFONT)SelectObject(handle_device_context, handle_font);


	//  rbg}bvÌæ~²Ìxðwè  //
	switch (in_set_inform.bit_map_level)
	{
		// 0~4
	case PAKAGE::FONT::E_FONTBIT_MAP_LEVEL::e_4:
		FLG_GRAY_SETTING = GGO_GRAY2_BITMAP;
		num_grad = 4;
		break;

		// 0~16
	case PAKAGE::FONT::E_FONTBIT_MAP_LEVEL::e_16:
		FLG_GRAY_SETTING = GGO_GRAY4_BITMAP;
		num_grad = 16;
		break;

		// 0~64
	case PAKAGE::FONT::E_FONTBIT_MAP_LEVEL::e_64:
		FLG_GRAY_SETTING = GGO_GRAY8_BITMAP;
		num_grad = 64;
		break;
	}   // * 0`num_gradÉwèµ½lÌÔÅFÌîñðæ¾Å«é
	
	// eLXgÝèðEBhEÌReLXg©çæ¾
	GetTextMetrics(handle_device_context, &txt_met);

	
	//  Ïé¾  //
	GLYPHMETRICS glyph_met;    // tHgpÌÝè
	
	DWORD font_map_size = 0; // rbg}bvÌTCY
	
	// rbg}bvTCYðæ¾
	font_map_size = GetGlyphOutlineW(handle_device_context, (UINT)in_set_inform.text_code, FLG_GRAY_SETTING, &glyph_met, 0, NULL, &texture_uv_setting_mat);

	std::vector<DWORD> font_texture_data;    // tHg©çæ¾µ½æîñ


	// }bvÌæ¾
	font_texture_data.resize(font_map_size);
	GetGlyphOutlineW(handle_device_context, (UINT)in_set_inform.text_code, FLG_GRAY_SETTING, &glyph_met, font_map_size, &font_texture_data[0], &texture_uv_setting_mat);
	

	//  Ïé¾  //
	DATA::COLOR::C_Color set_color(1.0f, 1.0f, 1.0f, 0.0f); // Ýè·éF
	
	int font_map_start_x = glyph_met.gmptGlyphOrigin.x; // ûüÅÌtHgÌJnrbgÔ
	int font_map_start_y = txt_met.tmAscent - glyph_met.gmptGlyphOrigin.y;  // ûüÅÌtHgÌJnrbgÔ

	int font_size_x = (glyph_met.gmBlackBoxX + (4 - (glyph_met.gmBlackBoxX % 4)) % 4);    // ûüÅÌtHgÌrbgiSÅÁÄéÌÍlÂ¡ÉÀ×Än³êé½ßj
	int font_size_y = glyph_met.gmBlackBoxY;    // ûüÅÌtHgÌrbg

	int map_x_size = in_set_inform.draw_rect.right_x - in_set_inform.draw_rect.left_x + 1; // ¡ûüÅÌ}bvÉ«Þå«³
	int map_y_size = in_set_inform.draw_rect.top_y - in_set_inform.draw_rect.bottom_y + 1; // cûüÅÌ}bvÉ«Þå«³


	int map_write_start_x = (int)(((float)font_map_start_x / ((float)font_size_x + (float)font_map_start_x)) * (float)map_x_size); // }bvÉ«ÞÆ«ÌÅÌJnÀW
	int map_write_start_y = (int)(((float)font_map_start_y / ((float)font_size_y + (float)font_map_start_y)) * (float)map_y_size); // }bvÉ«ÞÆ«ÌÅÌJnÀW


	// çêÄ­éæð}bvÉí¹é½ßÌ²®
	font_size_x /= 4;
	map_x_size -= map_write_start_x;
	map_y_size -= map_write_start_y;


	float font_size_x_by_map_x_size = (float)font_size_x / (float)map_x_size;   // ÅÌtHg}bvÉKp·é½ßÌ{¦
	float font_size_y_by_map_y_size = (float)font_size_y / (float)map_y_size;   // ÅÌtHg}bvÉKp·é½ßÌ{¦


	// eNX`pÌ}bvðmÛ·é
	in_set_inform.tex_map_data->M_Map_Variable_Size_Change(in_set_inform.draw_rect.right_x, in_set_inform.draw_rect.top_y);


	// C³ªKvÈ¶ÍC³ðÁ¦éiLÈÇj
	switch (in_set_inform.text_code)
	{
		// nCtÍºÉÀ×çêéÌÅãÉ °éATCYàù³·é
	case L'-':
		map_write_start_y /= 2;
		map_x_size /= 2;
		map_write_start_x = (in_set_inform.draw_rect.right_x - in_set_inform.draw_rect.left_x) / 3;
		break;

		// LÎµ_ÍºÉÀ×çêéÌÅãÉ °é
	case L'[':
		map_write_start_y /= 2;
		break;
	}


	// cÌsNZªÌ[v
	for (int l_y_now_pix = 0; l_y_now_pix < map_y_size; l_y_now_pix++)
	{
		//  Ïé¾  //
		int now_data_y_element = (int)(l_y_now_pix * font_size_y_by_map_y_size);  // »Ýæèo·f[^ÌÀWªÌvf
		
		now_data_y_element =
			(now_data_y_element >= (font_size_y - 1)) * (font_size_y - 1)
			+
			(now_data_y_element < (font_size_y - 1)) * now_data_y_element;

		now_data_y_element *= font_size_x;

		
		// ¡ÌsNZªÌ[v
		for (int l_x_now_pix = 0; l_x_now_pix < map_x_size; l_x_now_pix++)
		{
			//  Ïé¾  //
			int now_data_element = (int)(l_x_now_pix * font_size_x_by_map_x_size);  // »Ýæèo·f[^ÌvfÔ

			now_data_element =
				(now_data_element >= (font_size_x - 1)) * (font_size_x - 1)
				+
				(now_data_element < (font_size_x - 1)) * now_data_element;

			now_data_element += now_data_y_element;

			WORD now_color_data = (WORD)((font_texture_data[now_data_element] * 255) / num_grad);    // æèoµ½J[f[^


			// FÌZ³ªn³êé¾¯ÈÌÅ§¾xÌÝÝè·é
			set_color.m_a = (float)(now_color_data & 0x000000ff) / 255;
			in_set_inform.tex_map_data->M_Set_Color_At_Point(set_color, l_x_now_pix + in_set_inform.draw_rect.left_x + map_write_start_x, l_y_now_pix + in_set_inform.draw_rect.bottom_y + map_write_start_y);
		}
	}


	// gpÏÝÌ}bvf[^ððú
	font_texture_data.clear();
	font_texture_data.shrink_to_fit();


	// ³XÝè³êÄ¢½tHgÉß·
	SelectObject(handle_device_context, old_font_handle);

	//  ÀÌðú
	DeleteObject(handle_font);
	ReleaseDC(NULL, handle_device_context);

	return true;
}


//-- Qb^ --//

//===============//
// Ú×   F±Ì_OVXeÌVF[_[ÌtH_ÜÅÌpX
// ø   Fvoid
// ßèl Fstring VF[_[ÌtH_ÜÅÌpX
//===============//
std::string C_DX12_System::M_Get_Shader_Folder_Path(void) const
{
	return "project/asset/shader/compile/hlsl/dx12/";
}


//===============//
// Ú×   FDX12Ì_OVXeÌVF[_[Ìg£qðÔ·
// ø   Fvoid
// ßèl Fstring DX12ÅÌVF[_[Ìg£q
//===============//
std::string C_DX12_System::M_Get_Shader_Extension(void) const
{
	return ".cso";
}


//===============//
// Ú×   F_OVXeªI¹µÄ¢é©Ç¤©ÌtOðÔ·
// ø   Fvoid
// ßèl Fbool _OVXeªI¹µÄ¢é©Ç¤©ÌtO
//===============//
bool C_DX12_System::M_Get_End_Rendering_System(void) const
{
	return mpr_variable->flg_rendering_api_end;
}


//-- Zb^ --//

//===============//
// Ú×   FFf[^ðZbg·é
// ø   Fconst C_Color & Zbg·éFf[^(const)
// ßèl Fvoid
//===============//
void C_DX12_System::M_Set_Clear_Color(const DATA::COLOR::C_Color & in_set_color)
{
	mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_RED] = in_set_color.m_r;
	mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_GREEN] = in_set_color.m_g;
	mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_BLUE] = in_set_color.m_b;
	mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_ALPHA] = in_set_color.m_a;

	return;
}


//-- [h --//

//===============//
// Ú×   FeNX`ð[h·é
// ø   Fstring t@CÌpX, C_Texture_Map & eNX`}bvÌQÆ
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_DX12_System::M_Load_Texture(std::string in_file_path, ASSET::TEXTURE::C_Texture_Map & in_tex_map) const
{
	//  Ïé¾  //
	DirectX::TexMetadata file_metadata = {};     // eNX`Ì^f[^ðæ¾·é

	DirectX::ScratchImage scratch_img = {};  // æt@CÌÇÝæèÊ

	std::vector<wchar_t> w_file_path;  // t@CpXðwcharÉÏ·µ½Ê

	int file_path_size = (int)in_file_path.size();   // t@CpX¶


	// ChLÉÏ··é
	w_file_path.resize((size_t)(file_path_size + 1));
	for (int loop_x = 0; loop_x < file_path_size; loop_x++)
	{
		w_file_path[loop_x] = (wchar_t)in_file_path[loop_x];
	}
	w_file_path[file_path_size] = '\0';


	// t@CÌÇÝÝ    // ¸sµ½çG[Å²¯é
	if (FAILED(DirectX::LoadFromWICFile(&w_file_path[0], DirectX::WIC_FLAGS_NONE, &file_metadata, scratch_img)))
	{
		HRESULT result_error = DirectX::LoadFromWICFile(&w_file_path[0], DirectX::WIC_FLAGS_NONE, &file_metadata, scratch_img);

		w_file_path.clear();
		w_file_path.shrink_to_fit();
		return false;
	}
	w_file_path.clear();
	w_file_path.shrink_to_fit();


	//  Ïé¾  //
	const DirectX::Image * address_image = scratch_img.GetImage(0, 0, 0);   // æf[^ÌAhX
	

	// ÌmÛ
	in_tex_map.M_Delete_Map();
	in_tex_map.M_Map_Variable_Size_Change((int)address_image->width, (int)address_image->height);


	// sNZf[^ÌZbg
	for (int l_tex_y = 0; l_tex_y < (int)address_image->height; l_tex_y++)
	{
		//  Ïé¾  //
		int row_plus = l_tex_y * (int)address_image->width;	// ÝèÊuÌcñªÅ¸ç·Ê
		int image_plus = row_plus * 4;	// C[WÀWÌÝèÊuÌcñªÅ¸ç·Ê


		for (int l_tex_x = 0; l_tex_x < (int)address_image->width; l_tex_x++)
		{
			//  Ïé¾  //
			DATA::COLOR::C_Color set_color; // Ýè·éF


			set_color.m_r = address_image->pixels[image_plus + l_tex_x * 4 + 0] / 255.0f;
			set_color.m_g = address_image->pixels[image_plus + l_tex_x * 4 + 1] / 255.0f;
			set_color.m_b = address_image->pixels[image_plus + l_tex_x * 4 + 2] / 255.0f;
			set_color.m_a = address_image->pixels[image_plus + l_tex_x * 4 + 3] / 255.0f;
			in_tex_map.M_Set_Color_At_Point(set_color, l_tex_x, l_tex_y);
		}
	}

	// ¬÷
	return true;
}


#endif // OS_IS_WINDOWS


