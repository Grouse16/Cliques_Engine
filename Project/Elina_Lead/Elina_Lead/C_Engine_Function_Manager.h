//����������������������������������������������//
// �ڍ�   �F�G���W���̋@�\�𐧌䂷��N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_ENGINE_FUNCTION_MANAGER
#define D_INCLUDE_GUARD_C_ENGINE_FUNCTION_MANAGER


// �� �t�@�C���Ђ炫 �� //
#include <string>
#include <vector>

#include "C_Engine_Function_Base.h"


// �� �l�[���X�y�[�X �� //

// �G���W���̋@�\�𐧌䂷��V�X�e�����Ăяo�����߂̖��O
namespace GAME::FUNCTION
{
	// �� �N���X �� //

	// �G���W���̋@�\�𐧌䂷��N���X
	class C_Engine_Function_Manager
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPR_Variable
		{
			std::vector<GAME::FUNCTION::C_Engine_Function_Base * > function_list;	// �@�\���Ǘ�����z��

			std::vector<GAME::FUNCTION::C_Engine_Function_Base * > before_func_update_list;	// �V�[�������O�ɍX�V����@�\�̃��X�g
			std::vector<GAME::FUNCTION::C_Engine_Function_Base * > after_func_update_list;	// �V�[��������ɍX�V����@�\�̃��X�g
			std::vector<GAME::FUNCTION::C_Engine_Function_Base * > before_func_draw_list;		// �`�悷��@�\�̃��X�g
			std::vector<GAME::FUNCTION::C_Engine_Function_Base * > after_func_draw_list;			// �`�悷��@�\�̃��X�g

			std::vector<std::string> function_create_kind_list;	// �@�\�̐����v�����܂Ƃ߂����X�g

			bool flg_reset_list = false;	// ���X�g�����Z�b�g���邩�ǂ����̃t���O�A�ꕔ�̋@�\�̗D��x���ύX���ꂽ�Ƃ��ɂ�����x�ݒ肵�Ȃ����^�C�~���O���w�肷�邽�߂ɐݒ肷��

		} static mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O

		static C_Engine_Function_Manager m_this;	// �G���W������p�̃V�X�e���̎���(�V���O���g��)


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^�A�V���O���g�����Ɏg�p
		C_Engine_Function_Manager(void);


		//-��- ���� -��-//

		// �w�肳�ꂽ�@�\�̌^�̐��������s����
		template <class TYPE_CREATE_FUNCTION>
		static C_Engine_Function_Base * M_Creat_Function_Excute(void)
		{
			// �� �ϐ��錾 �� //
			C_Engine_Function_Base * new_function_address = nullptr;	// �V����


			// �������ă��X�g�ɉ�����
			new_function_address = new TYPE_CREATE_FUNCTION;
			mpr_variable.function_list.reserve(mpr_variable.function_list.size() + 1);
			mpr_variable.function_list.emplace_back(new_function_address);

			return new_function_address;
		}


		//-��- �@�\ -��-//

		// �@�\�̐������s���@�����F��������@�\�̖��O
		static void M_Create_Function_By_Kind(std::string);

		// �V�[�������O�ɍX�V����@�\��ǉ�
		static void M_Set_Before_Update_Func_To_List(GAME::FUNCTION::C_Engine_Function_Base *);

		// �V�[��������ɍX�V����@�\��ǉ�
		static void M_Set_After_Update_Func_To_List(GAME::FUNCTION::C_Engine_Function_Base *);

		// �V�[���O�̕`�悷��@�\��ǉ�����
		static void M_Set_Before_Draw_Func_To_List(GAME::FUNCTION::C_Engine_Function_Base *);

		// �V�[����̕`�悷��@�\��ǉ�����
		static void M_Set_After_Draw_Func_To_List(GAME::FUNCTION::C_Engine_Function_Base *);

		// �w�肳�ꂽ�A�h���X�̋@�\�����ׂĂ̓o�^����폜����@�����F�폜����@�\�̃A�h���X
		static void M_Erase_This_Function_On_All_List(GAME::FUNCTION::C_Engine_Function_Base *);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �I���� -��-//

		// �f�X�g���N�^
		~C_Engine_Function_Manager(void);

		// ���������
		static void M_Release_Memory(void);


		//-��- �X�V -��-//

		// �V�[�������O�̋@�\�̍X�V���s��
		static void M_Before_Scene_Update(void);

		// �V�[��������̋@�\�̍X�V���s��
		static void M_After_Scene_Update(void);

		// �V�[�������O�̋@�\�̕`����s��
		static void M_Before_Scene_Draw(void);

		// �V�[��������̋@�\�̕`����s��
		static void M_After_Scene_Draw(void);


		//-��- �@�\ -��-//

		// �폜�̃t���O���������@�\������
		static void M_Delete_Function(void);

		// ��������v���̂������@�\��S�Đ�������
		static bool M_Execute_Create_Function_By_List(void);

		// �@�\�̐�����v������A�����Fstring ��������@�\�̖��O
		static void M_Command_Create_Function(std::string);
	};
}


#endif // !D_INCLUDE_GUARD_C_ENGINE_FUNCTION_MANAGER


//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��

