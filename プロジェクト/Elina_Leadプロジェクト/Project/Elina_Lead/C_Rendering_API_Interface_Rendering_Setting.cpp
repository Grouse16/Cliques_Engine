//����������������������������������������������//
// �ڍ�   �F�����_�����OAPI�̃����_�����O�ݒ�̃C���^�[�t�F�[�X
// ����   �F�����_�����O�ݒ�ɑ΂��铮��݂̂��܂Ƃ߂Ē񋟂���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Rendering_API_Interface_Rendering_Setting.h"
#include "C_Rendering_API_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::API::RENDER_INTERFACE;


// �� �֐� �� //

//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����O�ݒ�̐���
// ����   �Funique_ptr<C_Rendering_Graphics_Setting_Inform_Base> & �ݒ��̃����_�����O�ݒ�̎Q��, const S_Create_Rendering_Graphics_Setting_Inform & �����p�̏��̎Q�Ɓiconst�j
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Rendering_API_Interface_Rendering_Setting::M_Create_Rendering_Setting(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Graphics_Setting_Inform_Base> & out_result_rendering_setting, const RENDERING::API::CREATE::S_Create_Rendering_Graphics_Setting_Inform & in_create_inform)
{
	return RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Create_Rendering_Graphics_Inform(out_result_rendering_setting, in_create_inform);
}


//-��- �`�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����O�ݒ��`��p�ɃZ�b�g����
// ����   �Funique_ptr<C_Rendering_Graphics_Setting_Inform_Base> & �Z�b�g���郌���_�����O�ݒ�̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Rendering_Setting::M_Set_Rendering_Setting_To_Draw(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Graphics_Setting_Inform_Base> & in_set_rendering_setting)
{
	return RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Rendering_Set_Rendering_Setting(in_set_rendering_setting);
}

