//����������������������������������������������//
// �ڍ�   �F�����_�����OAPI�ɑ΂����{������s�����߂̃C���^�[�t�F�[�X
// ����   �F��{����݂̂��܂Ƃ߂Ē񋟂���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Rendering_API_Interface_User.h"
#include "C_Rendering_API_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::API::RENDER_INTERFACE;


// �� �֐� ���@//

//==�� �p�u���b�N ��==//

//-��- �����_�����O -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����O�̊J�n�̎��s
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_User::M_Rendering_Start(void)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Rendering_Start();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����O�̏I���ƕ`��o�b�t�@�؂�ւ��̎��s
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_User::M_Rendering_End_And_Swap_Screen(void)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Rendering_End_And_Swap_Screen();

	return;
}


//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����OAPI������ł��邩�ǂ������`�F�b�N����
// ����   �Fvoid
// �߂�l �Fbool ���펞�̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Rendering_API_Interface_User::M_Rendering_API_Safe_Check(void)
{
	// �� �ϐ��錾 �� //
	RENDERING::API::BASE::C_Rendering_API_Base* rendering_api_address = RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance();  // �����_�����OAPI�ւ̃A�h���X


	// �����_�����OAPI�̃A�h���X���폜����Ă���Ȃ�ُ��Ԃ�
	if (rendering_api_address == nullptr)
	{
		return false;
	}

	// �����_�����OAPI�V�X�e�����I�����Ă���Ȃ�ُ��Ԃ�
	if (rendering_api_address->M_Get_End_Rendering_System())
	{
		return false;
	}

	// �ُ킪������Ȃ��̂Ő���ł���
	return true;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���̃����_�����O�V�X�e���̃V�F�[�_�[�̃t�H���_�܂ł̃p�X��Ԃ�
// ����   �Fvoid
// �߂�l �Fstring �V�F�[�_�[�܂ł̃p�X
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::string C_Rendering_API_Interface_User::M_Get_Shader_Folder_Path(void)
{
	return RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Get_Shader_Folder_Path();
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̃����_�����O�V�X�e���̃V�F�[�_�[�̊g���q��Ԃ�
// ����   �Fvoid
// �߂�l �Fstring �V�F�[�_�[�̊g���q
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::string C_Rendering_API_Interface_User::M_Get_Shader_Extension(void)
{
	return RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Get_Shader_Extension();
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F��ʂ��N���A����F��ݒ肷��
// ����   �FC_Color �Z�b�g����F
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_User::M_Set_Screen_Clear_Color(DATA::COLOR::C_Color in_set_color)
{
	RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Set_Clear_Color(in_set_color);

	return;
}
