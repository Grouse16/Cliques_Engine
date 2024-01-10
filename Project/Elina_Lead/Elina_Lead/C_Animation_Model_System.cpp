//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�������f���̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Animation_Model_System.h"
#include "C_Main_Camera.h"
#include "C_Animation_Model_Loader.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::ANIMATION_MODEL;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Model_System::C_Animation_Model_System(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Model_System::~C_Animation_Model_System(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������̉�����s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
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


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�p�X��3D�A�j���[�V�������f�������[�h����
// ����   �Fstring 3D�A�j���[�V�������f���܂ł̃p�X
// �߂�l �Fbool �������̂�ture
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Animation_Model_System::M_Load_3D_Animation_Model_By_Path(std::string in_3d_animation_model_path)
{
	// �� �ϐ��錾 �� //
	SYSTEM::TEXT::C_Text_And_File_Manager load_file;	// �t�@�C�������[�h���邽�߂̃N���X


	// ���ݎ����Ă���A�j���[�V�������f���f�[�^�͍폜����
	M_Release();


	// �A�j���[�V�������f�������[�h����A���s������G���[�Ŕ�����
	if (ASSET::ANIMATION_MODEL::LOADER::C_Animation_Model_Loader::M_Load_Animation_Model_File(in_3d_animation_model_path, load_file) == false)
	{
		return false;
	}

	// ���_�f�[�^�����[�h����A���s������G���[�Ŕ�����
	if (ASSET::ANIMATION_MODEL::LOADER::C_Animation_Model_Loader::M_Load_Animation_Model_Vertex(load_file, mpr_variable.vertex_system) == false)
	{
		return false;
	}

	// �{�[���f�[�^�����[�h����A���s������G���[�Ŕ�����
	if (ASSET::ANIMATION_MODEL::LOADER::C_Animation_Model_Loader::M_Load_Animation_Model_Bone(load_file, mpr_variable.bone_list) == false)
	{
		return false;
	}

	// ���b�V���f�[�^�����[�h����A���s������G���[�Ŕ�����
	if (ASSET::ANIMATION_MODEL::LOADER::C_Animation_Model_Loader::M_Load_Animation_Model_Mesh(load_file, mpr_variable.mesh_list) == false)
	{
		return false;
	}


	// ���[�h�ɐ����A�f�o�b�O���͐������O��\��
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log
	(
		DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP,
		DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT,
		"�A�j���[�V�����p���f���̃��[�h�ɐ������܂����F" + in_3d_animation_model_path
	);
#endif // _DEBUG

	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃A�j���[�V�����f�[�^�����[�h����
// ����   �Fstring ���[�h����A�j���[�V�����f�[�^��
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Animation_Model_System::M_Load_Animation_Data_By_Name(std::string in_animation_data_name)
{
	// ���łɃ��[�h����Ă���Ȃ牽�����Ȃ�
	for (ASSET::ANIMATION_SYSTEM::C_Animation_Data_System & now_animation_data : mpr_variable.animation_data_list)
	{
		if (now_animation_data.M_Get_Name() == in_animation_data_name)
		{
			return true;
		}
	}


	// �� �ϐ��錾 �� //
	std::string load_path = "project/asset/animation/" + in_animation_data_name + ".elanmdt";	// �A�j���[�V�����f�[�^�܂ł̃p�X

	int new_animation_data_number = (int)mpr_variable.animation_data_list.size();	// �V�����A�j���[�V�����f�[�^�̔z��ԍ�


	// �A�j���[�V�����f�[�^�����[�h����@���s��false��Ԃ��Ĕ�����
	mpr_variable.animation_data_list.resize(new_animation_data_number + 1);
	if (mpr_variable.animation_data_list[new_animation_data_number].M_Load_Animation_Data_By_Path(load_path, mpr_variable.bone_list) == false)
	{
		return false;
	}

	// �A�j���[�V�����f�[�^����ݒ�
	mpr_variable.animation_data_list[new_animation_data_number].M_Set_Name(in_animation_data_name);

	// ���[�h�ɐ���
	return true;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃��b�V����Ԃ�
// ����   �Fstring �T�����b�V���̖��O
// �߂�l �FC_Mesh_Data * ���O����v�������b�V���̃A�h���X�A��v���Ȃ�������nullptr��Ԃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::MESH::C_Mesh_Data * C_Animation_Model_System::M_Get_Mesh_Data_By_Name(std::string in_mesh_name)
{
	// ��v���郁�b�V������T���A����΂��̃A�h���X��Ԃ�
	for (ASSET::MESH::C_Mesh_Data & l_now_mesh_data : mpr_variable.mesh_list)
	{
		if (l_now_mesh_data.M_Get_Mesh_Name() == in_mesh_name)
		{
			return &l_now_mesh_data;
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
std::vector<ASSET::MESH::C_Mesh_Data> &  C_Animation_Model_System::M_Get_Mesh_Inform_List(void)
{
	return mpr_variable.mesh_list;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃A�j���[�V�����f�[�^��Ԃ�
// ����   �Fstring �T���A�j���[�V�����f�[�^�̖��O
// �߂�l �Fconst C_Animation_Data_System * ���O����v�����A�j���[�V�����f�[�^�̃A�h���X�A��v���Ȃ�������nullptr��Ԃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * C_Animation_Model_System::M_Get_Animation_Data_By_Name(std::string in_animation_data)
{
	// ��v����A�j���[�V�����f�[�^����T���A����΂��̃A�h���X��Ԃ�
	for (ASSET::ANIMATION_SYSTEM::C_Animation_Data_System & now_animation_data : mpr_variable.animation_data_list)
	{
		if (now_animation_data.M_Get_Name() == in_animation_data)
		{
			return &now_animation_data;
		}
	}

	// ������Ȃ�����
	return nullptr;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�����V�X�e���̃��X�g�̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �Fconst vector<C_Animation_Data_System> & �A�j���[�V�����V�X�e���̃��X�g�̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const std::vector<ASSET::ANIMATION_SYSTEM::C_Animation_Data_System> & C_Animation_Model_System::M_Get_Animation_Inform_List(void)
{
	return mpr_variable.animation_data_list;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃{�[����Ԃ�
// ����   �Fvoid
// �߂�l �Fstring �{�[����
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const ASSET::ANIMATION::BONE::S_Bone_Inform * C_Animation_Model_System::M_Get_Bone_Inform_By_Name(std::string in_bone_name)
{
	// ��v����{�[������T���A����΂��̃A�h���X��Ԃ�
	for (ASSET::ANIMATION::BONE::S_Bone_Inform & now_bone_inform : mpr_variable.bone_list)
	{
		if (now_bone_inform.bone_name == in_bone_name)
		{
			return &now_bone_inform;
		}
	}

	// ������Ȃ�����
	return nullptr;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�{�[�����̃��X�g��Ԃ�
// ����   �Fvoid
// �߂�l �Fconst vector<S_Bone_Inform> �{�[�����̃��X�g��Ԃ�(const)
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & C_Animation_Model_System::M_Get_Bone_Inform_List(void)
{
	return mpr_variable.bone_list;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F3D���f����`�悷��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Model_System::M_Draw_3D_Model(void)
{
	// ���_���Z�b�g
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
void C_Animation_Model_System::M_Draw_Meshes_By_Name(std::string in_draw_mesh_name)
{
	// ���_���Z�b�g
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
void C_Animation_Model_System::M_Draw_3D_Model_Do_Not_Use_Material(void)
{
	// ���_���Z�b�g
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
void C_Animation_Model_System::M_Draw_Meshes_By_Name_Do_Not_Use_Material(std::string in_draw_mesh_name)
{
	// ���_���Z�b�g
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
// �ڍ�   �F�{�[���̃}�g���N�X���}�e���A���ɃZ�b�g����
// ����   �Fconst vector<XMFLOAT4X4> & �Z�b�g����{�[���}�g���N�X�z��̎Q��(const)
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Model_System::M_Set_Bone_Matrix(const std::vector<DirectX::XMFLOAT4X4> & in_bone_matrix_list)
{
	// �� �ϐ��錾 �� //
	int bone_sum = (int)mpr_variable.bone_list.size();	// �{�[����


	// �Z�b�g����{�[���}�g���N�X�z�񂪌��݂̃{�[�����ƈ�v���Ȃ��Ȃ珈�������Ȃ�
	if (bone_sum != in_bone_matrix_list.size())
	{
		return;
	}

	// �S�Ẵ��b�V���Ƀ{�[�����Z�b�g����
	for (ASSET::MESH::C_Mesh_Data & now_mesh_inform : mpr_variable.mesh_list)
	{
		now_mesh_inform.M_Get_Material_User().M_Get_Material_Address()->M_Set_Bone_Matrix(in_bone_matrix_list);
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���[���h �r���[ �v���W�F�N�V���������C���J���������ɒ萔�o�b�t�@�ɃZ�b�g����
// ����   �Fconst C_Transform & �g�����X�t�H�[���̎Q�Ɓiconst�j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Model_System::M_Set_World_View_Projection_With_Main_Camera_By_Transform(const MATH::C_Transform & in_transform)
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
// ����   �Fconst XMMATRIX & ���[���h�}�g���N�X�̎Q�Ɓiconst�j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Model_System::M_Set_World_View_Projection_With_Main_Camera_By_World_Matrix(const DirectX::XMMATRIX & in_world_matrix)
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
