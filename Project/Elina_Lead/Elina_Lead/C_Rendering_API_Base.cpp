//����������������������������������������������//
// �ڍ�   �F�T�[�h�p�[�e�B�̓��̃O���t�B�b�N�𐧌䂷��V�X�e���̊��N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Rendering_API_Base.h"


// �� �l�[���X�y�[�X �� //
using namespace RENDERING::API::BASE;


// �� �ϐ��錾 �� //
std::unique_ptr <C_Rendering_API_Base> C_Rendering_API_Base::m_this;	// �N���X�̃C���X�^���X�p�A�h���X�A��Ƀ|�����[�t�B�Y�����Ɏg�p


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �I���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����O�p��API���I������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Base::M_Delete_API(void)
{
	if (m_this != nullptr)
	{
		m_this.reset();
		m_this = nullptr;
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Rendering_API_Base::~C_Rendering_API_Base(void)
{
	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���̃N���X�̎��̂̃A�h���X��Ԃ�
// ����   �Fvoid
// �߂�l �FC_Rendering_API_Base * �����_�����OAPI���N���X�̃A�h���X
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Rendering_API_Base * C_Rendering_API_Base::M_Get_Instance(void)
{
	return m_this.get();
}
