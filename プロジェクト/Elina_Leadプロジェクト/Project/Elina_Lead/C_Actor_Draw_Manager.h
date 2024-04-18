//����������������������������������������������//
// �ڍ�   �F�A�N�^�[�̕`�搧�������N���X
// ����   �F�A�N�^�[��`�悷�邩�ǂ����̃t���O��A������J�����Ƃ̈ʒu�֌W����̃J�����O�Ȃǂ��s���ĕ`�悷��I�u�W�F�N�g���܂Ƃ߂Ď���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_ACTOR_DRAW_MANAGER
#define D_INCLUDE_GUARD_C_ACTOR_DRAW_MANAGER


// �� �t�@�C���Ђ炫 �� //
#include "C_Actor_Base.h"

#include <vector>


// �� �l�[���X�y�[�X �� //

// �A�N�^�[�̕`�搧��p�V�X�e�����Ăяo�����߂̖��O
namespace GAME::INSTANCE::ACTOR::DRAW_MANAGER
{
	// �� �N���X �� //

	// �A�N�^�[�̕`�搧�������N���X
	class C_Actor_Draw_Manager
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ� �� //
		
		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::vector<GAME::INSTANCE::ACTOR::BASE::C_Actor_Base * > draw_actor_list;			// �`�悷��A�N�^�[�̃��X�g
			std::vector<GAME::INSTANCE::ACTOR::BASE::C_Actor_Base * > after_draw_actor_list;	// �A�N�^�[�̒ʏ�`���ɕ`�悷��A�N�^�[�̃��X�g

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O

		static C_Actor_Draw_Manager m_this;	// ���䂷��V�X�e�����V���O���g�������邽�߂̃C���X�^���X

		
		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^
		C_Actor_Draw_Manager(void);


		//-��- �`�� -��-//

		// �J�����O�̏��������s����@�����F�J�����O�̔�����s���A�N�^�[�̃A�h���X�@�߂�l�F�`�悷�鎞�̂�true
		static bool M_Culling_Calculation(GAME::INSTANCE::ACTOR::BASE::C_Actor_Base * );


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �I���� -��-//

		// �f�X�g���N�^
		~C_Actor_Draw_Manager(void);


		//-��- �Z�b�^ -��-//

		// �`�惊�X�g�ɃA�N�^�[��ǉ�����@�����F�ǉ�����A�N�^�[�̃A�h���X
		static void M_Set_Actor_To_Draw_List(GAME::INSTANCE::ACTOR::BASE::C_Actor_Base * );

		// �ʏ�`���̕`�惊�X�g�ɃA�N�^�[��ǉ�����@�����F�ǉ�����A�N�^�[�̃A�h���X
		static void M_Set_Actor_To_After_Draw_List(GAME::INSTANCE::ACTOR::BASE::C_Actor_Base * );


		//-��- �`�� -��-//

		// �`�惊�X�g���̃A�N�^�[��`�悷��
		static void M_Draw_Actor_In_Draw_List(void);

		// �ʏ�`���̕`�惊�X�g���̃A�N�^�[��`�悷��
		static void M_Draw_Actor_In_After_Draw_List(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_ACTOR_DRAW_MANAGER
