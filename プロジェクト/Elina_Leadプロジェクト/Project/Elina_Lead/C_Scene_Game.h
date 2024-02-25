//����������������������������������������������//
// �ڍ�   �F�Q�[���V�[���̃N���X
// ����   �F�Q�[���V�[�����L�̓����A�Q�[���V�[���ɕK�v�ȃI�u�W�F�N�g�̃��[�h���s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_SCENE_GAME_H_FILE
#define D_INCLUDE_GUARD_C_SCENE_GAME_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_Scene_Base.h"


// �� �l�[���X�y�[�X �� //
namespace GAME::SCENE
{
	// �� �N���X �� //

	// �Q�[���V�[���̃N���X
	class C_Scene_Game : public GAME::SCENE::BASE::C_Scene_Base
	{
		//==�� �v���C�x�[�g ��==//
	private:


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^
		C_Scene_Game(void);

		// �f�X�g���N�^
		~C_Scene_Game(void) override;

		// �������̉�����s��
		void M_Release(void) override;


		//-��- ���[�h -��-//

		// �Q�[���V�[���̃��[�h
		void M_Scene_Load(void) override;


		//-��- �X�V -��-//

		// �Q�[���X�V�O�̃Q�[���V�[���̍X�V���s��
		void M_Scene_Before_Update(void) override;

		// �Q�[���X�V��E�`��O�̃Q�[���V�[���̍X�V���s��
		void M_Scene_After_Update(void) override;

		// �Q�[���`��O�̃Q�[���V�[���̍X�V���s��
		void M_Scene_Update_After_Draw(void) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_SCENE_GAME_H_FILE
