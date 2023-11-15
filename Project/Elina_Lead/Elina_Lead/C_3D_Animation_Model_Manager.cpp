//����������������������������������������������//
// �ڍ�   �F3D�A�j���[�V���������郂�f�����Ǘ�����V�X�e��
// ����   �F�����A�j���[�V�������f���̑��d���[�h��h���A���O�ɂ�郂�f���̊Ǘ����s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_3D_Animation_Model_Manager.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::ANIMATION_MODEL::MANAGER;


// �� �X�^�e�B�b�N�ϐ� �� //
C_3D_Animation_Model_Manager C_3D_Animation_Model_Manager::m_this;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^�A�V���O���g��������
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_3D_Animation_Model_Manager::C_3D_Animation_Model_Manager(void)
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
C_3D_Animation_Model_Manager::~C_3D_Animation_Model_Manager(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_3D_Animation_Model_Manager::M_Release(void)
{
	for (S_3D_Animation_Model_Manage_Inform & in_animation_model_inform : m_this.mpr_variable.animation_model_inform_list)
	{
		in_animation_model_inform.animation_model->M_Release();
		in_animation_model_inform.animation_model.reset();
	}

	m_this.mpr_variable.animation_model_inform_list.clear();
	m_this.mpr_variable.animation_model_inform_list.shrink_to_fit();

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�A�j���[�V�������f����Ԃ�
// ����   �Fstring �T���A�j���[�V�������f���̖��O
// �߂�l �FC_3D_Animation_Model_System * �w�肳�ꂽ�A�j���[�V�������f���ւ̃A�h���X�A�Ȃ����nullptr��Ԃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::ANIMATION_MODEL::C_3D_Animation_Model_System * C_3D_Animation_Model_Manager::M_Get_Animation_Model_By_Name(std::string in_search_animation_model_name)
{
	// �w�肳�ꂽ�A�j���[�V�������f�����ƈ�v����A�j���[�V�������f���̃A�h���X��Ԃ�
	for (S_3D_Animation_Model_Manage_Inform & now_animation_model_inform : m_this.mpr_variable.animation_model_inform_list)
	{
		if (now_animation_model_inform.name == in_search_animation_model_name)
		{
			now_animation_model_inform.user_sum += 1;
			return now_animation_model_inform.animation_model.get();
		}
	}

	// ������Ȃ�����
	return nullptr;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�������f��������A�j���[�V�������f�������[�h����
// ����   �Fstring ���[�h����A�j���[�V�������f����
// �߂�l �FC_3D_Animation_Model_System * ���������A�j���[�V�������f���ւ̃A�h���X
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::ANIMATION_MODEL::C_3D_Animation_Model_System * C_3D_Animation_Model_Manager::M_Load_Animation_Model_By_Name(std::string in_load_animation_model_name)
{
	// �� �ϐ��錾 �� //
	std::string model_3d_inform_path = "project/asset/animation_model/" + in_load_animation_model_name + ".elanmmdl";	// �A�j���[�V�������f�����ւ̃p�X

	int animation_model_slot_num = m_this.mpr_variable.animation_model_inform_list.size();	// ���삷��A�j���[�V�������f���̔ԍ�


	// �V�����A�j���[�V�������f���ݒ�p�̃X���b�g�𐶐�
	m_this.mpr_variable.animation_model_inform_list.resize(animation_model_slot_num + 1);
	m_this.mpr_variable.animation_model_inform_list[animation_model_slot_num].animation_model.reset(new ASSET::ANIMATION_MODEL::C_3D_Animation_Model_System());

	// �A�j���[�V�������f����񂩂�A�j���[�V�������f�������[�h����A�ł��Ȃ����false��Ԃ�
	if (m_this.mpr_variable.animation_model_inform_list[animation_model_slot_num].animation_model->M_Load_3D_Animation_Model_By_Path(model_3d_inform_path) == false)
	{
		return nullptr;
	}

	// �V�����A�j���[�V�������f���̖��O��o�^���A�g�p����Ă��鐔�����Z
	m_this.mpr_variable.animation_model_inform_list[animation_model_slot_num].name = in_load_animation_model_name;
	m_this.mpr_variable.animation_model_inform_list[animation_model_slot_num].user_sum = 1;

	// ���������A�j���[�V�������f����Ԃ�
	return m_this.mpr_variable.animation_model_inform_list[animation_model_slot_num].animation_model.get();
}


//-��- �폜 -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�A�j���[�V�������f���̏��L����������邱�Ƃ�ʒm����
// ����   �FC_3D_Animation_Model_System * & ���L�����������A�j���[�V�������f���̃A�h���X�̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_3D_Animation_Model_Manager::M_Release_Animation_Model(ASSET::ANIMATION_MODEL::C_3D_Animation_Model_System * & in_animation_model)
{
	// �A�j���[�V�������f���ݒ薼����w�肳�ꂽ3D���f���ݒ��T���āA���������珊�L����Ă��鐔�̃J�E���g�����炵�ĎQ�Ƃł��Ȃ�����
	for (S_3D_Animation_Model_Manage_Inform & now_animation_model_inform : m_this.mpr_variable.animation_model_inform_list)
	{
		if (now_animation_model_inform.animation_model.get() == in_animation_model)
		{
			in_animation_model = nullptr;
			now_animation_model_inform.user_sum -= 1;


			// ���̃A�j���[�V�������f���ݒ肪�g���Ȃ��Ȃ�����폜����
			m_this.mpr_variable.animation_model_inform_list.erase
			(
				std::remove_if
				(
					m_this.mpr_variable.animation_model_inform_list.begin(),
					m_this.mpr_variable.animation_model_inform_list.end(),

					// �c��̐���0�ɂȂ�ƍ폜���郉���_��
					[](S_3D_Animation_Model_Manage_Inform & in_animation_model_setting)->bool
					{
						if (in_animation_model_setting.user_sum < 1)
						{
							in_animation_model_setting.animation_model.reset();

							return true;
						}

						return false;
					}
				),
				m_this.mpr_variable.animation_model_inform_list.end()
			);

			return;
		}
	}

	return;
}
