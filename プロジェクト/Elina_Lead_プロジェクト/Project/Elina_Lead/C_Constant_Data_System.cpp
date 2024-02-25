//����������������������������������������������//
// �ڍ�   �F�萔�o�b�t�@�̏����~���ɐݒ肵�A�����_�����O���邽�߂̃V�X�e��
// ����   �F�萔�f�[�^�̃����_�����O���J�v�Z��������
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Constant_Data_System.h"
#include "C_Rendering_API_Interface_Constant_Resource.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::CAPSULE;


// �� �֐� �� //

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Constant_Buffer_Data_System::C_Constant_Buffer_Data_System(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Constant_Buffer_Data_System::~C_Constant_Buffer_Data_System(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Constant_Buffer_Data_System::M_Release(void)
{
	mpr_variable.constant_data.clear();
	mpr_variable.constant_data.shrink_to_fit();

	mpr_variable.data_signature_name.clear();
	mpr_variable.data_signature_name.shrink_to_fit();
	
	mpr_variable.constant_buffer_inform.reset();

	mpr_variable.attach_shader_kind = ASSET::SHADER::E_SHADER_KIND::e_ALL;

	mpr_variable.list_sum = 0;

	return;
}


//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�萔�o�b�t�@�ƃf�[�^�𐶐�����
// ����   �Fint �o�b�t�@��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Constant_Buffer_Data_System::M_Create_Constant_Buffer_And_Data(int in_buffer_sum)
{
	// �� �ϐ��錾 �� //
	RENDERING::API::CREATE::S_Create_Constant_Buffer_Inform creat_constant_inform;	// �萔�o�b�t�@�����p���


	// ���ݎ����Ă���f�[�^���������
	M_Release();

	// �����p�̃f�[�^��ݒ肵�Đ������s��
	creat_constant_inform.m_list_size = in_buffer_sum + ((in_buffer_sum <= 0) * 1);	// �萔�o�b�t�@�̔z�񐔁A�O�ɂȂ�Ȃ��悤�ɂ��Ă���
	RENDERING::API::RENDER_INTERFACE::C_Rendering_API_Interface_Constant_Resource::M_Create_Constant_Resource(mpr_variable.constant_buffer_inform, creat_constant_inform);


	// �� �萔�f�[�^�̐��� �� //

	// �萔�f�[�^���m�ۂ��B�萔�o�b�t�@�z�񐔂�ݒ肷��
	mpr_variable.constant_data.resize(in_buffer_sum);
	mpr_variable.list_sum = creat_constant_inform.m_list_size;
	
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�萔�o�b�t�@�݂̂𐶐�����
// ����   �Fint �o�b�t�@��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Constant_Buffer_Data_System::M_Create_Only_Constant_Buffer(int in_buffer_sum)
{
	// �� �ϐ��錾 �� //
	RENDERING::API::CREATE::S_Create_Constant_Buffer_Inform creat_constant_inform;	// �萔�o�b�t�@�����p���


	// ���ݎ����Ă���f�[�^���������
	M_Release();

	// �����p�̃f�[�^��ݒ肵�Đ������s��
	creat_constant_inform.m_list_size = in_buffer_sum + ((in_buffer_sum <= 0) * 1);	// �萔�o�b�t�@�̔z�񐔁A�O�ɂȂ�Ȃ��悤�ɂ��Ă���
	RENDERING::API::RENDER_INTERFACE::C_Rendering_API_Interface_Constant_Resource::M_Create_Constant_Resource(mpr_variable.constant_buffer_inform, creat_constant_inform);


	// �� �萔�f�[�^�̐��� �� //

	// �萔�f�[�^���m�ۂ��B�萔�o�b�t�@�z�񐔂�ݒ肷��
	mpr_variable.list_sum = creat_constant_inform.m_list_size;

	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�[�^�̎��ʖ����Z�b�g����
// ����   �Fstring �Z�b�g���镶����
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Constant_Buffer_Data_System::M_Set_Data_Signature_Name(std::string in_set_name)
{
	mpr_variable.data_signature_name.clear();
	mpr_variable.data_signature_name = in_set_name;
	mpr_variable.data_signature_name.shrink_to_fit();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`���f�[�^�ݒ��̃V�F�[�_�[�̎�ނ�ύX����
// ����   �FE_SHADER_KIND �ݒ��̃V�F�[�_�[�̎��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Constant_Buffer_Data_System::M_Set_Attach_Shader_Kind(ASSET::SHADER::E_SHADER_KIND in_set_shader_kind)
{
	mpr_variable.attach_shader_kind = in_set_shader_kind;

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�[�^�̎��ʖ���Ԃ�
// ����   �Fvoid
// �߂�l �Fconst string & ���݂̃f�[�^���ʖ��̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const std::string & C_Constant_Buffer_Data_System::M_Get_Data_Signature_Name(void)
{
	return mpr_variable.data_signature_name;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�萔�o�b�t�@�p�̃f�[�^��Ԃ��@
// ����   �Fvoid
// �߂�l �Fvector<S_256_Byte_Type> & �萔�f�[�^
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::vector<C_Constant_Buffer_Data_System::S_256_Byte_Type> & C_Constant_Buffer_Data_System::M_Get_Constant_Data(void)
{
	return mpr_variable.constant_data;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`���f�[�^�ݒ��̃V�F�[�_�[�̎�ނ�Ԃ�
// ����   �Fvoid
// �߂�l �FE_SHADER_KIND �ݒ��̃V�F�[�_�[�̎��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::SHADER::E_SHADER_KIND C_Constant_Buffer_Data_System::M_Get_Attach_Shader_Kind(void)
{
	return mpr_variable.attach_shader_kind;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�萔�o�b�t�@�̃f�[�^�̃A�h���X���擾���ĕԂ�
// ����   �Fvoid
// �߂�l �Funsigned char * �萔�o�b�t�@�̃f�[�^�̃A�h���X
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
unsigned char * RENDERING::CAPSULE::C_Constant_Buffer_Data_System::M_Get_Constant_Buffer_Data(void)
{
	return nullptr;
}



//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�萔�o�b�t�@�����݂̃f�[�^�ōX�V����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Constant_Buffer_Data_System::M_Set_Constant_Data_To_Buffer(void)
{
	mpr_variable.constant_buffer_inform->M_Set_Data_To_Buffer(&mpr_variable.constant_data[0], mpr_variable.list_sum, 256);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�萔�o�b�t�@��GPU�ɓn��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Constant_Buffer_Data_System::M_Set_Constant_Buffer_To_GPU(void)
{
	// �� �ϐ��錾 �� //
	RENDERING::API::INSTANCE::S_Constant_Buffer_Drawing_Setting drawing_setting;	// �`��p�ɓn�����


	// �`�����ݒ肵��GPU�ɓn��
	drawing_setting.add_constant_buffer = mpr_variable.constant_buffer_inform.get();
	drawing_setting.add_attach_shader_kind = mpr_variable.attach_shader_kind;
	drawing_setting.add_signature_name = &mpr_variable.data_signature_name;
	RENDERING::API::RENDER_INTERFACE::C_Rendering_API_Interface_Constant_Resource::M_Set_Constant_Resource_To_Draw(drawing_setting);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F �萔�o�b�t�@���w�肳�ꂽ�C���f�b�N�X�ɃZ�b�g���AGPU�ɓn��
// ����   �Fint �ݒ肷��C���f�b�N�X�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Constant_Buffer_Data_System::M_Set_Constant_Buffer_To_GPU_By_Index(int in_slot_num)
{
	RENDERING::API::RENDER_INTERFACE::C_Rendering_API_Interface_Constant_Resource::M_Set_Constant_Resource_To_Draw_By_Slot_Index(mpr_variable.constant_buffer_inform, in_slot_num);

	return;
}

