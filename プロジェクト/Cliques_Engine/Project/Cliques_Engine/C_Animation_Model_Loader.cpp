////
// Ú×   FAj[VfÌ[hð·éVXe
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Animation_Model_Loader.h"

#include "C_Console_Log_Interface.h"


//  l[Xy[XÌÈª  //
using namespace ASSET::ANIMATION_MODEL::LOADER;


//  Ö  //

//== pubN ==//

//-- [h --//

//===============//
// Ú×   Fwè³ê½pXÌt@Cð[hµAAj[VfÌf[^Å é©Ç¤©ð»è·é
// ø   Fstring t@CÌpX, C_Text_And_File_Manager & [hµ½¶f[^Ìæ¾æÌQÆ
// ßèl Fbool [hÉ¬÷A©ÂAj[VfÌf[^Å éêÌÝtrue
//===============//
bool C_Animation_Model_Loader::M_Load_Animation_Model_File(std::string in_file_path, SYSTEM::TEXT::C_Text_And_File_Manager & in_file_text)
{
	// t@CðZbg
	in_file_text.M_Set_File_Path(in_file_path);


	// wè³ê½t@Cð[h@[hÉ¸sÍG[ðoµÄ²¯é
	if (in_file_text.M_Load_Now_File() == false)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "t@CÌæ¾É¸sµÜµ½F" + in_file_path);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}

	// FØ¼ðTõ·é
	if (in_file_text.M_Check_Text_Is_Equal_Now_Position("This-Is-ELANMMDL") == false)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "±Ìt@CÍ.elanmmdl`®ÅÍ èÜ¹ñF" + in_file_path);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}

	// t@CÌ[hÉ¬÷µ½ÌÅtrue
	return true;
}


//===============//
// Ú×   FAj[VfÌ¸_f[^ðÇÝÜê½f[^ð³É[h·é
// ø   FC_Text_And_File_Manager & [hµ½fÌt@Cf[^ÌQÆ, C_Object_Vertex_System<S_3D_Animation_Model_Vertex> & ÝèæÌ¸_f[^ÌQÆ
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_Animation_Model_Loader::M_Load_Animation_Model_Vertex(SYSTEM::TEXT::C_Text_And_File_Manager & in_model_file_data, RENDERING::CAPSULE::C_Object_Vertex_System<DATA::VERTEX::S_3D_Animation_Model_Vertex>& in_vertex_system)
{
	//  Ïé¾  //
	std::vector<DATA::VERTEX::S_3D_Animation_Model_Vertex> & vertex_data_list = in_vertex_system.M_Get_Vertex_Data();	// ¸_f[^ÌXgÌQÆ


	// ¸_ÌÊuÖÚ®AÈ¯êÎG[ðÔµÄI¹
	if (in_model_file_data.M_Goto_Right_By_Text_In_Front_Row("VERTSUM:") == false)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_OBJECT,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
			"¸_ðoÅ«Ü¹ñÅµ½F" + in_model_file_data.M_Get_File_Path_Refer()
		);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}

	// ¸_ðæ¾µA¸_ªðmÛµ¸_obt@ð¶¬
	in_vertex_system.M_Create_Vertex_Data_And_Buffer((int)in_model_file_data.M_Get_Number());

	// ¸_f[^ð[h
	for (DATA::VERTEX::S_3D_Animation_Model_Vertex & l_now_vertex_data : vertex_data_list)
	{
		// »ÝÌ¸_f[^ÜÅÚ®
		in_model_file_data.M_Move_Next_Raw();

		// ¸_ÀWÌ[h
		l_now_vertex_data.vertex.x = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.vertex.y = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.vertex.z = (float)in_model_file_data.M_Get_Float_Double_Number();

		// UVÀWÌ[h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.uv.u = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.uv.v = (float)in_model_file_data.M_Get_Float_Double_Number();

		// FÌ[h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.color.m_r = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.color.m_g = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.color.m_b = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.color.m_a = (float)in_model_file_data.M_Get_Float_Double_Number();

		// @üxNgÌ[h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.normal.x = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.normal.y = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.normal.z = (float)in_model_file_data.M_Get_Float_Double_Number();

		// ^WFgxNgÌ[h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.tangent.x = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.tangent.y = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.tangent.z = (float)in_model_file_data.M_Get_Float_Double_Number();

		// oCm[}^WFgxNgi]@üxNgjÌ[h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.binormal_tangent.x = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.binormal_tangent.y = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.binormal_tangent.z = (float)in_model_file_data.M_Get_Float_Double_Number();

		// {[EFCgi{[e¿ljîñÌÊuÖÚ®
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(":");

		// {[EFCgîñÌI¹ÌLª­é©ASñJèÔ·ÜÅA{[EFCgîñð[hµ±¯é
		for (int loop_cnt = 0; loop_cnt < DATA::VERTEX::con_BONE_WEIGHT_INDEX_SUM || in_model_file_data.M_Get_Text_Of_Now_Position() != ':'; loop_cnt++)
		{
			l_now_vertex_data.bone_weight[loop_cnt].bone_index = (int)in_model_file_data.M_Get_Number();
			in_model_file_data.M_Goto_Right_By_Text_In_Front_Column("/");
			l_now_vertex_data.bone_weight[loop_cnt].weight = (float)in_model_file_data.M_Get_Float_Double_Number();
			in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		}
	}

	// ¸_obt@Éf[^ðÝèµ¸_f[^ÌÝíA¸_obt@Ícé
	in_vertex_system.M_Set_Vertex_Data_To_Buffer();
	in_vertex_system.M_Delete_Vertex_Data();

	// ¬÷µ½ÌÅtrue
	return true;
}


