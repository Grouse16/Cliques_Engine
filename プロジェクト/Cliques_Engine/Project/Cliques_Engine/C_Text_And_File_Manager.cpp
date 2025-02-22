////
// Ú×   Ft@C§äpVXeÌNX
// à¾   Ft@Cð¶¬µAf[^ðL^Å«é
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include <string.h>
#include <fstream>
#include <sys/stat.h>
#include <filesystem>

#include "C_Text_And_File_Manager.h"


//  l[Xy[X  //
using namespace SYSTEM::TEXT;


//  ZLeBAEg  //
#define _CRT_SECURE_NO_WARNINGS	// ZLeBÉæéxðsíÈ¢


//  Öè`  //

//== vCx[g ==//

//-- f[^Ø --//

//===============//
// Ú×   FüÍ³ê½pX¼ªoOðø«N±³È¢àÌ©Ç¤©ð»è·é
// ø   Fstd::string & pX¼
// ßèl Fbool ³µ¯êÎtrue
//===============//
bool C_Text_And_File_Manager::M_Is_File_Path_Succeed(std::string& in_check_path_name)
{
	// pX¼ªó¶ÈçÔá¢
	if (in_check_path_name.size() <= 0)
	{
		return false;
	}


	//  pX¼©fBNgª¶ÝµÄ¢È¢Èç»êàÔá¢  //
	if (M_Is_CR(in_check_path_name[0]) == true || M_Is_CR(in_check_path_name[in_check_path_name.size() - 1]) == true)
	{
		return false;
	}

	
	// pX¼Í³Å é
	return true;
}


//===============//
// Ú×   FüÍ³ê½pX¼ªoOðø«N±³È¢àÌ©Ç¤©ð»è·é
// ø   Fstd::string & pX¼
// ßèl Fbool ³µ¯êÎtrue
//===============//
bool C_Text_And_File_Manager::M_Is_Folder_Path_Is_Succeed(std::string & in_check_path_name)
{
	// pX¼ªó¶ÈçÔá¢
	if (in_check_path_name.size() <= 0)
	{
		return false;
	}


	// tH_pXÌêÔÅªüs¶Èç³ðJ±¤ÆµÄ¢éÌÅG[
	if (M_Is_CR(in_check_path_name[0]) == true)
	{
		return false;
	}

	// tH_¼Í³Å é
	return true;
}


//===============//
// Ú×   Ft@Cªwè³êÄ¢é©Ç¤©ð»è
// ø   Fstd::string & pX¼
// ßèl Fbool t@CÜÅÌpXÈçtrue tH_ÈÇÜÅÈçfalse
//===============//
bool C_Text_And_File_Manager::M_Is_File(std::string & in_check_path)
{
	//  fBNgðwè³êÄ¢½çfalse  //
	if (std::filesystem::is_directory(in_check_path) == true)
	{
		return false;
	}


	// t@CÜÅÌpXÅ é
	return true;
}


//===============//
// Ú×   Fwè³ê½¶ªüs¶Å é©Ç¤©ð»è·é
// ø   Fconst char & ¶f[^
// ßèl Fbool trueÈçüsR[h
//===============//
bool C_Text_And_File_Manager::M_Is_CR(const char & in_check_charact)
{
	//  üsR[h©Ç¤©ð»è  //
	switch (in_check_charact)
	{
	// EBhEYnÌüsR[h
	case '/':
		return true;

	// UnixÆLinuxnÜ½ÍMACOSnÌüsR[hÌÌØ
	case '\n':
		return true;

	// MACOSnÌüsR[hÌÌØ
	case '\r':
		return true;

	// R\[ÅÌwèû®
	case '\\':
		return true;
	}


	// üsR[hÅÍÈ©Á½
	return false;
}


//== pubN ==//

//-- RXgN^ÆfXgN^ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Text_And_File_Manager::C_Text_And_File_Manager(void)
{
	M_Reset_Data();

	return;
}


