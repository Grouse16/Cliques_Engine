//����������������������������������������������//
// �ڍ�   �F�A�v���P�[�V��������p�̃N���X
// ����   �F�Q�[����ʂ̃f�o�b�O���Ɏ��s�����V�[����ʂ𐧌䂷�邽�߂̃V�X�e��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_APK_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_APK_MANAGER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>
#include <string>


// �� �l�[���X�y�[�X �� //

// �A�v���P�[�V�����p�̃V�X�e�����Ăяo�����߂̖��O
namespace GAME::APPLICATION
{
	// �� �萔 �� //
	const std::string con_INITIALIZED_SCENE_NAME = "TITLE";	// �����̃V�[����


	// �� �N���X �� //

	// �A�v���P�[�V��������p�̃N���X�A�i�Q�[���^�u�̎��s���j
	class C_APK_Manager
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			bool flg_apk_active = false;	// �A�v���P�[�V�����i�V�[���̍X�V��`��j���A�N�e�B�u���ǂ��� true�ŃA�N�e�B�u
		};

		SPr_Variable mpr_variable;	// �ϐ����Ăяo�����߂̖��O

		static std::unique_ptr<C_APK_Manager> m_this;	// �A�v���P�[�V��������p�̃V�X�e���̎���(�V���O���g��)


		//-��- ������ -��-//

		// �R���X�g���N�^�@�V���O���g�����̂��߂ɉB��
		C_APK_Manager(void);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �I���� -��-//

		// ���������Ďg�p�\�ɂ���@�߂�l�F�������̂�true
		static bool M_Init(void);

		// �f�X�g���N�^
		~C_APK_Manager(void);

		// ���������
		static void M_Release(void);


		//-��- ���� -��-//

		// �A�v���P�[�V�����̓���
		static void M_APK_Input(void);


		//-��- �X�V -��-//

		// �A�v���P�[�V�����̍X�V
		static void M_APK_Update(void);
		

		//-��- �`�� -��-//

		// �A�v���P�[�V�����̕`��
		static void M_APK_Draw(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_APK_MANAGER_H_FILE


//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��
