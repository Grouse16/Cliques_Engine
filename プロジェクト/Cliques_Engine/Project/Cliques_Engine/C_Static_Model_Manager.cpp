////
// Ú×   F3DfÌNX
// à¾   F3DfÌæ¾©ç`æAAj[VÌÀsÜÅðs¤
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Static_Model_Manager.h"


//  l[Xy[XÌÈª  //
using namespace ASSET::MODEL::MANAGER;


//  X^eBbNÏ  //
C_Static_Model_Manager C_Static_Model_Manager::m_this;


//  Ö  //

//== vCx[g ==//

//-- ú» --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Static_Model_Manager::C_Static_Model_Manager(void)
{
	return;
}


//== pubN ==//

//-- I¹ --//

//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Static_Model_Manager::~C_Static_Model_Manager(void)
{
	M_Release();

	return;
}


//===============//
// Ú×   FÌðúð·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Static_Model_Manager::M_Release(void)
{
	for (S_Static_Model_Inform & now_3d_model : m_this.mpr_variable.model_list)
	{
		now_3d_model.model_data.reset();
	}

	m_this.mpr_variable.model_list.clear();
	m_this.mpr_variable.model_list.shrink_to_fit();

	return;
}


//-- Qb^ --//

//===============//
// Ú×   Fwè³ê½3DfðÔ·
// ø   Fstring 3DfÌ¼O
// ßèl FC_Static_Model_System * wè³ê½3Dff[^ÖÌAhXAÈ¯êÎnullptrðÔ·
//===============//
ASSET::MODEL::C_Static_Model_System * C_Static_Model_Manager::M_Get_3D_Model_By_Name(std::string in_3D_model_name)
{
	// wè³ê½¼OÌ3DfðT·
	for (S_Static_Model_Inform & model_inform : m_this.mpr_variable.model_list)
	{
		if (model_inform.name == in_3D_model_name)
		{
			model_inform.user_sum += 1;
			return model_inform.model_data.get();
		}
	}

	// ©Â©çÈ©Á½
	return nullptr;
}


//-- [h --//

//===============//
// Ú×   F3Df¼©ç3Dfð[h·é
// ø   Fstring 3Df¼
// ßèl FC_Material * ¶¬µ½3Dff[^ÖÌAhX
//===============//
ASSET::MODEL::C_Static_Model_System * C_Static_Model_Manager::M_Load_3D_Model_By_Name(std::string in_3D_model_name)
{
	//  Ïé¾  //
	std::string model_3d_inform_path = "project/asset/model/" + in_3D_model_name + ".elsttmdl";	// 3DfîñÖÌpX

	int model_slot_num = (int)m_this.mpr_variable.model_list.size();	// ì·é3DfÌÔ


	// Vµ¢3DfÝèpÌXbgð¶¬
	m_this.mpr_variable.model_list.resize(model_slot_num + 1);
	m_this.mpr_variable.model_list[model_slot_num].model_data.reset(new ASSET::MODEL::C_Static_Model_System());

	// 3Dfîñ©ç3Dfð[h·éAÅ«È¯êÎfalseðÔ·
	if (m_this.mpr_variable.model_list[model_slot_num].model_data->M_Load_3D_Model_By_Path(model_3d_inform_path) == false)
	{
		return nullptr;
	}

	// Vµ¢3DfÌ¼Oðo^µAgp³êÄ¢éðÁZ
	m_this.mpr_variable.model_list[model_slot_num].name = in_3D_model_name;
	m_this.mpr_variable.model_list[model_slot_num].user_sum = 1;

	// ¶¬µ½3DfðÔ·
	return m_this.mpr_variable.model_list[model_slot_num].model_data.get();
}


//-- í --//

//===============//
// Ú×   F3Df¼©ç3Dfð[h·é
// ø   Fstring 3Df¼
// ßèl FC_Material * ¶¬µ½3Dff[^ÖÌAhX
//===============//
void C_Static_Model_Manager::M_Release_3D_Model(ASSET::MODEL::C_Static_Model_System * & in_delete_model)
{
	// 3DfÝè¼©çwè³ê½3DfÝèðTµÄA©Â©Á½çL³êÄ¢éÌJEgð¸çµÄQÆÅ«È­·é
	for (S_Static_Model_Inform & now_3d_model_inform : m_this.mpr_variable.model_list)
	{
		if (now_3d_model_inform.model_data.get() == in_delete_model)
		{
			in_delete_model = nullptr;
			now_3d_model_inform.user_sum -= 1;


			// ±Ì3DfÝèªgíêÈ­ÈÁ½çí·é
			m_this.mpr_variable.model_list.erase
			(
				std::remove_if
				(
					m_this.mpr_variable.model_list.begin(),
					m_this.mpr_variable.model_list.end(),

					// cèÌª0ÉÈéÆí·é_®
					[](S_Static_Model_Inform & in_3d_model_setting)->bool
					{
						if (in_3d_model_setting.user_sum < 1)
						{
							in_3d_model_setting.model_data.reset();

							return true;
						}

						return false;
					}
				),
				m_this.mpr_variable.model_list.end()
			);

			return;
		}
	}

	return;
}