//===============//
// Ú×   Ff[^ú»
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Reset_Data(void)
{
	mpr_variable.sentence_data.clear();
	mpr_variable.sentence_data.shrink_to_fit();

	// êsÚÍì¬µÄ¨­
	mpr_variable.sentence_data.resize(1);

	mpr_variable.file_path.clear();
	mpr_variable.file_path.shrink_to_fit();
	mpr_variable.file_path = mpr_variable.con_default_name;
	mpr_variable.column_number = 0;
	mpr_variable.row_number = 0;

	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Text_And_File_Manager::~C_Text_And_File_Manager(void)
{
	M_Reset_Data();

	return;
}


//-- f[^Ï· --//

//===============//
// Ú×   F¶ñð10iÌINT^ÉÏ··é
// ø   Fconst char * Ï··éf[^
// ßèl Fint Ï·Ê
//===============//
int C_Text_And_File_Manager::M_Convert_Data_Char_To_X16INT(std::string in_data)
{
	//  Ïé¾  //
	int result_10x_number = 0;	// Ï·Ê
	int text_size = (int)in_data.size();	// ¶
	int multiple_level = 1;	// 10iÏ·½ßÌ{¦


	// Ï·ðs¤
	for (int loop_x = text_size - 1; loop_x > -1; loop_x--)
	{
		//  Ïé¾  //
		int down_data = in_data[loop_x] & 0x0f;	// ºÊ4rbgÌf[^
		int top_data = in_data[loop_x] & 0xf0;	// ãÊ4rbgÌf[^i_ããÊ4rbgÍºÊ4rbgæèêñ½­16ð|¯È¯êÎÈçÈ¢ªæèoµ½Éà¤·ÅÉ16rbg{ÉÈÁÄ¢é@(RF10iÅ5rbgÚÍ16¾©ç@16iÅl¦éÆãÊÆºÊÅÊêÄ¢éÆöoµÄµÜ¤)j


		// 10iÉÏ·µ½ÊðÁZ
		result_10x_number += (top_data + down_data) * multiple_level;


		// 10ÌÌ½ßÉâ·
		multiple_level *= 256;
	}


	// ÊðÔ·
	return result_10x_number;
}


//-- ¶¬ --//

//===============//
// Ú×   FpXÜÅÌtH_ð¶¬·é
// ø   Fstd::string t@CÜÅÌpX
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_Text_And_File_Manager::M_Create_Path_Of_Folder(std::string in_path_string)
{
	// tH_ÌpXª³µ­È¢ÍX[
	if (M_Is_Folder_Path_Is_Succeed(in_path_string) == false)
	{
		return false;
	}


	// t@Cª©Â©êÎ¨íé
	if (M_Is_File_Exist(in_path_string) == true)
	{
		return true;
	}


	//  Ïé¾  //
	struct stat s_stat_fold;	// tH_Tõp

	int n_text_size = (int)strlen(in_path_string.data());	// pXÌ¶

	bool b_succes = true;	// tH_ª é©Ç¤©ÌtO


	// êÔºÌtH_ðTõµÄA³¯êÎtOðº°é
	for (int n_num = n_text_size - 1; n_num >= 0; n_num--)
	{
		// tH_¼©çêÔ[¢tH_ª êÎ»êðTõ·é 
		if (M_Is_CR(in_path_string[n_num]) == true)
		{
			//  Ïé¾  //
			char* p_search_folder_name = new char[(long long)n_num + 1];	// TõÌtH_¼

			// tH_¼ðÝè
			for (int n_len = 0; n_len < n_num; n_len++)
			{
				p_search_folder_name[n_len] = in_path_string[n_len];
			}

			// I[¶ðÇÁ
			p_search_folder_name[n_num] = '\0';

			// êÔ[¢tH_ªÈ¯êÎ¬÷ÌtOðº°é
			if (stat(p_search_folder_name, &s_stat_fold) != 0)
			{
				b_succes = false;
			}

			// ðú
			delete[] p_search_folder_name;
			p_search_folder_name = nullptr;

			// êÔ[¢tH_ð­©µ½ÌÅð²¯é
			n_num -= n_text_size;
		}
	}

	// êÔ[¢tH_ª©Â©Á½çðI¹·é
	if (b_succes == true)
	{
		return true;
	}


	//  t@CTõ  //

	// tH_Tõ
	for (int n_num = 0; n_num < n_text_size; n_num++)
	{
		// tH_¼ªwè³êÄ¢êÎtH_ðTõµÄÈ¯êÎ¶¬
		if (M_Is_CR(in_path_string[n_num]) == true)
		{
			//  Ïé¾  //
			char* p_search_folder_name = new char[(long long)n_num + 1];	// TõÌtH_¼


			// tH_¼ðÝè
			for (int n_len = 0; n_len < n_num; n_len++)
			{
				p_search_folder_name[n_len] = in_path_string[n_len];
			}

			// I[¶ðÇÁ
			p_search_folder_name[n_num] = '\0';

			// tH_ªÈ¯êÎ¶¬·é
			if (stat(p_search_folder_name, &s_stat_fold) != 0)
			{
				//  Ïé¾  //
				wchar_t* p_set_fol_name = new wchar_t[(long long)n_num + 1];	// ¶¬·étH_¼

				int create_result = 0;	// ¶¬Ê


				// tH_¼ðÝè
				for (int n_len = 0; n_len < n_num; n_len++)
				{
					p_set_fol_name[n_len] = p_search_folder_name[n_len];
				}

				// I[¶ðÇÁ
				p_set_fol_name[n_num] = '\0';

				
				// tH_ð¶¬·é
				create_result = _wmkdir(p_set_fol_name);

				
				// ðú
				delete[] p_set_fol_name;
				p_set_fol_name = nullptr;


				// ¶¬É¸sµ½çG[ðo·
				if (create_result == -1)
				{
					delete[] p_search_folder_name;
					p_search_folder_name = nullptr;

					return false;
				}
			}

			// ðú
			delete[] p_search_folder_name;
			p_search_folder_name = nullptr;
		}
	}

	return true;
}


//===============//
// Ú×   FpXÜÅÌt@CÆtH_ªÈ¯êÎ¶¬·é
// ø   Fstring t@CÜÅÌpX
// ßèl F¬÷ÌÝtrue
//===============//
bool C_Text_And_File_Manager::M_Create_File_And_Folder_If_File_Not_Exist(std::string in_path_string)
{
	// tH_ÌpXª³µ­È¢ÍX[
	if (M_Is_Folder_Path_Is_Succeed(in_path_string) == false)
	{
		return false;
	}


	// t@Cª©Â©êÎ¨íé
	if (M_Is_File_Exist(in_path_string) == true)
	{
		return true;
	}


	//  tH_ð¶¬·é  //
	M_Create_Path_Of_Folder(in_path_string);


	// tH_ÌÝÌwèÅ êÎ»±Åf
	if (M_Is_File(in_path_string) == false)
	{
		return true;
	}


	//  Ïé¾  //
	std::fstream creat_file(in_path_string, std::ios_base::out | std::ios_base::trunc);	// t@CÒWpVXe


	// t@Cð¶¬·é
	creat_file << "";


	// t@CðÂ¶é
	creat_file.close();


	// t@CÜÅÌ¶¬É¬÷
	return true;
}


//-- Zb^ --//

//===============//
// Ú×   F±ê©çÒW·ét@CÌpXðwè·éiÈ¯êÎ¶¬³êéj
// ø   Fstring t@CÌpX
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_Text_And_File_Manager::M_Set_File_Path(std::string in_file_path)
{
	//  t@Cª³µ­wè³êÄ¢È¢Èç²¯é  //
	if (M_Is_File_Path_Succeed(in_file_path) == false)
	{
		return false;
	}


	//  t@Cª©Â©çÈ¯êÎìé  //		// ¶¬¸sÅG[ðo·
	if (M_Create_File_And_Folder_If_File_Not_Exist(in_file_path) == false)
	{
		return false;
	}


	//  wè³ê½îñðÝè  //
	mpr_variable.file_path = in_file_path;

	// wèÉ¬÷
	return true;
}


//===============//
// Ú×   FÒW[hðwè·é
// ø   FE_EDIT_MODE ÒW[hðwè·éÔ
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Set_Edit_Mode(E_EDIT_MODE in_set_mode)
{
	mpr_variable.mode_setting = in_set_mode;

	return;
}


//-- Qb^ --//

//===============//
// Ú×   F»ÝÌf[^ÌQÆðn·
// ø   Fvoid
// ßèl Fconst vector<string> & f[^ÌQÆ
//===============//
const std::vector<std::string> & C_Text_And_File_Manager::M_Get_File_Data_Refer(void) const
{
	return mpr_variable.sentence_data;
}


//===============//
// Ú×   F»ÝÌf[^ÌQÆðn·
// ø   Fvoid
// ßèl Fstring & t@CpXÌQÆ
//===============//
const std::string & C_Text_And_File_Manager::M_Get_File_Path_Refer(void) const
{
	return mpr_variable.file_path;
}


//===============//
// Ú×   F»ÝÌsÌÔðÔ·
// ø   Fvoid
// ßèl Fint »ÝÌsÌÔ
//===============//
int C_Text_And_File_Manager::M_Get_Now_Row(void) const
{
	return mpr_variable.row_number;
}


//===============//
// Ú×   F»ÝÌñÌÔðÔ·
// ø   Fvoid
// ßèl Fint »ÝÌñÌÔ
//===============//
int C_Text_And_File_Manager::M_Get_Now_Column(void) const
{
	return mpr_variable.column_number;
}


//===============//
// Ú×   F¶ÍÌsðÔ·
// ø   Fvoid
// ßèl Fint ¶ÍÌs
//===============//
int C_Text_And_File_Manager::M_Get_Text_Row_Sum(void) const
{
	return (int)mpr_variable.sentence_data.size();
}


//===============//
// Ú×   F¡IðÌsÌ¶ðÔ·
// ø   Fvoid
// ßèl Fint ¶
//===============//
int C_Text_And_File_Manager::M_Get_Column_Sum_In_Now_Row(void)
{
	return (int)mpr_variable.sentence_data[mpr_variable.row_number].size();
}


//===============//
// Ú×   F»ÝÌ¶ÍSÌÌ¶ðÔ·
// ø   Fvoid
// ßèl Fint ¶
//===============//
int C_Text_And_File_Manager::M_Get_Sentence_Text_Size(void)
{
	//  Ïé¾  //
	int result_text_size = 0;	// ¶Ìv
	int row_size = (int)mpr_variable.sentence_data.size(); // s


	return 0;
}


//===============//
// Ú×   F»ÝÌêÌ¶ðÔ·
// ø   Fvoid
// ßèl Fchar »ÝÌêÌ¶
//===============//
char C_Text_And_File_Manager::M_Get_Text_Of_Now_Position(void)
{
	return mpr_variable.sentence_data[mpr_variable.row_number][mpr_variable.column_number];
}


//-- Z[u --//

//===============//
// Ú×   FìÌt@CÉ»ÝÌf[^ðã«ÅZ[u·é
// ø   Fvoid
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_Text_And_File_Manager::M_Save_Data_To_Now_File(void)
{
	//  Ïé¾  //
	std::fstream creat_file;	// t@CÒWpVXe

	int row_sum = (int)mpr_variable.sentence_data.size();	// s


	//  ÒW[hÉæÁÄðªò  //
	switch (mpr_variable.mode_setting)
	{
		// oCi`®
	case E_EDIT_MODE::e_BINARY:
		creat_file.open(mpr_variable.file_path, std::ios::out, std::ios::binary);
		break;

		// eLXg`®
	case E_EDIT_MODE::e_TEXT:
		creat_file.open(mpr_variable.file_path, std::ios::out);
		break;
	}


	// ÇÝæêÄ¢È©Á½çG[ðoµÄ²¯é
	if (!creat_file)
	{
		creat_file.close();
		return false;
	}


	// t@Cð¶¬·éµàeð«Þ
	for (int loop_x = 0; loop_x < row_sum; loop_x++)
	{
		creat_file << mpr_variable.sentence_data[loop_x].data();


		// Ü¾ºÉsª éÈçüs
		if (loop_x + 1 < row_sum)
		{
			creat_file << "\n";
		}
	}

	// t@CðÂ¶é
	creat_file.close();

	return true;
}


//===============//
// Ú×   Fwè³ê½t@CÉ»ÝÌf[^ðã«ÅZ[u·é
// ø   Fstring t@CÌpX
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_Text_And_File_Manager::M_Save_Data_To_Select_File(std::string in_file_path)
{
	//  t@Cª³µ­wè³êÄ¢È¢Èç²¯é  //
	if (M_Is_File_Path_Succeed(in_file_path) == false)
	{
		return false;
	}


	//  Ïé¾  //
	std::fstream creat_file;	// t@CÒWpVXe

	int row_sum = (int)mpr_variable.sentence_data.size();	// s


	//  ÒW[hÉæÁÄðªò  //
	switch (mpr_variable.mode_setting)
	{
		// oCi`®
	case E_EDIT_MODE::e_BINARY:
		creat_file.open(in_file_path, std::ios::out, std::ios::binary);
		break;

		// eLXg`®
	case E_EDIT_MODE::e_TEXT:
		creat_file.open(in_file_path, std::ios::out);
		break;
	}


	// ÇÝæêÄ¢È©Á½çG[ðoµÄ²¯é
	if (!creat_file)
	{
		creat_file.close();
		return false;
	}


	// t@Cð¶¬·éµàeð«Þ
	for (int loop_x = 0; loop_x < row_sum; loop_x++)
	{
		creat_file << mpr_variable.sentence_data[loop_x].data();


		// Ü¾ºÉsª éÈçüs
		if (loop_x + 1 < row_sum)
		{
			creat_file << "\n";
		}
	}

	// t@CðÂ¶é
	creat_file.close();

	return true;
}


//===============//
// Ú×   FìÌt@CÉ»ÝÌf[^ðÇÁÅZ[u·é
// ø   Fvoid
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_Text_And_File_Manager::M_Add_Data_To_Now_File(void)
{
	//  Ïé¾  //
	std::fstream add_file;	// t@CÒWpVXe

	int row_sum = (int)mpr_variable.sentence_data.size();	// s


	//  ÒW[hÉæÁÄðªò  //
	switch (mpr_variable.mode_setting)
	{
		// oCi`®
	case E_EDIT_MODE::e_BINARY:
		add_file.open(mpr_variable.file_path, std::ios::app, std::ios::binary);
		break;

		// eLXg`®
	case E_EDIT_MODE::e_TEXT:
		add_file.open(mpr_variable.file_path, std::ios::app);
		break;
	}


	// ÇÝæêÄ¢È©Á½çG[ðoµÄ²¯é
	if (!add_file)
	{
		add_file.close();
		return false;
	}


	// t@Cð¶¬·éµàeð«Þ
	for (int loop_x = 0; loop_x < row_sum; loop_x++)
	{
		add_file << mpr_variable.sentence_data[loop_x].data();


		// Ü¾ºÉsª éÈçüs
		if (loop_x + 1 < row_sum)
		{
			add_file << "\n";
		}
	}

	// t@CðÂ¶é
	add_file.close();

	return true;
}


//===============//
// Ú×   Fwè³ê½t@CÉ»ÝÌf[^ðÇÁÅZ[u·é
// ø   Fstring t@CÌpX
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_Text_And_File_Manager::M_Add_Data_To_Select_File(std::string in_file_path)
{
	//  t@Cª³µ­wè³êÄ¢È¢Èç²¯é  //
	if (M_Is_File_Path_Succeed(in_file_path) == false)
	{
		return false;
	}


	//  Ïé¾  //
	std::fstream add_file;	// t@CÒWpVXe

	int row_sum = (int)mpr_variable.sentence_data.size();	// s


	//  ÒW[hÉæÁÄðªò  //
	switch (mpr_variable.mode_setting)
	{
		// oCi`®
	case E_EDIT_MODE::e_BINARY:
		add_file.open(in_file_path, std::ios::app, std::ios::binary);
		break;

		// eLXg`®
	case E_EDIT_MODE::e_TEXT:
		add_file.open(in_file_path, std::ios::app);
		break;
	}


	// ÇÝæêÄ¢È©Á½çG[ðoµÄ²¯é
	if (!add_file)
	{
		add_file.close();
		return false;
	}


	// t@Cð¶¬·éµàeð«Þ
	for (int loop_x = 0; loop_x < row_sum; loop_x++)
	{
		add_file << mpr_variable.sentence_data[loop_x].data();


		// Ü¾ºÉsª éÈçüs
		if (loop_x + 1 < row_sum)
		{
			add_file << "\n";
		}
	}

	// t@CðÂ¶é
	add_file.close();

	return true;
}


//-- [h --//

//===============//
// Ú×   FìÌt@C©çf[^ðÇÝÞ
// ø   Fvoid
// ßèl Fbool ¬÷ÌÝture
//===============//
bool C_Text_And_File_Manager::M_Load_Now_File(void)
{
	//  t@Cª³µ­wè³êÄ¢È¢Èç²¯é  //
	if (M_Is_File_Path_Succeed(mpr_variable.file_path) == false)
	{
		return false;
	}


	//  Ïé¾  //
	std::ifstream load_file;	// t@CÌÇÝæèpVXe

	std::string data_one_line;	// êsªÌf[^


	//  ÒW[hÉæÁÄðªò  //
	switch (mpr_variable.mode_setting)
	{
		// oCi`®
	case E_EDIT_MODE::e_BINARY:
		load_file.open(mpr_variable.file_path, std::ios::in, std::ios::binary);
		break;

		// eLXg`®
	case E_EDIT_MODE::e_TEXT:
		load_file.open(mpr_variable.file_path, std::ios::in);
		break;
	}


	// ÇÝæêÄ¢È©Á½çG[ðoµÄ²¯é
	if (!load_file)
	{
		load_file.close();
		return false;
	}


	// sªÈ¯êÎêsÇÁ
	if (mpr_variable.sentence_data.size() <= 0)
	{
		mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
	}


	// EOF(t@CÌIíè)ª­éÜÅæèoµ±¯é
	while (std::getline(load_file, data_one_line) && !data_one_line.empty())
	{
		// óÈçX[
		if (data_one_line.size() <= 0)
		{

		}

		// üsR[hª éÈçüsR[hð²¢Äf[^ðüêé
		else if (M_Is_CR(data_one_line[data_one_line.size() - 1]) == true)
		{
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line.substr(0, data_one_line.size() - 1);
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
		}

		// üsR[hªÈ¢ÈçÊíÊèf[^ðüêé
		else
		{
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line;
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
		}

		// êsÇÁ
		mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
	}


	// t@CðÆ¶é
	load_file.close();

	return true;
}


//===============//
// Ú×   FìÌt@C©çwè³ê½sÔ¾¯f[^ðÇÝÞ
// ø   Fint ÇÝnÜèÌs, int ÇÝIíèÌs
// ßèl Fbool ¬÷ÌÝture
//===============//
bool C_Text_And_File_Manager::M_Load_Now_File_Only_Select_Raw(int in_start_row, int in_end_row)
{
	//  t@Cª³µ­wè³êÄ¢È¢Èç²¯é  //
	if (M_Is_File_Path_Succeed(mpr_variable.file_path) == false)
	{
		return false;
	}


	//  Ïé¾  //
	std::ifstream load_file;	// t@CÌÇÝæèpVXe

	std::string data_one_line;	// êsªÌf[^


	//  ÒW[hÉæÁÄðªò  //
	switch (mpr_variable.mode_setting)
	{
		// oCi`®
	case E_EDIT_MODE::e_BINARY:
		load_file.open(mpr_variable.file_path, std::ios::in, std::ios::binary);
		break;

		// eLXg`®
	case E_EDIT_MODE::e_TEXT:
		load_file.open(mpr_variable.file_path, std::ios::in);
		break;
	}


	// ÇÝæêÄ¢È©Á½çG[ðoµÄ²¯é
	if (!load_file)
	{
		load_file.close();
		return false;
	}


	// sªÈ¯êÎêsÇÁ
	if (mpr_variable.sentence_data.size() <= 0)
	{
		mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
	}


	// EOF(t@CÌIíè)ª­éÜÅæèoµ±¯é
	for (int loop_x = 0; std::getline(load_file, data_one_line) && !data_one_line.empty(); loop_x++)
	{
		// nÜèÌsÆIíèÌsÌÔÌsÌÝÇÝæé
		if (in_start_row <= loop_x)
		{
			// óÈçX[
			if (data_one_line.size() <= 0)
			{

			}

			// üsR[hª éÈçüsR[hð²¢Äf[^ðüêé
			else if (M_Is_CR(data_one_line[data_one_line.size() - 1]) == true)
			{
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line.substr(0, data_one_line.size() - 1);
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
			}

			// üsR[hªÈ¢ÈçÊíÊèf[^ðüêé
			else
			{
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line;
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
			}

			// êsÇÁ
			mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
		}

		// IíèÌsð±¦½ç±êÈãÇÝæçÈ­Äæ¢ÌÅt@CðÂ¶ÄI¹
		else if (in_end_row <= loop_x)
		{
			load_file.close();
			return true;
		}
	}


	// t@CðÆ¶é
	load_file.close();

	return true;
}


//===============//
// Ú×   Fwè³ê½t@C©çf[^ðÇÝÞ
// ø   Fstd::string t@CÌpX
// ßèl Fbool ¬÷ÌÝture
//===============//
bool C_Text_And_File_Manager::M_Load_Select_File(std::string in_file_path)
{
	//  t@Cª³µ­wè³êÄ¢È¢Èç²¯é  //
	if (M_Is_File_Path_Succeed(in_file_path) == false)
	{
		return false;
	}


	//  t@CàtH_àÈ¢Èçfalse  //
	if (M_Is_File_Exist(in_file_path) == false)
	{
		return false;
	}



	//  t@Cª³µ­wè³êÄ¢È¢Èç²¯é  //
	if (M_Is_File(in_file_path) == false)
	{
		return false;
	}


	//  Ïé¾  //
	std::ifstream load_file;	// t@CÌÇÝæèpVXe

	std::string data_one_line;	// êsªÌf[^


	//  ÒW[hÉæÁÄðªò  //
	switch (mpr_variable.mode_setting)
	{
		// oCi`®
	case E_EDIT_MODE::e_BINARY:
		load_file.open(in_file_path, std::ios::in, std::ios::binary);
		break;

		// eLXg`®
	case E_EDIT_MODE::e_TEXT:
		load_file.open(in_file_path, std::ios::in);
		break;
	}


	// ÇÝæêÄ¢È©Á½çG[ðoµÄ²¯é
	if (!load_file)
	{
		load_file.close();
		return false;
	}


	// sªÈ¯êÎêsÇÁ
	if (mpr_variable.sentence_data.size() <= 0)
	{
		mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
	}


	// EOF(t@CÌIíè)ª­éÜÅæèoµ±¯é
	while (std::getline(load_file, data_one_line))
	{
		// óÈçX[
		if (data_one_line.size() <= 0)
		{

		}

		// üsR[hª éÈçüsR[hð²¢Äf[^ðüêé
		else if (M_Is_CR(data_one_line[data_one_line.size() - 1]) == true)
		{
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line.substr(0, data_one_line.size() - 1);
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
		}

		// üsR[hªÈ¢ÈçÊíÊèf[^ðüêé
		else
		{
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line;
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
		}


		// êsÇÁ
		mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
	}


	// t@CðÆ¶é
	load_file.close();

	return true;
}


//===============//
// Ú×   Fwè³ê½t@C©çwè³ê½sÔ¾¯f[^ðÇÝÞ
// ø   Fstd::string, int ÇÝnÜèÌs, int ÇÝIíèÌs
// ßèl Fbool ¬÷ÌÝture
//===============//
bool C_Text_And_File_Manager::M_Load_Select_File_Only_Select_Raw(std::string in_file_path, int in_start_row, int in_end_row)
{
	//  t@Cª³µ­wè³êÄ¢È¢Èç²¯é  //
	if (M_Is_File_Path_Succeed(in_file_path) == false)
	{
		return false;
	}


	//  t@CàtH_àÈ¢Èçfalse  //
	if (M_Is_File_Exist(in_file_path) == false)
	{
		return false;
	}


	//  t@Cª³µ­wè³êÄ¢È¢Èç²¯é  //
	if (M_Is_File(in_file_path) == false)
	{
		return false;
	}


	//  Ïé¾  //
	std::ifstream load_file;	// t@CÌÇÝæèpVXe

	std::string data_one_line;	// êsªÌf[^


	//  ÒW[hÉæÁÄðªò  //
	switch (mpr_variable.mode_setting)
	{
		// oCi`®
	case E_EDIT_MODE::e_BINARY:
		load_file.open(in_file_path, std::ios::in, std::ios::binary);
		break;

		// eLXg`®
	case E_EDIT_MODE::e_TEXT:
		load_file.open(in_file_path, std::ios::in);
		break;
	}


	// ÇÝæêÄ¢È©Á½çG[ðoµÄ²¯é
	if (!load_file)
	{
		load_file.close();
		return false;
	}


	// sªÈ¯êÎêsÇÁ
	if (mpr_variable.sentence_data.size() <= 0)
	{
		mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
	}


	// EOF(t@CÌIíè)ª­éÜÅæèoµ±¯é
	for (int loop_x = 0; std::getline(load_file, data_one_line) && !data_one_line.empty(); loop_x++)
	{
		// ÍÍàÌÌÝÇÝæé
		if (in_start_row <= loop_x)
		{
			// óÈçX[
			if (data_one_line.size() <= 0)
			{

			}

			// üsR[hª éÈçüsR[hð²¢Äf[^ðüêé
			else if (M_Is_CR(data_one_line[data_one_line.size() - 1]) == true)
			{
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line.substr(0, data_one_line.size() - 1);
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
			}

			// üsR[hªÈ¢ÈçÊíÊèf[^ðüêé
			else
			{
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line;
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
			}


			// êsÇÁ
			mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
		}

		// IíèÌsð±¦½ç±êÈãÇÝæçÈ­Äæ¢ÌÅt@CðÂ¶ÄI¹
		if (in_end_row <= loop_x)
		{
			load_file.close();
			return true;
		}
	}


	// t@CðÆ¶é
	load_file.close();

	return true;
}


//-- üÍ --//

//===============//
// Ú×   Fwè³ê½f[^ð»ÝÌìÊu©çüÍ·é
// ø   Fshort üÍ·éf[^
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Input_This_Data(short in_data)
{
	mpr_variable.sentence_data[mpr_variable.row_number].insert(mpr_variable.column_number, std::to_string(in_data));
	mpr_variable.column_number += (int)std::to_string(in_data).size();

	return;
}


//===============//
// Ú×   Fwè³ê½f[^ð»ÝÌìÊu©çüÍ·é
// ø   Funsigned short üÍ·éf[^
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Input_This_Data(unsigned short in_data)
{
	mpr_variable.sentence_data[mpr_variable.row_number].insert(mpr_variable.column_number, std::to_string(in_data));
	mpr_variable.column_number += (int)std::to_string(in_data).size();

	return;
}

//===============//
// Ú×   Fwè³ê½f[^ð»ÝÌìÊu©çüÍ·é
// ø   Fint üÍ·éf[^
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Input_This_Data(int in_data)
{
	mpr_variable.sentence_data[mpr_variable.row_number].insert(mpr_variable.column_number, std::to_string(in_data));
	mpr_variable.column_number += (int)std::to_string(in_data).size();

	return;
}


//===============//
// Ú×   Fwè³ê½f[^ð»ÝÌìÊu©çüÍ·é
// ø   Funsigned int üÍ·éf[^
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Input_This_Data(unsigned int in_data)
{
	mpr_variable.sentence_data[mpr_variable.row_number].insert(mpr_variable.column_number, std::to_string(in_data));
	mpr_variable.column_number += (int)std::to_string(in_data).size();

	return;
}


//===============//
// Ú×   Fwè³ê½f[^ð»ÝÌìÊu©çüÍ·é
// ø   Flong long üÍ·éf[^
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Input_This_Data(long long in_data)
{
	mpr_variable.sentence_data[mpr_variable.row_number].insert(mpr_variable.column_number, std::to_string(in_data));
	mpr_variable.column_number += (int)std::to_string(in_data).size();

	return;
}


//===============//
// Ú×   Fwè³ê½f[^ð»ÝÌìÊu©çüÍ·é
// ø   Funsigned long long üÍ·éf[^
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Input_This_Data(unsigned long long in_data)
{
	mpr_variable.sentence_data[mpr_variable.row_number].insert(mpr_variable.column_number, std::to_string(in_data));
	mpr_variable.column_number += (int)std::to_string(in_data).size();

	return;
}


//===============//
// Ú×   Fwè³ê½f[^ð»ÝÌìÊu©çüÍ·é
// ø   Fstd::string üÍ·éf[^
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Input_This_Data(std::string in_data)
{
	//  Ïé¾  //
	std::string stack_data;	// ÊðT¦é½ßÌf[^

	int text_size = (int)in_data.size();	// ¶


	// ¶ªs¤
	for (int check_x = 0; check_x < text_size; check_x++)
	{
		// üsR[hª Á½çüs·é
		if (M_Is_CR(in_data[check_x]) == true)
		{
			// EÉvfª éÈçüsæÉ»ÌvfðÚ®³¹A¡ÜÅ½ß½f[^ð»ÝÌsÉi[·é
			if (mpr_variable.sentence_data[mpr_variable.row_number].size() >= mpr_variable.column_number)
			{
				mpr_variable.sentence_data.insert(mpr_variable.sentence_data.begin() + mpr_variable.row_number + 1, mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number));
				mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, mpr_variable.column_number) + stack_data;
				mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();
			}

			// È¢ÈçüsÌÝðs¤A¡ÜÅ½ß½f[^ð»ÝÌsÉi[·é
			else
			{
				mpr_variable.sentence_data.insert(mpr_variable.sentence_data.begin() + mpr_variable.row_number + 1, "");
				mpr_variable.sentence_data[mpr_variable.row_number] += stack_data;
				mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();
			}


			// PÂºÌsðIð·é
			mpr_variable.row_number += 1;

			// êÔ¶ðIðÉ·é
			mpr_variable.column_number = 0;

			// X^bNÌf[^ðNA
			stack_data.clear();
			stack_data.shrink_to_fit();
		}

		// ¶ðÂÈ°é
		else
		{
			stack_data += in_data[check_x];
		}
	}


	// ÅãÜÅcÁ½f[^ði[
	mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, mpr_variable.column_number) + stack_data + mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number);
	mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();

	// IðÊuðÚ®
	mpr_variable.column_number += text_size;

	return;
}


