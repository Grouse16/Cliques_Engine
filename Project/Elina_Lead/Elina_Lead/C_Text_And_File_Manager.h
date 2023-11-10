//����������������������������������������������//
// �ڍ�   �F�t�@�C������p�V�X�e���̃N���X
// ����   �F�t�@�C���𐶐����A�f�[�^���L�^�ł���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_FILE_USER_H_FILE
#define D_INCLUDE_GUARD_FILE_USER_H_FILE


// �� �t�@�C���Ђ炫 �� //
#include <vector>
#include <string>


// �� �l�[���X�y�[�X �� //

// �e�L�X�g�𐧌䂷��V�X�e�����Ăяo�����߂̖��O
namespace SYSTEM::TEXT
{
	// �� �萔 �� //

	// �ҏW���[�h���w�肷�邽�߂̗�
	enum class E_EDIT_MODE
	{
		e_TEXT,		// �e�L�X�g�`��
		e_BINARY,	// �o�C�i���`��
	};


	// �� �N���X �� //

	// ���͂𐧌䂷�邽�߂̃N���X�A�t�@�C���̓ǂݏ������s��
	class C_Text_And_File_Manager
	{
		//==�� �v���C�x�[�g ��==//
	private:

		// �� �ϐ��錾 �� //

		// �v���C�x�[�g�ϐ����܂Ƃ߂��\����
		struct SPr_Variable
		{
			const std::string con_default_name = "default_file_name";	// �f�t�H���g�̃t�@�C����

			E_EDIT_MODE mode_setting = E_EDIT_MODE::e_TEXT;	// �ҏW���[�h�ݒ�

			std::vector<std::string> stack_data;	// ���͂̃f�[�^�i���z�񁁍s,�@���z�񁁗񂨂�ѕ����j

			std::string file_path = con_default_name;	// �t�@�C���܂ł̃p�X

			int row_number = 0;		// �s�̔ԍ�
			int column_number = 0;	// ��̔ԍ�

		} mpr_variable;	// �v���C�x�[�g�ϐ����Ăяo�����߂̖��O


		//-��- �f�[�^���� -��-//

		// ���͂��ꂽ�p�X�����o�O�������N�����Ȃ����̂��ǂ����𔻒肷��@�����F�p�X���@�߂�l�F�p�X�������������true
		bool M_Is_File_Path_Succeed(std::string & );

		// ���͂��ꂽ�p�X���̂����t�H���_�̕������o�O�������N�����Ȃ����̂��ǂ����𔻒肷��@�����F�p�X���@�߂�l�F�p�X�������������true
		bool M_Is_Folder_Path_Is_Succeed(std::string & );

		// �t�@�C�����w�肳��Ă��邩�ǂ����𔻒�@�����F�p�X���@�߂�l�F�t�@�C���܂ł̃p�X�Ȃ�true �t�H���_�Ȃǂ܂łȂ�false
		bool M_Is_File(std::string & );

		// �w�肳�ꂽ���������s�����ł��邩�ǂ����𔻒肷��@�����F�����f�[�^�@�߂�l�Ftrue�Ȃ���s�R�[�h
		bool M_Is_CR(const char &);


		//==��  �p�u���b�N  ��==//
	public:

		//-��- �������ƏI���� -��-//

		// �R���X�g���N�^
		C_Text_And_File_Manager(void);

		// �f�[�^������
		void M_Reset_Data(void);

		// �f�X�g���N�^
		~C_Text_And_File_Manager(void);


		//-��- �f�[�^�ϊ� -��-//

		// �������10�i����INT�^�ɕϊ�����@�����F�ϊ�����f�[�^�@�߂�l�F�ϊ�����
		static int M_Convert_Data_Char_To_X16INT(std::string);


		//-��- ���� -��-//

		// �n���ꂽ�p�X�̃t�@�C�������݂��Ă��Ȃ���ΐ�������i�p�X��+���s�������t�H���_�Ƃ���j�@�����F�t�@�C���܂ł̃p�X
		bool M_Creat_Path_Of_Folder(std::string);

