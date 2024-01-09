//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�����p�̃��b�V���̃N���X
// ����   �F�A�j���[�V�����u�����h�p�̒萔�o�b�t�@�����V�X�e����ǉ��������b�V���V�X�e���N���X
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 ���@//
#include "C_Animative_Mesh.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::ANIMATION::MESH;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animative_Mesh::C_Animative_Mesh(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animative_Mesh::~C_Animative_Mesh(void)
{
	M_Release();

	return;
}



//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������̉�����s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animative_Mesh::M_Release(void)
{
	mpr_variable.vertex_index_system.M_Release();
	mpr_variable.material.M_Release();

	return;
}


//-��- ���_�C���f�b�N�X -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�C���f�b�N�X���w�肳�ꂽ��������
// ����   �Fint �������钸�_�C���f�b�N�X��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animative_Mesh::M_Create_Index_List(int in_creat_index_sum)
{
	mpr_variable.vertex_index_system.M_Create_Index_Buffer(in_creat_index_sum);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�C���f�b�N�X�̃f�[�^���C���f�b�N�X�o�b�t�@�ɐݒ肷��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animative_Mesh::M_Attach_Index_Data_To_Buffer(void)
{
	mpr_variable.vertex_index_system.M_Set_Index_Data_To_Buffer();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�C���f�b�N�X�f�[�^�݂̂��폜����i�o�b�t�@�ɐݒ��A�ҏW���Ȃ��Ȃ�K�v���Ȃ��j
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animative_Mesh::M_Delete_Index_Data(void)
{
	mpr_variable.vertex_index_system.M_Release();

	return;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃}�e���A�������[�h����
// ����   �F�}�e���A����
// �߂�l �F�������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Animative_Mesh::M_Load_Material_By_Name(std::string in_load_material_name)
{
	return mpr_variable.material.M_Load_Material(in_load_material_name);
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���b�V������ݒ肷��
// ����   �Fstring ���b�V����
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animative_Mesh::M_Set_Name(std::string in_set_name)
{
	mpr_variable.name = in_set_name;

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�C���f�b�N�X�f�[�^�̃��X�g�̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �Fvector<unsigned __int32> & ���_�C���f�b�N�X�f�[�^�̃��X�g�̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::vector<unsigned __int32> & C_Animative_Mesh::M_Get_Index_Data_List(void)
{
	return mpr_variable.vertex_index_system.M_Get_Index_Data();
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̃}�e���A�����[�U�[�̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �FC_Material_User & �}�e���A�����[�U�[�̎Q�Ƃ�Ԃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::MATERIAL::C_Material_User & C_Animative_Mesh::M_Get_Material_User(void)
{
	return mpr_variable.material;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���b�V������Ԃ�
// ����   �Fvoid
// �߂�l �Fstring ���b�V����
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::string C_Animative_Mesh::M_Get_Name(void)
{
	return mpr_variable.name;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���b�V���̕`������s����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animative_Mesh::M_Draw_Mesh(void)
{
	// �}�e���A�����Z�b�g����i�����_�����O�ݒ��o�^���A�萔�o�b�t�@�A�e�N�X�`����GPU�̃f�[�^�X���b�g�ɃZ�b�g�j
	mpr_variable.material.M_Material_Attach_To_Draw();

	// ���_��`�悷��i���_�C���f�b�N�X�o�b�t�@�̃��X�g�S�Ă�`�悷��j
	mpr_variable.vertex_index_system.M_Draw_Execute_By_Index_Data();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�}�e���A���̐ݒ�������ɖʂ̕`��̂ݍs���i�O���Ń}�e���A����ݒ肵�Ă���`�悷��Ƃ��p�j
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animative_Mesh::M_Draw_Mesh_Do_Not_Set_Material(void)
{
	mpr_variable.vertex_index_system.M_Draw_Execute_By_Index_Data();

	return;
}


