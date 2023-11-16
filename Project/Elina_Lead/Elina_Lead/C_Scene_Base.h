//����������������������������������������������//
// �ڍ�   �F�V�[���̊��ƂȂ�N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_SCENE_BASE_H_FILE
#define D_INCLUDE_GUARD_C_SCENE_BASE_H_FILE


// �� �l�[���X�y�[�X �� //

// �Q�[���̃V�[���̊��ƂȂ�N���X
namespace GAME::SCENE::BASE
{
	// �� �N���X �� //

	// �V�[���̊��ƂȂ�N���X
	class C_Scene_Base
	{
		//==�� �v���C�x�[�g ��==//
	private:


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^
		C_Scene_Base(void);

		// �f�X�g���N�^
		virtual ~C_Scene_Base(void) = 0;

		// �������̉�����s��
		virtual void M_Release(void) = 0;


		//-��- ���[�h -��-//

		// �V�[���̃��[�h�̎��s���s��
		virtual void M_Scene_Load(void) = 0;


		//-��- �X�V -��-//

		// �V�[���̍X�V���s��
		virtual void M_Scene_Update(void) = 0;


		//-��- �`�� -��-//

		// �V�[���̕`����s��
		virtual void M_Scene_Draw(void) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_SCENE_BASE_H_FILE

