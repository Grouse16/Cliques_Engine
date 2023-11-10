//����������������������������������������������//
// �ڍ�   �F�V�F�[�_�[����p�̃N���X
// ����   �F�V�F�[�_�[�̓ǂݎ��Ə����o���A�Ǘ����s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Shader_Manager.h"
#include "C_Rendering_Graphics_API_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::SHADER::MANAGER;


// �� �X�^�e�B�b�N�ϐ� �� //
C_Shader_Manager C_Shader_Manager::m_this;


// �� �ϐ��錾 �� //
C_Shader_Manager C_Shader_Manager::m_this;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Shader_Manager::C_Shader_Manager(void)
{
	// �V�F�[�_�[�̎�ސ������X�g�����
	mpr_variable.shader_inform_list.resize((int)E_SHADER_KIND::e_ALL);

	return;
}


//==�� �p�u���b�N ��==//

//-��- �I���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Shader_Manager::~C_Shader_Manager(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Shader_Manager::M_Release(void)
{
	for (std::vector<S_Shader_Manage_Inform> & now_inform_list : m_this.mpr_variable.shader_inform_list)
	{
		for (S_Shader_Manage_Inform & now_inform : now_inform_list)
		{
			now_inform.shader->M_Release();
			now_inform.shader.reset();
		}

		now_inform_list.clear();
		now_inform_list.shrink_to_fit();
	}

	m_this.mpr_variable.shader_inform_list.clear();
	m_this.mpr_variable.shader_inform_list.shrink_to_fit();

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�V�F�[�_�[�f�[�^��Ԃ�
// ����   �FE_SHADER_KIND �V�F�[�_�[�̎��, string �V�F�[�_�[�̐ݒ�̖��O
// �߂�l �FC_Shader_Set * �w�肳�ꂽ�V�F�[�_�[�f�[�^�ւ̃A�h���X
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::SHADER::C_Shader_Code * C_Shader_Manager::M_Get_Shader_Setting(E_SHADER_KIND in_shader_kind, std::string in_shader_name)
{
	// ���łɃ��[�h�ς݂̃V�F�[�_�[�ݒ�����猩����܂ŒT�����A���������炻�̃f�[�^�̃A�h���X��Ԃ�
	for (S_Shader_Manage_Inform & now_shader_inform : m_this.mpr_variable.shader_inform_list[(int)in_shader_kind])
	{
		if (now_shader_inform.name == in_shader_name)
		{
			now_shader_inform.user_sum += 1;
			return now_shader_inform.shader.get();
		}
	}

	// ���[�h�ł��Ȃ�������nullptr��Ԃ�
	return nullptr;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�F�[�_�[������V�F�[�_�[�����[�h����
// ����   �FE_SHADER_KIND �V�F�[�_�[�̎��, string �V�F�[�_�[���̎Q��
// �߂�l �FC_Shader_Code * ���������V�F�[�_�[�f�[�^�ւ̃A�h���X
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::SHADER::C_Shader_Code * C_Shader_Manager::M_Load_Shader_By_Name(E_SHADER_KIND in_shader_kind, std::string in_shader_name)
{
	// �� �ϐ��錾 �� //
	std::string shader_inform_path = RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Get_Shader_Folder_Path() + in_shader_name;	// �V�F�[�_�[���ւ̃p�X

	int shader_slot_num = m_this.mpr_variable.shader_inform_list[(int)in_shader_kind].size();	// ���삷��V�F�[�_�[�̔ԍ�


	// �V�����V�F�[�_�[�ݒ�p�̃X���b�g�𐶐�
	m_this.mpr_variable.shader_inform_list[(int)in_shader_kind].resize(shader_slot_num + 1);
	m_this.mpr_variable.shader_inform_list[(int)in_shader_kind][shader_slot_num].shader.reset(new ASSET::SHADER::C_Shader_Code);

	// �V�F�[�_�[��񂩂�V�F�[�_�[�����[�h����A�ł��Ȃ����false��Ԃ�
	if (m_this.mpr_variable.shader_inform_list[(int)in_shader_kind][shader_slot_num].shader->M_Load_Shader_File(shader_inform_path) == false)
	{
		return nullptr;
	}

	// �V�����V�F�[�_�[�̖��O��o�^���A�g�p����Ă��鐔�����Z
	m_this.mpr_variable.shader_inform_list[(int)in_shader_kind][shader_slot_num].name = in_shader_name;
	m_this.mpr_variable.shader_inform_list[(int)in_shader_kind][shader_slot_num].user_sum = 1;

	// ���������V�F�[�_�[��Ԃ�
	return m_this.mpr_variable.shader_inform_list[(int)in_shader_kind][shader_slot_num].shader.get();
}


//-��- �폜 -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�V�F�[�_�[�ݒ�̏��L����������邱�Ƃ�ʒm����
// ����   �FE_SHADER_KIND �V�F�[�_�[�̎��, C_Shader_Setting * & ���L�����������V�F�[�_�[�ݒ�̃A�h���X�̎Q�Ɓiconst�j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Shader_Manager::M_Released_Shader_Setting_Once(ASSET::SHADER::E_SHADER_KIND in_shader_kind, C_Shader_Code * & in_released_shader)
{
	// �w�肳�ꂽ�V�F�[�_�[�ݒ��T�����A���������珊�����Ă���C���X�^���X�������炵�A���̃V�F�[�_�[�ւ̐ڑ���؂�
	for (S_Shader_Manage_Inform & now_shader_set : m_this.mpr_variable.shader_inform_list[(int)in_shader_kind])
	{
		if (now_shader_set.shader.get() == in_released_shader)
		{
			in_released_shader = nullptr;
			now_shader_set.user_sum -= 1;


			// ���̃V�F�[�_�[���g���Ȃ��Ȃ�����폜����
			m_this.mpr_variable.shader_inform_list[(int)in_shader_kind].erase
			(
				std::remove_if
				(
					m_this.mpr_variable.shader_inform_list[(int)in_shader_kind].begin(),
					m_this.mpr_variable.shader_inform_list[(int)in_shader_kind].end(),

					// �폜�����̃����_��
					[](S_Shader_Manage_Inform & in_shader_inform)
					{
						if (in_shader_inform.user_sum < 1)
						{
							in_shader_inform.shader.reset();

							return true;
						}

						return false;
					}
				),
				m_this.mpr_variable.shader_inform_list[(int)in_shader_kind].end()
			);
			m_this.mpr_variable.shader_inform_list[(int)in_shader_kind].shrink_to_fit();

			return;
		}
	}

	return;
}

