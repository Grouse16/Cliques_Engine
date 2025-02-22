////
// Ú×   F`æpCvCpîñð¶¬·é½ßÌîñÌ\¢Ì
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_CREATE_RENDERING_GRAPHICS_SETTING_INFORM_H_FILE
#define D_INCLUDE_GUARD_C_CREATE_RENDERING_GRAPHICS_SETTING_INFORM_H_FILE


//  t@CÐç«  //
#include <vector>
#include <string>

#include "C_Shader_Setting.h"
#include "Blend_Setting_Inform.h"
#include "Depth_Stencil_Setting_Inform.h"
#include "Rasterizer_Setting_Inform.h"
#include "Depth_Stencil_Setting_Inform.h"
#include "S_Sampling_Setting_Inform.h"


//  l[Xy[X  //

// OtBbNð§ä·éVXeÌîñð¶¬·é½ßÌîñðÄÑo·½ßÌ¼O
namespace RENDERING::API::CREATE
{
	//  \¢Ì  //

	// uhÝèð¶¬·é½ßÌf[^Ì\¢Ì
	struct S_Blend_Setting_Create_Data
	{
		RENDERING::INFORM::BLEND::E_BLEND_MODE blend_mode = RENDERING::INFORM::BLEND::E_BLEND_MODE::e_NORMAL;	// uh[h

		RENDERING::INFORM::BLEND::E_BLEND_OPTION blend_option = RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_ADD;	// uhÌû@

		RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT draw_format = RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_2_FLOAT;	// `æÌ«Ý`®

		RENDERING::INFORM::BLEND::E_RENDERING_DRAW_COLOR draw_color = RENDERING::INFORM::BLEND::E_RENDERING_DRAW_COLOR::e_RGBA;	// «ÞÆ«ÌF
	};

	// [xXeVÝèð¶¬·é½ßÌf[^Ì\¢Ì
	struct S_Depth_Stencil_Create_Data
	{
		RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE mode = RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE::e_NO;	// [xÌ[h

		RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE write_rule = RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_ALWAYS;	// [xl«Ý[

		RENDERING::INFORM::DEPTH_STENCIL::E_STENCIL_ACTIVATE_SETTING stencil_activate = RENDERING::INFORM::DEPTH_STENCIL::E_STENCIL_ACTIVATE_SETTING::e_NO_ACTIVE;	// XeVðLøÉ·é©Ç¤©
	};

	// X^CUÝèð¶¬·é½ßÌf[^Ì\¢Ì
	struct S_Rasterizer_Create_Data
	{
		RENDERING::INFORM::RASTERIZER::E_DRAW_MODE draw_mode = RENDERING::INFORM::RASTERIZER::E_DRAW_MODE::e_NORMAL;	// IuWFNg`æ[h

		RENDERING::INFORM::RASTERIZER::E_MESH_CULLING mesh_culling = RENDERING::INFORM::RASTERIZER::E_MESH_CULLING::e_FRONT;	// JOÉcéÊð\ Åßé

		RENDERING::INFORM::RASTERIZER::E_MESH_FRONT mesh_front = RENDERING::INFORM::RASTERIZER::E_MESH_FRONT::e_CLOCK_WISE;	// ÊÌ\ü«ðßéÌ¸_Ì`æ

		RENDERING::INFORM::RASTERIZER::E_ANTIALIASING antialiasing = RENDERING::INFORM::RASTERIZER::E_ANTIALIASING::e_DONT;	// A`GCAVOÌ[h

		RENDERING::INFORM::RASTERIZER::S_Depth_Setting_Value depth_value;	// [xîñÝèpÌl

		bool flg_conservative = false;	// ÛçIÈX^CYðs¤©Ç¤©ÌtOAtrueÅÛçIÈX^CYðs¤
	};

	// `æpCvCpîñð¶¬·é½ßÌîñÌ\¢Ì
	struct S_Create_Rendering_Graphics_Setting_Inform
	{
		ASSET::SHADER::C_Shader_Setting * shader_setting = nullptr;	// VF[_[Ýèîñ

		S_Depth_Stencil_Create_Data depth_stencil_data;	// [xXeVÌ¶¬pf[^

		S_Rasterizer_Create_Data rasterizer_data;	// X^CUÝèÌ¶¬pf[^

		std::vector<S_Blend_Setting_Create_Data> blend_setting;	// uhÝèÌ¶¬pf[^

		RENDERING::INFORM::SAMPLING::S_Sampling_Setting_Inform sampling_setting;	// TvOÌÝè
	};
}


#endif // !D_INCLUDE_GUARD_C_CREATE_RENDERING_GRAPHICS_SETTING_INFORM_H_FILE
