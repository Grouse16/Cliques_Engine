//����������������������������������������������//
// �ڍ�   �F�A�j���[�V�������f�����g�p���邽�߂̃V�X�e��
// ����   �F�A�j���[�V�������f���}�l�[�W���[�Ƃ̑�����B�����A�ȒP�Ɏg�p�ł���悤�ɃJ�v�Z��������@�A�j���[�V�����̎��s���s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_MODEL_USER
#define D_INCLUDE_GUARD_C_ANIMATION_MODEL_USER


// �� �t�@�C���Ђ炫 �� //
#include <memory>

#include "C_3D_Animation_Model_System.h"
#include "C_Animation_Calculation_System.h"
#include "C_Transform.h"


// �� �l�[���X�y�[�X �� //

// �A�j���[�V�������f�����g�p����V�X�e�����Ăяo�����߂̖��O
namespace ASSET::ANIMATION_MODEL
{
	// �� �N���X �� //

	// �A�j���[�V�������f�����g�p���邽�߂̃V�X�e��
	class C_Animation_Model_User
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::vector<DirectX::XMFLOAT4X4> bone_matrix_list;	// �{�[���}�g���N�X�̔z��

			ASSET::ANIMATION_MODEL::C_3D_Animation_Model_System * animation_model = nullptr;	// �g�p����A�j���[�V�������f���܂ł̃A�h���X

			std::unique_ptr<ASSET::ANIMATION::CALCULATOR::C_Animation_Calculation_System> animation_calculator = nullptr;	// �A�j���[�V�����̌v�Z�V�X�e��

			std::string model_name = "default";	// ���f����

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O

		
		// �� �֐� �� //

		//-��- �A�j���[�V���� -��-//

		// �w�肳�ꂽ���O�̃A�j���[�V�����f�[�^�����f������擾����V�X�e���@�����F�A�j���[�V�������̎Q�Ɓ@�߂�l�F�A�j���[�V�����f�[�^�̃A�h���X(const)
		const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * M_Get_Animation(std::string &);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Animation_Model_User(void);

		// �f�X�g���N�^
		~C_Animation_Model_User(void);

		// �������̉�����s��
		void M_Release(void);


		//-��- ���[�h -��-//

		// �w�肳�ꂽ���O�̃A�j���[�V�������f����ǂݍ��ށ@�����F���[�h����A�j���[�V�������f�����@�߂�l�F�������̂�true
		bool M_Load_Animation_Model(std::string);

		// �w�肳�ꂽ���O�̃A�j���[�V�����f�[�^�����[�h����@�����F���[�h����A�j���[�V�����f�[�^���@�߂�l�F�������̂�true
		bool M_Load_Animation_Data_By_Name(std::string);


		//-��- �X�V -��-//

		// �A�j���[�V�������w�肳�ꂽ���ԕ��o�߂�����@�����F�o�߂����鎞��
		void M_Time_Update(float);


		//-��- �`�� -��-//

		// ���f���̕`����J�n����A�`��O�Ɏ��s����K�v������@�����F���[���h�}�g���N�X�ϊ��s��̎Q�Ɓiconst�j
		void M_Model_Draw_Start(const DirectX::XMMATRIX & );

		// �A�j���[�V�������f����`�悷��
		void M_Draw_Model(void);

		// �A�j���[�V�������f������w�肳�ꂽ���O�̃��b�V���݂̂�`�悷��@�����F���b�V����
		void M_Draw_Mesh_By_Mesh_Name(std::string);

		// �w�肳�ꂽ�}�e���A���ŃA�j���[�V�������f����`�悷��@�����F�g�p����}�e���A���Q��
		void M_Draw_Model_And_Set_Material(ASSET::MATERIAL::C_Material_User & );

		// �w�肳�ꂽ�}�e���A���ŃA�j���[�V�������f������w�肳�ꂽ���O�̃��b�V���݂̂�`�悷��@�����F�g�p����}�e���A���̎Q��, ���b�V����
		void M_Draw_Mesh_By_Mesh_Name_And_Set_Material(ASSET::MATERIAL::C_Material_User & ,std::string);

		// ���f���̕`����I������
		void M_Model_Draw_End(void);


		//-��- �A�j���[�V���� -��-//

		// �A�j���[�V���������݂̎��Ԃ̂܂܍Đ�����i�u�����h����j �����F�A�j���[�V������, �u�����h�ɕK�v�Ȏ��ԁ@�߂�l�F�������̂�true
		bool M_Play_Animation(std::string, float);

		// �A�j���[�V�������w�肳�ꂽ���Ԃ���Đ�����i�u�����h����j�@�����F�A�j���[�V������, �u�����h�ɕK�v�Ȏ���, �A�j���[�V�����J�n���ԁ@�߂�l�F�������̂�true
		bool M_Play_Animation_Set_Time(std::string, float, float);

		// �A�j���[�V���������݂̎��Ԃ̂܂܃��[�v�Đ�����i�u�����h����j�i�u�����h��̃A�j���[�V������0�b����n�܂�j�@�����F�A�j���[�V������, �u�����h�ɕK�v�Ȏ��ԁ@�߂�l�F�������̂�true
		bool M_Loop_Play_Animation(std::string, float);

		// �A�j���[�V�������w�肳�ꂽ���Ԃ��烋�[�v�Đ�����i�u�����h����j�i�u�����h��̃A�j���[�V������0�b����n�܂�j�@�����F�A�j���[�V������, �u�����h�ɕK�v�Ȏ���, �A�j���[�V�����J�n���ԁ@�߂�l�F�������̂�true
		bool M_Loop_Play_Animation_And_Set_Time(std::string, float, float);

		// �A�j���[�V���������݂̎��Ԃ̂܂܋����I�ɍĐ�����i�u�����h�Ȃ��j�@�����F�A�j���[�V�������@�߂�l�F�������̂�true
		bool M_Force_Play_Animation(std::string);

		// �A�j���[�V�������w�肳�ꂽ���Ԃ��狭���I�ɍĐ�����i�u�����h�Ȃ��j�@�����F�A�j���[�V������, �A�j���[�V�����̊J�n���ԁ@�߂�l�F�������̂�true
		bool M_Force_Play_Animation_And_Set_Time(std::string, float);

		// �A�j���[�V���������݂̎��Ԃ̂܂܋����I�Ƀ��[�v�Đ�����i�u�����h�Ȃ��j�@�����F�A�j���[�V�������@�߂�l�F�������̂�true
		bool M_Force_Loop_Play_Animation(std::string);

		// �A�j���[�V�������w�肳�ꂽ���Ԃ��狭���I�Ƀ��[�v�Đ�����i�u�����h�Ȃ��j�@�����F�A�j���[�V������, �A�j���[�V�����̊J�n���ԁ@�߂�l�F�������̂�true
		bool M_Force_Loop_Play_Animation_And_Set_Time(std::string, float);

		// �A�j���[�V�������x���Z�b�g����@�����F�Z�b�g����A�j���[�V�������x
		void M_Set_Animation_Speed(float);


		//-��- �Q�b�^ -��-//

		// ���݂̃A�j���[�V�������f����Ԃ��@�߂�l�F���݂̃A�j���[�V�������f���ւ̃A�h���X
		ASSET::ANIMATION_MODEL::C_3D_Animation_Model_System * M_Get_Animation_Model_Address(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_MODEL_USER
