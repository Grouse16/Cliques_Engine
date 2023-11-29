//����������������������������������������������//
// �ڍ�   �F���C���J�����̃V�X�e��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Main_Camera.h"
#include "C_Projection_System.h"
#include "C_OS_System_Base.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace GAME::CAMERA::MAIN_CAMERA;


// �� �X�^�e�B�b�N�ϐ� �� //
C_Main_Camera C_Main_Camera::m_this;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Main_Camera::C_Main_Camera(void)
{
	return;
}


//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���C���J����������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Main_Camera::M_Reset(void)
{
	// �� �萔 �� //
	GAME::CAMERA::PROJECTION::C_Projection_System projection_init;	// �v���W�F�N�V�����̏����l


	// �r���[�̃}�g���N�X������������
	m_this.mpr_variable.view = DirectX::XMMATRIX();

	// �v���W�F�N�V�����̃}�g���N�X������������
	projection_init.aspect_ratio = OS::C_OS_System_Base::M_Get_Instance()->M_Get_Aspect_Size();
	projection_init.M_Get_Projection(m_this.mpr_variable.projection);

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Main_Camera::~C_Main_Camera(void)
{
	return;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�r���[�̃}�g���N�X�ϊ��s����Z�b�g����
// ����   �Fconst XMMATRIX & �Z�b�g����r���[�̃}�g���N�X�ϊ��s��̎Q�Ɓiconst�j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Main_Camera::M_Set_View_Matrix(const DirectX::XMMATRIX & in_set_view)
{
	m_this.mpr_variable.view = in_set_view;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�v���W�F�N�V�����̃}�g���N�X�ϊ��s����Z�b�g����
// ����   �Fconst XMMATRIX & �Z�b�g����v���W�F�N�V�����̃}�g���N�X�ϊ��s��̎Q�Ɓiconst�j
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Main_Camera::M_Set_Projection_Matrix(const DirectX::XMMATRIX & in_set_projection)
{
	m_this.mpr_variable.projection = in_set_projection;

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�r���[�̃}�g���N�X�ϊ��s��̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �Fconst XMMATRIX & �r���[�̃}�g���N�X�ϊ��s��̎Q�Ɓiconst�j
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const DirectX::XMMATRIX & C_Main_Camera::M_Get_View_Matrix(void)
{
	return m_this.mpr_variable.view;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�v���W�F�N�V�����̃}�g���N�X�ϊ��s��̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �Fconst XMMATRIX & �v���W�F�N�V�����̃}�g���N�X�ϊ��s��̎Q�Ɓiconst�j
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const DirectX::XMMATRIX & C_Main_Camera::M_Get_Projection_Matrix(void)
{
	return m_this.mpr_variable.projection;
}
