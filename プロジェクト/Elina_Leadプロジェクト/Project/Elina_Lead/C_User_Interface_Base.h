//����������������������������������������������//
// �ڍ�   �FUI�̊��ƂȂ�N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_USER_INTERFACE_BASE_H_FILE
#define D_INCLUDE_GUARD_C_USER_INTERFACE_BASE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

#include "C_Game_Instance_Base.h"
#include "C_UI_Component_Base.h"


// �� �l�[���X�y�[�X �� //

// �Q�[����UI�̊��N���X���Ăяo�����߂̖��O
namespace GAME::INSTANCE::UI::BASE
{
	// �� �R���Z�v�g�N���X �� //

	// UI�R���|�[�l���g�̔h���N���X�݂̂�o�^�ł���悤�ɂ���i�e���v���[�g�����𐧌�����j (C++20�Ȃ̂Œ���)
	template<typename C_Check_Instance>
	concept C_Checked_UI_Component_Class = std::is_base_of<GAME::UI_COMPONENT::BASE::C_UI_Component_Base, C_Check_Instance>::value;


	// �� �N���X �� //

	// UI�̊��ƂȂ�N���X
	class C_User_Interface_Base : public GAME::INSTANCE::BASE::C_Game_Instance_Base
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �\���� �� //

		// �t�h�p�̃R���|�[�l���g���Ǘ����邽�߂̍\����
		struct S_UI_Component_Inform
		{
			std::unique_ptr<GAME::UI_COMPONENT::BASE::C_UI_Component_Base> ui_component;	// �t�h�̃R���|�[�l���g

			std::string name = "default";	// �t�h�R���|�[�l���g��
		};


		// �� �ϐ��錾 �� //
		std::vector<S_UI_Component_Inform> m_ui_component_list;	// UI�̃R���|�[�l���g�̃��X�g


		// �� �֐� �� //

		//-��- �R���|�[�l���g -��-//

		// �w�肳�ꂽUI�p�̃R���|�[�l���g�𐶐����A���̃A�h���X��Ԃ��@�����Fstring ��������R���|�[�l���g���@�߂�l�FC_UI_Component_Base * ���������R���|�[�l���g�̃A�h���X
		template <C_Checked_UI_Component_Class C_UI_Component_Class>
		C_UI_Component_Class * M_Create_Component_And_Set_Name(std::string);

		// �w�肳�ꂽ���O��UI�̃R���|�[�l���g���폜����@�����Fstring �폜����R���|�[�l���g��
		void M_Delete_Component_By_Name(std::string);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_User_Interface_Base(void);

		// �f�X�g���N�^
		virtual ~C_User_Interface_Base(void);


		//-��- �X�V -��-//

		// �R���|�[�l���g�̍X�V���s��
		void M_Update_Component(void);

		// UI�̍X�V���s��
		virtual void M_UI_Update(void) = 0;

		// �폜�̃t���O�������Ă���R���|�[�l���g���폜����
		void M_Delete_Component_Update(void);


		//-��- �`�� -��-//

		// UI�̕`����s��
		virtual void M_UI_Draw(void) = 0;
	};


	// �� �֐� �� //

	//==�� �v���C�x�[�g ��==//

	//-��- �R���|�[�l���g -��-//
	
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	// �ڍ�   �F�w�肳�ꂽUI�p�̃R���|�[�l���g�𐶐����A���̃A�h���X��Ԃ�
	// ����   �Fstring ��������R���|�[�l���g��
	// �߂�l �FC_UI_Component_Base * ���������R���|�[�l���g�̃A�h���X
	//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
	template<C_Checked_UI_Component_Class C_UI_Component_Class>
	inline C_UI_Component_Class * C_User_Interface_Base::M_Create_Component_And_Set_Name(std::string in_set_ui_component_name)
	{
		// �� �ϐ��錾 �� //
		C_UI_Component_Class * new_ui_component = new C_UI_Component_Class();	// �V����UI�̃R���|�[�l���g�̃A�h���X

		int new_ui_component_slot = m_ui_component_list.size();	// �V����UI�̃R���|�[�l���g�p�̃X���b�g�ԍ�


		// �V����UI�̃R���|�[�l���g�����X�g�ɒǉ�
		m_ui_component_list.resize(new_ui_component_slot + 1);
		m_ui_component_list[new_ui_component_slot].ui_component.reset(new_ui_component);
		m_ui_component_list[new_ui_component_slot].name = in_set_ui_component_name;

		// �������ꂽ�R���|�[�l���g�̃A�h���X��Ԃ�
		return new_ui_component;
	}
}


#endif // !D_INCLUDE_GUARD_C_USER_INTERFACE_BASE_H_FILE
