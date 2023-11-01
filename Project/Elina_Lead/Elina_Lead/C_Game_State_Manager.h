//����������������������������������������������//
// �ڍ�   �F�G���W���̏�Ԃ����L���邽�߂̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_Engine_State_Manager_H_FILE
#define D_INCLUDE_GUARD_C_Engine_State_Manager_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>
#include <string>


// �� �l�[���X�y�[�X �� //

// �G���W���̏�Ԃ����L����
namespace GAME::STATE
{
	// �� �萔 �� //

	const std::wstring con_Invalid_Scene_Name = L"Invald";// �V�[�����ݒ肳��Ă��Ȃ����Ƃ�����������


	// �� �N���X �� //

	// �G���W���̏�Ԃ����L���邽�߂̃N���X
	class C_Game_State_Manager
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �ϐ����܂Ƃ߂��\����
		struct S_Varible
		{
			std::wstring now_engine_scene_name = con_Invalid_Scene_Name;			// ���݂̃G���W���̃V�[����
			std::wstring excute_change_engine_scene_name = con_Invalid_Scene_Name;	// �V�[���ύX�v���̕ύX��V�[����
			

		};	// �ϐ����Ăяo�����߂̖��O


		// �� �ϐ��錾 �� //
		static std::unique_ptr<C_Game_State_Manager> m_this;	// ���g�̃C���X�^���X��

		S_Varible mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^
		C_Game_State_Manager(void);


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �V�X�e���𐶐�����
		static void M_Init(void);

		// �f�X�g���N�^
		~C_Game_State_Manager(void);

		// ���������
		static void M_Release(void);


		//-��- �Z�b�^ -��-//

		// ���݂̃V�[�������Z�b�g����@�����F�ݒ肷�錻�݂̃V�[����
		static void M_Set_Now_Engine_Scene_Name(std::wstring);

		// �V�[���ύX�v���̕ύX��V�[�������Z�b�g����@�����F�Z�b�g����V�[���ύX�v���̕ύX��V�[����
		static void M_Set_Execute_Change_Engine_Scene_Name(std::wstring);


		//-��- �Q�b�^ -��-//

		// ���݂̃V�[�����̎Q�Ƃ��擾����@�߂�l�F���݂̃V�[�����̎Q��(const)
		static const std::wstring & M_Get_Now_Engine_Scene_Name(void);

		// �V�[���ύX�v���̕ύX��V�[�����̎Q�Ƃ��擾����@�߂�l�F�V�[���ύX�v���̕ύX��V�[�����̎Q��(const)
		static const std::wstring & M_Get_Execute_Change_Engine_Scene_Name(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_Engine_State_Manager_H_FILE



