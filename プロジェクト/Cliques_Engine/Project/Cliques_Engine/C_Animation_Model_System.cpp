////
// Ú×   FAj[VfÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Animation_Model_System.h"
#include "C_Main_Camera.h"
#include "C_Animation_Model_Loader.h"

#include "C_Console_Log_Interface.h"


//  l[Xy[XÌÈª  //
using namespace ASSET::ANIMATION_MODEL;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Animation_Model_System::C_Animation_Model_System(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Animation_Model_System::~C_Animation_Model_System(void)
{
	M_Release();

	return;
}


//===============//
// Ú×   FÌðúðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Animation_Model_System::M_Release(void)
{
	mpr_variable.mesh_list.clear();
	mpr_variable.mesh_list.shrink_to_fit();

	mpr_variable.bone_list.clear();
	mpr_variable.bone_list.shrink_to_fit();

	mpr_variable.vertex_system.M_Release();

	mpr_variable.animation_data_list.clear();
	mpr_variable.animation_data_list.shrink_to_fit();

	return;
}


//-- [h --//

//===============//
// Ú×   Fwè³ê½pXÌ3DAj[Vfð[h·é
// ø   Fstring 3DAj[VfÜÅÌpX
// ßèl Fbool ¬÷ÌÝture
//===============//
bool C_Animation_Model_System::M_Load_3D_Animation_Model_By_Path(std::string in_3d_animation_model_path)
{
	//  Ïé¾  //
	SYSTEM::TEXT::C_Text_And_File_Manager load_file;	// t@Cð[h·é½ßÌNX


	// »ÝÁÄ¢éAj[Vff[^Íí·é
	M_Release();


	// Aj[Vfð[h·éA¸sµ½çG[Å²¯é
	if (ASSET::ANIMATION_MODEL::LOADER::C_Animation_Model_Loader::M_Load_Animation_Model_File(in_3d_animation_model_path, load_file) == false)
	{
		return false;
	}

	// ¸_f[^ð[h·éA¸sµ½çG[Å²¯é
	if (ASSET::ANIMATION_MODEL::LOADER::C_Animation_Model_Loader::M_Load_Animation_Model_Vertex(load_file, mpr_variable.vertex_system) == false)
	{
		return false;
	}

	// {[f[^ð[h·éA¸sµ½çG[Å²¯é
	if (ASSET::ANIMATION_MODEL::LOADER::C_Animation_Model_Loader::M_Load_Animation_Model_Bone(load_file, mpr_variable.bone_list) == false)
	{
		return false;
	}

	// bVf[^ð[h·éA¸sµ½çG[Å²¯é
	if (ASSET::ANIMATION_MODEL::LOADER::C_Animation_Model_Loader::M_Load_Animation_Model_Mesh(load_file, mpr_variable.mesh_list) == false)
	{
		return false;
	}


	// Aj[VpfÌ[h¬÷ðm
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
	(
		DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP,
		DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT,
		"Aj[VpfÌ[hÉ¬÷µÜµ½F" + in_3d_animation_model_path
	);

	return true;
}


//===============//
// Ú×   Fwè³ê½¼OÌAj[Vf[^ð[h·é
// ø   Fstring [h·éAj[Vf[^¼
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_Animation_Model_System::M_Load_Animation_Data_By_Name(std::string in_animation_data_name)
{
	// ·ÅÉ[h³êÄ¢éÈç½àµÈ¢
	for (ASSET::ANIMATION_SYSTEM::C_Animation_Data_System & now_animation_data : mpr_variable.animation_data_list)
	{
		if (now_animation_data.M_Get_Name() == in_animation_data_name)
		{
			return true;
		}
	}


	//  Ïé¾  //
	std::string load_path = "project/asset/animation/" + in_animation_data_name + ".elanmdt";	// Aj[Vf[^ÜÅÌpX

	int new_animation_data_number = (int)mpr_variable.animation_data_list.size();	// Vµ¢Aj[Vf[^ÌzñÔ


	// Aj[Vf[^ð[h·é@¸sÅfalseðÔµÄ²¯é
	mpr_variable.animation_data_list.resize(new_animation_data_number + 1);
	if (mpr_variable.animation_data_list[new_animation_data_number].M_Load_Animation_Data_By_Path(load_path, mpr_variable.bone_list) == false)
	{
		return false;
	}

	// Aj[Vf[^¼ðÝè
	mpr_variable.animation_data_list[new_animation_data_number].M_Set_Name(in_animation_data_name);

	// [hÉ¬÷
	return true;
}


//-- Qb^ --//

//===============//
// Ú×   Fwè³ê½¼OÌbVðÔ·
// ø   Fstring T·bVÌ¼O
// ßèl FC_Mesh_Data * ¼Oªêvµ½bVÌAhXAêvµÈ©Á½çnullptrðÔ·
//===============//
ASSET::MESH::C_Mesh_Data * C_Animation_Model_System::M_Get_Mesh_Data_By_Name(std::string in_mesh_name)
{
	// êv·ébV¼ðTµA êÎ»ÌAhXðÔ·
	for (ASSET::MESH::C_Mesh_Data & l_now_mesh_data : mpr_variable.mesh_list)
	{
		if (l_now_mesh_data.M_Get_Mesh_Name() == in_mesh_name)
		{
			return &l_now_mesh_data;
		}
	}

	// ©Â©çÈ©Á½
	return nullptr;
}


//===============//
// Ú×   FbVîñÌXgÌQÆðÔ·
// ø   Fvoid
// ßèl Fvector<C_Mesh_Data> & bVîñÌXgÌQÆ
//===============//
std::vector<ASSET::MESH::C_Mesh_Data> &  C_Animation_Model_System::M_Get_Mesh_Inform_List(void)
{
	return mpr_variable.mesh_list;
}


//===============//
// Ú×   Fwè³ê½¼OÌAj[Vf[^ðÔ·
// ø   Fstring T·Aj[Vf[^Ì¼O
// ßèl Fconst C_Animation_Data_System * ¼Oªêvµ½Aj[Vf[^ÌAhXAêvµÈ©Á½çnullptrðÔ·
//===============//
const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * C_Animation_Model_System::M_Get_Animation_Data_By_Name(std::string in_animation_data)
{
	// êv·éAj[Vf[^¼ðTµA êÎ»ÌAhXðÔ·
	for (ASSET::ANIMATION_SYSTEM::C_Animation_Data_System & now_animation_data : mpr_variable.animation_data_list)
	{
		if (now_animation_data.M_Get_Name() == in_animation_data)
		{
			return &now_animation_data;
		}
	}

	// ©Â©çÈ©Á½
	return nullptr;
}


//===============//
// Ú×   FAj[VVXeÌXgÌQÆðÔ·
// ø   Fvoid
// ßèl Fconst vector<C_Animation_Data_System> & Aj[VVXeÌXgÌQÆ
//===============//
const std::vector<ASSET::ANIMATION_SYSTEM::C_Animation_Data_System> & C_Animation_Model_System::M_Get_Animation_Inform_List(void)
{
	return mpr_variable.animation_data_list;
}


//===============//
// Ú×   Fwè³ê½¼OÌ{[ðÔ·
// ø   Fvoid
// ßèl Fstring {[¼
//===============//
const ASSET::ANIMATION::BONE::S_Bone_Inform * C_Animation_Model_System::M_Get_Bone_Inform_By_Name(std::string in_bone_name)
{
	// êv·é{[¼ðTµA êÎ»ÌAhXðÔ·
	for (ASSET::ANIMATION::BONE::S_Bone_Inform & now_bone_inform : mpr_variable.bone_list)
	{
		if (now_bone_inform.bone_name == in_bone_name)
		{
			return &now_bone_inform;
		}
	}

	// ©Â©çÈ©Á½
	return nullptr;
}


//===============//
// Ú×   F{[îñÌXgðÔ·
// ø   Fvoid
// ßèl Fconst vector<S_Bone_Inform> {[îñÌXgðÔ·(const)
//===============//
const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & C_Animation_Model_System::M_Get_Bone_Inform_List(void)
{
	return mpr_variable.bone_list;
}


//-- `æ --//

//===============//
// Ú×   F3Dfð`æ·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Animation_Model_System::M_Draw_3D_Model(void)
{
	// ¸_ðZbg
	mpr_variable.vertex_system.M_Set_Vertex_Buffer_To_Rendering();

	// SÄÌbVð`æ
	for (ASSET::MESH::C_Mesh_Data & now_mesh_inform : mpr_variable.mesh_list)
	{
		now_mesh_inform.M_Draw_Mesh();
	}

	return;
}


//===============//
// Ú×   F3Df©çwè³ê½bV¼ÌÝ`æ·é
// ø   Fstring `æ·ébV¼i¡»è·éj
// ßèl Fvoid
//===============//
void C_Animation_Model_System::M_Draw_Meshes_By_Name(std::string in_draw_mesh_name)
{
	// ¸_ðZbg
	mpr_variable.vertex_system.M_Set_Vertex_Buffer_To_Rendering();

	// SÄÌbV©ç`æ·ébV¼Æ¯¶bVÌÝ`æ
	for (ASSET::MESH::C_Mesh_Data & now_mesh_inform : mpr_variable.mesh_list)
	{
		if (now_mesh_inform.M_Get_Mesh_Name() == in_draw_mesh_name)
		{
			now_mesh_inform.M_Draw_Mesh();
		}
	}

	return;
}


//===============//
// Ú×   F}eAðÝè¹¸ÉA3Dfð`æ·éi`æOÉ}eAðZbg·éÆ«pj
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Animation_Model_System::M_Draw_3D_Model_Do_Not_Use_Material(void)
{
	// ¸_ðZbg
	mpr_variable.vertex_system.M_Set_Vertex_Buffer_To_Rendering();

	// SÄÌbVð`æ
	for (ASSET::MESH::C_Mesh_Data & now_mesh_inform : mpr_variable.mesh_list)
	{
		now_mesh_inform.M_Draw_Mesh_Do_Not_Set_Material();
	}

	return;
}


//===============//
// Ú×   F}eAðÝè¹¸ÉA3Df©çwè³ê½bV¼ÌÝ`æ·éi`æOÉ}eAðZbg·éÆ«pj
// ø   Fstring `æ·ébV¼i¡»è·éj
// ßèl Fvoid
//===============//
void C_Animation_Model_System::M_Draw_Meshes_By_Name_Do_Not_Use_Material(std::string in_draw_mesh_name)
{
	// ¸_ðZbg
	mpr_variable.vertex_system.M_Set_Vertex_Buffer_To_Rendering();

	// SÄÌbV©ç`æ·ébV¼Æ¯¶bVÌÝ`æ
	for (ASSET::MESH::C_Mesh_Data & now_mesh_inform : mpr_variable.mesh_list)
	{
		if (now_mesh_inform.M_Get_Mesh_Name() == in_draw_mesh_name)
		{
			now_mesh_inform.M_Draw_Mesh_Do_Not_Set_Material();
		}
	}

	return;
}


//-- èobt@ --//

//===============//
// Ú×   F{[Ì}gNXð}eAÉZbg·é
// ø   Fconst vector<XMFLOAT4X4> & Zbg·é{[}gNXzñÌQÆ(const)
// ßèl Fvoid
//===============//
void C_Animation_Model_System::M_Set_Bone_Matrix(const std::vector<DirectX::XMFLOAT4X4> & in_bone_matrix_list)
{
	//  Ïé¾  //
	int bone_sum = (int)mpr_variable.bone_list.size();	// {[


	// Zbg·é{[}gNXzñª»ÝÌ{[îñÆêvµÈ¢ÈçðµÈ¢
	if (bone_sum != in_bone_matrix_list.size())
	{
		return;
	}

	// SÄÌbVÉ{[ðZbg·é
	for (ASSET::MESH::C_Mesh_Data & now_mesh_inform : mpr_variable.mesh_list)
	{
		now_mesh_inform.M_Get_Material_User().M_Get_Material_Address()->M_Set_Bone_Matrix(in_bone_matrix_list);
	}

	return;
}


//===============//
// Ú×   F[h r[ vWFNVðCJð³Éèobt@ÉZbg·é
// ø   Fconst C_Transform & gXtH[ÌQÆiconstj
// ßèl Fvoid
//===============//
void C_Animation_Model_System::M_Set_World_View_Projection_With_Main_Camera_By_Transform(const MATH::C_Transform & in_transform)
{
	//  Ïé¾  //
	MATH::WVP::S_World_View_Projection_Data in_set_wvp;	// [h r[ vWFNVÌ}gNXãû


	// [h}gNXð¶¬
	in_transform.M_Generate_Matrix(in_set_wvp.world);

	// r[}gNXðZbg
	in_set_wvp.view = GAME::CAMERA::MAIN_CAMERA::C_Main_Camera::M_Get_View_Matrix();

	// vWFNV}gNXðZbg
	in_set_wvp.projection = GAME::CAMERA::MAIN_CAMERA::C_Main_Camera::M_Get_Projection_Matrix();

	// SÄÌbVÌ}eAÉgXtH[ðZbg
	for (ASSET::MESH::C_Mesh_Data & now_mesh : mpr_variable.mesh_list)
	{
		now_mesh.M_Get_Material_User().M_Get_Material_Address()->M_Set_WVP_Matrix(in_set_wvp);
	}

	return;
}


//===============//
// Ú×   F[h r[ vWFNVðCJð³Éèobt@ÉZbg·éA[h}gNXðó¯æé
// ø   Fconst XMMATRIX & [h}gNXÌQÆiconstj
// ßèl Fvoid
//===============//
void C_Animation_Model_System::M_Set_World_View_Projection_With_Main_Camera_By_World_Matrix(const DirectX::XMMATRIX & in_world_matrix)
{
	//  Ïé¾  //
	MATH::WVP::S_World_View_Projection_Data in_set_wvp;	// [h r[ vWFNVÌ}gNXãû


	// [h}gNXð¶¬
	in_set_wvp.world = in_world_matrix;

	// r[}gNXðZbg
	in_set_wvp.view = GAME::CAMERA::MAIN_CAMERA::C_Main_Camera::M_Get_View_Matrix();

	// vWFNV}gNXðZbg
	in_set_wvp.projection = GAME::CAMERA::MAIN_CAMERA::C_Main_Camera::M_Get_Projection_Matrix();

	// SÄÌbVÌ}eAÉgXtH[ðZbg
	for (ASSET::MESH::C_Mesh_Data & now_mesh : mpr_variable.mesh_list)
	{
		now_mesh.M_Get_Material_User().M_Get_Material_Address()->M_Set_WVP_Matrix(in_set_wvp);
	}

	return;
}


















































//======================================================================
// Copyright 2023 ûüâ´½
// 
// àµà±ÌR[hð©ªÌvWFNgÉpµ½¢ÌÅ êÎA
// [AhXFtakasaka.ryusei1116@gmail.com
// Ü½ÍAûüâ´½ÜÅ²A­¾³¢B
// R[hÌs¾ªÌðàâAÅVÌóÔÌñÈÇÉÎ¢½µÜ·B
//======================================================================
