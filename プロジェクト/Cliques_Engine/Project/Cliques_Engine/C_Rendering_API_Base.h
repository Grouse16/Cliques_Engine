////
// Ú×   FT[hp[eBÌ_OÉæéOtBbNð§ä·éVXeÌîêNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_RENDERING_API_BASE_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_API_BASE_H_FILE


//  t@CÐç«  //
#include<iostream>
#include<memory>
#include<vector>
#include<string>

#include "C_Rendering_Vertex_Buffer_Setting_Inform_Base.h"
#include "C_Rendering_Index_Buffer_Setting_Inform_Base.h"
#include "C_Rendering_Texture_Setting_Inform_Base.h"
#include "C_Rendering_Constant_Buffer_Setting_Inform_Base.h"
#include "C_Rendering_Graphics_Setting_Inform_Base.h"
#include "C_Rendering_Font_Inform_Base.h"
#include "C_Rendering_Screen_Data_Base.h"
#include "C_Rendering_Depth_Stencil_Buffer_Base.h"

#include "S_Create_Vertex_Buffer_Inform.h"
#include "S_Create_Index_Buffer_Inform.h"
#include "S_Create_Texture_Setting_Inform.h"
#include "S_Create_Constant_Buffer_Inform.h"
#include "S_Create_Rendering_Graphics_Setting_Inform.h"
#include "S_Create_Font_Data_Inform.h"
#include "S_Create_Render_Screen_Inform.h"
#include "S_Create_Depth_Stencil_Buffer_Inform.h"

#include "C_Color.h"
#include "S_Rect.h"
#include "S_Make_Font_To_Graph_Pakage.h"


//  l[Xy[X  //

// _OAPIÌîêNXðÄÑo·½ßÌ¼O
namespace RENDERING::API::BASE
{
	//  NX  //
	
	// _OAPIÌîêNX
	class C_Rendering_API_Base
	{
	//== veNg ==//
	protected:

		//  Ïé¾  //
		static std::unique_ptr<C_Rendering_API_Base> m_this;	// NXÌCX^XpAhXAåÉ|[tBY»Égp


	//== pubN ==//
	public:

		//  Ö  //

		//-- ú»ÆI¹ --//

		// _OAPIÌú»
		virtual bool M_Set_Up(void) = 0;

		// _OAPIÌðú
		virtual void M_Release(void) = 0;

		// _OAPIÌí
		static void M_Delete_API(void);

		// fXgN^
		virtual ~C_Rendering_API_Base(void);


		//-- _O --//

		// _OJnÌ
		virtual void M_Rendering_Start(void) = 0;

		// _OI¹Æ`æobt@ÌØèÖ¦
		virtual void M_Rendering_End_And_Swap_Screen(void) = 0;


		//-- _OÝè --//

		// _OÝèÌ¶¬·é@øFÝèæÌ_OÝè, _OÝèÌ¶¬pÌîñ(const)
		virtual bool M_Create_Rendering_Graphics_Inform(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Graphics_Setting_Inform_Base>&, const RENDERING::API::CREATE::S_Create_Rendering_Graphics_Setting_Inform&) const = 0;

		// _OÝèÌZbg·é@øFZbg·é_OÝè(const)
		virtual void M_Rendering_Set_Rendering_Setting(const std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Graphics_Setting_Inform_Base>&) = 0;


		//-- _OæÊ --//

		// _OæÊÌ¶¬·é@øFÝèæÌ_OæÊÌQÆ, _OæÊð¶¬·é½ßÌîñÌQÆiconstj@ßèlF¬÷ÌÝtrue
		virtual bool M_Create_Rendering_Screen(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> &, const RENDERING::API::CREATE::S_Create_Render_Screen_Inform & ) const = 0;

		// _OæÊÌNA·é@øFNA·é_OæÊÔ, NA·é_OæÊVXeÌQÆ
		virtual void M_Clear_Rendering_Screen(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & ) const = 0;

		// _OæÊð`ææÆµÄZbg·é@øFÝèæÌ_OæÊÌQÆ
		virtual void M_Set_Rendering_Screen_To_Render_Target(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & ) = 0;

		// _OæÊðwè³ê½eNX`\[XXbgÉZbg·é@øF_OæÊÔ, ÝèæÌeNX`ÌXbgÔ, _OæÊVXeÌQÆ
		virtual void M_Set_Rendering_Screen_To_Texture_Slot(int, int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & ) = 0;

		// _OæÊÌf[^ðÇÝæèÂ\É·é@øFÝè·é_OæÊÔ, _OæÊVXeÌQÆ
		virtual void M_Set_Rendering_Screen_Can_Readable(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & ) = 0;

		// CÌ_OæÊð`ææÉ·é
		virtual void M_Set_Main_Rendering_Screen_To_Rendering(void) = 0;

