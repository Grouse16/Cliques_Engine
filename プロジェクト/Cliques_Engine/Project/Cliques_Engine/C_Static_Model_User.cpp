//����������������������������������������������//
// �ڍ�   �F3D���f�����g�p���邽�߂̃V�X�e��
// ����   �F3D���f���g�p����3D���f������V�X�e���Ƃ̘A�����ȗ�������
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Static_Model_User.h"
#include "C_Static_Model_Manager.h"


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
C_Static_Model_User::C_Static_Model_User(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Static_Model_User::~C_Static_Model_User(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������̉�����s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Static_Model_User::M_Release(void)
{
	// 3D���f���������Ă��Ȃ��Ȃ���s���Ȃ�
	if (mpr_variable.use_model_address == nullptr)
	{
		return;
	}


	// ���ݏ������Ă���3D���f���̏��L�����������
	ASSET::MODEL::MANAGER::C_Static_Model_Manager::M_Release_3D_Model(mpr_variable.use_model_address);

	return;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O��3D���f����ǂݍ���
// ����   �Fstring ���[�h����3D���f����
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Static_Model_User::M_Load_3D_Model(std::string in_load_3d_model_name)
{
	// �� �ϐ��錾 �� //
	ASSET::MODEL::C_Static_Model_System * new_3D_model_address = nullptr;	// �V����3D���f���̃A�h���X


	// 3D���f�����O����T�����Ď擾
	new_3D_model_address = ASSET::MODEL::MANAGER::C_Static_Model_Manager::M_Get_3D_Model_By_Name(in_load_3d_model_name);

	// �w�肵��3D���f�����܂��Ȃ��Ȃ琶������
	if (new_3D_model_address == nullptr)
	{
		new_3D_model_address = ASSET::MODEL::MANAGER::C_Static_Model_Manager::M_Load_3D_Model_By_Name(in_load_3d_model_name);

		// �����Ɏ��s�����甲����
		if (new_3D_model_address == nullptr)
		{
			return false;
		}
	}


	// �擾�ł����}�e���A���Ɠ���ւ���
	M_Release();
	mpr_variable.use_model_address = new_3D_model_address;

	return true;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F3D���f����`�悷��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Static_Model_User::M_Draw_3D_Model(void)
{
	// ���f���������Ă��Ȃ��Ȃ�`��͂��Ȃ�
	if (mpr_variable.use_model_address == nullptr)
	{
		return;
	}

	mpr_variable.use_model_address->M_Draw_Model();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃��b�V���̂ݕ`�悷��
// ����   �Fstring �`�悷�郁�b�V����
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Static_Model_User::M_Draw_3D_Model_Meshes_By_Mesh_Name(std::string in_mesh_name)
{
	// ���f���������Ă��Ȃ��Ȃ�`��͂��Ȃ�
	if (mpr_variable.use_model_address == nullptr)
	{
		return;
	}

	mpr_variable.use_model_address->M_Draw_Meshes_By_Name(in_mesh_name);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�}�e���A����ݒ肹���ɁA3D���f����`�悷��i�`��O�Ƀ}�e���A�����Z�b�g����Ƃ��p�j
// ����   �FC_Material_User & �g�p����}�e���A���̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Static_Model_User::M_Draw_3D_Model_And_Set_Material(ASSET::MATERIAL::C_Material_User & in_use_material)
{
	// ���f���������Ă��Ȃ��Ȃ�`��͂��Ȃ�
	if (mpr_variable.use_model_address == nullptr)
	{
		return;
	}


	// �w�肳�ꂽ�}�e���A���������_�����V�X�e���ɑ���
	in_use_material.M_Material_Attach_To_Draw();

	// 3D���f����`�悷��
	mpr_variable.use_model_address->M_Draw_Model_Do_Not_Use_Material();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �}�e���A����ݒ肹���ɁA3D���f������w�肳�ꂽ���b�V�����̂ݕ`�悷��i�`��O�Ƀ}�e���A�����Z�b�g����Ƃ��p�j
// ����   �FC_Material_User & �g�p����}�e���A���̎Q��, string �`�悷�郁�b�V�����i�������肷��j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Static_Model_User::M_Draw_3D_Model_Meshes_By_Name_And_Set_Material(ASSET::MATERIAL::C_Material_User & in_use_material, std::string in_mesh_name)
{
	// ���f���������Ă��Ȃ��Ȃ�`��͂��Ȃ�
	if (mpr_variable.use_model_address == nullptr)
	{
		return;
	}


	// �w�肳�ꂽ�}�e���A���������_�����V�X�e���ɑ���
	in_use_material.M_Material_Attach_To_Draw();

	// �w�肳�ꂽ���O�̃��b�V���݂̂�`�悷��
	mpr_variable.use_model_address->M_Draw_Meshes_By_Name_Do_Not_Use_Material(in_mesh_name);

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂�3D���f����Ԃ�
// ����   �Fstring �`�悷�郁�b�V����
// �߂�l �FC_Static_Model_System * ���݂�3D���f���ւ̃A�h���X
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Static_Model_System * C_Static_Model_User::M_Get_3D_Model_Address(void)
{
	return mpr_variable.use_model_address;
}


