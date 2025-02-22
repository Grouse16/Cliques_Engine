////
// Ú×   Fèobt@ÌZbgpÌf[^ÌîêNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_CONSTANT_BUFFER_SETTING_INFORM_BASE_H_FILE
#define D_INCLUDE_GUARD_C_CONSTANT_BUFFER_SETTING_INFORM_BASE_H_FILE


//  t@CÐç«  //
#include <memory>
#include <string>

#include "E_Shader_Kind.h"


//  l[Xy[X  //

// OtBbNð§ä·éVXeÌîñðÄÑo·½ßÌ¼O
namespace RENDERING::API::INSTANCE
{
	//  NX  //

	// èobt@§äpf[^ÌîêNX
	class C_Rendering_Constant_Buffer_Setting_Inform_Base
	{
	//== pubN ==//
	public:

		//-- Ö --//

		//-- I¹ --//

		// RXgN^
		C_Rendering_Constant_Buffer_Setting_Inform_Base(void);

		// fXgN^
		virtual ~C_Rendering_Constant_Buffer_Setting_Inform_Base(void);


		//-- Zb^ --//

		// èobt@Éwè³ê½îñðZbg·é@øFZbg·éf[^, zñ, Zbg·éf[^TCY
		virtual void M_Set_Data_To_Buffer(void*, int, int) = 0;


		//-- Qb^ --//

		// èobt@Ìf[^ÌAhXðÔ·@gpªIíÁ½çK¸Close·é±Æ@ßèlFèobt@Ìf[^ÌAhX
		virtual unsigned char * M_Get_Constant_Buffer_Data_Address(void) = 0;

		// èobt@Ìf[^ðgpI¹·é
		virtual void M_Close_Constant_Buffer_Data_Address(void) = 0;
	};


	// èobt@ð`æ·éÆ«ÌîñZbg
	struct S_Constant_Buffer_Drawing_Setting
	{
		C_Rendering_Constant_Buffer_Setting_Inform_Base * add_constant_buffer = nullptr;	// èobt@pîñÌAhX

		std::string * add_signature_name = nullptr;	// ¯Ê¼ÌAhX

		ASSET::SHADER::E_SHADER_KIND add_attach_shader_kind = ASSET::SHADER::E_SHADER_KIND::e_ALL;	// ÝèæÌVF[_[ÌíÞÌAhX
	};
}


#endif // !D_INCLUDE_GUARD_C_CONSTANT_BUFFER_SETTING_INFORM_BASE_H_FILE
