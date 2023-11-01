//����������������������������������������������//
// �ڍ�   �F�v���b�g�t�H�[�����o�p�V�X�e��
// ����   �F�v���b�g�t�H�[���������������A�}�N���ŕ��򂳂���ׂ��ł͂Ȃ��ꏊ�̂��߂Ɏg�p����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Platform_Detection_System.h"
#include "Platform_Detector_Macro.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace PLATFORM::DETECTION;


// �� �ϐ��錾 �� //
C_Platform_Detection_System C_Platform_Detection_System::m_this_instance;	// �R���X�g���N�^�N���p�p�̃C���X�^���X


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^�AOS�̎��ʂ��s��
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Platform_Detection_System::C_Platform_Detection_System(void)
{
	// �E�B���h�E�Y�ł̎��s��
#ifdef D_OS_IS_WINDOWS
	m_platform_num = E_PLATFORM_NUMBER::e_WINDOWS;

	// �}�b�N�ł̎��s��
#elif D_OS_IS_MAC
	m_platform_num = E_PLATFORM_NUMBER::e_MAC;

	// ���i�b�N�X�ł̎��s��
#elif D_OS_IS_LINUX
	m_platform_num = E_PLATFORM_NUMBER::e_LINUX;

	// ���j�b�N�X�ł̎��s��
#elif D_OS_IS_UNIX
	m_platform_num = E_PLATFORM_NUMBER::e_UNIX;
	
	// �v���b�g�t�H�[�����ʕs��
#elif D_OS_IS_UNKNOWN
	m_platform_num = E_PLATFORM_NUMBER::e_UNKNOWN;
#endif // D_OS_IS_UNKNOWN

	return;
}


//==�� �p�u���b�N ��==//

//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�v���b�g�t�H�[�����ʗp�ԍ���n��
// ����   �Fvoid
// �߂�l �Fconst E_PLATFORM_NUMBER & �v���b�g�t�H�[�����ʗp�ԍ��̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const E_PLATFORM_NUMBER & C_Platform_Detection_System::M_Get_Platform_Number(void)
{
	return m_this_instance.m_platform_num;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̃����_�����OAPI�ԍ���n��
// ����   �Fvoid
// �߂�l �Fconst E_RENDERING_API_NUMBER & �����_�����OAPI�ԍ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const E_RENDERING_API_NUMBER & C_Platform_Detection_System::M_Get_Rendering_API_Number(void)
{
	return m_this_instance.m_rendering_api_num;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����OAPI���w�肷��ԍ���ݒ肷��
// ����   �FE_RENDERING_API_NUMBER �ݒ肷�郌���_�����OAPI�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Platform_Detection_System::M_Set_Rendering_API_Number(E_RENDERING_API_NUMBER in_rendering_api_num)
{
	m_this_instance.m_rendering_api_num = in_rendering_api_num;

	return;
}
