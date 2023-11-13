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

#include "S_Key_Frame.h"


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
			std::vector<ASSET::ANIMATION::DATA::S_Key_Frame> position_key_list;	// �ʒu���W�̃L�[�̃��X�g
			std::vector<ASSET::ANIMATION::DATA::S_Key_Frame> scale_key_list;	// �X�P�[���̃L�[�̃��X�g

			std::vector<ASSET::ANIMATION::DATA::S_Rotation_Key_Frame> rotation_key_list;	// ��]�̃L�[�̃��X�g

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

		// �w�肳�ꂽ�p�X�̃A�j���[�V�����f�[�^�����[�h����
		bool M_Get_Animation_Data_Load(std::string);


	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_DATA_SYSTEM_H_FILE