//===============//
// Ú×   FAj[VfÌ{[f[^ðÇÝÜê½f[^ð³É[h·é
// ø   FC_Text_And_File_Manager & [hµ½fÌt@Cf[^ÌQÆ, vector<S_Bone_Inform> &  ÝèæÌ{[f[^ÌQÆ
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_Animation_Model_Loader::M_Load_Animation_Model_Bone(SYSTEM::TEXT::C_Text_And_File_Manager & in_model_file_data, std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & in_bone_system)
{
	// {[ÌÊuÖÚ®AÈ¯êÎG[ðÔµÄI¹
	if (in_model_file_data.M_Goto_Right_By_Text_In_Front_Row("BONESUM:") == false)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_OBJECT,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
			"{[ðoÅ«Ü¹ñÅµ½F" + in_model_file_data.M_Get_File_Path_Refer()
		);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}

	
	// {[ðæ¾µA{[ªðmÛ
	in_bone_system.resize((int)in_model_file_data.M_Get_Number());

	// {[f[^ð[h
	for (ASSET::ANIMATION::BONE::S_Bone_Inform & l_now_bone_inform : in_bone_system)
	{
		// »ÝÌ{[Ìf[^ÜÅÚ®
		in_model_file_data.M_Move_Next_Raw();


		// {[¼ðæ¾
		l_now_bone_inform.bone_name = in_model_file_data.M_Get_Data_By_Text("/");


		// e{[ÌCfbNXðæ¾
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence("/");
		l_now_bone_inform.parent_bone_index = (int)in_model_file_data.M_Get_Number();


		// q{[ÌCfbNXðæ¾
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence("/");
		while (in_model_file_data.M_Get_Data_By_Number(1) != "/")
		{
			l_now_bone_inform.children_bone_index_list.reserve(l_now_bone_inform.children_bone_index_list.size());
			l_now_bone_inform.children_bone_index_list.emplace_back((int)in_model_file_data.M_Get_Number());
			in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(",");
		}


		// ItZbg}gNXAPð[h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence("/");
		l_now_bone_inform.offset_matrix._11 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// ItZbg}gNXAQð[h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._12 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// ItZbg}gNXARð[h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._13 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// ItZbg}gNXASð[h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._14 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// ItZbg}gNXBPð[h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._21 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// ItZbg}gNXBQð[h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._22 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// ItZbg}gNXBRð[h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._23 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// ItZbg}gNXBSð[h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._24 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// ItZbg}gNXCPð[h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._31 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// ItZbg}gNXCQð[h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._32 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// ItZbg}gNXCRð[h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._33 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// ItZbg}gNXCSð[h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._34 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// ItZbg}gNXDPð[h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._41 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// ItZbg}gNXDQð[h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._42 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// ItZbg}gNXDRð[h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._43 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// ItZbg}gNXDSð[h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._44 = (float)in_model_file_data.M_Get_Float_Double_Number();
	}

	// ¬÷µ½ÌÅtrue
	return true;
}


