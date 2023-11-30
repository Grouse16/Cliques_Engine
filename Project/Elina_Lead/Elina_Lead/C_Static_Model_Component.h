//����������������������������������������������//
// �ڍ�   �F�ό`���Ȃ����f���̃R���|�[�l���g�̃V�X�e��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_STATIC_MODEL_COMPONENT
#define D_INCLUDE_GUARD_C_STATIC_MODEL_COMPONENT


// �� �t�@�C���Ђ炫 �� //
#include <vector>
#include <string>

#include "C_Component_Base.h"
#include "C_3D_Model_User.h"
#include "C_Transform.h"
#include "C_Material_User.h"
#include "S_Model_Draw_Command.h"


// �� �l�[���X�y�[�X �� //

// ���f���p�R���|�[�l���g���Ăяo�����߂̖��O
namespace GAME::COMPONENT::MODEL_COMPONENT
{
	// �� �N���X �� //

	// �ό`���Ȃ����f���̃R���|�[�l���g�N���X
	class C_Static_Model_Component : public GAME::COMPONENT::BASE::C_Component_Base
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			ASSET::MODEL::C_3D_Model_User model_system;	// 3D���f���V�X�e��
			
			MATH::C_Transform transform;	// ���f���̐ݒu�ʒu�i���[�J�����W�j

			std::vector<ASSET::MODEL_SYSTEM::S_Model_Draw_Command> draw_command_list;	// �`��ݒ胊�X�g

			DirectX::XMMATRIX world_matrix = DirectX::XMMATRIX();	// ���[���h�}�g���N�X�ϊ��s��

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Static_Model_Component(void);

		// �f�X�g���N�^
		~C_Static_Model_Component(void);


		//-��- ���[�h -��-//

		// �w�肳�ꂽ���O�̃��f�������[�h����@�����F���[�h���郂�f�����@�߂�l�F�������̂�true
		bool M_Load_Model_By_Name(std::string);


		//-��- �Z�b�^ -��-//

		// �`��ݒ胊�X�g��ԍ����w�肵�Đݒ肷��A�O�ɂ������`��ݒ�̃f�[�^�͏�����@�����F�ݒ��̕`��ݒ�ԍ�, �g�p����}�e���A����, �`�悷�郁�b�V�����̃��X�g�i���g�Ȃ��őS���b�V���`��j�@�߂�l�F�ǉ������}�e���A���g�p�V�X�e���̃A�h���X
		ASSET::MATERIAL::C_Material_User * M_Set_Model_Draw_List(int, std::string, std::vector<std::string>);


		//-��- �Q�b�^ -��-//

		// ���[�J�����W�̎Q�Ƃ�Ԃ��@�߂�l�F���[�J�����W�̎Q��
		MATH::C_Transform & M_Get_Transform(void);

		// ���f���V�X�e���̎Q�Ƃ�Ԃ��@�߂�l�F���f���V�X�e���̎Q��
		ASSET::MODEL::C_3D_Model_User & M_Get_Model_Address(void);


		//-��- �`�� -��-//

		// �`��ʒu�ƂȂ郏�[���h�}�g���N�X��ݒ肷��A�`��̊J�n���Ɏ��s����A�ʏ�`��̊J�n���ł悢�@�����F�ݒ肷�郏�[���h�}�g���N�X�ϊ��s��̎Q�Ɓiconst�j
		void M_Draw_Start_World_Matrix_Set(const DirectX::XMMATRIX & );

		// ���f���̕`����s���@�����F�`�悷�鎞�̕`��ݒ�̔ԍ�
		void M_Model_Draw(int);

		// �R���|�[�l���g�p�̕`�揈�������g�p���Ȃ��i���f���`��O�Ƀ}�e���A���̐ݒ�Ȃǂ��s�����߁j
		void M_Draw(void) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_STATIC_MODEL_COMPONENT
