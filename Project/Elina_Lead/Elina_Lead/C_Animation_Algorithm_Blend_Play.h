//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�������u�����h�Đ�����N���X
// ����   �F�u�����h���I�������ۂ̃V���O���g���A�j���[�V�����Ɠ���ւ��邽�߂̏��̓A�j���[�V�����X�e�[�^�X���ɃZ�b�g�����
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_ALGORITHM_BLEND_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_ALGORITHM_BLEND_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>

#include "C_Animation_Algorithm_Base.h"
#include "C_Animation_Data_System.h"
#include "S_Animation_Status.h"


// �� �l�[���X�y�[�X �� //

// �A�j���[�V�����̌v�Z�A���S���Y�����Ăяo�����߂̖��O
namespace ASSET::ANIMATION::ALGORITHM
{
	// �� �N���X �� //

	// �A�j���[�V�������u�����h�Đ�����N���X
	class C_Animation_Algorithm_Blend_Play : public ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Base
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //
		ASSET::ANIMATION::S_Animation_Status & m_animation_status;	// �A�j���[�V�����X�e�[�^�X

		ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * m_from_animation = nullptr;	// �u�����h���̃A�j���[�V����
		ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * m_to_animation = nullptr;	// �u�����h��̃A�j���[�V����

		float animation_from_time = 0.0f;	// �A�j���[�V�������̃A�j���[�V��������


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^�@���������ɐݒ肵�Ȃ��R���X�g���N�^�𖳌���
		C_Animation_Algorithm_Blend_Play(void) = delete;

		// �R���X�g���N�^�@�����F�A�j���[�V�����X�e�[�^�X�̎Q��, �u�����h���̃A�j���[�V����, �u�����h��̃A�j���[�V����
		C_Animation_Algorithm_Blend_Play(ASSET::ANIMATION::S_Animation_Status &, ASSET::ANIMATION_SYSTEM::C_Animation_Data_System *, ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * );

		// �f�X�g���N�^
		~C_Animation_Algorithm_Blend_Play(void) override;


		//-��- �X�V -��-//

		// �A�j���[�V�������Ԃ̍X�V
		void M_Animation_Time_Update(void) override;

		// �A�j���[�V�����̍X�V�@�����F�X�V��������{�[���̃}�g���N�X�̔z��̎Q��
		void M_Animation_Update(std::vector<DirectX::XMFLOAT4X4> &) override;


		//-��- �Q�b�^ -��-//

		// ���݂̃A�j���[�V������Ԃ��@�߂�l�F���݂̃A�j���[�V�����̃A�h���X
		ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * M_Get_Now_Animation(void) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_ALGORITHM_BLEND_H_FILE
