//����������������������������������������������//
// �ڍ�   �F3D���f���̃N���X
// ����   �F3D���f���̎擾����`��A�A�j���[�V�����̎��s�܂ł��s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Static_Model_System.h"
#include "C_Text_And_File_Manager.h"
#include "C_Main_Camera.h"
#include "C_Static_Model_Loader.h"

#include "C_Log_System.h"


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
C_Static_Model_System::C_Static_Model_System(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Static_Model_System::~C_Static_Model_System(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������̉�����s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
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


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�p�X��3D���f�������[�h����
// ����   �Fstring 3D���f���܂ł̃p�X
// �߂�l �Fbool �������̂�ture
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Static_Model_System::M_Load_3D_Model_By_Path(std::string in_3d_model_path)
{
	// �� �ϐ��錾 �� //
	SYSTEM::TEXT::C_Text_And_File_Manager file_data;	// �t�@�C���̃f�[�^��ǂݎ��V�X�e��


	// ���ݎ����Ă��郂�f���f�[�^�͍폜����
	M_Release();


	// ���f���̃f�[�^�����[�h����A���s������G���[�Ŕ�����
	if (ASSET::MODEL::STATIC_MODEL::LOADER::C_Static_Model_Loader::M_Load_Static_Model_File_Data(in_3d_model_path, file_data) == false)
	{
		return false;
	}

	// ���_�̃f�[�^�����[�h����A���s������G���[�Ŕ�����
	if (ASSET::MODEL::STATIC_MODEL::LOADER::C_Static_Model_Loader::M_Load_Static_Model_Vertex(file_data, mpr_variable.vertex_system) == false)
	{
		return false;
	}

	// ���b�V���̃f�[�^�����[�h����A���s������G���[�Ŕ�����
	if (ASSET::MODEL::STATIC_MODEL::LOADER::C_Static_Model_Loader::M_Load_Static_Model_Mesh(file_data, mpr_variable.mesh_list) == false)
	{
		return false;
	}


	// ���f���̃��[�h�̐��������m
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log
	(
		DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP,
		DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT,
		"���f���̃��[�h�ɐ������܂����F" + in_3d_model_path
	);

	return true;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃��b�V����Ԃ�
// ����   �Fstring �T�����b�V���̖��O
// �߂�l �FC_Mesh_Data * ���O����v�������b�V���̃A�h���X�A��v���Ȃ�������nullptr��Ԃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::MESH::C_Mesh_Data * C_Static_Model_System::M_Get_Mesh_Data_By_Name(std::string in_mesh_name)
{
	// ��v���郁�b�V������T���A����΂��̃A�h���X��Ԃ�
	for (ASSET::MESH::C_Mesh_Data & now_mesh_data : mpr_variable.mesh_list)
	{
		if (now_mesh_data.M_Get_Mesh_Name() == in_mesh_name)
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
// �߂�l �Fvector<C_Mesh_Data> & ���b�V�����̃��X�g�̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::vector<ASSET::MESH::C_Mesh_Data> & C_Static_Model_System::M_Get_Mesh_Inform_List(void)
{
	return mpr_variable.mesh_list;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F3D���f����`�悷��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Static_Model_System::M_Draw_Model(void)
{
	// ���_�V�F�[�_�[���Z�b�g
	mpr_variable.vertex_system.M_Set_Vertex_Buffer_To_Rendering();

	// �S�Ẵ��b�V����`��
	for (ASSET::MESH::C_Mesh_Data & now_mesh_inform : mpr_variable.mesh_list)
	{
		now_mesh_inform.M_Draw_Mesh();
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F3D���f������w�肳�ꂽ���b�V�����̂ݕ`�悷��
// ����   �Fstring �`�悷�郁�b�V�����i�������肷��j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Static_Model_System::M_Draw_Meshes_By_Name(std::string in_draw_mesh_name)
{
	// ���_�V�F�[�_�[���Z�b�g
	mpr_variable.vertex_system.M_Set_Vertex_Buffer_To_Rendering();

	// �S�Ẵ��b�V������`�悷�郁�b�V�����Ɠ������b�V���̂ݕ`��
	for (ASSET::MESH::C_Mesh_Data & now_mesh_inform : mpr_variable.mesh_list)
	{
		if (now_mesh_inform.M_Get_Mesh_Name() == in_draw_mesh_name)
		{
			now_mesh_inform.M_Draw_Mesh();
		}
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�}�e���A����ݒ肹���ɁA3D���f����`�悷��i�`��O�Ƀ}�e���A�����Z�b�g����Ƃ��p�j
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Static_Model_System::M_Draw_Model_Do_Not_Use_Material(void)
{
	// ���_�V�F�[�_�[���Z�b�g
	mpr_variable.vertex_system.M_Set_Vertex_Buffer_To_Rendering();

	// �S�Ẵ��b�V����`��
	for (ASSET::MESH::C_Mesh_Data & now_mesh_inform : mpr_variable.mesh_list)
	{
		now_mesh_inform.M_Draw_Mesh_Do_Not_Set_Material();
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�}�e���A����ݒ肹���ɁA3D���f������w�肳�ꂽ���b�V�����̂ݕ`�悷��i�`��O�Ƀ}�e���A�����Z�b�g����Ƃ��p�j
// ����   �Fstring �`�悷�郁�b�V�����i�������肷��j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Static_Model_System::M_Draw_Meshes_By_Name_Do_Not_Use_Material(std::string in_draw_mesh_name)
{
	// ���_�V�F�[�_�[���Z�b�g
	mpr_variable.vertex_system.M_Set_Vertex_Buffer_To_Rendering();

	// �S�Ẵ��b�V������`�悷�郁�b�V�����Ɠ������b�V���̂ݕ`��
	for (ASSET::MESH::C_Mesh_Data & now_mesh_inform : mpr_variable.mesh_list)
	{
		if (now_mesh_inform.M_Get_Mesh_Name() == in_draw_mesh_name)
		{
			now_mesh_inform.M_Draw_Mesh_Do_Not_Set_Material();
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
void C_Static_Model_System::M_Set_World_View_Projection_With_Main_Camera_By_Transform(const MATH::C_Transform & in_transform)
{
	// �� �ϐ��錾 �� //
	MATH::WVP::S_World_View_Projection_Data in_set_wvp;	// ���[���h �r���[ �v���W�F�N�V�����̃}�g���N�X���
	

	// ���[���h�}�g���N�X�𐶐�
	in_transform.M_Generate_Matrix(in_set_wvp.world);

	// �r���[�}�g���N�X���Z�b�g
	in_set_wvp.view = GAME::CAMERA::MAIN_CAMERA::C_Main_Camera::M_Get_View_Matrix();

	// �v���W�F�N�V�����}�g���N�X���Z�b�g
	in_set_wvp.projection = GAME::CAMERA::MAIN_CAMERA::C_Main_Camera::M_Get_Projection_Matrix();

	// �S�Ẵ��b�V���̃}�e���A���Ƀg�����X�t�H�[�����Z�b�g
	for (ASSET::MESH::C_Mesh_Data & now_mesh : mpr_variable.mesh_list)
	{
		now_mesh.M_Get_Material_User().M_Get_Material_Address()->M_Set_WVP_Matrix(in_set_wvp);
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���[���h �r���[ �v���W�F�N�V���������C���J���������ɒ萔�o�b�t�@�ɃZ�b�g����A���[���h�}�g���N�X���󂯎��
// ����   �Fconst C_Transform & ���[���h�}�g���N�X�̎Q�Ɓiconst�j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Static_Model_System::M_Set_World_View_Projection_With_Main_Camera_By_World_Matrix(const DirectX::XMMATRIX & in_world_matrix)
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
	for (ASSET::MESH::C_Mesh_Data & now_mesh : mpr_variable.mesh_list)
	{
		now_mesh.M_Get_Material_User().M_Get_Material_Address()->M_Set_WVP_Matrix(in_set_wvp);
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
