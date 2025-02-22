////
// Ú×   FVF[_[§äpÌNX
// à¾   FVF[_[ÌÇÝæèÆ«oµAÇðs¤
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_C_RENDERING_SHADER_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_SHADER_MANAGER_H_FILE


//  t@CÐç«  //
#include <vector>
#include <string>

#include "C_Shader_Code.h"
#include "E_Shader_Kind.h"


//  l[Xy[X  //

// _OÉgp·éVF[_[ðÄÑo·½ßÌ¼O
namespace ASSET::SHADER::MANAGER
{
	//  NX  //

	// VF[_[Ì§äpVXe
	class C_Shader_Manager
	{
	//== vCx[g ==//
	private:

		//  \¢Ì  //
		
		// VF[_[îñÌ\¢Ì
		struct S_Shader_Manage_Inform
		{
			std::unique_ptr<C_Shader_Code> shader = nullptr;	// VF[_[Ýè

			std::string name = "DEFAULT";	// VF[_[Ýè¼

			int user_sum = 0;	// ±ÌVF[_[îñðÁÄ¢éVXeÌ
		};


		//  Ïé¾  //

		// vCx[gÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			std::vector<std::vector<S_Shader_Manage_Inform>> shader_inform_list;	// VF[_[îñÌXg
		};

		SPr_Variable mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O

		static C_Shader_Manager m_this;	// VF[_[§äpVXeÌVOg»pCX^X


		//  Ö  //

		//-- ú» --//

		// RXgN^AVOg»·é
		C_Shader_Manager(void);


	//== pubN ==//
	public:

		//  Ö  //

		//-- I¹ --//

		// fXgN^
		~C_Shader_Manager(void);

		// ððú·é
		static void M_Release(void);


		//-- Qb^ --//

		// wè³ê½VF[_[f[^ðÔ·@øFVF[_[ÌíÞ, VF[_[ÝèÌ¼O@ßèlFwè³ê½VF[_[f[^ÖÌAhXAÈ¯êÎnullptrðÔ·
		static C_Shader_Code * M_Get_Shader_Setting(E_SHADER_KIND, std::string);


		//-- [h --//

		// VF[_[¼©ç}eAð[h·é@øFVF[_[ÌíÞ@ßèlF¶¬µ½VF[_[f[^ÖÌAhX
		static C_Shader_Code * M_Load_Shader_By_Name(E_SHADER_KIND, std::string);


		//-- í --//

		// wè³ê½VF[_[f[^ÌL ðúü·é±ÆðÊm·é@øFVF[_[ÌíÞ, L ðúü·éVF[_[f[^ÌAhXÌQÆ
		static void M_Released_Shader_Once(E_SHADER_KIND, C_Shader_Code * &);
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_SHADER_MANAGER_H_FILE


//======================================================================
// Copyright 2023 ûüâ´½
// 
// àµà±ÌR[hð©ªÌvWFNgÉpµ½¢ÌÅ êÎA
// [AhXFtakasaka.ryusei1116@gmail.com
// Ü½ÍAûüâ´½ÜÅ²A­¾³¢B
// R[hÌs¾ªÌðàâAÅVÌóÔÌñÈÇÉÎ¢½µÜ·B
//======================================================================

