////
// Ú×   FÏ`µÈ¢fÌR|[lgÌVXe
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Animation_Model_Component.h"
#include "C_Game_Time_Manager.h"


//  l[Xy[XÌÈª  //
using namespace GAME::COMPONENT::MODEL_COMPONENT;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Animation_Model_Component::C_Animation_Model_Component(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Animation_Model_Component::~C_Animation_Model_Component(void)
{
	return;
}


//-- Zb^ --//

//===============//
// Ú×   Fwè³ê½¼OÌfð[h·é
// ø   Fstring [h·éf¼
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_Animation_Model_Component::M_Load_Animation_Model_By_Name(std::string in_load_model_name)
{
	return mpr_variable.model_system.M_Load_Animation_Model(in_load_model_name);
}


//===============//
// Ú×   F`æÝèXgðÔðwèµÄÝè·éAOÉ Á½`æÝèÌf[^ÍÁ¦é
// ø   Fint ÝèæÌ`æÝèÔ, string gp·é}eA¼, vector<string> `æ·ébV¼ÌXgigÈµÅSbV`æj
// ßèl FC_Material_User * ÇÁµ½}eAgpVXeÌAhX
//===============//
ASSET::MATERIAL::C_Material_User * C_Animation_Model_Component::M_Set_Model_Draw_List(int in_draw_command_number, std::string in_material_name, std::vector<std::string> in_mesh_name_list)
{
	// wè³ê½ÔªÌzñªpÓ³êÄ¢È¯êÎzñðpÓ·é
	if (in_draw_command_number >= mpr_variable.draw_command_list.size())
	{
		mpr_variable.draw_command_list.resize(in_draw_command_number + 1);
	}


	// gp·é}eA¼ªNATURALAÜ½Íó¶Èç³©çbVÉo^³êÄ¢é}eAðgp·é
	if (in_material_name == "NATURAL" || in_material_name == "")
	{
		mpr_variable.draw_command_list[in_draw_command_number].model_draw_option = ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_NATURAL_DRAW;
	}

	// }eA¼ðwè³êÄ¢éÍ»Ì}eAð[h·é
	else
	{
		// }eAðwè·étOð§Äé
		mpr_variable.draw_command_list[in_draw_command_number].model_draw_option = ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_MATERIAL_ORIGINAL;

		// }eAÌ[hA¸sµ½çG[Å²¯é
		if (mpr_variable.draw_command_list[in_draw_command_number].material_data.M_Load_Material(in_material_name) == false)
		{
			return nullptr;
		}
	}

	// `æ·ébVÉwèª éÈço^·é
	if (in_mesh_name_list.size() > 0)
	{
		mpr_variable.draw_command_list[in_draw_command_number].mesh_name_list = in_mesh_name_list;

		// }eAðwèµ½¤¦ÅbVÌwèðs¤
		if (mpr_variable.draw_command_list[in_draw_command_number].model_draw_option == ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_MATERIAL_ORIGINAL)
		{
			mpr_variable.draw_command_list[in_draw_command_number].model_draw_option = ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_SELECT_MESH_AND_MATERIAL_ORIGINAL;
		}

		// bVÌwèÌÝs¤
		else
		{
			mpr_variable.draw_command_list[in_draw_command_number].model_draw_option = ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_SELECT_MESH;
		}
	}

	// gp·é}eAgpVXeÌAhXðÔ·
	return &mpr_variable.draw_command_list[in_draw_command_number].material_data;
}


//===============//
// Ú×   F^CCðgp·é[hÉØèÖ¦é
// ø   Fstring gp·é^CC¼
// ßèl Fvoid
//===============//
void C_Animation_Model_Component::M_Set_Time_Line_Name_And_Start_Time_Line_Mode(std::string in_time_line_name)
{
	mpr_variable.time_line_name = in_time_line_name;
	mpr_variable.flg_use_time_line = true;

	return;
}


//===============//
// Ú×   FÊíÌQ[Ôðgp·é[hÉØèÖ¦é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Animation_Model_Component::M_Set_Game_Time_Mode(void)
{
	mpr_variable.flg_use_time_line = false;

	return;
}


//===============//
// Ú×   F[JÀWÌQÆðÔ·
// ø   Fvoid
// ßèl FC_Transform & [JÀWÌQÆ
//===============//
MATH::C_Transform & C_Animation_Model_Component::M_Get_Transform(void)
{
	return mpr_variable.transform;
}


//===============//
// Ú×   FfVXeÌQÆðÔ·
// ø   Fvoid
// ßèl FC_Animation_Model_User & Aj[VfVXeÌQÆ
//===============//
ASSET::ANIMATION_MODEL::C_Animation_Model_User & C_Animation_Model_Component::M_Get_Model_Address(void)
{
	return mpr_variable.model_system;
}


//-- XV --//

//===============//
// Ú×   FAj[VÌÔðXV·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Animation_Model_Component::M_Update(void)
{
	// ^CCðgp·éêÍA^CCÔðâ¢í¹Ä»ÌÔÅAj[VÔðXV·é
	if (mpr_variable.flg_use_time_line)
	{
		mpr_variable.model_system.M_Time_Update(GAME::TIME::C_Game_Time_Manager::M_Get_Time_Line_Delta_Second(mpr_variable.time_line_name));
	}

	// ÊíÍQ[Ôðgp·é
	else
	{
		mpr_variable.model_system.M_Time_Update(GAME::TIME::C_Game_Time_Manager::M_Get_Game_Second());
	}

	return;
}


//-- `æ --//

//===============//
// Ú×   F`æÊuÆÈé[h}gNXðÝè·éA`æÌJnÉÀs·éAÊí`æÌJnÅæ¢
// ø   Fconst XMMATRIX & Ýè·é[h}gNXÏ·sñÌQÆiconstj
// ßèl Fvoid
//===============//
void C_Animation_Model_Component::M_Draw_Start_And_World_Matrix_Set(const DirectX::XMMATRIX & in_world_matrix)
{
	// [h}gNXÏ·sñð¶¬
	mpr_variable.transform.M_Generate_Matrix(mpr_variable.world_matrix);
	mpr_variable.world_matrix *= in_world_matrix;

	// fÌ`æðJn·é
	mpr_variable.model_system.M_Model_Draw_Start(mpr_variable.world_matrix);

	return;
}


//===============//
// Ú×   FfÌ`æðs¤
// ø   Fint `æ·éÌ`æÝèÌÔ
// ßèl Fvoid
//===============//
void C_Animation_Model_Component::M_Model_Draw(int in_draw_command_number)
{
	//-- `æIvVÅªòµÄ`æðsÈ¤ --//
	switch (mpr_variable.draw_command_list[in_draw_command_number].model_draw_option)
	{
		// Êí`æ
	case ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_NATURAL_DRAW:
	default:
		mpr_variable.model_system.M_Draw_Model();
		break;

		// }eAðwèµÄ`æ·é
	case ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_MATERIAL_ORIGINAL:
		{
			//  Ïé¾  //
			ASSET::MATERIAL::C_Material * use_material = nullptr;	// gp·é}eAÌAhX


			// gp·é}eAðæ¾µAWVPðZbg
			use_material = mpr_variable.draw_command_list[in_draw_command_number].material_data.M_Get_Material_Address();
			use_material->M_Set_World_Matrix(mpr_variable.world_matrix);
			use_material->M_Set_View_Projection_By_Main_Camera();
			mpr_variable.model_system.M_Draw_Model_And_Set_Material(mpr_variable.draw_command_list[in_draw_command_number].material_data);
		}
	break;

	// bVðwèµÄ`æ·é
	case ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_SELECT_MESH:

		for (std::string & now_mesh_name : mpr_variable.draw_command_list[in_draw_command_number].mesh_name_list)
		{
			mpr_variable.model_system.M_Draw_Mesh_By_Mesh_Name(now_mesh_name);
		}
		break;

		// bVÆ}eAðwèµÄ`æ·é
	case ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_SELECT_MESH_AND_MATERIAL_ORIGINAL:
	{
		//  Ïé¾  //
		ASSET::MATERIAL::C_Material* use_material = nullptr;	// gp·é}eAÌAhX


		// gp·é}eAðæ¾µAWVPðZbg
		use_material = mpr_variable.draw_command_list[in_draw_command_number].material_data.M_Get_Material_Address();
		use_material->M_Set_World_Matrix(mpr_variable.world_matrix);
		use_material->M_Set_View_Projection_By_Main_Camera();

		// bVðwèµÄ`æ·é
		for (std::string & now_mesh_name : mpr_variable.draw_command_list[in_draw_command_number].mesh_name_list)
		{
			mpr_variable.model_system.M_Draw_Mesh_By_Mesh_Name_And_Set_Material(mpr_variable.draw_command_list[in_draw_command_number].material_data, now_mesh_name);
		}
	}
	break;
	}

	return;
}


//===============//
// Ú×   FfÌ`æðI¹·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Animation_Model_Component::M_Model_Draw_End(void)
{
	mpr_variable.model_system.M_Model_Draw_End();

	return;
}


//===============//
// Ú×   FR|[lgpÌ`æ¾ªgpµÈ¢if`æOÉ}eAÌÝèÈÇðs¤½ßj
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Animation_Model_Component::M_Draw(void)
{
	return;
}
