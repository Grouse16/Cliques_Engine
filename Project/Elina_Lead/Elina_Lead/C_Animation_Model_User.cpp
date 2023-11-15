//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�������f�����g�p���邽�߂̃V�X�e��
// ����   �F�A�j���[�V�������f���}�l�[�W���[�Ƃ̑�����B�����A�ȒP�Ɏg�p�ł���悤�ɃJ�v�Z��������@�A�j���[�V�����̎��s���s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Animation_Model_User.h"
#include "C_3D_Animation_Model_Manager.h"


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
C_Animation_Model_User::C_Animation_Model_User(void)
{
	return;
}

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Model_User::~C_Animation_Model_User(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������̉�����s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Model_User::M_Release(void)
{
	// �A�j���[�V�������f���������ĂȂ��Ȃ�X���[
	if (mpr_variable.animation_model == nullptr)
	{
		return;
	}

	// ����V�X�e���ɂ��̃A�j���[�V�������f���̎g�p������ʒm����
	ASSET::ANIMATION_MODEL::MANAGER::C_3D_Animation_Model_Manager::M_Release_Animation_Model(mpr_variable.animation_model);

	// �A�j���[�V�����̌v�Z�V�X�e��������������
	mpr_variable.animation_calculator.reset();

	return;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃A�j���[�V�������f����ǂݍ���
// ����   �Fstring ���[�h����A�j���[�V�������f����
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Model_User::M_Load_Animation_Model(std::string in_load_animation_model_name)
{
	// �� �ϐ��錾 �� //
	ASSET::ANIMATION_MODEL::C_3D_Animation_Model_System * new_animation_model_address = nullptr;	// �V�����A�j���[�V�������f���̃A�h���X


	// �A�j���[�V�������f���̖��O����T�����Ď擾
	new_animation_model_address = ASSET::ANIMATION_MODEL::MANAGER::C_3D_Animation_Model_Manager::M_Get_Animation_Model_By_Name(in_load_animation_model_name);

	// �w�肵���A�j���[�V�������f�����܂��Ȃ��Ȃ琶������
	if (new_animation_model_address == nullptr)
	{
		new_animation_model_address = ASSET::ANIMATION_MODEL::MANAGER::C_3D_Animation_Model_Manager::M_Load_Animation_Model_By_Name(in_load_animation_model_name);

		// �����Ɏ��s�����甲����
		if (new_animation_model_address == nullptr)
		{
			return;
		}
	}


	// �擾�ł����A�j���[�V�������f���Ɠ���ւ���
	M_Release();
	mpr_variable.animation_model = new_animation_model_address;
	mpr_variable.animation_calculator.reset(new ANIMATION::CALCULATOR::C_Animation_Calculation_System(&new_animation_model_address->M_Get_Bone_Inform_List()));

	return;
}


//-��- �X�V -��-//

void ASSET::ANIMATION_MODEL::C_Animation_Model_User::M_Animation_Update(void)
{
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���̃A�j���[�V�������f����`�悷��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Model_User::M_Animation_Model_Draw(void)
{
	// �A�j���[�V�������f���������Ă��Ȃ��Ȃ�`�悵�Ȃ�
	if (mpr_variable.animation_model == nullptr)
	{
		return;
	}

	mpr_variable.animation_model->M_Set_Bone_Matrix(mpr_variable.animation_calculator->M_Animation_Update);
	mpr_variable.animation_model->M_Draw_3D_Model();

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̃A�j���[�V�������f����Ԃ�
// ����   �Fvoid
// �߂�l �FC_3D_Animation_Model_System * ���݂̃A�j���[�V�������f���ւ̃A�h���X
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::ANIMATION_MODEL::C_3D_Animation_Model_System * C_Animation_Model_User::M_Get_Animation_Model_Address(void)
{
	return mpr_variable.animation_model;
}

