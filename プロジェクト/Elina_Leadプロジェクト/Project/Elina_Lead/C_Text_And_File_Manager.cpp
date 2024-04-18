//����������������������������������������������//
// �ڍ�   �F�t�@�C������p�V�X�e���̃N���X
// ����   �F�t�@�C���𐶐����A�f�[�^���L�^�ł���
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include <string.h>
#include <fstream>
#include <sys/stat.h>
#include <filesystem>

#include "C_Text_And_File_Manager.h"


// �� �l�[���X�y�[�X �� //
using namespace SYSTEM::TEXT;


// �� �Z�L�����e�B�A�E�g �� //
#define _CRT_SECURE_NO_WARNINGS	// �Z�L�����e�B�ɂ��x�����s��Ȃ�


// �� �֐���` �� //

//==�� �v���C�x�[�g ��==//

//-��- �f�[�^���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���͂��ꂽ�p�X�����o�O�������N�����Ȃ����̂��ǂ����𔻒肷��
// ����   �Fstd::string & �p�X��
// �߂�l �Fbool ���������true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Is_File_Path_Succeed(std::string& in_check_path_name)
{
	// �p�X�����󕶎��Ȃ�ԈႢ
	if (in_check_path_name.size() <= 0)
	{
		return false;
	}


	// �� �p�X�����f�B���N�g�������݂��Ă��Ȃ��Ȃ炻����ԈႢ �� //
	if (M_Is_CR(in_check_path_name[0]) == true || M_Is_CR(in_check_path_name[in_check_path_name.size() - 1]) == true)
	{
		return false;
	}

	
	// �p�X���͐����ł���
	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���͂��ꂽ�p�X�����o�O�������N�����Ȃ����̂��ǂ����𔻒肷��
// ����   �Fstd::string & �p�X��
// �߂�l �Fbool ���������true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Is_Folder_Path_Is_Succeed(std::string & in_check_path_name)
{
	// �p�X�����󕶎��Ȃ�ԈႢ
	if (in_check_path_name.size() <= 0)
	{
		return false;
	}


	// �t�H���_�p�X�̈�ԍŏ������s�����Ȃ疳���J�����Ƃ��Ă���̂ŃG���[
	if (M_Is_CR(in_check_path_name[0]) == true)
	{
		return false;
	}

	// �t�H���_���͐����ł���
	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�t�@�C�����w�肳��Ă��邩�ǂ����𔻒�
// ����   �Fstd::string & �p�X��
// �߂�l �Fbool �t�@�C���܂ł̃p�X�Ȃ�true �t�H���_�Ȃǂ܂łȂ�false
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Is_File(std::string & in_check_path)
{
	// �� �f�B���N�g�����w�肳��Ă�����false �� //
	if (std::filesystem::is_directory(in_check_path) == true)
	{
		return false;
	}


	// �t�@�C���܂ł̃p�X�ł���
	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ���������s�����ł��邩�ǂ����𔻒肷��
// ����   �Fconst char & �����f�[�^
// �߂�l �Fbool true�Ȃ���s�R�[�h
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Is_CR(const char & in_check_charact)
{
	// �� ���s�R�[�h���ǂ����𔻒� �� //
	switch (in_check_charact)
	{
	// �E�B���h�E�Y�n�̉��s�R�[�h
	case '/':
		return true;

	// Unix��Linux�n�܂���MACOS�n�̉��s�R�[�h�̎��̌���
	case '\n':
		return true;

	// MACOS�n�̉��s�R�[�h�̎��̌���
	case '\r':
		return true;

	// �R���\�[���ł̎w�����
	case '\\':
		return true;
	}


	// ���s�R�[�h�ł͂Ȃ�����
	return false;
}


//==�� �p�u���b�N ��==//

//-��- �R���X�g���N�^�ƃf�X�g���N�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Text_And_File_Manager::C_Text_And_File_Manager(void)
{
	M_Reset_Data();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�[�^������
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Reset_Data(void)
{
	mpr_variable.sentence_data.clear();
	mpr_variable.sentence_data.shrink_to_fit();

	// ��s�ڂ͍쐬���Ă���
	mpr_variable.sentence_data.resize(1);

	mpr_variable.file_path.clear();
	mpr_variable.file_path.shrink_to_fit();
	mpr_variable.file_path = mpr_variable.con_default_name;
	mpr_variable.column_number = 0;
	mpr_variable.row_number = 0;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_Text_And_File_Manager::~C_Text_And_File_Manager(void)
{
	M_Reset_Data();

	return;
}


//-��- �f�[�^�ϊ� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�������10�i����INT�^�ɕϊ�����
// ����   �Fconst char * �ϊ�����f�[�^
// �߂�l �Fint �ϊ�����
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
int C_Text_And_File_Manager::M_Convert_Data_Char_To_X16INT(std::string in_data)
{
	// �� �ϐ��錾 �� //
	int result_10x_number = 0;	// �ϊ�����
	int text_size = (int)in_data.size();	// ������
	int multiple_level = 1;	// 10�i���ϊ����߂̔{��


	// �ϊ����s��
	for (int loop_x = text_size - 1; loop_x > -1; loop_x--)
	{
		// �� �ϐ��錾 �� //
		int down_data = in_data[loop_x] & 0x0f;	// ����4�r�b�g�̃f�[�^
		int top_data = in_data[loop_x] & 0xf0;	// ���4�r�b�g�̃f�[�^�i���_����4�r�b�g�͉���4�r�b�g����񑽂�16���|���Ȃ���΂Ȃ�Ȃ������o�������ɂ������ł�16�r�b�g�{�ɂȂ��Ă���@(���R�F10�i����5�r�b�g�ڂ�16������@16�i���ōl����Ə�ʂƉ��ʂŕʂ�Ă���ƍ��o���Ă��܂�)�j


		// 10�i���ɕϊ��������ʂ����Z
		result_10x_number += (top_data + down_data) * multiple_level;


		// 10���̌��̂��߂ɑ��₷
		multiple_level *= 256;
	}


	// ���ʂ�Ԃ�
	return result_10x_number;
}


//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�p�X�܂ł̃t�H���_�𐶐�����
// ����   �Fstd::string �t�@�C���܂ł̃p�X
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Create_Path_Of_Folder(std::string in_path_string)
{
	// �t�H���_�̃p�X���������Ȃ����̓X���[
	if (M_Is_Folder_Path_Is_Succeed(in_path_string) == false)
	{
		return false;
	}


	// �t�@�C����������΂����
	if (M_Is_File_Exist(in_path_string) == true)
	{
		return true;
	}


	// �� �ϐ��錾 �� //
	struct stat s_stat_fold;	// �t�H���_�T���p

	int n_text_size = (int)strlen(in_path_string.data());	// �p�X�̕�����

	bool b_succes = true;	// �t�H���_�����邩�ǂ����̃t���O


	// ��ԉ��̃t�H���_��T�����āA������΃t���O��������
	for (int n_num = n_text_size - 1; n_num >= 0; n_num--)
	{
		// �t�H���_�������Ԑ[���t�H���_������΂����T������ 
		if (M_Is_CR(in_path_string[n_num]) == true)
		{
			// �� �ϐ��錾 �� //
			char* p_search_folder_name = new char[(long long)n_num + 1];	// �T�����̃t�H���_��

			// �t�H���_����ݒ�
			for (int n_len = 0; n_len < n_num; n_len++)
			{
				p_search_folder_name[n_len] = in_path_string[n_len];
			}

			// �I�[������ǉ�
			p_search_folder_name[n_num] = '\0';

			// ��Ԑ[���t�H���_���Ȃ���ΐ����̃t���O��������
			if (stat(p_search_folder_name, &s_stat_fold) != 0)
			{
				b_succes = false;
			}

			// ���������
			delete[] p_search_folder_name;
			p_search_folder_name = nullptr;

			// ��Ԑ[���t�H���_�𔭌������̂ŏ����𔲂���
			n_num -= n_text_size;
		}
	}

	// ��Ԑ[���t�H���_�����������珈�����I������
	if (b_succes == true)
	{
		return true;
	}


	// �� �t�@�C���T�� �� //

	// �t�H���_�T��
	for (int n_num = 0; n_num < n_text_size; n_num++)
	{
		// �t�H���_�����w�肳��Ă���΃t�H���_��T�����ĂȂ���ΐ���
		if (M_Is_CR(in_path_string[n_num]) == true)
		{
			// �� �ϐ��錾 �� //
			char* p_search_folder_name = new char[(long long)n_num + 1];	// �T�����̃t�H���_��


			// �t�H���_����ݒ�
			for (int n_len = 0; n_len < n_num; n_len++)
			{
				p_search_folder_name[n_len] = in_path_string[n_len];
			}

			// �I�[������ǉ�
			p_search_folder_name[n_num] = '\0';

			// �t�H���_���Ȃ���ΐ�������
			if (stat(p_search_folder_name, &s_stat_fold) != 0)
			{
				// �� �ϐ��錾 �� //
				wchar_t* p_set_fol_name = new wchar_t[(long long)n_num + 1];	// ��������t�H���_��

				int create_result = 0;	// ��������


				// �t�H���_����ݒ�
				for (int n_len = 0; n_len < n_num; n_len++)
				{
					p_set_fol_name[n_len] = p_search_folder_name[n_len];
				}

				// �I�[������ǉ�
				p_set_fol_name[n_num] = '\0';

				
				// �t�H���_�𐶐�����
				create_result = _wmkdir(p_set_fol_name);

				
				// ���������
				delete[] p_set_fol_name;
				p_set_fol_name = nullptr;


				// �����Ɏ��s������G���[���o��
				if (create_result == -1)
				{
					delete[] p_search_folder_name;
					p_search_folder_name = nullptr;

					return false;
				}
			}

			// ���������
			delete[] p_search_folder_name;
			p_search_folder_name = nullptr;
		}
	}

	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�p�X�܂ł̃t�@�C���ƃt�H���_���Ȃ���ΐ�������
// ����   �Fstring �t�@�C���܂ł̃p�X
// �߂�l �F�������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Create_File_And_Folder_If_File_Not_Exist(std::string in_path_string)
{
	// �t�H���_�̃p�X���������Ȃ����̓X���[
	if (M_Is_Folder_Path_Is_Succeed(in_path_string) == false)
	{
		return false;
	}


	// �t�@�C����������΂����
	if (M_Is_File_Exist(in_path_string) == true)
	{
		return true;
	}


	// �� �t�H���_�𐶐����� �� //
	M_Create_Path_Of_Folder(in_path_string);


	// �t�H���_�݂̂̎w��ł���΂����Œ��f
	if (M_Is_File(in_path_string) == false)
	{
		return true;
	}


	// �� �ϐ��錾 �� //
	std::fstream creat_file(in_path_string, std::ios_base::out | std::ios_base::trunc);	// �t�@�C���ҏW�p�V�X�e��


	// �t�@�C���𐶐�����
	creat_file << "";


	// �t�@�C�������
	creat_file.close();


	// �t�@�C���܂ł̐����ɐ���
	return true;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���ꂩ��ҏW����t�@�C���̃p�X���w�肷��i�Ȃ���ΐ��������j
// ����   �Fstring �t�@�C���̃p�X
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Set_File_Path(std::string in_file_path)
{
	// �� �t�@�C�����������w�肳��Ă��Ȃ��Ȃ甲���� �� //
	if (M_Is_File_Path_Succeed(in_file_path) == false)
	{
		return false;
	}


	// �� �t�@�C����������Ȃ���΍�� �� //		// �������s�ŃG���[���o��
	if (M_Create_File_And_Folder_If_File_Not_Exist(in_file_path) == false)
	{
		return false;
	}


	// �� �w�肳�ꂽ����ݒ� �� //
	mpr_variable.file_path = in_file_path;

	// �w��ɐ���
	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�ҏW���[�h���w�肷��
// ����   �FE_EDIT_MODE �ҏW���[�h���w�肷��ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Set_Edit_Mode(E_EDIT_MODE in_set_mode)
{
	mpr_variable.mode_setting = in_set_mode;

	return;
}


//-��- �Q�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̃f�[�^�̎Q�Ƃ�n��
// ����   �Fvoid
// �߂�l �Fconst vector<string> & �f�[�^�̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const std::vector<std::string> & C_Text_And_File_Manager::M_Get_File_Data_Refer(void)
{
	return mpr_variable.sentence_data;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̃f�[�^�̎Q�Ƃ�n��
// ����   �Fvoid
// �߂�l �Fstring & �t�@�C���p�X�̎Q��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
const std::string & C_Text_And_File_Manager::M_Get_File_Path_Refer(void)
{
	return mpr_variable.file_path;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̍s�̔ԍ���Ԃ�
// ����   �Fvoid
// �߂�l �Fint ���݂̍s�̔ԍ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
int C_Text_And_File_Manager::M_Get_Now_Row(void)
{
	return mpr_variable.row_number;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̗�̔ԍ���Ԃ�
// ����   �Fvoid
// �߂�l �Fint ���݂̗�̔ԍ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
int C_Text_And_File_Manager::M_Get_Now_Column(void)
{
	return mpr_variable.column_number;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���͂̍s����Ԃ�
// ����   �Fvoid
// �߂�l �Fint ���͂̍s��
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
int C_Text_And_File_Manager::M_Get_Text_Row_Sum(void)
{
	return (int)mpr_variable.sentence_data.size();
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���I�𒆂̍s�̕�������Ԃ�
// ����   �Fvoid
// �߂�l �Fint ������
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
int C_Text_And_File_Manager::M_Get_Column_Sum_In_Now_Row(void)
{
	return (int)mpr_variable.sentence_data[mpr_variable.row_number].size();
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̕��͑S�̂̕�������Ԃ�
// ����   �Fvoid
// �߂�l �Fint ������
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
int C_Text_And_File_Manager::M_Get_Sentence_Text_Size(void)
{
	// �� �ϐ��錾 �� //
	int result_text_size = 0;	// �������̍��v
	int row_size = (int)mpr_variable.sentence_data.size(); // �s��


	return 0;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���݂̏ꏊ�̕�����Ԃ�
// ����   �Fvoid
// �߂�l �Fchar ���݂̏ꏊ�̕���
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
char C_Text_And_File_Manager::M_Get_Text_Of_Now_Position(void)
{
	return mpr_variable.sentence_data[mpr_variable.row_number][mpr_variable.column_number];
}


//-��- �Z�[�u -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���쒆�̃t�@�C���Ɍ��݂̃f�[�^���㏑���ŃZ�[�u����
// ����   �Fvoid
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Save_Data_To_Now_File(void)
{
	// �� �ϐ��錾 �� //
	std::fstream creat_file;	// �t�@�C���ҏW�p�V�X�e��

	int row_sum = (int)mpr_variable.sentence_data.size();	// �s��


	// �� �ҏW���[�h�ɂ���ď����𕪊� �� //
	switch (mpr_variable.mode_setting)
	{
		// �o�C�i���`��
	case E_EDIT_MODE::e_BINARY:
		creat_file.open(mpr_variable.file_path, std::ios::out, std::ios::binary);
		break;

		// �e�L�X�g�`��
	case E_EDIT_MODE::e_TEXT:
		creat_file.open(mpr_variable.file_path, std::ios::out);
		break;
	}


	// �ǂݎ��Ă��Ȃ�������G���[���o���Ĕ�����
	if (!creat_file)
	{
		creat_file.close();
		return false;
	}


	// �t�@�C���𐶐����邵���e����������
	for (int loop_x = 0; loop_x < row_sum; loop_x++)
	{
		creat_file << mpr_variable.sentence_data[loop_x].data();


		// �܂����ɍs������Ȃ���s
		if (loop_x + 1 < row_sum)
		{
			creat_file << "\n";
		}
	}

	// �t�@�C�������
	creat_file.close();

	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�t�@�C���Ɍ��݂̃f�[�^���㏑���ŃZ�[�u����
// ����   �Fstring �t�@�C���̃p�X
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Save_Data_To_Select_File(std::string in_file_path)
{
	// �� �t�@�C�����������w�肳��Ă��Ȃ��Ȃ甲���� �� //
	if (M_Is_File_Path_Succeed(in_file_path) == false)
	{
		return false;
	}


	// �� �ϐ��錾 �� //
	std::fstream creat_file;	// �t�@�C���ҏW�p�V�X�e��

	int row_sum = (int)mpr_variable.sentence_data.size();	// �s��


	// �� �ҏW���[�h�ɂ���ď����𕪊� �� //
	switch (mpr_variable.mode_setting)
	{
		// �o�C�i���`��
	case E_EDIT_MODE::e_BINARY:
		creat_file.open(in_file_path, std::ios::out, std::ios::binary);
		break;

		// �e�L�X�g�`��
	case E_EDIT_MODE::e_TEXT:
		creat_file.open(in_file_path, std::ios::out);
		break;
	}


	// �ǂݎ��Ă��Ȃ�������G���[���o���Ĕ�����
	if (!creat_file)
	{
		creat_file.close();
		return false;
	}


	// �t�@�C���𐶐����邵���e����������
	for (int loop_x = 0; loop_x < row_sum; loop_x++)
	{
		creat_file << mpr_variable.sentence_data[loop_x].data();


		// �܂����ɍs������Ȃ���s
		if (loop_x + 1 < row_sum)
		{
			creat_file << "\n";
		}
	}

	// �t�@�C�������
	creat_file.close();

	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���쒆�̃t�@�C���Ɍ��݂̃f�[�^��ǉ��ŃZ�[�u����
// ����   �Fvoid
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Add_Data_To_Now_File(void)
{
	// �� �ϐ��錾 �� //
	std::fstream add_file;	// �t�@�C���ҏW�p�V�X�e��

	int row_sum = (int)mpr_variable.sentence_data.size();	// �s��


	// �� �ҏW���[�h�ɂ���ď����𕪊� �� //
	switch (mpr_variable.mode_setting)
	{
		// �o�C�i���`��
	case E_EDIT_MODE::e_BINARY:
		add_file.open(mpr_variable.file_path, std::ios::app, std::ios::binary);
		break;

		// �e�L�X�g�`��
	case E_EDIT_MODE::e_TEXT:
		add_file.open(mpr_variable.file_path, std::ios::app);
		break;
	}


	// �ǂݎ��Ă��Ȃ�������G���[���o���Ĕ�����
	if (!add_file)
	{
		add_file.close();
		return false;
	}


	// �t�@�C���𐶐����邵���e����������
	for (int loop_x = 0; loop_x < row_sum; loop_x++)
	{
		add_file << mpr_variable.sentence_data[loop_x].data();


		// �܂����ɍs������Ȃ���s
		if (loop_x + 1 < row_sum)
		{
			add_file << "\n";
		}
	}

	// �t�@�C�������
	add_file.close();

	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�t�@�C���Ɍ��݂̃f�[�^��ǉ��ŃZ�[�u����
// ����   �Fstring �t�@�C���̃p�X
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Add_Data_To_Select_File(std::string in_file_path)
{
	// �� �t�@�C�����������w�肳��Ă��Ȃ��Ȃ甲���� �� //
	if (M_Is_File_Path_Succeed(in_file_path) == false)
	{
		return false;
	}


	// �� �ϐ��錾 �� //
	std::fstream add_file;	// �t�@�C���ҏW�p�V�X�e��

	int row_sum = (int)mpr_variable.sentence_data.size();	// �s��


	// �� �ҏW���[�h�ɂ���ď����𕪊� �� //
	switch (mpr_variable.mode_setting)
	{
		// �o�C�i���`��
	case E_EDIT_MODE::e_BINARY:
		add_file.open(in_file_path, std::ios::app, std::ios::binary);
		break;

		// �e�L�X�g�`��
	case E_EDIT_MODE::e_TEXT:
		add_file.open(in_file_path, std::ios::app);
		break;
	}


	// �ǂݎ��Ă��Ȃ�������G���[���o���Ĕ�����
	if (!add_file)
	{
		add_file.close();
		return false;
	}


	// �t�@�C���𐶐����邵���e����������
	for (int loop_x = 0; loop_x < row_sum; loop_x++)
	{
		add_file << mpr_variable.sentence_data[loop_x].data();


		// �܂����ɍs������Ȃ���s
		if (loop_x + 1 < row_sum)
		{
			add_file << "\n";
		}
	}

	// �t�@�C�������
	add_file.close();

	return true;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���쒆�̃t�@�C������f�[�^��ǂݍ���
// ����   �Fvoid
// �߂�l �Fbool �������̂�ture
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Load_Now_File(void)
{
	// �� �t�@�C�����������w�肳��Ă��Ȃ��Ȃ甲���� �� //
	if (M_Is_File_Path_Succeed(mpr_variable.file_path) == false)
	{
		return false;
	}


	// �� �ϐ��錾 �� //
	std::ifstream load_file;	// �t�@�C���̓ǂݎ��p�V�X�e��

	std::string data_one_line;	// ��s���̃f�[�^


	// �� �ҏW���[�h�ɂ���ď����𕪊� �� //
	switch (mpr_variable.mode_setting)
	{
		// �o�C�i���`��
	case E_EDIT_MODE::e_BINARY:
		load_file.open(mpr_variable.file_path, std::ios::in, std::ios::binary);
		break;

		// �e�L�X�g�`��
	case E_EDIT_MODE::e_TEXT:
		load_file.open(mpr_variable.file_path, std::ios::in);
		break;
	}


	// �ǂݎ��Ă��Ȃ�������G���[���o���Ĕ�����
	if (!load_file)
	{
		load_file.close();
		return false;
	}


	// �s���Ȃ���Έ�s�ǉ�
	if (mpr_variable.sentence_data.size() <= 0)
	{
		mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
	}


	// EOF(�t�@�C���̏I���)������܂Ŏ��o��������
	while (std::getline(load_file, data_one_line) && !data_one_line.empty())
	{
		// �󔒂Ȃ�X���[
		if (data_one_line.size() <= 0)
		{

		}

		// ���s�R�[�h������Ȃ���s�R�[�h�𔲂��ăf�[�^������
		else if (M_Is_CR(data_one_line[data_one_line.size() - 1]) == true)
		{
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line.substr(0, data_one_line.size() - 1);
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
		}

		// ���s�R�[�h���Ȃ��Ȃ�ʏ�ʂ�f�[�^������
		else
		{
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line;
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
		}

		// ��s�ǉ�
		mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
	}


	// �t�@�C�����Ƃ���
	load_file.close();

	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���쒆�̃t�@�C������w�肳�ꂽ�s�Ԃ����f�[�^��ǂݍ���
// ����   �Fint �ǂݎn�܂�̍s, int �ǂݏI���̍s
// �߂�l �Fbool �������̂�ture
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Load_Now_File_Only_Select_Raw(int in_start_row, int in_end_row)
{
	// �� �t�@�C�����������w�肳��Ă��Ȃ��Ȃ甲���� �� //
	if (M_Is_File_Path_Succeed(mpr_variable.file_path) == false)
	{
		return false;
	}


	// �� �ϐ��錾 �� //
	std::ifstream load_file;	// �t�@�C���̓ǂݎ��p�V�X�e��

	std::string data_one_line;	// ��s���̃f�[�^


	// �� �ҏW���[�h�ɂ���ď����𕪊� �� //
	switch (mpr_variable.mode_setting)
	{
		// �o�C�i���`��
	case E_EDIT_MODE::e_BINARY:
		load_file.open(mpr_variable.file_path, std::ios::in, std::ios::binary);
		break;

		// �e�L�X�g�`��
	case E_EDIT_MODE::e_TEXT:
		load_file.open(mpr_variable.file_path, std::ios::in);
		break;
	}


	// �ǂݎ��Ă��Ȃ�������G���[���o���Ĕ�����
	if (!load_file)
	{
		load_file.close();
		return false;
	}


	// �s���Ȃ���Έ�s�ǉ�
	if (mpr_variable.sentence_data.size() <= 0)
	{
		mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
	}


	// EOF(�t�@�C���̏I���)������܂Ŏ��o��������
	for (int loop_x = 0; std::getline(load_file, data_one_line) && !data_one_line.empty(); loop_x++)
	{
		// �n�܂�̍s�ƏI���̍s�̊Ԃ̍s�̂ݓǂݎ��
		if (in_start_row <= loop_x)
		{
			// �󔒂Ȃ�X���[
			if (data_one_line.size() <= 0)
			{

			}

			// ���s�R�[�h������Ȃ���s�R�[�h�𔲂��ăf�[�^������
			else if (M_Is_CR(data_one_line[data_one_line.size() - 1]) == true)
			{
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line.substr(0, data_one_line.size() - 1);
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
			}

			// ���s�R�[�h���Ȃ��Ȃ�ʏ�ʂ�f�[�^������
			else
			{
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line;
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
			}

			// ��s�ǉ�
			mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
		}

		// �I���̍s���������炱��ȏ�ǂݎ��Ȃ��Ă悢�̂Ńt�@�C������ďI��
		else if (in_end_row <= loop_x)
		{
			load_file.close();
			return true;
		}
	}


	// �t�@�C�����Ƃ���
	load_file.close();

	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�t�@�C������f�[�^��ǂݍ���
// ����   �Fstd::string �t�@�C���̃p�X
// �߂�l �Fbool �������̂�ture
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Load_Select_File(std::string in_file_path)
{
	// �� �t�@�C�����������w�肳��Ă��Ȃ��Ȃ甲���� �� //
	if (M_Is_File_Path_Succeed(in_file_path) == false)
	{
		return false;
	}


	// �� �t�@�C�����t�H���_���Ȃ��Ȃ�false �� //
	if (M_Is_File_Exist(in_file_path) == false)
	{
		return false;
	}



	// �� �t�@�C�����������w�肳��Ă��Ȃ��Ȃ甲���� �� //
	if (M_Is_File(in_file_path) == false)
	{
		return false;
	}


	// �� �ϐ��錾 �� //
	std::ifstream load_file;	// �t�@�C���̓ǂݎ��p�V�X�e��

	std::string data_one_line;	// ��s���̃f�[�^


	// �� �ҏW���[�h�ɂ���ď����𕪊� �� //
	switch (mpr_variable.mode_setting)
	{
		// �o�C�i���`��
	case E_EDIT_MODE::e_BINARY:
		load_file.open(in_file_path, std::ios::in, std::ios::binary);
		break;

		// �e�L�X�g�`��
	case E_EDIT_MODE::e_TEXT:
		load_file.open(in_file_path, std::ios::in);
		break;
	}


	// �ǂݎ��Ă��Ȃ�������G���[���o���Ĕ�����
	if (!load_file)
	{
		load_file.close();
		return false;
	}


	// �s���Ȃ���Έ�s�ǉ�
	if (mpr_variable.sentence_data.size() <= 0)
	{
		mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
	}


	// EOF(�t�@�C���̏I���)������܂Ŏ��o��������
	while (std::getline(load_file, data_one_line))
	{
		// �󔒂Ȃ�X���[
		if (data_one_line.size() <= 0)
		{

		}

		// ���s�R�[�h������Ȃ���s�R�[�h�𔲂��ăf�[�^������
		else if (M_Is_CR(data_one_line[data_one_line.size() - 1]) == true)
		{
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line.substr(0, data_one_line.size() - 1);
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
		}

		// ���s�R�[�h���Ȃ��Ȃ�ʏ�ʂ�f�[�^������
		else
		{
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line;
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
		}


		// ��s�ǉ�
		mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
	}


	// �t�@�C�����Ƃ���
	load_file.close();

	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�t�@�C������w�肳�ꂽ�s�Ԃ����f�[�^��ǂݍ���
// ����   �Fstd::string, int �ǂݎn�܂�̍s, int �ǂݏI���̍s
// �߂�l �Fbool �������̂�ture
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Load_Select_File_Only_Select_Raw(std::string in_file_path, int in_start_row, int in_end_row)
{
	// �� �t�@�C�����������w�肳��Ă��Ȃ��Ȃ甲���� �� //
	if (M_Is_File_Path_Succeed(in_file_path) == false)
	{
		return false;
	}


	// �� �t�@�C�����t�H���_���Ȃ��Ȃ�false �� //
	if (M_Is_File_Exist(in_file_path) == false)
	{
		return false;
	}


	// �� �t�@�C�����������w�肳��Ă��Ȃ��Ȃ甲���� �� //
	if (M_Is_File(in_file_path) == false)
	{
		return false;
	}


	// �� �ϐ��錾 �� //
	std::ifstream load_file;	// �t�@�C���̓ǂݎ��p�V�X�e��

	std::string data_one_line;	// ��s���̃f�[�^


	// �� �ҏW���[�h�ɂ���ď����𕪊� �� //
	switch (mpr_variable.mode_setting)
	{
		// �o�C�i���`��
	case E_EDIT_MODE::e_BINARY:
		load_file.open(in_file_path, std::ios::in, std::ios::binary);
		break;

		// �e�L�X�g�`��
	case E_EDIT_MODE::e_TEXT:
		load_file.open(in_file_path, std::ios::in);
		break;
	}


	// �ǂݎ��Ă��Ȃ�������G���[���o���Ĕ�����
	if (!load_file)
	{
		load_file.close();
		return false;
	}


	// �s���Ȃ���Έ�s�ǉ�
	if (mpr_variable.sentence_data.size() <= 0)
	{
		mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
	}


	// EOF(�t�@�C���̏I���)������܂Ŏ��o��������
	for (int loop_x = 0; std::getline(load_file, data_one_line) && !data_one_line.empty(); loop_x++)
	{
		// �͈͓��̎��̂ݓǂݎ��
		if (in_start_row <= loop_x)
		{
			// �󔒂Ȃ�X���[
			if (data_one_line.size() <= 0)
			{

			}

			// ���s�R�[�h������Ȃ���s�R�[�h�𔲂��ăf�[�^������
			else if (M_Is_CR(data_one_line[data_one_line.size() - 1]) == true)
			{
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line.substr(0, data_one_line.size() - 1);
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
			}

			// ���s�R�[�h���Ȃ��Ȃ�ʏ�ʂ�f�[�^������
			else
			{
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line;
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
			}


			// ��s�ǉ�
			mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
		}

		// �I���̍s���������炱��ȏ�ǂݎ��Ȃ��Ă悢�̂Ńt�@�C������ďI��
		if (in_end_row <= loop_x)
		{
			load_file.close();
			return true;
		}
	}


	// �t�@�C�����Ƃ���
	load_file.close();

	return true;
}


//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�f�[�^�����݂̑���ʒu������͂���
// ����   �Fshort ���͂���f�[�^
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Input_This_Data(short in_data)
{
	mpr_variable.sentence_data[mpr_variable.row_number].insert(mpr_variable.column_number, std::to_string(in_data));
	mpr_variable.column_number += (int)std::to_string(in_data).size();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�f�[�^�����݂̑���ʒu������͂���
// ����   �Funsigned short ���͂���f�[�^
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Input_This_Data(unsigned short in_data)
{
	mpr_variable.sentence_data[mpr_variable.row_number].insert(mpr_variable.column_number, std::to_string(in_data));
	mpr_variable.column_number += (int)std::to_string(in_data).size();

	return;
}

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�f�[�^�����݂̑���ʒu������͂���
// ����   �Fint ���͂���f�[�^
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Input_This_Data(int in_data)
{
	mpr_variable.sentence_data[mpr_variable.row_number].insert(mpr_variable.column_number, std::to_string(in_data));
	mpr_variable.column_number += (int)std::to_string(in_data).size();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�f�[�^�����݂̑���ʒu������͂���
// ����   �Funsigned int ���͂���f�[�^
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Input_This_Data(unsigned int in_data)
{
	mpr_variable.sentence_data[mpr_variable.row_number].insert(mpr_variable.column_number, std::to_string(in_data));
	mpr_variable.column_number += (int)std::to_string(in_data).size();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�f�[�^�����݂̑���ʒu������͂���
// ����   �Flong long ���͂���f�[�^
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Input_This_Data(long long in_data)
{
	mpr_variable.sentence_data[mpr_variable.row_number].insert(mpr_variable.column_number, std::to_string(in_data));
	mpr_variable.column_number += (int)std::to_string(in_data).size();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�f�[�^�����݂̑���ʒu������͂���
// ����   �Funsigned long long ���͂���f�[�^
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Input_This_Data(unsigned long long in_data)
{
	mpr_variable.sentence_data[mpr_variable.row_number].insert(mpr_variable.column_number, std::to_string(in_data));
	mpr_variable.column_number += (int)std::to_string(in_data).size();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�f�[�^�����݂̑���ʒu������͂���
// ����   �Fstd::string ���͂���f�[�^
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Input_This_Data(std::string in_data)
{
	// �� �ϐ��錾 �� //
	std::string stack_data;	// ���ʂ��T���邽�߂̃f�[�^

	int text_size = (int)in_data.size();	// ������


	// ���������s��
	for (int check_x = 0; check_x < text_size; check_x++)
	{
		// ���s�R�[�h������������s����
		if (M_Is_CR(in_data[check_x]) == true)
		{
			// �E�ɗv�f������Ȃ���s��ɂ��̗v�f���ړ������A���܂ł��߂��f�[�^�����݂̍s�Ɋi�[����
			if (mpr_variable.sentence_data[mpr_variable.row_number].size() >= mpr_variable.column_number)
			{
				mpr_variable.sentence_data.insert(mpr_variable.sentence_data.begin() + mpr_variable.row_number + 1, mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number));
				mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, mpr_variable.column_number) + stack_data;
				mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();
			}

			// �Ȃ��Ȃ���s�݂̂��s���A���܂ł��߂��f�[�^�����݂̍s�Ɋi�[����
			else
			{
				mpr_variable.sentence_data.insert(mpr_variable.sentence_data.begin() + mpr_variable.row_number + 1, "");
				mpr_variable.sentence_data[mpr_variable.row_number] += stack_data;
				mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();
			}


			// �P���̍s��I������
			mpr_variable.row_number += 1;

			// ��ԍ���I�𒆂ɂ���
			mpr_variable.column_number = 0;

			// �X�^�b�N���̃f�[�^���N���A
			stack_data.clear();
			stack_data.shrink_to_fit();
		}

		// �������Ȃ���
		else
		{
			stack_data += in_data[check_x];
		}
	}


	// �Ō�܂Ŏc�����f�[�^���i�[
	mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, mpr_variable.column_number) + stack_data + mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number);
	mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();

	// �I���ʒu���ړ�
	mpr_variable.column_number += text_size;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�f�[�^�����݂̑���ʒu������͂���
// ����   �Fdouble ���͂���f�[�^
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Input_This_Data(double in_data)
{
	mpr_variable.sentence_data[mpr_variable.row_number].insert(mpr_variable.column_number, std::to_string(in_data));
	mpr_variable.column_number += (int)std::to_string(in_data).size();

	return;
}


//-��- �폜 -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�f�[�^�𕶏͓�����w�肳�ꂽ�񐔕������폜����
// ����   �Fint �폜�񐔁i�O�őS�č폜�j, std::string �폜���镶��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Delete_Data_Equal_This_Text_In_Sentence(int in_delete_num, std::string in_delete_text)
{
	// �� �ϐ��錾 �� //
	int line_sum = (int)mpr_variable.sentence_data.size();	// �s��
	int text_size = (int)in_delete_text.size();	// �T�����镶���̕�����


	// �S�Ă̍s���J��Ԃ�
	for (int loop_row = 0; loop_row < line_sum; loop_row++)
	{
		// �� �ϐ��錾 �� //
		int column_sum = (int)mpr_variable.sentence_data[loop_row].size() - text_size;	// �T���\�ȍő��


		// �ꕶ���ڂ���v���邩���J��Ԃ��ĒT��
		for (int loop_column = 0; loop_column <= column_sum; loop_column++)
		{
			// ������������������T����������
			for (int check_x = 0; in_delete_text[check_x] == mpr_variable.sentence_data[loop_row][loop_column + check_x] && check_x < text_size; check_x++)
			{
				// ����������폜����
				if (check_x + 1 >= text_size)
				{
					// �폜�ʒu���E�ɕ������Ȃ��Ȃ�폜�ʒu�܂ł��i�[
					if (mpr_variable.sentence_data[loop_row].size() <= loop_column + text_size)
					{
						mpr_variable.sentence_data[loop_row] = mpr_variable.sentence_data[loop_row].substr(0, loop_column);
					}

					// �폜�ʒu���E�ɕ���������Ȃ�폜�ʒu�̂ݏȂ�
					else
					{
						mpr_variable.sentence_data[loop_row] = mpr_variable.sentence_data[loop_row].substr(0, loop_column) + mpr_variable.sentence_data[loop_row].substr(loop_column + text_size);
					}


					mpr_variable.sentence_data[loop_row].shrink_to_fit();


					// ���̑I���ʒu���O�̈ʒu�������ꂽ��߂�
					if (mpr_variable.row_number >= loop_row)
					{
						if (mpr_variable.column_number >= loop_column)
						{
							mpr_variable.column_number -= text_size;
						}


						// �I�𒆂̏ꏊ�����̍s���𒴂������̍s�ɖ߂�
						if (mpr_variable.column_number < 0)
						{
							mpr_variable.column_number = (int)mpr_variable.sentence_data[mpr_variable.row_number - 1].size();
						}
					}


					// �c��̍폜�񐔂����炷�A�����Ȃ���ΏI������
					in_delete_num -= 1;
					if (in_delete_num == 0)
					{
						return;
					}
				}
			}
		}
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�f�[�^��I�𒆂̍s������w�肳�ꂽ�񐔕������폜����
// ����   �Fint �폜�񐔁i�O�őS�č폜�j, std::string �폜���镶��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Delete_Data_Eqaul_This_Text_In_Now_Row(int in_delete_num, std::string in_delete_text)
{
	// �� �ϐ��錾 �� //
	int text_size = (int)in_delete_text.size();	// �T�����镶���̕�����
	int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// �T���\�ȍő��


	// �ꕶ���ڂ���v���邩���J��Ԃ��ĒT��
	for (int loop_column = 0; loop_column <= column_sum; loop_column++)
	{
		// ������������������T����������
		for (int check_x = 0; in_delete_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
		{
			// ����������폜����
			if (check_x + 1 >= text_size)
			{
				// �폜�ʒu���E�ɕ������Ȃ��Ȃ�폜�ʒu�܂ł��i�[
				if (mpr_variable.sentence_data[mpr_variable.row_number].size() <= loop_column + text_size)
				{
					mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, loop_column);
				}

				// �폜�ʒu���E�ɕ��������Ȃ�폜�ʒu�̂ݏȂ�
				else
				{
					mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, loop_column) + mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column + text_size);
				}


				mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();


				// �폜�͈͈ȍ~�ɑI�𒆂̏ꏊ����������폜�͈͕����Ɉړ�����
				if (loop_column <= mpr_variable.column_number)
				{
					mpr_variable.column_number = loop_column - 1;


					// 0�ȉ��ɂ͂Ȃ�Ȃ��悤�ɂ���
					if (mpr_variable.column_number < 0)
					{
						mpr_variable.column_number = 0;
					}
				}


				// �c��̍폜�񐔂����炷�A�����Ȃ���ΏI������
				in_delete_num -= 1;
				if (in_delete_num == 0)
				{
					return;
				}
			}
		}
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�f�[�^��I�𒆈ʒu�̉E���̍s������w�肳�ꂽ�񐔕������폜����
// ����   �Fint �폜�񐔁i�O�őS�č폜�j, std::string �폜���镶��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Delete_Data_Eqaul_This_Text_In_Now_Row_For_Right(int in_delete_num, std::string in_delete_text)
{
	// �� �ϐ��錾 �� //
	int text_size = (int)in_delete_text.size();	// �T�����镶���̕�����
	int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// �T���\�ȍő��


	// �ꕶ���ڂ���v���邩���J��Ԃ��ĒT��
	for (int loop_column = mpr_variable.column_number; loop_column <= column_sum; loop_column++)
	{
		// ������������������T����������
		for (int check_x = 0; in_delete_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
		{
			// ����������폜����
			if (check_x + 1 >= text_size)
			{
				// �폜�ʒu���E�ɕ������Ȃ��Ȃ�폜�ʒu�܂ł��i�[
				if (mpr_variable.sentence_data[mpr_variable.row_number].size() <= loop_column + text_size)
				{
					mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, loop_column);
				}

				// �폜�ʒu���E�ɕ��������Ȃ�폜�ʒu�̂ݏȂ�
				else
				{
					mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, loop_column) + mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column + text_size);
				}


				mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();


				// �폜�͈͓��ɑI�𒆂̏ꏊ����������폜�͈͂̍��Ɉړ�����
				if (loop_column <= mpr_variable.column_number && mpr_variable.column_number <= loop_column + text_size)
				{
					mpr_variable.column_number = loop_column - 1;


					// 0�ȉ��ɂ͂Ȃ�Ȃ��悤�ɂ���
					if (mpr_variable.column_number < 0)
					{
						mpr_variable.column_number = 0;
					}
				}


				// �c��̍폜�񐔂����炷�A�����Ȃ���ΏI������
				in_delete_num -= 1;
				if (in_delete_num == 0)
				{
					return;
				}
			}
		}
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�f�[�^��I�𒆈ʒu�̍����̍s������w�肳�ꂽ�񐔕������폜����
// ����   �Fint �폜�񐔁i�O�őS�č폜�j, std::string �폜���镶��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Delete_Data_Eqaul_This_Text_In_Now_Row_For_Left(int in_delete_num, std::string in_delete_text)
{
	// �� �ϐ��錾 �� //
	int text_size = (int)in_delete_text.size();	// �T�����镶���̕�����


	// �ꕶ���ڂ���v���邩���J��Ԃ��ĒT��
	for (int loop_column = mpr_variable.column_number; loop_column > -1; loop_column--)
	{
		// ������������������T����������
		for (int check_x = 0; in_delete_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
		{
			// ����������폜����
			if (check_x + 1 >= text_size)
			{
				// �폜�ʒu���E�ɕ������Ȃ��Ȃ�폜�ʒu�܂ł��i�[
				if (mpr_variable.sentence_data[mpr_variable.row_number].size() <= loop_column + text_size)
				{
					mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, loop_column);
				}

				// �폜�ʒu���E�ɕ��������Ȃ�폜�ʒu�̂ݏȂ�
				else
				{
					mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, loop_column) + mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column + text_size);
				}


				mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();


				// �폜�͈͓��ɑI�𒆂̏ꏊ����������폜�͈͂̍��Ɉړ�����
				if (loop_column <= mpr_variable.column_number && mpr_variable.column_number <= loop_column + text_size)
				{
					mpr_variable.column_number = loop_column - 1;


					// 0�ȉ��ɂ͂Ȃ�Ȃ��悤�ɂ���
					if (mpr_variable.column_number < 0)
					{
						mpr_variable.column_number = 0;
					}
				}


				// �c��̍폜�񐔂����炷
				in_delete_num -= 1;


				// �c��̍폜�񐔂������Ȃ���Ώ������I������
				if (in_delete_num == 0)
				{
					return;
				}
			}
		}
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�s���폜����
// ����   �Fint �폜����s
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Delete_Row(int in_delete_row)
{
	// �Ō�̍s�̎��͓��e�̂ݍ폜���A�P�s�͂��Ȃ炸�c��悤�ɂ���i�o�O��h�����߂Ɂj
	if (mpr_variable.sentence_data.size() == 1)
	{
		mpr_variable.sentence_data[0].clear();
		mpr_variable.sentence_data[0].shrink_to_fit();

		return;
	}


	// �폜�ʒu�����̈ʒu���O�Ȃ��s��ɂ��炷
	if (in_delete_row <= mpr_variable.row_number)
	{
		mpr_variable.row_number -= 1;


		// 0�ȉ��ɂȂ�Ȃ��悤�ɂ���
		if (mpr_variable.row_number < 0)
		{
			mpr_variable.row_number = 0;
			mpr_variable.column_number = 0;
		}

		// ���̍s���폜����Ă������s��̕��͂̈�ԉE�Ɉړ�����
		else if (in_delete_row == mpr_variable.row_number + 1)
		{
			mpr_variable.column_number = (int)mpr_variable.sentence_data[mpr_variable.row_number].size();
		}
	}

	// �͈͊O���w�肵���Ƃ��͍폜�����ɏI���
	else if (in_delete_row < 0 || (int)mpr_variable.sentence_data.size() <= in_delete_row)
	{
		return;
	}


	// �폜���s��
	mpr_variable.sentence_data.erase(mpr_variable.sentence_data.begin() + in_delete_row);
	mpr_variable.sentence_data.shrink_to_fit();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���̏ꏊ����w�肳�ꂽ�������������������폜����i�s�͂����Ȃ��j
// ����   �Fint �폜���镶����
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Delete_Column(int in_delete_num)
{
	// �� �폜���Ȃ��Ȃ�X���[ �� //
	if (in_delete_num > 0)
	{
		return;
	}


	// �� �E�����ɍ폜����Ƃ� �� //
	if (in_delete_num > 0)
	{
		// �� �폜���镶�������s���Ɏ��܂�Ȃ��Ȃ�s���܂ł��폜 �� //
		if (mpr_variable.sentence_data[mpr_variable.row_number].size() <= mpr_variable.column_number + in_delete_num)
		{
			mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, mpr_variable.column_number);
			mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();

			return;
		}


		// �s���Ɏ��܂�Ȃ�s�̊Ԃ������폜����
		mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, mpr_variable.column_number) + mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number + in_delete_num);
		mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();

		return;
	}


	// �� �������ɍ폜����Ƃ� �� //

	// �� �폜���镶�������s���Ɏ��܂�Ȃ��Ȃ�s�̂͂��܂�܂ł��폜 �� //
	if (mpr_variable.column_number - in_delete_num < 0)
	{
		mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number);
		mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();

		return;
	}


	// �s���Ŏ��܂�Ȃ�s�̊Ԃ������폜����
	mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, mpr_variable.column_number - in_delete_num) + mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number + 1);
	mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�t�@�C�����폜����
// ����   �Fvoid
// �߂�l �Fbool �폜����t�@�C����������Ȃ������A�������͎w�肳�ꂽ�p�X���f�B���N�g���������Ȃ�false
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Delete_Now_File(void)
{
	// �� �t�@�C����������Ȃ��Ȃ�G���[��Ԃ� �� //
	if (M_Is_File(mpr_variable.file_path) == false)
	{
		return false;
	}


	// �� �t�@�C�����폜���� �� //
	std::filesystem::remove(mpr_variable.file_path);


	// �폜�ɐ���
	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�t�@�C�����폜����
// ����   �Fstd::string �t�@�C���܂ł̃p�X
// �߂�l �Fbool �폜����t�@�C����������Ȃ������A�������͎w�肳�ꂽ�p�X���f�B���N�g���������Ȃ�false
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Delete_Select_File(std::string is_file_path)
{
	// �� �t�@�C����������Ȃ��Ȃ�G���[��Ԃ� �� //
	if (M_Is_File(is_file_path) == false)
	{
		return false;
	}


	// �� �t�@�C�����폜���� �� //
	std::filesystem::remove(is_file_path);


	// �폜�ɐ���
	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�t�H���_���폜����
// ����   �Fstd::string �폜����t�H���_�܂ł̃p�X
// �߂�l �Fbool �폜����t�H���_��������Ȃ�������false
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Delete_Select_Folder(std::string in_folder_path)
{
	// �� �t�H���_��������Ȃ��Ȃ�G���[��Ԃ� �� //
	if (std::filesystem::is_directory(in_folder_path) == false)
	{
		return false;
	}


	// �� �t�@�C�����폜���� �� //
	std::filesystem::remove_all(in_folder_path);


	// �폜�ɐ���
	return true;
}


//-��- �ύX -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���ݕҏW���̃t�@�C���̃t�@�C������ύX����
// ����   �Fstd::string �ύX��̃t�@�C����
// �߂�l �Fbool �ύX�ɐ���������true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Rename_Now_File(std::string in_after_name)
{
	// �� �t�@�C����������Ȃ��Ȃ�G���[��Ԃ� �� //
	if (M_Is_File(mpr_variable.file_path) == false)
	{
		return false;
	}


	// �� �t�@�C�����폜���� �� //
	std::filesystem::rename(mpr_variable.file_path, in_after_name);


	// �t�@�C���܂ł̃p�X��ύX
	mpr_variable.file_path = in_after_name;


	// �ύX�ɐ�������
	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�t�@�C���̃t�@�C������ύX����
// ����   �Fstd::string �ύX�O�̃t�@�C����, std::string �ύX��̃t�@�C����
// �߂�l �Fbool �ύX�ɐ���������true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Rename_Select_File(std::string in_before_name, std::string in_after_name)
{
	// �� �t�@�C����������Ȃ��Ȃ�G���[��Ԃ� �� //
	if (M_Is_File(in_before_name) == false)
	{
		return false;
	}


	// �� �t�@�C�����폜���� �� //
	std::filesystem::rename(in_before_name, in_after_name);


	// �ύX�ɐ�������
	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�t�H���_�̃t�H���_����ύX����
// ����   �Fstd::string �ύX�O�̃t�H���_��, std::string �ύX��̃t�H���_��
// �߂�l �Fbool �ύX�ɐ���������true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Rename_Select_Folder(std::string in_before_name, std::string in_after_name)
{
	// �� �t�H���_��������Ȃ��Ȃ�G���[��Ԃ� �� //
	if (std::filesystem::is_directory(in_before_name) == false)
	{
		return false;
	}


	// �� �t�@�C�����폜���� �� //
	std::filesystem::rename(in_before_name, in_after_name);


	// �ύX�ɐ�������
	return true;
}


//-��- �o�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F��������p�����̕⏕���s���C�����C���֐��A���l���͎��̋��ʂ̏������P�̊֐��ɂ܂Ƃ߂邽�߂Ɏg��
// ����   �Fint & �ݒ��̕ϐ�, int �ݒ肷��f�[�^
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
inline void IM_Get_Number_Setting_System(long long& in_result_number, int in_set_number)
{
	in_result_number = in_result_number * 10 + in_set_number;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���̏ꏊ�̉E�ɐ���������ꍇ�͂��̐�����Ԃ�
// ����   �Fvoid
// �߂�l �Flong long ���o�������l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
long long C_Text_And_File_Manager::M_Get_Number(void)
{
	// �� �ϐ��錾 �� //
	std::string serch_text = mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number);	// �T�����镶��

	long long result_number = 0;	// ���ʂ̐��l

	int serch_sum = (int)serch_text.size();	// �T����

	bool flg_minus = false;			// true�̎��̓}�C�i�X�l


	// �ꕶ���Â��o���Ă���
	for (int check_x = 0; check_x < serch_sum; check_x++)
	{
		// �� ���������ʂ��Đ��l�ɕϊ� �� //
		switch (serch_text[check_x])
		{
			//  0  //
		case '�O':
		case '0':
			IM_Get_Number_Setting_System(result_number, 0);
			break;

			//  1  //
		case '�P':
		case '1':
			IM_Get_Number_Setting_System(result_number, 1);
			break;

			//  2  //
		case '�Q':
		case '2':
			IM_Get_Number_Setting_System(result_number, 2);
			break;

			//  3  //
		case '�R':
		case '3':
			IM_Get_Number_Setting_System(result_number, 3);
			break;

			//  4  //
		case '�S':
		case '4':
			IM_Get_Number_Setting_System(result_number, 4);
			break;

			//  5  //
		case '�T':
		case '5':
			IM_Get_Number_Setting_System(result_number, 5);
			break;

			//  6  //
		case '�U':
		case '6':
			IM_Get_Number_Setting_System(result_number, 6);
			break;

			//  7  //
		case '�V':
		case '7':
			IM_Get_Number_Setting_System(result_number, 7);
			break;

			//  8  //
		case '�W':
		case '8':
			IM_Get_Number_Setting_System(result_number, 8);
			break;

			//  9  //
		case '�X':
		case '9':
			IM_Get_Number_Setting_System(result_number, 9);
			break;

			//  -  //
		case '-':

			// �ꕶ���ڂɃ}�C�i�X�L����������}�C�i�X�w�肷��
			if (check_x == 0)
			{
				flg_minus = true;
			}

			// �ꕶ���ڂłȂ���ΏI������
			else
			{
				return result_number * (1 - flg_minus * 2);
			}

			break;

			//  +  //
		case '+':

			// �ꕶ���ڈȍ~�Ƀv���X�L���������炻���ŏI������
			if (check_x > 0)
			{
				return result_number * (1 - flg_minus * 2);
			}

			break;

			//  ��������Ȃ������炱���ŏI���  //
		default:

			return result_number * (1 - flg_minus * 2);

			break;
		}
	}

	return result_number * (1 - flg_minus * 2);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F��������p�����̕⏕���s���C�����C���֐��A���l���͎��̋��ʂ̏������P�̊֐��ɂ܂Ƃ߂邽�߂Ɏg��
// ����   �Fint & �ݒ��̐����p�ϐ�, double & �ݒ��̏����p�ϐ�, int & ����������p�ϐ�, bool �ݒ莞�̃��[�h, int �ݒ肷��f�[�^
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
inline void IM_Get_Float_Double_Number_Setting_System(int& in_number_data, double& in_floating_data, int& in_floating_multiple_num, bool in_flg_floating_mode, int in_set_number)
{
	// ���������쎞
	if (in_flg_floating_mode == false)
	{
		in_number_data = in_number_data * 10 + in_set_number;
	}

	// ���������쎞
	else
	{
		in_floating_data = in_floating_data + (double)in_set_number / (double)in_floating_multiple_num;
		in_floating_multiple_num *= 10;
	}

	return;
}

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���̏ꏊ�̉E�ɐ���������ꍇ�͂��̏�������̐�����Ԃ�
// ����   �Fvoid
// �߂�l �Fdouble ���o�������l
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
double C_Text_And_File_Manager::M_Get_Float_Double_Number(void)
{
	// �� �ϐ��錾 �� //
	std::string string_to_float_text = mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number);	// �ϊ����镶��

	return std::stod(string_to_float_text);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���̏ꏊ����w�肳�ꂽ�������Ԃ�
// ����   �Fint ������
// �߂�l �Fstd::string �Ԃ�����
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::string C_Text_And_File_Manager::M_Get_Data_By_Number(int in_text_num)
{
	// �� �s�𒴂���Ȃ炻�̍s�̍Ō�̕����܂ł�Ԃ� �� //
	if (mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number).size() <= in_text_num + mpr_variable.column_number)
	{
		return mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number);
	}


	// �s���ő����Ȃ炻�̕���Ԃ�
	return mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number, in_text_num);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���̏ꏊ����w�肳�ꂽ�����܂ł�Ԃ�
// ����   �Fstd::string �T�����镶��
// �߂�l �Fstd::string �Ԃ������@������Ȃ������ꍇ�́A___Not_Founds___��Ԃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::string C_Text_And_File_Manager::M_Get_Data_By_Text(std::string in_search_text)
{
	// �� �ϐ��錾 �� //
	int text_size = (int)in_search_text.size();	// �T�����镶���̕�����
	int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// �T���\�ȍő��


	// �ꕶ���ڂ���v���邩���J��Ԃ��ĒT��
	for (int loop_column = mpr_variable.column_number + 1; loop_column <= column_sum; loop_column++)
	{
		// ������������������T����������
		for (int check_x = 0; in_search_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x]; check_x++)
		{
			// ���������炻���܂ł̕��͂�Ԃ�
			if (check_x + 1 >= text_size)
			{
				return mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number, loop_column - mpr_variable.column_number);
			}
		}
	}

	// �Ȃ���Δ����ł��Ȃ��������Ƃ�Ԃ�
	return "___Not_Founds___";
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�s�̎n�܂肩��I�𒆂̏ꏊ�܂ł�Ԃ�
// ����   �Fvoid
// �߂�l �Fstd::string �Ԃ�����
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::string C_Text_And_File_Manager::M_Get_Data_Left_In_Row(void)
{
	return mpr_variable.sentence_data[mpr_variable.row_number].substr(0, mpr_variable.column_number);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�I�𒆂̏ꏊ����s���܂ł�Ԃ�
// ����   �Fvoid
// �߂�l �Fstd::string �Ԃ�����
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::string C_Text_And_File_Manager::M_Get_Data_Right_In_Row(void)
{
	return mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���̑I�𒆂̍s�̎n�܂肩��I���܂ł��Ƃ�
// ����   �Fvoid
// �߂�l �Fstd::string �Ԃ�����
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::string C_Text_And_File_Manager::M_Get_Data_Now_Row(void)
{
	return mpr_variable.sentence_data[mpr_variable.row_number];
}


//-��- �ҏW�ʒu -��-//

//=�� ���ڈړ��n ��=//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���̎n�܂�Ɉړ�����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Goto_Sentence_Start(void)
{
	mpr_variable.row_number = 0;
	mpr_variable.column_number = 0;

	return;
}

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���̏I���Ɉړ�����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Goto_Sentence_End(void)
{
	// ��ԉ��̍s�ֈړ�
	mpr_variable.row_number = (int)mpr_variable.sentence_data.size() - 1;

	// �����̈ʒu���s���̍Ōォ��擾
	mpr_variable.column_number = (int)mpr_variable.sentence_data[mpr_variable.row_number].size();

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�s�̎n�܂�Ɉړ�����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Goto_Column_In_Row_Start(void)
{
	mpr_variable.column_number = 0;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�s�̏I���Ɉړ�����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Goto_Column_In_Row_End(void)
{
	mpr_variable.column_number = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - 1;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�s�̎n�܂�Ɉړ�����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Goto_Start_Row(void)
{
	mpr_variable.row_number = 0;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�s�̎n�܂�Ɉړ�����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Goto_End_Row(void)
{
	mpr_variable.row_number = (int)mpr_variable.sentence_data.size() - 1;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�s�Ɉړ�����
// ����   �F�s�̔ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Goto_Row_By_Set_Number(unsigned int in_set_row)
{
	// �l���Z�b�g����
	mpr_variable.row_number = in_set_row;


	// �s������Ă��Ȃ���Α��₷
	if (mpr_variable.sentence_data.size() <= mpr_variable.row_number)
	{
		mpr_variable.sentence_data.resize(mpr_variable.row_number + 1);
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�s�Ɉړ�����
// ����   �F��̔ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Goto_Column_By_Set_Number(unsigned int in_set_column)
{
	// �l���Z�b�g����
	mpr_variable.column_number = in_set_column;


	// �񂪑���Ă��Ȃ���Α��₷
	if (mpr_variable.sentence_data[mpr_variable.row_number].size() <= mpr_variable.column_number)
	{
		mpr_variable.sentence_data[mpr_variable.row_number].resize(mpr_variable.column_number + 1);
	}

	return;
}


//=�� �Ԑڈړ��n ��==//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�����A�ړ�����
// ����   �F�ړ���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Move_Position_By_Number(int in_move_num)
{
	// �� �ړ����Ȃ����̓X���[ �� //
	if (in_move_num == 0)
	{
		return;
	}


	// �� �ړ����{�����̎� �� //
	if (in_move_num > 0)
	{
		// �� ���̏ꏊ����̔��� �� //

		// �s���Ŏ��܂�Ȃ����ړ����ړ�������
		if (mpr_variable.column_number + in_move_num <= mpr_variable.sentence_data[mpr_variable.row_number].size())
		{
			mpr_variable.column_number += in_move_num;

			return;
		}


		// �T���������炷
		in_move_num -= (int)mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number).size();


		// ���܂�Ȃ��Ȃ牽��ڂ܂ōs������T������
		for (mpr_variable.row_number += 1; mpr_variable.row_number < mpr_variable.sentence_data.size(); mpr_variable.row_number++)
		{
			// ���̍s���Ŏ��܂�Ȃ����c��̕��ɐݒ�
			if (in_move_num < mpr_variable.sentence_data[mpr_variable.row_number].size())
			{
				mpr_variable.column_number = in_move_num;

				return;
			}


			// �T���������炷
			in_move_num -= (int)mpr_variable.sentence_data[mpr_variable.row_number].size();
		}


		// �Ō�܂ŒT�������̂ɂ܂�������������ꍇ�͍Ō�̏ꏊ�őł��؂�
		mpr_variable.row_number = (int)mpr_variable.sentence_data.size() - 1;
		mpr_variable.column_number = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - 1;

		return;
	}


	// �� �ړ���-�����̎� �� //

	// �{�Ŕ��f��������������₷���̂ŕϊ�
	in_move_num *= -1;


	// �s���Ŏ��܂�Ȃ����ړ����ړ�������
	if (mpr_variable.column_number - in_move_num > -1)
	{
		mpr_variable.column_number -= in_move_num;

		return;
	}


	// �T���������炷
	in_move_num -= (int)mpr_variable.sentence_data[mpr_variable.row_number].substr(0, mpr_variable.column_number).size();


	// ����Ŏ��܂�Ȃ��Ȃ牽��ڂ܂ōs������T������
	for (mpr_variable.row_number -= 1; mpr_variable.row_number > -1; mpr_variable.row_number--)
	{
		// �s���Ŏ��܂�Ȃ����ړ����ړ�������
		if (mpr_variable.sentence_data[mpr_variable.row_number].size() - in_move_num > 0)
		{
			mpr_variable.column_number = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - (1 + in_move_num);

			return;
		}


		// �T���������炷
		in_move_num -= (int)mpr_variable.sentence_data[mpr_variable.row_number].size();
	}


	// ��ԍŏ����������w�肳��Ă������ԍŏ��ł����
	mpr_variable.row_number = 0;
	mpr_variable.column_number = 0;

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�����A�ړ�����
// ����   �F�ړ���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Move_Raw_By_Number(int in_move_row_num)
{
	// �� �ړ����Ȃ����̓X���[ �� //
	if (in_move_row_num == 0)
	{
		return;
	}


	// �� �ړ����{�����̎� �� //
	if (in_move_row_num > 0)
	{
		// ����𒴂���Ȃ�Ō�̍s�𒼐ڎw��
		if (mpr_variable.row_number + (int)in_move_row_num > mpr_variable.sentence_data.size())
		{
			mpr_variable.row_number = (int)mpr_variable.sentence_data.size();

			return;
		}


		// �����Ȃ��Ȃ�w�蕪�ړ�������
		mpr_variable.row_number += in_move_row_num;

		return;
	}


	// �� �ړ���-�����̎� �� //

	// �{�Ŕ��f��������������₷���̂ŕϊ�
	in_move_row_num *= -1;


	// �����Ȃ��Ȃ�w�蕪�ړ�������
	mpr_variable.row_number -= in_move_row_num;


	// ��ԏ�𒴂���Ȃ�ŏ��̍s�𒼐ڎw��
	if (mpr_variable.row_number < 0)
	{
		mpr_variable.row_number = 0;

		return;
	}

	return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���̍s�ֈړ�����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_Text_And_File_Manager::M_Move_Next_Raw(void)
{
	M_Move_Raw_By_Number(1);
	M_Goto_Column_By_Set_Number(0);

	return;
}


//=�� �T���ړ��n ��=//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȍ~�ň�ԋ߂����̂𕶏͂���(���s���܂߂�)�T�����āA���̕����̉E�Ɉړ�����
// ����   �Fstring �T�����镶��
// �߂�l �Fbool �݂���Ȃ����false
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Goto_Right_By_Text_In_Front_Sentence(std::string in_serch_text)
{
	// �� �ϐ��錾 �� //
	int line_sum = (int)mpr_variable.sentence_data.size();	// �s��
	int text_size = (int)in_serch_text.size();	// �T�����镶���̕�����


	// �� �I�𒆂̍s�̎��̒T�� �� //
	{
		// �� �ϐ��錾 �� //
		int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size();	// �T���\�ȍő��


		// �ꕶ���ڂ���v���邩���J��Ԃ��ĒT��
		for (int loop_column = mpr_variable.column_number; loop_column <= column_sum; loop_column++)
		{
			// �� �ϐ��錾 �� //
			std::string stack_check_string = mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column);	// �T���p������X�^�b�N

			int stack_size = (int)stack_check_string.size();	// �X�^�b�N�f�[�^�̃T�C�Y
			int now_row_number = mpr_variable.row_number;	// ���̍s�̔ԍ�
			int indented_time = 0;	// ���s������

			bool flg_not_this = false;	// �f�[�^�������łȂ�����\���t���O


			// ������������������T����������
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// ���s�R�[�h������Ȃ玟�̍s��ǂݍ���
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// ���̍s������Ȃ���s
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ���̍s���K�v�Ȃ̂ɂȂ��Ȃ炱�̕����̔�����Ō�ɂ���
					else
					{
						flg_not_this = true;
					}
				}


				// �Ⴄ�Ȃ�T������߂�
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// ���������炻���Ɉړ����ďI��
				else if (check_x + 1 >= text_size)
				{
					// ���s���Ă��Ȃ������當�������ړ�
					if (indented_time == 0)
					{
						mpr_variable.column_number = loop_column + text_size;
					}

					// ���s���Ă����猻�݂̒T���ʒu��T���Ĉړ�
					else
					{
						text_size -= (int)mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column).size();

						for (int indent_cnt = 1; indent_cnt < indented_time; indent_cnt++)
						{
							text_size -= (int)mpr_variable.sentence_data[mpr_variable.row_number + indent_cnt].size();
						}

						mpr_variable.column_number = text_size;
					}

					mpr_variable.row_number = now_row_number;

					return true;
				}


				// ���̈�s���Ō�̕����𒴂���Ȃ���s����
				if (check_x + 1 >= stack_size)
				{
					// ���̍s������Ȃ���s
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ���̍s���K�v�Ȃ̂ɂȂ��Ȃ炱�̕����̔�����Ō�ɂ���
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}


	// ���̍s����w�肳�ꂽ������T������
	for (int loop_row = mpr_variable.row_number + 1; loop_row < line_sum; loop_row++)
	{
		// �� �ϐ��錾 �� //
		int column_sum = (int)mpr_variable.sentence_data[loop_row].size();	// �T���\�ȍő��


		// �����s�ɂ��邩�ǂ����𔻒肷��
		for (int loop_column = 0; loop_column <= column_sum; loop_column++)
		{
			// �� �ϐ��錾 �� //
			std::string stack_check_string = mpr_variable.sentence_data[loop_row].substr(loop_column);	// �T���p������X�^�b�N

			int stack_size = (int)stack_check_string.size();	// �X�^�b�N�f�[�^�̃T�C�Y
			int now_row_number = loop_row;	// ���̍s�̔ԍ�
			int indented_time = 0;	// ���s������

			bool flg_not_this = false;	// �f�[�^�������łȂ�����\���t���O


			// ������������������T����������
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// ���s�R�[�h������Ȃ玟�̍s��ǂݍ���
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// ���̍s������Ȃ���s
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ���̍s���K�v�Ȃ̂ɂȂ��Ȃ炱�̕����̔�����Ō�ɂ���
					else
					{
						flg_not_this = true;
					}
				}


				// �Ⴄ�Ȃ�T������߂�
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// ���������炻���Ɉړ����ďI��
				else if (check_x + 1 >= text_size)
				{
					// ���s���Ă��Ȃ������當�������ړ�
					if (indented_time == 0)
					{
						mpr_variable.column_number = loop_column + text_size;
					}

					// ���s���Ă����猻�݂̒T���ʒu��T���Ĉړ�
					else
					{
						text_size -= (int)mpr_variable.sentence_data[loop_row].substr(loop_column).size();

						for (int indent_cnt = 1; indent_cnt < indented_time; indent_cnt++)
						{
							text_size -= (int)mpr_variable.sentence_data[loop_row + indent_cnt].size();
						}

						mpr_variable.column_number = text_size;
					}

					mpr_variable.row_number = now_row_number;

					return true;
				}


				// ���̈�s���Ō�̕����𒴂���Ȃ���s����
				if (check_x + 1 >= stack_size)
				{
					// ���̍s������Ȃ���s
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ���̍s���K�v�Ȃ̂ɂȂ��Ȃ炱�̕����̔�����Ō�ɂ���
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}

	// �݂���Ȃ�����
	return false;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȑO�ň�ԋ߂����̂𕶏͂���(���s���܂߂�)�T�����āA���̕����̉E�Ɉړ�����
// ����   �Fstd::string �T�����镶��
// �߂�l �Fbool �݂���Ȃ����false
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Goto_Right_By_Text_In_Back_Sentence(std::string in_serch_text)
{
	// �� �ϐ��錾 �� //
	int line_sum = (int)mpr_variable.sentence_data.size();	// �s��
	int text_size = (int)in_serch_text.size();	// �T�����镶���̕�����


	// �� �I�𒆂̍s�̎��̒T�� �� //
	{
		// �� �ϐ��錾 �� //
		int start_column = (int)mpr_variable.sentence_data[mpr_variable.row_number].size();	// �T���J�n�ʒu


		// �ʏ펞�̒T���J�n�ʒu���I���ʒu�����ł���ΒT���J�n�ʒu�����炷
		if (mpr_variable.column_number <= start_column)
		{
			start_column = mpr_variable.column_number - 1;
		}


		// �ꕶ���ڂ���v���邩���J��Ԃ��ĒT��
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			// �� �ϐ��錾 �� //
			std::string stack_check_string = mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column);	// �T���p������X�^�b�N

			int stack_size = (int)stack_check_string.size();	// �X�^�b�N�f�[�^�̃T�C�Y
			int now_row_number = mpr_variable.row_number;	// ���̍s�̔ԍ�
			int indented_time = 0;	// ���s������

			bool flg_not_this = false;	// �f�[�^�������łȂ�����\���t���O


			// ������������������T����������
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// ���s�R�[�h������Ȃ玟�̍s��ǂݍ���
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// ���̍s������Ȃ���s
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ���̍s���K�v�Ȃ̂ɂȂ��Ȃ炱�̕����̔�����Ō�ɂ���
					else
					{
						flg_not_this = true;
					}
				}


				// �Ⴄ�Ȃ�T������߂�
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// ���������炻���Ɉړ����ďI��
				else if (check_x + 1 >= text_size)
				{
					// ���s���Ă��Ȃ������當�������ړ�
					if (indented_time == 0)
					{
						mpr_variable.column_number = loop_column + text_size;
					}

					// ���s���Ă����猻�݂̒T���ʒu��T���Ĉړ�
					else
					{
						text_size -= (int)mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column).size();

						for (int indent_cnt = 1; indent_cnt < indented_time; indent_cnt++)
						{
							text_size -= (int)mpr_variable.sentence_data[mpr_variable.row_number + indent_cnt].size();
						}

						mpr_variable.column_number = text_size;
					}

					mpr_variable.row_number = now_row_number;

					return true;
				}


				// ���̈�s���Ō�̕����𒴂���Ȃ���s����
				if (check_x + 1 >= stack_size)
				{
					// ���̍s������Ȃ���s
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ���̍s���K�v�Ȃ̂ɂȂ��Ȃ炱�̕����̔�����Ō�ɂ���
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}


	// ��O�̍s����w�肳�ꂽ������T������
	for (int loop_row = mpr_variable.row_number - 1; loop_row > -1; loop_row--)
	{
		// �� �ϐ��錾 �� //
		int start_column = (int)mpr_variable.sentence_data[loop_row].size();	// �T���J�n�ʒu


		// �ꕶ���ڂ���v���邩���J��Ԃ��ĒT��
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			// �� �ϐ��錾 �� //
			std::string stack_check_string = mpr_variable.sentence_data[loop_row].substr(loop_column);	// �T���p������X�^�b�N

			int stack_size = (int)stack_check_string.size();	// �X�^�b�N�f�[�^�̃T�C�Y
			int now_row_number = loop_row;	// ���̍s�̔ԍ�
			int indented_time = 0;	// ���s������

			bool flg_not_this = false;	// �f�[�^�������łȂ�����\���t���O


			// ������������������T����������
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// ���s�R�[�h������Ȃ玟�̍s��ǂݍ���
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// ���̍s������Ȃ���s
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ���̍s���K�v�Ȃ̂ɂȂ��Ȃ炱�̕����̔�����Ō�ɂ���
					else
					{
						flg_not_this = true;
					}
				}


				// �Ⴄ�Ȃ�T������߂�
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// ���������炻���Ɉړ����ďI��
				else if (check_x + 1 >= text_size)
				{
					// ���s���Ă��Ȃ������當�������ړ�
					if (indented_time == 0)
					{
						mpr_variable.column_number = loop_column + text_size;
					}

					// ���s���Ă����猻�݂̒T���ʒu��T���Ĉړ�
					else
					{
						text_size -= (int)mpr_variable.sentence_data[loop_row].substr(loop_column).size();

						for (int indent_cnt = 1; indent_cnt < indented_time; indent_cnt++)
						{
							text_size -= (int)mpr_variable.sentence_data[loop_row + indent_cnt].size();
						}

						mpr_variable.column_number = text_size;
					}

					mpr_variable.row_number = now_row_number;

					return true;
				}


				// ���̈�s���Ō�̕����𒴂���Ȃ���s����
				if (check_x + 1 >= stack_size)
				{
					// ���̍s������Ȃ���s
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ���̍s���K�v�Ȃ̂ɂȂ��Ȃ炱�̕����̔�����Ō�ɂ���
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}

	// �݂���Ȃ�����
	return false;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȍ~�ň�ԋ߂����̂��s���ƂɁi���s�͊܂߂��Ɂj�T�����āA���̕����̉E�Ɉړ�����
// ����   �Fstd::string �T�����镶��
// �߂�l �Fbool �݂���Ȃ����false
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Goto_Right_By_Text_In_Front_Row(std::string in_serch_text)
{
	// �� �ϐ��錾 �� //
	int line_sum = (int)mpr_variable.sentence_data.size();	// �s��
	int text_size = (int)in_serch_text.size();	// �T�����镶���̕�����


	// �� �I�𒆂̍s�̎��̒T�� �� //
	{
		// �� �ϐ��錾 �� //
		int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// �T���\�ȍő��


		// �ꕶ���ڂ���v���邩���J��Ԃ��ĒT��
		for (int loop_column = mpr_variable.column_number; loop_column <= column_sum; loop_column++)
		{
			// ������������������T����������
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
			{
				// ���������炻���Ɉړ����ďI��
				if (check_x + 1 >= text_size)
				{
					mpr_variable.column_number = loop_column + text_size;

					return true;
				}
			}
		}
	}


	// ���̍s����w�肳�ꂽ������T������
	for (int loop_row = mpr_variable.row_number + 1; loop_row < line_sum; loop_row++)
	{
		// �� �ϐ��錾 �� //
		int column_sum = (int)mpr_variable.sentence_data[loop_row].size() - text_size;	// �T���\�ȍő��


		// �ꕶ���ڂ���v���邩���J��Ԃ��ĒT��
		for (int loop_column = 0; loop_column <= column_sum; loop_column++)
		{
			// ������������������T����������
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[loop_row][loop_column + check_x] && check_x < text_size; check_x++)
			{
				// ���������炻���Ɉړ����ďI��
				if (check_x + 1 >= text_size)
				{
					mpr_variable.row_number = loop_row;
					mpr_variable.column_number = loop_column + text_size;

					return true;
				}
			}
		}
	}

	// �݂���Ȃ�����
	return false;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȑO�ň�ԋ߂����̂��s���ƂɁi���s�͊܂߂��Ɂj�T�����āA���̕����̉E�Ɉړ�����
// ����   �Fstd::string �T�����镶��
// �߂�l �Fbool �݂���Ȃ����false
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Goto_Right_By_Text_In_Back_Row(std::string in_serch_text)
{
	// �� �ϐ��錾 �� //
	int text_size = (int)in_serch_text.size();	// �T�����镶���̕�����


	// �� �I�𒆂̍s�̎��̒T�� �� //
	{
		// �� �ϐ��錾 �� //
		int start_column = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// �T���J�n�ʒu


		// �ʏ펞�̒T���J�n�ʒu���I���ʒu�����ł���ΒT���J�n�ʒu�����炷
		if (mpr_variable.column_number <= start_column)
		{
			start_column = mpr_variable.column_number - 1;
		}


		// �ꕶ���ڂ���v���邩���J��Ԃ��ĒT��
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			// ������������������T����������
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
			{
				// ���������炻���Ɉړ����ďI��
				if (check_x + 1 >= text_size)
				{
					// �����ꏊ�ɋA���Ă��Ă��Ȃ���Έړ�����i�A�����ꍇ�͂����ŃX���[����΃��[�v�𔲂���j
					if (mpr_variable.column_number != loop_column + text_size)
					{
						mpr_variable.column_number = loop_column + text_size;

						return true;
					}
				}
			}
		}
	}


	// ��O�̍s����w�肳�ꂽ������T������
	for (int loop_row = mpr_variable.row_number - 1; loop_row > -1; loop_row--)
	{
		// �� �ϐ��錾 �� //
		int start_column = (int)mpr_variable.sentence_data[loop_row].size() - text_size;	// �T���J�n�ʒu


		// �ʏ펞�̒T���J�n�ʒu���I���ʒu�����ł���ΒT���J�n�ʒu�����炷
		if (mpr_variable.column_number <= start_column)
		{
			start_column = mpr_variable.column_number - 1;
		}


		// �ꕶ���ڂ���v���邩���J��Ԃ��ĒT��
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			// ������������������T����������
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[loop_row][loop_column + check_x] && check_x < text_size; check_x++)
			{
				// ���������炻���Ɉړ����ďI��
				if (check_x + 1 >= text_size)
				{
					mpr_variable.row_number = loop_row;
					mpr_variable.column_number = loop_column + text_size;

					return true;
				}
			}
		}
	}

	// �݂���Ȃ�����
	return false;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȑO�ň�ԋ߂����̂��s���ƂɁi���s�͊܂߂��Ɂj�T�����āA���̕����̉E�Ɉړ�����
// ����   �Fstd::string �T�����镶��
// �߂�l �Fbool �݂���Ȃ����false
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Goto_Right_By_Text_In_Front_Column(std::string in_serch_text)
{
	// �� �ϐ��錾 �� //
	int text_size = (int)in_serch_text.size();	// �T�����镶���̕�����
	int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// �T���\�ȍő��


	// �ꕶ���ڂ���v���邩���J��Ԃ��ĒT��
	for (int loop_column = mpr_variable.column_number; loop_column <= column_sum; loop_column++)
	{
		// ������������������T����������
		for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
		{
			// ���������炻���Ɉړ����ďI��
			if (check_x + 1 >= text_size)
			{
				mpr_variable.column_number = loop_column + text_size;

				return true;
			}
		}
	}

	// �݂���Ȃ�����
	return false;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȑO�ň�ԋ߂����̂��s���ƂɁi���s�͊܂߂��Ɂj�T�����āA���̕����̉E�Ɉړ�����
// ����   �Fstd::string �T�����镶��
// �߂�l �Fbool �݂���Ȃ����false
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Goto_Right_By_Text_In_Back_Column(std::string in_serch_text)
{
	// �� �ϐ��錾 �� //
	int text_size = (int)in_serch_text.size();	// �T�����镶���̕�����
	int start_column = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// �T���J�n�ʒu


	// �ʏ펞�̒T���J�n�ʒu���I���ʒu�����ł���ΒT���J�n�ʒu�����炷
	if (mpr_variable.column_number <= start_column)
	{
		start_column = mpr_variable.column_number - 1;
	}


	// �ꕶ���ڂ���v���邩���J��Ԃ��ĒT��
	for (int loop_column = start_column; loop_column > -1; loop_column--)
	{
		// ������������������T����������
		for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
		{
			// ���������炻���Ɉړ����ďI��
			if (check_x + 1 >= text_size)
			{
				// �����ꏊ�ɋA���Ă��Ă��Ȃ���Έړ�����i�A�����ꍇ�͂����ŃX���[����΃��[�v�𔲂���j
				if (mpr_variable.column_number != loop_column + text_size)
				{
					mpr_variable.column_number = loop_column + text_size;

					return true;
				}
			}
		}
	}

	// �݂���Ȃ�����
	return false;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȍ~�ň�ԋ߂����̂𕶏͂���(���s���܂߂�)�T�����āA���̕����̍��Ɉړ�����
// ����   �Fstd::string �T�����镶��
// �߂�l �Fbool �݂���Ȃ����false
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Goto_Left_By_Text_In_Front_Sentence(std::string in_serch_text)
{
	// �� �ϐ��錾 �� //
	int line_sum = (int)mpr_variable.sentence_data.size();	// �s��
	int text_size = (int)in_serch_text.size();	// �T�����镶���̕�����


	// �� �I�𒆂̍s�̎��̒T�� �� //
	{
		// �� �ϐ��錾 �� //
		int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size();	// �T���\�ȍő��


		// �ꕶ���ڂ���v���邩���J��Ԃ��ĒT��
		for (int loop_column = mpr_variable.column_number + 1; loop_column <= column_sum; loop_column++)
		{
			// �� �ϐ��錾 �� //
			std::string stack_check_string = mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column);	// �T���p������X�^�b�N

			int stack_size = (int)stack_check_string.size();	// �X�^�b�N�f�[�^�̃T�C�Y
			int now_row_number = mpr_variable.row_number;	// ���̍s�̔ԍ�
			int indented_time = 0;	// ���s������

			bool flg_not_this = false;	// �f�[�^�������łȂ�����\���t���O


			// ������������������T����������
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// ���s�R�[�h������Ȃ玟�̍s��ǂݍ���
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// ���̍s������Ȃ���s
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ���̍s���K�v�Ȃ̂ɂȂ��Ȃ炱�̕����̔�����Ō�ɂ���
					else
					{
						flg_not_this = true;
					}
				}


				// �Ⴄ�Ȃ�T������߂�
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// ���������炻���Ɉړ����ďI��
				else if (check_x + 1 >= text_size)
				{
					// ���s���Ă��Ȃ������當�������ړ�
					if (indented_time == 0)
					{
						mpr_variable.column_number = loop_column + text_size;
					}

					// ���s���Ă����猻�݂̒T���ʒu��T���Ĉړ�
					else
					{
						text_size -= (int)mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column).size();

						for (int indent_cnt = 1; indent_cnt < indented_time; indent_cnt++)
						{
							text_size -= (int)mpr_variable.sentence_data[mpr_variable.row_number + indent_cnt].size();
						}

						mpr_variable.column_number = text_size;
					}

					mpr_variable.row_number = now_row_number;

					return true;
				}


				// ���̈�s���Ō�̕����𒴂���Ȃ���s����
				if (check_x + 1 >= stack_size)
				{
					// ���̍s������Ȃ���s
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ���̍s���K�v�Ȃ̂ɂȂ��Ȃ炱�̕����̔�����Ō�ɂ���
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}


	// ���̍s����w�肳�ꂽ������T������
	for (int loop_row = mpr_variable.row_number + 1; loop_row < line_sum; loop_row++)
	{
		// �� �ϐ��錾 �� //
		int column_sum = (int)mpr_variable.sentence_data[loop_row].size();	// �T���\�ȍő��


		// �����s�ɂ��邩�ǂ����𔻒肷��
		for (int loop_column = 0; loop_column <= column_sum; loop_column++)
		{
			// �� �ϐ��錾 �� //
			std::string stack_check_string = mpr_variable.sentence_data[loop_row].substr(loop_column);	// �T���p������X�^�b�N

			int stack_size = (int)stack_check_string.size();	// �X�^�b�N�f�[�^�̃T�C�Y
			int now_row_number = loop_row;	// ���̍s�̔ԍ�
			int indented_time = 0;	// ���s������

			bool flg_not_this = false;	// �f�[�^�������łȂ�����\���t���O


			// ������������������T����������
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// ���s�R�[�h������Ȃ玟�̍s��ǂݍ���
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// ���̍s������Ȃ���s
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ���̍s���K�v�Ȃ̂ɂȂ��Ȃ炱�̕����̔�����Ō�ɂ���
					else
					{
						flg_not_this = true;
					}
				}


				// �Ⴄ�Ȃ�T������߂�
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// ���������炻���Ɉړ����ďI��
				else if (check_x + 1 >= text_size)
				{
					// ���s���Ă��Ȃ������當�������ړ�
					if (indented_time == 0)
					{
						mpr_variable.column_number = loop_column + text_size;
					}

					// ���s���Ă����猻�݂̒T���ʒu��T���Ĉړ�
					else
					{
						text_size -= (int)mpr_variable.sentence_data[loop_row].substr(loop_column).size();

						for (int indent_cnt = 1; indent_cnt < indented_time; indent_cnt++)
						{
							text_size -= (int)mpr_variable.sentence_data[loop_row + indent_cnt].size();
						}

						mpr_variable.column_number = text_size;
					}

					mpr_variable.row_number = now_row_number;

					return true;
				}


				// ���̈�s���Ō�̕����𒴂���Ȃ���s����
				if (check_x + 1 >= stack_size)
				{
					// ���̍s������Ȃ���s
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ���̍s���K�v�Ȃ̂ɂȂ��Ȃ炱�̕����̔�����Ō�ɂ���
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}

	// �݂���Ȃ�����
	return false;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȑO�ň�ԋ߂����̂𕶏͂���(���s���܂߂�)�T�����āA���̕����̍��Ɉړ�����
// ����   �Fstd::string �T�����镶��
// �߂�l �Fbool �݂���Ȃ����false
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Goto_Left_By_Text_In_Back_Sentence(std::string in_serch_text)
{
	// �� �ϐ��錾 �� //
	int line_sum = (int)mpr_variable.sentence_data.size();	// �s��
	int text_size = (int)in_serch_text.size();	// �T�����镶���̕�����


	// �� �I�𒆂̍s�̎��̒T�� �� //
	{
		// �� �ϐ��錾 �� //
		int start_column = (int)mpr_variable.sentence_data[mpr_variable.row_number].size();	// �T���J�n�ʒu


		// �ʏ펞�̒T���J�n�ʒu���I���ʒu�����ł���ΒT���J�n�ʒu�����炷
		if (mpr_variable.column_number <= start_column)
		{
			start_column = mpr_variable.column_number - 1;
		}


		// �ꕶ���ڂ���v���邩���J��Ԃ��ĒT��
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			// �� �ϐ��錾 �� //
			std::string stack_check_string = mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column);	// �T���p������X�^�b�N

			int stack_size = (int)stack_check_string.size();	// �X�^�b�N�f�[�^�̃T�C�Y
			int now_row_number = mpr_variable.row_number;	// ���̍s�̔ԍ�

			bool flg_not_this = false;	// �f�[�^�������łȂ�����\���t���O


			// ������������������T����������
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// ���s�R�[�h������Ȃ玟�̍s��ǂݍ���
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// ���̍s������Ȃ���s
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ���̍s���K�v�Ȃ̂ɂȂ��Ȃ炱�̕����̔�����Ō�ɂ���
					else
					{
						flg_not_this = true;
					}
				}


				// �Ⴄ�Ȃ�T������߂�
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// ���������炻���Ɉړ����ďI��
				else if (check_x + 1 >= text_size)
				{
					mpr_variable.row_number = now_row_number;
					mpr_variable.column_number = loop_column;

					return true;
				}


				// ���̈�s���Ō�̕����𒴂���Ȃ���s����
				if (check_x + 1 >= stack_size)
				{
					// ���̍s������Ȃ���s
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ���̍s���K�v�Ȃ̂ɂȂ��Ȃ炱�̕����̔�����Ō�ɂ���
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}


	// ��O�̍s����w�肳�ꂽ������T������
	for (int loop_row = mpr_variable.row_number - 1; loop_row > -1; loop_row--)
	{
		// �� �ϐ��錾 �� //
		int start_column = (int)mpr_variable.sentence_data[loop_row].size();	// �T���J�n�ʒu


		// �ꕶ���ڂ���v���邩���J��Ԃ��ĒT��
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			// �� �ϐ��錾 �� //
			std::string stack_check_string = mpr_variable.sentence_data[loop_row].substr(loop_column);	// �T���p������X�^�b�N

			int stack_size = (int)stack_check_string.size();	// �X�^�b�N�f�[�^�̃T�C�Y
			int now_row_number = loop_row;	// ���̍s�̔ԍ�

			bool flg_not_this = false;	// �f�[�^�������łȂ�����\���t���O


			// ������������������T����������
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// ���s�R�[�h������Ȃ玟�̍s��ǂݍ���
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// ���̍s������Ȃ���s
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ���̍s���K�v�Ȃ̂ɂȂ��Ȃ炱�̕����̔�����Ō�ɂ���
					else
					{
						flg_not_this = true;
					}
				}


				// �Ⴄ�Ȃ�T������߂�
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// ���������炻���Ɉړ����ďI��
				else if (check_x + 1 >= text_size)
				{
					mpr_variable.row_number = now_row_number;
					mpr_variable.column_number = loop_column;

					return true;
				}


				// ���̈�s���Ō�̕����𒴂���Ȃ���s����
				if (check_x + 1 >= stack_size)
				{
					// ���̍s������Ȃ���s
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ���̍s���K�v�Ȃ̂ɂȂ��Ȃ炱�̕����̔�����Ō�ɂ���
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}

	// �݂���Ȃ�����
	return false;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȍ~�ň�ԋ߂����̂��s���ƂɁi���s�͊܂߂��Ɂj�T�����āA���̕����̍��Ɉړ�����
// ����   �Fstd::string �T�����镶��
// �߂�l �Fbool �݂���Ȃ����false
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Goto_Left_By_Text_In_Front_Row(std::string in_serch_text)
{
	// �� �ϐ��錾 �� //
	int line_sum = (int)mpr_variable.sentence_data.size();	// �s��
	int text_size = (int)in_serch_text.size();	// �T�����镶���̕�����


	// �� �I�𒆂̍s�̎��̒T�� �� //
	{
		// �� �ϐ��錾 �� //
		int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// �T���\�ȍő��


		// �ꕶ���ڂ���v���邩���J��Ԃ��ĒT��
		for (int loop_column = mpr_variable.column_number + 1; loop_column <= column_sum; loop_column++)
		{
			// ������������������T����������
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
			{
				// ���������炻���Ɉړ����ďI��
				if (check_x + 1 >= text_size)
				{
					mpr_variable.column_number = loop_column;

					return true;
				}
			}
		}
	}


	// ���̍s����w�肳�ꂽ������T������
	for (int loop_row = mpr_variable.row_number + 1; loop_row < line_sum; loop_row++)
	{
		// �� �ϐ��錾 �� //
		int column_sum = (int)mpr_variable.sentence_data[loop_row].size() - text_size;	// �T���\�ȍő��


		// �ꕶ���ڂ���v���邩���J��Ԃ��ĒT��
		for (int loop_column = 0; loop_column <= column_sum; loop_column++)
		{
			// ������������������T����������
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[loop_row][loop_column + check_x] && check_x < text_size; check_x++)
			{
				// ���������炻���Ɉړ����ďI��
				if (check_x + 1 >= text_size)
				{
					mpr_variable.row_number = loop_row;
					mpr_variable.column_number = loop_column;

					return true;
				}
			}
		}
	}

	// �݂���Ȃ�����
	return false;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȑO�ň�ԋ߂����̂��s���ƂɁi���s�͊܂߂��Ɂj�T�����āA���̕����̍��Ɉړ�����
// ����   �Fstd::string �T�����镶��
// �߂�l �Fbool �݂���Ȃ����false
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Goto_Left_By_Text_In_Back_Row(std::string in_serch_text)
{
	// �� �ϐ��錾 �� //
	int text_size = (int)in_serch_text.size();	// �T�����镶���̕�����


	// �� �I�𒆂̍s�̎��̒T�� �� //
	{
		// �� �ϐ��錾 �� //
		int start_column = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// �T���J�n�ʒu


		// �ʏ펞�̒T���J�n�ʒu���I���ʒu�����ł���ΒT���J�n�ʒu�����炷
		if (mpr_variable.column_number <= start_column)
		{
			start_column = mpr_variable.column_number - 1;
		}


		// �ꕶ���ڂ���v���邩���J��Ԃ��ĒT��
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			// ������������������T����������
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
			{
				// ���������炻���Ɉړ����ďI��
				if (check_x + 1 >= text_size)
				{
					mpr_variable.column_number = loop_column;

					return true;
				}
			}
		}
	}


	// ��O�̍s����w�肳�ꂽ������T������
	for (int loop_row = mpr_variable.row_number - 1; loop_row > -1; loop_row--)
	{
		// �� �ϐ��錾 �� //
		int start_column = (int)mpr_variable.sentence_data[loop_row].size() - text_size;	// �T���J�n�ʒu


		// �ʏ펞�̒T���J�n�ʒu���I���ʒu�����ł���ΒT���J�n�ʒu�����炷
		if (mpr_variable.column_number <= start_column)
		{
			start_column = mpr_variable.column_number - 1;
		}


		// �ꕶ���ڂ���v���邩���J��Ԃ��ĒT��
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			// ������������������T����������
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[loop_row][loop_column + check_x] && check_x < text_size; check_x++)
			{
				// ���������炻���Ɉړ����ďI��
				if (check_x + 1 >= text_size)
				{
					mpr_variable.row_number = loop_row;
					mpr_variable.column_number = loop_column;

					return true;
				}
			}
		}
	}

	// �݂���Ȃ�����
	return false;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȍ~�ň�ԋ߂����̂�I�𒆂̍s���ŒT�����āA���̕����̍��Ɉړ�����
// ����   �Fstd::string �T�����镶��
// �߂�l �Fbool �݂���Ȃ����false
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Goto_Left_By_Text_In_Front_Column(std::string in_serch_text)
{
	// �� �ϐ��錾 �� //
	int text_size = (int)in_serch_text.size();	// �T�����镶���̕�����
	int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// �T���\�ȍő��


	// �ꕶ���ڂ���v���邩���J��Ԃ��ĒT��
	for (int loop_column = mpr_variable.column_number + 1; loop_column <= column_sum; loop_column++)
	{
		// ������������������T����������
		for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
		{
			// ���������炻���Ɉړ����ďI��
			if (check_x + 1 >= text_size)
			{
				mpr_variable.column_number = loop_column;

				return true;
			}
		}
	}

	// �݂���Ȃ�����
	return false;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�����Ɠ��������̂������̏ꏊ�ȑO�ň�ԋ߂����̂�I�𒆂̍s���ŒT�����āA���̕����̍��Ɉړ�����
// ����   �Fstd::string �T�����镶��
// �߂�l �Fbool �݂���Ȃ����false
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Goto_Left_By_Text_In_Back_Column(std::string in_serch_text)
{
	// �� �ϐ��錾 �� //
	int text_size = (int)in_serch_text.size();	// �T�����镶���̕�����
	int start_column = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// �T���J�n�ʒu


	// �ʏ펞�̒T���J�n�ʒu���I���ʒu�����ł���ΒT���J�n�ʒu�����炷
	if (mpr_variable.column_number <= start_column)
	{
		start_column = mpr_variable.column_number - 1;
	}


	// �ꕶ���ڂ���v���邩���J��Ԃ��ĒT��
	for (int loop_column = start_column; loop_column > -1; loop_column--)
	{
		// ������������������T����������
		for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
		{
			// ���������炻���Ɉړ����ďI��
			if (check_x + 1 >= text_size)
			{
				mpr_variable.column_number = loop_column;

				return true;
			}
		}
	}

	// �݂���Ȃ�����
	return false;
}


//-��- �����T�� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���I�𒆂̍s�Ɏw�肳�ꂽ�������I�𒆂̗�����邩�ǂ�����Ԃ�
// ����   �Fstd::string �T�����镶��
// �߂�l �Fbool �݂���Ȃ����false
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Serch_Text_In_Sentence(std::string in_serch_text)
{
	// �� �ϐ��錾 �� //
	int line_sum = (int)mpr_variable.sentence_data.size();	// �s��
	int text_size = (int)in_serch_text.size();	// �T�����镶���̕�����


	// ���̍s����w�肳�ꂽ������T������
	for (int loop_row = 0; loop_row < line_sum; loop_row++)
	{
		// �� �ϐ��錾 �� //
		int column_sum = (int)mpr_variable.sentence_data[loop_row].size();	// �T���\�ȍő��


		// �����s�ɂ��邩�ǂ����𔻒肷��
		for (int loop_column = 0; loop_column <= column_sum; loop_column++)
		{
			// �� �ϐ��錾 �� //
			std::string stack_check_string = mpr_variable.sentence_data[loop_row].substr(loop_column);	// �T���p������X�^�b�N

			int stack_size = (int)stack_check_string.size();	// �X�^�b�N�f�[�^�̃T�C�Y
			int now_row_number = loop_row;	// ���̍s�̔ԍ�

			bool flg_not_this = false;	// �f�[�^�������łȂ�����\���t���O


			// ������������������T����������
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// ���s�R�[�h������Ȃ玟�̍s��ǂݍ���
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// ���̍s������Ȃ���s
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ���̍s���K�v�Ȃ̂ɂȂ��Ȃ炱�̕����̔�����Ō�ɂ���
					else
					{
						flg_not_this = true;
					}
				}


				// �Ⴄ�Ȃ�T������߂�
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// ���������̂ł��̂��Ƃ������ďI��
				else if (check_x + 1 >= text_size)
				{
					return true;
				}


				// ���̈�s���Ō�̕����𒴂���Ȃ���s����
				if (check_x + 1 >= stack_size)
				{
					// ���̍s������Ȃ���s
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ���̍s���K�v�Ȃ̂ɂȂ��Ȃ炱�̕����̔�����Ō�ɂ���
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}

	// �݂���Ȃ�����
	return false;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���I�𒆂̍s�Ɏw�肳�ꂽ�������I�𒆂̗�����邩�ǂ�����Ԃ�
// ����   �Fstd::string �T�����镶��
// �߂�l �Fbool �݂���Ȃ����false
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Search_Text_In_Now_Row(std::string in_search_text)
{
	// �� �ϐ��錾 �� //
	int text_size = (int)in_search_text.size();	// �T�����镶���̕�����
	int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// ��


	// �����s�ɂ��邩�ǂ����𔻒肷��
	for (int loop_column = 0; loop_column <= column_sum; loop_column++)
	{
		// ������������������T����������
		for (int check_x = 0; in_search_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
		{
			// ���������̂ł��̂��Ƃ������ďI��
			if (check_x + 1 >= text_size)
			{
				return true;
			}
		}
	}

	// �݂���Ȃ�����
	return false;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�������w�肳�ꂽ������邩�ǂ�����Ԃ�
// ����   �Fint �T������s, std::string �T�����镶��
// �߂�l �Fbool �݂���Ȃ����false
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Search_Text_In_Select_Row(int in_select_row, std::string in_search_text)
{
	// �� �ϐ��錾 �� //
	int text_size = (int)in_search_text.size();	// �T�����镶���̕�����
	int column_sum = (int)mpr_variable.sentence_data[in_select_row].size() - text_size;	// ��


	// �s�͈̔͊O���w�肳�ꂽ��G���[
	if (in_select_row < 0 || mpr_variable.sentence_data.size() <= in_select_row)
	{
		return false;
	}


	// �����s�ɂ��邩�ǂ����𔻒肷��
	for (int loop_column = 0; loop_column <= column_sum; loop_column++)
	{
		// ������������������T����������
		for (int check_x = 0; in_search_text[check_x] == mpr_variable.sentence_data[in_select_row][loop_column + check_x] && check_x < text_size; check_x++)
		{
			// ���������̂ł��̂��Ƃ������ďI��
			if (check_x + 1 >= text_size)
			{
				return true;
			}
		}
	}

	// �݂���Ȃ�����
	return false;
}


//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���I�𒆂̏ꏊ���當������v���Ă��邩�𒲂ׂ�
// ����   �Fstd::string �T�����镶��
// �߂�l �Fbool ��v�����Ƃ��̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Check_Text_Is_Eqaul_Now_Position(std::string in_search_text)
{
	// �� �ϐ��錾 �� //
	int text_size = (int)in_search_text.size();	// �T�����镶���̕�����


	// �w�肳�ꂽ�����̕�������������T������͈͂𒴂���Ȃ�Ⴄ������Ȃ̂ňႤ���Ƃ�����
	if (mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number).size() < text_size)
	{
		return false;
	}


	// �ŏ��̕��������v�������邩�ǂ��������؂���
	for (int check_x = 0; in_search_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][check_x + mpr_variable.column_number] && check_x < text_size; check_x++)
	{
		// �Ō�܂ň�v���������猩���������Ƃ������Ĕ�����
		if (check_x + 1 >= text_size)
		{
			return true;
		}
	}

	// �Ⴄ���Ƃ�����
	return false;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�t�@�C�������邩�ǂ����𔻒肷��
// ����   �Fstd::string �t�@�C���܂ł̃p�X
// �߂�l �Fbool �݂�������true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_Text_And_File_Manager::M_Is_File_Exist(std::string in_path_string)
{
	// �� �ϐ��錾 �� //
	std::fstream f_file_system(in_path_string, std::ios_base::in);	// �t�@�C������p�N���X�A�ǂݍ��݂Ő錾


	// �t�@�C�����J���Ă��Ȃ���΃G���[��Ԃ��ďI��
	if (!f_file_system)
	{
		f_file_system.close();
		return false;
	}


	// �t�@�C�������
	f_file_system.close();

	return true;
}