//===============//
// Ú×   Fwè³ê½f[^ð»ÝÌìÊu©çüÍ·é
// ø   Fdouble üÍ·éf[^
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Input_This_Data(double in_data)
{
	mpr_variable.sentence_data[mpr_variable.row_number].insert(mpr_variable.column_number, std::to_string(in_data));
	mpr_variable.column_number += (int)std::to_string(in_data).size();

	return;
}


//-- í --//

//===============//
// Ú×   Fwè³ê½f[^ð¶Íà©çwè³ê½ñª¾¯í·é
// ø   Fint íñiOÅSÄíj, std::string í·é¶
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Delete_Data_Equal_This_Text_In_Sentence(int in_delete_num, std::string in_delete_text)
{
	//  Ïé¾  //
	int line_sum = (int)mpr_variable.sentence_data.size();	// s
	int text_size = (int)in_delete_text.size();	// Tõ·é¶Ì¶


	// SÄÌsªJèÔ·
	for (int loop_row = 0; loop_row < line_sum; loop_row++)
	{
		//  Ïé¾  //
		int column_sum = (int)mpr_variable.sentence_data[loop_row].size() - text_size;	// TõÂ\ÈÅåñ


		// ê¶Úªêv·é©ðJèÔµÄTõ
		for (int loop_column = 0; loop_column <= column_sum; loop_column++)
		{
			// ¯¶¶ª Á½çTõµ±¯é
			for (int check_x = 0; in_delete_text[check_x] == mpr_variable.sentence_data[loop_row][(size_t)loop_column + check_x] && check_x < text_size; check_x++)
			{
				// ©Â©Á½çí·é
				if (check_x + 1 >= text_size)
				{
					// íÊuæèEÉ¶ªÈ¢ÈçíÊuÜÅði[
					if (mpr_variable.sentence_data[loop_row].size() <= (size_t)loop_column + (size_t)text_size)
					{
						mpr_variable.sentence_data[loop_row] = mpr_variable.sentence_data[loop_row].substr(0, loop_column);
					}

					// íÊuæèEÉ¶ª éÈçíÊuÌÝÈ­
					else
					{
						mpr_variable.sentence_data[loop_row] = mpr_variable.sentence_data[loop_row].substr(0, loop_column) + mpr_variable.sentence_data[loop_row].substr((size_t)loop_column + text_size);
					}


					mpr_variable.sentence_data[loop_row].shrink_to_fit();


					// ¡ÌIðÊuæèOÌÊuªÁ³ê½çßé
					if (mpr_variable.row_number >= loop_row)
					{
						if (mpr_variable.column_number >= loop_column)
						{
							mpr_variable.column_number -= text_size;
						}


						// IðÌêª¡Ìsàð´¦½çãÌsÉßé
						if (mpr_variable.column_number < 0)
						{
							mpr_variable.column_number = (int)mpr_variable.sentence_data[(size_t)mpr_variable.row_number - 1].size();
						}
					}


					// cèÌíñð¸ç·Aà¤È¯êÎI¹·é
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


//===============//
// Ú×   Fwè³ê½f[^ðIðÌsà©çwè³ê½ñª¾¯í·é
// ø   Fint íñiOÅSÄíj, std::string í·é¶
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Delete_Data_Equal_This_Text_In_Now_Row(int in_delete_num, std::string in_delete_text)
{
	//  Ïé¾  //
	int text_size = (int)in_delete_text.size();	// Tõ·é¶Ì¶
	int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// TõÂ\ÈÅåñ


	// ê¶Úªêv·é©ðJèÔµÄTõ
	for (int loop_column = 0; loop_column <= column_sum; loop_column++)
	{
		// ¯¶¶ª Á½çTõµ±¯é
		for (int check_x = 0; in_delete_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][(size_t)loop_column + check_x] && check_x < text_size; check_x++)
		{
			// ©Â©Á½çí·é
			if (check_x + 1 >= text_size)
			{
				// íÊuæèEÉ¶ªÈ¢ÈçíÊuÜÅði[
				if (mpr_variable.sentence_data[mpr_variable.row_number].size() <= (size_t)loop_column + text_size)
				{
					mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, loop_column);
				}

				// íÊuæèEÉ¶ª ÂÈçíÊuÌÝÈ­
				else
				{
					mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, loop_column) + mpr_variable.sentence_data[mpr_variable.row_number].substr((size_t)loop_column + text_size);
				}


				mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();


				// íÍÍÈ~ÉIðÌêª Á½çíÍÍª¶ÉÚ®·é
				if (loop_column <= mpr_variable.column_number)
				{
					mpr_variable.column_number = loop_column - 1;


					// 0ÈºÉÍÈçÈ¢æ¤É·é
					if (mpr_variable.column_number < 0)
					{
						mpr_variable.column_number = 0;
					}
				}


				// cèÌíñð¸ç·Aà¤È¯êÎI¹·é
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


//===============//
// Ú×   Fwè³ê½f[^ðIðÊuÌE¤Ìsà©çwè³ê½ñª¾¯í·é
// ø   Fint íñiOÅSÄíj, std::string í·é¶
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Delete_Data_Equal_This_Text_In_Now_Row_For_Right(int in_delete_num, std::string in_delete_text)
{
	//  Ïé¾  //
	int text_size = (int)in_delete_text.size();	// Tõ·é¶Ì¶
	int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// TõÂ\ÈÅåñ


	// ê¶Úªêv·é©ðJèÔµÄTõ
	for (int loop_column = mpr_variable.column_number; loop_column <= column_sum; loop_column++)
	{
		// ¯¶¶ª Á½çTõµ±¯é
		for (int check_x = 0; in_delete_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][(size_t)loop_column + check_x] && check_x < text_size; check_x++)
		{
			// ©Â©Á½çí·é
			if (check_x + 1 >= text_size)
			{
				// íÊuæèEÉ¶ªÈ¢ÈçíÊuÜÅði[
				if (mpr_variable.sentence_data[mpr_variable.row_number].size() <= (size_t)loop_column + text_size)
				{
					mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, loop_column);
				}

				// íÊuæèEÉ¶ª ÂÈçíÊuÌÝÈ­
				else
				{
					mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, loop_column) + mpr_variable.sentence_data[mpr_variable.row_number].substr((size_t)loop_column + text_size);
				}


				mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();


				// íÍÍàÉIðÌêª Á½çíÍÍÌ¶ÉÚ®·é
				if (loop_column <= mpr_variable.column_number && mpr_variable.column_number <= loop_column + text_size)
				{
					mpr_variable.column_number = loop_column - 1;


					// 0ÈºÉÍÈçÈ¢æ¤É·é
					if (mpr_variable.column_number < 0)
					{
						mpr_variable.column_number = 0;
					}
				}


				// cèÌíñð¸ç·Aà¤È¯êÎI¹·é
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


//===============//
// Ú×   Fwè³ê½f[^ðIðÊuÌ¶¤Ìsà©çwè³ê½ñª¾¯í·é
// ø   Fint íñiOÅSÄíj, std::string í·é¶
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Delete_Data_Equal_This_Text_In_Now_Row_For_Left(int in_delete_num, std::string in_delete_text)
{
	//  Ïé¾  //
	int text_size = (int)in_delete_text.size();	// Tõ·é¶Ì¶


	// ê¶Úªêv·é©ðJèÔµÄTõ
	for (int loop_column = mpr_variable.column_number; loop_column > -1; loop_column--)
	{
		// ¯¶¶ª Á½çTõµ±¯é
		for (int check_x = 0; in_delete_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][(size_t)loop_column + check_x] && check_x < text_size; check_x++)
		{
			// ©Â©Á½çí·é
			if (check_x + 1 >= text_size)
			{
				// íÊuæèEÉ¶ªÈ¢ÈçíÊuÜÅði[
				if (mpr_variable.sentence_data[mpr_variable.row_number].size() <= (size_t)loop_column + text_size)
				{
					mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, loop_column);
				}

				// íÊuæèEÉ¶ª ÂÈçíÊuÌÝÈ­
				else
				{
					mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, loop_column) + mpr_variable.sentence_data[mpr_variable.row_number].substr((size_t)loop_column + text_size);
				}


				mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();


				// íÍÍàÉIðÌêª Á½çíÍÍÌ¶ÉÚ®·é
				if (loop_column <= mpr_variable.column_number && mpr_variable.column_number <= loop_column + text_size)
				{
					mpr_variable.column_number = loop_column - 1;


					// 0ÈºÉÍÈçÈ¢æ¤É·é
					if (mpr_variable.column_number < 0)
					{
						mpr_variable.column_number = 0;
					}
				}


				// cèÌíñð¸ç·
				in_delete_num -= 1;


				// cèÌíñªà¤È¯êÎðI¹·é
				if (in_delete_num == 0)
				{
					return;
				}
			}
		}
	}

	return;
}


//===============//
// Ú×   Fwè³ê½sðí·é
// ø   Fint í·és
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Delete_Row(int in_delete_row)
{
	// ÅãÌsÌÍàeÌÝíµAPsÍ©Èç¸céæ¤É·éioOðh®½ßÉj
	if (mpr_variable.sentence_data.size() == 1)
	{
		mpr_variable.sentence_data[0].clear();
		mpr_variable.sentence_data[0].shrink_to_fit();

		return;
	}


	// íÊuª¡ÌÊuæèOÈçêsãÉ¸ç·
	if (in_delete_row <= mpr_variable.row_number)
	{
		mpr_variable.row_number -= 1;


		// 0ÈºÉÈçÈ¢æ¤É·é
		if (mpr_variable.row_number < 0)
		{
			mpr_variable.row_number = 0;
			mpr_variable.column_number = 0;
		}

		// ¡Ìsªí³êÄ¢½çêsãÌ¶ÍÌêÔEÉÚ®·é
		else if (in_delete_row == mpr_variable.row_number + 1)
		{
			mpr_variable.column_number = (int)mpr_variable.sentence_data[mpr_variable.row_number].size();
		}
	}

	// ÍÍOðwèµ½Æ«Íí¹¸ÉIíé
	else if (in_delete_row < 0 || (int)mpr_variable.sentence_data.size() <= in_delete_row)
	{
		return;
	}


	// íðs¤
	mpr_variable.sentence_data.erase(mpr_variable.sentence_data.begin() + in_delete_row);
	mpr_variable.sentence_data.shrink_to_fit();

	return;
}


//===============//
// Ú×   F¡Ìê©çwè³ê½¶ª¾¯¶ðí·éisÍ±¦È¢j
// ø   Fint í·é¶
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Delete_Column(int in_delete_num)
{
	//  íµÈ¢ÈçX[  //
	if (in_delete_num > 0)
	{
		return;
	}


	//  EûüÉí·éÆ«  //
	if (in_delete_num > 0)
	{
		//  í·é¶ªsàÉûÜçÈ¢ÈçsÜÅðí  //
		if (mpr_variable.sentence_data[mpr_variable.row_number].size() <= (size_t)mpr_variable.column_number + in_delete_num)
		{
			mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, mpr_variable.column_number);
			mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();

			return;
		}


		// sàÉûÜéÈçsÌÔ¾¯ðí·é
		mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, mpr_variable.column_number) + mpr_variable.sentence_data[mpr_variable.row_number].substr((size_t)mpr_variable.column_number + in_delete_num);
		mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();

		return;
	}


	//  ¶ûüÉí·éÆ«  //

	//  í·é¶ªsàÉûÜçÈ¢ÈçsÌÍ¶ÜèÜÅðí  //
	if (mpr_variable.column_number - in_delete_num < 0)
	{
		mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number);
		mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();

		return;
	}


	// sàÅûÜéÈçsÌÔ¾¯ðí·é
	mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, (size_t)mpr_variable.column_number - in_delete_num) + mpr_variable.sentence_data[mpr_variable.row_number].substr((size_t)mpr_variable.column_number + 1);
	mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();

	return;
}


//===============//
// Ú×   Ft@Cðí·é
// ø   Fvoid
// ßèl Fbool í·ét@Cª©Â©çÈ©Á½Aàµ­Íwè³ê½pXªfBNgð³·Èçfalse
//===============//
bool C_Text_And_File_Manager::M_Delete_Now_File(void)
{
	//  t@Cª©Â©çÈ¢ÈçG[ðÔ·  //
	if (M_Is_File(mpr_variable.file_path) == false)
	{
		return false;
	}


	//  t@Cðí·é  //
	std::filesystem::remove(mpr_variable.file_path);


	// íÉ¬÷
	return true;
}


//===============//
// Ú×   Ft@Cðí·é
// ø   Fstd::string t@CÜÅÌpX
// ßèl Fbool í·ét@Cª©Â©çÈ©Á½Aàµ­Íwè³ê½pXªfBNgð³·Èçfalse
//===============//
bool C_Text_And_File_Manager::M_Delete_Select_File(std::string is_file_path)
{
	//  t@Cª©Â©çÈ¢ÈçG[ðÔ·  //
	if (M_Is_File(is_file_path) == false)
	{
		return false;
	}


	//  t@Cðí·é  //
	std::filesystem::remove(is_file_path);


	// íÉ¬÷
	return true;
}


//===============//
// Ú×   Fwè³ê½tH_ðí·é
// ø   Fstd::string í·étH_ÜÅÌpX
// ßèl Fbool í·étH_ª©Â©çÈ©Á½çfalse
//===============//
bool C_Text_And_File_Manager::M_Delete_Select_Folder(std::string in_folder_path)
{
	//  tH_ª©Â©çÈ¢ÈçG[ðÔ·  //
	if (std::filesystem::is_directory(in_folder_path) == false)
	{
		return false;
	}


	//  t@Cðí·é  //
	std::filesystem::remove_all(in_folder_path);


	// íÉ¬÷
	return true;
}


//-- ÏX --//

//===============//
// Ú×   F»ÝÒWÌt@CÌt@C¼ðÏX·é
// ø   Fstd::string ÏXãÌt@C¼
// ßèl Fbool ÏXÉ¬÷µ½çtrue
//===============//
bool C_Text_And_File_Manager::M_Rename_Now_File(std::string in_after_name)
{
	//  t@Cª©Â©çÈ¢ÈçG[ðÔ·  //
	if (M_Is_File(mpr_variable.file_path) == false)
	{
		return false;
	}


	//  t@Cðí·é  //
	std::filesystem::rename(mpr_variable.file_path, in_after_name);


	// t@CÜÅÌpXðÏX
	mpr_variable.file_path = in_after_name;


	// ÏXÉ¬÷µ½
	return true;
}


//===============//
// Ú×   Fwè³ê½t@CÌt@C¼ðÏX·é
// ø   Fstd::string ÏXOÌt@C¼, std::string ÏXãÌt@C¼
// ßèl Fbool ÏXÉ¬÷µ½çtrue
//===============//
bool C_Text_And_File_Manager::M_Rename_Select_File(std::string in_before_name, std::string in_after_name)
{
	//  t@Cª©Â©çÈ¢ÈçG[ðÔ·  //
	if (M_Is_File(in_before_name) == false)
	{
		return false;
	}


	//  t@Cðí·é  //
	std::filesystem::rename(in_before_name, in_after_name);


	// ÏXÉ¬÷µ½
	return true;
}


//===============//
// Ú×   Fwè³ê½tH_ÌtH_¼ðÏX·é
// ø   Fstd::string ÏXOÌtH_¼, std::string ÏXãÌtH_¼
// ßèl Fbool ÏXÉ¬÷µ½çtrue
//===============//
bool C_Text_And_File_Manager::M_Rename_Select_Folder(std::string in_before_name, std::string in_after_name)
{
	//  tH_ª©Â©çÈ¢ÈçG[ðÔ·  //
	if (std::filesystem::is_directory(in_before_name) == false)
	{
		return false;
	}


	//  t@Cðí·é  //
	std::filesystem::rename(in_before_name, in_after_name);


	// ÏXÉ¬÷µ½
	return true;
}


//-- oÍ --//

//===============//
// Ú×   FüèpÌâðs¤CCÖAlüÍÌ¤ÊÌðPÂÌÖÉÜÆßé½ßÉg¤
// ø   Fint & ÝèæÌÏ, int Ýè·éf[^
// ßèl Fvoid
//===============//
inline void IM_Get_Number_Setting_System(long long& in_result_number, int in_set_number)
{
	in_result_number = in_result_number * 10 + in_set_number;

	return;
}


//===============//
// Ú×   F¡ÌêÌEÉª éêÍ»ÌðÔ·
// ø   Fvoid
// ßèl Flong long æèoµ½l
//===============//
long long C_Text_And_File_Manager::M_Get_Number(void)
{
	//  Ïé¾  //
	std::string serch_text = mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number);	// Tõ·é¶

	long long result_number = 0;	// ÊÌl

	int serch_sum = (int)serch_text.size();	// Tõ

	bool flg_minus = false;			// trueÌÍ}CiXl


	// ê¶ÃÂæèoµÄ¢­
	for (int check_x = 0; check_x < serch_sum; check_x++)
	{
		//  ¶ð¯ÊµÄlÉÏ·  //
		switch (serch_text[check_x])
		{
			//  0  //
		case 'O':
		case '0':
			IM_Get_Number_Setting_System(result_number, 0);
			break;

			//  1  //
		case 'P':
		case '1':
			IM_Get_Number_Setting_System(result_number, 1);
			break;

			//  2  //
		case 'Q':
		case '2':
			IM_Get_Number_Setting_System(result_number, 2);
			break;

			//  3  //
		case 'R':
		case '3':
			IM_Get_Number_Setting_System(result_number, 3);
			break;

			//  4  //
		case 'S':
		case '4':
			IM_Get_Number_Setting_System(result_number, 4);
			break;

			//  5  //
		case 'T':
		case '5':
			IM_Get_Number_Setting_System(result_number, 5);
			break;

			//  6  //
		case 'U':
		case '6':
			IM_Get_Number_Setting_System(result_number, 6);
			break;

			//  7  //
		case 'V':
		case '7':
			IM_Get_Number_Setting_System(result_number, 7);
			break;

			//  8  //
		case 'W':
		case '8':
			IM_Get_Number_Setting_System(result_number, 8);
			break;

			//  9  //
		case 'X':
		case '9':
			IM_Get_Number_Setting_System(result_number, 9);
			break;

			//  -  //
		case '-':

			// ê¶ÚÉ}CiXLª«½ç}CiXwè·é
			if (check_x == 0)
			{
				flg_minus = true;
			}

			// ê¶ÚÅÈ¯êÎI¹·é
			else
			{
				return result_number * ((size_t)1 - (size_t)flg_minus * 2);
			}

			break;

			//  +  //
		case '+':

			// ê¶ÚÈ~ÉvXLª½ç»±ÅI¹·é
			if (check_x > 0)
			{
				return result_number * ((size_t)1 - (size_t)flg_minus * 2);
			}

			break;

			//  ¶áÈ©Á½ç±±ÅIíé  //
		default:

			return result_number * ((size_t)1 - (size_t)flg_minus * 2);

			break;
		}
	}

	return result_number * ((size_t)1 - (size_t)flg_minus * 2);
}


