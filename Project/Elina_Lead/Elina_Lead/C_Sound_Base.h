//����������������������������������������������//
// �ڍ�   �F�T�E���h�̊��ƂȂ�N���X
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_SOUND_BASE_H_FILE
#define D_INCLUDE_GUARD_C_SOUND_BASE_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "C_Game_Instance_Base.h"


// �� �l�[���X�y�[�X �� //

// �Q�[���̃T�E���h�̊��N���X���Ăяo�����߂̖��O
namespace GAME::INSTANCE::SOUND::BASE
{
	// �� �N���X �� //

	// �T�E���h�̊��ƂȂ�N���X
	class C_Sound_Base : public GAME::INSTANCE::BASE::C_Game_Instance_Base
	{
		//==�� �v���C�x�[�g ��==//
	private:


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �X�V -��-//

		// �T�E���h�̍X�V���s��
		virtual void M_Sound_Update(void) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_SOUND_BASE_H_FILE

