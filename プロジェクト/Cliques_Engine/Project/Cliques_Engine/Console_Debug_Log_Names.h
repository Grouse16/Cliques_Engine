//����������������������������������������������//
// �ڍ�   �F�R���\�[�����O�p�̃e���v���[�g�ƂȂ镶����p�̃t�@�C��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_CONSOLE_DEBUG_LOG_NAMES_H_FILE
#define D_INCLUDE_GUARD_CONSOLE_DEBUG_LOG_NAMES_H_FILE


// �� �l�[���X�y�[�X �� //

// �R���\�[�����O�p�̃V�X�e�����Ăяo�����߂̖��O
namespace DEBUGGER::LOG::CONSOLE
{
	// �� �萔 �� //

	// ���O�Ɏg�p���镶������܂Ƃ߂��\����
	namespace ALL_LOG_NAME
	{
		// ���C���V�X�e���p�̃��O������
		namespace MAIN_SYSTEM
		{
			constexpr char con_CONSOLE_CREATED[] = "Console_Created";		// �R���\�[���̐����������̃��O�^�C�g��
			constexpr char con_SET_UP_SUCCEEDED[] = "WIN_DX12_SET_UP_SUCCEEDED";	// �E�B���h�E�Y��DX12�̃V�X�e���̃Z�b�g�A�b�v�������̃��O�^�C�g��
			constexpr char con_ALL_SET_UP_SUCCEEDED[] = "ALL_SET_UP_CLEAR";	// �S�ẴZ�b�g�A�b�v�ɐ��������Ƃ��̃��O
			constexpr char con_END[] = "APK_END";	// �A�v���P�[�V�����I�����̃��O�^�C�g��
		};

		// �Q�[���p�̃��O������
		namespace GAME_SYSTEM
		{
			constexpr char con_GAME_INIT[] = "GAME_INIT";					// �����グ���O
			constexpr char con_GAME_INIT_ERROR[] = "GAME_INIT_ERROR";		// �����グ���s���̃��O
			constexpr char con_GAME_SHADER_ERROR[] = "SHADER_ERROR";		// �V�F�[�_�[�̐������s��
			constexpr char con_GAME_CREATE_FUNCTION[] = "CREATE_FUNCTION";	// �@�\�̐���
		};

		// �Q�[���̕`��V�X�e���p�̃��O������
		namespace GAME_RENDERING
		{
			constexpr char con_INIT[] = "GAME_RENDERING_INIT";		// �����グ���O
			constexpr char con_RENDERING_ERROR[] = "GAME_RENDERING";		// �����_�����O�n���̏����ł̃G���[
			constexpr char con_ERROR[] = "GAME_RENDERING_ERROR";	// �G���[���O
		};

		// �A�v���P�[�V�����̃G���[���O
		namespace APK_LOG
		{
			constexpr char con_MANAGERS_ERROR[] = "MANAGER-ERRORS";	// �E�B���h�E�Y�̃Z�b�g�A�b�v�������̃��O�^�C�g��
		};

		// �E�B���h�E�Y�p�̃��O������
		namespace WINDOWS
		{
			constexpr char con_SET_UP_SUCCEEDED[] = "Windows_Set_Up_Succeeded";	// �E�B���h�E�Y�̃Z�b�g�A�b�v�������̃��O�^�C�g��
		};

		// DX12�p�̃��O������
		namespace DX12
		{
			constexpr char con_SET_UP_SUCCEEDED[] = "DX12_Set_Up_Succeeded";	// �E�B���h�E�Y�̃Z�b�g�A�b�v�������̃��O�^�C�g��
			constexpr char con_SET_UP_FAILED[] = "DX12_Set_Up_Failed";		// �E�B���h�E�Y�̃Z�b�g�A�b�v���s���̃��O�^�C�g��

			constexpr char con_DEVICE_DELETED[] = "DX12_Device_Deleted";	// �f�o�C�X���폜���ꂽ���̃��O�^�C�g��

			constexpr char con_ERROR_CHECKING[] = "DX12_ERROR_CHECKING";	// �G���[���o���̃��O�^�C�g��
		};
	};
}


#endif //!D_INCLUDE_GUARD_CONSOLE_DEBUG_LOG_NAMES_H_FILE