//===============//
// Ú×   FüèpÌâðs¤CCÖAlüÍÌ¤ÊÌðPÂÌÖÉÜÆßé½ßÉg¤
// ø   Fint & ÝèæÌ®pÏ, double & ÝèæÌ­pÏ, int & ­§äpÏ, bool ÝèÌ[h, int Ýè·éf[^
// ßèl Fvoid
//===============//
inline void IM_Get_Float_Double_Number_Setting_System(int& in_number_data, double& in_floating_data, int& in_floating_multiple_num, bool in_flg_floating_mode, int in_set_number)
{
	// ®ì
	if (in_flg_floating_mode == false)
	{
		in_number_data = in_number_data * 10 + in_set_number;
	}

	// ­ì
	else
	{
		in_floating_data = in_floating_data + (double)in_set_number / (double)in_floating_multiple_num;
		in_floating_multiple_num *= 10;
	}

	return;
}

//===============//
// Ú×   F¡ÌêÌEÉª éêÍ»Ì­ èÌðÔ·
// ø   Fvoid
// ßèl Fdouble æèoµ½l
//===============//
double C_Text_And_File_Manager::M_Get_Float_Double_Number(void)
{
	//  Ïé¾  //
	std::string string_to_float_text = mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number);	// Ï··é¶

	return std::stod(string_to_float_text);
}


//===============//
// Ú×   F¡Ìê©çwè³ê½¶ªÔ·
// ø   Fint ¶
// ßèl Fstd::string Ô·¶
//===============//
std::string C_Text_And_File_Manager::M_Get_Data_By_Number(int in_text_num)
{
	//  sð´¦éÈç»ÌsÌÅãÌ¶ÜÅðÔ·  //
	if (mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number).size() <= (size_t)in_text_num + mpr_variable.column_number)
	{
		return mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number);
	}


	// sàÅ«èéÈç»ÌªðÔ·
	return mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number, in_text_num);
}


//===============//
// Ú×   F¡Ìê©çwè³ê½¶ÜÅðÔ·
// ø   Fstd::string Tõ·é¶
// ßèl Fstd::string Ô·¶@©Â©çÈ©Á½êÍA___Not_Founds___ðÔ·
//===============//
std::string C_Text_And_File_Manager::M_Get_Data_By_Text(std::string in_search_text)
{
	//  Ïé¾  //
	int text_size = (int)in_search_text.size();	// Tõ·é¶Ì¶
	int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// TõÂ\ÈÅåñ


	// ê¶Úªêv·é©ðJèÔµÄTõ
	for (int loop_column = mpr_variable.column_number + 1; loop_column <= column_sum; loop_column++)
	{
		// ¯¶¶ª Á½çTõµ±¯é
		for (int check_x = 0; in_search_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][(size_t)loop_column + check_x]; check_x++)
		{
			// ©Â©Á½ç»±ÜÅÌ¶ÍðÔ·
			if (check_x + 1 >= text_size)
			{
				return mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number, (size_t)loop_column - mpr_variable.column_number);
			}
		}
	}

	// È¯êÎ­©Å«È©Á½±ÆðÔ·
	return "___Not_Founds___";
}


//===============//
// Ú×   FsÌnÜè©çIðÌêÜÅðÔ·
// ø   Fvoid
// ßèl Fstd::string Ô·¶
//===============//
std::string C_Text_And_File_Manager::M_Get_Data_Left_In_Row(void)
{
	return mpr_variable.sentence_data[mpr_variable.row_number].substr(0, mpr_variable.column_number);
}


//===============//
// Ú×   FIðÌê©çsÜÅðÔ·
// ø   Fvoid
// ßèl Fstd::string Ô·¶
//===============//
std::string C_Text_And_File_Manager::M_Get_Data_Right_In_Row(void)
{
	return mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number);
}


//===============//
// Ú×   F¡ÌIðÌsÌnÜè©çIíèÜÅðÆé
// ø   Fvoid
// ßèl Fstd::string Ô·¶
//===============//
std::string C_Text_And_File_Manager::M_Get_Data_Now_Row(void)
{
	return mpr_variable.sentence_data[mpr_variable.row_number];
}


//-- ÒWÊu --//

//= ¼ÚÚ®n =//

//===============//
// Ú×   F¶ÌnÜèÉÚ®·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Goto_Sentence_Start(void)
{
	mpr_variable.row_number = 0;
	mpr_variable.column_number = 0;

	return;
}

//===============//
// Ú×   F¶ÌIíèÉÚ®·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Goto_Sentence_End(void)
{
	// êÔºÌsÖÚ®
	mpr_variable.row_number = (int)mpr_variable.sentence_data.size() - 1;

	// ¶ÌÊuðsàÌÅã©çæ¾
	mpr_variable.column_number = (int)mpr_variable.sentence_data[mpr_variable.row_number].size();

	return;
}


//===============//
// Ú×   FsÌnÜèÉÚ®·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Goto_Column_In_Row_Start(void)
{
	mpr_variable.column_number = 0;

	return;
}


//===============//
// Ú×   FsÌIíèÉÚ®·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Goto_Column_In_Row_End(void)
{
	mpr_variable.column_number = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - 1;

	return;
}


//===============//
// Ú×   FsÌnÜèÉÚ®·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Goto_Start_Row(void)
{
	mpr_variable.row_number = 0;

	return;
}


//===============//
// Ú×   FsÌnÜèÉÚ®·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Goto_End_Row(void)
{
	mpr_variable.row_number = (int)mpr_variable.sentence_data.size() - 1;

	return;
}


//===============//
// Ú×   Fwè³ê½sÉÚ®·é
// ø   FsÌÔ
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Goto_Row_By_Set_Number(unsigned int in_set_row)
{
	// lðZbg·é
	mpr_variable.row_number = in_set_row;


	// sª«èÄ¢È¯êÎâ·
	if (mpr_variable.sentence_data.size() <= mpr_variable.row_number)
	{
		mpr_variable.sentence_data.resize((size_t)mpr_variable.row_number + 1);
	}

	return;
}


//===============//
// Ú×   Fwè³ê½sÉÚ®·é
// ø   FñÌÔ
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Goto_Column_By_Set_Number(unsigned int in_set_column)
{
	// lðZbg·é
	mpr_variable.column_number = in_set_column;


	// ñª«èÄ¢È¯êÎâ·
	if (mpr_variable.sentence_data[mpr_variable.row_number].size() <= mpr_variable.column_number)
	{
		mpr_variable.sentence_data[mpr_variable.row_number].resize((size_t)mpr_variable.column_number + 1);
	}

	return;
}


//= ÔÚÚ®n ==//

//===============//
// Ú×   Fwè³ê½ªAÚ®·é
// ø   FÚ®Ê
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Move_Position_By_Number(int in_move_num)
{
	//  Ú®µÈ¢ÍX[  //
	if (in_move_num == 0)
	{
		return;
	}


	//  Ú®ª{ûüÌ  //
	if (in_move_num > 0)
	{
		//  ¡Ìê©çÌ»è  //

		// sàÅûÜéÈçñðÚ®ªÚ®³¹é
		if ((size_t)mpr_variable.column_number + in_move_num <= mpr_variable.sentence_data[mpr_variable.row_number].size())
		{
			mpr_variable.column_number += in_move_num;

			return;
		}


		// Tõªð¸ç·
		in_move_num -= (int)mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number).size();


		// ûÜçÈ¢Èç½ñÚÜÅs­©ðTõ·é
		for (mpr_variable.row_number += 1; mpr_variable.row_number < mpr_variable.sentence_data.size(); mpr_variable.row_number++)
		{
			// ±ÌsàÅûÜéÈçñðcèÌªÉÝè
			if (in_move_num < mpr_variable.sentence_data[mpr_variable.row_number].size())
			{
				mpr_variable.column_number = in_move_num;

				return;
			}


			// Tõªð¸ç·
			in_move_num -= (int)mpr_variable.sentence_data[mpr_variable.row_number].size();
		}


		// ÅãÜÅTõµ½ÌÉÜ¾¶ª éêÍÅãÌêÅÅ¿Øé
		mpr_variable.row_number = (int)mpr_variable.sentence_data.size() - 1;
		mpr_variable.column_number = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - 1;

		return;
	}


	//  Ú®ª-ûüÌ  //

	// {Å»fµ½ûªª©èâ·¢ÌÅÏ·
	in_move_num *= -1;


	// sàÅûÜéÈçñðÚ®ªÚ®³¹é
	if (mpr_variable.column_number - in_move_num > -1)
	{
		mpr_variable.column_number -= in_move_num;

		return;
	}


	// Tõªð¸ç·
	in_move_num -= (int)mpr_variable.sentence_data[mpr_variable.row_number].substr(0, mpr_variable.column_number).size();


	// ñàÅûÜçÈ¢Èç½ñÚÜÅs­©ðTõ·é
	for (mpr_variable.row_number -= 1; mpr_variable.row_number > -1; mpr_variable.row_number--)
	{
		// sàÅûÜéÈçñðÚ®ªÚ®³¹é
		if (mpr_variable.sentence_data[mpr_variable.row_number].size() - in_move_num > 0)
		{
			mpr_variable.column_number = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - (1 + in_move_num);

			return;
		}


		// Tõªð¸ç·
		in_move_num -= (int)mpr_variable.sentence_data[mpr_variable.row_number].size();
	}


	// êÔÅæèàãëðwè³êÄ¢½çêÔÅÅ¨íé
	mpr_variable.row_number = 0;
	mpr_variable.column_number = 0;

	return;
}


//===============//
// Ú×   Fwè³ê½ªAÚ®·é
// ø   FÚ®Ê
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Move_Raw_By_Number(int in_move_row_num)
{
	//  Ú®µÈ¢ÍX[  //
	if (in_move_row_num == 0)
	{
		return;
	}


	//  Ú®ª{ûüÌ  //
	if (in_move_row_num > 0)
	{
		// ãÀð´¦éÈçÅãÌsð¼Úwè
		if ((size_t)mpr_variable.row_number + (int)in_move_row_num > mpr_variable.sentence_data.size())
		{
			mpr_variable.row_number = (int)mpr_variable.sentence_data.size();

			return;
		}


		// ´¦È¢ÈçwèªÚ®³¹é
		mpr_variable.row_number += in_move_row_num;

		return;
	}


	//  Ú®ª-ûüÌ  //

	// {Å»fµ½ûªª©èâ·¢ÌÅÏ·
	in_move_row_num *= -1;


	// ´¦È¢ÈçwèªÚ®³¹é
	mpr_variable.row_number -= in_move_row_num;


	// êÔãð´¦éÈçÅÌsð¼Úwè
	if (mpr_variable.row_number < 0)
	{
		mpr_variable.row_number = 0;

		return;
	}

	return;
}


//===============//
// Ú×   FÌsÖÚ®·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Text_And_File_Manager::M_Move_Next_Raw(void)
{
	M_Move_Raw_By_Number(1);
	M_Goto_Column_By_Set_Number(0);

	return;
}


//= TõÚ®n =//

//===============//
// Ú×   Fwè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈ~ÅêÔß¢àÌð¶Í²Æ(üsàÜßÄ)TõµÄA»Ì¶ÌEÉÚ®·é
// ø   Fstring Tõ·é¶
// ßèl Fbool ÝÂ©çÈ¯êÎfalse
//===============//
bool C_Text_And_File_Manager::M_Goto_Right_By_Text_In_Front_Sentence(std::string in_serch_text)
{
	//  Ïé¾  //
	int line_sum = (int)mpr_variable.sentence_data.size();	// s
	int text_size = (int)in_serch_text.size();	// Tõ·é¶Ì¶


	//  IðÌsÌÌTõ  //
	{
		//  Ïé¾  //
		int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size();	// TõÂ\ÈÅåñ


		// ê¶Úªêv·é©ðJèÔµÄTõ
		for (int loop_column = mpr_variable.column_number; loop_column <= column_sum; loop_column++)
		{
			//  Ïé¾  //
			std::string stack_check_string = mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column);	// Tõp¶ñX^bN

			int stack_size = (int)stack_check_string.size();	// X^bNf[^ÌTCY
			int now_row_number = mpr_variable.row_number;	// ¡ÌsÌÔ
			int indented_time = 0;	// üsµ½ñ

			bool flg_not_this = false;	// f[^ª¯¶ÅÈ¢ð\·tO


			// ¯¶¶ª Á½çTõµ±¯é
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// üsR[hª éÈçÌsðÇÝÞ
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// Ìsª éÈçüs
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ÌsªKvÈÌÉÈ¢Èç±Ì¶Ì»èðÅãÉ·é
					else
					{
						flg_not_this = true;
					}
				}


				// á¤ÈçTõðâßé
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// ©Â©Á½ç»±ÉÚ®µÄI¹
				else if (check_x + 1 >= text_size)
				{
					// üsµÄ¢È©Á½ç¶ªÚ®
					if (indented_time == 0)
					{
						mpr_variable.column_number = loop_column + text_size;
					}

					// üsµÄ¢½ç»ÝÌTõÊuðTµÄÚ®
					else
					{
						text_size -= (int)mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column).size();

						for (int indent_cnt = 1; indent_cnt < indented_time; indent_cnt++)
						{
							text_size -= (int)mpr_variable.sentence_data[(size_t)mpr_variable.row_number + indent_cnt].size();
						}

						mpr_variable.column_number = text_size;
					}

					mpr_variable.row_number = now_row_number;

					return true;
				}


				// ÌêsªÅãÌ¶ð´¦éÈçüs·é
				if (check_x + 1 >= stack_size)
				{
					// Ìsª éÈçüs
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ÌsªKvÈÌÉÈ¢Èç±Ì¶Ì»èðÅãÉ·é
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}


	// Ìs©çwè³ê½¶ðTõ·é
	for (int loop_row = mpr_variable.row_number + 1; loop_row < line_sum; loop_row++)
	{
		//  Ïé¾  //
		int column_sum = (int)mpr_variable.sentence_data[loop_row].size();	// TõÂ\ÈÅåñ


		// ¯¶sÉ é©Ç¤©ð»è·é
		for (int loop_column = 0; loop_column <= column_sum; loop_column++)
		{
			//  Ïé¾  //
			std::string stack_check_string = mpr_variable.sentence_data[loop_row].substr(loop_column);	// Tõp¶ñX^bN

			int stack_size = (int)stack_check_string.size();	// X^bNf[^ÌTCY
			int now_row_number = loop_row;	// ¡ÌsÌÔ
			int indented_time = 0;	// üsµ½ñ

			bool flg_not_this = false;	// f[^ª¯¶ÅÈ¢ð\·tO


			// ¯¶¶ª Á½çTõµ±¯é
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// üsR[hª éÈçÌsðÇÝÞ
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// Ìsª éÈçüs
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ÌsªKvÈÌÉÈ¢Èç±Ì¶Ì»èðÅãÉ·é
					else
					{
						flg_not_this = true;
					}
				}


				// á¤ÈçTõðâßé
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// ©Â©Á½ç»±ÉÚ®µÄI¹
				else if (check_x + 1 >= text_size)
				{
					// üsµÄ¢È©Á½ç¶ªÚ®
					if (indented_time == 0)
					{
						mpr_variable.column_number = loop_column + text_size;
					}

					// üsµÄ¢½ç»ÝÌTõÊuðTµÄÚ®
					else
					{
						text_size -= (int)mpr_variable.sentence_data[loop_row].substr(loop_column).size();

						for (int indent_cnt = 1; indent_cnt < indented_time; indent_cnt++)
						{
							text_size -= (int)mpr_variable.sentence_data[(size_t)loop_row + indent_cnt].size();
						}

						mpr_variable.column_number = text_size;
					}

					mpr_variable.row_number = now_row_number;

					return true;
				}


				// ÌêsªÅãÌ¶ð´¦éÈçüs·é
				if (check_x + 1 >= stack_size)
				{
					// Ìsª éÈçüs
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ÌsªKvÈÌÉÈ¢Èç±Ì¶Ì»èðÅãÉ·é
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}

	// ÝÂ©çÈ©Á½
	return false;
}


//===============//
// Ú×   Fwè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈOÅêÔß¢àÌð¶Í²Æ(üsàÜßÄ)TõµÄA»Ì¶ÌEÉÚ®·é
// ø   Fstd::string Tõ·é¶
// ßèl Fbool ÝÂ©çÈ¯êÎfalse
//===============//
bool C_Text_And_File_Manager::M_Goto_Right_By_Text_In_Back_Sentence(std::string in_search_text)
{
	//  Ïé¾  //
	int line_sum = (int)mpr_variable.sentence_data.size();	// s
	int text_size = (int)in_search_text.size();	// Tõ·é¶Ì¶


	//  IðÌsÌÌTõ  //
	{
		//  Ïé¾  //
		int start_column = (int)mpr_variable.sentence_data[mpr_variable.row_number].size();	// TõJnÊu


		// ÊíÌTõJnÊuæèIðÊuª¶Å êÎTõJnÊuð¸ç·
		if (mpr_variable.column_number <= start_column)
		{
			start_column = mpr_variable.column_number - 1;
		}


		// ê¶Úªêv·é©ðJèÔµÄTõ
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			//  Ïé¾  //
			std::string stack_check_string = mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column);	// Tõp¶ñX^bN

			int stack_size = (int)stack_check_string.size();	// X^bNf[^ÌTCY
			int now_row_number = mpr_variable.row_number;	// ¡ÌsÌÔ
			int indented_time = 0;	// üsµ½ñ

			bool flg_not_this = false;	// f[^ª¯¶ÅÈ¢ð\·tO


			// ¯¶¶ª Á½çTõµ±¯é
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// üsR[hª éÈçÌsðÇÝÞ
				if (M_Is_CR(in_search_text[check_x]) == true)
				{
					// Ìsª éÈçüs
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ÌsªKvÈÌÉÈ¢Èç±Ì¶Ì»èðÅãÉ·é
					else
					{
						flg_not_this = true;
					}
				}


				// á¤ÈçTõðâßé
				if (in_search_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// ©Â©Á½ç»±ÉÚ®µÄI¹
				else if (check_x + 1 >= text_size)
				{
					// üsµÄ¢È©Á½ç¶ªÚ®
					if (indented_time == 0)
					{
						mpr_variable.column_number = loop_column + text_size;
					}

					// üsµÄ¢½ç»ÝÌTõÊuðTµÄÚ®
					else
					{
						text_size -= (int)mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column).size();

						for (int indent_cnt = 1; indent_cnt < indented_time; indent_cnt++)
						{
							text_size -= (int)mpr_variable.sentence_data[(size_t)mpr_variable.row_number + indent_cnt].size();
						}

						mpr_variable.column_number = text_size;
					}

					mpr_variable.row_number = now_row_number;

					return true;
				}


				// ÌêsªÅãÌ¶ð´¦éÈçüs·é
				if (check_x + 1 >= stack_size)
				{
					// Ìsª éÈçüs
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ÌsªKvÈÌÉÈ¢Èç±Ì¶Ì»èðÅãÉ·é
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}


	// êÂOÌs©çwè³ê½¶ðTõ·é
	for (int loop_row = mpr_variable.row_number - 1; loop_row > -1; loop_row--)
	{
		//  Ïé¾  //
		int start_column = (int)mpr_variable.sentence_data[loop_row].size();	// TõJnÊu


		// ê¶Úªêv·é©ðJèÔµÄTõ
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			//  Ïé¾  //
			std::string stack_check_string = mpr_variable.sentence_data[loop_row].substr(loop_column);	// Tõp¶ñX^bN

			int stack_size = (int)stack_check_string.size();	// X^bNf[^ÌTCY
			int now_row_number = loop_row;	// ¡ÌsÌÔ
			int indented_time = 0;	// üsµ½ñ

			bool flg_not_this = false;	// f[^ª¯¶ÅÈ¢ð\·tO


			// ¯¶¶ª Á½çTõµ±¯é
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// üsR[hª éÈçÌsðÇÝÞ
				if (M_Is_CR(in_search_text[check_x]) == true)
				{
					// Ìsª éÈçüs
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ÌsªKvÈÌÉÈ¢Èç±Ì¶Ì»èðÅãÉ·é
					else
					{
						flg_not_this = true;
					}
				}


				// á¤ÈçTõðâßé
				if (in_search_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// ©Â©Á½ç»±ÉÚ®µÄI¹
				else if (check_x + 1 >= text_size)
				{
					// üsµÄ¢È©Á½ç¶ªÚ®
					if (indented_time == 0)
					{
						mpr_variable.column_number = loop_column + text_size;
					}

					// üsµÄ¢½ç»ÝÌTõÊuðTµÄÚ®
					else
					{
						text_size -= (int)mpr_variable.sentence_data[loop_row].substr(loop_column).size();

						for (int indent_cnt = 1; indent_cnt < indented_time; indent_cnt++)
						{
							text_size -= (int)mpr_variable.sentence_data[(size_t)loop_row + indent_cnt].size();
						}

						mpr_variable.column_number = text_size;
					}

					mpr_variable.row_number = now_row_number;

					return true;
				}


				// ÌêsªÅãÌ¶ð´¦éÈçüs·é
				if (check_x + 1 >= stack_size)
				{
					// Ìsª éÈçüs
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ÌsªKvÈÌÉÈ¢Èç±Ì¶Ì»èðÅãÉ·é
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}

	// ÝÂ©çÈ©Á½
	return false;
}


//===============//
// Ú×   Fwè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈ~ÅêÔß¢àÌðs²ÆÉiüsÍÜß¸ÉjTõµÄA»Ì¶ÌEÉÚ®·é
// ø   Fstd::string Tõ·é¶
// ßèl Fbool ÝÂ©çÈ¯êÎfalse
//===============//
bool C_Text_And_File_Manager::M_Goto_Right_By_Text_In_Front_Row(std::string in_serch_text)
{
	//  Ïé¾  //
	int line_sum = (int)mpr_variable.sentence_data.size();	// s
	int text_size = (int)in_serch_text.size();	// Tõ·é¶Ì¶


	//  IðÌsÌÌTõ  //
	{
		//  Ïé¾  //
		int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// TõÂ\ÈÅåñ


		// ê¶Úªêv·é©ðJèÔµÄTõ
		for (int loop_column = mpr_variable.column_number; loop_column <= column_sum; loop_column++)
		{
			// ¯¶¶ª Á½çTõµ±¯é
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][(size_t)loop_column + check_x] && check_x < text_size; check_x++)
			{
				// ©Â©Á½ç»±ÉÚ®µÄI¹
				if (check_x + 1 >= text_size)
				{
					mpr_variable.column_number = loop_column + text_size;

					return true;
				}
			}
		}
	}


	// Ìs©çwè³ê½¶ðTõ·é
	for (int loop_row = mpr_variable.row_number + 1; loop_row < line_sum; loop_row++)
	{
		//  Ïé¾  //
		int column_sum = (int)mpr_variable.sentence_data[loop_row].size() - text_size;	// TõÂ\ÈÅåñ


		// ê¶Úªêv·é©ðJèÔµÄTõ
		for (int loop_column = 0; loop_column <= column_sum; loop_column++)
		{
			// ¯¶¶ª Á½çTõµ±¯é
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[loop_row][(size_t)loop_column + check_x] && check_x < text_size; check_x++)
			{
				// ©Â©Á½ç»±ÉÚ®µÄI¹
				if (check_x + 1 >= text_size)
				{
					mpr_variable.row_number = loop_row;
					mpr_variable.column_number = loop_column + text_size;

					return true;
				}
			}
		}
	}

	// ÝÂ©çÈ©Á½
	return false;
}


//===============//
// Ú×   Fwè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈOÅêÔß¢àÌðs²ÆÉiüsÍÜß¸ÉjTõµÄA»Ì¶ÌEÉÚ®·é
// ø   Fstd::string Tõ·é¶
// ßèl Fbool ÝÂ©çÈ¯êÎfalse
//===============//
bool C_Text_And_File_Manager::M_Goto_Right_By_Text_In_Back_Row(std::string in_serch_text)
{
	//  Ïé¾  //
	int text_size = (int)in_serch_text.size();	// Tõ·é¶Ì¶


	//  IðÌsÌÌTõ  //
	{
		//  Ïé¾  //
		int start_column = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// TõJnÊu


		// ÊíÌTõJnÊuæèIðÊuª¶Å êÎTõJnÊuð¸ç·
		if (mpr_variable.column_number <= start_column)
		{
			start_column = mpr_variable.column_number - 1;
		}


		// ê¶Úªêv·é©ðJèÔµÄTõ
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			// ¯¶¶ª Á½çTõµ±¯é
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][(size_t)loop_column + check_x] && check_x < text_size; check_x++)
			{
				// ©Â©Á½ç»±ÉÚ®µÄI¹
				if (check_x + 1 >= text_size)
				{
					// ¯¶êÉAÁÄ«Ä¢È¯êÎÚ®·éiAÁ½êÍ±±ÅX[·êÎ[vð²¯éj
					if (mpr_variable.column_number != loop_column + text_size)
					{
						mpr_variable.column_number = loop_column + text_size;

						return true;
					}
				}
			}
		}
	}


	// êÂOÌs©çwè³ê½¶ðTõ·é
	for (int loop_row = mpr_variable.row_number - 1; loop_row > -1; loop_row--)
	{
		//  Ïé¾  //
		int start_column = (int)mpr_variable.sentence_data[loop_row].size() - text_size;	// TõJnÊu


		// ÊíÌTõJnÊuæèIðÊuª¶Å êÎTõJnÊuð¸ç·
		if (mpr_variable.column_number <= start_column)
		{
			start_column = mpr_variable.column_number - 1;
		}


		// ê¶Úªêv·é©ðJèÔµÄTõ
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			// ¯¶¶ª Á½çTõµ±¯é
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[loop_row][(size_t)loop_column + check_x] && check_x < text_size; check_x++)
			{
				// ©Â©Á½ç»±ÉÚ®µÄI¹
				if (check_x + 1 >= text_size)
				{
					mpr_variable.row_number = loop_row;
					mpr_variable.column_number = loop_column + text_size;

					return true;
				}
			}
		}
	}

	// ÝÂ©çÈ©Á½
	return false;
}


//===============//
// Ú×   Fwè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈOÅêÔß¢àÌðs²ÆÉiüsÍÜß¸ÉjTõµÄA»Ì¶ÌEÉÚ®·é
// ø   Fstd::string Tõ·é¶
// ßèl Fbool ÝÂ©çÈ¯êÎfalse
//===============//
bool C_Text_And_File_Manager::M_Goto_Right_By_Text_In_Front_Column(std::string in_serch_text)
{
	//  Ïé¾  //
	int text_size = (int)in_serch_text.size();	// Tõ·é¶Ì¶
	int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// TõÂ\ÈÅåñ


	// ê¶Úªêv·é©ðJèÔµÄTõ
	for (int loop_column = mpr_variable.column_number; loop_column <= column_sum; loop_column++)
	{
		// ¯¶¶ª Á½çTõµ±¯é
		for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][(size_t)loop_column + check_x] && check_x < text_size; check_x++)
		{
			// ©Â©Á½ç»±ÉÚ®µÄI¹
			if (check_x + 1 >= text_size)
			{
				mpr_variable.column_number = loop_column + text_size;

				return true;
			}
		}
	}

	// ÝÂ©çÈ©Á½
	return false;
}


//===============//
// Ú×   Fwè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈOÅêÔß¢àÌðs²ÆÉiüsÍÜß¸ÉjTõµÄA»Ì¶ÌEÉÚ®·é
// ø   Fstd::string Tõ·é¶
// ßèl Fbool ÝÂ©çÈ¯êÎfalse
//===============//
bool C_Text_And_File_Manager::M_Goto_Right_By_Text_In_Back_Column(std::string in_serch_text)
{
	//  Ïé¾  //
	int text_size = (int)in_serch_text.size();	// Tõ·é¶Ì¶
	int start_column = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// TõJnÊu


	// ÊíÌTõJnÊuæèIðÊuª¶Å êÎTõJnÊuð¸ç·
	if (mpr_variable.column_number <= start_column)
	{
		start_column = mpr_variable.column_number - 1;
	}


	// ê¶Úªêv·é©ðJèÔµÄTõ
	for (int loop_column = start_column; loop_column > -1; loop_column--)
	{
		// ¯¶¶ª Á½çTõµ±¯é
		for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][(size_t)loop_column + check_x] && check_x < text_size; check_x++)
		{
			// ©Â©Á½ç»±ÉÚ®µÄI¹
			if (check_x + 1 >= text_size)
			{
				// ¯¶êÉAÁÄ«Ä¢È¯êÎÚ®·éiAÁ½êÍ±±ÅX[·êÎ[vð²¯éj
				if (mpr_variable.column_number != loop_column + text_size)
				{
					mpr_variable.column_number = loop_column + text_size;

					return true;
				}
			}
		}
	}

	// ÝÂ©çÈ©Á½
	return false;
}


//===============//
// Ú×   Fwè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈ~ÅêÔß¢àÌð¶Í²Æ(üsàÜßÄ)TõµÄA»Ì¶Ì¶ÉÚ®·é
// ø   Fstd::string Tõ·é¶
// ßèl Fbool ÝÂ©çÈ¯êÎfalse
//===============//
bool C_Text_And_File_Manager::M_Goto_Left_By_Text_In_Front_Sentence(std::string in_serch_text)
{
	//  Ïé¾  //
	int line_sum = (int)mpr_variable.sentence_data.size();	// s
	int text_size = (int)in_serch_text.size();	// Tõ·é¶Ì¶


	//  IðÌsÌÌTõ  //
	{
		//  Ïé¾  //
		int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size();	// TõÂ\ÈÅåñ


		// ê¶Úªêv·é©ðJèÔµÄTõ
		for (int loop_column = mpr_variable.column_number + 1; loop_column <= column_sum; loop_column++)
		{
			//  Ïé¾  //
			std::string stack_check_string = mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column);	// Tõp¶ñX^bN

			int stack_size = (int)stack_check_string.size();	// X^bNf[^ÌTCY
			int now_row_number = mpr_variable.row_number;	// ¡ÌsÌÔ
			int indented_time = 0;	// üsµ½ñ

			bool flg_not_this = false;	// f[^ª¯¶ÅÈ¢ð\·tO


			// ¯¶¶ª Á½çTõµ±¯é
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// üsR[hª éÈçÌsðÇÝÞ
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// Ìsª éÈçüs
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ÌsªKvÈÌÉÈ¢Èç±Ì¶Ì»èðÅãÉ·é
					else
					{
						flg_not_this = true;
					}
				}


				// á¤ÈçTõðâßé
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// ©Â©Á½ç»±ÉÚ®µÄI¹
				else if (check_x + 1 >= text_size)
				{
					// üsµÄ¢È©Á½ç¶ªÚ®
					if (indented_time == 0)
					{
						mpr_variable.column_number = loop_column + text_size;
					}

					// üsµÄ¢½ç»ÝÌTõÊuðTµÄÚ®
					else
					{
						text_size -= (int)mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column).size();

						for (int indent_cnt = 1; indent_cnt < indented_time; indent_cnt++)
						{
							text_size -= (int)mpr_variable.sentence_data[(size_t)mpr_variable.row_number + indent_cnt].size();
						}

						mpr_variable.column_number = text_size;
					}

					mpr_variable.row_number = now_row_number;

					return true;
				}


				// ÌêsªÅãÌ¶ð´¦éÈçüs·é
				if (check_x + 1 >= stack_size)
				{
					// Ìsª éÈçüs
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ÌsªKvÈÌÉÈ¢Èç±Ì¶Ì»èðÅãÉ·é
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}


	// Ìs©çwè³ê½¶ðTõ·é
	for (int loop_row = mpr_variable.row_number + 1; loop_row < line_sum; loop_row++)
	{
		//  Ïé¾  //
		int column_sum = (int)mpr_variable.sentence_data[loop_row].size();	// TõÂ\ÈÅåñ


		// ¯¶sÉ é©Ç¤©ð»è·é
		for (int loop_column = 0; loop_column <= column_sum; loop_column++)
		{
			//  Ïé¾  //
			std::string stack_check_string = mpr_variable.sentence_data[loop_row].substr(loop_column);	// Tõp¶ñX^bN

			int stack_size = (int)stack_check_string.size();	// X^bNf[^ÌTCY
			int now_row_number = loop_row;	// ¡ÌsÌÔ
			int indented_time = 0;	// üsµ½ñ

			bool flg_not_this = false;	// f[^ª¯¶ÅÈ¢ð\·tO


			// ¯¶¶ª Á½çTõµ±¯é
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// üsR[hª éÈçÌsðÇÝÞ
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// Ìsª éÈçüs
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ÌsªKvÈÌÉÈ¢Èç±Ì¶Ì»èðÅãÉ·é
					else
					{
						flg_not_this = true;
					}
				}


				// á¤ÈçTõðâßé
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// ©Â©Á½ç»±ÉÚ®µÄI¹
				else if (check_x + 1 >= text_size)
				{
					// üsµÄ¢È©Á½ç¶ªÚ®
					if (indented_time == 0)
					{
						mpr_variable.column_number = loop_column + text_size;
					}

					// üsµÄ¢½ç»ÝÌTõÊuðTµÄÚ®
					else
					{
						text_size -= (int)mpr_variable.sentence_data[loop_row].substr(loop_column).size();

						for (int indent_cnt = 1; indent_cnt < indented_time; indent_cnt++)
						{
							text_size -= (int)mpr_variable.sentence_data[(size_t)loop_row + indent_cnt].size();
						}

						mpr_variable.column_number = text_size;
					}

					mpr_variable.row_number = now_row_number;

					return true;
				}


				// ÌêsªÅãÌ¶ð´¦éÈçüs·é
				if (check_x + 1 >= stack_size)
				{
					// Ìsª éÈçüs
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ÌsªKvÈÌÉÈ¢Èç±Ì¶Ì»èðÅãÉ·é
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}

	// ÝÂ©çÈ©Á½
	return false;
}


//===============//
// Ú×   Fwè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈOÅêÔß¢àÌð¶Í²Æ(üsàÜßÄ)TõµÄA»Ì¶Ì¶ÉÚ®·é
// ø   Fstd::string Tõ·é¶
// ßèl Fbool ÝÂ©çÈ¯êÎfalse
//===============//
bool C_Text_And_File_Manager::M_Goto_Left_By_Text_In_Back_Sentence(std::string in_serch_text)
{
	//  Ïé¾  //
	int line_sum = (int)mpr_variable.sentence_data.size();	// s
	int text_size = (int)in_serch_text.size();	// Tõ·é¶Ì¶


	//  IðÌsÌÌTõ  //
	{
		//  Ïé¾  //
		int start_column = (int)mpr_variable.sentence_data[mpr_variable.row_number].size();	// TõJnÊu


		// ÊíÌTõJnÊuæèIðÊuª¶Å êÎTõJnÊuð¸ç·
		if (mpr_variable.column_number <= start_column)
		{
			start_column = mpr_variable.column_number - 1;
		}


		// ê¶Úªêv·é©ðJèÔµÄTõ
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			//  Ïé¾  //
			std::string stack_check_string = mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column);	// Tõp¶ñX^bN

			int stack_size = (int)stack_check_string.size();	// X^bNf[^ÌTCY
			int now_row_number = mpr_variable.row_number;	// ¡ÌsÌÔ

			bool flg_not_this = false;	// f[^ª¯¶ÅÈ¢ð\·tO


			// ¯¶¶ª Á½çTõµ±¯é
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// üsR[hª éÈçÌsðÇÝÞ
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// Ìsª éÈçüs
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ÌsªKvÈÌÉÈ¢Èç±Ì¶Ì»èðÅãÉ·é
					else
					{
						flg_not_this = true;
					}
				}


				// á¤ÈçTõðâßé
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// ©Â©Á½ç»±ÉÚ®µÄI¹
				else if (check_x + 1 >= text_size)
				{
					mpr_variable.row_number = now_row_number;
					mpr_variable.column_number = loop_column;

					return true;
				}


				// ÌêsªÅãÌ¶ð´¦éÈçüs·é
				if (check_x + 1 >= stack_size)
				{
					// Ìsª éÈçüs
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ÌsªKvÈÌÉÈ¢Èç±Ì¶Ì»èðÅãÉ·é
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}


	// êÂOÌs©çwè³ê½¶ðTõ·é
	for (int loop_row = mpr_variable.row_number - 1; loop_row > -1; loop_row--)
	{
		//  Ïé¾  //
		int start_column = (int)mpr_variable.sentence_data[loop_row].size();	// TõJnÊu


		// ê¶Úªêv·é©ðJèÔµÄTõ
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			//  Ïé¾  //
			std::string stack_check_string = mpr_variable.sentence_data[loop_row].substr(loop_column);	// Tõp¶ñX^bN

			int stack_size = (int)stack_check_string.size();	// X^bNf[^ÌTCY
			int now_row_number = loop_row;	// ¡ÌsÌÔ

			bool flg_not_this = false;	// f[^ª¯¶ÅÈ¢ð\·tO


			// ¯¶¶ª Á½çTõµ±¯é
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// üsR[hª éÈçÌsðÇÝÞ
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// Ìsª éÈçüs
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ÌsªKvÈÌÉÈ¢Èç±Ì¶Ì»èðÅãÉ·é
					else
					{
						flg_not_this = true;
					}
				}


				// á¤ÈçTõðâßé
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// ©Â©Á½ç»±ÉÚ®µÄI¹
				else if (check_x + 1 >= text_size)
				{
					mpr_variable.row_number = now_row_number;
					mpr_variable.column_number = loop_column;

					return true;
				}


				// ÌêsªÅãÌ¶ð´¦éÈçüs·é
				if (check_x + 1 >= stack_size)
				{
					// Ìsª éÈçüs
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ÌsªKvÈÌÉÈ¢Èç±Ì¶Ì»èðÅãÉ·é
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}

	// ÝÂ©çÈ©Á½
	return false;
}


//===============//
// Ú×   Fwè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈ~ÅêÔß¢àÌðs²ÆÉiüsÍÜß¸ÉjTõµÄA»Ì¶Ì¶ÉÚ®·é
// ø   Fstd::string Tõ·é¶
// ßèl Fbool ÝÂ©çÈ¯êÎfalse
//===============//
bool C_Text_And_File_Manager::M_Goto_Left_By_Text_In_Front_Row(std::string in_serch_text)
{
	//  Ïé¾  //
	int line_sum = (int)mpr_variable.sentence_data.size();	// s
	int text_size = (int)in_serch_text.size();	// Tõ·é¶Ì¶


	//  IðÌsÌÌTõ  //
	{
		//  Ïé¾  //
		int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// TõÂ\ÈÅåñ


		// ê¶Úªêv·é©ðJèÔµÄTõ
		for (int loop_column = mpr_variable.column_number + 1; loop_column <= column_sum; loop_column++)
		{
			// ¯¶¶ª Á½çTõµ±¯é
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][(size_t)loop_column + check_x] && check_x < text_size; check_x++)
			{
				// ©Â©Á½ç»±ÉÚ®µÄI¹
				if (check_x + 1 >= text_size)
				{
					mpr_variable.column_number = loop_column;

					return true;
				}
			}
		}
	}


	// Ìs©çwè³ê½¶ðTõ·é
	for (int loop_row = mpr_variable.row_number + 1; loop_row < line_sum; loop_row++)
	{
		//  Ïé¾  //
		int column_sum = (int)mpr_variable.sentence_data[loop_row].size() - text_size;	// TõÂ\ÈÅåñ


		// ê¶Úªêv·é©ðJèÔµÄTõ
		for (int loop_column = 0; loop_column <= column_sum; loop_column++)
		{
			// ¯¶¶ª Á½çTõµ±¯é
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[loop_row][(size_t)loop_column + check_x] && check_x < text_size; check_x++)
			{
				// ©Â©Á½ç»±ÉÚ®µÄI¹
				if (check_x + 1 >= text_size)
				{
					mpr_variable.row_number = loop_row;
					mpr_variable.column_number = loop_column;

					return true;
				}
			}
		}
	}

	// ÝÂ©çÈ©Á½
	return false;
}


//===============//
// Ú×   Fwè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈOÅêÔß¢àÌðs²ÆÉiüsÍÜß¸ÉjTõµÄA»Ì¶Ì¶ÉÚ®·é
// ø   Fstd::string Tõ·é¶
// ßèl Fbool ÝÂ©çÈ¯êÎfalse
//===============//
bool C_Text_And_File_Manager::M_Goto_Left_By_Text_In_Back_Row(std::string in_serch_text)
{
	//  Ïé¾  //
	int text_size = (int)in_serch_text.size();	// Tõ·é¶Ì¶


	//  IðÌsÌÌTõ  //
	{
		//  Ïé¾  //
		int start_column = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// TõJnÊu


		// ÊíÌTõJnÊuæèIðÊuª¶Å êÎTõJnÊuð¸ç·
		if (mpr_variable.column_number <= start_column)
		{
			start_column = mpr_variable.column_number - 1;
		}


		// ê¶Úªêv·é©ðJèÔµÄTõ
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			// ¯¶¶ª Á½çTõµ±¯é
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][(size_t)loop_column + check_x] && check_x < text_size; check_x++)
			{
				// ©Â©Á½ç»±ÉÚ®µÄI¹
				if (check_x + 1 >= text_size)
				{
					mpr_variable.column_number = loop_column;

					return true;
				}
			}
		}
	}


	// êÂOÌs©çwè³ê½¶ðTõ·é
	for (int loop_row = mpr_variable.row_number - 1; loop_row > -1; loop_row--)
	{
		//  Ïé¾  //
		int start_column = (int)mpr_variable.sentence_data[loop_row].size() - text_size;	// TõJnÊu


		// ÊíÌTõJnÊuæèIðÊuª¶Å êÎTõJnÊuð¸ç·
		if (mpr_variable.column_number <= start_column)
		{
			start_column = mpr_variable.column_number - 1;
		}


		// ê¶Úªêv·é©ðJèÔµÄTõ
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			// ¯¶¶ª Á½çTõµ±¯é
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[loop_row][(size_t)loop_column + check_x] && check_x < text_size; check_x++)
			{
				// ©Â©Á½ç»±ÉÚ®µÄI¹
				if (check_x + 1 >= text_size)
				{
					mpr_variable.row_number = loop_row;
					mpr_variable.column_number = loop_column;

					return true;
				}
			}
		}
	}

	// ÝÂ©çÈ©Á½
	return false;
}


//===============//
// Ú×   Fwè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈ~ÅêÔß¢àÌðIðÌsàÅTõµÄA»Ì¶Ì¶ÉÚ®·é
// ø   Fstd::string Tõ·é¶
// ßèl Fbool ÝÂ©çÈ¯êÎfalse
//===============//
bool C_Text_And_File_Manager::M_Goto_Left_By_Text_In_Front_Column(std::string in_serch_text)
{
	//  Ïé¾  //
	int text_size = (int)in_serch_text.size();	// Tõ·é¶Ì¶
	int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// TõÂ\ÈÅåñ


	// ê¶Úªêv·é©ðJèÔµÄTõ
	for (int loop_column = mpr_variable.column_number + 1; loop_column <= column_sum; loop_column++)
	{
		// ¯¶¶ª Á½çTõµ±¯é
		for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][(size_t)loop_column + check_x] && check_x < text_size; check_x++)
		{
			// ©Â©Á½ç»±ÉÚ®µÄI¹
			if (check_x + 1 >= text_size)
			{
				mpr_variable.column_number = loop_column;

				return true;
			}
		}
	}

	// ÝÂ©çÈ©Á½
	return false;
}


//===============//
// Ú×   Fwè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈOÅêÔß¢àÌðIðÌsàÅTõµÄA»Ì¶Ì¶ÉÚ®·é
// ø   Fstd::string Tõ·é¶
// ßèl Fbool ÝÂ©çÈ¯êÎfalse
//===============//
bool C_Text_And_File_Manager::M_Goto_Left_By_Text_In_Back_Column(std::string in_search_text)
{
	//  Ïé¾  //
	int text_size = (int)in_search_text.size();	// Tõ·é¶Ì¶
	int start_column = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// TõJnÊu


	// ÊíÌTõJnÊuæèIðÊuª¶Å êÎTõJnÊuð¸ç·
	if (mpr_variable.column_number <= start_column)
	{
		start_column = mpr_variable.column_number - 1;
	}


	// ê¶Úªêv·é©ðJèÔµÄTõ
	for (int loop_column = start_column; loop_column > -1; loop_column--)
	{
		// ¯¶¶ª Á½çTõµ±¯é
		for (int check_x = 0; in_search_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][(size_t)loop_column + check_x] && check_x < text_size; check_x++)
		{
			// ©Â©Á½ç»±ÉÚ®µÄI¹
			if (check_x + 1 >= text_size)
			{
				mpr_variable.column_number = loop_column;

				return true;
			}
		}
	}

	// ÝÂ©çÈ©Á½
	return false;
}


//-- ¶Tõ --//

//===============//
// Ú×   F¡IðÌsÉwè³ê½¶ªIðÌñà é©Ç¤©ðÔ·
// ø   Fstd::string Tõ·é¶
// ßèl Fbool ÝÂ©çÈ¯êÎfalse
//===============//
bool C_Text_And_File_Manager::M_Search_Text_In_Sentence(std::string in_serch_text)
{
	//  Ïé¾  //
	int line_sum = (int)mpr_variable.sentence_data.size();	// s
	int text_size = (int)in_serch_text.size();	// Tõ·é¶Ì¶


	// Ìs©çwè³ê½¶ðTõ·é
	for (int loop_row = 0; loop_row < line_sum; loop_row++)
	{
		//  Ïé¾  //
		int column_sum = (int)mpr_variable.sentence_data[loop_row].size();	// TõÂ\ÈÅåñ


		// ¯¶sÉ é©Ç¤©ð»è·é
		for (int loop_column = 0; loop_column <= column_sum; loop_column++)
		{
			//  Ïé¾  //
			std::string stack_check_string = mpr_variable.sentence_data[loop_row].substr(loop_column);	// Tõp¶ñX^bN

			int stack_size = (int)stack_check_string.size();	// X^bNf[^ÌTCY
			int now_row_number = loop_row;	// ¡ÌsÌÔ

			bool flg_not_this = false;	// f[^ª¯¶ÅÈ¢ð\·tO


			// ¯¶¶ª Á½çTõµ±¯é
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// üsR[hª éÈçÌsðÇÝÞ
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// Ìsª éÈçüs
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ÌsªKvÈÌÉÈ¢Èç±Ì¶Ì»èðÅãÉ·é
					else
					{
						flg_not_this = true;
					}
				}


				// á¤ÈçTõðâßé
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// ©Â©Á½ÌÅ»Ì±Æð¦µÄI¹
				else if (check_x + 1 >= text_size)
				{
					return true;
				}


				// ÌêsªÅãÌ¶ð´¦éÈçüs·é
				if (check_x + 1 >= stack_size)
				{
					// Ìsª éÈçüs
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// ÌsªKvÈÌÉÈ¢Èç±Ì¶Ì»èðÅãÉ·é
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}

	// ÝÂ©çÈ©Á½
	return false;
}


//===============//
// Ú×   F¡IðÌsÉwè³ê½¶ªIðÌñà é©Ç¤©ðÔ·
// ø   Fstd::string Tõ·é¶
// ßèl Fbool ÝÂ©çÈ¯êÎfalse
//===============//
bool C_Text_And_File_Manager::M_Search_Text_In_Now_Row(std::string in_search_text)
{
	//  Ïé¾  //
	int text_size = (int)in_search_text.size();	// Tõ·é¶Ì¶
	int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// ñ


	// ¯¶sÉ é©Ç¤©ð»è·é
	for (int loop_column = 0; loop_column <= column_sum; loop_column++)
	{
		// ¯¶¶ª Á½çTõµ±¯é
		for (int check_x = 0; in_search_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][(size_t)loop_column + check_x] && check_x < text_size; check_x++)
		{
			// ©Â©Á½ÌÅ»Ì±Æð¦µÄI¹
			if (check_x + 1 >= text_size)
			{
				return true;
			}
		}
	}

	// ÝÂ©çÈ©Á½
	return false;
}


//===============//
// Ú×   Fwè³ê½¶ªwè³ê½ñà é©Ç¤©ðÔ·
// ø   Fint Tõ·és, std::string Tõ·é¶
// ßèl Fbool ÝÂ©çÈ¯êÎfalse
//===============//
bool C_Text_And_File_Manager::M_Search_Text_In_Select_Row(int in_select_row, std::string in_search_text)
{
	//  Ïé¾  //
	int text_size = (int)in_search_text.size();	// Tõ·é¶Ì¶
	int column_sum = (int)mpr_variable.sentence_data[in_select_row].size() - text_size;	// ñ


	// sÌÍÍOðwè³ê½çG[
	if (in_select_row < 0 || mpr_variable.sentence_data.size() <= in_select_row)
	{
		return false;
	}


	// ¯¶sÉ é©Ç¤©ð»è·é
	for (int loop_column = 0; loop_column <= column_sum; loop_column++)
	{
		// ¯¶¶ª Á½çTõµ±¯é
		for (int check_x = 0; in_search_text[check_x] == mpr_variable.sentence_data[in_select_row][(size_t)loop_column + check_x] && check_x < text_size; check_x++)
		{
			// ©Â©Á½ÌÅ»Ì±Æð¦µÄI¹
			if (check_x + 1 >= text_size)
			{
				return true;
			}
		}
	}

	// ÝÂ©çÈ©Á½
	return false;
}


//-- »è --//

//===============//
// Ú×   F¡IðÌê©ç¶ªêvµÄ¢é©ð²×é
// ø   Fstd::string Tõ·é¶
// ßèl Fbool êvµ½Æ«ÌÝtrue
//===============//
bool C_Text_And_File_Manager::M_Check_Text_Is_Equal_Now_Position(std::string in_search_text)
{
	//  Ïé¾  //
	int text_size = (int)in_search_text.size();	// Tõ·é¶Ì¶


	// wè³ê½¶Ì¶ª¡©çTõ·éÍÍð´¦éÈçá¤¶ñÈÌÅá¤±Æð¦·
	if (mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number).size() < text_size)
	{
		return false;
	}


	// ÅÌ¶©çêvµ±¯é©Ç¤©ðØ·é
	for (int check_x = 0; in_search_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][(size_t)check_x + mpr_variable.column_number] && check_x < text_size; check_x++)
	{
		// ÅãÜÅêvµ±¯½ç©Â©Á½±Æð¦µÄ²¯é
		if (check_x + 1 >= text_size)
		{
			return true;
		}
	}

	// á¤±Æð¦·
	return false;
}


//===============//
// Ú×   Ft@Cª é©Ç¤©ð»è·é
// ø   Fstd::string t@CÜÅÌpX
// ßèl Fbool ÝÂ©Á½çtrue
//===============//
bool C_Text_And_File_Manager::M_Is_File_Exist(std::string in_path_string)
{
	//  Ïé¾  //
	std::fstream f_file_system(in_path_string, std::ios_base::in);	// t@CìpNXAÇÝÝÅé¾


	// t@CðJ¯Ä¢È¯êÎG[ðÔµÄI¹
	if (!f_file_system)
	{
		f_file_system.close();
		return false;
	}


	// t@CðÂ¶é
	f_file_system.close();

	return true;
}


