//����������������������������������������������//
// �ڍ�   �F3D���f���̃N���X
// ����   �F3D���f���̎擾����`��A�A�j���[�V�����̎��s�܂ł��s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_3D_Model_Manager.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::MODEL::MANAGER;


// �� �X�^�e�B�b�N�ϐ� �� //
C_3D_Model_Manager C_3D_Model_Manager::m_this;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_3D_Model_Manager::C_3D_Model_Manager(void)
{
	return;
}


//==�� �p�u���b�N ��==//

//-��- �I���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_3D_Model_Manager::~C_3D_Model_Manager(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������̉��������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_3D_Model_Manager::M_Release(void)
{
	for (S_3D_Model_Inform & now_3d_model : m_this.mpr_variable.model_list)
	{
		now_3d_model.model_data.reset();
	}

	m_this.mpr_variable.model_list.clear();
	m_this.mpr_variable.model_list.shrink_to_fit();

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ3D���f����Ԃ�
// ����   �Fstring 3D���f���̖��O
// �߂�l �FC_3D_Model_System * �w�肳�ꂽ3D���f���f�[�^�ւ̃A�h���X�A�Ȃ����nullptr��Ԃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::MODEL::C_3D_Model_System * C_3D_Model_Manager::M_Get_3D_Model_By_Name(std::string in_3D_model_name)
{
	// �w�肳�ꂽ���O��3D���f����T��
	for (S_3D_Model_Inform & model_inform : m_this.mpr_variable.model_list)
	{
		if (model_inform.name == in_3D_model_name)
		{
			model_inform.user_sum += 1;
			return model_inform.model_data.get();
		}
	}

	// ������Ȃ�����
	return nullptr;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F3D���f��������3D���f�������[�h����
// ����   �Fstring 3D���f����
// �߂�l �FC_Material * ��������3D���f���f�[�^�ւ̃A�h���X
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::MODEL::C_3D_Model_System * C_3D_Model_Manager::M_Load_3D_Model_By_Name(std::string in_3D_model_name)
{
	// �� �ϐ��錾 �� //
	std::string model_3d_inform_path = "project/asset/model/" + in_3D_model_name + ".elsttmdl";	// 3D���f�����ւ̃p�X

	int model_slot_num = m_this.mpr_variable.model_list.size();	// ���삷��3D���f���̔ԍ�


	// �V����3D���f���ݒ�p�̃X���b�g�𐶐�
	m_this.mpr_variable.model_list.resize(model_slot_num + 1);
	m_this.mpr_variable.model_list[model_slot_num].model_data.reset(new ASSET::MODEL::C_3D_Model_System());

	// 3D���f����񂩂�3D���f�������[�h����A�ł��Ȃ����false��Ԃ�
	if (m_this.mpr_variable.model_list[model_slot_num].model_data->M_Load_3D_Model_By_Path(model_3d_inform_path) == false)
	{
		return nullptr;
	}

	// �V����3D���f���̖��O��o�^���A�g�p����Ă��鐔�����Z
	m_this.mpr_variable.model_list[model_slot_num].name = in_3D_model_name;
	m_this.mpr_variable.model_list[model_slot_num].user_sum = 1;

	// ��������3D���f����Ԃ�
	return m_this.mpr_variable.model_list[model_slot_num].model_data.get();
}


//-��- �폜 -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F3D���f��������3D���f�������[�h����
// ����   �Fstring 3D���f����
// �߂�l �FC_Material * ��������3D���f���f�[�^�ւ̃A�h���X
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_3D_Model_Manager::M_Release_3D_Model(ASSET::MODEL::C_3D_Model_System * & in_delete_model)
{
	// 3D���f���ݒ薼����w�肳�ꂽ3D���f���ݒ��T���āA���������珊�L����Ă��鐔�̃J�E���g�����炵�ĎQ�Ƃł��Ȃ�����
	for (S_3D_Model_Inform & now_3d_model_inform : m_this.mpr_variable.model_list)
	{
		if (now_3d_model_inform.model_data.get() == in_delete_model)
		{
			in_delete_model = nullptr;
			now_3d_model_inform.user_sum -= 1;


			// ����3D���f���ݒ肪�g���Ȃ��Ȃ�����폜����
			m_this.mpr_variable.model_list.erase
			(
				std::remove_if
				(
					m_this.mpr_variable.model_list.begin(),
					m_this.mpr_variable.model_list.end(),

					// �c��̐���0�ɂȂ�ƍ폜���郉���_��
					[](S_3D_Model_Inform & in_3d_model_setting)->bool
					{
						if (in_3d_model_setting.user_sum < 1)
						{
							in_3d_model_setting.model_data.reset();

							return true;
						}

						return false;
					}
				),
				m_this.mpr_variable.model_list.end()
			);

			return;
		}
	}

	return;
}

