//����������������������������������������������//
// �ڍ�   �F�ʏ�ɃA�j���[�V�������Đ�����N���X
// ����   �F��̃A�j���[�V�����������Ă���̍Đ��̂ݍs��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include "C_Animation_Algorithm_Play.h"
#include "C_Game_Time_Manager.h"


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace ASSET::ANIMATION::ALGORITHM;


// �� �֐� �� //

//==�� �p�u���b�N ��==//

//-��- �������ƏI���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �F�A�j���[�V�����X�e�[�^�X�̎Q��, �A�j���[�V��������f�[�^�̃Z�b�g
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Algorithm_Play::C_Animation_Algorithm_Play(ASSET::ANIMATION::S_Animation_Status & in_set_animation_status, ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * in_set_animation_data) : m_animation_status(in_set_animation_status)
{
	m_now_animation = in_set_animation_data;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Animation_Algorithm_Play::~C_Animation_Algorithm_Play(void)
{
	return;
}


//-��- �X�V -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�������Ԃ̍X�V
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Animation_Algorithm_Play::M_Animation_Time_Update(void)
{
	

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�A�j���[�V�����̍X�V
// ����   �Fvector<XMFLOAT4X4> & �X�V��������{�[���̃}�g���N�X�̔z��̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Play::M_Animation_Update(std::vector<DirectX::XMFLOAT4X4> & in_set_matrix)
{
}

