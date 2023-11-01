//����������������������������������������������//
// �ڍ�   �F�}�e���A�����g�p���邽�߂̃N���X
// ����   �F�}�e���A���̎擾�A���[�h�A������~���ɍs���Astatic�ł���}�l�[�W���𑼂̎���������؂藣�����߂ɂ���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Material_User.h"
#include "C_Material_Manager.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::MATERIAL;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Material_User::C_Material_User(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Material_User::~C_Material_User(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�}�e���A�����������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Material_User::M_Release(void)
{
	// �}�e���A���������Ă��Ȃ��Ȃ�X���[
	if (mpr_variable.material_address == nullptr)
	{
		return;
	}

	// �}�e���A���̎g�p�I���𐧌�p�V�X�e���ɒʒm
	ASSET::MATERIAL::MANAGER::C_Material_Manager::M_Release_Material(mpr_variable.material_address);

	return;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃}�e���A����ǂݍ���
// ����   �Fstd::string �}�e���A����
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Material_User::M_Load_Material(std::string in_material_name)
{
	// �� �ϐ��錾 �� //
	ASSET::MATERIAL::C_Material * new_material_address;	// �V�����}�e���A���̃A�h���X


	// �}�e���A�����O����T�����Ď擾
	new_material_address = ASSET::MATERIAL::MANAGER::C_Material_Manager::M_Get_Material_By_Name(in_material_name);

	// �w�肵���}�e���A�����܂��Ȃ��Ȃ琶������
	if (new_material_address == nullptr)
	{
		new_material_address = ASSET::MATERIAL::MANAGER::C_Material_Manager::M_Load_Material_By_Name(in_material_name);

		// �����Ɏ��s�����甲����
		if (new_material_address == nullptr)
		{
			return;
		}
	}


	// �擾�ł����}�e���A���Ɠ���ւ���
	M_Release();
	mpr_variable.material_address = new_material_address;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���̃}�e���A����`��p�ɃZ�b�g����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Material_User::M_Material_Attach_To_Draw(void)
{
	mpr_variable.material_address->M_Attach_To_GPU();

	return;
}



