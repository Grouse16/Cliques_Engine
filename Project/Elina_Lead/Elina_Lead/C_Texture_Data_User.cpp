//����������������������������������������������//
// �ڍ�   �F�e�N�X�`���f�[�^�̏����~���ɐݒ肵�A�����_�����O���邽�߂̃V�X�e��
// ����   �F�e�N�X�`���f�[�^�̃����_�����O���J�v�Z��������
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Texture_Manager.h"
#include "C_Texture_Data_User.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::TEXTURE;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Texture_Data_User::C_Texture_Data_User(void)
{
	// �����̃e�N�X�`�����擾����
	mpr_variable.texture_data = ASSET::TEXTURE::MANAGER::C_Texture_Manager::M_Get_Reset_Texture();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Texture_Data_User::~C_Texture_Data_User(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`�����������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Data_User::M_Release(void)
{
	// �e�N�X�`���������Ă��Ȃ��Ȃ����͂��Ȃ��i���Z�b�g�p�̃e�N�X�`���̎��j
	if (mpr_variable.texture_data == ASSET::TEXTURE::MANAGER::C_Texture_Manager::M_Get_Reset_Texture())
	{
		return;
	}

	ASSET::TEXTURE::MANAGER::C_Texture_Manager::M_Release_Texture(mpr_variable.texture_data);

	return;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃e�N�X�`����ǂݍ���
// ����   �Fstring �e�N�X�`����
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Data_User::M_Load_Texture(std::string in_texture_name)
{
	// �� �ϐ��錾 �� //
	RENDERING::CAPSULE::C_Texture_Data_System * get_texture = nullptr;	// ���肵���e�N�X�`���f�[�^


	// �e�N�X�`��������e�N�X�`�����擾����
	get_texture = ASSET::TEXTURE::MANAGER::C_Texture_Manager::M_Get_Texture_By_Name(in_texture_name);


	// �e�N�X�`�����܂���������Ă��Ȃ��Ȃ烍�[�h����
	if (get_texture == nullptr)
	{
		get_texture = ASSET::TEXTURE::MANAGER::C_Texture_Manager::M_Load_Texture_By_Name(in_texture_name);

		// �����ɂ����s�����甲����
		if (get_texture == nullptr)
		{
			return;
		}
	}

	// �擾�����e�N�X�`������������
	mpr_variable.texture_data = get_texture;

	return;
}



//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���̃e�N�X�`����`��p�ɃZ�b�g����
// ����   �Fint �ݒ��̃C���f�b�N�X�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Data_User::M_Texture_Attach_To_Draw(int in_index_number)
{
	mpr_variable.texture_data->M_Attach_To_Shader_By_Index(in_index_number);

	return;
}