		// CÌ\¦Ì_OæÊðwè³ê½eNX`XbgÉZbg·é@øFÝèæÌeNX`ÌXbgÔ
		virtual void M_Set_Main_Front_Rendering_Screen_To_Texture_Slot(int) = 0;

		// CÌ`æ«ÝÌ_OæÊðwè³ê½eNX`XbgÉZbg·é@øFÝèæÌeNX`ÌXbgÔ
		virtual void M_Set_Main_Back_Rendering_Screen_To_Texture_Slot(int) = 0;

		// CÌ_OæÊÌf[^ðeNX`ÉÚ·@øFÝèæÌeNX`ÌQÆ
		virtual void M_Save_Main_Rendering_Screen_To_Texture(ASSET::TEXTURE::C_Texture_Map & ) const = 0;

		// wè³ê½_OæÊÌf[^ðeNX`ÉÚ·@øFÝè·é_OæÊÔ, _OæÊVXeÌQÆ, ÝèæÌeNX`ÌQÆ
		virtual void M_Save_Rendering_Screen_To_Texture(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & , ASSET::TEXTURE::C_Texture_Map & ) const = 0;

		// _OæÊÌíðÊm·é@øFí³ê½_OæÊÌAhXiconstj
		virtual void M_Notice_Rendering_Screen_Deleted(const RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base * ) = 0;


		//-- [xXeVobt@ --//

		// [xXeVobt@ð¶¬·é@øF¶¬æÌ[xXeVobt@ÌQÆ, [xXeVobt@ð¶¬·é½ßÌîñÌQÆiconstj@ßèlF¬÷ÌÝtrue
		virtual bool M_Create_Depth_Stencil_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & , const RENDERING::API::CREATE::S_Create_Depth_Stencil_Buffer_Inform & ) const = 0;

