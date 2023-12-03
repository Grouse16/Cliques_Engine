//����������������������������������������������//
// �ڍ�   �F3D���f���̃N���X
// ����   �F3D���f���̎擾����`��A�A�j���[�V�����̎��s�܂ł��s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_3D_Model_System.h"
#include "C_Text_And_File_Manager.h"
#include "C_Main_Camera.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::MODEL;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_3D_Model_System::C_3D_Model_System(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_3D_Model_System::~C_3D_Model_System(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������̉�����s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_3D_Model_System::M_Release(void)
{
	for (S_Mesh_Data_Inform & mesh_data : mpr_variable.mesh_inform_list)
	{
		mesh_data.mesh_data.reset();
	}
	mpr_variable.mesh_inform_list.clear();
	mpr_variable.mesh_inform_list.shrink_to_fit();

	return;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�p�X��3D���f�������[�h����
// ����   �Fstring 3D���f���܂ł̃p�X
// �߂�l �Fbool �������̂�ture
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_3D_Model_System::M_Load_3D_Model_By_Path(std::string in_3d_model_path)
{
	// �� �ϐ��錾 �� //
	SYSTEM::TEXT::C_Text_And_File_Manager file_data;	// �t�@�C���̃f�[�^��ǂݎ��V�X�e��


	// �w�肳�ꂽ�t�@�C�������[�h�@���[�h�Ɏ��s���̓G���[���o���Ĕ�����
	if (file_data.M_Load_Select_File(in_3d_model_path) == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "�t�@�C���̎擾�Ɏ��s���܂����F" + in_3d_model_path);
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return false;
	}

	// �F�ؖ���T������
	if (file_data.M_Goto_Right_By_Text_In_Front_Row("This-Is-ELSTTMDL") == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "���̃t�@�C����.elsttmdl�`���ł͂���܂���F" + in_3d_model_path);
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return false;
	}


	// ���ݎ����Ă��郂�f���f�[�^�͍폜����
	M_Release();

	
	// ���b�V���f�[�^�����擾
	file_data.M_Goto_Right_By_Text_In_Front_Row("MESHSUM:");
	mpr_variable.mesh_inform_list.resize(file_data.M_Get_Number());

	// ���b�V���f�[�^���ǂݎ��
	for(S_Mesh_Data_Inform & now_mesh_inform : mpr_variable.mesh_inform_list)
	{
		// ���b�V���̈ʒu�ֈړ�
		file_data.M_Goto_Right_By_Text_In_Front_Row("MESH:");

		// ���b�V�������擾
		file_data.M_Move_Next_Raw();
		now_mesh_inform.name = file_data.M_Get_Data_Now_Row();

		// ���b�V���f�[�^�𐶐�
		now_mesh_inform.mesh_data.reset(new ASSET::MESH::C_Mesh_Data());

		// ���b�V���̃}�e���A�������[�h�@���[�h���s�ŃG���[���o���Ĕ�����
		file_data.M_Move_Raw_By_Number(2);
		file_data.M_Goto_Column_By_Set_Number(0);
		if (now_mesh_inform.mesh_data->M_Load_Material_By_Name(file_data.M_Get_Data_Now_Row()) == false)
		{
#ifdef _DEBUG
			DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "�}�e���A���̃��[�h�Ɏ��s���܂����B���f���F" + in_3d_model_path + "-" + file_data.M_Get_Data_Now_Row());
			DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

			return false;
		}

		// ���_�����擾���A���_�f�[�^�𐶐�
		file_data.M_Goto_Right_By_Text_In_Front_Row("VERT:");
		now_mesh_inform.mesh_data->M_Create_Vertex_List(file_data.M_Get_Number());

		// ���_�f�[�^�����[�h
		for (DATA::VERTEX::S_3D_Model_Vertex & now_vertex_data : now_mesh_inform.mesh_data->M_Get_Vertex_Data_List())
		{
			// ���݂̒��_�f�[�^�܂ňړ�
			file_data.M_Move_Next_Raw();

			// ���_���W�̃��[�h
			now_vertex_data.vertex.x = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.vertex.y = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.vertex.z = file_data.M_Get_Float_Double_Number();

			// UV���W�̃��[�h
			file_data.M_Goto_Right_By_Text_In_Front_Column(":");
			now_vertex_data.uv.u = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.uv.v = file_data.M_Get_Float_Double_Number();

			// �F�̃��[�h
			file_data.M_Goto_Right_By_Text_In_Front_Column(":");
			now_vertex_data.color.m_r = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.color.m_g = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.color.m_b = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.color.m_a = file_data.M_Get_Float_Double_Number();

			// �@���x�N�g���̃��[�h
			file_data.M_Goto_Right_By_Text_In_Front_Column(":");
			now_vertex_data.normal.x = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.normal.y = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.normal.z = file_data.M_Get_Float_Double_Number();

			// �^���W�F���g�x�N�g���̃��[�h
			file_data.M_Goto_Right_By_Text_In_Front_Column(":");
			now_vertex_data.tangent.x = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.tangent.y = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.tangent.z = file_data.M_Get_Float_Double_Number();

			// �o�C�m�[�}���^���W�F���g�x�N�g���i�]�@���x�N�g���j�̃��[�h
			file_data.M_Goto_Right_By_Text_In_Front_Column(":");
			now_vertex_data.binormal_tangent.x = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.binormal_tangent.y = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.binormal_tangent.z = file_data.M_Get_Float_Double_Number();
		}

		// ���_�C���f�b�N�X�����擾���āA���_�C���f�b�N�X�f�[�^�𐶐�
		file_data.M_Goto_Right_By_Text_In_Front_Row("INDEX:");
		now_mesh_inform.mesh_data->M_Create_Index_List(file_data.M_Get_Number());

		// ���_�C���f�b�N�X�f�[�^�����[�h
		for (unsigned __int32 & now_index_data : now_mesh_inform.mesh_data->M_Get_Index_Data_List())
		{
			file_data.M_Move_Next_Raw();
			now_index_data = file_data.M_Get_Number();
		}

		// ���_�ƒ��_�C���f�b�N�X��񕪂̃o�b�t�@�𐶐����A�f�[�^���o�b�t�@�ɃZ�b�g�A���̌�f�[�^�͎g�p���Ȃ��̂ō폜�i�o�b�t�@�͎c��j
		now_mesh_inform.mesh_data->M_Create_Vertex_Buffer_And_Index_Buffer();
		now_mesh_inform.mesh_data->M_Attach_Vertex_Data_To_Buffer();
		now_mesh_inform.mesh_data->M_Attach_Index_Data_To_Buffer();
		now_mesh_inform.mesh_data->M_Delete_Vertex_Data();
		now_mesh_inform.mesh_data->M_Delete_Index_Data();
	}

	// ���[�h�ɐ����A�f�o�b�O���͐������O��\��
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "���f���̃��[�h�ɐ������܂����F" + in_3d_model_path);
#endif // _DEBUG

	return true;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃��b�V����Ԃ�
