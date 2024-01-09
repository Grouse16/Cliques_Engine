//����������������������������������������������//
// �ڍ�   �F���_�C���f�b�N�X�V�X�e���̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Vertex_Index_System.h"
#include "S_Create_Index_Buffer_Inform.h"
#include "C_Rendering_Graphics_API_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::CAPSULE;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Vertex_Index_System::C_Vertex_Index_System(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R�s�[�R���X�g���N�^
// ����   �Fconst C_Vertex_Index_System & �R�s�[����f�[�^�̎Q��(const)
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Vertex_Index_System::C_Vertex_Index_System(const C_Vertex_Index_System & in_copy_data)
{
	// ���_�C���f�b�N�X�o�b�t�@���R�s�[����
	mpr_variable.m_index_buffer.reset(in_copy_data.mpr_variable.m_index_buffer.get());

	// ���_�C���f�b�N�X�f�[�^���R�s�[����
	mpr_variable.m_index_data = in_copy_data.mpr_variable.m_index_data;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Vertex_Index_System::~C_Vertex_Index_System(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Vertex_Index_System::M_Release(void)
{
	mpr_variable.m_index_buffer.reset();

	mpr_variable.m_index_data.clear();
	mpr_variable.m_index_data.shrink_to_fit();

	return;
}


//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�C���f�b�N�X�o�b�t�@�𐶐�����
// ����   �Fint ��������C���f�b�N�X��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Vertex_Index_System::M_Create_Index_Buffer(int in_index_sum)
{
	// �� �ϐ��錾 �� //
	RENDERING::GRAPHICS::CREATE::S_Create_Index_Buffer_Inform creat_index_inform;	// ���_�C���f�b�N�X�o�b�t�@�����p�̏��


	// ���_�C���f�b�N�X����ݒ肷��
	creat_index_inform.index_sum = in_index_sum;

	// ���_�C���f�b�N�X�o�b�t�@�𐶐�����
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Create_Index_Inform(mpr_variable.m_index_buffer, creat_index_inform);

	
	// ���_�C���f�b�N�X�f�[�^�𐶐�����
	mpr_variable.m_index_data.resize(in_index_sum);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�C���f�b�N�X�o�b�t�@�����݂̃C���f�b�N�X�f�[�^�ɍ��킹�Đ�������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Vertex_Index_System::M_Create_Index_Buffer_By_Now_Index_Data(void)
{
	// �� �ϐ��錾 �� //
	RENDERING::GRAPHICS::CREATE::S_Create_Index_Buffer_Inform creat_index_inform;	// ���_�C���f�b�N�X�o�b�t�@�����p�̏��


	// ���_�C���f�b�N�X����ݒ肷��
	creat_index_inform.index_sum = (int)mpr_variable.m_index_data.size();

	// ���_�C���f�b�N�X�o�b�t�@�𐶐�����
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Create_Index_Inform(mpr_variable.m_index_buffer, creat_index_inform);

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�C���f�b�N�X�f�[�^�̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �Fvector<unsigned int> & ���_�C���f�b�N�X�f�[�^�̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::vector<unsigned int> & C_Vertex_Index_System::M_Get_Index_Data(void)
{
	return mpr_variable.m_index_data;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�C���f�b�N�X�f�[�^���g�p���ĕ`�悷��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Vertex_Index_System::M_Set_Index_Data_To_Buffer(void)
{
	mpr_variable.m_index_buffer->M_Set_Index_Setting(mpr_variable.m_index_data);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�C���f�b�N�X�f�[�^���g�p���ĕ`�悷��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Vertex_Index_System::M_Draw_Execute_By_Index_Data(void)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Draw_Command_By_Index_Buffer(mpr_variable.m_index_buffer);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�C���f�b�N�X�f�[�^���g�p���ĕ`�悷��C���f�b�N�X�f�[�^�͈̔͂��w�肵�ĕ`�悷��
// ����   �Fint �`��J�n�C���f�b�N�X, int �`��I���C���f�b�N�X
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Vertex_Index_System::M_Draw_Index_Data_By_Index_Data_Range(int in_draw_start_index, int in_draw_end_index)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Draw_Command_By_Index_Buffer_By_Range(mpr_variable.m_index_buffer, in_draw_start_index, in_draw_end_index);

	return;
}

