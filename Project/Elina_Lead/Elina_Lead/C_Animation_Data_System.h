//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�����f�[�^�̃N���X
// ����   �F���[�h�A�w�肳�ꂽ���Ԃł̃}�g���N�X�ϊ�����Ԃ��Ȃǂ�����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_DATA_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_DATA_SYSTEM_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>
#include <string>

#include "S_Bone_Inform.h"
#include "S_Bone_Key_Inform.h"


// �� �l�[���X�y�[�X �� //

// �A�j���[�V�����f�[�^���Ăяo�����߂̖��O
namespace ASSET::ANIMATION::DATA
{
	// �� �N���X �� //

	// �A�j���[�V�����f�[�^�̃N���X
	class C_Animation_Data_System
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::vector<ASSET::ANIMATION::BONE::S_Bone_Key_Inform> bone_key_list;	// �{�[���̃L�[���̃��X�g

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Animation_Data_System(void);

		// �f�X�g���N�^
		~C_Animation_Data_System(void);

		// �������̉�����s��
		void M_Release(void);

		
		//-��- ���[�h -��-//

		// �w�肳�ꂽ�p�X�̃A�j���[�V�����f�[�^�����[�h����@�����F�A�j���[�V�����f�[�^�܂ł̃p�X, �A�^�b�`�惂�f���̃{�[���̏��@�߂�l�F�������̂�true
		bool M_Load_Anmation_Data_By_Path(std::string, std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> &);


		//-��- �L�[�t���[�� -��-//

		// �w�肳�ꂽ���ԂƃL�[�̉e���ʂ��炻�ꂼ��̃{�[���̃L�[���𐶐����A�ݒ��փZ�b�g����@�����F����, �L�[�e����, �ݒ��̃{�[���L�[�z��̎Q��
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_DATA_SYSTEM_H_FILE

