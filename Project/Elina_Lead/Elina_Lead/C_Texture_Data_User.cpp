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
	mpr_variable.texture_data.reset(ASSET::TEXTURE::MANAGER::C_Texture_Manager::M_Get_Reset_Texture());

	// �I���W�i���̃e�N�X�`���ł͂Ȃ����Ƃ�����
	mpr_variable.flg_original_texture = false;

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
	if (mpr_variable.texture_data.get() == ASSET::TEXTURE::MANAGER::C_Texture_Manager::M_Get_Reset_Texture())
	{
		return;
	}


	// �I���W�i���̃e�N�X�`���Ȃ�A����������������Z�b�g�p�e�N�X�`���Ɠ���ւ���
	if (mpr_variable.flg_original_texture)
	{
		mpr_variable.texture_data->M_Delete();
		mpr_variable.texture_data.reset(ASSET::TEXTURE::MANAGER::C_Texture_Manager::M_Get_Reset_Texture());
	}

	// ���[�h�����e�N�X�`���Ȃ�₢���킹���č폜�@���[�h�����e�N�X�`���������ꍇ�̓��Z�b�g�p�e�N�X�`���ɂȂ��ĕԂ��Ă���
	else
	{
		ASSET::TEXTURE::MANAGER::C_Texture_Manager::M_Release_Texture(mpr_variable.texture_data);
	}

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
	M_Release();
	mpr_variable.texture_data.release();
	mpr_variable.texture_data.reset(get_texture);

	// �I���W�i���̃e�N�X�`���ł͂Ȃ����Ƃ�����
	mpr_variable.flg_original_texture = false;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�I���W�i���̃e�N�X�`���f�[�^�𐶐�����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Data_User::M_Create_Original_Texture_Data(void)
{
	// �ȑO�܂ł̃e�N�X�`�����������
	M_Release();

	// �Ǝ��̃f�[�^�����[�h
	mpr_variable.texture_data.release();
	mpr_variable.texture_data.reset(new RENDERING::CAPSULE::C_Texture_Data_System());

	// �I���W�i���̃e�N�X�`���ł��邱�Ƃ�����
	mpr_variable.flg_original_texture = true;

	return;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���̃e�N�X�`����`��p���i���ʖ�,�V�F�[�_�[�̎�ށj������GPU�ɃZ�b�g����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Data_User::M_Texture_Attach_To_Draw_By_Inform(void)
{
	mpr_variable.texture_data->M_Set_Attach_Shader_Kind(mpr_variable.shader_kind);
	mpr_variable.texture_data->M_Set_Data_Signature_Name(mpr_variable.signature_name);
	mpr_variable.texture_data->M_Attach_To_Shader();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���̃e�N�X�`����`��p�ɃZ�b�g����
// ����   �Fint �ݒ��̃C���f�b�N�X�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Data_User::M_Texture_Attach_To_Draw_By_Index(int in_index_number)
{
	mpr_variable.texture_data->M_Attach_To_Shader_By_Index(in_index_number);

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`���f�[�^�̃A�h���X��Ԃ�
// ����   �Fvoid
// �߂�l �FC_Texture_Data_System * �e�N�X�`���f�[�^�̃A�h���X
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
RENDERING::CAPSULE::C_Texture_Data_System * C_Texture_Data_User::M_Get_Texture_Data(void)
{
	return mpr_variable.texture_data.get();
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`���̎��ʖ����Z�b�g����
// ����   �Fstring �e�N�X�`�����ʖ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Data_User::M_Set_Texture_Signature(std::string in_set_signature_name)
{
	mpr_variable.signature_name = in_set_signature_name;

	return;
}

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�F�[�_�[�̎�ނ��Z�b�g����
// ����   �FE_SHADER_KIND �V�F�[�_�[�̎��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Texture_Data_User::M_Set_Texture_Shader_Kind(ASSET::SHADER::E_SHADER_KIND in_set_shader_kind)
{
	mpr_variable.shader_kind = in_set_shader_kind;

	return;
}
