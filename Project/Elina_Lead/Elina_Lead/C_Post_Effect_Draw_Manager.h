//����������������������������������������������//
// �ڍ�   �F�|�X�g�G�t�F�N�g�̕`�搧��V�X�e��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_POST_EFFECT_DRAW_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_POST_EFFECT_DRAW_MANAGER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>

#include "C_Post_Effect_Base.h"


// �� �l�[���X�y�[�X �� //

// �|�X�g�G�t�F�N�g�̕`�搧��V�X�e�����Ăяo�����߂̖��O
namespace GAME::INSTANCE::POST_EFFECT::DRAW_MANAGER
{
	// �� �N���X �� //

	// �|�X�g�G�t�F�N�g�̕`�搧�������N���X
	class C_Post_Effect_Draw_Manager
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::vector<GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base * > post_effect_before_ui_list;	// UI�̕`��O�ɕ`�悷��|�X�g�G�t�F�N�g�̃��X�g
			std::vector<GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base * > post_effect_after_ui_list;	// UI�̕`���ɕ`�悷��|�X�g�G�t�F�N�g�̃��X�g

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O

		static C_Post_Effect_Draw_Manager m_this;	// �|�X�g�G�t�F�N�g�̕`�搧��V�X�e�����V���O���g�������邽�߂̃C���X�^���X


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^
		C_Post_Effect_Draw_Manager(void);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �I���� -��-//

		// �f�X�g���N�^
		~C_Post_Effect_Draw_Manager(void);


		//-��- �Z�b�^ -��-//

		// UI�̑O�ɕ`�悷��|�X�g�G�t�F�N�g��`�惊�X�g�ɒǉ�����@�����F�ǉ�����|�X�g�G�t�F�N�g
		static void M_Set_Post_Effect_Before_UI(GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base * );

		// UI�̌�ɕ`�悷��|�X�g�G�t�F�N�g��`�惊�X�g�ɒǉ�����@�����F�ǉ�����|�X�g�G�t�F�N�g
		static void M_Set_Post_Effect_After_UI(GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base * );


		//-��- �`�� -��-//

		// UI�̑O�̃|�X�g�G�t�F�N�g��`�悷��
		static void M_Draw_Post_Effect_Before_UI(void);

		// UI�̌�̃|�X�g�G�t�F�N�g��`�悷��
		static void M_Draw_Post_Effect_After_UI(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_POST_EFFECT_DRAW_MANAGER_H_FILE

