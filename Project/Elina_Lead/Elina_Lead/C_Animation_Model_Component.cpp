//����������������������������������������������//
// �ڍ�   �F�ό`���Ȃ����f���̃R���|�[�l���g�̃V�X�e��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Animation_Model_Component.h"
#include "C_Game_Time_Manager.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::COMPONENT::MODEL_COMPONENT;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Model_Component::C_Animation_Model_Component(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Model_Component::~C_Animation_Model_Component(void)
{
	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃��f�������[�h����
// ����   �Fstring ���[�h���郂�f����
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Animation_Model_Component::M_Load_Animation_Model_By_Name(std::string in_load_model_name)
{
	return mpr_variable.model_system.M_Load_Animation_Model(in_load_model_name);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�`��ݒ胊�X�g��ԍ����w�肵�Đݒ肷��A�O�ɂ������`��ݒ�̃f�[�^�͏�����
// ����   �Fint �ݒ��̕`��ݒ�ԍ�, string �g�p����}�e���A����, vector<string> �`�悷�郁�b�V�����̃��X�g�i���g�Ȃ��őS���b�V���`��j
// �߂�l �FC_Material_User * �ǉ������}�e���A���g�p�V�X�e���̃A�h���X
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::MATERIAL::C_Material_User * C_Animation_Model_Component::M_Set_Model_Draw_List(int in_draw_command_number, std::string in_material_name, std::vector<std::string> in_mesh_name_list)
{
	// �w�肳�ꂽ�ԍ����̔z�񂪗p�ӂ���Ă��Ȃ���Δz���p�ӂ���
	if (in_draw_command_number >= mpr_variable.draw_command_list.size())
	{
		mpr_variable.draw_command_list.resize(in_draw_command_number + 1);
	}


	// �g�p����}�e���A������NATURAL�A�܂��͋󕶎��Ȃ猳���烁�b�V���ɓo�^����Ă���}�e���A�����g�p����
	if (in_material_name == "NATURAL" || in_material_name == "")
	{
		mpr_variable.draw_command_list[in_draw_command_number].model_draw_option = ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_NATURAL_DRAW;
	}

	// �}�e���A�������w�肳��Ă��鎞�͂��̃}�e���A�������[�h����
	else
	{
		// �}�e���A�����w�肷��t���O�𗧂Ă�
		mpr_variable.draw_command_list[in_draw_command_number].model_draw_option = ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_MATERIAL_ORIGINAL;

		// �}�e���A���̃��[�h�A���s������G���[�Ŕ�����
		if (mpr_variable.draw_command_list[in_draw_command_number].material_data.M_Load_Material(in_material_name) == false)
		{
			return nullptr;
		}
	}

	// �`�悷�郁�b�V���Ɏw�肪����Ȃ�o�^����
	if (in_mesh_name_list.size() > 0)
	{
		mpr_variable.draw_command_list[in_draw_command_number].mesh_name_list = in_mesh_name_list;

		// �}�e���A�����w�肵�������Ń��b�V���̎w����s��
		if (mpr_variable.draw_command_list[in_draw_command_number].model_draw_option == ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_MATERIAL_ORIGINAL)
		{
			mpr_variable.draw_command_list[in_draw_command_number].model_draw_option = ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_SELECT_MESH_AND_MATERIAL_ORIGINAL;
		}

		// ���b�V���̎w��̂ݍs��
		else
		{
			mpr_variable.draw_command_list[in_draw_command_number].model_draw_option = ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_SELECT_MESH;
		}
	}

	// �g�p����}�e���A���g�p�V�X�e���̃A�h���X��Ԃ�
	return &mpr_variable.draw_command_list[in_draw_command_number].material_data;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�^�C�����C�����g�p���郂�[�h�ɐ؂�ւ���
// ����   �Fstring �g�p����^�C�����C����
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Model_Component::M_Set_Time_Line_Name_And_Start_Time_Line_Mode(std::string in_time_line_name)
{
	mpr_variable.time_line_name = in_time_line_name;
	mpr_variable.flg_use_time_line = true;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�ʏ�̃Q�[�����Ԃ��g�p���郂�[�h�ɐ؂�ւ���
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Model_Component::M_Set_Game_Time_Mode(void)
{
	mpr_variable.flg_use_time_line = false;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���[�J�����W�̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �FC_Transform & ���[�J�����W�̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
MATH::C_Transform & C_Animation_Model_Component::M_Get_Transform(void)
{
	return mpr_variable.transform;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���f���V�X�e���̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �FC_Animation_Model_User & �A�j���[�V�������f���V�X�e���̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::ANIMATION_MODEL::C_Animation_Model_User & C_Animation_Model_Component::M_Get_Model_Address(void)
{
	return mpr_variable.model_system;
}


//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�����̎��Ԃ��X�V����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Model_Component::M_Update(void)
{
	// �^�C�����C�����g�p����ꍇ�́A�^�C�����C�����Ԃ�₢���킹�Ă��̎��ԂŃA�j���[�V�������Ԃ��X�V����
	if (mpr_variable.flg_use_time_line)
	{
		mpr_variable.model_system.M_Time_Update(GAME::TIME::C_Game_Time_Manager::M_Get_Time_Line_Delta_Second(mpr_variable.time_line_name));
	}

	// �ʏ펞�̓Q�[�����Ԃ��g�p����
	else
	{
		mpr_variable.model_system.M_Time_Update(GAME::TIME::C_Game_Time_Manager::M_Get_Game_Second());
	}

	return;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�`��ʒu�ƂȂ郏�[���h�}�g���N�X��ݒ肷��A�`��̊J�n���Ɏ��s����A�ʏ�`��̊J�n���ł悢
// ����   �Fconst XMMATRIX & �ݒ肷�郏�[���h�}�g���N�X�ϊ��s��̎Q�Ɓiconst�j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Model_Component::M_Draw_Start_World_Matrix_Set(const DirectX::XMMATRIX & in_world_matrix)
{
	// ���[���h�}�g���N�X�ϊ��s��𐶐�
	mpr_variable.transform.M_Generate_World_Matrix(mpr_variable.world_matrix);
	mpr_variable.world_matrix *= in_world_matrix;

	// ���f���̕`����J�n����
	mpr_variable.model_system.M_Model_Draw_Start(mpr_variable.world_matrix);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���f���̕`����s��
// ����   �Fint �`�悷�鎞�̕`��ݒ�̔ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Model_Component::M_Model_Draw(int in_draw_command_number)
{
	//--�� �`��I�v�V�����ŕ��򂵂ĕ`����s�Ȃ� -��-//
	switch (mpr_variable.draw_command_list[in_draw_command_number].model_draw_option)
	{
		// �ʏ�`��
	case ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_NATURAL_DRAW:
	default:
		mpr_variable.model_system.M_Draw_Model();
		break;

		// �}�e���A�����w�肵�ĕ`�悷��
	case ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_MATERIAL_ORIGINAL:
		{
			// �� �ϐ��錾 �� //
			ASSET::MATERIAL::C_Material * use_material = nullptr;	// �g�p����}�e���A���̃A�h���X


			// �g�p����}�e���A�����擾���AWVP���Z�b�g
			use_material = mpr_variable.draw_command_list[in_draw_command_number].material_data.M_Get_Material_Address();
			use_material->M_Set_World_Matrix(mpr_variable.world_matrix);
			use_material->M_Set_View_Projection_By_Main_Camera();
			mpr_variable.model_system.M_Draw_Model_And_Set_Material(mpr_variable.draw_command_list[in_draw_command_number].material_data);
		}
	break;

	// ���b�V�����w�肵�ĕ`�悷��
	case ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_SELECT_MESH:

		for (std::string & now_mesh_name : mpr_variable.draw_command_list[in_draw_command_number].mesh_name_list)
		{
			mpr_variable.model_system.M_Draw_Mesh_By_Mesh_Name(now_mesh_name);
		}
		break;

		// ���b�V���ƃ}�e���A�����w�肵�ĕ`�悷��
	case ASSET::MODEL_SYSTEM::E_MODEL_DRAW_OPTION::e_SELECT_MESH_AND_MATERIAL_ORIGINAL:
	{
		// �� �ϐ��錾 �� //
		ASSET::MATERIAL::C_Material* use_material = nullptr;	// �g�p����}�e���A���̃A�h���X


		// �g�p����}�e���A�����擾���AWVP���Z�b�g
		use_material = mpr_variable.draw_command_list[in_draw_command_number].material_data.M_Get_Material_Address();
		use_material->M_Set_World_Matrix(mpr_variable.world_matrix);
		use_material->M_Set_View_Projection_By_Main_Camera();

		// ���b�V�����w�肵�ĕ`�悷��
		for (std::string & now_mesh_name : mpr_variable.draw_command_list[in_draw_command_number].mesh_name_list)
		{
			mpr_variable.model_system.M_Draw_Mesh_By_Mesh_Name_And_Set_Material(mpr_variable.draw_command_list[in_draw_command_number].material_data, now_mesh_name);
		}
	}
	break;
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���f���̕`����I������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Model_Component::M_Model_Draw_End(void)
{
	mpr_variable.model_system.M_Model_Draw_End();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���|�[�l���g�p�̕`�揈�������g�p���Ȃ��i���f���`��O�Ƀ}�e���A���̐ݒ�Ȃǂ��s�����߁j
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Model_Component::M_Draw(void)
{
	return;
}
