////
// Ú×   F3DfÌNX
// à¾   F3DfÌæ¾©ç`æAAj[VÌÀsÜÅðs¤
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Static_Model_System.h"
#include "C_Text_And_File_Manager.h"
#include "C_Main_Camera.h"
#include "C_Static_Model_Loader.h"

#include "C_Console_Log_Interface.h"


//  l[Xy[XÌÈª  //
using namespace ASSET::MODEL;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Static_Model_System::C_Static_Model_System(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Static_Model_System::~C_Static_Model_System(void)
{
	M_Release();

	return;
}


//===============//
// Ú×   FÌðúðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Static_Model_System::M_Release(void)
{
	for (ASSET::MESH::C_Mesh_Data & mesh_data : mpr_variable.mesh_list)
	{
		mesh_data.M_Release();
	}
	mpr_variable.mesh_list.clear();
	mpr_variable.mesh_list.shrink_to_fit();

	return;
}


//-- [h --//

//===============//
// Ú×   Fwè³ê½pXÌ3Dfð[h·é
// ø   Fstring 3DfÜÅÌpX
// ßèl Fbool ¬÷ÌÝture
//===============//
bool C_Static_Model_System::M_Load_3D_Model_By_Path(std::string in_3d_model_path)
{
	//  Ïé¾  //
	SYSTEM::TEXT::C_Text_And_File_Manager file_data;	// t@CÌf[^ðÇÝæéVXe


	// »ÝÁÄ¢éff[^Íí·é
	M_Release();


	// fÌf[^ð[h·éA¸sµ½çG[Å²¯é
	if (ASSET::MODEL::STATIC_MODEL::LOADER::C_Static_Model_Loader::M_Load_Static_Model_File_Data(in_3d_model_path, file_data) == false)
	{
		return false;
	}

	// ¸_Ìf[^ð[h·éA¸sµ½çG[Å²¯é
	if (ASSET::MODEL::STATIC_MODEL::LOADER::C_Static_Model_Loader::M_Load_Static_Model_Vertex(file_data, mpr_variable.vertex_system) == false)
	{
		return false;
	}

	// bVÌf[^ð[h·éA¸sµ½çG[Å²¯é
	if (ASSET::MODEL::STATIC_MODEL::LOADER::C_Static_Model_Loader::M_Load_Static_Model_Mesh(file_data, mpr_variable.mesh_list) == false)
	{
		return false;
	}


	// fÌ[hÌ¬÷ðm
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
	(
		DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP,
		DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT,
		"fÌ[hÉ¬÷µÜµ½F" + in_3d_model_path
	);

	return true;
}


//-- Qb^ --//

//===============//
// Ú×   Fwè³ê½¼OÌbVðÔ·
// ø   Fstring T·bVÌ¼O
// ßèl FC_Mesh_Data * ¼Oªêvµ½bVÌAhXAêvµÈ©Á½çnullptrðÔ·
//===============//
ASSET::MESH::C_Mesh_Data * C_Static_Model_System::M_Get_Mesh_Data_By_Name(std::string in_mesh_name)
{
	// êv·ébV¼ðTµA êÎ»ÌAhXðÔ·
	for (ASSET::MESH::C_Mesh_Data & now_mesh_data : mpr_variable.mesh_list)
	{
		if (now_mesh_data.M_Get_Mesh_Name() == in_mesh_name)
		{
			return &now_mesh_data;
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
std::vector<ASSET::MESH::C_Mesh_Data> & C_Static_Model_System::M_Get_Mesh_Inform_List(void)
{
	return mpr_variable.mesh_list;
}


//-- `æ --//

//===============//
// Ú×   F3Dfð`æ·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Static_Model_System::M_Draw_Model(void)
{
	// ¸_VF[_[ðZbg
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
void C_Static_Model_System::M_Draw_Meshes_By_Name(std::string in_draw_mesh_name)
{
	// ¸_VF[_[ðZbg
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
void C_Static_Model_System::M_Draw_Model_Do_Not_Use_Material(void)
{
	// ¸_VF[_[ðZbg
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
void C_Static_Model_System::M_Draw_Meshes_By_Name_Do_Not_Use_Material(std::string in_draw_mesh_name)
{
	// ¸_VF[_[ðZbg
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
// Ú×   F[h r[ vWFNVðCJð³Éèobt@ÉZbg·éAgXtH[ðó¯æé
// ø   Fconst C_Transform & gXtH[ÌQÆiconstj
// ßèl Fvoid
//===============//
void C_Static_Model_System::M_Set_World_View_Projection_With_Main_Camera_By_Transform(const MATH::C_Transform & in_transform)
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
// ø   Fconst C_Transform & [h}gNXÌQÆiconstj
// ßèl Fvoid
//===============//
void C_Static_Model_System::M_Set_World_View_Projection_With_Main_Camera_By_World_Matrix(const DirectX::XMMATRIX & in_world_matrix)
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
