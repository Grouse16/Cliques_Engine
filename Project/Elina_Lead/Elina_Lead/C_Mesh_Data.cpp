//����������������������������������������������//
// �ڍ�   �F���b�V���̃f�[�^�Ǘ��p�̃V�X�e���̃N���X
// ����   �F���_�Ⓒ�_�C���f�b�N�X���̊Ǘ����s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Mesh_Data.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::MESH;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Mesh_Data::C_Mesh_Data(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Mesh_Data::~C_Mesh_Data(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������̉�����s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Mesh_Data::M_Release(void)
{
	mpr_variable.vertex_setting.M_Release();
	mpr_variable.material.M_Release();

	return;
}


//-��- �ݒ� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_���w�肳�ꂽ��������
// ����   �Fint �������钸�_��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Mesh_Data::M_Create_Vertex_List(int in_creat_vertex_sum)
{
	mpr_variable.vertex_setting.M_Create_Vertex_Data_By_Number(in_creat_vertex_sum);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�C���f�b�N�X���w�肳�ꂽ��������
// ����   �Fint �������钸�_�C���f�b�N�X��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Mesh_Data::M_Create_Index_List(int in_creat_index_sum)
{
	mpr_variable.vertex_setting.M_Create_Index_Data_By_Number(in_creat_index_sum);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�o�b�t�@�ƒ��_�C���f�b�N�X�o�b�t�@�𐶐����@�����_�f�[�^�ƒ��_�C���f�b�N�X��K�v�Ȑ������������Ă�����s���邱��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Mesh_Data::M_Create_Vertex_Buffer_And_Index_Buffer(void)
{
	mpr_variable.vertex_setting.M_Create_Vertex_Buffer_By_Now_Parameter();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�C���f�b�N�X�̃f�[�^���C���f�b�N�X�o�b�t�@�ɐݒ肷��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Mesh_Data::M_Attach_Index_Data_To_Buffer(void)
{
	mpr_variable.vertex_setting.M_Index_Data_To_Buffer();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�f�[�^�𒸓_�o�b�t�@�ɐݒ肷��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Mesh_Data::M_Attach_Vertex_Data_To_Buffer(void)
{
	mpr_variable.vertex_setting.M_Set_Vertex_Data_To_Buffer();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�f�[�^�݂̂��폜����i���_�o�b�t�@�ɐݒ��A�ҏW���Ȃ��Ȃ玝���Ă����K�v���Ȃ��j
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Mesh_Data::M_Delete_Vertex_Data(void)
{
	mpr_variable.vertex_setting.M_Delete_Vertex_Data();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�C���f�b�N�X�f�[�^�݂̂��폜����i�o�b�t�@�ɐݒ��A�ҏW���Ȃ��Ȃ�K�v���Ȃ��j
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Mesh_Data::M_Delete_Index_Data(void)
{
	mpr_variable.vertex_setting.M_Delete_Index_Data();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃}�e���A�������[�h����
// ����   �F�}�e���A����
// �߂�l �F�������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Mesh_Data::M_Load_Material_By_Name(std::string in_load_material_name)
{
	return mpr_variable.material.M_Load_Material(in_load_material_name);
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�f�[�^�̃��X�g�̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �Fvector<S_3D_Model_Vertex> & ���_�f�[�^�̃��X�g��Ԃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::vector<DATA::VERTEX::S_3D_Model_Vertex> & C_Mesh_Data::M_Get_Vertex_Data_List(void)
{
	return mpr_variable.vertex_setting.M_Get_Vertex_Data();
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�C���f�b�N�X�f�[�^�̃��X�g�̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �Fvector<unsigned __int32> & ���_�C���f�b�N�X�f�[�^�̃��X�g�̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::vector<unsigned __int32> & C_Mesh_Data::M_Get_Index_Data_List(void)
{
	return mpr_variable.vertex_setting.M_Get_Index_Data();
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̃}�e���A�����[�U�[�̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �FC_Material_User & �}�e���A�����[�U�[�̎Q�Ƃ�Ԃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::MATERIAL::C_Material_User & C_Mesh_Data::M_Get_Material_User(void)
{
	return mpr_variable.material;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���b�V���̕`������s����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Mesh_Data::M_Draw_Mesh(void)
{
	// �}�e���A�����Z�b�g����i�����_�����O�ݒ��o�^���A�萔�o�b�t�@�A�e�N�X�`����GPU�̃f�[�^�X���b�g�ɃZ�b�g�j
	mpr_variable.material.M_Material_Attach_To_Draw();

	// ���_��`�悷��i���_�C���f�b�N�X�o�b�t�@�̃��X�g�S�Ă�`�悷��j
	mpr_variable.vertex_setting.M_Set_Vertex_Buffer_To_Redering();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�}�e���A���̐ݒ�������ɖʂ̕`��̂ݍs���i�O���Ń}�e���A����ݒ肵�Ă���`�悷��Ƃ��p�j
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Mesh_Data::m_Draw_Mesh_Do_Not_Set_Material(void)
{
	mpr_variable.vertex_setting.M_Set_Vertex_Buffer_To_Redering();

	return;
}