//===============//
// Ú×   FAj[VfÌbVðÇÝÜê½f[^ð³É[h·é
// ø   FC_Text_And_File_Manager & [hµ½fÌt@Cf[^ÌQÆ, vector<C_Mesh_Data> &  ÝèæÌ{[f[^ÌQÆ
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_Animation_Model_Loader::M_Load_Animation_Model_Mesh(SYSTEM::TEXT::C_Text_And_File_Manager & in_model_file_data, std::vector<ASSET::MESH::C_Mesh_Data> & in_mesh_system)
{
	// bVÌÊuÖÚ®AÈ¯êÎG[ðÔµÄI¹
	if (in_model_file_data.M_Goto_Right_By_Text_In_Front_Row("MESHSUM:") == false)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_OBJECT,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
			"bVðoÅ«Ü¹ñÅµ½F" + in_model_file_data.M_Get_File_Path_Refer()
		);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}


	// bVðæ¾µAbVªðmÛ
	in_mesh_system.resize((int)in_model_file_data.M_Get_Number());


	// bVf[^ð[h
	for (ASSET::MESH::C_Mesh_Data & l_now_mesh : in_mesh_system)
	{
		//  Ïé¾  //
		std::vector<unsigned int> & index_list = l_now_mesh.M_Get_Index_Data_List();	// bVªgp·é¸_CfbNXÌXgÌQÆ


		// ¡ÌbVîñÌJnÊuÖÚ®
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Row("MESH:");


		// bV¼ðæ¾
		in_model_file_data.M_Move_Next_Raw();
		l_now_mesh.M_Set_Mesh_Name(in_model_file_data.M_Get_Data_Now_Row());


		// bVÌ}eAð[h@[h¸sÅG[ðoµÄ²¯é
		in_model_file_data.M_Move_Raw_By_Number(2);
		in_model_file_data.M_Goto_Column_By_Set_Number(0);
		if (l_now_mesh.M_Load_Material_By_Name(in_model_file_data.M_Get_Data_Now_Row()) == false)
		{
			DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
			(
				DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP,
				DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
				"}eAÌ[hÉ¸sµÜµ½BAj[VpfF" + in_model_file_data.M_Get_File_Path_Refer() + "@}eAF" + in_model_file_data.M_Get_Data_Now_Row()
			);
			DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

			return false;
		}


		// ¸_CfbNXðæ¾µÄA¸_CfbNXf[^ð¶¬
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Row("INDEX:");
		l_now_mesh.M_Create_Index_List((int)in_model_file_data.M_Get_Number());

		// ¸_CfbNXf[^ð[h
		for (unsigned __int32 & now_index_data : index_list)
		{
			in_model_file_data.M_Move_Next_Raw();
			now_index_data = (unsigned int)in_model_file_data.M_Get_Number();
		}

		// ¸_CfbNXîñªÌobt@ð¶¬µAf[^ðobt@ÉZbgA»Ìãf[^ÍgpµÈ¢ÌÅíiobt@Ícéj
		l_now_mesh.M_Attach_Index_Data_To_Buffer();
		l_now_mesh.M_Delete_Index_Data();
	}

	// ¬÷µ½ÌÅtrue
	return true;
}

