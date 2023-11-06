//����������������������������������������������//
// �ڍ�   �F�V�F�[�_�[�̐ݒ���܂Ƃ߂������Ǘ�����N���X
// ����   �F���d�ɓ������̂����[�h����Ȃ��悤�ɐ��䂵�A�K�v���Ȃ��Ȃ����V�F�[�_�[�̐ݒ���폜����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Shader_Setting_Manager.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::SHADER::MANAGER;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^�A�V���O���g��������
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Shader_Setting_Manager::C_Shader_Setting_Manager(void)
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
C_Shader_Setting_Manager::~C_Shader_Setting_Manager(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Shader_Setting_Manager::M_Release(void)
{
	for (S_Shader_Setting_Inform & now_shader_setting_inform : m_this.mpr_variable.shader_setting_list)
	{
		now_shader_setting_inform.shader_setting_data->M_Release();
		now_shader_setting_inform.shader_setting_data.reset();
	}

	m_this.mpr_variable.shader_setting_list.clear();
	m_this.mpr_variable.shader_setting_list.shrink_to_fit();

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�V�F�[�_�[�ݒ��Ԃ�
// ����   �Fstring �V�F�[�_�[�ݒ�̖��O
// �߂�l �FC_Shader_Setting * �w�肳�ꂽ�V�F�[�_�[�ݒ�ւ̃A�h���X�A�Ȃ����nullptr��Ԃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::SHADER::C_Shader_Setting * C_Shader_Setting_Manager::M_Get_Shader_Setting_By_Name(std::string in_shader_setting_name)
{
	// �V�F�[�_�[�ݒ薼����w�肳�ꂽ�V�F�[�_�[�ݒ��T���āA���������炻���Ԃ�
	for (S_Shader_Setting_Inform & now_shader_setting_inform : m_this.mpr_variable.shader_setting_list)
	{
		if (now_shader_setting_inform.name == in_shader_setting_name)
		{
			now_shader_setting_inform.user_sum += 1;
			return now_shader_setting_inform.shader_setting_data.get();
		}
	}

	// ������Ȃ�����
	return nullptr;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�F�[�_�[�ݒ薼����V�F�[�_�[�ݒ�����[�h����
// ����   �Fstring �V�F�[�_�[�ݒ薼
// �߂�l �FC_Shader_Setting * ���������V�F�[�_�[�ݒ�ւ̃A�h���X
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::SHADER::C_Shader_Setting * C_Shader_Setting_Manager::M_Load_Shader_Setting_By_Name(std::string in_shader_setting_name)
{
	// �� �萔 �� //
	std::string shader_setting_inform_path = "project/asset/shader/inform/setting/" + in_shader_setting_name + ".elsst";	// �V�F�[�_�[�ݒ�ւ̃p�X

	int shader_setting_slot_num = m_this.mpr_variable.shader_setting_list.size();	// ���삷��V�F�[�_�[�ݒ�̔ԍ�


	// �V�����V�F�[�_�[�ݒ�p�̃X���b�g�𐶐�
	m_this.mpr_variable.shader_setting_list.resize(shader_setting_slot_num + 1);
	m_this.mpr_variable.shader_setting_list[shader_setting_slot_num].shader_setting_data.reset(new ASSET::SHADER::C_Shader_Setting());

	// �V�F�[�_�[�ݒ薼����V�F�[�_�[�ݒ�����[�h����A�ł��Ȃ����false��Ԃ�
	if (m_this.mpr_variable.shader_setting_list[shader_setting_slot_num].shader_setting_data->M_Load_Shaders_Inform_By_Shader_Setting_File_Path(shader_setting_inform_path) == false)
	{
		return nullptr;
	}

	// �V�����V�F�[�_�[�ݒ�̖��O��o�^���A�g�p����Ă��鐔�����Z
	m_this.mpr_variable.shader_setting_list[shader_setting_slot_num].name = in_shader_setting_name;
	m_this.mpr_variable.shader_setting_list[shader_setting_slot_num].user_sum = 1;

	// ���������V�F�[�_�[�ݒ��Ԃ�
	return m_this.mpr_variable.shader_setting_list[shader_setting_slot_num].shader_setting_data.get();
}


//-��- �폜 -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�V�F�[�_�[�ݒ�̏��L����������邱�Ƃ�ʒm����
// ����   �FC_Shader_Setting * & ���L�����������V�F�[�_�[�ݒ�̃A�h���X�̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Shader_Setting_Manager::M_Release_Shader(ASSET::SHADER::C_Shader_Setting * & in_release_shader_setting_address)
{
	// �V�F�[�_�[�ݒ薼����w�肳�ꂽ�V�F�[�_�[�ݒ��T���āA���������珊�L����Ă��鐔�̃J�E���g�����炵�ĎQ�Ƃł��Ȃ�����
	for (S_Shader_Setting_Inform & now_shader_setting_inform : m_this.mpr_variable.shader_setting_list)
	{
		if (now_shader_setting_inform.shader_setting_data.get() == in_release_shader_setting_address)
		{
			in_release_shader_setting_address = nullptr;
			now_shader_setting_inform.user_sum -= 1;


			// ���̃V�F�[�_�[�ݒ肪�g���Ȃ��Ȃ�����폜����
			m_this.mpr_variable.shader_setting_list.erase
			(
				std::remove_if
				(
					m_this.mpr_variable.shader_setting_list.begin(),
					m_this.mpr_variable.shader_setting_list.end(),

					// �c��̐���0�ɂȂ�ƍ폜���郉���_��
					[](S_Shader_Setting_Inform & in_shader_setting)->bool
					{
						if (in_shader_setting.user_sum < 1)
						{
							in_shader_setting.shader_setting_data.reset();

							return true;
						}

						return false;
					}
				),
				m_this.mpr_variable.shader_setting_list.end()
			);

			return;
		}
	}

	return;
}
