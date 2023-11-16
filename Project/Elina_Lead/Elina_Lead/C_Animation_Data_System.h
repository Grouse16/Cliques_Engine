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
#include "C_Bone_Data.h"
#include "S_Bone_Key_Frame_List.h"


// �� �l�[���X�y�[�X �� //

// �A�j���[�V�����f�[�^���Ăяo�����߂̖��O
namespace ASSET::ANIMATION_SYSTEM
{
	// �� �N���X �� //

	// �A�j���[�V�����f�[�^�̃N���X
	class C_Animation_Data_System
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �\���� �� //

		// �{�[���̃A�j���[�V�����L�[�Ǘ��p�̏��̍\����
		struct S_Bone_Key_Inform
		{
			ASSET::ANIMATION::BONE::S_Bone_Key_Frame_List key;	// �{�[���̃L�[���̃��X�g

			int bone_index = 0;	// �{�[���̃C���f�b�N�X�ԍ�
		};


		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::vector<S_Bone_Key_Inform> bone_key_list;	// �{�[���̃L�[���̃��X�g

			float animation_max_time = 0.0f;	// �A�j���[�V�����̍ő厞��

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		// �� �֐� �� //

		//-��- �L�[�t���[���u�����h -��-//

		// �n���ꂽ�������ɃL�[�l�����ԂŊ���o���Ă�Ԃ��@�����F�J�n�̃L�[�l, �I���̃L�[�l, ���Ԃ̃p�[�Z���g�@�߂�l�F�v�Z���ʂ̃L�[�l
		inline float M_Key_To_Key_Value_Calculation_By_Time(float, float, float) const;

		// �w�肳�ꂽ��񂩂�L�[�t���[���̌v�Z���s�������u�����h����@�����F���̎���, �u�����h��, �ݒ茳�̃L�[�t���[�����, �ݒ��̃L�[�l
		inline void M_Blend_Key_Frame(float , float , const std::vector<ASSET::ANIMATION_SYSTEM::S_Key_Frame> &, DirectX::XMFLOAT3 &) const;

		// �w�肳�ꂽ��񂩂�N�H�[�^�j�I���̃L�[�t���[���̌v�Z���s�������u�����h����@�����F���̎���, �u�����h��, �ݒ茳�̃N�H�[�^�j�I���L�[�t���[�����, �ݒ��̃L�[�l
		inline void M_Blend_Quaternion_Key_Frame(float, float, const std::vector<ASSET::ANIMATION_SYSTEM::S_Quaternion_Key_Frame> &, DirectX::XMVECTOR &) const;


		//-��- �L�[�t���[���Z�b�g -��-//

		// �w�肳�ꂽ��񂩂�L�[�t���[���̌v�Z���s�������Z�b�g����@�����F���̎���, �ݒ茳�̃L�[�t���[�����, �ݒ��̃L�[�l
		inline void M_Set_Key_Frame(float, const std::vector<ASSET::ANIMATION_SYSTEM::S_Key_Frame> & , DirectX::XMFLOAT3 & ) const;

		// �w�肳�ꂽ��񂩂�N�H�[�^�j�I���̃L�[�t���[���̌v�Z���s�������Z�b�g����@�����F���̎���, �ݒ茳�̃N�H�[�^�j�I���L�[�t���[�����, �ݒ��̃L�[�l
		inline void M_Set_Quaternion_Key_Frame(float, const std::vector<ASSET::ANIMATION_SYSTEM::S_Quaternion_Key_Frame> &, DirectX::XMVECTOR &) const;


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Animation_Data_System(void);

		// �f�X�g���N�^
		~C_Animation_Data_System(void);

		// �������̉�����s��
		void M_Release(void);

		
		//-��- ���[�h -��-//

		// �w�肳�ꂽ�p�X�̃A�j���[�V�����f�[�^�����[�h����@�����F�A�j���[�V�����f�[�^�܂ł̃p�X, �A�^�b�`�惂�f���̃{�[���̏��@�߂�l�F�������̂�true
		bool M_Load_Animation_Data_By_Path(std::string, std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> &);


		//-��- �L�[�t���[���u�����h -��-//

		// �w�肳�ꂽ���ԂƃL�[�̃u�����h�����炻�ꂼ��̃{�[���̃L�[���𐶐����A�ݒ��փu�����h����@�����F����, �u�����h��, �ݒ��̃{�[���L�[�̃{�[�����Ƃ̔z��̎Q��
		void M_Blend_Bone_Key(float, float, std::vector<ASSET::ANIMATION::BONE::C_Bone_Data> &) const;


		//-��- �L�[�t���[���Z�b�g -��-//

		// �w�肳�ꂽ���Ԃ��炻�ꂼ��̃{�[���̃L�[���𐶐����A�ݒ��փZ�b�g����@�����F����, �ݒ��̃{�[���L�[�̃{�[�����Ƃ̔z��̎Q��
		void M_Set_Bone_Key(float, std::vector<ASSET::ANIMATION::BONE::C_Bone_Data> &) const;


		//-��- �Q�b�^ -��-//

		// �A�j���[�V�����J�n����I���܂ł̎��ԁ@�߂�l�F�A�j���[�V�����J�n����I���܂ł̎���
		int M_Get_Animation_Time(void) const;
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_DATA_SYSTEM_H_FILE

