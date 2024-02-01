//����������������������������������������������//
// �ڍ�   �F�O���t�B�b�N�XAPI�����������邽�߂̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_OS_Manager_And_Rendering_API_Initialize_And_Release_System.h"
#include "Platform_Detector_Macro.h"
#include "C_Platform_Detection_System.h"


// �� �E�B���h�E�YOS�̎��̂�DirextX��L���� �� //
#ifdef D_OS_IS_WINDOWS
#include "C_Windows_OS_Management_System.h"
#include "C_DX12_System.h"
#endif // D_OS_IS_WINDOWS


// �� �}�N�� �� //
#if _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace PLATFORM;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��- ������ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::C_OS_Manager_And_Rendering_API_Initialize_And_Release_System(void)
{
	return;
}


//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FOS����V�X�e���̏��������s��
// ����   �Fvoid
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Init_OS(void)
{
	return OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Set_Up();
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����OAPI�̏��������s��
// ����   �Fvoid
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Init_Rendering_API(void)
{
	// �� ����������API�ɂ���ĕ��� �� //
	switch (PLATFORM::DETECTION::C_Platform_Detection_System::M_Get_Rendering_API_Number())
	{
		// �� �E�B���h�E�YOS�̎��̂�DirectX��L���� �� //
#ifdef D_OS_IS_WINDOWS

	//  DX11  //
	case PLATFORM::E_RENDERING_API_KIND::e_DX11:

		break;

		//  DX12  //
	case PLATFORM::E_RENDERING_API_KIND::e_DX12:

		// DX12�̏�����
		RENDERING::GRAPHICS::DX12::C_DX12_System::M_Create_DirectX12();
		return RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Set_Up();

		break;

#endif // D_OS_IS_WINDOWS

		//  OpenGL  //
	case PLATFORM::E_RENDERING_API_KIND::e_OPENGL:


		// �����_�����OAPI��OpenGL�ł��邱�Ƃ�����
		PLATFORM::DETECTION::C_Platform_Detection_System::M_Set_Rendering_API_Number(PLATFORM::E_RENDERING_API_KIND::e_OPENGL);

		break;


		//  Vulkan  //
	case PLATFORM::E_RENDERING_API_KIND::e_VULKAN:


		break;

		//  �Ȃɂ������ł��Ȃ������̂ŃG���[���o���ďI��  //
	default:
		return false;
		break;
	}

	// �������ɐ���
	return true;
}


//==�� �p�u���b�N ��==//

//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�E�B���h�E�YOS����V�X�e���̂Ƃ��̂ݕK�v�ȃR�}���h�ԍ����w�肷��A���ꂪ�Ȃ��ƃE�B���h�E�𐶐��ł��Ȃ�
// ����   �Fint �R�}���h�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Set_CMD_Number(int in_set_cmd)
{
	// �E�B���h�E�Y���̓R�}���h�ԍ����Z�b�g
#ifdef D_OS_IS_WINDOWS

	// DirectX�g�p���݂̂ł悢
	if (PLATFORM::DETECTION::C_Platform_Detection_System::M_Get_Rendering_API_Number() == PLATFORM::E_RENDERING_API_KIND::e_DX11 ||
		PLATFORM::DETECTION::C_Platform_Detection_System::M_Get_Rendering_API_Number() == PLATFORM::E_RENDERING_API_KIND::e_DX12)
	{
		OS::WINDOWS::C_Windows_OS_Management_System::M_Set_Cmd_Show(in_set_cmd);
	}

#endif

	return;
}


//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FOS����V�X�e���̐������s��
// ����   �FE_RENDERING_API_KIND �g�p����API�̎�ނւ̎Q��
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Create_OS(E_RENDERING_API_KIND in_use_api_kind)
{
	// �� �E�B���h�E�Y��Ή�����OpenGL�ɐ؂�ւ��� �� //
	if ((in_use_api_kind == E_RENDERING_API_KIND::e_DX12 || in_use_api_kind == E_RENDERING_API_KIND::e_DX11) && PLATFORM::DETECTION::C_Platform_Detection_System::M_Get_Platform_Number() != PLATFORM::E_OS_KIND::e_WINDOWS)
	{
		in_use_api_kind = E_RENDERING_API_KIND::e_OPENGL;
	}


	// �� ����������API�ɂ���ĕ��� �� //
	switch (in_use_api_kind)
	{
		// �� �E�B���h�E�YOS�̎��̂�DirextX��L���� �� //
#ifdef D_OS_IS_WINDOWS

	//  DX11  //
	case E_RENDERING_API_KIND::e_DX11:

		// �E�B���h�E�Y�̐���
		OS::WINDOWS::C_Windows_OS_Management_System::M_Create_Windows_System();


		// �����_�����OAPI��DX11�ł��邱�Ƃ�����
		PLATFORM::DETECTION::C_Platform_Detection_System::M_Set_Rendering_API_Number(PLATFORM::E_RENDERING_API_KIND::e_DX11);

		break;

		//  DX12  //
	case E_RENDERING_API_KIND::e_DX12:

		// �E�B���h�E�Y�̐���
		OS::WINDOWS::C_Windows_OS_Management_System::M_Create_Windows_System();


		// �����_�����OAPI��DX12�ł��邱�Ƃ�����
		PLATFORM::DETECTION::C_Platform_Detection_System::M_Set_Rendering_API_Number(PLATFORM::E_RENDERING_API_KIND::e_DX12);

		break;

#endif // D_OS_IS_WINDOWS

		//  OpenGL  //
	case E_RENDERING_API_KIND::e_OPENGL:


		// �����_�����OAPI��OpenGL�ł��邱�Ƃ�����
		PLATFORM::DETECTION::C_Platform_Detection_System::M_Set_Rendering_API_Number(PLATFORM::E_RENDERING_API_KIND::e_OPENGL);

		break;


		//  Vulkan  //
	case E_RENDERING_API_KIND::e_VULKAN:


		break;

		//  �Ȃɂ������ł��Ȃ������̂ŃG���[���o���ďI��  //
	default:
		return false;
		break;
	}

	// �������ɐ���
	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FOS����V�X�e���ƃ����_�����OAPI�𐶐�����
// ����   �Fvoid
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Init_OS_Management_System_And_Create_Rendering_API(void)
{
	// OS����V�X�e���̏������@���s�ŃG���[���o���Ĕ�����
	if (M_Init_OS() == false)
	{
		return false;
	}


	// �����_�����OAPI�̏��������s���@���s�ŃG���[���o���Ĕ�����
	if (M_Init_Rendering_API() == false)
	{
		return false;
	}

	return true;
}


//-��- �I���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FOS����V�X�e���ƃ����_�����OAPI���������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Release_OS_Management_System_And_Rendering_API(void)
{
	if (RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance() != nullptr)
	{
		RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Release();
		RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Delete_API();
	}

	if (OS::BASE::C_OS_Management_System_Base::M_Get_Instance() != nullptr)
	{
		OS::BASE::C_OS_Management_System_Base::M_Get_Instance()->M_Release();
		OS::BASE::C_OS_Management_System_Base::M_Delete_OS_System();
	}

	return;
}
