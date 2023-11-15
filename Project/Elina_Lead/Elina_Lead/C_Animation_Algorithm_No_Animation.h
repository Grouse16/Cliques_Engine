//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�������s��Ȃ����̃��f���\���p�̃N���X�i�������p�j
// ����   �F�A�j���[�V�����̍Đ����ݒ肳���܂ł̊ԁAT�|�[�Y�̂悤�ȏ�����Ԃ�ݒ肷��N���X
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_ALGORITHM_NO_ANIMATION_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_ALGORITHM_NO_ANIMATION_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>

#include "C_Animation_Algorithm_Base.h"
#include "S_Bone_Inform.h"


// �� �l�[���X�y�[�X �� //

// �A�j���[�V�����̌v�Z�A���S���Y�����Ăяo�����߂̖��O
namespace ASSET::ANIMATION::ALGORITHM
{
	// �� �N���X �� //

	// �A�j���[�V�������s��Ȃ����̃��f���\���p�̃N���X�i�������p�j
	class C_Animation_Algorithm_No_Animation : public ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Base
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //
		const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & m_bone_inform_list;	// �{�[�����̃��X�g�̎Q��


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^�@���������ɐݒ肵�Ȃ��R���X�g���N�^�𖳌���
		C_Animation_Algorithm_No_Animation(void) = delete;

		// �R���X�g���N�^�@�����F�{�[���̏������̎Q��(const)
		C_Animation_Algorithm_No_Animation(const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & );

		// �f�X�g���N�^
		~C_Animation_Algorithm_No_Animation(void) override;


		//-��- �X�V -��-//

		// �A�j���[�V�������Ԃ̍X�V
		void M_Animation_Time_Update(void) override;

		// �A�j���[�V�����̍X�V�@�����F�X�V��������{�[���̃}�g���N�X�̔z��̎Q��
		void M_Animation_Update(std::vector<DirectX::XMFLOAT4X4> & ) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_ALGORITHM_NO_ANIMATION_H_FILE

