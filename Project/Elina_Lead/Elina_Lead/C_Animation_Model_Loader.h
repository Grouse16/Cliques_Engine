//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�������f���̃��[�h������V�X�e��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_MODEL_LOADER_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_MODEL_LOADER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include "S_Animation_Model_Load_Information.h"


// �� �l�[���X�y�[�X �� //

// �A�j���[�V�������f�������[�h���邽�߂̃V�X�e�����Ăяo�����߂̖��O
namespace ASSET::ANIMATION_MODEL::LOADER
{
	// �� �N���X �� //

	// �A�j���[�V�������f�������[�h����N���X
	class C_Animation_Model_Loader
	{
	//==�� �v���C�x�[�g ��==//
	private:

		// �� �֐� �� //

		//-��- ������ -��-//

		// �C���X�^���X���ł��Ȃ��悤�ɃR���X�g���N�^���B��������ō폜
		C_Animation_Model_Loader(void) = delete;


	//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- ���[�h -��-//

		// �A�j���[�V�������f�������[�h����@�����F���[�h���邽�߂̏��̎Q�Ɓ@�߂�l�F�������̂�true
		static bool M_Load_Animation_Model(S_Animation_Model_Load_System &);
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_MODEL_LOADER_H_FILE

