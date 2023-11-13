//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�������f���̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_3D_Animation_Model_System.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::ANIMATION::MODEL;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_3D_Animation_Model_System::C_3D_Animation_Model_System(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_3D_Animation_Model_System::~C_3D_Animation_Model_System(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������̉�����s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_3D_Animation_Model_System::M_Release(void)
{
	for (S_Animative_Mesh_Data_Inform & mesh_data : mpr_variable.mesh_inform_list)
	{
		mesh_data.mesh_data.reset();
	}
	mpr_variable.mesh_inform_list.clear();
	mpr_variable.mesh_inform_list.shrink_to_fit();

	return;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�p�X��3D�A�j���[�V�������f�������[�h����
// ����   �Fstring 3D�A�j���[�V�������f���܂ł̃p�X
// �߂�l �Fbool �������̂�ture
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_3D_Animation_Model_System::M_Load_3D_Animation_Model_By_Path(std::string in_3d_animation_model_path)
{
	// �� �ϐ��錾 �� //
	SYSTEM::TEXT::C_Text_And_File_Manager file_data;	// �t�@�C���̃f�[�^��ǂݎ��V�X�e��


	// �w�肳�ꂽ�t�@�C�������[�h�@���[�h�Ɏ��s���̓G���[���o���Ĕ�����
	if (file_data.M_Load_Select_File(in_3d_animation_model_path) == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "�t�@�C���̎擾�Ɏ��s���܂����F" + in_3d_animation_model_path);
#endif // _DEBUG

		return false;
	}


	// �� �ϐ��錾 �� //
	int now_mesh_num = 0;	// ���̃��b�V���̔ԍ�


	// ���ݎ����Ă���A�j���[�V�������f���f�[�^�͍폜����
	M_Release();


	// �F�ؖ���T������
	if (file_data.M_Goto_Right_By_Text_In_Front_Row("This-Is-ELANMMDL") == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "���̃t�@�C����.elmdl�`���ł͂���܂���F" + in_3d_animation_model_path);
#endif // _DEBUG

		return false;
	}


	// ���b�V���f�[�^�����擾
	file_data.M_Goto_Right_By_Text_In_Front_Row("MESHSUM:");
	mpr_variable.mesh_inform_list.resize(file_data.M_Get_Number());


	// �{�[�������擾�����̐����{�[���𐶐�
	file_data.M_Goto_Right_By_Text_In_Front_Row("BONESUM:" + std::to_string(now_mesh_num) + ":");
	mpr_variable.bone_list.resize(file_data.M_Get_Number());


	// �{�[���f�[�^���ǂݎ��
	for (ASSET::ANIMATION::BONE::S_Bone_Inform & bone_inform : mpr_variable.bone_list)
	{
		// ���݂̃{�[���̃f�[�^�܂ňړ�
		file_data.M_Move_Next_Raw();

		// �{�[�������擾
		bone_inform.bone_name = file_data.M_Get_Data_By_Text("/");

		// �I�t�Z�b�g�}�g���N�XA�P�����[�h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._11 = file_data.M_Get_Number();

		// �I�t�Z�b�g�}�g���N�XA�Q�����[�h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._12 = file_data.M_Get_Number();

		// �I�t�Z�b�g�}�g���N�XA�R�����[�h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._13 = file_data.M_Get_Number();
		
		// �I�t�Z�b�g�}�g���N�XA�S�����[�h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._14 = file_data.M_Get_Number();

		// �I�t�Z�b�g�}�g���N�XB�P�����[�h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._21 = file_data.M_Get_Number();

		// �I�t�Z�b�g�}�g���N�XB�Q�����[�h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._22 = file_data.M_Get_Number();

		// �I�t�Z�b�g�}�g���N�XB�R�����[�h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._23 = file_data.M_Get_Number();

		// �I�t�Z�b�g�}�g���N�XB�S�����[�h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._24 = file_data.M_Get_Number();

		// �I�t�Z�b�g�}�g���N�XC�P�����[�h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._31 = file_data.M_Get_Number();

		// �I�t�Z�b�g�}�g���N�XC�Q�����[�h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._32 = file_data.M_Get_Number();

		// �I�t�Z�b�g�}�g���N�XC�R�����[�h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._33 = file_data.M_Get_Number();

		// �I�t�Z�b�g�}�g���N�XC�S�����[�h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._34 = file_data.M_Get_Number();

		// �I�t�Z�b�g�}�g���N�XD�P�����[�h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._41 = file_data.M_Get_Number();

		// �I�t�Z�b�g�}�g���N�XD�Q�����[�h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._42 = file_data.M_Get_Number();

		// �I�t�Z�b�g�}�g���N�XD�R�����[�h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._43 = file_data.M_Get_Number();

		// �I�t�Z�b�g�}�g���N�XD�S�����[�h
		file_data.M_Goto_Right_By_Text_In_Front_Sentence(":");
		bone_inform.offset_matrix._44 = file_data.M_Get_Number();
	}


	// ���b�V���f�[�^���ǂݎ��
	for (S_Animative_Mesh_Data_Inform & now_mesh_inform : mpr_variable.mesh_inform_list)
	{
		// ���b�V���ԍ����X�V
		now_mesh_num += 1;

		// ���b�V���̈ʒu�ֈړ�
		file_data.M_Goto_Right_By_Text_In_Front_Row("MESH" + std::to_string(now_mesh_num) + ":");

		// ���b�V�������擾
		file_data.M_Move_Next_Raw();
		now_mesh_inform.name = file_data.M_Get_Data_Now_Row();

		// ���b�V���f�[�^�𐶐�
		now_mesh_inform.mesh_data.reset(new ASSET::ANIMATION::MESH::C_Animative_Mesh());

		// ���b�V���̃}�e���A�������[�h�@���[�h���s�ŃG���[���o���Ĕ�����
		file_data.M_Move_Raw_By_Number(2);
		file_data.M_Goto_Column_By_Set_Number(0);
		if (now_mesh_inform.mesh_data->M_Load_Material_By_Name(file_data.M_Get_Data_Now_Row()) == false)
		{
#ifdef _DEBUG
			DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "�}�e���A���̃��[�h�Ɏ��s���܂���");
#endif // _DEBUG

			return false;
		}

		// ���_�����擾���A���_�f�[�^�𐶐�
		file_data.M_Goto_Right_By_Text_In_Front_Row("VERT" + std::to_string(now_mesh_num) + ":");
		now_mesh_inform.mesh_data->M_Creat_Vertex_List(file_data.M_Get_Number());

		// ���_�f�[�^�����[�h
		for (DATA::VERTEX::S_3D_Animation_Model_Vertex & now_vertex_data : now_mesh_inform.mesh_data->M_Get_Vertex_Data_List())
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
			now_vertex_data.color.r = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.color.g = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.color.b = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			now_vertex_data.color.a = file_data.M_Get_Float_Double_Number();

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

			// �{�[���E�F�C�g�i�{�[���e���l�j���̈ʒu�ֈړ�
			file_data.M_Goto_Right_By_Text_In_Front_Column(":");

			// �{�[���E�F�C�g���̏I���̋L�������邩�A�S��J��Ԃ��܂ŁA�{�[���E�F�C�g�������[�h��������
			for (int loop_cnt = 0; loop_cnt < DATA::VERTEX::con_BONE_WEIGHT_INDEX_SUM || file_data.M_Get_Text_Of_Now_Position() != ':'; loop_cnt++)
			{
				now_vertex_data.bone_weight[loop_cnt].bone_index = file_data.M_Get_Number();
				file_data.M_Goto_Right_By_Text_In_Front_Column("/");
				now_vertex_data.bone_weight[loop_cnt].weight = file_data.M_Get_Float_Double_Number();
				file_data.M_Goto_Right_By_Text_In_Front_Column(",");
			}
		}

		// ���_�C���f�b�N�X�����擾���āA���_�C���f�b�N�X�f�[�^�𐶐�
		file_data.M_Goto_Right_By_Text_In_Front_Row("INDEX" + std::to_string(now_mesh_num) + ":");
		now_mesh_inform.mesh_data->M_Creat_Index_List(file_data.M_Get_Number());

		// ���_�C���f�b�N�X�f�[�^�����[�h
		for (unsigned __int32 & now_index_data : now_mesh_inform.mesh_data->M_Get_Index_Data_List())
		{
			file_data.M_Move_Next_Raw();
			now_index_data = file_data.M_Get_Number();
		}

		// ���_�ƒ��_�C���f�b�N�X��񕪂̃o�b�t�@�𐶐����A�f�[�^���o�b�t�@�ɃZ�b�g�A���̌�f�[�^�͎g�p���Ȃ��̂ō폜�i�o�b�t�@�͎c��j
		now_mesh_inform.mesh_data->M_Creat_Vertex_Buffer_And_Index_Buffer();
		now_mesh_inform.mesh_data->M_Attach_Vertex_Data_To_Buffer();
		now_mesh_inform.mesh_data->M_Attach_Index_Data_To_Buffer();
		now_mesh_inform.mesh_data->M_Delete_Vertex_Data();
		now_mesh_inform.mesh_data->M_Delete_Index_Data();
	}

	// ���[�h�ɐ����A�f�o�b�O���͐������O��\��
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "���f���̃��[�h�ɐ������܂����F" + in_3d_animation_model_path);
#endif // _DEBUG

	return true;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃��b�V����Ԃ�
// ����   �Fstring �T�����b�V���̖��O
// �߂�l �FC_3D_Animation_Model_System::S_Animative_Mesh_Data_Inform * ���O����v�������b�V���̃A�h���X�A��v���Ȃ�������nullptr��Ԃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_3D_Animation_Model_System::S_Animative_Mesh_Data_Inform * C_3D_Animation_Model_System::M_Get_Mesh_Data_By_Name(std::string in_mesh_name)
{
	// ��v���郁�b�V������T���A����΂��̃A�h���X��Ԃ�
	for (S_Animative_Mesh_Data_Inform & now_mesh_data : mpr_variable.mesh_inform_list)
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
// �߂�l �Fvector<C_3D_Animation_Model_System::S_Animative_Mesh_Data_Inform> & ���b�V�����̃��X�g�̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::vector<C_3D_Animation_Model_System::S_Animative_Mesh_Data_Inform> &  C_3D_Animation_Model_System::M_Get_Mesh_Inform_List(void)
{
	return mpr_variable.mesh_inform_list;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F3D���f����`�悷��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_3D_Animation_Model_System::M_Draw_3D_Model(void)
{
	// �S�Ẵ��b�V����`��
	for (S_Animative_Mesh_Data_Inform & now_mesh_inform : mpr_variable.mesh_inform_list)
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
void C_3D_Animation_Model_System::M_Draw_Meshes_By_Name(std::string in_draw_mesh_name)
{
	// �S�Ẵ��b�V������`�悷�郁�b�V�����Ɠ������b�V���̂ݕ`��
	for (S_Animative_Mesh_Data_Inform & now_mesh_inform : mpr_variable.mesh_inform_list)
	{
		if (now_mesh_inform.name == in_draw_mesh_name)
		{
			now_mesh_inform.mesh_data->M_Draw_Mesh();
		}
	}

	return;
}

