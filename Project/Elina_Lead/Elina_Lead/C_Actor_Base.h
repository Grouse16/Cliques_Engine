//����������������������������������������������//
// �ڍ�   �F�A�N�^�[�̊��ƂȂ�N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_ACTOR_BASE_H_FILE
#define D_INCLUDE_GUARD_C_ACTOR_BASE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>
#include <memory>

#include "C_Game_Instance_Base.h"
#include "C_Component_Base.h"


// �� �l�[���X�y�[�X �� //

// �Q�[���̃A�N�^�[�̊��N���X���Ăяo�����߂̖��O
namespace GAME::INSTANCE::ACTOR::BASE
{
	// �� �R���Z�v�g�N���X �� //

	// �R���|�[�l���g�̔h���N���X�݂̂�o�^�ł���悤�ɂ���i�e���v���[�g�����𐧌�����j (C++20�Ȃ̂Œ���)
	template<typename C_Check_Instance>
	concept C_Checked_Component_Class = std::is_base_of<GAME::COMPONENT::BASE::C_Component_Base, C_Check_Instance>::value;


	// �� �N���X �� //

	// �A�N�^�[�̊��ƂȂ�N���X
	class C_Actor_Base : public GAME::INSTANCE::BASE::C_Game_Instance_Base
	{
		//==�� �v���C�x�[�g ��==// 
	private:

		// �� �\���� �� //

		// �R���|�[�l���g����p�̏��̍\����
		struct S_Component_Inform
		{
			std::unique_ptr<GAME::COMPONENT::BASE::C_Component_Base> component;	// �R���|�[�l���g

			std::string name = "default";	// �R���|�[�l���g��
		};


		// �� �ϐ��錾 �� //
		std::vector<S_Component_Inform> m_component_list;	// �R���|�[�l���g�̃��X�g

		bool m_draw_flg = true;			// �`�悷�邩�ǂ����̃t���O
		bool m_after_draw_flg = false;	// �ʏ�`���ɕ`�悷�邩�ǂ����̃t���O


		// �� �֐� �� //

		//-��- �R���|�[�l���g -��-//

		// �w�肳�ꂽ�R���|�[�l���g�𐶐����A���̃A�h���X��Ԃ��@�����Fstring ��������R���|�[�l���g���@�߂�l�FC_UI_Component_Base * ���������R���|�[�l���g�̃A�h���X
		template <C_Checked_Component_Class C_Component_Class>
		C_Component_Class * M_Create_Component_And_Set_Name(std::string);

		// �w�肳�ꂽ���O�̃R���|�[�l���g���폜����@�����Fstring �폜����R���|�[�l���g��
		void M_Delete_Component_By_Name(std::string);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Actor_Base(void);

		// �f�X�g���N�^
		virtual ~C_Actor_Base(void);


		//-��- �D��x -��-//

		// �A�N�^�[�̗D��x��Ԃ��@�߂�l�F�A�N�^�[�̗D��x
		virtual int M_Get_Priority(void) = 0;


		//-��- �X�V -��-//

		// �R���|�[�l���g�̍X�V���s��
		void M_Component_Update(void);

		// �A�N�^�[�̍X�V���s��
		virtual void M_Actor_Update(void) = 0;

		// �폜�̃t���O�������Ă���R���|�[�l���g���폜����
		void M_Delete_Component_Update(void);


		//-��- �`�� -��-//

		// �A�N�^�[�`�悷��
		virtual void M_Actor_Draw(void) = 0;

		// �ʏ�`���ɃA�N�^�[��`�悷��
		virtual void M_Actor_After_Draw(void) = 0;


		//-��- �Z�b�^ -��-//

		// �A�N�^�[��ʏ�`��ŕ`�悷�邩�ǂ����̃t���O���Z�b�g����@�����Ftrue�̎��͕`�悷��Afalse�̎��͕`�悵�Ȃ�
		void M_Set_Draw_Flg(bool);

		// �ʏ�`���ɃA�N�^�[��`�悷�邩�ǂ����̃t���O���Z�b�g����@�����Ftrue�̎��͕`�悷��Afalse�̎��͕`�悵�Ȃ�
		void M_Set_After_Draw_Flg(bool);

		
		//-��- �Q�b�^ -��-//

		// �A�N�^�[��`�悷�邩�ǂ����̃t���O��Ԃ��@�߂�l�Ftrue�͕`�悷��Afalse�͕`�悵�Ȃ�
		bool M_Get_Draw_Flg(void);

		// �ʏ�`���ɃA�N�^�[��`�悷�邩�ǂ����̃t���O��Ԃ��@�߂�l�Ftrue�͕`�悷��Afalse�͕`�悵�Ȃ�
		bool M_Get_After_Draw_Flg(void);
	};


	// �� �֐� �� //

	//==�� �v���C�x�[�g ��==//

	//-��- �R���|�[�l���g -��-//

	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�w�肳�ꂽ�R���|�[�l���g�𐶐����A���̃A�h���X��Ԃ�
	// ����   �Fstring ��������R���|�[�l���g��
	// �߂�l �FC_UI_Component_Base * ���������R���|�[�l���g�̃A�h���X
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	template<C_Checked_Component_Class C_Component_Class>
	inline C_Component_Class * C_Actor_Base::M_Create_Component_And_Set_Name(std::string in_set_ui_component_name)
	{
		// �� �ϐ��錾 �� //
		C_Component_Class * new_component = new C_Component_Class();	// �V�����R���|�[�l���g�̃A�h���X

		int new_component_slot = m_component_list.size();	// �V�����R���|�[�l���g�p�̃X���b�g�ԍ�


		// �V�����R���|�[�l���g�����X�g�ɒǉ�
		m_component_list.resize(new_component_slot + 1);
		m_component_list[new_component_slot].component.reset(new_component);
		m_component_list[new_component_slot].name = in_set_ui_component_name;

		// �������ꂽ�R���|�[�l���g�̃A�h���X��Ԃ�
		return new_component;
	}
}


#endif // !D_INCLUDE_GUARD_C_ACTOR_BASE_H_FILE


