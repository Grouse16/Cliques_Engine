//����������������������������������������������//
// �ڍ�   �F�G���W���p�̃����_�����O�ݒ���Ǘ�����}�l�[�W���[
// ����   �F�G���W���Ɏg�p���郌���_�����O�p�C�v���C���ݒ�̏������Ǝg�p�𐧌䂷��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_ENGINE_RENDERING_SETTING_MANAGER
#define D_INCLUDE_GUARD_C_ENGINE_RENDERING_SETTING_MANAGER


// �� �t�@�C���Ђ炫 �� //
#include "C_Rendering_Setting_System_For_Engine.h"


// �� �l�[���X�y�[�X �� //

// �G���W���p�̕`��p�V�X�e�����Ăяo�����߂̖��O
namespace GAME::DRAW
{
	// �� �� �� //

	// �g�p���郌���_�����O�ݒ�̔ԍ����w�肷��
	enum class E_RENDERING_SETTING_NUM
	{
		e_UI,		// UI�p�̃����_�����O�ݒ�
		e_OBJECT,	// �I�u�W�F�N�g�p�̃����_�����O�ݒ�

		e_SUM,	// �����_�����O�ݒ萔
	};


	// �� �N���X �� //

	// �G���W���p�̃����_�����O�ݒ���Ǘ�����}�l�[�W���[�̃N���X
	class C_Engine_Rendering_Setting_Manager
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //
		
		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			RENDERING::CAPSULE::C_Rendering_Setting_System_For_Engine rendering_setting_system_list[(int)E_RENDERING_SETTING_NUM::e_SUM];	// �����_�����O�ݒ�V�X�e���̃��X�g
		};

		static SPr_Variable mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O

		static C_Engine_Rendering_Setting_Manager m_this;	// ���̃N���X���C���X�^���X�����邽�߂̕ϐ�


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^�A�V���O���g�����̂��߂ɉB��
		C_Engine_Rendering_Setting_Manager(void);


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// ���������s���@�߂�l�F�������̏ꍇ�́Atrue
		static bool M_Init(void);

		// �f�X�g���N�^
		~C_Engine_Rendering_Setting_Manager(void);

		// �������̉��
		static void M_Release(void);


		//-��- �`�� -��-//

		// �w�肳�ꂽ�����_�����O�ݒ��`��ɓK�p����@�����F�����_�����O�ݒ�̔ԍ�
		static void M_Attach_This_Rendering_Setting(E_RENDERING_SETTING_NUM);
	};
}


#endif // !D_INCLUDE_GUARD_C_ENGINE_RENDERING_SETTING_MANAGER

