//����������������������������������������������//
// �ڍ�   �F�����_�����OAPI�̃t�H���g�f�[�^�p�V�X�e���̃C���^�[�t�F�[�X
// ����   �F�t�H���g�ɑ΂��铮��݂̂��܂Ƃ߂Ē񋟂���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Rendering_API_Interface_Font.h"
#include "C_Rendering_API_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::API::RENDER_INTERFACE;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�t�H���g���w�肳�ꂽ�t�H���g�������Ƀ��[�h����
// ����   �Funique_ptr<C_Rendering_Font_Inform_Base> & �ݒ��̃t�H���g�V�X�e���̎Q��, const S_Create_Font_Data_Inform & �t�H���g�𐶐����邽�߂̏��̎Q�Ɓiconst�j
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Rendering_API_Interface_Font::M_Load_Font(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Font_Inform_Base> & out_result_font_system, const RENDERING::API::CREATE::S_Create_Font_Data_Inform & in_font_create_inform)
{
    return RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Create_Font_Data(out_result_font_system, in_font_create_inform);
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�n���ꂽ�������ɕ�������}�b�v�ɃZ�b�g����
// ����   �FS_Make_Font_To_Graph_Package & �t�H���g�f�[�^���e�N�X�`���}�b�v�Ɉڂ����߂̏��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Font::M_Set_Font_Map(PAKAGE::FONT::S_Make_Font_To_Graph_Package & in_make_font_graph_package)
{
    RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance()->M_Set_Font_To_Texture_Map(in_make_font_graph_package);

    return;
}
