////
// Ú×   FÃIfð[h·éNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_Static_Model_Loader.h"

#include "C_Console_Log_Interface.h"


//  l[Xy[XÌÈª  //
using namespace ASSET::MODEL::STATIC_MODEL::LOADER;


//  Ö  //

//== pubN ==//

//-- [h --//

//===============//
// Ú×   Fwè³ê½t@Cð[hµAÃIfÅ é©Ç¤©ð»è·é
// ø   Fstring t@C¼, C_Text_And_File_Manager & [hµ½t@Cf[^ÌL^æ
// ßèl Fbool [hÉ¬÷A©ÂÃIfÅ êÎtrue
//===============//
bool C_Static_Model_Loader::M_Load_Static_Model_File_Data(std::string in_load_file_name, SYSTEM::TEXT::C_Text_And_File_Manager & in_file_data_system)
{
	// t@CðZbg
	in_file_data_system.M_Set_File_Path(in_load_file_name);


	// wè³ê½t@Cð[h@[hÉ¸sÍG[ðoµÄ²¯é
	if (in_file_data_system.M_Load_Now_File() == false)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_OBJECT,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
			"t@CÌæ¾É¸sµÜµ½F" + in_load_file_name
		);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}

	// t@CªÃIfÅ é©Ç¤©ð»èAÃIfÅÈ¯êÎG[ðoµÄ²¯é
	if (in_file_data_system.M_Check_Text_Is_Equal_Now_Position("This-Is-ELSTTMDL") == false)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_OBJECT,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
			"±Ìt@CÍ.elsttmdl`®ÅÍ èÜ¹ñF" + in_load_file_name
		);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}

	// [hÉ¬÷µ½çtrueðÔ·
	return true;
}


//===============//
// Ú×   FÃIfÌ¸_f[^ð[h·é
// ø   FC_Text_And_File_Manager & ft@CÌf[^, C_Object_Vertex_System<S_3D_Model_Vertex> & [hæÌ¸_f[^ÌQÆ
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_Static_Model_Loader::M_Load_Static_Model_Vertex(SYSTEM::TEXT::C_Text_And_File_Manager & in_file_data, RENDERING::CAPSULE::C_Object_Vertex_System<DATA::VERTEX::S_3D_Model_Vertex> & in_vertex_system)
{
	//  Ïé¾  //
	std::vector<DATA::VERTEX::S_3D_Model_Vertex> vertex_data_list = in_vertex_system.M_Get_Vertex_Data();	// »ÝÌ¸_f[^


	// ¸_ÖÚ®AÈ¯êÎG[ðoµÄ²¯é
	if (in_file_data.M_Goto_Right_By_Text_In_Front_Row("VERTSUM:") == false)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_OBJECT,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
			"t@CÌæ¾É¸sµÜµ½F" + in_file_data.M_Get_File_Path_Refer()
		);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}

	// ¸_ðæ¾µA¸_f[^ðì¬
	in_vertex_system.M_Create_Vertex_Data_And_Buffer((int)in_file_data.M_Get_Number());


	// ¸_f[^ð[h
	for (DATA::VERTEX::S_3D_Model_Vertex & l_now_vertex_data : vertex_data_list)
	{
		// »ÝÌ¸_f[^ÜÅÚ®
		in_file_data.M_Move_Next_Raw();

		// ¸_ÀWÌ[h
		l_now_vertex_data.vertex.x = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.vertex.y = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.vertex.z = (float)in_file_data.M_Get_Float_Double_Number();

		// UVÀWÌ[h
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.uv.u = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.uv.v = (float)in_file_data.M_Get_Float_Double_Number();

		// FÌ[h
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.color.m_r = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.color.m_g = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.color.m_b = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.color.m_a = (float)in_file_data.M_Get_Float_Double_Number();

		// @üxNgÌ[h
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.normal.x = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.normal.y = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.normal.z = (float)in_file_data.M_Get_Float_Double_Number();

		// ^WFgxNgÌ[h
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.tangent.x = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.tangent.y = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.tangent.z = (float)in_file_data.M_Get_Float_Double_Number();

		// oCm[}^WFgxNgi]@üxNgjÌ[h
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.binormal_tangent.x = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.binormal_tangent.y = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.binormal_tangent.z = (float)in_file_data.M_Get_Float_Double_Number();
	}


	// ¸_f[^ðobt@ÉZbgµÄ¸_f[^ðíA¸_obt@ÌÝc·
	in_vertex_system.M_Set_Vertex_Data_To_Buffer();
	in_vertex_system.M_Delete_Vertex_Data();

	// [hÉ¬÷µ½çtrueðÔ·
	return true;
}


//===============//
// Ú×   FÃIfÌbVf[^ð[h·é
// ø   FC_Text_And_File_Manager & ft@CÌf[^, C_Object_Vertex_System<S_3D_Model_Vertex> & [hæÌ¸_f[^ÌQÆ
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_Static_Model_Loader::M_Load_Static_Model_Mesh(SYSTEM::TEXT::C_Text_And_File_Manager & in_file_data, std::vector<ASSET::MESH::C_Mesh_Data> & in_mesh_list)
{
	// bVf[^ÖÚ®AÈ¯êÎG[ðoµÄ²¯é
	if (in_file_data.M_Goto_Right_By_Text_In_Front_Row("MESHSUM:") == false)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_OBJECT,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
			"t@CÌæ¾É¸sµÜµ½F" + in_file_data.M_Get_File_Path_Refer()
		);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}

	// bVf[^ðæ¾µAbVf[^ðì¬
	in_mesh_list.resize(in_file_data.M_Get_Number());


	// bVf[^ªÇÝæé
	for (ASSET::MESH::C_Mesh_Data & now_mesh_inform : in_mesh_list)
	{
		// bVÌÊuÖÚ®
		in_file_data.M_Goto_Right_By_Text_In_Front_Row("MESH:");


		// bV¼ðæ¾
		in_file_data.M_Move_Next_Raw();
		now_mesh_inform.M_Set_Mesh_Name(in_file_data.M_Get_Data_Now_Row());


		// bVÌ}eAð[h@[h¸sÅG[ðoµÄ²¯é
		in_file_data.M_Move_Raw_By_Number(2);
		in_file_data.M_Goto_Column_By_Set_Number(0);
		if (now_mesh_inform.M_Load_Material_By_Name(in_file_data.M_Get_Data_Now_Row()) == false)
		{
			DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
			(
				DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP,
				DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
				"}eAÌ[hÉ¸sµÜµ½BfF" + in_file_data.M_Get_File_Path_Refer() + "@}eAF" + in_file_data.M_Get_Data_Now_Row()
			);
			DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

			return false;
		}


		// ¸_CfbNXðæ¾µÄA¸_CfbNXf[^ð¶¬
		in_file_data.M_Goto_Right_By_Text_In_Front_Row("INDEX:");
		now_mesh_inform.M_Create_Index_List((int)in_file_data.M_Get_Number());

		// ¸_CfbNXf[^ð[h
		for (unsigned __int32 & now_index_data : now_mesh_inform.M_Get_Index_Data_List())
		{
			in_file_data.M_Move_Next_Raw();
			now_index_data = (unsigned int)in_file_data.M_Get_Number();
		}

		// ¸_Æ¸_CfbNXîñªÌobt@ð¶¬µAf[^ðobt@ÉZbgA»Ìãf[^ÍgpµÈ¢ÌÅíiobt@Ícéj
		now_mesh_inform.M_Attach_Index_Data_To_Buffer();
		now_mesh_inform.M_Delete_Index_Data();
	}

	// [hÉ¬÷µ½çtrueðÔ·
	return true;
}


