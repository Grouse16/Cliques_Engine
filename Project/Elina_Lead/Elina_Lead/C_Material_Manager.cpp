//����������������������������������������������//
// �ڍ�   �F�}�e���A���𐧌䂷�邽�߂̃V�X�e��
// ����   �F�}�e���A���̃��[�h�������s������A�d�����ē����}�e���A�������[�h���Ȃ��悤�ɊǗ�����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include <algorithm>

#include "C_Material_Manager.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::MATERIAL::MANAGER;


// �� �X�^�e�B�b�N�ϐ� �� //
C_Material_Manager C_Material_Manager::m_this;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^�A�V���O���g��������
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Material_Manager::C_Material_Manager(void)
{
	return;
}


//==�� �p�u���b�N ��==//

//-��- �I���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^�A�V���O���g��������
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Material_Manager::~C_Material_Manager(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Material_Manager::M_Release(void)
{
	for (S_Material_Manage_Inform & now_material : m_this.mpr_variable.material_inform_list)
	{
		now_material.material.reset();
	}

	m_this.mpr_variable.material_inform_list.clear();
	m_this.mpr_variable.material_inform_list.shrink_to_fit();

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�}�e���A����Ԃ�
// ����   �Fstd::string �}�e���A���̖��O
// �߂�l �FC_Material * �w�肳�ꂽ�}�e���A���f�[�^�ւ̃A�h���X�A�Ȃ����nullptr��Ԃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::MATERIAL::C_Material * C_Material_Manager::M_Get_Material_By_Name(std::string in_material_name)
{
	// �}�e���A��������w�肳�ꂽ�}�e���A����T���āA���������炻���Ԃ�
	for (S_Material_Manage_Inform & now_material_inform : m_this.mpr_variable.material_inform_list)
	{
		if (now_material_inform.name == in_material_name)
		{
			now_material_inform.user_sum += 1;
			return now_material_inform.material.get();
		}
	}

	// ������Ȃ�����
	return nullptr;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�}�e���A��������}�e���A�������[�h����
// ����   �Fstd::string �}�e���A���̖��O
// �߂�l �FC_Material * �w�肳�ꂽ�}�e���A���f�[�^�ւ̃A�h���X�A�Ȃ����nullptr��Ԃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::MATERIAL::C_Material * C_Material_Manager::M_Load_Material_By_Name(std::string in_material_name)
{
	// �� �萔 �� //
	std::string material_inform_path = "project/asset/material/" + in_material_name + ".elmat";	// �}�e���A�����ւ̃p�X

	int material_slot_num = m_this.mpr_variable.material_inform_list.size();	// ���삷��}�e���A���̔ԍ�


	// �V�����}�e���A���ݒ�p�̃X���b�g�𐶐�
	m_this.mpr_variable.material_inform_list.resize(material_slot_num + 1);
	m_this.mpr_variable.material_inform_list[material_slot_num].material.reset(new ASSET::MATERIAL::C_Material);

	// �}�e���A����񂩂�}�e���A�������[�h����A�ł��Ȃ����false��Ԃ�
	if (m_this.mpr_variable.material_inform_list[material_slot_num].material->M_Load_Material_By_Path(material_inform_path) == false)
	{
		return nullptr;
	}

	// �V�����}�e���A���̖��O��o�^���A�g�p����Ă��鐔�����Z
	m_this.mpr_variable.material_inform_list[material_slot_num].name = in_material_name;
	m_this.mpr_variable.material_inform_list[material_slot_num].user_sum = 1;

	// ���������}�e���A����Ԃ�
	return m_this.mpr_variable.material_inform_list[material_slot_num].material.get();
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�}�e���A����Ԃ�
// ����   �Fstd::string �}�e���A���̖��O
// �߂�l �FC_Material * �w�肳�ꂽ�}�e���A���f�[�^�ւ̃A�h���X�A�Ȃ����nullptr��Ԃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Material_Manager::M_Release_Material(ASSET::MATERIAL::C_Material * & in_release_material_address)
{
	// �}�e���A��������w�肳�ꂽ�}�e���A����T���āA���������珊�L����Ă��鐔�̃J�E���g�����炵�ĎQ�Ƃł��Ȃ�����
	for (S_Material_Manage_Inform & now_material_inform : m_this.mpr_variable.material_inform_list)
	{
		if (now_material_inform.material.get() == in_release_material_address)
		{
			in_release_material_address = nullptr;
			now_material_inform.user_sum -= 1;


			// ���̃}�e���A�����g���Ȃ��Ȃ�����폜����
			m_this.mpr_variable.material_inform_list.erase
			(
				std::remove_if
				(
					m_this.mpr_variable.material_inform_list.begin(),
					m_this.mpr_variable.material_inform_list.end(),

					// �c��̐���0�ɂȂ�ƍ폜���郉���_��
					[](S_Material_Manage_Inform & in_material)->bool
					{
						if (in_material.user_sum < 1)
						{
							in_material.material.reset();

							return true;
						}

						return false;
					}
				), 
				m_this.mpr_variable.material_inform_list.end()
			);

			return;
		}
	}

	return;
}


