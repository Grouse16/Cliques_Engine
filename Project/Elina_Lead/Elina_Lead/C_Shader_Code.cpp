//����������������������������������������������//
// �ڍ�   �F�V�F�[�_�[�̃o�C�g�R�[�h�p�̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include <string>

#include "C_Shader_Code.h"
#include "C_Platform_Detection_System.h"

// �f�o�b�O���̂�
#ifdef _DEBUG

#include "C_Log_System.h"

#endif // _DEBUG


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::SHADER;


// �� �萔 �� //

// �����_�����OAPI���Ƃ̃t�@�C������ݒ�
namespace RENDER_API_FILENAME
{
	const char * C_DX12 = "_DX12.cso";	// dx12���̃t�@�C����
	const char * C_DX11 = "_DX11.cso";	// dx11���̃t�@�C����
	const char * C_OPENGL = "_GLSL.cso";	// openGL���̃t�@�C����
}


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Shader_Code::C_Shader_Code(void)
{
	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Shader_Code::~C_Shader_Code(void)
{
	M_Release();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�o�C�g�R�[�h�̃����������������������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Shader_Code::M_Release(void)
{
	// �R�[�h�̏��p�����������
	mpr_variable.binary_ptr.reset();

	// �T�C�Y��������
	mpr_variable.size = 0;

	return;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�F�[�_�[�̏�����
// ����   �Fstring �V�F�[�_�[�̐ݒ�
// �߂�l �Fbool �V�F�[�_�[������������true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Shader_Code::M_Load_Shader_File(std::string in_shader_file_name)
{
	// �� �ϐ��錾 �� //
	FILE * file_address = nullptr;	// �R���p�C���ς݃V�F�[�_�[�̃t�@�C�������

	std::string file_name = in_shader_file_name;	// �t�@�C����


	// �v���b�g�t�H�[�����ɕ��򂷂�
	switch (PLATFORM::DETECTION::C_Platform_Detection_System::M_Get_Rendering_API_Number())
	{
	//  DX12  //
	case PLATFORM::DETECTION::E_RENDERING_API_NUMBER::e_DX12:

		file_name += RENDER_API_FILENAME::C_DX12;

		break;

		//  DX11  //
	case PLATFORM::DETECTION::E_RENDERING_API_NUMBER::e_DX11:

		file_name += RENDER_API_FILENAME::C_DX11;

		break;

		//  OpenGL  Vulkan  �s����  //
	case PLATFORM::DETECTION::E_RENDERING_API_NUMBER::e_OPENGL:
	case PLATFORM::DETECTION::E_RENDERING_API_NUMBER::e_VULKAN:
	case PLATFORM::DETECTION::E_RENDERING_API_NUMBER::e_UNKNOWN:

		file_name += RENDER_API_FILENAME::C_OPENGL;

		break;
	}


	// �R���p�C���ς݃V�F�[�_�[�̃t�@�C�����J��
	fopen_s(&file_address, file_name.c_str(), "rb");


	// �t�@�C�����Ȃ�������false�Ŕ�����
	if (file_address == nullptr)
	{
		// �f�o�b�O���̂݃G���[���x��
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_SHADER_ERROR, (file_name + "�V�F�[�_�[�̓ǂݎ��Ɏ��s���܂���").c_str());
#endif // _DEBUG

		return false;
	}


	// �f�o�b�O���̂ݐ��������m
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, (file_name + "�V�F�[�_�[�̓ǂݎ��ɐ������܂���").c_str());
#endif // _DEBUG


	// �o�C�g�R�[�h�̃r�b�g���̓���
	fseek(file_address, 0, SEEK_END);
	mpr_variable.size = ftell(file_address);
	rewind(file_address);


	// �o�C�g�R�[�h�����[�h����
	mpr_variable.binary_ptr.reset(new(void * [mpr_variable.size]));
	fread(mpr_variable.binary_ptr.get(), 1, mpr_variable.size, file_address);


	// �t�@�C�������
	fclose(file_address);
	file_address = nullptr;

	return true;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���p�C���ς݃R�[�h�̎Q�Ƃ�Ԃ�
// ����   �Fvoid
// �߂�l �Fconst unique_ptr<void * > & �R���p�C���ς݃R�[�h
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const std::unique_ptr<void * > & C_Shader_Code::M_Get_Compiled_Cord(void) const
{
	return mpr_variable.binary_ptr;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R�[�h�̃o�C�g�T�C�Y��Ԃ�
// ����   �Fvoid
// �߂�l �Fint �R�[�h�̃o�C�g�T�C�Y
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
int C_Shader_Code::M_Get_Cord_Size(void) const
{
	return mpr_variable.size;
}



