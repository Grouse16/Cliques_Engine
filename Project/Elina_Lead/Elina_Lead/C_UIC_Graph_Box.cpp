//����������������������������������������������//
// �ڍ�   �F�摜��\������UI�̃N���X�iUI�̃R���|�[�l���g�j
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_UIC_Graph_Box.h"
#include "E_BOX_VERTEX_SETTING.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::UI_COMPONENT;


// �� �֐� �� //

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_UIC_Text_Box::C_UIC_Text_Box(void)
{
	// �� �ϐ��錾�@�� //
	std::vector<DATA::VERTEX::S_UI_Vertex> & vertex_list = mpr_variable.vertex_system.M_Get_Vertex_Data();	// ���_�f�[�^�̃��X�g

	std::vector<unsigned int> & index_list = mpr_variable.vertex_system.M_Get_Index_Data();	// �C���f�b�N�X�f�[�^�̃��X�g


	// �}�e���A���̃��[�h
	mpr_variable.material.M_Load_Material("UI_Material");

	// ���_�f�[�^�̐���
	mpr_variable.vertex_system.M_Create_Vertex_And_Index_Data_And_Buffer((int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_SUM, (int)DATA::VERTEX::SETTING::E_BOX_INDEX_SETTING::e_SUM);


	// �C���f�b�N�X�f�[�^���Z�b�g����
	index_list[0] = (unsigned int)DATA::VERTEX::SETTING::E_BOX_INDEX_SETTING::e_INDEX_1;
	index_list[1] = (unsigned int)DATA::VERTEX::SETTING::E_BOX_INDEX_SETTING::e_INDEX_2;
	index_list[2] = (unsigned int)DATA::VERTEX::SETTING::E_BOX_INDEX_SETTING::e_INDEX_3;
	index_list[3] = (unsigned int)DATA::VERTEX::SETTING::E_BOX_INDEX_SETTING::e_INDEX_4;
	index_list[4] = (unsigned int)DATA::VERTEX::SETTING::E_BOX_INDEX_SETTING::e_INDEX_5;
	index_list[5] = (unsigned int)DATA::VERTEX::SETTING::E_BOX_INDEX_SETTING::e_INDEX_6;


	// UV���W�����ꂼ��ݒ�
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_LEFT_TOP].uv.M_Set_UV(0.0f, 0.0f);
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_LEFT_BOTTOM].uv.M_Set_UV(0.0f, 1.0f);
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_RIGHT_TOP].uv.M_Set_UV(1.0f, 0.0f);
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_RIGHT_BOTTOM].uv.M_Set_UV(1.0f, 1.0f);


	// ���_�o�b�t�@�ɃZ�b�g
	mpr_variable.vertex_system.M_Vertex_Data_To_Buffer();
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_UIC_Text_Box::~C_UIC_Text_Box(void)
{
	mpr_variable.vertex_system.M_Release();
	mpr_variable.material.M_Release();

	return;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃e�N�X�`�������[�h����
// ����   �Fstring ���[�h����e�N�X�`����
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_UIC_Text_Box::M_Load_Texture(std::string in_load_texture_name)
{
	mpr_variable.material.M_Get_Material_Address()->M_Load_Texture_To_Slot_By_Index(0, in_load_texture_name);

	return;
}


//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�X�V���s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_UIC_Text_Box::M_Update(void)
{
	return;
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�`����s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_UIC_Text_Box::M_Draw(void)
{
	// �}�e���A����`��ɓK�p
	mpr_variable.material.M_Material_Attach_To_Draw();

	// ���_��`�悷��
	mpr_variable.vertex_system.M_Draw_All_Vertex();

	return;
}


//-��- ���W -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FUI�̍��W���Z�b�g����
// ����   �FS_Rect �Z�b�g�ʒu�̎l�p�`�i�������O�C�E�オ�P�j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_UIC_Text_Box::M_Set_UI_Position(DATA::RECTSETTING::S_Rect in_set_rect)
{
	// �� �ϐ��錾 �� //
	std::vector<DATA::VERTEX::S_UI_Vertex> & vertex_list = mpr_variable.vertex_system.M_Get_Vertex_Data();	// ���_�f�[�^�̃��X�g


	// ���㒸�_�̍��W���Z�b�g
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_LEFT_TOP].position.x = in_set_rect.left_x / 2.0f;
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_LEFT_TOP].position.y = in_set_rect.top_y / 2.0f;

	// �E�㒸�_�̍��W���Z�b�g
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_RIGHT_TOP].position.x = in_set_rect.right_x / 2.0f;
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_RIGHT_TOP].position.y = in_set_rect.top_y / 2.0f;

	// �������_�̍��W���Z�b�g
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_LEFT_BOTTOM].position.x = in_set_rect.left_x / 2.0f;
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_LEFT_BOTTOM].position.y = in_set_rect.bottom_y / 2.0f;

	// �E�����_�̍��W���Z�b�g
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_RIGHT_BOTTOM].position.x = in_set_rect.right_x / 2.0f;
	vertex_list[(int)DATA::VERTEX::SETTING::E_BOX_VERTEX_SETTING::e_RIGHT_BOTTOM].position.y = in_set_rect.bottom_y / 2.0f;

	// ���_�o�b�t�@�ɃZ�b�g
	mpr_variable.vertex_system.M_Vertex_Data_To_Buffer();

	return;
}


//-��- �J���[ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�F��ݒ肷��
// ����   �FC_Color �F
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_UIC_Text_Box::M_Set_Color(DATA::COLOR::C_Color in_set_color)
{
	// �� �ϐ��錾 �� //
	std::vector<DATA::VERTEX::S_UI_Vertex> & vertex_list = mpr_variable.vertex_system.M_Get_Vertex_Data();	// ���_�f�[�^�̃��X�g


	// ���_�̐F��ݒ肵�Ē��_�o�b�t�@�ɃZ�b�g
	for (DATA::VERTEX::S_UI_Vertex & now_vertex : vertex_list)
	{
		now_vertex.color = in_set_color;
	}
	mpr_variable.vertex_system.M_Vertex_Data_To_Buffer();

	return;
}
