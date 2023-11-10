//����������������������������������������������//
// �ڍ�   �F�e�N�X�`���𐧌䂷�邽�߂̃V�X�e��
// ����   �F�e�N�X�`���̃��[�h�������s������A�d�����ē����e�N�X�`�������[�h���Ȃ��悤�ɊǗ�����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Texture_Manager.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::TEXTURE::MANAGER;


// �� �X�^�e�B�b�N�ϐ� �� //
C_Texture_Manager C_Texture_Manager::m_this;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Texture_Manager::C_Texture_Manager(void)
{
	return;
}


//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`������p�̃V�X�e��������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Manager::M_Init(void)
{
	m_this.mpr_variable.reset_texture.M_Reset_Texture();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Texture_Manager::~C_Texture_Manager(void)
{
	M_Release();

	mpr_variable.reset_texture.M_Delete();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Manager::M_Release(void)
{
	for (S_Texture_Manage_Inform & now_texture : m_this.mpr_variable.texture_list)
	{
		now_texture.texture.reset();
	}

	m_this.mpr_variable.texture_list.clear();
	m_this.mpr_variable.texture_list.shrink_to_fit();

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃e�N�X�`����Ԃ�
// ����   �Fstring �e�N�X�`���̖��O
// �߂�l �FC_Texture_Data_System * �w�肳�ꂽ�e�N�X�`���ւ̃A�h���X�A�Ȃ����nullptr��Ԃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
RENDERING::CAPSULE::C_Texture_Data_System * C_Texture_Manager::M_Get_Texture_By_Name(std::string in_texture_name)
{
	// �e�N�X�`��������w�肳�ꂽ�e�N�X�`����T���āA���������炻���Ԃ�
	for (S_Texture_Manage_Inform & now_texture_inform : m_this.mpr_variable.texture_list)
	{
		if (now_texture_inform.name == in_texture_name)
		{
			now_texture_inform.user_sum += 1;
			return now_texture_inform.texture.get();
		}
	}

	// ������Ȃ�����
	return nullptr;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`��������e�N�X�`�������[�h����
// ����   �Fstring �e�N�X�`����
// �߂�l �FC_Texture_Data_System * ���������e�N�X�`���ւ̃A�h���X�A�Ȃ����nullptr��Ԃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
RENDERING::CAPSULE::C_Texture_Data_System * C_Texture_Manager::M_Load_Texture_By_Name(std::string in_texture_name)
{
	// �� �萔 �� //
	std::string texture_inform_path = "project/asset/texture/" + in_texture_name;	// �e�N�X�`�����ւ̃p�X

	int texture_slot_num = m_this.mpr_variable.texture_list.size();	// ���삷��e�N�X�`���̔ԍ�


	// �V�����e�N�X�`���ݒ�p�̃X���b�g�𐶐�
	m_this.mpr_variable.texture_list.resize(texture_slot_num + 1);
	m_this.mpr_variable.texture_list[texture_slot_num].texture.reset(new RENDERING::CAPSULE::C_Texture_Data_System());

	// �e�N�X�`����񂩂�e�N�X�`�������[�h����A�ł��Ȃ����false��Ԃ�
	if (m_this.mpr_variable.texture_list[texture_slot_num].texture->M_Create_Texture_By_Load_Texture_File(texture_inform_path) == false)
	{
		return nullptr;
	}

	// �V�����e�N�X�`���̖��O��o�^���A�g�p����Ă��鐔�����Z
	m_this.mpr_variable.texture_list[texture_slot_num].name = in_texture_name;
	m_this.mpr_variable.texture_list[texture_slot_num].user_sum = 1;

	// �����ł̓e�N�X�`���}�b�v�͎g�p���Ȃ��̂ō폜
	m_this.mpr_variable.texture_list[texture_slot_num].texture->M_Delete_Map();

	// ���������e�N�X�`����Ԃ�
	return m_this.mpr_variable.texture_list[texture_slot_num].texture.get();
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���Z�b�g�p�̃e�N�X�`����Ԃ�
// ����   �Fvoid
// �߂�l �FC_Texture_Data_System * �e�N�X�`����񃊃Z�b�g���̃e�N�X�`���̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
RENDERING::CAPSULE::C_Texture_Data_System * C_Texture_Manager::M_Get_Reset_Texture(void)
{
	return &m_this.mpr_variable.reset_texture;
}


//-��- �폜 -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�e�N�X�`���ݒ�̏��L����������邱�Ƃ�ʒm����
// ����   �FC_Texture_Data_System * & ���L�����������V�F�[�_�[�ݒ�̃A�h���X�̎Q�Ɓiconst�j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Manager::M_Release_Texture(RENDERING::CAPSULE::C_Texture_Data_System * & in_release_texture_address)
{
	// �e�N�X�`��������w�肳�ꂽ�e�N�X�`����T���āA���������珊�L����Ă��鐔�̃J�E���g�����炵�ĎQ�Ƃł��Ȃ�����
	for (S_Texture_Manage_Inform & now_texture_inform : m_this.mpr_variable.texture_list)
	{
		if (now_texture_inform.texture.get() == in_release_texture_address)
		{
			in_release_texture_address = &m_this.mpr_variable.reset_texture;
			now_texture_inform.user_sum -= 1;


			// ���̃e�N�X�`�����g���Ȃ��Ȃ�����폜����
			m_this.mpr_variable.texture_list.erase
			(
				std::remove_if
				(
					m_this.mpr_variable.texture_list.begin(),
					m_this.mpr_variable.texture_list.end(),

					// �c��̐���0�ɂȂ�ƍ폜���郉���_��
					[](S_Texture_Manage_Inform & in_texture)->bool
					{
						if (in_texture.user_sum < 1)
						{
							in_texture.texture.reset();

							return true;
						}

						return false;
					}
				),
				m_this.mpr_variable.texture_list.end()
			);

			return;
		}
	}

	return;
}



