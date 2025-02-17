//����������������������������������������������//
// �ڍ�   �F�R���|�[�l���g�̊��N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_COMPONET_BASE_H_FILE
#define D_INCLUDE_GUARD_C_COMPONET_BASE_H_FILE


// �� �l�[���X�y�[�X �� //

// �R���|�[�l���g���Ăяo�����߂̖��O
namespace GAME::COMPONENT::BASE
{
	// �� �N���X �� //

	// �R���|�[�l���g�̊��N���X
	class C_Component_Base
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //
		bool m_flg_destroy_component = false;	// �R���|�[�l���g���폜����


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Component_Base(void);

		// �f�X�g���N�^
		virtual ~C_Component_Base(void);


		//-��- �X�V -��-//

		// �R���|�[�l���g�̍X�V
		virtual void M_Update(void) = 0;


		//-��- �`�� -��-//

		// �R���|�[�l���g�̕`��
		virtual void M_Draw(void) = 0;


		//-��- �Q�b�^ -��-//

		// �R���|�[�l���g���폜���邩�ǂ����̃t���O��Ԃ��@�߂�l�Ftrue�ō폜����Afalse�ō폜���Ȃ�
		bool M_Get_Component_Destroy_Flg(void);


		//-��- �폜 -��-//

		// �R���|�[�l���g���폜����t���O�𗧂Ă�
		void M_Destroy(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_COMPONET_BASE_H_FILE