// ����   �Fstring �T�����b�V���̖��O
// �߂�l �FC_3D_Model_System::S_Mesh_Data_Inform * ���O����v�������b�V���̃A�h���X�A��v���Ȃ�������nullptr��Ԃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_3D_Model_System::S_Mesh_Data_Inform * C_3D_Model_System::M_Get_Mesh_Data_By_Name(std::string in_mesh_name)
{
	// ��v���郁�b�V������T���A����΂��̃A�h���X��Ԃ�
	for (S_Mesh_Data_Inform & now_mesh_data : mpr_variable.mesh_inform_list)
	{
		if (now_mesh_data.name == in_mesh_name)
		{
			return &now_mesh_data;
		}
	}

	// ������Ȃ�����
	return nullptr;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���b�V�����̃��X�g�̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �Fvector<C_3D_Model_System::S_Mesh_Data_Inform> & ���b�V�����̃��X�g�̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::vector<C_3D_Model_System::S_Mesh_Data_Inform> & C_3D_Model_System::M_Get_Mesh_Inform_List(void)
{
	return mpr_variable.mesh_inform_list;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F3D���f����`�悷��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_3D_Model_System::M_Draw_Model(void)
{
	// �S�Ẵ��b�V����`��
	for (S_Mesh_Data_Inform & now_mesh_inform : mpr_variable.mesh_inform_list)
	{
		now_mesh_inform.mesh_data->M_Draw_Mesh();
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F3D���f������w�肳�ꂽ���b�V�����̂ݕ`�悷��
// ����   �Fstring �`�悷�郁�b�V�����i�������肷��j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_3D_Model_System::M_Draw_Meshes_By_Name(std::string in_draw_mesh_name)
{
	// �S�Ẵ��b�V������`�悷�郁�b�V�����Ɠ������b�V���̂ݕ`��
	for (S_Mesh_Data_Inform & now_mesh_inform : mpr_variable.mesh_inform_list)
	{
		if (now_mesh_inform.name == in_draw_mesh_name)
		{
			now_mesh_inform.mesh_data->M_Draw_Mesh();
		}
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�}�e���A����ݒ肹���ɁA3D���f����`�悷��i�`��O�Ƀ}�e���A�����Z�b�g����Ƃ��p�j
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_3D_Model_System::M_Draw_Model_Do_Not_Use_Material(void)
{
	// �S�Ẵ��b�V����`��
	for (S_Mesh_Data_Inform & now_mesh_inform : mpr_variable.mesh_inform_list)
	{
		now_mesh_inform.mesh_data->m_Draw_Mesh_Do_Not_Set_Material();
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�}�e���A����ݒ肹���ɁA3D���f������w�肳�ꂽ���b�V�����̂ݕ`�悷��i�`��O�Ƀ}�e���A�����Z�b�g����Ƃ��p�j
// ����   �Fstring �`�悷�郁�b�V�����i�������肷��j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_3D_Model_System::M_Draw_Meshes_By_Name_Do_Not_Use_Material(std::string in_draw_mesh_name)
{
	// �S�Ẵ��b�V������`�悷�郁�b�V�����Ɠ������b�V���̂ݕ`��
	for (S_Mesh_Data_Inform & now_mesh_inform : mpr_variable.mesh_inform_list)
	{
		if (now_mesh_inform.name == in_draw_mesh_name)
		{
			now_mesh_inform.mesh_data->m_Draw_Mesh_Do_Not_Set_Material();
		}
	}

	return;
}


//-��- �萔�o�b�t�@ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���[���h �r���[ �v���W�F�N�V���������C���J���������ɒ萔�o�b�t�@�ɃZ�b�g����A�g�����X�t�H�[�����󂯎��
// ����   �Fconst C_Transform & �g�����X�t�H�[���̎Q�Ɓiconst�j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_3D_Model_System::M_Set_World_View_Projection_With_Main_Camera_By_Transform(const MATH::C_Transform & in_transform)
{
	// �� �ϐ��錾 �� //
	MATH::WVP::S_World_View_Projection_Data in_set_wvp;	// ���[���h �r���[ �v���W�F�N�V�����̃}�g���N�X���
	

	// ���[���h�}�g���N�X�𐶐�
	in_transform.M_Generate_World_Matrix(in_set_wvp.world);

	// �r���[�}�g���N�X���Z�b�g
	in_set_wvp.view = GAME::CAMERA::MAIN_CAMERA::C_Main_Camera::M_Get_View_Matrix();

	// �v���W�F�N�V�����}�g���N�X���Z�b�g
	in_set_wvp.projection = GAME::CAMERA::MAIN_CAMERA::C_Main_Camera::M_Get_Projection_Matrix();

	// �S�Ẵ��b�V���̃}�e���A���Ƀg�����X�t�H�[�����Z�b�g
	for (S_Mesh_Data_Inform & now_mesh : mpr_variable.mesh_inform_list)
	{
		now_mesh.mesh_data->M_Get_Material_User().M_Get_Material_Address()->M_Set_WVP_Matrix(in_set_wvp);
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���[���h �r���[ �v���W�F�N�V���������C���J���������ɒ萔�o�b�t�@�ɃZ�b�g����A���[���h�}�g���N�X���󂯎��
// ����   �Fconst C_Transform & ���[���h�}�g���N�X�̎Q�Ɓiconst�j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_3D_Model_System::M_Set_World_View_Projection_With_Main_Camera_By_World_Matrix(const DirectX::XMMATRIX & in_world_matrix)
{
	// �� �ϐ��錾 �� //
	MATH::WVP::S_World_View_Projection_Data in_set_wvp;	// ���[���h �r���[ �v���W�F�N�V�����̃}�g���N�X���


	// ���[���h�}�g���N�X�𐶐�
	in_set_wvp.world = in_world_matrix;

	// �r���[�}�g���N�X���Z�b�g
	in_set_wvp.view = GAME::CAMERA::MAIN_CAMERA::C_Main_Camera::M_Get_View_Matrix();

	// �v���W�F�N�V�����}�g���N�X���Z�b�g
	in_set_wvp.projection = GAME::CAMERA::MAIN_CAMERA::C_Main_Camera::M_Get_Projection_Matrix();

	// �S�Ẵ��b�V���̃}�e���A���Ƀg�����X�t�H�[�����Z�b�g
	for (S_Mesh_Data_Inform& now_mesh : mpr_variable.mesh_inform_list)
	{
		now_mesh.mesh_data->M_Get_Material_User().M_Get_Material_Address()->M_Set_WVP_Matrix(in_set_wvp);
	}

	return;
}

























































//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��
