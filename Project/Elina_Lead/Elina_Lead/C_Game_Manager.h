//����������������������������������������������//
// �ڍ�   �F�Q�[���̃V�X�e������p�̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_ENGINE_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_ENGINE_MANAGER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_Game_State_Manager.h"

#include <vector>


// �� �l�[���X�y�[�X �� //

// �G���W���̐���p�̃V�X�e��
namespace GAME
{
	// �� �N���X �� //

	// �G���W������p�V�X�e��
	class C_Game_Manager
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			bool flg_engine_exsist = true;		// �G���W�������݂��Ă��邩�ǂ����̃t���O
			bool flg_engine_activate = false;	// �G���W�����ғ������ǂ����̃t���O
			bool flg_OS_active_now = false;		// OS�V�X�e�����ғ������ǂ����̃t���O

		} static mpr_variable;	// �ϐ����Ăяo�����߂̖��O

		static C_Game_Manager m_this;	// �G���W������p�̃V�X�e���̎���(�V���O���g��)


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^
		C_Game_Manager(void);

		
		//-��- �X�V -��-//

		// �f�[�^�̍X�V���s��
		static void M_Data_Update(void);

		// �E�B���h�E�^�C�g���̍X�V
		static void M_Window_Title_Update(void);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �G���W���̏�����
		static void M_Init(void);

		// �f�X�g���N�^
		~C_Game_Manager(void);

		// ���������
		static void M_Release(void);


		//-��- �Z�b�^ -��-//

		// �G���W���𑶍݂��Ă����Ԃ��ǂ�����ݒ肷��@�����Ftrue�͐���ɑ��݂��Ă���
		static void M_Set_Engine_Exist_Flg(bool);

		// �G���W�����ғ������ǂ�����ݒ肷��@�����Ftrue�͉ғ���
		static void M_Set_Engine_Activate_Flg(bool);


		//-��- �Q�b�^ -��-//

		// �G���W���𑶍݂��Ă����Ԃ��ǂ������擾����@�����Ftrue�͐���ɑ��݂��Ă���
		static bool M_Get_Engine_Exist_Flg(void);

		// �G���W�����A�N�e�B�u��Ԃ��ǂ�����Ԃ��@�߂�l�F�A�N�e�B�u���̂�ture
		static bool M_Get_Engine_Active_Flg(void);


		//-��- ���s -��-//

		// �G���W���̏��������s����
		static void M_Executes_Process(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_ENGINE_MANAGER_H_FILE


//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��
