//����������������������������������������������//
// �ڍ�   �F�Q�[����̃V�X�e���̊��ƂȂ�N���X
// ����   �F����̃N���X�̃C���X�^���X���܂Ƃ߂�N���X�ȂǁA�Q�[����ő��݂��邪�`�悳��Ȃ��C���X�^���X
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_SYSTEM_BASE_H_FILE
#define D_INCLUDE_GUARD_C_SYSTEM_BASE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_Game_Instance_Base.h"


// �� �l�[���X�y�[�X �� //

// �Q�[����̃C���X�^���X�̃V�X�e���̊��ƂȂ�N���X���Ăяo�����߂̖��O
namespace GAME::INSTANCE::GAME_SYSTEM::BASE
{
	// �� �N���X �� //

	// �V�X�e���̊��ƂȂ�N���X
	class C_Game_System_Base : public GAME::INSTANCE::BASE::C_Game_Instance_Base
	{
		//==�� �v���C�x�[�g ��==//
	private:


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//
		
		// �R���X�g���N�^
		C_Game_System_Base(void);

		// �f�X�g���N�^
		virtual ~C_Game_System_Base(void);

		
		//-��- �X�V -��-//

		// �X�V���s��
		virtual void M_System_Update(void) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_SYSTEM_BASE_H_FILE

