//����������������������������������������������//
// �ڍ�   �F�v���b�g�t�H�[�����o�p�V�X�e��
// ����   �F�v���b�g�t�H�[���������������A�}�N���ŕ��򂳂���ׂ��ł͂Ȃ��ꏊ�̂��߂Ɏg�p����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_PLATFORM_DETECTION_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_PLATFORM_DETECTION_SYSTEM_H_FILE


// �� �l�[���X�y�[�X �� //

// �v���b�g�t�H�[�����o�p�V�X�e�����Ăяo�����߂̖��O
namespace PLATFORM::DETECTION
{
	// �� �萔 �� //

	// �v���b�g�t�H�[�����w�肷���
	enum class E_PLATFORM_NUMBER
	{
		e_WINDOWS,	// �E�B���h�E�Y
		e_MAC,		// �}�b�N
		e_LINUX,	// ���i�b�N�X
		e_UNIX,		// ���j�b�N�X
		e_UNKNOWN,	// ���ʕs��
	};

	// �����_�����OAPI���w�肷���
	enum class E_RENDERING_API_NUMBER
	{
		e_DX12,		// �_�C���N�g�G�b�N�X12
		e_DX11,		// �_�C���N�g�G�b�N�X11
		e_OPENGL,	// �I�[�v��GL
		e_VULKAN,	// �o���J��
		e_UNKNOWN,	// ���ʕs��
	};


	// �� �N���X �� //

	// �v���b�g�t�H�[�����o�p�V�X�e��
	class C_Platform_Detection_System
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //
		static C_Platform_Detection_System m_this_instance;	// �R���X�g���N�^�N���p�p�̃C���X�^���X

		E_PLATFORM_NUMBER m_platform_num = E_PLATFORM_NUMBER::e_UNKNOWN;	// �v���b�g�t�H�[�����ʗp�ԍ�

		E_RENDERING_API_NUMBER m_rendering_api_num = E_RENDERING_API_NUMBER::e_UNKNOWN;	// �v���b�g�t�H�[�����ʗp�ԍ�

		
		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^
		C_Platform_Detection_System(void);


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �Q�b�^ -��-//

		// �v���b�g�t�H�[�����ʗp�ԍ���n��
		static const E_PLATFORM_NUMBER & M_Get_Platform_Number(void);

		// ���݂̃����_�����OAPI�ԍ���n��
		static const E_RENDERING_API_NUMBER & M_Get_Rendering_API_Number(void);


		//-��- �Z�b�^ -��-//

		// �����_�����OAPI���w�肷��ԍ���ݒ肷��@�����F�ݒ肷�郌���_�����OAPI�ԍ�
		static void M_Set_Rendering_API_Number(E_RENDERING_API_NUMBER);
	};
}


#endif // !D_INCLUDE_GUARD_C_PLATFORM_DETECTION_SYSTEM_H_FILE


//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��

