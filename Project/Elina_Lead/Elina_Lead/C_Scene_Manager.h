//����������������������������������������������//
// �ڍ�   �F�V�[���𐧌䂷�邽�߂̃N���X
// ����   �F�V�[���̃��[�h�Ɖ���ȂǁA�Ǘ����s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h -��-//
#ifndef D_INCLUDE_GUARD_C_SCENE_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_SCENE_MANAGER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <memory>
#include <string>

#include "C_Scene_Base.h"


// �� �l�[���X�y�[�X �� //

// �V�[���𐧌䂷��V�X�e�����Ăяo�����߂̖��O
namespace GAME::SCENE::MANAGER
{
	// �� �N���X �� //

	// �V�[���𐧌䂷�邽�߂̃N���X
	class C_Scene_Manager
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::unique_ptr<GAME::SCENE::BASE::C_Scene_Base> game_scene = nullptr;	// �V�[���V�X�e��

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O

		static C_Scene_Manager m_this;	// ����V�X�e���̎��́i�V���O���g�����j


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^
		C_Scene_Manager(void);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �I���� -��-//

		// �f�X�g���N�^
		~C_Scene_Manager(void);

		// �������̉�����s��
		static void M_Release(void);


		//-��- ���[�h -��-//

		// ���O����V�[�������[�h����@�����F���[�h����V�[����
		static bool M_Scene_Load(std::string);

		// ���݂̃V�[���̃A�h���X��Ԃ��@�߂�l�F���݂̃V�[���̃A�h���X
		static GAME::SCENE::BASE::C_Scene_Base * M_Get_Scene(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_SCENE_MANAGER_H_FILE

