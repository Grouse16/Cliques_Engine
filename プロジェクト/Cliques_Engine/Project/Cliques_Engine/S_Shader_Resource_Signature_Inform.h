////
// Ú×   FVF[_[Ì¯Ê¼ðÇ·é½ßÌ\¢ÌÌé¾
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_S_SHADER_SIGNATURE_INFORM
#define D_INCLUDE_GUARD_S_SHADER_SIGNATURE_INFORM


//  t@CÐç«  //
#include <vector>
#include <string>

#include "E_Shader_Kind.h"


//  l[Xy[X  //

// VF[_[pÌè`ðÄÑo·½ßÌ¼O
namespace ASSET::SHADER
{
	//  ñ  //

	// \[XÌíÞ
	enum class E_RESOURCE_KIND : char
	{
		e_CONSTANT_BUFFER,	// èobt@
		e_TEXTURE,			// eNX`
	};


	//  \¢Ì  //

	// èobt@Ì\[XîñÌ\¢Ì
	struct S_Constant_Resource_Inform
	{
		E_SHADER_KIND shader_kind = E_SHADER_KIND::e_ALL;	// ÝèæÌVF[_[ÌíÞ

		std::string resource_name = "default";	// èobt@Ì¼O

		int array_sum = 0;	// èobt@Ìzñ

		bool flg_data_creation = false;	// f[^ð¶¬·é©Ç¤©ÌtO

		int slot_number = 0;	// XbgÔ
	};


	// eNX`obt@Ì\[XîñÌ\¢Ì
	struct S_Texture_Resource_Inform
	{
		E_SHADER_KIND shader_kind = E_SHADER_KIND::e_ALL;	// ÝèæÌVF[_[ÌíÞ

		std::string resource_name = "default";	// eNX`Ì¼O
		std::string initialize_texture_name = "default";	// ú[h·éeNX`¼

		int slot_number = 0;	// XbgÔ
	};


	// _OæÊÌ\[XîñÌ\¢Ì
	struct S_Screen_Resource_Inform
	{
		E_SHADER_KIND shader_kind = E_SHADER_KIND::e_ALL;	// ÝèæÌVF[_[ÌíÞ

		std::string resource_name = "default";	// eNX`Ì¼O

		int slot_number = 0;	// XbgÔ
	};


	// [xXeVÌ\[XîñÌ\¢Ì
	struct S_Depth_Stencil_Resource_Inform
	{
		E_SHADER_KIND shader_kind = E_SHADER_KIND::e_ALL;	// ÝèæÌVF[_[ÌíÞ

		std::string resource_name = "default";	// eNX`Ì¼O

		int slot_number = 0;	// XbgÔ
	};


	// Tv[Ì\[XîñÌ\¢Ì
	struct S_Sampler_Resource_Inform
	{
		E_SHADER_KIND shader_kind = E_SHADER_KIND::e_ALL;	// ÝèæÌVF[_[ÌíÞ

		std::string uv_setting = "";	// UVÌgpû@
	};


	// XbgÌîñÌ\¢Ì
	struct S_Resource_Slot_Inform
	{
		E_RESOURCE_KIND resource_kind = E_RESOURCE_KIND::e_CONSTANT_BUFFER;	// \[XÌíÞ

		E_SHADER_KIND shader_kind = E_SHADER_KIND::e_ALL;	// ÝèæÌVF[_[ÌíÞ
	};


	// \[XÌîñðÜÆß½\¢Ì
	struct S_Resource_Inform_List
	{
		std::vector<S_Constant_Resource_Inform> constant_list;	// èobt@ÌîñXg

		std::vector<S_Texture_Resource_Inform> texture_list;	// eNX`ÌîñXg

		std::vector<S_Screen_Resource_Inform> screen_list;	// _OæÊÌîñXg

		std::vector<S_Depth_Stencil_Resource_Inform> depth_stencil_list;	// [xXeVÌîñXg

		std::vector<S_Sampler_Resource_Inform> sampler_list;	// Tv[ÌîñXg

		std::vector<S_Resource_Slot_Inform> slot_list;	// XbgÌîñXg
	};
}


#endif // !D_INCLUDE_GUARD_S_SHADER_SIGNATURE_INFORM

