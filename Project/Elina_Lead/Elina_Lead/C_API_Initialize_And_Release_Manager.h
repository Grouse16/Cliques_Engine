//����������������������������������������������//
// �ڍ�   �F�v���b�g�t�H�[���ŕ��򂷂鏉�����Ɖ���𐧌䂷��N���X
// ����   �FOS�ƕ`��p�����_�����OAPI�i�T�[�h�p�[�e�B���j��OS���Ƃɕ��򂷂�
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_GRAPHICS_API_INISIALIZER_H_FILE
#define D_INCLUDE_GUARD_C_GRAPHICS_API_INISIALIZER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>


// �� �l�[���X�y�[�X �� //

// �v���b�g�t�H�[���ŕ��򂷂鏉�����Ɖ���𐧌䂷��N���X���Ăяo�����߂̖��O
namespace PLATFORM
{
	// �� �萔 �� //

	// �����_�����O�pAPI�̎�ނ��w�肷���
	enum class E_RENDERING_API_KIND
	{
		e_DX11,		// �_�C���N�g�G�b�N�X�P�P
		e_DX12,		// �_�C���N�g�G�b�N�X�P�Q
		e_OPENGL,	// �I�[�v��GL
		e_VULKAN,	// �o���J��
	};


	// �� �N���X �� //
	
	// �v���b�g�t�H�[���ŕ��򂷂鏉�����Ɖ���𐧌䂷��N���X
	class C_API_Initialize_And_Release_Manager
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^	�����ł��Ȃ�����
		C_API_Initialize_And_Release_Manager(void);


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- ������ -��-//

		// OS�̏��������s���@����ɐ������邱�Ɓ@�߂�l�F�������̂�true
		static bool M_Init_OS(void);

		// OS�̐������s���@�����F�g�p����API�̎�ށ@�߂�l�F�������̂�true
		static bool M_Create_OS(E_RENDERING_API_KIND);

		// API�̏��������s���@�����Fvoid�@�߂�l�F�������̂�true
		static bool M_Init_API(void);

		// �E�B���h�E�YOS�̂Ƃ��̂ݕK�v�ȃR�}���h�ԍ����w�肷��A���ꂪ�Ȃ��ƃE�B���h�E�𐶐��ł��Ȃ��@�����F�R�}���h�ԍ�
		static void M_Set_CMD_Number(int);


		//-��- �I���� -��-//

		// �f�X�g���N�^
		~C_API_Initialize_And_Release_Manager(void);

		// API���������
		static void M_Relese_Graphics_API(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_GRAPHICS_API_INISIALIZER_H_FILE


//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��

