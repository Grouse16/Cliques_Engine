//����������������������������������������������//
// �ڍ�   �F�Q�[���̓��͂𐧌䂷��V�X�e��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_C_Game_TIME_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_Game_TIME_MANAGER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>
#include <memory>
#include <string>


// �� �l�[���X�y�[�X �� //

// �Q�[���̎��Ԃ��Ăяo�����߂̖��O
namespace GAME::TIME
{
	// �� �N���X �� //

	// �Q�[���̎��Ԃ𐧌䂷��V�X�e��
	class C_Game_Time_Manager
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �\���� �� //

		// ���Ԃ̗�����Ǘ����邽�߂̃f�[�^�̍\����
		struct S_Time_Line
		{
			std::string time_name = "default";	// ���̎��Ԃ̖��O

			float time_speed = 0.0f;	// ���Ԃ̑��x
			float delta_second = 0.0f;	// �o�ߎ���
		};


		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			std::vector<S_Time_Line> time_line_list;	// ���Ԃ̗���̃��X�g

			unsigned __int64 time_of_seconds_start = 0;	// ��b�̎n�܂�̎���
			unsigned __int64 now_timer = 0;				// ���̎��Ԃ��v������
			unsigned __int64 then_timer = 0;			// �O��̎��Ԃ��v������

			float need_spend_time = 0;			// �t���[�����[�g���ێ����邽�߂ɂ͂��̎��Ԃ܂őҋ@����ׂ��Ƃ�������
			float delta_second = 0.0f;			// �O�̍X�V����̌o�ߎ��ԁi�b�P�ʁj�i���A���^�C���j
			float game_delta_second = 0.0f;		// �Q�[���S�̂̌o�ߎ��ԁi�b�P�ʁj
			float one_frame_time = 0.0f;		// �P�t���[���ԂŌo�߂��Ă���ׂ�����
			float game_speed = 1.0f;			// �Q�[���̃X�s�[�h]
			float delta_second_limit = 0.0f;	// �o�ߎ��Ԃ̍ő�l

			int frame_rate = 60;	// �t���[�����[�g
			int fps = 1;		// ��b�Ԃ̃t���[����
			int now_frame = 0;	// ���݂̃t���[����

			bool flg_constant_frame = true;	// �Œ�t���[���ɂ��邩�ǂ����̃t���O

			std::vector<std::string> delete_time_line_list;	// �폜����^�C�����C���̃��X�g

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O

		static std::unique_ptr<C_Game_Time_Manager> m_this;	// �C���X�^���X�����邽�߂̎��́i�V���O���g���p�j


		// �� �֐� �� //

		//-��- ������ -��-//

		// �R���X�g���N�^
		C_Game_Time_Manager(void);


		//==�� �p�u���b�N ��==//
	public:

		// �� �֐� �� //

		//-��- �������ƏI���� -��-//

		// ���ԗp�V�X�e���𐶐�����
		static void M_Init(void);

		// �f�X�g���N�^
		~C_Game_Time_Manager(void);

		// ���������������
		static void M_Release(void);

		// �^�C�����C�������Z�b�g����
		static void M_Reset_Time_Line(void);


		//-��- �X�V -��-//

		// ���Ԃ̍X�V
		static void M_Time_Update(void);

		// �t���[���̏I�����ɍs���X�V
		static void M_Frame_End_Update(void);


		//-��- �Q�b�^ -��-//

		// FPS���ێ����邽�߂̎��Ԃ��o�߂��Ă��邩�ǂ�����Ԃ��@�߂�l�Ftrue�Ȃ�o�߂��Ă���
		static bool M_Get_FPS_Request_Time_Passed(void);

		// ���݂̋K��t���[�����[�g��Ԃ��@�߂�l�F�K��t���[�����[�g
		static int M_Get_Frame_Rate(void);

		// ���݂�fps��Ԃ��@�߂�l�F���݂�fps
		static int M_Get_FPS(void);

		// ���݂̌o�ߎ��Ԃ�Ԃ��@�߂�l�F���݂̌o�ߎ���
		static float M_Get_Delta_Second(void);

		// �Q�[�����ł̌o�ߎ��Ԃ�Ԃ��@�߂�l�F�Q�[���ł̌o�ߎ���
		static float M_Get_Game_Second(void);

		// �Q�[�������Ԃ̃X�s�[�h��Ԃ��@�߂�l�F�Q�[�������Ԃ̃X�s�[�h
		static float M_Get_Game_Speed(void);

		// �w�肳�ꂽ���O�̃^�C�����C���̌o�ߎ��Ԃ�Ԃ��@�����F�擾����^�C�����C�����@�߂�l�F���̃^�C�����C���ł̌o�߃X�s�[�h
		static float M_Get_Time_Line_Delta_Second(std::string);


		//-��- �Z�b�^ -��-//

		// �t���[�����[�g���Z�b�g����@�����F�ݒ肷��t���[�����[�g
		static void M_Set_Frame_Rate(int);

		// �Q�[�������Ԃ̃X�s�[�h���Z�b�g����@�����F�Z�b�g����Q�[�������Ԃ̃X�s�[�h
		static void M_Set_Game_Speed(float);

		// �w�肳�ꂽ���O�̃^�C�����C���Ɏw�肳�ꂽ�X�s�[�h���Z�b�g����@�����F�ݒ��̃^�C�����C����, �ݒ肷�鎞�Ԃ̗���̃X�s�[�h
		static void M_Set_Time_Line_Speed(std::string, float);


		//-��- ���� -��-//

		// �^�C�����C���i���Ԃ̗���j�𐶐�����@�����F�������鎞�Ԃ̗���̖��O, ���Ԃ̗���̏����X�s�[�h
		static void M_Create_New_Time_Line(std::string, float);


		//-��- �폜 -��-//

		// �w�肳�ꂽ���O�̃^�C�����C�����폜����@�����F�폜����^�C�����C����
		static void M_Delete_Time_Line_By_Name(std::string);
	};
}


#endif // !D_INCLUDE_GUARD_C_Game_TIME_H_FILE
