//����������������������������������������������//
// �ڍ�   �F�ό`���Ȃ����f���̃R���|�[�l���g�̃V�X�e��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Static_Model_Component.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::COMPONENT::MODEL_COMPONENT;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Static_Model_Component::C_Static_Model_Component(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Static_Model_Component::~C_Static_Model_Component(void)
{
	return;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���O�̃��f�������[�h����
// ����   �Fstring ���[�h���郂�f����
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Static_Model_Component::M_Load_Model_By_Name(std::string in_load_model_name)
{
	return mpr_variable.model_system.M_Load_3D_Model(in_load_model_name);
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���[�J�����W�̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �FC_Transform & ���[�J�����W�̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
MATH::C_Transform & C_Static_Model_Component::M_Get_Transform(void)
{
	return mpr_variable.transform;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���f���V�X�e���̃A�h���X��Ԃ�
// ����   �Fvoid
// �߂�l �FC_3D_Model_User * ���f���V�X�e���̃A�h���X
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
ASSET::MODEL::C_3D_Model_User * C_Static_Model_Component::M_Get_Model_Address(void)
{
	return mpr_variable.model_system.get();
}
