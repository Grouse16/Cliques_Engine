//����������������������������������������������//
// �ڍ�   �F�^�C�g���V�[���̃N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_SCENE_TITLE_H_FILE
#define D_INCLUDE_GUARD_C_SCENE_TITLE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_Scene_Base.h"


// �� �l�[���X�y�[�X �� //

// �Q�[���V�[���̃V�X�e�����Ăяo�����߂̖��O
namespace GAME::SCENE
{
	// �� �N���X �� //

	// �^�C�g���V�[���̃N���X
	class C_Scene_Title : public GAME::SCENE::BASE::C_Scene_Base
	{
		//==�� �v���C�x�[�g ��==//
	private:


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^
		C_Scene_Title(void);

		// �f�X�g���N�^
		~C_Scene_Title(void) override;

		// �������̉�����s��
		void M_Release(void) override;


		//-��- ���[�h -��-//

		// �^�C�g���V�[���̃��[�h
		void M_Scene_Load(void) override;


		//-��- �X�V -��-//

		// �Q�[���X�V�O�̃^�C�g���V�[���̍X�V���s��
		void M_Scene_Before_Update(void) override;

		// �Q�[���X�V��E�`��O�̃^�C�g���V�[���̍X�V���s��
		void M_Scene_After_Update(void) override;

		// �Q�[���`��O�̃^�C�g���V�[���̍X�V���s��
		void M_Scene_Update_After_Draw(void) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_SCENE_TITLE_H_FILE
