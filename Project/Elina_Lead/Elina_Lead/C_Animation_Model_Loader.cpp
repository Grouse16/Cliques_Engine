//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�������f���̃��[�h������V�X�e��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Animation_Model_Loader.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::ANIMATION_MODEL::LOADER;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�p�X�̃t�@�C�������[�h���A�A�j���[�V�������f���̃f�[�^�ł��邩�ǂ����𔻒肷��
// ����   �Fstring �t�@�C���̃p�X, C_Text_And_File_Manager & ���[�h���������f�[�^�̎擾��̎Q��
// �߂�l �Fbool ���[�h�ɐ����A���A�j���[�V�������f���̃f�[�^�ł���ꍇ�̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Animation_Model_Loader::M_Load_Animation_Model_File(std::string in_file_path, SYSTEM::TEXT::C_Text_And_File_Manager & in_file_text)
{
	// �t�@�C�����Z�b�g
	in_file_text.M_Set_File_Path(in_file_path);


	// �w�肳�ꂽ�t�@�C�������[�h�@���[�h�Ɏ��s���̓G���[���o���Ĕ�����
	if (in_file_text.M_Load_Now_File() == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "�t�@�C���̎擾�Ɏ��s���܂����F" + in_file_path);
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return false;
	}

	// �F�ؖ���T������
	if (in_file_text.M_Check_Text_Is_Eqaul_Now_Position("This-Is-ELANMMDL") == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "���̃t�@�C����.elanmmdl�`���ł͂���܂���F" + in_file_path);
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return false;
	}

	// �t�@�C���̃��[�h�ɐ��������̂�true
	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�������f���̒��_�f�[�^��ǂݍ��܂ꂽ�f�[�^�����Ƀ��[�h����
// ����   �FC_Text_And_File_Manager & ���[�h�������f���̃t�@�C���f�[�^�̎Q��, C_Object_Vertex_System<S_3D_Animation_Model_Vertex> & �ݒ��̒��_�f�[�^�̎Q��
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Animation_Model_Loader::M_Load_Animation_Model_Vertex(SYSTEM::TEXT::C_Text_And_File_Manager & in_model_file_data, RENDERING::CAPSULE::C_Object_Vertex_System<DATA::VERTEX::S_3D_Animation_Model_Vertex>& in_vertex_system)
{
	// �� �ϐ��錾 �� //
	std::vector<DATA::VERTEX::S_3D_Animation_Model_Vertex> & vertex_data_list = in_vertex_system.M_Get_Vertex_Data();	// ���_�f�[�^�̃��X�g�̎Q��


	// ���_���̈ʒu�ֈړ��A�Ȃ���΃G���[��Ԃ��ďI��
	if (in_model_file_data.M_Goto_Right_By_Text_In_Front_Row("VERTSUM:") == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log
		(
			DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT,
			DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
			"���_�������o�ł��܂���ł����F" + in_model_file_data.M_Get_File_Path_Refer()
		);
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return false;
	}

	// ���_�����擾���A���_�������������m�ۂ����_�o�b�t�@�𐶐�
	in_vertex_system.M_Create_Vertex_Data_And_Buffer((int)in_model_file_data.M_Get_Number());

	// ���_�f�[�^�����[�h
	for (DATA::VERTEX::S_3D_Animation_Model_Vertex & l_now_vertex_data : vertex_data_list)
	{
		// ���݂̒��_�f�[�^�܂ňړ�
		in_model_file_data.M_Move_Next_Raw();

		// ���_���W�̃��[�h
		l_now_vertex_data.vertex.x = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.vertex.y = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.vertex.z = (float)in_model_file_data.M_Get_Float_Double_Number();

		// UV���W�̃��[�h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.uv.u = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.uv.v = (float)in_model_file_data.M_Get_Float_Double_Number();

		// �F�̃��[�h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.color.m_r = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.color.m_g = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.color.m_b = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.color.m_a = (float)in_model_file_data.M_Get_Float_Double_Number();

		// �@���x�N�g���̃��[�h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.normal.x = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.normal.y = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.normal.z = (float)in_model_file_data.M_Get_Float_Double_Number();

		// �^���W�F���g�x�N�g���̃��[�h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.tangent.x = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.tangent.y = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.tangent.z = (float)in_model_file_data.M_Get_Float_Double_Number();

		// �o�C�m�[�}���^���W�F���g�x�N�g���i�]�@���x�N�g���j�̃��[�h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(":");
		l_now_vertex_data.binormal_tangent.x = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.binormal_tangent.y = (float)in_model_file_data.M_Get_Float_Double_Number();
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		l_now_vertex_data.binormal_tangent.z = (float)in_model_file_data.M_Get_Float_Double_Number();

		// �{�[���E�F�C�g�i�{�[���e���l�j���̈ʒu�ֈړ�
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(":");

		// �{�[���E�F�C�g���̏I���̋L�������邩�A�S��J��Ԃ��܂ŁA�{�[���E�F�C�g�������[�h��������
		for (int loop_cnt = 0; loop_cnt < DATA::VERTEX::con_BONE_WEIGHT_INDEX_SUM || in_model_file_data.M_Get_Text_Of_Now_Position() != ':'; loop_cnt++)
		{
			l_now_vertex_data.bone_weight[loop_cnt].bone_index = (int)in_model_file_data.M_Get_Number();
			in_model_file_data.M_Goto_Right_By_Text_In_Front_Column("/");
			l_now_vertex_data.bone_weight[loop_cnt].weight = (float)in_model_file_data.M_Get_Float_Double_Number();
			in_model_file_data.M_Goto_Right_By_Text_In_Front_Column(",");
		}
	}

	// ���_�o�b�t�@�Ƀf�[�^��ݒ肵���_�f�[�^�̂ݍ폜�A���_�o�b�t�@�͎c��
	in_vertex_system.M_Set_Vertex_Data_To_Buffer();
	in_vertex_system.M_Delete_Vertex_Data();

	// ���������̂�true
	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�������f���̃{�[���f�[�^��ǂݍ��܂ꂽ�f�[�^�����Ƀ��[�h����
// ����   �FC_Text_And_File_Manager & ���[�h�������f���̃t�@�C���f�[�^�̎Q��, vector<S_Bone_Inform> &  �ݒ��̃{�[���f�[�^�̎Q��
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Animation_Model_Loader::M_Load_Animation_Model_Bone(SYSTEM::TEXT::C_Text_And_File_Manager & in_model_file_data, std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & in_bone_system)
{
	// �{�[�����̈ʒu�ֈړ��A�Ȃ���΃G���[��Ԃ��ďI��
	if (in_model_file_data.M_Goto_Right_By_Text_In_Front_Row("BONESUM:") == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log
		(
			DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT,
			DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
			"�{�[���������o�ł��܂���ł����F" + in_model_file_data.M_Get_File_Path_Refer()
		);
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return false;
	}

	
	// �{�[�������擾���A�{�[���������������m��
	in_bone_system.resize((int)in_model_file_data.M_Get_Number());

	// �{�[���f�[�^�����[�h
	for (ASSET::ANIMATION::BONE::S_Bone_Inform & l_now_bone_inform : in_bone_system)
	{
		// ���݂̃{�[���̃f�[�^�܂ňړ�
		in_model_file_data.M_Move_Next_Raw();


		// �{�[�������擾
		l_now_bone_inform.bone_name = in_model_file_data.M_Get_Data_By_Text("/");


		// �e�{�[���̃C���f�b�N�X���擾
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence("/");
		l_now_bone_inform.parent_bone_index = (int)in_model_file_data.M_Get_Number();


		// �q�{�[���̃C���f�b�N�X���擾
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence("/");
		while (in_model_file_data.M_Get_Data_By_Number(1) != "/")
		{
			l_now_bone_inform.children_bone_index_list.reserve(l_now_bone_inform.children_bone_index_list.size());
			l_now_bone_inform.children_bone_index_list.emplace_back((int)in_model_file_data.M_Get_Number());
			in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(",");
		}


		// �I�t�Z�b�g�}�g���N�XA�P�����[�h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence("/");
		l_now_bone_inform.offset_matrix._11 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// �I�t�Z�b�g�}�g���N�XA�Q�����[�h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._12 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// �I�t�Z�b�g�}�g���N�XA�R�����[�h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._13 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// �I�t�Z�b�g�}�g���N�XA�S�����[�h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._14 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// �I�t�Z�b�g�}�g���N�XB�P�����[�h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._21 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// �I�t�Z�b�g�}�g���N�XB�Q�����[�h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._22 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// �I�t�Z�b�g�}�g���N�XB�R�����[�h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._23 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// �I�t�Z�b�g�}�g���N�XB�S�����[�h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._24 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// �I�t�Z�b�g�}�g���N�XC�P�����[�h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._31 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// �I�t�Z�b�g�}�g���N�XC�Q�����[�h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._32 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// �I�t�Z�b�g�}�g���N�XC�R�����[�h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._33 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// �I�t�Z�b�g�}�g���N�XC�S�����[�h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._34 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// �I�t�Z�b�g�}�g���N�XD�P�����[�h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._41 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// �I�t�Z�b�g�}�g���N�XD�Q�����[�h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._42 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// �I�t�Z�b�g�}�g���N�XD�R�����[�h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._43 = (float)in_model_file_data.M_Get_Float_Double_Number();

		// �I�t�Z�b�g�}�g���N�XD�S�����[�h
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		l_now_bone_inform.offset_matrix._44 = (float)in_model_file_data.M_Get_Float_Double_Number();
	}

	// ���������̂�true
	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�������f���̃��b�V����ǂݍ��܂ꂽ�f�[�^�����Ƀ��[�h����
// ����   �FC_Text_And_File_Manager & ���[�h�������f���̃t�@�C���f�[�^�̎Q��, vector<C_Animative_Mesh> &  �ݒ��̃{�[���f�[�^�̎Q��
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Animation_Model_Loader::M_Load_Animation_Model_Mesh(SYSTEM::TEXT::C_Text_And_File_Manager & in_model_file_data, std::vector<ASSET::ANIMATION::MESH::C_Animative_Mesh> & in_mesh_system)
{
	// ���b�V�����̈ʒu�ֈړ��A�Ȃ���΃G���[��Ԃ��ďI��
	if (in_model_file_data.M_Goto_Right_By_Text_In_Front_Row("MESHSUM:") == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log
		(
			DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT,
			DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
			"���b�V���������o�ł��܂���ł����F" + in_model_file_data.M_Get_File_Path_Refer()
		);
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return false;
	}


	// ���b�V�������擾���A���b�V���������������m��
	in_mesh_system.resize((int)in_model_file_data.M_Get_Number());


	// ���b�V���f�[�^�����[�h
	for (ASSET::ANIMATION::MESH::C_Animative_Mesh & l_now_mesh : in_mesh_system)
	{
		// �� �ϐ��錾 �� //
		std::vector<unsigned int> & index_list = l_now_mesh.M_Get_Index_Data_List();	// ���b�V�����g�p���钸�_�C���f�b�N�X�̃��X�g�̎Q��


		// ���̃��b�V�����̊J�n�ʒu�ֈړ�
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Row("MESH:");


		// ���b�V�������擾
		in_model_file_data.M_Move_Next_Raw();
		l_now_mesh.M_Set_Name(in_model_file_data.M_Get_Data_Now_Row());


		// ���b�V���̃}�e���A�������[�h�@���[�h���s�ŃG���[���o���Ĕ�����
		in_model_file_data.M_Move_Raw_By_Number(2);
		in_model_file_data.M_Goto_Column_By_Set_Number(0);
		if (l_now_mesh.M_Load_Material_By_Name(in_model_file_data.M_Get_Data_Now_Row()) == false)
		{
#ifdef _DEBUG
			DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::C_Log_System::M_Print_Log
			(
				DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP,
				DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
				"�}�e���A���̃��[�h�Ɏ��s���܂����B�A�j���[�V�����p���f���F" + in_model_file_data.M_Get_File_Path_Refer() + "�@�}�e���A���F" + in_model_file_data.M_Get_Data_Now_Row()
			);
			DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

			return false;
		}


		// ���_�C���f�b�N�X�����擾���āA���_�C���f�b�N�X�f�[�^�𐶐�
		in_model_file_data.M_Goto_Right_By_Text_In_Front_Row("INDEX:");
		l_now_mesh.M_Create_Index_List((int)in_model_file_data.M_Get_Number());

		// ���_�C���f�b�N�X�f�[�^�����[�h
		for (unsigned __int32 & now_index_data : index_list)
		{
			in_model_file_data.M_Move_Next_Raw();
			now_index_data = (unsigned int)in_model_file_data.M_Get_Number();
		}

		// ���_�C���f�b�N�X��񕪂̃o�b�t�@�𐶐����A�f�[�^���o�b�t�@�ɃZ�b�g�A���̌�f�[�^�͎g�p���Ȃ��̂ō폜�i�o�b�t�@�͎c��j
		l_now_mesh.M_Attach_Index_Data_To_Buffer();
		l_now_mesh.M_Delete_Index_Data();
	}

	// ���������̂�true
	return true;
}