		// [xXeVobt@ðNA·é@øFNA·é[xXeVobt@ÌQÆ
		virtual void M_Clear_Depth_Stencil_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & ) const = 0;

		// [xXeVobt@ð`æpÉZbg·é@øFÝè·é[xXeVobt@ÌQÆ
		virtual void M_Set_Depth_Stencil_Buffer_To_Rendering(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & ) = 0;

		// [xXeVobt@ðGPUp\[XÌeNX`XbgÉZbg@øFÝèæÌXbgÔ, Ýè·é[xXeVobt@ÌQÆ
		virtual void M_Set_Depth_Stencil_Buffer_To_Texture_Slot(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & ) = 0;

		// [xXeVobt@ÌíðÊm·é@øFí³ê½[xXeVobt@ÌAhXiconstj
		virtual void M_Notice_Depth_Stencil_Buffer_Deleted(const RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base * ) = 0;

		// [xXeVobt@ðZbg·é
		virtual void M_Reset_Depth_Stencil_Buffer(void) = 0;


		//-- ¸_obt@ --//

		// ¸_f[^pÌîñð¶¬·é@øFÝèæÌ¸_îñ, ¶¬pÌîñ(const)
		virtual void M_Create_Vertex_Inform(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & , const RENDERING::API::CREATE::S_Create_Vertex_Buffer_Inform & ) const = 0;

		// ¸_obt@ðZbg·é@øF¸_f[^Ýèpîñ(const)
		virtual void M_Set_Vertex_Buffer(const std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & ) = 0;

		// ¸_obt@ð³É`æðÀs·é@øF`æ·é¸_f[^(const)
		virtual void M_Draw_Command_By_Vertex_Buffer(const std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & ) = 0;


		//-- CfbNXobt@ --//

		// ¸_CfbNXf[^pÌîñð¶¬·é@øFÝèæÌ¸_CfbNXîñ, ¶¬pÌîñ(const)
		virtual void M_Create_Index_Inform(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & , const RENDERING::API::CREATE::S_Create_Index_Buffer_Inform & ) const = 0;

		// ¸_CfbNXobt@ð³É`æðs¤@øF¸_CfbNXf[^Ýèpîñ(const)
		virtual void M_Draw_Command_By_Index_Buffer(const std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & ) = 0;

		// ¸_CfbNXobt@ð³Éwè³ê½CfbNXÔÌ`æðs¤@øF¸_CfbNXf[^Ýèpîñ(const), `æðJn·éCfbNXÔ, `æI¹ÌCfbNXÔ
		virtual void M_Draw_Command_By_Index_Buffer_By_Range(const std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & , int, int) = 0;

		// ¸_CfbNXobt@ðZbg·é@øF¸_CfbNXf[^ÝèpîñÌQÆ
		virtual void M_Set_Index_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & ) = 0;

		// Zbg³ê½¸_CfbNXobt@ð³É`æðs¤
		virtual void M_Draw_Command_By_Set_Index_Buffer(void) = 0;

		// Zbg³ê½¸_CfbNXobt@ð³Éwè³ê½CfbNXÔÌ`æðs¤@øF`æðJn·éCfbNXÔ, `æI¹ÌCfbNXÔ
		virtual void M_Draw_Command_By_Set_Index_Buffer_By_Range(int, int) = 0;
		

		//-- èobt@ --//

		// èf[^pÌîñð¶¬·é@øFÝèæÌèîñ, ¶¬pÌîñ(const)
		virtual void M_Create_Constant_Inform(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Constant_Buffer_Setting_Inform_Base> & , const RENDERING::API::CREATE::S_Create_Constant_Buffer_Inform & ) const = 0;

		// èf[^ðZbg·é@øFèf[^Ýèpîñ(const)
		virtual void M_Rendering_Set_Constant_Buffer(RENDERING::API::INSTANCE::S_Constant_Buffer_Drawing_Setting & ) = 0;

		// wè³ê½CfbNXÔÌXbgÉèf[^ðZbg·é@øFèf[^Ýèpîñ, ZbgæÌCfbNXÔ
		virtual void M_Rendering_Set_Constant_Buffer_By_Index(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Constant_Buffer_Setting_Inform_Base> & , int) = 0;


		//-- eNX` --//

		// eNX`pÌîñð¶¬·é@øFeNX`pîñ, ¶¬pÌîñ(const)@ßèlF¬÷ÌÝtrue
		virtual bool M_Create_Texture_Inform(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Texture_Setting_Inform_Base>&, const RENDERING::API::CREATE::S_Create_Texture_Setting_Inform & ) const = 0;

		// eNX`Ìf[^ðZbg·é@øFZbg·éeNX`f[^îñ(const)
		virtual void M_Rendering_Set_Texture(RENDERING::API::INSTANCE::S_Texture_Buffer_Drawing_Setting & ) = 0;

		// wè³ê½CfbNXÔÌXbgÉeNX`Ìf[^ðZbg·é@øFZbg·éeNX`f[^îñ(const), ZbgæÌCfbNXÔ
		virtual void M_Rendering_Set_Texture_By_Index(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Texture_Setting_Inform_Base> & , int) = 0;


		//-- tHg --//

		// tHgðwè³ê½tHg¼ð³É[h·é@øFÝèæÌtHgîñp[^, ¶¬pÌîñ(const)@ßèlF¬÷ÌÝtrue
		virtual bool M_Create_Font_Data(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Font_Inform_Base> &, const RENDERING::API::CREATE::S_Create_Font_Data_Inform & ) const = 0;

		// n³ê½îñð³É¶ñð}bvÉZbg·é@øFtHg©çæðìé½ßÌpbP[Wîñ@ßèlF¬÷ÌÝtrue
		virtual bool M_Set_Font_To_Texture_Map(PAKAGE::FONT::S_Make_Font_To_Graph_Package & ) const = 0;


		//-- Qb^ --//

		// ±ÌNXÌÀÌÌAhXðÔ·@ßèlF©NXÌCX^XÖÌAhX
		static C_Rendering_API_Base * M_Get_Instance(void);

		// ±Ì_OVXeÌVF[_[ÌtH_ÜÅÌpXðÔ·@ßèlFVF[_[ÌtH_ÜÅÌpX
		virtual std::string M_Get_Shader_Folder_Path(void) const = 0;

		// ±Ì_OVXeÌVF[_[Ìg£qðÔ·@ßèlFVF[_[Ìg£q
		virtual std::string M_Get_Shader_Extension(void) const = 0;

		// _OVXeªI¹µÄ¢é©Ç¤©ÌtOðÔ·@ßèlF_OVXeªI¹µÄ¢é©Ç¤©ÌtO
		virtual bool M_Get_End_Rendering_System(void) const = 0;


		//-- Zb^ --//

		// æÊðNA·éFðÝè·é@øFÝè·éF(const)
		virtual void M_Set_Clear_Color(const DATA::COLOR::C_Color & ) = 0;


		//-- [h --//

		// eNX`ð[h·é@øFeNX`t@CÌpX, eNX`}bvÌQÆ
		virtual bool M_Load_Texture(std::string, ASSET::TEXTURE::C_Texture_Map &) const = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_API_BASE_H_FILE


//======================================================================
// Copyright 2023 ûüâ´½
// 
// àµà±ÌR[hð©ªÌvWFNgÉpµ½¢ÌÅ êÎA
// [AhXFtakasaka.ryusei1116@gmail.com
// Ü½ÍAûüâ´½ÜÅ²A­¾³¢B
// R[hÌs¾ªÌðàâAÅVÌóÔÌñÈÇÉÎ¢½µÜ·B
//======================================================================

