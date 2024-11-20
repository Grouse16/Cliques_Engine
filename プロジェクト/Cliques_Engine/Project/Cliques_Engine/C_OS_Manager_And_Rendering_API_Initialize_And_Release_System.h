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

#include "E_RENDERING_API_KIND.h"


// �� �l�[���X�y�[�X �� //

// �v���b�g�t�H�[���ŕ��򂷂鏉�����Ɖ���𐧌䂷��N���X���Ăяo�����߂̖��O
namespace PLATFORM
{
	// �� �N���X �� //
	
	// �v���b�g�t�H�[���ŕ��򂷂鏉�����Ɖ���𐧌䂷��N���X
	class C_OS_Manager_And_Rendering_API_Initialize_And_Release_System
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^	�����ł��Ȃ�����
		C_OS_Manager_And_Rendering_API_Initialize_And_Release_System(void);


		//-��- ���� -��-//

		// OS����V�X�e���̏��������s���@�߂�l�F�������̂�true
		static bool M_Init_OS(void);

		// �����_�����OAPI�̏��������s���@�߂�l�Fbool �������̂�true
		static bool M_Init_Rendering_API(void);


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- ���� -��-//

		// OS����V�X�e���̐������s���@�����F�g�p����API�̎�ނւ̎Q�Ɓ@�߂�l�Fbool �������̂�true
		static bool M_Create_OS(E_RENDERING_API_KIND);

		// OS����V�X�e�������������ă����_�����OAPI�𐶐�����@�����F�g�p����API�̎�ނւ̎Q�Ɓ@�߂�l�F�������̂�true
		static bool M_Init_OS_Management_System_And_Create_Rendering_API(void);


		//-��- �I���� -��-//

		// OS����V�X�e���ƃ����_�����OAPI���������
		static void M_Release_OS_Management_System_And_Rendering_API(void);


		//-��- �폜 -��-//

		// �R���\�[����ʂ��폜����
		static void M_Destruct_Console_Window(void);
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

