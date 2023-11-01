//����������������������������������������������//
// �ڍ�   �F�����_�����O�p�̏����~���ɐݒ肵�A�����_�����O���邽�߂̃V�X�e��
// ����   �F�����_�����O�p���̐ݒ���J�v�Z��������
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_RENDERING_SETTING_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_SETTING_SYSTEM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>

#include "C_Rendering_Graphics_Setting_Inform_Base.h"


// �� �l�[���X�y�[�X �� //

// �`��Ɏg�p����V�X�e�����Ăяo�����߂̖��O
namespace RENDERING::CAPSULE
{
	// �� �N���X �� //

	// �����_�����O�p�̏����~���ɐݒ肵�A�����_�����O���邽�߂̃V�X�e��
	class C_Rendering_Setting_System
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::unique_ptr <RENDERING::GRAPHICS::INSTANCE::C_Rendering_Graphics_Setting_Inform_Base> rendering_setting_inform = nullptr;	// �����_�����O�ݒ�p���

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Rendering_Setting_System(void);

		// �f�X�g���N�^
		~C_Rendering_Setting_System(void);

		// �������̉�����s��
		void M_Delete(void);


		//-��- ���� -��-//

		// �����p�̏������ɐ�������@�����F�g�p����V�F�[�_�[�Z�b�g�̔ԍ�
		void M_Creat_Pipeline_Setting(int);


		//-��- �`�� -��-//

		// �����_�����OAPI�ɂ��̃����_�����O�ݒ��K�p����
		void M_Set_Rendering_Setting_For_API(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_SETTING_SYSTEM_H_FILE
