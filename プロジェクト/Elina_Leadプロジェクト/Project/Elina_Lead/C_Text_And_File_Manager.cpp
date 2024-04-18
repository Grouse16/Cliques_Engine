//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ファイル制御用システムのクラス
// 説明   ：ファイルを生成し、データを記録できる
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include <string.h>
#include <fstream>
#include <sys/stat.h>
#include <filesystem>

#include "C_Text_And_File_Manager.h"


// ☆ ネームスペース ☆ //
using namespace SYSTEM::TEXT;


// ☆ セキュリティアウト ☆ //
#define _CRT_SECURE_NO_WARNINGS	// セキュリティによる警告を行わない


// ☆ 関数定義 ☆ //

//==☆ プライベート ☆==//

//-☆- データ検証 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：入力されたパス名がバグを引き起こさないものかどうかを判定する
// 引数   ：std::string & パス名
// 戻り値 ：bool 正しければtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Is_File_Path_Succeed(std::string& in_check_path_name)
{
	// パス名が空文字なら間違い
	if (in_check_path_name.size() <= 0)
	{
		return false;
	}


	// ☆ パス名かディレクトリが存在していないならそれも間違い ☆ //
	if (M_Is_CR(in_check_path_name[0]) == true || M_Is_CR(in_check_path_name[in_check_path_name.size() - 1]) == true)
	{
		return false;
	}

	
	// パス名は正当である
	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：入力されたパス名がバグを引き起こさないものかどうかを判定する
// 引数   ：std::string & パス名
// 戻り値 ：bool 正しければtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Is_Folder_Path_Is_Succeed(std::string & in_check_path_name)
{
	// パス名が空文字なら間違い
	if (in_check_path_name.size() <= 0)
	{
		return false;
	}


	// フォルダパスの一番最初が改行文字なら無を開こうとしているのでエラー
	if (M_Is_CR(in_check_path_name[0]) == true)
	{
		return false;
	}

	// フォルダ名は正当である
	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ファイルが指定されているかどうかを判定
// 引数   ：std::string & パス名
// 戻り値 ：bool ファイルまでのパスならtrue フォルダなどまでならfalse
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Is_File(std::string & in_check_path)
{
	// ☆ ディレクトリを指定されていたらfalse ☆ //
	if (std::filesystem::is_directory(in_check_path) == true)
	{
		return false;
	}


	// ファイルまでのパスである
	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された文字が改行文字であるかどうかを判定する
// 引数   ：const char & 文字データ
// 戻り値 ：bool trueなら改行コード
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Is_CR(const char & in_check_charact)
{
	// ☆ 改行コードかどうかを判定 ☆ //
	switch (in_check_charact)
	{
	// ウィンドウズ系の改行コード
	case '/':
		return true;

	// UnixとLinux系またはMACOS系の改行コードの時の検証
	case '\n':
		return true;

	// MACOS系の改行コードの時の検証
	case '\r':
		return true;

	// コンソールでの指定方式
	case '\\':
		return true;
	}


	// 改行コードではなかった
	return false;
}


//==☆ パブリック ☆==//

//-☆- コンストラクタとデストラクタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Text_And_File_Manager::C_Text_And_File_Manager(void)
{
	M_Reset_Data();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：データ初期化
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Reset_Data(void)
{
	mpr_variable.sentence_data.clear();
	mpr_variable.sentence_data.shrink_to_fit();

	// 一行目は作成しておく
	mpr_variable.sentence_data.resize(1);

	mpr_variable.file_path.clear();
	mpr_variable.file_path.shrink_to_fit();
	mpr_variable.file_path = mpr_variable.con_default_name;
	mpr_variable.column_number = 0;
	mpr_variable.row_number = 0;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Text_And_File_Manager::~C_Text_And_File_Manager(void)
{
	M_Reset_Data();

	return;
}


//-☆- データ変換 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：文字列を10進数のINT型に変換する
// 引数   ：const char * 変換するデータ
// 戻り値 ：int 変換結果
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
int C_Text_And_File_Manager::M_Convert_Data_Char_To_X16INT(std::string in_data)
{
	// ☆ 変数宣言 ☆ //
	int result_10x_number = 0;	// 変換結果
	int text_size = (int)in_data.size();	// 文字数
	int multiple_level = 1;	// 10進数変換ための倍率


	// 変換を行う
	for (int loop_x = text_size - 1; loop_x > -1; loop_x--)
	{
		// ☆ 変数宣言 ☆ //
		int down_data = in_data[loop_x] & 0x0f;	// 下位4ビットのデータ
		int top_data = in_data[loop_x] & 0xf0;	// 上位4ビットのデータ（理論上上位4ビットは下位4ビットより一回多く16を掛けなければならないが取り出した時にもうすでに16ビット倍になっている　(理由：10進数で5ビット目は16だから　16進数で考えると上位と下位で別れていると錯覚してしまう)）


		// 10進数に変換した結果を加算
		result_10x_number += (top_data + down_data) * multiple_level;


		// 10次の桁のために増やす
		multiple_level *= 256;
	}


	// 結果を返す
	return result_10x_number;
}


//-☆- 生成 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：パスまでのフォルダを生成する
// 引数   ：std::string ファイルまでのパス
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Create_Path_Of_Folder(std::string in_path_string)
{
	// フォルダのパスが正しくない時はスルー
	if (M_Is_Folder_Path_Is_Succeed(in_path_string) == false)
	{
		return false;
	}


	// ファイルが見つかればおわる
	if (M_Is_File_Exist(in_path_string) == true)
	{
		return true;
	}


	// ☆ 変数宣言 ☆ //
	struct stat s_stat_fold;	// フォルダ探索用

	int n_text_size = (int)strlen(in_path_string.data());	// パスの文字数

	bool b_succes = true;	// フォルダがあるかどうかのフラグ


	// 一番下のフォルダを探索して、無ければフラグを下げる
	for (int n_num = n_text_size - 1; n_num >= 0; n_num--)
	{
		// フォルダ名から一番深いフォルダがあればそれを探索する 
		if (M_Is_CR(in_path_string[n_num]) == true)
		{
			// ☆ 変数宣言 ☆ //
			char* p_search_folder_name = new char[(long long)n_num + 1];	// 探索時のフォルダ名

			// フォルダ名を設定
			for (int n_len = 0; n_len < n_num; n_len++)
			{
				p_search_folder_name[n_len] = in_path_string[n_len];
			}

			// 終端文字を追加
			p_search_folder_name[n_num] = '\0';

			// 一番深いフォルダがなければ成功のフラグを下げる
			if (stat(p_search_folder_name, &s_stat_fold) != 0)
			{
				b_succes = false;
			}

			// メモリ解放
			delete[] p_search_folder_name;
			p_search_folder_name = nullptr;

			// 一番深いフォルダを発見したので処理を抜ける
			n_num -= n_text_size;
		}
	}

	// 一番深いフォルダが見つかったら処理を終了する
	if (b_succes == true)
	{
		return true;
	}


	// ☆ ファイル探索 ☆ //

	// フォルダ探索
	for (int n_num = 0; n_num < n_text_size; n_num++)
	{
		// フォルダ名が指定されていればフォルダを探索してなければ生成
		if (M_Is_CR(in_path_string[n_num]) == true)
		{
			// ☆ 変数宣言 ☆ //
			char* p_search_folder_name = new char[(long long)n_num + 1];	// 探索時のフォルダ名


			// フォルダ名を設定
			for (int n_len = 0; n_len < n_num; n_len++)
			{
				p_search_folder_name[n_len] = in_path_string[n_len];
			}

			// 終端文字を追加
			p_search_folder_name[n_num] = '\0';

			// フォルダがなければ生成する
			if (stat(p_search_folder_name, &s_stat_fold) != 0)
			{
				// ☆ 変数宣言 ☆ //
				wchar_t* p_set_fol_name = new wchar_t[(long long)n_num + 1];	// 生成するフォルダ名

				int create_result = 0;	// 生成結果


				// フォルダ名を設定
				for (int n_len = 0; n_len < n_num; n_len++)
				{
					p_set_fol_name[n_len] = p_search_folder_name[n_len];
				}

				// 終端文字を追加
				p_set_fol_name[n_num] = '\0';

				
				// フォルダを生成する
				create_result = _wmkdir(p_set_fol_name);

				
				// メモリ解放
				delete[] p_set_fol_name;
				p_set_fol_name = nullptr;


				// 生成に失敗したらエラーを出す
				if (create_result == -1)
				{
					delete[] p_search_folder_name;
					p_search_folder_name = nullptr;

					return false;
				}
			}

			// メモリ解放
			delete[] p_search_folder_name;
			p_search_folder_name = nullptr;
		}
	}

	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：パスまでのファイルとフォルダがなければ生成する
// 引数   ：string ファイルまでのパス
// 戻り値 ：成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Create_File_And_Folder_If_File_Not_Exist(std::string in_path_string)
{
	// フォルダのパスが正しくない時はスルー
	if (M_Is_Folder_Path_Is_Succeed(in_path_string) == false)
	{
		return false;
	}


	// ファイルが見つかればおわる
	if (M_Is_File_Exist(in_path_string) == true)
	{
		return true;
	}


	// ☆ フォルダを生成する ☆ //
	M_Create_Path_Of_Folder(in_path_string);


	// フォルダのみの指定であればそこで中断
	if (M_Is_File(in_path_string) == false)
	{
		return true;
	}


	// ☆ 変数宣言 ☆ //
	std::fstream creat_file(in_path_string, std::ios_base::out | std::ios_base::trunc);	// ファイル編集用システム


	// ファイルを生成する
	creat_file << "";


	// ファイルを閉じる
	creat_file.close();


	// ファイルまでの生成に成功
	return true;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：これから編集するファイルのパスを指定する（なければ生成される）
// 引数   ：string ファイルのパス
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Set_File_Path(std::string in_file_path)
{
	// ☆ ファイルが正しく指定されていないなら抜ける ☆ //
	if (M_Is_File_Path_Succeed(in_file_path) == false)
	{
		return false;
	}


	// ☆ ファイルが見つからなければ作る ☆ //		// 生成失敗でエラーを出す
	if (M_Create_File_And_Folder_If_File_Not_Exist(in_file_path) == false)
	{
		return false;
	}


	// ☆ 指定された情報を設定 ☆ //
	mpr_variable.file_path = in_file_path;

	// 指定に成功
	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：編集モードを指定する
// 引数   ：E_EDIT_MODE 編集モードを指定する番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Set_Edit_Mode(E_EDIT_MODE in_set_mode)
{
	mpr_variable.mode_setting = in_set_mode;

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在のデータの参照を渡す
// 引数   ：void
// 戻り値 ：const vector<string> & データの参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const std::vector<std::string> & C_Text_And_File_Manager::M_Get_File_Data_Refer(void)
{
	return mpr_variable.sentence_data;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在のデータの参照を渡す
// 引数   ：void
// 戻り値 ：string & ファイルパスの参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const std::string & C_Text_And_File_Manager::M_Get_File_Path_Refer(void)
{
	return mpr_variable.file_path;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在の行の番号を返す
// 引数   ：void
// 戻り値 ：int 現在の行の番号
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
int C_Text_And_File_Manager::M_Get_Now_Row(void)
{
	return mpr_variable.row_number;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在の列の番号を返す
// 引数   ：void
// 戻り値 ：int 現在の列の番号
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
int C_Text_And_File_Manager::M_Get_Now_Column(void)
{
	return mpr_variable.column_number;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：文章の行数を返す
// 引数   ：void
// 戻り値 ：int 文章の行数
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
int C_Text_And_File_Manager::M_Get_Text_Row_Sum(void)
{
	return (int)mpr_variable.sentence_data.size();
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：今選択中の行の文字数を返す
// 引数   ：void
// 戻り値 ：int 文字数
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
int C_Text_And_File_Manager::M_Get_Column_Sum_In_Now_Row(void)
{
	return (int)mpr_variable.sentence_data[mpr_variable.row_number].size();
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在の文章全体の文字数を返す
// 引数   ：void
// 戻り値 ：int 文字数
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
int C_Text_And_File_Manager::M_Get_Sentence_Text_Size(void)
{
	// ☆ 変数宣言 ☆ //
	int result_text_size = 0;	// 文字数の合計
	int row_size = (int)mpr_variable.sentence_data.size(); // 行数


	return 0;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在の場所の文字を返す
// 引数   ：void
// 戻り値 ：char 現在の場所の文字
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
char C_Text_And_File_Manager::M_Get_Text_Of_Now_Position(void)
{
	return mpr_variable.sentence_data[mpr_variable.row_number][mpr_variable.column_number];
}


//-☆- セーブ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：操作中のファイルに現在のデータを上書きでセーブする
// 引数   ：void
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Save_Data_To_Now_File(void)
{
	// ☆ 変数宣言 ☆ //
	std::fstream creat_file;	// ファイル編集用システム

	int row_sum = (int)mpr_variable.sentence_data.size();	// 行数


	// ☆ 編集モードによって処理を分岐 ☆ //
	switch (mpr_variable.mode_setting)
	{
		// バイナリ形式
	case E_EDIT_MODE::e_BINARY:
		creat_file.open(mpr_variable.file_path, std::ios::out, std::ios::binary);
		break;

		// テキスト形式
	case E_EDIT_MODE::e_TEXT:
		creat_file.open(mpr_variable.file_path, std::ios::out);
		break;
	}


	// 読み取れていなかったらエラーを出して抜ける
	if (!creat_file)
	{
		creat_file.close();
		return false;
	}


	// ファイルを生成するし内容を書き込む
	for (int loop_x = 0; loop_x < row_sum; loop_x++)
	{
		creat_file << mpr_variable.sentence_data[loop_x].data();


		// まだ下に行があるなら改行
		if (loop_x + 1 < row_sum)
		{
			creat_file << "\n";
		}
	}

	// ファイルを閉じる
	creat_file.close();

	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたファイルに現在のデータを上書きでセーブする
// 引数   ：string ファイルのパス
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Save_Data_To_Select_File(std::string in_file_path)
{
	// ☆ ファイルが正しく指定されていないなら抜ける ☆ //
	if (M_Is_File_Path_Succeed(in_file_path) == false)
	{
		return false;
	}


	// ☆ 変数宣言 ☆ //
	std::fstream creat_file;	// ファイル編集用システム

	int row_sum = (int)mpr_variable.sentence_data.size();	// 行数


	// ☆ 編集モードによって処理を分岐 ☆ //
	switch (mpr_variable.mode_setting)
	{
		// バイナリ形式
	case E_EDIT_MODE::e_BINARY:
		creat_file.open(in_file_path, std::ios::out, std::ios::binary);
		break;

		// テキスト形式
	case E_EDIT_MODE::e_TEXT:
		creat_file.open(in_file_path, std::ios::out);
		break;
	}


	// 読み取れていなかったらエラーを出して抜ける
	if (!creat_file)
	{
		creat_file.close();
		return false;
	}


	// ファイルを生成するし内容を書き込む
	for (int loop_x = 0; loop_x < row_sum; loop_x++)
	{
		creat_file << mpr_variable.sentence_data[loop_x].data();


		// まだ下に行があるなら改行
		if (loop_x + 1 < row_sum)
		{
			creat_file << "\n";
		}
	}

	// ファイルを閉じる
	creat_file.close();

	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：操作中のファイルに現在のデータを追加でセーブする
// 引数   ：void
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Add_Data_To_Now_File(void)
{
	// ☆ 変数宣言 ☆ //
	std::fstream add_file;	// ファイル編集用システム

	int row_sum = (int)mpr_variable.sentence_data.size();	// 行数


	// ☆ 編集モードによって処理を分岐 ☆ //
	switch (mpr_variable.mode_setting)
	{
		// バイナリ形式
	case E_EDIT_MODE::e_BINARY:
		add_file.open(mpr_variable.file_path, std::ios::app, std::ios::binary);
		break;

		// テキスト形式
	case E_EDIT_MODE::e_TEXT:
		add_file.open(mpr_variable.file_path, std::ios::app);
		break;
	}


	// 読み取れていなかったらエラーを出して抜ける
	if (!add_file)
	{
		add_file.close();
		return false;
	}


	// ファイルを生成するし内容を書き込む
	for (int loop_x = 0; loop_x < row_sum; loop_x++)
	{
		add_file << mpr_variable.sentence_data[loop_x].data();


		// まだ下に行があるなら改行
		if (loop_x + 1 < row_sum)
		{
			add_file << "\n";
		}
	}

	// ファイルを閉じる
	add_file.close();

	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたファイルに現在のデータを追加でセーブする
// 引数   ：string ファイルのパス
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Add_Data_To_Select_File(std::string in_file_path)
{
	// ☆ ファイルが正しく指定されていないなら抜ける ☆ //
	if (M_Is_File_Path_Succeed(in_file_path) == false)
	{
		return false;
	}


	// ☆ 変数宣言 ☆ //
	std::fstream add_file;	// ファイル編集用システム

	int row_sum = (int)mpr_variable.sentence_data.size();	// 行数


	// ☆ 編集モードによって処理を分岐 ☆ //
	switch (mpr_variable.mode_setting)
	{
		// バイナリ形式
	case E_EDIT_MODE::e_BINARY:
		add_file.open(in_file_path, std::ios::app, std::ios::binary);
		break;

		// テキスト形式
	case E_EDIT_MODE::e_TEXT:
		add_file.open(in_file_path, std::ios::app);
		break;
	}


	// 読み取れていなかったらエラーを出して抜ける
	if (!add_file)
	{
		add_file.close();
		return false;
	}


	// ファイルを生成するし内容を書き込む
	for (int loop_x = 0; loop_x < row_sum; loop_x++)
	{
		add_file << mpr_variable.sentence_data[loop_x].data();


		// まだ下に行があるなら改行
		if (loop_x + 1 < row_sum)
		{
			add_file << "\n";
		}
	}

	// ファイルを閉じる
	add_file.close();

	return true;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：操作中のファイルからデータを読み込む
// 引数   ：void
// 戻り値 ：bool 成功時のみture
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Load_Now_File(void)
{
	// ☆ ファイルが正しく指定されていないなら抜ける ☆ //
	if (M_Is_File_Path_Succeed(mpr_variable.file_path) == false)
	{
		return false;
	}


	// ☆ 変数宣言 ☆ //
	std::ifstream load_file;	// ファイルの読み取り用システム

	std::string data_one_line;	// 一行分のデータ


	// ☆ 編集モードによって処理を分岐 ☆ //
	switch (mpr_variable.mode_setting)
	{
		// バイナリ形式
	case E_EDIT_MODE::e_BINARY:
		load_file.open(mpr_variable.file_path, std::ios::in, std::ios::binary);
		break;

		// テキスト形式
	case E_EDIT_MODE::e_TEXT:
		load_file.open(mpr_variable.file_path, std::ios::in);
		break;
	}


	// 読み取れていなかったらエラーを出して抜ける
	if (!load_file)
	{
		load_file.close();
		return false;
	}


	// 行がなければ一行追加
	if (mpr_variable.sentence_data.size() <= 0)
	{
		mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
	}


	// EOF(ファイルの終わり)がくるまで取り出し続ける
	while (std::getline(load_file, data_one_line) && !data_one_line.empty())
	{
		// 空白ならスルー
		if (data_one_line.size() <= 0)
		{

		}

		// 改行コードがあるなら改行コードを抜いてデータを入れる
		else if (M_Is_CR(data_one_line[data_one_line.size() - 1]) == true)
		{
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line.substr(0, data_one_line.size() - 1);
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
		}

		// 改行コードがないなら通常通りデータを入れる
		else
		{
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line;
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
		}

		// 一行追加
		mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
	}


	// ファイルをとじる
	load_file.close();

	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：操作中のファイルから指定された行間だけデータを読み込む
// 引数   ：int 読み始まりの行, int 読み終わりの行
// 戻り値 ：bool 成功時のみture
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Load_Now_File_Only_Select_Raw(int in_start_row, int in_end_row)
{
	// ☆ ファイルが正しく指定されていないなら抜ける ☆ //
	if (M_Is_File_Path_Succeed(mpr_variable.file_path) == false)
	{
		return false;
	}


	// ☆ 変数宣言 ☆ //
	std::ifstream load_file;	// ファイルの読み取り用システム

	std::string data_one_line;	// 一行分のデータ


	// ☆ 編集モードによって処理を分岐 ☆ //
	switch (mpr_variable.mode_setting)
	{
		// バイナリ形式
	case E_EDIT_MODE::e_BINARY:
		load_file.open(mpr_variable.file_path, std::ios::in, std::ios::binary);
		break;

		// テキスト形式
	case E_EDIT_MODE::e_TEXT:
		load_file.open(mpr_variable.file_path, std::ios::in);
		break;
	}


	// 読み取れていなかったらエラーを出して抜ける
	if (!load_file)
	{
		load_file.close();
		return false;
	}


	// 行がなければ一行追加
	if (mpr_variable.sentence_data.size() <= 0)
	{
		mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
	}


	// EOF(ファイルの終わり)がくるまで取り出し続ける
	for (int loop_x = 0; std::getline(load_file, data_one_line) && !data_one_line.empty(); loop_x++)
	{
		// 始まりの行と終わりの行の間の行のみ読み取る
		if (in_start_row <= loop_x)
		{
			// 空白ならスルー
			if (data_one_line.size() <= 0)
			{

			}

			// 改行コードがあるなら改行コードを抜いてデータを入れる
			else if (M_Is_CR(data_one_line[data_one_line.size() - 1]) == true)
			{
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line.substr(0, data_one_line.size() - 1);
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
			}

			// 改行コードがないなら通常通りデータを入れる
			else
			{
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line;
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
			}

			// 一行追加
			mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
		}

		// 終わりの行をこえたらこれ以上読み取らなくてよいのでファイルを閉じて終了
		else if (in_end_row <= loop_x)
		{
			load_file.close();
			return true;
		}
	}


	// ファイルをとじる
	load_file.close();

	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたファイルからデータを読み込む
// 引数   ：std::string ファイルのパス
// 戻り値 ：bool 成功時のみture
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Load_Select_File(std::string in_file_path)
{
	// ☆ ファイルが正しく指定されていないなら抜ける ☆ //
	if (M_Is_File_Path_Succeed(in_file_path) == false)
	{
		return false;
	}


	// ☆ ファイルもフォルダもないならfalse ☆ //
	if (M_Is_File_Exist(in_file_path) == false)
	{
		return false;
	}



	// ☆ ファイルが正しく指定されていないなら抜ける ☆ //
	if (M_Is_File(in_file_path) == false)
	{
		return false;
	}


	// ☆ 変数宣言 ☆ //
	std::ifstream load_file;	// ファイルの読み取り用システム

	std::string data_one_line;	// 一行分のデータ


	// ☆ 編集モードによって処理を分岐 ☆ //
	switch (mpr_variable.mode_setting)
	{
		// バイナリ形式
	case E_EDIT_MODE::e_BINARY:
		load_file.open(in_file_path, std::ios::in, std::ios::binary);
		break;

		// テキスト形式
	case E_EDIT_MODE::e_TEXT:
		load_file.open(in_file_path, std::ios::in);
		break;
	}


	// 読み取れていなかったらエラーを出して抜ける
	if (!load_file)
	{
		load_file.close();
		return false;
	}


	// 行がなければ一行追加
	if (mpr_variable.sentence_data.size() <= 0)
	{
		mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
	}


	// EOF(ファイルの終わり)がくるまで取り出し続ける
	while (std::getline(load_file, data_one_line))
	{
		// 空白ならスルー
		if (data_one_line.size() <= 0)
		{

		}

		// 改行コードがあるなら改行コードを抜いてデータを入れる
		else if (M_Is_CR(data_one_line[data_one_line.size() - 1]) == true)
		{
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line.substr(0, data_one_line.size() - 1);
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
		}

		// 改行コードがないなら通常通りデータを入れる
		else
		{
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line;
			mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
		}


		// 一行追加
		mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
	}


	// ファイルをとじる
	load_file.close();

	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたファイルから指定された行間だけデータを読み込む
// 引数   ：std::string, int 読み始まりの行, int 読み終わりの行
// 戻り値 ：bool 成功時のみture
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Load_Select_File_Only_Select_Raw(std::string in_file_path, int in_start_row, int in_end_row)
{
	// ☆ ファイルが正しく指定されていないなら抜ける ☆ //
	if (M_Is_File_Path_Succeed(in_file_path) == false)
	{
		return false;
	}


	// ☆ ファイルもフォルダもないならfalse ☆ //
	if (M_Is_File_Exist(in_file_path) == false)
	{
		return false;
	}


	// ☆ ファイルが正しく指定されていないなら抜ける ☆ //
	if (M_Is_File(in_file_path) == false)
	{
		return false;
	}


	// ☆ 変数宣言 ☆ //
	std::ifstream load_file;	// ファイルの読み取り用システム

	std::string data_one_line;	// 一行分のデータ


	// ☆ 編集モードによって処理を分岐 ☆ //
	switch (mpr_variable.mode_setting)
	{
		// バイナリ形式
	case E_EDIT_MODE::e_BINARY:
		load_file.open(in_file_path, std::ios::in, std::ios::binary);
		break;

		// テキスト形式
	case E_EDIT_MODE::e_TEXT:
		load_file.open(in_file_path, std::ios::in);
		break;
	}


	// 読み取れていなかったらエラーを出して抜ける
	if (!load_file)
	{
		load_file.close();
		return false;
	}


	// 行がなければ一行追加
	if (mpr_variable.sentence_data.size() <= 0)
	{
		mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
	}


	// EOF(ファイルの終わり)がくるまで取り出し続ける
	for (int loop_x = 0; std::getline(load_file, data_one_line) && !data_one_line.empty(); loop_x++)
	{
		// 範囲内の時のみ読み取る
		if (in_start_row <= loop_x)
		{
			// 空白ならスルー
			if (data_one_line.size() <= 0)
			{

			}

			// 改行コードがあるなら改行コードを抜いてデータを入れる
			else if (M_Is_CR(data_one_line[data_one_line.size() - 1]) == true)
			{
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line.substr(0, data_one_line.size() - 1);
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
			}

			// 改行コードがないなら通常通りデータを入れる
			else
			{
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1] += data_one_line;
				mpr_variable.sentence_data[mpr_variable.sentence_data.size() - 1].shrink_to_fit();
			}


			// 一行追加
			mpr_variable.sentence_data.resize(mpr_variable.sentence_data.size() + 1);
		}

		// 終わりの行をこえたらこれ以上読み取らなくてよいのでファイルを閉じて終了
		if (in_end_row <= loop_x)
		{
			load_file.close();
			return true;
		}
	}


	// ファイルをとじる
	load_file.close();

	return true;
}


//-☆- 入力 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたデータを現在の操作位置から入力する
// 引数   ：short 入力するデータ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Input_This_Data(short in_data)
{
	mpr_variable.sentence_data[mpr_variable.row_number].insert(mpr_variable.column_number, std::to_string(in_data));
	mpr_variable.column_number += (int)std::to_string(in_data).size();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたデータを現在の操作位置から入力する
// 引数   ：unsigned short 入力するデータ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Input_This_Data(unsigned short in_data)
{
	mpr_variable.sentence_data[mpr_variable.row_number].insert(mpr_variable.column_number, std::to_string(in_data));
	mpr_variable.column_number += (int)std::to_string(in_data).size();

	return;
}

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたデータを現在の操作位置から入力する
// 引数   ：int 入力するデータ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Input_This_Data(int in_data)
{
	mpr_variable.sentence_data[mpr_variable.row_number].insert(mpr_variable.column_number, std::to_string(in_data));
	mpr_variable.column_number += (int)std::to_string(in_data).size();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたデータを現在の操作位置から入力する
// 引数   ：unsigned int 入力するデータ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Input_This_Data(unsigned int in_data)
{
	mpr_variable.sentence_data[mpr_variable.row_number].insert(mpr_variable.column_number, std::to_string(in_data));
	mpr_variable.column_number += (int)std::to_string(in_data).size();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたデータを現在の操作位置から入力する
// 引数   ：long long 入力するデータ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Input_This_Data(long long in_data)
{
	mpr_variable.sentence_data[mpr_variable.row_number].insert(mpr_variable.column_number, std::to_string(in_data));
	mpr_variable.column_number += (int)std::to_string(in_data).size();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたデータを現在の操作位置から入力する
// 引数   ：unsigned long long 入力するデータ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Input_This_Data(unsigned long long in_data)
{
	mpr_variable.sentence_data[mpr_variable.row_number].insert(mpr_variable.column_number, std::to_string(in_data));
	mpr_variable.column_number += (int)std::to_string(in_data).size();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたデータを現在の操作位置から入力する
// 引数   ：std::string 入力するデータ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Input_This_Data(std::string in_data)
{
	// ☆ 変数宣言 ☆ //
	std::string stack_data;	// 結果を控えるためのデータ

	int text_size = (int)in_data.size();	// 文字数


	// 文字数分行う
	for (int check_x = 0; check_x < text_size; check_x++)
	{
		// 改行コードがあったら改行する
		if (M_Is_CR(in_data[check_x]) == true)
		{
			// 右に要素があるなら改行先にその要素を移動させ、今までためたデータを現在の行に格納する
			if (mpr_variable.sentence_data[mpr_variable.row_number].size() >= mpr_variable.column_number)
			{
				mpr_variable.sentence_data.insert(mpr_variable.sentence_data.begin() + mpr_variable.row_number + 1, mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number));
				mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, mpr_variable.column_number) + stack_data;
				mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();
			}

			// ないなら改行のみを行う、今までためたデータを現在の行に格納する
			else
			{
				mpr_variable.sentence_data.insert(mpr_variable.sentence_data.begin() + mpr_variable.row_number + 1, "");
				mpr_variable.sentence_data[mpr_variable.row_number] += stack_data;
				mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();
			}


			// １つ下の行を選択する
			mpr_variable.row_number += 1;

			// 一番左を選択中にする
			mpr_variable.column_number = 0;

			// スタック中のデータをクリア
			stack_data.clear();
			stack_data.shrink_to_fit();
		}

		// 文字をつなげる
		else
		{
			stack_data += in_data[check_x];
		}
	}


	// 最後まで残ったデータを格納
	mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, mpr_variable.column_number) + stack_data + mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number);
	mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();

	// 選択位置を移動
	mpr_variable.column_number += text_size;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたデータを現在の操作位置から入力する
// 引数   ：double 入力するデータ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Input_This_Data(double in_data)
{
	mpr_variable.sentence_data[mpr_variable.row_number].insert(mpr_variable.column_number, std::to_string(in_data));
	mpr_variable.column_number += (int)std::to_string(in_data).size();

	return;
}


//-☆- 削除 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたデータを文章内から指定された回数分だけ削除する
// 引数   ：int 削除回数（０で全て削除）, std::string 削除する文字
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Delete_Data_Equal_This_Text_In_Sentence(int in_delete_num, std::string in_delete_text)
{
	// ☆ 変数宣言 ☆ //
	int line_sum = (int)mpr_variable.sentence_data.size();	// 行数
	int text_size = (int)in_delete_text.size();	// 探索する文字の文字数


	// 全ての行分繰り返す
	for (int loop_row = 0; loop_row < line_sum; loop_row++)
	{
		// ☆ 変数宣言 ☆ //
		int column_sum = (int)mpr_variable.sentence_data[loop_row].size() - text_size;	// 探索可能な最大列数


		// 一文字目が一致するかを繰り返して探索
		for (int loop_column = 0; loop_column <= column_sum; loop_column++)
		{
			// 同じ文字があったら探索し続ける
			for (int check_x = 0; in_delete_text[check_x] == mpr_variable.sentence_data[loop_row][loop_column + check_x] && check_x < text_size; check_x++)
			{
				// 見つかったら削除する
				if (check_x + 1 >= text_size)
				{
					// 削除位置より右に文字がないなら削除位置までを格納
					if (mpr_variable.sentence_data[loop_row].size() <= loop_column + text_size)
					{
						mpr_variable.sentence_data[loop_row] = mpr_variable.sentence_data[loop_row].substr(0, loop_column);
					}

					// 削除位置より右に文字があるなら削除位置のみ省く
					else
					{
						mpr_variable.sentence_data[loop_row] = mpr_variable.sentence_data[loop_row].substr(0, loop_column) + mpr_variable.sentence_data[loop_row].substr(loop_column + text_size);
					}


					mpr_variable.sentence_data[loop_row].shrink_to_fit();


					// 今の選択位置より前の位置が消されたら戻る
					if (mpr_variable.row_number >= loop_row)
					{
						if (mpr_variable.column_number >= loop_column)
						{
							mpr_variable.column_number -= text_size;
						}


						// 選択中の場所が今の行内を超えたら上の行に戻る
						if (mpr_variable.column_number < 0)
						{
							mpr_variable.column_number = (int)mpr_variable.sentence_data[mpr_variable.row_number - 1].size();
						}
					}


					// 残りの削除回数を減らす、もうなければ終了する
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


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたデータを選択中の行内から指定された回数分だけ削除する
// 引数   ：int 削除回数（０で全て削除）, std::string 削除する文字
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Delete_Data_Eqaul_This_Text_In_Now_Row(int in_delete_num, std::string in_delete_text)
{
	// ☆ 変数宣言 ☆ //
	int text_size = (int)in_delete_text.size();	// 探索する文字の文字数
	int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// 探索可能な最大列数


	// 一文字目が一致するかを繰り返して探索
	for (int loop_column = 0; loop_column <= column_sum; loop_column++)
	{
		// 同じ文字があったら探索し続ける
		for (int check_x = 0; in_delete_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
		{
			// 見つかったら削除する
			if (check_x + 1 >= text_size)
			{
				// 削除位置より右に文字がないなら削除位置までを格納
				if (mpr_variable.sentence_data[mpr_variable.row_number].size() <= loop_column + text_size)
				{
					mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, loop_column);
				}

				// 削除位置より右に文字があつなら削除位置のみ省く
				else
				{
					mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, loop_column) + mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column + text_size);
				}


				mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();


				// 削除範囲以降に選択中の場所があったら削除範囲分左に移動する
				if (loop_column <= mpr_variable.column_number)
				{
					mpr_variable.column_number = loop_column - 1;


					// 0以下にはならないようにする
					if (mpr_variable.column_number < 0)
					{
						mpr_variable.column_number = 0;
					}
				}


				// 残りの削除回数を減らす、もうなければ終了する
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


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたデータを選択中位置の右側の行内から指定された回数分だけ削除する
// 引数   ：int 削除回数（０で全て削除）, std::string 削除する文字
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Delete_Data_Eqaul_This_Text_In_Now_Row_For_Right(int in_delete_num, std::string in_delete_text)
{
	// ☆ 変数宣言 ☆ //
	int text_size = (int)in_delete_text.size();	// 探索する文字の文字数
	int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// 探索可能な最大列数


	// 一文字目が一致するかを繰り返して探索
	for (int loop_column = mpr_variable.column_number; loop_column <= column_sum; loop_column++)
	{
		// 同じ文字があったら探索し続ける
		for (int check_x = 0; in_delete_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
		{
			// 見つかったら削除する
			if (check_x + 1 >= text_size)
			{
				// 削除位置より右に文字がないなら削除位置までを格納
				if (mpr_variable.sentence_data[mpr_variable.row_number].size() <= loop_column + text_size)
				{
					mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, loop_column);
				}

				// 削除位置より右に文字があつなら削除位置のみ省く
				else
				{
					mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, loop_column) + mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column + text_size);
				}


				mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();


				// 削除範囲内に選択中の場所があったら削除範囲の左に移動する
				if (loop_column <= mpr_variable.column_number && mpr_variable.column_number <= loop_column + text_size)
				{
					mpr_variable.column_number = loop_column - 1;


					// 0以下にはならないようにする
					if (mpr_variable.column_number < 0)
					{
						mpr_variable.column_number = 0;
					}
				}


				// 残りの削除回数を減らす、もうなければ終了する
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


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたデータを選択中位置の左側の行内から指定された回数分だけ削除する
// 引数   ：int 削除回数（０で全て削除）, std::string 削除する文字
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Delete_Data_Eqaul_This_Text_In_Now_Row_For_Left(int in_delete_num, std::string in_delete_text)
{
	// ☆ 変数宣言 ☆ //
	int text_size = (int)in_delete_text.size();	// 探索する文字の文字数


	// 一文字目が一致するかを繰り返して探索
	for (int loop_column = mpr_variable.column_number; loop_column > -1; loop_column--)
	{
		// 同じ文字があったら探索し続ける
		for (int check_x = 0; in_delete_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
		{
			// 見つかったら削除する
			if (check_x + 1 >= text_size)
			{
				// 削除位置より右に文字がないなら削除位置までを格納
				if (mpr_variable.sentence_data[mpr_variable.row_number].size() <= loop_column + text_size)
				{
					mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, loop_column);
				}

				// 削除位置より右に文字があつなら削除位置のみ省く
				else
				{
					mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, loop_column) + mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column + text_size);
				}


				mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();


				// 削除範囲内に選択中の場所があったら削除範囲の左に移動する
				if (loop_column <= mpr_variable.column_number && mpr_variable.column_number <= loop_column + text_size)
				{
					mpr_variable.column_number = loop_column - 1;


					// 0以下にはならないようにする
					if (mpr_variable.column_number < 0)
					{
						mpr_variable.column_number = 0;
					}
				}


				// 残りの削除回数を減らす
				in_delete_num -= 1;


				// 残りの削除回数がもうなければ処理を終了する
				if (in_delete_num == 0)
				{
					return;
				}
			}
		}
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された行を削除する
// 引数   ：int 削除する行
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Delete_Row(int in_delete_row)
{
	// 最後の行の時は内容のみ削除し、１行はかならず残るようにする（バグを防ぐために）
	if (mpr_variable.sentence_data.size() == 1)
	{
		mpr_variable.sentence_data[0].clear();
		mpr_variable.sentence_data[0].shrink_to_fit();

		return;
	}


	// 削除位置が今の位置より前なら一行上にずらす
	if (in_delete_row <= mpr_variable.row_number)
	{
		mpr_variable.row_number -= 1;


		// 0以下にならないようにする
		if (mpr_variable.row_number < 0)
		{
			mpr_variable.row_number = 0;
			mpr_variable.column_number = 0;
		}

		// 今の行が削除されていたら一行上の文章の一番右に移動する
		else if (in_delete_row == mpr_variable.row_number + 1)
		{
			mpr_variable.column_number = (int)mpr_variable.sentence_data[mpr_variable.row_number].size();
		}
	}

	// 範囲外を指定したときは削除せずに終わる
	else if (in_delete_row < 0 || (int)mpr_variable.sentence_data.size() <= in_delete_row)
	{
		return;
	}


	// 削除を行う
	mpr_variable.sentence_data.erase(mpr_variable.sentence_data.begin() + in_delete_row);
	mpr_variable.sentence_data.shrink_to_fit();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：今の場所から指定された文字数分だけ文字を削除する（行はこえない）
// 引数   ：int 削除する文字数
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Delete_Column(int in_delete_num)
{
	// ☆ 削除しないならスルー ☆ //
	if (in_delete_num > 0)
	{
		return;
	}


	// ☆ 右方向に削除するとき ☆ //
	if (in_delete_num > 0)
	{
		// ☆ 削除する文字数が行内に収まらないなら行末までを削除 ☆ //
		if (mpr_variable.sentence_data[mpr_variable.row_number].size() <= mpr_variable.column_number + in_delete_num)
		{
			mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, mpr_variable.column_number);
			mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();

			return;
		}


		// 行内に収まるなら行の間だけを削除する
		mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, mpr_variable.column_number) + mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number + in_delete_num);
		mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();

		return;
	}


	// ☆ 左方向に削除するとき ☆ //

	// ☆ 削除する文字数が行内に収まらないなら行のはじまりまでを削除 ☆ //
	if (mpr_variable.column_number - in_delete_num < 0)
	{
		mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number);
		mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();

		return;
	}


	// 行内で収まるなら行の間だけを削除する
	mpr_variable.sentence_data[mpr_variable.row_number] = mpr_variable.sentence_data[mpr_variable.row_number].substr(0, mpr_variable.column_number - in_delete_num) + mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number + 1);
	mpr_variable.sentence_data[mpr_variable.row_number].shrink_to_fit();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ファイルを削除する
// 引数   ：void
// 戻り値 ：bool 削除するファイルが見つからなかった、もしくは指定されたパスがディレクトリをさすならfalse
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Delete_Now_File(void)
{
	// ☆ ファイルが見つからないならエラーを返す ☆ //
	if (M_Is_File(mpr_variable.file_path) == false)
	{
		return false;
	}


	// ☆ ファイルを削除する ☆ //
	std::filesystem::remove(mpr_variable.file_path);


	// 削除に成功
	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ファイルを削除する
// 引数   ：std::string ファイルまでのパス
// 戻り値 ：bool 削除するファイルが見つからなかった、もしくは指定されたパスがディレクトリをさすならfalse
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Delete_Select_File(std::string is_file_path)
{
	// ☆ ファイルが見つからないならエラーを返す ☆ //
	if (M_Is_File(is_file_path) == false)
	{
		return false;
	}


	// ☆ ファイルを削除する ☆ //
	std::filesystem::remove(is_file_path);


	// 削除に成功
	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたフォルダを削除する
// 引数   ：std::string 削除するフォルダまでのパス
// 戻り値 ：bool 削除するフォルダが見つからなかったらfalse
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Delete_Select_Folder(std::string in_folder_path)
{
	// ☆ フォルダが見つからないならエラーを返す ☆ //
	if (std::filesystem::is_directory(in_folder_path) == false)
	{
		return false;
	}


	// ☆ ファイルを削除する ☆ //
	std::filesystem::remove_all(in_folder_path);


	// 削除に成功
	return true;
}


//-☆- 変更 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在編集中のファイルのファイル名を変更する
// 引数   ：std::string 変更後のファイル名
// 戻り値 ：bool 変更に成功したらtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Rename_Now_File(std::string in_after_name)
{
	// ☆ ファイルが見つからないならエラーを返す ☆ //
	if (M_Is_File(mpr_variable.file_path) == false)
	{
		return false;
	}


	// ☆ ファイルを削除する ☆ //
	std::filesystem::rename(mpr_variable.file_path, in_after_name);


	// ファイルまでのパスを変更
	mpr_variable.file_path = in_after_name;


	// 変更に成功した
	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたファイルのファイル名を変更する
// 引数   ：std::string 変更前のファイル名, std::string 変更後のファイル名
// 戻り値 ：bool 変更に成功したらtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Rename_Select_File(std::string in_before_name, std::string in_after_name)
{
	// ☆ ファイルが見つからないならエラーを返す ☆ //
	if (M_Is_File(in_before_name) == false)
	{
		return false;
	}


	// ☆ ファイルを削除する ☆ //
	std::filesystem::rename(in_before_name, in_after_name);


	// 変更に成功した
	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたフォルダのフォルダ名を変更する
// 引数   ：std::string 変更前のフォルダ名, std::string 変更後のフォルダ名
// 戻り値 ：bool 変更に成功したらtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Rename_Select_Folder(std::string in_before_name, std::string in_after_name)
{
	// ☆ フォルダが見つからないならエラーを返す ☆ //
	if (std::filesystem::is_directory(in_before_name) == false)
	{
		return false;
	}


	// ☆ ファイルを削除する ☆ //
	std::filesystem::rename(in_before_name, in_after_name);


	// 変更に成功した
	return true;
}


//-☆- 出力 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：数字入手用処理の補助を行うインライン関数、数値入力時の共通の処理を１つの関数にまとめるために使う
// 引数   ：int & 設定先の変数, int 設定するデータ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
inline void IM_Get_Number_Setting_System(long long& in_result_number, int in_set_number)
{
	in_result_number = in_result_number * 10 + in_set_number;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：今の場所の右に数字がある場合はその数字を返す
// 引数   ：void
// 戻り値 ：long long 取り出した数値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
long long C_Text_And_File_Manager::M_Get_Number(void)
{
	// ☆ 変数宣言 ☆ //
	std::string serch_text = mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number);	// 探索する文字

	long long result_number = 0;	// 結果の数値

	int serch_sum = (int)serch_text.size();	// 探索数

	bool flg_minus = false;			// trueの時はマイナス値


	// 一文字づつ取り出していく
	for (int check_x = 0; check_x < serch_sum; check_x++)
	{
		// ☆ 文字を識別して数値に変換 ☆ //
		switch (serch_text[check_x])
		{
			//  0  //
		case '０':
		case '0':
			IM_Get_Number_Setting_System(result_number, 0);
			break;

			//  1  //
		case '１':
		case '1':
			IM_Get_Number_Setting_System(result_number, 1);
			break;

			//  2  //
		case '２':
		case '2':
			IM_Get_Number_Setting_System(result_number, 2);
			break;

			//  3  //
		case '３':
		case '3':
			IM_Get_Number_Setting_System(result_number, 3);
			break;

			//  4  //
		case '４':
		case '4':
			IM_Get_Number_Setting_System(result_number, 4);
			break;

			//  5  //
		case '５':
		case '5':
			IM_Get_Number_Setting_System(result_number, 5);
			break;

			//  6  //
		case '６':
		case '6':
			IM_Get_Number_Setting_System(result_number, 6);
			break;

			//  7  //
		case '７':
		case '7':
			IM_Get_Number_Setting_System(result_number, 7);
			break;

			//  8  //
		case '８':
		case '8':
			IM_Get_Number_Setting_System(result_number, 8);
			break;

			//  9  //
		case '９':
		case '9':
			IM_Get_Number_Setting_System(result_number, 9);
			break;

			//  -  //
		case '-':

			// 一文字目にマイナス記号がきたらマイナス指定する
			if (check_x == 0)
			{
				flg_minus = true;
			}

			// 一文字目でなければ終了する
			else
			{
				return result_number * (1 - flg_minus * 2);
			}

			break;

			//  +  //
		case '+':

			// 一文字目以降にプラス記号が来たらそこで終了する
			if (check_x > 0)
			{
				return result_number * (1 - flg_minus * 2);
			}

			break;

			//  数字じゃなかったらここで終わる  //
		default:

			return result_number * (1 - flg_minus * 2);

			break;
		}
	}

	return result_number * (1 - flg_minus * 2);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：数字入手用処理の補助を行うインライン関数、数値入力時の共通の処理を１つの関数にまとめるために使う
// 引数   ：int & 設定先の整数用変数, double & 設定先の少数用変数, int & 少数桁制御用変数, bool 設定時のモード, int 設定するデータ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
inline void IM_Get_Float_Double_Number_Setting_System(int& in_number_data, double& in_floating_data, int& in_floating_multiple_num, bool in_flg_floating_mode, int in_set_number)
{
	// 整数部操作時
	if (in_flg_floating_mode == false)
	{
		in_number_data = in_number_data * 10 + in_set_number;
	}

	// 少数部操作時
	else
	{
		in_floating_data = in_floating_data + (double)in_set_number / (double)in_floating_multiple_num;
		in_floating_multiple_num *= 10;
	}

	return;
}

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：今の場所の右に数字がある場合はその少数ありの数字を返す
// 引数   ：void
// 戻り値 ：double 取り出した数値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
double C_Text_And_File_Manager::M_Get_Float_Double_Number(void)
{
	// ☆ 変数宣言 ☆ //
	std::string string_to_float_text = mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number);	// 変換する文字

	return std::stod(string_to_float_text);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：今の場所から指定された文字分返す
// 引数   ：int 文字数
// 戻り値 ：std::string 返す文字
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
std::string C_Text_And_File_Manager::M_Get_Data_By_Number(int in_text_num)
{
	// ☆ 行を超えるならその行の最後の文字までを返す ☆ //
	if (mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number).size() <= in_text_num + mpr_variable.column_number)
	{
		return mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number);
	}


	// 行内で足りるならその分を返す
	return mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number, in_text_num);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：今の場所から指定された文字までを返す
// 引数   ：std::string 探索する文字
// 戻り値 ：std::string 返す文字　見つからなかった場合は、___Not_Founds___を返す
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
std::string C_Text_And_File_Manager::M_Get_Data_By_Text(std::string in_search_text)
{
	// ☆ 変数宣言 ☆ //
	int text_size = (int)in_search_text.size();	// 探索する文字の文字数
	int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// 探索可能な最大列数


	// 一文字目が一致するかを繰り返して探索
	for (int loop_column = mpr_variable.column_number + 1; loop_column <= column_sum; loop_column++)
	{
		// 同じ文字があったら探索し続ける
		for (int check_x = 0; in_search_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x]; check_x++)
		{
			// 見つかったらそこまでの文章を返す
			if (check_x + 1 >= text_size)
			{
				return mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number, loop_column - mpr_variable.column_number);
			}
		}
	}

	// なければ発見できなかったことを返す
	return "___Not_Founds___";
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：行の始まりから選択中の場所までを返す
// 引数   ：void
// 戻り値 ：std::string 返す文字
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
std::string C_Text_And_File_Manager::M_Get_Data_Left_In_Row(void)
{
	return mpr_variable.sentence_data[mpr_variable.row_number].substr(0, mpr_variable.column_number);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：選択中の場所から行末までを返す
// 引数   ：void
// 戻り値 ：std::string 返す文字
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
std::string C_Text_And_File_Manager::M_Get_Data_Right_In_Row(void)
{
	return mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：今の選択中の行の始まりから終わりまでをとる
// 引数   ：void
// 戻り値 ：std::string 返す文字
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
std::string C_Text_And_File_Manager::M_Get_Data_Now_Row(void)
{
	return mpr_variable.sentence_data[mpr_variable.row_number];
}


//-☆- 編集位置 -☆-//

//=☆ 直接移動系 ☆=//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：文の始まりに移動する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Goto_Sentence_Start(void)
{
	mpr_variable.row_number = 0;
	mpr_variable.column_number = 0;

	return;
}

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：文の終わりに移動する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Goto_Sentence_End(void)
{
	// 一番下の行へ移動
	mpr_variable.row_number = (int)mpr_variable.sentence_data.size() - 1;

	// 文字の位置を行内の最後から取得
	mpr_variable.column_number = (int)mpr_variable.sentence_data[mpr_variable.row_number].size();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：行の始まりに移動する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Goto_Column_In_Row_Start(void)
{
	mpr_variable.column_number = 0;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：行の終わりに移動する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Goto_Column_In_Row_End(void)
{
	mpr_variable.column_number = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - 1;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：行の始まりに移動する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Goto_Start_Row(void)
{
	mpr_variable.row_number = 0;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：行の始まりに移動する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Goto_End_Row(void)
{
	mpr_variable.row_number = (int)mpr_variable.sentence_data.size() - 1;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された行に移動する
// 引数   ：行の番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Goto_Row_By_Set_Number(unsigned int in_set_row)
{
	// 値をセットする
	mpr_variable.row_number = in_set_row;


	// 行が足りていなければ増やす
	if (mpr_variable.sentence_data.size() <= mpr_variable.row_number)
	{
		mpr_variable.sentence_data.resize(mpr_variable.row_number + 1);
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された行に移動する
// 引数   ：列の番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Goto_Column_By_Set_Number(unsigned int in_set_column)
{
	// 値をセットする
	mpr_variable.column_number = in_set_column;


	// 列が足りていなければ増やす
	if (mpr_variable.sentence_data[mpr_variable.row_number].size() <= mpr_variable.column_number)
	{
		mpr_variable.sentence_data[mpr_variable.row_number].resize(mpr_variable.column_number + 1);
	}

	return;
}


//=☆ 間接移動系 ☆==//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された数分、移動する
// 引数   ：移動量
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Move_Position_By_Number(int in_move_num)
{
	// ☆ 移動しない時はスルー ☆ //
	if (in_move_num == 0)
	{
		return;
	}


	// ☆ 移動が＋方向の時 ☆ //
	if (in_move_num > 0)
	{
		// ☆ 今の場所からの判定 ☆ //

		// 行内で収まるなら列を移動分移動させる
		if (mpr_variable.column_number + in_move_num <= mpr_variable.sentence_data[mpr_variable.row_number].size())
		{
			mpr_variable.column_number += in_move_num;

			return;
		}


		// 探索分を減らす
		in_move_num -= (int)mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number).size();


		// 収まらないなら何列目まで行くかを探索する
		for (mpr_variable.row_number += 1; mpr_variable.row_number < mpr_variable.sentence_data.size(); mpr_variable.row_number++)
		{
			// この行内で収まるなら列を残りの分に設定
			if (in_move_num < mpr_variable.sentence_data[mpr_variable.row_number].size())
			{
				mpr_variable.column_number = in_move_num;

				return;
			}


			// 探索分を減らす
			in_move_num -= (int)mpr_variable.sentence_data[mpr_variable.row_number].size();
		}


		// 最後まで探索したのにまだ文字数がある場合は最後の場所で打ち切る
		mpr_variable.row_number = (int)mpr_variable.sentence_data.size() - 1;
		mpr_variable.column_number = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - 1;

		return;
	}


	// ☆ 移動が-方向の時 ☆ //

	// ＋で判断した方が分かりやすいので変換
	in_move_num *= -1;


	// 行内で収まるなら列を移動分移動させる
	if (mpr_variable.column_number - in_move_num > -1)
	{
		mpr_variable.column_number -= in_move_num;

		return;
	}


	// 探索分を減らす
	in_move_num -= (int)mpr_variable.sentence_data[mpr_variable.row_number].substr(0, mpr_variable.column_number).size();


	// 列内で収まらないなら何列目まで行くかを探索する
	for (mpr_variable.row_number -= 1; mpr_variable.row_number > -1; mpr_variable.row_number--)
	{
		// 行内で収まるなら列を移動分移動させる
		if (mpr_variable.sentence_data[mpr_variable.row_number].size() - in_move_num > 0)
		{
			mpr_variable.column_number = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - (1 + in_move_num);

			return;
		}


		// 探索分を減らす
		in_move_num -= (int)mpr_variable.sentence_data[mpr_variable.row_number].size();
	}


	// 一番最初よりも後ろを指定されていたら一番最初でおわる
	mpr_variable.row_number = 0;
	mpr_variable.column_number = 0;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された数分、移動する
// 引数   ：移動量
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Move_Raw_By_Number(int in_move_row_num)
{
	// ☆ 移動しない時はスルー ☆ //
	if (in_move_row_num == 0)
	{
		return;
	}


	// ☆ 移動が＋方向の時 ☆ //
	if (in_move_row_num > 0)
	{
		// 上限を超えるなら最後の行を直接指定
		if (mpr_variable.row_number + (int)in_move_row_num > mpr_variable.sentence_data.size())
		{
			mpr_variable.row_number = (int)mpr_variable.sentence_data.size();

			return;
		}


		// 超えないなら指定分移動させる
		mpr_variable.row_number += in_move_row_num;

		return;
	}


	// ☆ 移動が-方向の時 ☆ //

	// ＋で判断した方が分かりやすいので変換
	in_move_row_num *= -1;


	// 超えないなら指定分移動させる
	mpr_variable.row_number -= in_move_row_num;


	// 一番上を超えるなら最初の行を直接指定
	if (mpr_variable.row_number < 0)
	{
		mpr_variable.row_number = 0;

		return;
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：次の行へ移動する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Text_And_File_Manager::M_Move_Next_Raw(void)
{
	M_Move_Raw_By_Number(1);
	M_Goto_Column_By_Set_Number(0);

	return;
}


//=☆ 探索移動系 ☆=//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された文字と同じ文字のうち今の場所以降で一番近いものを文章ごと(改行も含めて)探索して、その文字の右に移動する
// 引数   ：string 探索する文字
// 戻り値 ：bool みつからなければfalse
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Goto_Right_By_Text_In_Front_Sentence(std::string in_serch_text)
{
	// ☆ 変数宣言 ☆ //
	int line_sum = (int)mpr_variable.sentence_data.size();	// 行数
	int text_size = (int)in_serch_text.size();	// 探索する文字の文字数


	// ☆ 選択中の行の時の探索 ☆ //
	{
		// ☆ 変数宣言 ☆ //
		int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size();	// 探索可能な最大列数


		// 一文字目が一致するかを繰り返して探索
		for (int loop_column = mpr_variable.column_number; loop_column <= column_sum; loop_column++)
		{
			// ☆ 変数宣言 ☆ //
			std::string stack_check_string = mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column);	// 探索用文字列スタック

			int stack_size = (int)stack_check_string.size();	// スタックデータのサイズ
			int now_row_number = mpr_variable.row_number;	// 今の行の番号
			int indented_time = 0;	// 改行した回数

			bool flg_not_this = false;	// データが同じでない事を表すフラグ


			// 同じ文字があったら探索し続ける
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// 改行コードがあるなら次の行を読み込む
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// 次の行があるなら改行
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// 次の行が必要なのにないならこの文字の判定を最後にする
					else
					{
						flg_not_this = true;
					}
				}


				// 違うなら探索をやめる
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// 見つかったらそこに移動して終了
				else if (check_x + 1 >= text_size)
				{
					// 改行していなかったら文字数分移動
					if (indented_time == 0)
					{
						mpr_variable.column_number = loop_column + text_size;
					}

					// 改行していたら現在の探索位置を探して移動
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


				// 次の一行が最後の文字を超えるなら改行する
				if (check_x + 1 >= stack_size)
				{
					// 次の行があるなら改行
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// 次の行が必要なのにないならこの文字の判定を最後にする
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}


	// 次の行から指定された文字を探索する
	for (int loop_row = mpr_variable.row_number + 1; loop_row < line_sum; loop_row++)
	{
		// ☆ 変数宣言 ☆ //
		int column_sum = (int)mpr_variable.sentence_data[loop_row].size();	// 探索可能な最大列数


		// 同じ行にあるかどうかを判定する
		for (int loop_column = 0; loop_column <= column_sum; loop_column++)
		{
			// ☆ 変数宣言 ☆ //
			std::string stack_check_string = mpr_variable.sentence_data[loop_row].substr(loop_column);	// 探索用文字列スタック

			int stack_size = (int)stack_check_string.size();	// スタックデータのサイズ
			int now_row_number = loop_row;	// 今の行の番号
			int indented_time = 0;	// 改行した回数

			bool flg_not_this = false;	// データが同じでない事を表すフラグ


			// 同じ文字があったら探索し続ける
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// 改行コードがあるなら次の行を読み込む
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// 次の行があるなら改行
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// 次の行が必要なのにないならこの文字の判定を最後にする
					else
					{
						flg_not_this = true;
					}
				}


				// 違うなら探索をやめる
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// 見つかったらそこに移動して終了
				else if (check_x + 1 >= text_size)
				{
					// 改行していなかったら文字数分移動
					if (indented_time == 0)
					{
						mpr_variable.column_number = loop_column + text_size;
					}

					// 改行していたら現在の探索位置を探して移動
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


				// 次の一行が最後の文字を超えるなら改行する
				if (check_x + 1 >= stack_size)
				{
					// 次の行があるなら改行
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// 次の行が必要なのにないならこの文字の判定を最後にする
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}

	// みつからなかった
	return false;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された文字と同じ文字のうち今の場所以前で一番近いものを文章ごと(改行も含めて)探索して、その文字の右に移動する
// 引数   ：std::string 探索する文字
// 戻り値 ：bool みつからなければfalse
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Goto_Right_By_Text_In_Back_Sentence(std::string in_serch_text)
{
	// ☆ 変数宣言 ☆ //
	int line_sum = (int)mpr_variable.sentence_data.size();	// 行数
	int text_size = (int)in_serch_text.size();	// 探索する文字の文字数


	// ☆ 選択中の行の時の探索 ☆ //
	{
		// ☆ 変数宣言 ☆ //
		int start_column = (int)mpr_variable.sentence_data[mpr_variable.row_number].size();	// 探索開始位置


		// 通常時の探索開始位置より選択位置が左であれば探索開始位置をずらす
		if (mpr_variable.column_number <= start_column)
		{
			start_column = mpr_variable.column_number - 1;
		}


		// 一文字目が一致するかを繰り返して探索
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			// ☆ 変数宣言 ☆ //
			std::string stack_check_string = mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column);	// 探索用文字列スタック

			int stack_size = (int)stack_check_string.size();	// スタックデータのサイズ
			int now_row_number = mpr_variable.row_number;	// 今の行の番号
			int indented_time = 0;	// 改行した回数

			bool flg_not_this = false;	// データが同じでない事を表すフラグ


			// 同じ文字があったら探索し続ける
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// 改行コードがあるなら次の行を読み込む
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// 次の行があるなら改行
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// 次の行が必要なのにないならこの文字の判定を最後にする
					else
					{
						flg_not_this = true;
					}
				}


				// 違うなら探索をやめる
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// 見つかったらそこに移動して終了
				else if (check_x + 1 >= text_size)
				{
					// 改行していなかったら文字数分移動
					if (indented_time == 0)
					{
						mpr_variable.column_number = loop_column + text_size;
					}

					// 改行していたら現在の探索位置を探して移動
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


				// 次の一行が最後の文字を超えるなら改行する
				if (check_x + 1 >= stack_size)
				{
					// 次の行があるなら改行
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// 次の行が必要なのにないならこの文字の判定を最後にする
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}


	// 一つ前の行から指定された文字を探索する
	for (int loop_row = mpr_variable.row_number - 1; loop_row > -1; loop_row--)
	{
		// ☆ 変数宣言 ☆ //
		int start_column = (int)mpr_variable.sentence_data[loop_row].size();	// 探索開始位置


		// 一文字目が一致するかを繰り返して探索
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			// ☆ 変数宣言 ☆ //
			std::string stack_check_string = mpr_variable.sentence_data[loop_row].substr(loop_column);	// 探索用文字列スタック

			int stack_size = (int)stack_check_string.size();	// スタックデータのサイズ
			int now_row_number = loop_row;	// 今の行の番号
			int indented_time = 0;	// 改行した回数

			bool flg_not_this = false;	// データが同じでない事を表すフラグ


			// 同じ文字があったら探索し続ける
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// 改行コードがあるなら次の行を読み込む
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// 次の行があるなら改行
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// 次の行が必要なのにないならこの文字の判定を最後にする
					else
					{
						flg_not_this = true;
					}
				}


				// 違うなら探索をやめる
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// 見つかったらそこに移動して終了
				else if (check_x + 1 >= text_size)
				{
					// 改行していなかったら文字数分移動
					if (indented_time == 0)
					{
						mpr_variable.column_number = loop_column + text_size;
					}

					// 改行していたら現在の探索位置を探して移動
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


				// 次の一行が最後の文字を超えるなら改行する
				if (check_x + 1 >= stack_size)
				{
					// 次の行があるなら改行
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// 次の行が必要なのにないならこの文字の判定を最後にする
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}

	// みつからなかった
	return false;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された文字と同じ文字のうち今の場所以降で一番近いものを行ごとに（改行は含めずに）探索して、その文字の右に移動する
// 引数   ：std::string 探索する文字
// 戻り値 ：bool みつからなければfalse
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Goto_Right_By_Text_In_Front_Row(std::string in_serch_text)
{
	// ☆ 変数宣言 ☆ //
	int line_sum = (int)mpr_variable.sentence_data.size();	// 行数
	int text_size = (int)in_serch_text.size();	// 探索する文字の文字数


	// ☆ 選択中の行の時の探索 ☆ //
	{
		// ☆ 変数宣言 ☆ //
		int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// 探索可能な最大列数


		// 一文字目が一致するかを繰り返して探索
		for (int loop_column = mpr_variable.column_number; loop_column <= column_sum; loop_column++)
		{
			// 同じ文字があったら探索し続ける
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
			{
				// 見つかったらそこに移動して終了
				if (check_x + 1 >= text_size)
				{
					mpr_variable.column_number = loop_column + text_size;

					return true;
				}
			}
		}
	}


	// 次の行から指定された文字を探索する
	for (int loop_row = mpr_variable.row_number + 1; loop_row < line_sum; loop_row++)
	{
		// ☆ 変数宣言 ☆ //
		int column_sum = (int)mpr_variable.sentence_data[loop_row].size() - text_size;	// 探索可能な最大列数


		// 一文字目が一致するかを繰り返して探索
		for (int loop_column = 0; loop_column <= column_sum; loop_column++)
		{
			// 同じ文字があったら探索し続ける
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[loop_row][loop_column + check_x] && check_x < text_size; check_x++)
			{
				// 見つかったらそこに移動して終了
				if (check_x + 1 >= text_size)
				{
					mpr_variable.row_number = loop_row;
					mpr_variable.column_number = loop_column + text_size;

					return true;
				}
			}
		}
	}

	// みつからなかった
	return false;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された文字と同じ文字のうち今の場所以前で一番近いものを行ごとに（改行は含めずに）探索して、その文字の右に移動する
// 引数   ：std::string 探索する文字
// 戻り値 ：bool みつからなければfalse
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Goto_Right_By_Text_In_Back_Row(std::string in_serch_text)
{
	// ☆ 変数宣言 ☆ //
	int text_size = (int)in_serch_text.size();	// 探索する文字の文字数


	// ☆ 選択中の行の時の探索 ☆ //
	{
		// ☆ 変数宣言 ☆ //
		int start_column = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// 探索開始位置


		// 通常時の探索開始位置より選択位置が左であれば探索開始位置をずらす
		if (mpr_variable.column_number <= start_column)
		{
			start_column = mpr_variable.column_number - 1;
		}


		// 一文字目が一致するかを繰り返して探索
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			// 同じ文字があったら探索し続ける
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
			{
				// 見つかったらそこに移動して終了
				if (check_x + 1 >= text_size)
				{
					// 同じ場所に帰ってきていなければ移動する（帰った場合はここでスルーすればループを抜ける）
					if (mpr_variable.column_number != loop_column + text_size)
					{
						mpr_variable.column_number = loop_column + text_size;

						return true;
					}
				}
			}
		}
	}


	// 一つ前の行から指定された文字を探索する
	for (int loop_row = mpr_variable.row_number - 1; loop_row > -1; loop_row--)
	{
		// ☆ 変数宣言 ☆ //
		int start_column = (int)mpr_variable.sentence_data[loop_row].size() - text_size;	// 探索開始位置


		// 通常時の探索開始位置より選択位置が左であれば探索開始位置をずらす
		if (mpr_variable.column_number <= start_column)
		{
			start_column = mpr_variable.column_number - 1;
		}


		// 一文字目が一致するかを繰り返して探索
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			// 同じ文字があったら探索し続ける
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[loop_row][loop_column + check_x] && check_x < text_size; check_x++)
			{
				// 見つかったらそこに移動して終了
				if (check_x + 1 >= text_size)
				{
					mpr_variable.row_number = loop_row;
					mpr_variable.column_number = loop_column + text_size;

					return true;
				}
			}
		}
	}

	// みつからなかった
	return false;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された文字と同じ文字のうち今の場所以前で一番近いものを行ごとに（改行は含めずに）探索して、その文字の右に移動する
// 引数   ：std::string 探索する文字
// 戻り値 ：bool みつからなければfalse
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Goto_Right_By_Text_In_Front_Column(std::string in_serch_text)
{
	// ☆ 変数宣言 ☆ //
	int text_size = (int)in_serch_text.size();	// 探索する文字の文字数
	int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// 探索可能な最大列数


	// 一文字目が一致するかを繰り返して探索
	for (int loop_column = mpr_variable.column_number; loop_column <= column_sum; loop_column++)
	{
		// 同じ文字があったら探索し続ける
		for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
		{
			// 見つかったらそこに移動して終了
			if (check_x + 1 >= text_size)
			{
				mpr_variable.column_number = loop_column + text_size;

				return true;
			}
		}
	}

	// みつからなかった
	return false;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された文字と同じ文字のうち今の場所以前で一番近いものを行ごとに（改行は含めずに）探索して、その文字の右に移動する
// 引数   ：std::string 探索する文字
// 戻り値 ：bool みつからなければfalse
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Goto_Right_By_Text_In_Back_Column(std::string in_serch_text)
{
	// ☆ 変数宣言 ☆ //
	int text_size = (int)in_serch_text.size();	// 探索する文字の文字数
	int start_column = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// 探索開始位置


	// 通常時の探索開始位置より選択位置が左であれば探索開始位置をずらす
	if (mpr_variable.column_number <= start_column)
	{
		start_column = mpr_variable.column_number - 1;
	}


	// 一文字目が一致するかを繰り返して探索
	for (int loop_column = start_column; loop_column > -1; loop_column--)
	{
		// 同じ文字があったら探索し続ける
		for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
		{
			// 見つかったらそこに移動して終了
			if (check_x + 1 >= text_size)
			{
				// 同じ場所に帰ってきていなければ移動する（帰った場合はここでスルーすればループを抜ける）
				if (mpr_variable.column_number != loop_column + text_size)
				{
					mpr_variable.column_number = loop_column + text_size;

					return true;
				}
			}
		}
	}

	// みつからなかった
	return false;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された文字と同じ文字のうち今の場所以降で一番近いものを文章ごと(改行も含めて)探索して、その文字の左に移動する
// 引数   ：std::string 探索する文字
// 戻り値 ：bool みつからなければfalse
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Goto_Left_By_Text_In_Front_Sentence(std::string in_serch_text)
{
	// ☆ 変数宣言 ☆ //
	int line_sum = (int)mpr_variable.sentence_data.size();	// 行数
	int text_size = (int)in_serch_text.size();	// 探索する文字の文字数


	// ☆ 選択中の行の時の探索 ☆ //
	{
		// ☆ 変数宣言 ☆ //
		int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size();	// 探索可能な最大列数


		// 一文字目が一致するかを繰り返して探索
		for (int loop_column = mpr_variable.column_number + 1; loop_column <= column_sum; loop_column++)
		{
			// ☆ 変数宣言 ☆ //
			std::string stack_check_string = mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column);	// 探索用文字列スタック

			int stack_size = (int)stack_check_string.size();	// スタックデータのサイズ
			int now_row_number = mpr_variable.row_number;	// 今の行の番号
			int indented_time = 0;	// 改行した回数

			bool flg_not_this = false;	// データが同じでない事を表すフラグ


			// 同じ文字があったら探索し続ける
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// 改行コードがあるなら次の行を読み込む
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// 次の行があるなら改行
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// 次の行が必要なのにないならこの文字の判定を最後にする
					else
					{
						flg_not_this = true;
					}
				}


				// 違うなら探索をやめる
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// 見つかったらそこに移動して終了
				else if (check_x + 1 >= text_size)
				{
					// 改行していなかったら文字数分移動
					if (indented_time == 0)
					{
						mpr_variable.column_number = loop_column + text_size;
					}

					// 改行していたら現在の探索位置を探して移動
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


				// 次の一行が最後の文字を超えるなら改行する
				if (check_x + 1 >= stack_size)
				{
					// 次の行があるなら改行
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// 次の行が必要なのにないならこの文字の判定を最後にする
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}


	// 次の行から指定された文字を探索する
	for (int loop_row = mpr_variable.row_number + 1; loop_row < line_sum; loop_row++)
	{
		// ☆ 変数宣言 ☆ //
		int column_sum = (int)mpr_variable.sentence_data[loop_row].size();	// 探索可能な最大列数


		// 同じ行にあるかどうかを判定する
		for (int loop_column = 0; loop_column <= column_sum; loop_column++)
		{
			// ☆ 変数宣言 ☆ //
			std::string stack_check_string = mpr_variable.sentence_data[loop_row].substr(loop_column);	// 探索用文字列スタック

			int stack_size = (int)stack_check_string.size();	// スタックデータのサイズ
			int now_row_number = loop_row;	// 今の行の番号
			int indented_time = 0;	// 改行した回数

			bool flg_not_this = false;	// データが同じでない事を表すフラグ


			// 同じ文字があったら探索し続ける
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// 改行コードがあるなら次の行を読み込む
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// 次の行があるなら改行
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// 次の行が必要なのにないならこの文字の判定を最後にする
					else
					{
						flg_not_this = true;
					}
				}


				// 違うなら探索をやめる
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// 見つかったらそこに移動して終了
				else if (check_x + 1 >= text_size)
				{
					// 改行していなかったら文字数分移動
					if (indented_time == 0)
					{
						mpr_variable.column_number = loop_column + text_size;
					}

					// 改行していたら現在の探索位置を探して移動
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


				// 次の一行が最後の文字を超えるなら改行する
				if (check_x + 1 >= stack_size)
				{
					// 次の行があるなら改行
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						indented_time += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// 次の行が必要なのにないならこの文字の判定を最後にする
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}

	// みつからなかった
	return false;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された文字と同じ文字のうち今の場所以前で一番近いものを文章ごと(改行も含めて)探索して、その文字の左に移動する
// 引数   ：std::string 探索する文字
// 戻り値 ：bool みつからなければfalse
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Goto_Left_By_Text_In_Back_Sentence(std::string in_serch_text)
{
	// ☆ 変数宣言 ☆ //
	int line_sum = (int)mpr_variable.sentence_data.size();	// 行数
	int text_size = (int)in_serch_text.size();	// 探索する文字の文字数


	// ☆ 選択中の行の時の探索 ☆ //
	{
		// ☆ 変数宣言 ☆ //
		int start_column = (int)mpr_variable.sentence_data[mpr_variable.row_number].size();	// 探索開始位置


		// 通常時の探索開始位置より選択位置が左であれば探索開始位置をずらす
		if (mpr_variable.column_number <= start_column)
		{
			start_column = mpr_variable.column_number - 1;
		}


		// 一文字目が一致するかを繰り返して探索
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			// ☆ 変数宣言 ☆ //
			std::string stack_check_string = mpr_variable.sentence_data[mpr_variable.row_number].substr(loop_column);	// 探索用文字列スタック

			int stack_size = (int)stack_check_string.size();	// スタックデータのサイズ
			int now_row_number = mpr_variable.row_number;	// 今の行の番号

			bool flg_not_this = false;	// データが同じでない事を表すフラグ


			// 同じ文字があったら探索し続ける
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// 改行コードがあるなら次の行を読み込む
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// 次の行があるなら改行
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// 次の行が必要なのにないならこの文字の判定を最後にする
					else
					{
						flg_not_this = true;
					}
				}


				// 違うなら探索をやめる
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// 見つかったらそこに移動して終了
				else if (check_x + 1 >= text_size)
				{
					mpr_variable.row_number = now_row_number;
					mpr_variable.column_number = loop_column;

					return true;
				}


				// 次の一行が最後の文字を超えるなら改行する
				if (check_x + 1 >= stack_size)
				{
					// 次の行があるなら改行
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// 次の行が必要なのにないならこの文字の判定を最後にする
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}


	// 一つ前の行から指定された文字を探索する
	for (int loop_row = mpr_variable.row_number - 1; loop_row > -1; loop_row--)
	{
		// ☆ 変数宣言 ☆ //
		int start_column = (int)mpr_variable.sentence_data[loop_row].size();	// 探索開始位置


		// 一文字目が一致するかを繰り返して探索
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			// ☆ 変数宣言 ☆ //
			std::string stack_check_string = mpr_variable.sentence_data[loop_row].substr(loop_column);	// 探索用文字列スタック

			int stack_size = (int)stack_check_string.size();	// スタックデータのサイズ
			int now_row_number = loop_row;	// 今の行の番号

			bool flg_not_this = false;	// データが同じでない事を表すフラグ


			// 同じ文字があったら探索し続ける
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// 改行コードがあるなら次の行を読み込む
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// 次の行があるなら改行
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// 次の行が必要なのにないならこの文字の判定を最後にする
					else
					{
						flg_not_this = true;
					}
				}


				// 違うなら探索をやめる
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// 見つかったらそこに移動して終了
				else if (check_x + 1 >= text_size)
				{
					mpr_variable.row_number = now_row_number;
					mpr_variable.column_number = loop_column;

					return true;
				}


				// 次の一行が最後の文字を超えるなら改行する
				if (check_x + 1 >= stack_size)
				{
					// 次の行があるなら改行
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// 次の行が必要なのにないならこの文字の判定を最後にする
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}

	// みつからなかった
	return false;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された文字と同じ文字のうち今の場所以降で一番近いものを行ごとに（改行は含めずに）探索して、その文字の左に移動する
// 引数   ：std::string 探索する文字
// 戻り値 ：bool みつからなければfalse
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Goto_Left_By_Text_In_Front_Row(std::string in_serch_text)
{
	// ☆ 変数宣言 ☆ //
	int line_sum = (int)mpr_variable.sentence_data.size();	// 行数
	int text_size = (int)in_serch_text.size();	// 探索する文字の文字数


	// ☆ 選択中の行の時の探索 ☆ //
	{
		// ☆ 変数宣言 ☆ //
		int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// 探索可能な最大列数


		// 一文字目が一致するかを繰り返して探索
		for (int loop_column = mpr_variable.column_number + 1; loop_column <= column_sum; loop_column++)
		{
			// 同じ文字があったら探索し続ける
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
			{
				// 見つかったらそこに移動して終了
				if (check_x + 1 >= text_size)
				{
					mpr_variable.column_number = loop_column;

					return true;
				}
			}
		}
	}


	// 次の行から指定された文字を探索する
	for (int loop_row = mpr_variable.row_number + 1; loop_row < line_sum; loop_row++)
	{
		// ☆ 変数宣言 ☆ //
		int column_sum = (int)mpr_variable.sentence_data[loop_row].size() - text_size;	// 探索可能な最大列数


		// 一文字目が一致するかを繰り返して探索
		for (int loop_column = 0; loop_column <= column_sum; loop_column++)
		{
			// 同じ文字があったら探索し続ける
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[loop_row][loop_column + check_x] && check_x < text_size; check_x++)
			{
				// 見つかったらそこに移動して終了
				if (check_x + 1 >= text_size)
				{
					mpr_variable.row_number = loop_row;
					mpr_variable.column_number = loop_column;

					return true;
				}
			}
		}
	}

	// みつからなかった
	return false;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された文字と同じ文字のうち今の場所以前で一番近いものを行ごとに（改行は含めずに）探索して、その文字の左に移動する
// 引数   ：std::string 探索する文字
// 戻り値 ：bool みつからなければfalse
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Goto_Left_By_Text_In_Back_Row(std::string in_serch_text)
{
	// ☆ 変数宣言 ☆ //
	int text_size = (int)in_serch_text.size();	// 探索する文字の文字数


	// ☆ 選択中の行の時の探索 ☆ //
	{
		// ☆ 変数宣言 ☆ //
		int start_column = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// 探索開始位置


		// 通常時の探索開始位置より選択位置が左であれば探索開始位置をずらす
		if (mpr_variable.column_number <= start_column)
		{
			start_column = mpr_variable.column_number - 1;
		}


		// 一文字目が一致するかを繰り返して探索
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			// 同じ文字があったら探索し続ける
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
			{
				// 見つかったらそこに移動して終了
				if (check_x + 1 >= text_size)
				{
					mpr_variable.column_number = loop_column;

					return true;
				}
			}
		}
	}


	// 一つ前の行から指定された文字を探索する
	for (int loop_row = mpr_variable.row_number - 1; loop_row > -1; loop_row--)
	{
		// ☆ 変数宣言 ☆ //
		int start_column = (int)mpr_variable.sentence_data[loop_row].size() - text_size;	// 探索開始位置


		// 通常時の探索開始位置より選択位置が左であれば探索開始位置をずらす
		if (mpr_variable.column_number <= start_column)
		{
			start_column = mpr_variable.column_number - 1;
		}


		// 一文字目が一致するかを繰り返して探索
		for (int loop_column = start_column; loop_column > -1; loop_column--)
		{
			// 同じ文字があったら探索し続ける
			for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[loop_row][loop_column + check_x] && check_x < text_size; check_x++)
			{
				// 見つかったらそこに移動して終了
				if (check_x + 1 >= text_size)
				{
					mpr_variable.row_number = loop_row;
					mpr_variable.column_number = loop_column;

					return true;
				}
			}
		}
	}

	// みつからなかった
	return false;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された文字と同じ文字のうち今の場所以降で一番近いものを選択中の行内で探索して、その文字の左に移動する
// 引数   ：std::string 探索する文字
// 戻り値 ：bool みつからなければfalse
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Goto_Left_By_Text_In_Front_Column(std::string in_serch_text)
{
	// ☆ 変数宣言 ☆ //
	int text_size = (int)in_serch_text.size();	// 探索する文字の文字数
	int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// 探索可能な最大列数


	// 一文字目が一致するかを繰り返して探索
	for (int loop_column = mpr_variable.column_number + 1; loop_column <= column_sum; loop_column++)
	{
		// 同じ文字があったら探索し続ける
		for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
		{
			// 見つかったらそこに移動して終了
			if (check_x + 1 >= text_size)
			{
				mpr_variable.column_number = loop_column;

				return true;
			}
		}
	}

	// みつからなかった
	return false;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された文字と同じ文字のうち今の場所以前で一番近いものを選択中の行内で探索して、その文字の左に移動する
// 引数   ：std::string 探索する文字
// 戻り値 ：bool みつからなければfalse
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Goto_Left_By_Text_In_Back_Column(std::string in_serch_text)
{
	// ☆ 変数宣言 ☆ //
	int text_size = (int)in_serch_text.size();	// 探索する文字の文字数
	int start_column = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// 探索開始位置


	// 通常時の探索開始位置より選択位置が左であれば探索開始位置をずらす
	if (mpr_variable.column_number <= start_column)
	{
		start_column = mpr_variable.column_number - 1;
	}


	// 一文字目が一致するかを繰り返して探索
	for (int loop_column = start_column; loop_column > -1; loop_column--)
	{
		// 同じ文字があったら探索し続ける
		for (int check_x = 0; in_serch_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
		{
			// 見つかったらそこに移動して終了
			if (check_x + 1 >= text_size)
			{
				mpr_variable.column_number = loop_column;

				return true;
			}
		}
	}

	// みつからなかった
	return false;
}


//-☆- 文字探索 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：今選択中の行に指定された文字が選択中の列内あるかどうかを返す
// 引数   ：std::string 探索する文字
// 戻り値 ：bool みつからなければfalse
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Serch_Text_In_Sentence(std::string in_serch_text)
{
	// ☆ 変数宣言 ☆ //
	int line_sum = (int)mpr_variable.sentence_data.size();	// 行数
	int text_size = (int)in_serch_text.size();	// 探索する文字の文字数


	// 次の行から指定された文字を探索する
	for (int loop_row = 0; loop_row < line_sum; loop_row++)
	{
		// ☆ 変数宣言 ☆ //
		int column_sum = (int)mpr_variable.sentence_data[loop_row].size();	// 探索可能な最大列数


		// 同じ行にあるかどうかを判定する
		for (int loop_column = 0; loop_column <= column_sum; loop_column++)
		{
			// ☆ 変数宣言 ☆ //
			std::string stack_check_string = mpr_variable.sentence_data[loop_row].substr(loop_column);	// 探索用文字列スタック

			int stack_size = (int)stack_check_string.size();	// スタックデータのサイズ
			int now_row_number = loop_row;	// 今の行の番号

			bool flg_not_this = false;	// データが同じでない事を表すフラグ


			// 同じ文字があったら探索し続ける
			for (int check_x = 0; flg_not_this == false; check_x++)
			{
				// 改行コードがあるなら次の行を読み込む
				if (M_Is_CR(in_serch_text[check_x]) == true)
				{
					// 次の行があるなら改行
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						stack_check_string += '\n';
						check_x += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// 次の行が必要なのにないならこの文字の判定を最後にする
					else
					{
						flg_not_this = true;
					}
				}


				// 違うなら探索をやめる
				if (in_serch_text[check_x] != stack_check_string[check_x])
				{
					flg_not_this = true;
				}

				// 見つかったのでそのことを示して終了
				else if (check_x + 1 >= text_size)
				{
					return true;
				}


				// 次の一行が最後の文字を超えるなら改行する
				if (check_x + 1 >= stack_size)
				{
					// 次の行があるなら改行
					if (now_row_number + 1 < line_sum)
					{
						now_row_number += 1;
						stack_check_string += mpr_variable.sentence_data[now_row_number];
						stack_size = (int)stack_check_string.size();
					}

					// 次の行が必要なのにないならこの文字の判定を最後にする
					else
					{
						flg_not_this = true;
					}
				}
			}
		}
	}

	// みつからなかった
	return false;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：今選択中の行に指定された文字が選択中の列内あるかどうかを返す
// 引数   ：std::string 探索する文字
// 戻り値 ：bool みつからなければfalse
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Search_Text_In_Now_Row(std::string in_search_text)
{
	// ☆ 変数宣言 ☆ //
	int text_size = (int)in_search_text.size();	// 探索する文字の文字数
	int column_sum = (int)mpr_variable.sentence_data[mpr_variable.row_number].size() - text_size;	// 列数


	// 同じ行にあるかどうかを判定する
	for (int loop_column = 0; loop_column <= column_sum; loop_column++)
	{
		// 同じ文字があったら探索し続ける
		for (int check_x = 0; in_search_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][loop_column + check_x] && check_x < text_size; check_x++)
		{
			// 見つかったのでそのことを示して終了
			if (check_x + 1 >= text_size)
			{
				return true;
			}
		}
	}

	// みつからなかった
	return false;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された文字が指定された列内あるかどうかを返す
// 引数   ：int 探索する行, std::string 探索する文字
// 戻り値 ：bool みつからなければfalse
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Search_Text_In_Select_Row(int in_select_row, std::string in_search_text)
{
	// ☆ 変数宣言 ☆ //
	int text_size = (int)in_search_text.size();	// 探索する文字の文字数
	int column_sum = (int)mpr_variable.sentence_data[in_select_row].size() - text_size;	// 列数


	// 行の範囲外を指定されたらエラー
	if (in_select_row < 0 || mpr_variable.sentence_data.size() <= in_select_row)
	{
		return false;
	}


	// 同じ行にあるかどうかを判定する
	for (int loop_column = 0; loop_column <= column_sum; loop_column++)
	{
		// 同じ文字があったら探索し続ける
		for (int check_x = 0; in_search_text[check_x] == mpr_variable.sentence_data[in_select_row][loop_column + check_x] && check_x < text_size; check_x++)
		{
			// 見つかったのでそのことを示して終了
			if (check_x + 1 >= text_size)
			{
				return true;
			}
		}
	}

	// みつからなかった
	return false;
}


//-☆- 判定 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：今選択中の場所から文字が一致しているかを調べる
// 引数   ：std::string 探索する文字
// 戻り値 ：bool 一致したときのみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Check_Text_Is_Eqaul_Now_Position(std::string in_search_text)
{
	// ☆ 変数宣言 ☆ //
	int text_size = (int)in_search_text.size();	// 探索する文字の文字数


	// 指定された文字の文字数が今から探索する範囲を超えるなら違う文字列なので違うことを示す
	if (mpr_variable.sentence_data[mpr_variable.row_number].substr(mpr_variable.column_number).size() < text_size)
	{
		return false;
	}


	// 最初の文字から一致し続けるかどうかを検証する
	for (int check_x = 0; in_search_text[check_x] == mpr_variable.sentence_data[mpr_variable.row_number][check_x + mpr_variable.column_number] && check_x < text_size; check_x++)
	{
		// 最後まで一致し続けたら見つかったことを示して抜ける
		if (check_x + 1 >= text_size)
		{
			return true;
		}
	}

	// 違うことを示す
	return false;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ファイルがあるかどうかを判定する
// 引数   ：std::string ファイルまでのパス
// 戻り値 ：bool みつかったらtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Text_And_File_Manager::M_Is_File_Exist(std::string in_path_string)
{
	// ☆ 変数宣言 ☆ //
	std::fstream f_file_system(in_path_string, std::ios_base::in);	// ファイル操作用クラス、読み込みで宣言


	// ファイルを開けていなければエラーを返して終了
	if (!f_file_system)
	{
		f_file_system.close();
		return false;
	}


	// ファイルを閉じる
	f_file_system.close();

	return true;
}