		// �p�X�܂ł̃t�@�C���ƃt�H���_���Ȃ���ΐ�������i�p�X��+���s�������t�H���_�Ƃ���j�@�����F�t�@�C���܂ł̃p�X
		bool M_Creat_File_And_Folder_If_File_Not_Exist(std::string);


		//-��- �Z�b�^ -��-//

		// ���ꂩ��ҏW����t�@�C���̃p�X���w�肷��i�Ȃ���ΐ��������j�@�����F�t�@�C���̃p�X�@�߂�l�F�������̂�true
		bool M_Set_File_Path(std::string);

		// �ҏW���[�h���w�肷��@�����F�ҏW���[�h���w�肷��ԍ�
		void M_Set_Edit_Mode(E_EDIT_MODE);


		//-��- �Q�b�^ -��-//

		// ���݂̃f�[�^�̎Q�Ƃ�n���@�߂�l�F�t�@�C���f�[�^�̕�����
		const std::vector<std::string> & M_Get_File_Data_Refer(void);

		// ���ݕҏW���̃t�@�C���̃p�X��Ԃ��@�߂�l�F�t�@�C���p�X�̕�����
		const std::string & M_Get_File_Path_Refer(void);

		// ���݂̍s�̔ԍ���Ԃ�
		int M_Get_Now_Row(void);

		// ���͂̍s����Ԃ�
		int M_Get_Text_Row_Sum(void);

		// ���݂̗�̔ԍ���Ԃ�
		int M_Get_Now_Column(void);

		// ���I�𒆂̍s�̕�������Ԃ�
		int M_Get_Column_Sum_In_Now_Row(void);

		// ���݂̕��͑S�̂̕�������Ԃ�
		int M_Get_Sentence_Text_Size(void);


		//-��- �Z�[�u -��-//

		// ���쒆�̃t�@�C���Ɍ��݂̃f�[�^���㏑���ŃZ�[�u����@�߂�l�F�������̂�true
		bool M_Save_Data_To_Now_File(void);

		// �w�肳�ꂽ�t�@�C���Ɍ��݂̃f�[�^���㏑���ŃZ�[�u����@�����F�t�@�C���̃p�X�@�߂�l�F�������̂�true
		bool M_Save_Data_To_Select_File(std::string);

		// ���쒆�̃t�@�C���Ɍ��݂̃f�[�^��ǉ��ŃZ�[�u����@�߂�l�F�������̂�true
		bool M_Add_Data_To_Now_File(void);

		// �w�肳�ꂽ�t�@�C���Ɍ��݂̃f�[�^��ǉ��ŃZ�[�u����@�����F�t�@�C���̃p�X�@�߂�l�F�������̂�true
		bool M_Add_Data_To_Select_File(std::string);


		//-��- ���[�h -��-//

		// ���쒆�̃t�@�C������f�[�^��ǂݍ��ށ@�߂�l�F�������̂�ture
		bool M_Load_Now_File(void);

		// ���쒆�̃t�@�C������w�肳�ꂽ�s�Ԃ����f�[�^��ǂݍ��ށ@�����F�ǂݎn�܂�̍s, �ǂݏI���̍s�@�߂�l�F�������̂�ture
		bool M_Load_Now_File_Only_Select_Raw(int, int);

		// �w�肳�ꂽ�t�@�C������f�[�^��ǂݍ��ށ@�����F�t�@�C���̃p�X�@�߂�l�F�������̂�ture
		bool M_Load_Select_File(std::string);

		// �w�肳�ꂽ�t�@�C������w�肳�ꂽ�s�Ԃ����f�[�^��ǂݍ��ށ@�����F�t�@�C���̃p�X, �ǂݎn�܂�̍s, �ǂݏI���̍s�@�߂�l�F�������̂�ture
		bool M_Load_Select_File_Only_Select_Raw(std::string, int, int);


		//-��- ���� -��-//

		// �w�肳�ꂽ�f�[�^�����݂̑���ʒu������͂���@�����F���͂���f�[�^
		void M_Input_This_Data(short);

		// �w�肳�ꂽ�f�[�^�����݂̑���ʒu������͂���@�����F���͂���f�[�^
		void M_Input_This_Data(unsigned short);

		// �w�肳�ꂽ�f�[�^�����݂̑���ʒu������͂���@�����F���͂���f�[�^
		void M_Input_This_Data(int);

		// �w�肳�ꂽ�f�[�^�����݂̑���ʒu������͂���@�����F���͂���f�[�^
		void M_Input_This_Data(unsigned int);

		// �w�肳�ꂽ�f�[�^�����݂̑���ʒu������͂���@�����F���͂���f�[�^
		void M_Input_This_Data(long long);

		// �w�肳�ꂽ�f�[�^�����݂̑���ʒu������͂���@�����F���͂���f�[�^
		void M_Input_This_Data(unsigned long long);

		// �w�肳�ꂽ�f�[�^�����݂̑���ʒu������͂���@�����F���͂���f�[�^
		void M_Input_This_Data(std::string);

		// �w�肳�ꂽ�f�[�^�����݂̑���ʒu������͂���@�����F���͂���f�[�^
		void M_Input_This_Data(double);


		//-��- �폜 -��-//

		// �w�肳�ꂽ�f�[�^�𕶏͓�����w�肳�ꂽ�񐔕������폜����@�����F�폜�񐔁i�O�őS�č폜�j, �폜���镶��
		void M_Delete_Data_Equal_This_Text_In_Sentence(int, std::string);

		// �w�肳�ꂽ�f�[�^��I�𒆂̍s������w�肳�ꂽ�񐔕������폜����@�����F�폜�񐔁i�O�őS�č폜�j, �폜���镶��
		void M_Delete_Data_Eqaul_This_Text_In_Now_Row(int, std::string);

		// �w�肳�ꂽ�f�[�^��I�𒆈ʒu�̉E���̍s������w�肳�ꂽ�񐔕������폜����@�����F�폜�񐔁i�O�őS�č폜�j, �폜���镶��
		void M_Delete_Data_Eqaul_This_Text_In_Now_Row_For_Right(int, std::string);

		// �w�肳�ꂽ�f�[�^��I�𒆈ʒu�̍����̍s������w�肳�ꂽ�񐔕������폜����@�����F�폜�񐔁i�O�őS�č폜�j, �폜���镶��
		void M_Delete_Data_Eqaul_This_Text_In_Now_Row_For_Left(int, std::string);

		// �w�肳�ꂽ�s���폜����@�����F�폜����s
		void M_Delete_Row(int);

		// ���̏ꏊ����w�肳�ꂽ�������������������폜����i�s�͂����Ȃ��j�@�����F�폜���镶����
		void M_Delete_Column(int);

		// �I�𒆂̃t�@�C�����폜����@�߂�l�F�폜����t�@�C����������Ȃ������A�������͎w�肳�ꂽ�p�X���f�B���N�g���������Ȃ�false
		bool M_Delete_Now_File(void);

		// �w�肳�ꂽ�t�@�C�����폜����@�����F�폜����t�@�C���܂ł̃p�X�@�߂�l�F�폜����t�@�C����������Ȃ������A�������͎w�肳�ꂽ�p�X���f�B���N�g���������Ȃ�false
		bool M_Delete_Select_File(std::string);

		// �w�肳�ꂽ�t�H���_���폜����@�����F�폜����t�H���_�܂ł̃p�X�@�߂�l�F�폜����t�H���_��������Ȃ�������false
		bool M_Delete_Select_Folder(std::string);


		//-��- �ύX -��-//

		// ���ݕҏW���̃t�@�C���̃t�@�C������ύX����@�����F�ύX��̃t�@�C�����@�߂�l�F�ύX�ɐ���������true
		bool M_Rename_Now_File(std::string);

		// �w�肳�ꂽ�t�@�C���̃t�@�C������ύX����@�����F�ύX�O�̃t�@�C����, �ύX��̃t�@�C�����@�߂�l�F�ύX�ɐ���������true
		bool M_Rename_Select_File(std::string, std::string);

		// �w�肳�ꂽ�t�H���_�̃t�H���_����ύX����@�����F�ύX�O�̃t�H���_��, �ύX��̃t�H���_���@�߂�l�F�ύX�ɐ���������true
		bool M_Rename_Select_Folder(std::string, std::string);


		//-��- �o�� -��-//

		// ���̏ꏊ�̉E�ɐ���������ꍇ�͂��̐�����Ԃ��@�߂�l�F�����^
		long long M_Get_Number(void);

		// ���̏ꏊ�̉E�ɐ���������ꍇ�͂��̏�������̐�����Ԃ��@�߂�l�F��������
		double M_Get_Float_Double_Number(void);

		// ���̏ꏊ����w�肳�ꂽ�������Ԃ��@�����F�������@�߂�l�F������
		std::string M_Get_Data_By_Number(int);

		// ���̏ꏊ����w�肳�ꂽ�����܂ł�Ԃ��A�w�肳�ꂽ�������Ȃ�������___Not_Founds___��Ԃ��@�����F�T�����镶����@�߂�l�F������
		std::string M_Get_Data_By_Text(std::string);

		// �s�̎n�܂肩��I�𒆂̏ꏊ�܂ł�Ԃ��@�߂�l�F������
		std::string M_Get_Data_Left_In_Row(void);

		// �I�𒆂̏ꏊ����s���܂ł�Ԃ��@�߂�l�F������
		std::string M_Get_Data_Right_In_Row(void);

		// ���̑I�𒆂̍s�̎n�܂肩��I���܂ł��Ƃ�@�߂�l�F������
		std::string M_Get_Data_Now_Row(void);


		//-��- �ҏW�ʒu -��-//

		//=�� ���ڈړ��n ��=//

		// ���̎n�܂�Ɉړ�����
		void M_Goto_Sentence_Start(void);

		// ���̏I���Ɉړ�����
		void M_Goto_Sentence_End(void);

		// �I�𒆂̍s�̎n�܂�Ɉړ�����
		void M_Goto_Column_In_Row_Start(void);

		// �I�𒆂̍s�̏I���Ɉړ�����
		void M_Goto_Column_In_Row_End(void);

		// �n�܂�̍s�Ɉړ�����
		void M_Goto_Start_Row(void);

		// �I���̍s�Ɉړ�����
		void M_Goto_End_Row(void);

		// �w�肳�ꂽ�s�Ɉړ�����@�����F�s�̔ԍ�
		void M_Goto_Row_By_Set_Number(unsigned int);

		// �w�肳�ꂽ��Ɉړ�����@�����F��̔ԍ�
		void M_Goto_Column_By_Set_Number(unsigned int);


		//=�� �Ԑڈړ��n ��==//

		// �w�肳�ꂽ�����A�ړ�����@�����F�ړ���
		void M_Move_Position_By_Number(int);

		// �w�肳�ꂽ�����A�s���ړ�����@�����F�ړ���
		void M_Move_Raw_By_Number(int);

		// ���̍s�ֈړ�����
		void M_Move_Next_Raw(void);


		//=�� �T���ړ��n ��=//

		// �w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȍ~�ň�ԋ߂����̂𕶏͂���(���s���܂߂�)�T�����āA���̕����̉E�Ɉړ�����@�����F�T�����镶���@�߂�l�F�݂�������true
		bool M_Goto_Right_By_Text_In_Front_Sentence(std::string);

		// �w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȑO�ň�ԋ߂����̂𕶏͂���(���s���܂߂�)�T�����āA���̕����̉E�Ɉړ�����@�����F�T�����镶���@�߂�l�F�݂�������true
		bool M_Goto_Right_By_Text_In_Back_Sentence(std::string);

		// �w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȍ~�ň�ԋ߂����̂��s���ƂɁi���s�͊܂߂��Ɂj�T�����āA���̕����̉E�Ɉړ�����@�����F�T�����镶���@�߂�l�F�݂�������true
		bool M_Goto_Right_By_Text_In_Front_Row(std::string);

		// �w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȑO�ň�ԋ߂����̂��s���ƂɁi���s�͊܂߂��Ɂj�T�����āA���̕����̉E�Ɉړ�����@�����F�T�����镶���@�߂�l�F�݂�������true
		bool M_Goto_Right_By_Text_In_Back_Row(std::string);

		// �w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȍ~�ň�ԋ߂����̂�I�𒆂̍s���ŒT�����āA���̕����̉E�Ɉړ�����@�����F�T�����镶���@�߂�l�F�݂�������true
		bool M_Goto_Right_By_Text_In_Front_Column(std::string);

