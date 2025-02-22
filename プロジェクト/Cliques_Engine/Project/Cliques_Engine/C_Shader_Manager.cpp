////
// Ú×   FVF[_[§äpÌNX
// à¾   FVF[_[ÌÇÝæèÆ«oµAÇðs¤
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Shader_Manager.h"
#include "C_Rendering_API_Interface_User.h"


//  l[Xy[XÌÈª  //
using namespace ASSET::SHADER::MANAGER;


//  X^eBbNÏ  //
C_Shader_Manager C_Shader_Manager::m_this;


//  Ö  //

//== vCx[g ==//

//-- ú» --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Shader_Manager::C_Shader_Manager(void)
{
	// VF[_[ÌíÞªXgðìé
	mpr_variable.shader_inform_list.resize((int)E_SHADER_KIND::e_ALL);

	return;
}


//== pubN ==//

//-- I¹ --//

//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Shader_Manager::~C_Shader_Manager(void)
{
	M_Release();

	return;
}


//===============//
// Ú×   Fððú·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Shader_Manager::M_Release(void)
{
	for (std::vector<S_Shader_Manage_Inform> & now_inform_list : m_this.mpr_variable.shader_inform_list)
	{
		for (S_Shader_Manage_Inform & now_inform : now_inform_list)
		{
			now_inform.shader->M_Release();
			now_inform.shader.reset();
		}

		now_inform_list.clear();
		now_inform_list.shrink_to_fit();
	}

	m_this.mpr_variable.shader_inform_list.clear();
	m_this.mpr_variable.shader_inform_list.shrink_to_fit();

	return;
}


//-- Qb^ --//

//===============//
// Ú×   Fwè³ê½VF[_[f[^ðÔ·
// ø   FE_SHADER_KIND VF[_[ÌíÞ, string VF[_[ÌÝèÌ¼O
// ßèl FC_Shader_Set * wè³ê½VF[_[f[^ÖÌAhX
//===============//
ASSET::SHADER::C_Shader_Code * C_Shader_Manager::M_Get_Shader_Setting(E_SHADER_KIND in_shader_kind, std::string in_shader_name)
{
	// wè³ê½¼OªVF[_[f[^à©ç©Â©éÜÅTõµA©Â©Á½ç»Ìf[^ÌAhXðÔ·
	for (S_Shader_Manage_Inform & now_shader_inform : m_this.mpr_variable.shader_inform_list[(int)in_shader_kind])
	{
		if (now_shader_inform.name == in_shader_name)
		{
			now_shader_inform.user_sum += 1;
			return now_shader_inform.shader.get();
		}
	}

	// [hÅ«È©Á½çnullptrðÔ·
	return nullptr;
}


//-- [h --//

//===============//
// Ú×   FVF[_[¼©çVF[_[ð[h·é
// ø   FE_SHADER_KIND VF[_[ÌíÞ, string VF[_[¼ÌQÆ
// ßèl FC_Shader_Code * ¶¬µ½VF[_[f[^ÖÌAhX
//===============//
ASSET::SHADER::C_Shader_Code * C_Shader_Manager::M_Load_Shader_By_Name(E_SHADER_KIND in_shader_kind, std::string in_shader_name)
{
	//  Ïé¾  //
	std::string shader_inform_path = 	// VF[_[îñÖÌpX
		RENDERING::API::RENDER_INTERFACE::C_Rendering_API_Interface_User::M_Get_Shader_Folder_Path() +
		in_shader_name +
		RENDERING::API::RENDER_INTERFACE::C_Rendering_API_Interface_User::M_Get_Shader_Extension();

	int shader_slot_num = (int)m_this.mpr_variable.shader_inform_list[(int)in_shader_kind].size();	// ì·éVF[_[ÌÔ


	// Vµ¢VF[_[ÝèpÌXbgð¶¬
	m_this.mpr_variable.shader_inform_list[(int)in_shader_kind].resize(shader_slot_num + 1);
	m_this.mpr_variable.shader_inform_list[(int)in_shader_kind][shader_slot_num].shader.reset(new ASSET::SHADER::C_Shader_Code);

	// VF[_[îñ©çVF[_[ð[h·éAÅ«È¯êÎfalseðÔ·
	if (m_this.mpr_variable.shader_inform_list[(int)in_shader_kind][shader_slot_num].shader->M_Load_Shader_File(shader_inform_path) == false)
	{
		return nullptr;
	}

	// Vµ¢VF[_[Ì¼Oðo^µAgp³êÄ¢éðÁZ
	m_this.mpr_variable.shader_inform_list[(int)in_shader_kind][shader_slot_num].name = in_shader_name;
	m_this.mpr_variable.shader_inform_list[(int)in_shader_kind][shader_slot_num].user_sum = 1;

	// ¶¬µ½VF[_[ðÔ·
	return m_this.mpr_variable.shader_inform_list[(int)in_shader_kind][shader_slot_num].shader.get();
}


//-- í --//

//===============//
// Ú×   Fwè³ê½VF[_[f[^ÌL ðúü·é±ÆðÊm·é
// ø   FE_SHADER_KIND VF[_[ÌíÞ, C_Shader_Setting * & L ðúü·éVF[_[f[^ÌAhXÌQÆiconstj
// ßèl Fvoid
//===============//
void C_Shader_Manager::M_Released_Shader_Once(ASSET::SHADER::E_SHADER_KIND in_shader_kind, C_Shader_Code * & in_released_shader)
{
	// wè³ê½VF[_[f[^ðTõµA©Â©Á½çµÄ¢éCX^Xð¸çµA»ÌVF[_[ÖÌÚ±ðØé
	for (S_Shader_Manage_Inform & now_shader_set : m_this.mpr_variable.shader_inform_list[(int)in_shader_kind])
	{
		if (now_shader_set.shader.get() == in_released_shader)
		{
			in_released_shader = nullptr;
			now_shader_set.user_sum -= 1;


			// ±ÌVF[_[ªgíêÈ­ÈÁ½çí·é
			m_this.mpr_variable.shader_inform_list[(int)in_shader_kind].erase
			(
				std::remove_if
				(
					m_this.mpr_variable.shader_inform_list[(int)in_shader_kind].begin(),
					m_this.mpr_variable.shader_inform_list[(int)in_shader_kind].end(),

					// íðÌ_®
					[](S_Shader_Manage_Inform & in_shader_inform)
					{
						if (in_shader_inform.user_sum < 1)
						{
							in_shader_inform.shader.reset();

							return true;
						}

						return false;
					}
				),
				m_this.mpr_variable.shader_inform_list[(int)in_shader_kind].end()
			);
			m_this.mpr_variable.shader_inform_list[(int)in_shader_kind].shrink_to_fit();

			return;
		}
	}

	return;
}

