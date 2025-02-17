//����������������������������������������������//
// �ڍ�   �F�ÓI���f�������[�h����N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Static_Model_Loader.h"

#include "C_Console_Log_Interface.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::MODEL::STATIC_MODEL::LOADER;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�t�@�C�������[�h���A�ÓI���f���ł��邩�ǂ����𔻒肷��
// ����   �Fstring �t�@�C����, C_Text_And_File_Manager & ���[�h�����t�@�C���f�[�^�̋L�^��
// �߂�l �Fbool ���[�h�ɐ����A���ÓI���f���ł����true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Static_Model_Loader::M_Load_Static_Model_File_Data(std::string in_load_file_name, SYSTEM::TEXT::C_Text_And_File_Manager & in_file_data_system)
{
	// �t�@�C�����Z�b�g
	in_file_data_system.M_Set_File_Path(in_load_file_name);


	// �w�肳�ꂽ�t�@�C�������[�h�@���[�h�Ɏ��s���̓G���[���o���Ĕ�����
	if (in_file_data_system.M_Load_Now_File() == false)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_OBJECT,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
			"�t�@�C���̎擾�Ɏ��s���܂����F" + in_load_file_name
		);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}

	// �t�@�C�����ÓI���f���ł��邩�ǂ����𔻒�A�ÓI���f���łȂ���΃G���[���o���Ĕ�����
	if (in_file_data_system.M_Check_Text_Is_Equal_Now_Position("This-Is-ELSTTMDL") == false)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_OBJECT,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
			"���̃t�@�C����.elsttmdl�`���ł͂���܂���F" + in_load_file_name
		);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}

	// ���[�h�ɐ���������true��Ԃ�
	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�ÓI���f���̒��_�f�[�^�����[�h����
// ����   �FC_Text_And_File_Manager & ���f���t�@�C���̃f�[�^, C_Object_Vertex_System<S_3D_Model_Vertex> & ���[�h��̒��_�f�[�^�̎Q��
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Static_Model_Loader::M_Load_Static_Model_Vertex(SYSTEM::TEXT::C_Text_And_File_Manager & in_file_data, RENDERING::CAPSULE::C_Object_Vertex_System<DATA::VERTEX::S_3D_Model_Vertex> & in_vertex_system)
{
	// �� �ϐ��錾 �� //
	std::vector<DATA::VERTEX::S_3D_Model_Vertex> vertex_data_list = in_vertex_system.M_Get_Vertex_Data();	// ���݂̒��_�f�[�^


	// ���_���ֈړ��A�Ȃ���΃G���[���o���Ĕ�����
	if (in_file_data.M_Goto_Right_By_Text_In_Front_Row("VERTSUM:") == false)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_OBJECT,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
			"�t�@�C���̎擾�Ɏ��s���܂����F" + in_file_data.M_Get_File_Path_Refer()
		);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}

	// ���_�����擾���A���_�f�[�^���쐬
	in_vertex_system.M_Create_Vertex_Data_And_Buffer((int)in_file_data.M_Get_Number());


	// ���_�f�[�^�����[�h
	for (DATA::VERTEX::S_3D_Model_Vertex & l_now_vertex_data : vertex_data_list)
	{
		// ���݂̒��_�f�[�^�܂ňړ�
		in_file_data.M_Move_Next_Raw();

		// ���_���W�̃��[�h
		l_now_vertex_data.vertex.x = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.vertex.y = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.vertex.z = (float)in_file_data.M_Get_Float_Double_Number();

		// UV���W�̃��[�h
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.uv.u = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.uv.v = (float)in_file_data.M_Get_Float_Double_Number();

		// �F�̃��[�h
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.color.m_r = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.color.m_g = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.color.m_b = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.color.m_a = (float)in_file_data.M_Get_Float_Double_Number();

		// �@���x�N�g���̃��[�h
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.normal.x = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.normal.y = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.normal.z = (float)in_file_data.M_Get_Float_Double_Number();

		// �^���W�F���g�x�N�g���̃��[�h
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.tangent.x = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.tangent.y = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.tangent.z = (float)in_file_data.M_Get_Float_Double_Number();

		// �o�C�m�[�}���^���W�F���g�x�N�g���i�]�@���x�N�g���j�̃��[�h
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.binormal_tangent.x = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.binormal_tangent.y = (float)in_file_data.M_Get_Float_Double_Number();
		in_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.binormal_tangent.z = (float)in_file_data.M_Get_Float_Double_Number();
	}


	// ���_�f�[�^���o�b�t�@�ɃZ�b�g���Ē��_�f�[�^���폜�A���_�o�b�t�@�̂ݎc��
	in_vertex_system.M_Set_Vertex_Data_To_Buffer();
	in_vertex_system.M_Delete_Vertex_Data();

	// ���[�h�ɐ���������true��Ԃ�
	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�ÓI���f���̃��b�V���f�[�^�����[�h����
// ����   �FC_Text_And_File_Manager & ���f���t�@�C���̃f�[�^, C_Object_Vertex_System<S_3D_Model_Vertex> & ���[�h��̒��_�f�[�^�̎Q��
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Static_Model_Loader::M_Load_Static_Model_Mesh(SYSTEM::TEXT::C_Text_And_File_Manager & in_file_data, std::vector<ASSET::MESH::C_Mesh_Data> & in_mesh_list)
{
	// ���b�V���f�[�^���ֈړ��A�Ȃ���΃G���[���o���Ĕ�����
	if (in_file_data.M_Goto_Right_By_Text_In_Front_Row("MESHSUM:") == false)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
		(
			DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_OBJECT,
			DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
			"�t�@�C���̎擾�Ɏ��s���܂����F" + in_file_data.M_Get_File_Path_Refer()
		);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}

	// ���b�V���f�[�^�����擾���A���b�V���f�[�^���쐬
	in_mesh_list.resize(in_file_data.M_Get_Number());


	// ���b�V���f�[�^���ǂݎ��
	for (ASSET::MESH::C_Mesh_Data & now_mesh_inform : in_mesh_list)
	{
		// ���b�V���̈ʒu�ֈړ�
		in_file_data.M_Goto_Right_By_Text_In_Front_Row("MESH:");


		// ���b�V�������擾
		in_file_data.M_Move_Next_Raw();
		now_mesh_inform.M_Set_Mesh_Name(in_file_data.M_Get_Data_Now_Row());


		// ���b�V���̃}�e���A�������[�h�@���[�h���s�ŃG���[���o���Ĕ�����
		in_file_data.M_Move_Raw_By_Number(2);
		in_file_data.M_Goto_Column_By_Set_Number(0);
		if (now_mesh_inform.M_Load_Material_By_Name(in_file_data.M_Get_Data_Now_Row()) == false)
		{
			DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log
			(
				DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP,
				DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
				"�}�e���A���̃��[�h�Ɏ��s���܂����B���f���F" + in_file_data.M_Get_File_Path_Refer() + "�@�}�e���A���F" + in_file_data.M_Get_Data_Now_Row()
			);
			DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

			return false;
		}


		// ���_�C���f�b�N�X�����擾���āA���_�C���f�b�N�X�f�[�^�𐶐�
		in_file_data.M_Goto_Right_By_Text_In_Front_Row("INDEX:");
		now_mesh_inform.M_Create_Index_List((int)in_file_data.M_Get_Number());

		// ���_�C���f�b�N�X�f�[�^�����[�h
		for (unsigned __int32 & now_index_data : now_mesh_inform.M_Get_Index_Data_List())
		{
			in_file_data.M_Move_Next_Raw();
			now_index_data = (unsigned int)in_file_data.M_Get_Number();
		}

		// ���_�ƒ��_�C���f�b�N�X��񕪂̃o�b�t�@�𐶐����A�f�[�^���o�b�t�@�ɃZ�b�g�A���̌�f�[�^�͎g�p���Ȃ��̂ō폜�i�o�b�t�@�͎c��j
		now_mesh_inform.M_Attach_Index_Data_To_Buffer();
		now_mesh_inform.M_Delete_Index_Data();
	}

	// ���[�h�ɐ���������true��Ԃ�
	return true;
}