		// �w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȑO�ň�ԋ߂����̂�I�𒆂̍s���ŒT�����āA���̕����̉E�Ɉړ�����@�����F�T�����镶���@�߂�l�F�݂�������true
		bool M_Goto_Right_By_Text_In_Back_Column(std::string);


		// �w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȍ~�ň�ԋ߂����̂𕶏͂���(���s���܂߂�)�T�����āA���̕����̍��Ɉړ�����@�����F�T�����镶���@�߂�l�F�݂�������true
		bool M_Goto_Left_By_Text_In_Front_Sentence(std::string);

		// �w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȑO�ň�ԋ߂����̂𕶏͂���(���s���܂߂�)�T�����āA���̕����̍��Ɉړ�����@�����F�T�����镶���@�߂�l�F�݂�������true
		bool M_Goto_Left_By_Text_In_Back_Sentence(std::string);

		// �w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȍ~�ň�ԋ߂����̂��s���ƂɁi���s�͊܂߂��Ɂj�T�����āA���̕����̍��Ɉړ�����@�����F�T�����镶���@�߂�l�F�݂�������true
		bool M_Goto_Left_By_Text_In_Front_Row(std::string);

		// �w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȑO�ň�ԋ߂����̂��s���ƂɁi���s�͊܂߂��Ɂj�T�����āA���̕����̍��Ɉړ�����@�����F�T�����镶���@�߂�l�F�݂�������true
		bool M_Goto_Left_By_Text_In_Back_Row(std::string);

		// �w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȍ~�ň�ԋ߂����̂�I�𒆂̍s���ŒT�����āA���̕����̍��Ɉړ�����@�����F�T�����镶���@�߂�l�F�݂�������true
		bool M_Goto_Left_By_Text_In_Front_Column(std::string);

		// �w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȑO�ň�ԋ߂����̂�I�𒆂̍s���ŒT�����āA���̕����̍��Ɉړ�����@�����F�T�����镶���@�߂�l�F�݂�������true
		bool M_Goto_Left_By_Text_In_Back_Column(std::string);


		//-��- �����T�� -��-//

		// �w�肳�ꂽ���������͓��ɂ��邩�ǂ�����Ԃ��@�����F�T�����镶���@�߂�l�F�݂�������true
		bool M_Serch_Text_In_Sentence(std::string);

		// �w�肳�ꂽ�������I�𒆂̗�����邩�ǂ�����Ԃ��@�����F�T�����镶���@�߂�l�F�݂�������true
		bool M_Serch_Text_In_Now_Row(std::string);

		// �w�肳�ꂽ�������w�肳�ꂽ������邩�ǂ�����Ԃ��@�����F�T������s, �T�����镶���@�߂�l�F�݂�������true
		bool M_Serch_Text_In_Select_Row(int, std::string);


		//-��- ���� -��-//

		// ���I�𒆂̏ꏊ���當������v���Ă��邩�𒲂ׂ�@�߂�l�F��v�����Ƃ��̂�true
		bool M_Check_Text_Is_Eqaul_Now_Position(std::string);

		// �t�@�C�������݂��邩�ǂ�����Ԃ��@�����F�t�@�C���܂ł̃p�X�@�߂�l�F�݂�������true
		bool M_Is_File_Exist(std::string);
	};
}


#endif // !D_INCLUDE_GUARD_FILE_USER_H_FILE



/* -��- �Q�l -��-
	
	// �t�@�C�����J���ۂ̐ݒ�
	app	�e�������݁i�o�́j�̑O�ɁA�X�g���[���̍Ō�ɃV�[�N����B�iappend �̗��j
	ate	�X�g���[���̃I�[�v������ɁA�X�g���[���̍Ō�ɃV�[�N����B�iat end �̗��j
	binary	���o�͂��o�C�i���ōs���B�i�e�L�X�g���[�h�̔��΁j
	in	���͂̂��߂ɃI�[�v������B
	out	�o�͂̂��߂ɃI�[�v������B
	trunc	�����̃X�g���[�����I�[�v������ۂɁA�X�g���[���̓��e��؂�l�߂�B�itruncate �̗��j
*/


//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��

