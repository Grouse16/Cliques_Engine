//����������������������������������������������//
// �ڍ�   �F�����_�����OAPI�̐����Ɖ���̃C���^�[�t�F�[�X
// ����   �F�����Ɖ���̓���݂̂��܂Ƃ߂Ē񋟂���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Rendering_API_Interface_Initialize_And_Release.h"
#include "C_Rendering_API_Base.h"
#include "Platform_Detector_Macro.h"


#ifdef _DEBUG
#include "C_Log_System.h"
#endif // !_DEBUG


// �� �E�B���h�E�YOS�̎��̂�DirectX��L���� �� //
#ifdef D_OS_IS_WINDOWS
#include "C_DX12_System.h"
#endif // D_OS_IS_WINDOWS



// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::API::RENDER_INTERFACE;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����OAPI�̏�����
// ����   �Fvoid
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Rendering_API_Interface_Initialize_And_Release::M_Initialize_Rendering_API(void)
{
	// �� �ϐ��錾 �� //
	RENDERING::API::BASE::C_Rendering_API_Base * rendering_api_address = RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance();  // �����_�����OAPI�ւ̃A�h���X


	// �C���X�^���X����������Ă��Ȃ��Ȃ�G���[��Ԃ�
	if (rendering_api_address == nullptr)
	{
		// �f�o�b�O���̂݃G���[���O���o��
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log
		(
			DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP,
			DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR,
			"�����_�����OAPI�̃C���X�^���X����������Ă��Ȃ���Ԃŏ����������s����܂���"
		);
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // !_DEBUG

		return false;
	}

	// �����_�����OAPI�̏�����
	return rendering_api_address->M_Set_Up();
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����OAPI��DX12�𐶐�����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Initialize_And_Release::M_Create_DX12(void)
{
	// �� �E�B���h�E�YOS�̎��̂�DirectX��L���� �� //
#ifdef D_OS_IS_WINDOWS
	RENDERING::API::DX12::C_DX12_System::M_Create_DirectX12();

#else

#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Print_Log
	(
		DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP,
		DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED,
		"Windows OS�����s�ł�����ł͂Ȃ��̂�DX12�̐��������s����܂���"
	);
	DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // !_DEBUG

#endif // D_OS_IS_WINDOWS

	return;
}


//-��- ��� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�����OAPI�̉��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Rendering_API_Interface_Initialize_And_Release::M_Release_Rendering_API(void)
{
	// �� �ϐ��錾 �� //
	RENDERING::API::BASE::C_Rendering_API_Base * rendering_api_address = RENDERING::API::BASE::C_Rendering_API_Base::M_Get_Instance();  // �����_�����OAPI�ւ̃A�h���X


	// �����_�����OAPI�����݂��Ă���Ȃ�폜
	if (rendering_api_address != nullptr)
	{
		rendering_api_address->M_Release();
		RENDERING::API::BASE::C_Rendering_API_Base::M_Delete_API();
	}

	return;
}