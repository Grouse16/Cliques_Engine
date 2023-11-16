//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ログを出力するクラス
// 説明   ：デバッグ用にログを記録する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ デバッグ時のみ有効 ☆ //
#if _DEBUG


// ☆ ファイルひらき ☆ //
#include <string>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <atlstr.h>

#include "C_Log_System.h"
#include "C_Text_And_File_Manager.h"
#include "C_OS_System_Base.h"


// デバッグ時はメモリリーク検出
#define _CRTDBG_MAP_ALLOC


// ☆ ネームスペースの省略 ☆ //
using namespace DEBUGGER::LOG;


// ☆ 変数宣言 ☆ //
C_Log_System C_Log_System::m_this;	// 自クラスへのアクセス用の変数
C_Log_System::Pr_Variable C_Log_System::mpr_variable;	// プライベート変数へのアクセス用の変数


// ☆ 定数 ☆ //
const char* con_DEBUG_FOLDER_PATH = "DEBUG_DATA/DEBUG_LOG";	// デバッグデータ保存先のパス


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- 初期化 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Log_System::C_Log_System(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	return;
}


//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デバッグシステムの初期化
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Log_System::M_Init_Debug(void)
{
	// 初期化されていれば抜ける
	if (mpr_variable.initialized == true)
	{
		return;
	}

	// 初期化されたことを記録
	mpr_variable.initialized = true;

	// コンソール画面を初期化する
	FreeConsole();


	// コンソール画面を召喚する
	AllocConsole();
	AttachConsole(ATTACH_PARENT_PROCESS);


	// コンソールのデータファイルを入手
	_wfreopen_s(&mpr_variable.console_file, L"CONOUT$", L"w+", stdout);

	// 出力の文字コード指定、https://learn.microsoft.com/en-us/cpp/c-runtime-library/translation-mode-constants?view=msvc-170
	{int stab = _setmode(_fileno(stdout), _O_TEXT);}


	// なんとなくカッコいい色を設定する
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);


	// ログ召喚した事をログとして残す
	M_Print_Log(E_LOG_TAGS::e_SET_UP, ALL_LOG_NAME::MAIN_SYSTEM::con_CONSOLE_CREATED, "デバッグ用コンソール及びシステムの生成に成功(Create C_Log_System & Console：Succeeded)");

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Log_System::~C_Log_System(void)
{
	// コンソール画面を削除する
	FreeConsole();


	// ファイルを閉じる
	if (mpr_variable.console_file != nullptr)
	{
		fclose(mpr_variable.console_file);
	}

	return;
}


//-☆- ログ出力 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ログを出力する
// 引数   ：C_Log_System::E_LOG_TAGS ログの種類, string 記録するファイル名, string 記録内容
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Log_System::M_Print_Log(E_LOG_TAGS in_tag, std::string in_file_name, std::string in_print_log)
{
	// 初期化されていなければ初期化
	M_Init_Debug();


	// ☆ 変数宣言 ☆ //
	SYSTEM::TEXT::C_Text_And_File_Manager file_user_system;	// ファイル操作用システム

	OS::S_Time_Inform now_time_and_day;	// 時間と日付

	std::string log_title;	// 出力するログタイトル
	std::string print_log;	// 出力するログ


	// 時間情報をデータに変換
	OS::C_OS_System_Base::M_Get_Instance()->M_Get_Now_Time(now_time_and_day);


	// 出力するログの日付を設定
	log_title += std::to_string(now_time_and_day.year)		// 年の表示
		+ "-" + std::to_string(now_time_and_day.month)		// 月の表示
		+ "-" + std::to_string(now_time_and_day.day) + "/";	// 日の表示


	// ☆ ログの識別番号によって別々の情報を付加 ☆ //
	switch (in_tag)
	{
		//-☆- システム -☆-//

		//  セットアップ  //
	case E_LOG_TAGS::e_SET_UP:
		log_title += "SYSTEM_00-SET_UP-";
		break;

		//  シャットダウン時  //
	case E_LOG_TAGS::e_SHUT_DOWN:
		log_title += "SYSTEM_01-SHUT_DOWN-";
		break;


		//-☆- アプリケーション -☆-//

		//  オブジェクト  //
	case E_LOG_TAGS::e_OBJECT:
		log_title += "APPLICATION_00-OBJECT-";
		break;

		//  ゲームの描画用システム  //
	case E_LOG_TAGS::e_GAME_RENDERING:
		log_title += "APPLICATION_01-GAME_RENDERING-";
		break;

		//  UI  //
	case E_LOG_TAGS::e_UI:
		log_title += "APPLICATION_02-UI-";
		break;


		//-☆- エラー -☆-//

		// 例外時
	default:
		break;
	}


	// 出力するログを設定
	print_log =
		std::to_string(now_time_and_day.hour) + "-hour."	// 時間
		+ std::to_string(now_time_and_day.minute) + "-min."	// 分
		+ std::to_string(now_time_and_day.second) + "-sec\n"	// 秒
		+ (std::string)(in_print_log)+"\n";				// ログ内容


	// コンソールに情報を表示する
	std::wcout << std::endl << log_title.c_str() << std::endl << print_log.c_str();


	// データを記入する
	file_user_system.M_Set_File_Path(((std::string)con_DEBUG_FOLDER_PATH + "/" + log_title + "/" + (std::string)(in_file_name)+".txt").c_str());
	file_user_system.M_Input_This_Data((print_log + "\n\0").c_str());
	file_user_system.M_Add_Data_To_Now_File();
	
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンソールをみるために処理を止めて入力バッファを全てクリアし
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Log_System::M_Stop_Update_And_Log_Present(void)
{
	// バッファの内容を画面に出力
	std::wcout << std::flush;

	// enterを待つ
	std::cout << "Press Enter to continue...";
	fflush(stdin);
	std::cin.get();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンソールのログを初期化する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Log_System::M_Console_LOG_Flush(void)
{
	// 色を元に戻す
	C_Log_System::M_Set_Console_Text_Color(E_LOG_COLOR::e_WHITE);
	C_Log_System::M_Set_Console_Back_Ground_Color(E_LOG_COLOR::e_BLACK);
	std::system("cls");

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンソールの文字カラーを変更する
// 引数   ：E_LOG_COLOR 設定する色番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Log_System::M_Set_Console_Text_Color(E_LOG_COLOR in_set_color)
{
	// 本家ホームページ https://learn.microsoft.com/ja-JP/windows/console/console-screen-buffers#character-attributes

	// ☆ 文字カラー変更を設定 ☆ //
	switch (in_set_color)
	{
		//  白  //
	case E_LOG_COLOR::e_WHITE:
		m_this.mpr_variable.color_text = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;
		break;

		//  黒  //
	case E_LOG_COLOR::e_BLACK:
		m_this.mpr_variable.color_text = 0;
		break;

		//  青  //
	case E_LOG_COLOR::e_BLUE:
		m_this.mpr_variable.color_text = FOREGROUND_BLUE;
		break;

		//  緑  //
	case E_LOG_COLOR::e_GREEN:
		m_this.mpr_variable.color_text = FOREGROUND_GREEN;
		break;

		//  赤  //
	case E_LOG_COLOR::e_RED:
		m_this.mpr_variable.color_text = FOREGROUND_RED;
		break;

		//  紫  //
	case E_LOG_COLOR::e_PURPLE:
		m_this.mpr_variable.color_text = FOREGROUND_RED | FOREGROUND_BLUE;
		break;
	}


	// 色の更新
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), m_this.mpr_variable.color_text | m_this.mpr_variable.color_back);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンソールの背景カラーを変更する
// 引数   ：E_LOG_COLOR 設定する色番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Log_System::M_Set_Console_Back_Ground_Color(E_LOG_COLOR in_set_color)
{
	// ☆ 背景カラー変更を設定 ☆ //
	switch (in_set_color)
	{
		//  白  //
	case E_LOG_COLOR::e_WHITE:
		m_this.mpr_variable.color_back = BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED;
		break;

		//  黒  //
	case E_LOG_COLOR::e_BLACK:
		m_this.mpr_variable.color_back = 0;
		break;

		//  青  //
	case E_LOG_COLOR::e_BLUE:
		m_this.mpr_variable.color_back = BACKGROUND_BLUE;
		break;

		//  緑  //
	case E_LOG_COLOR::e_GREEN:
		m_this.mpr_variable.color_back = BACKGROUND_GREEN;
		break;

		//  赤  //
	case E_LOG_COLOR::e_RED:
		m_this.mpr_variable.color_back = BACKGROUND_RED;
		break;

		//  紫  //
	case E_LOG_COLOR::e_PURPLE:
		m_this.mpr_variable.color_back = BACKGROUND_RED | BACKGROUND_BLUE;
		break;
	}


	// 色の更新
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), m_this.mpr_variable.color_text | m_this.mpr_variable.color_back);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンソールの背景カラーを変更する
// 引数   ：E_LOG_COLOR テキストの色番号, E_LOG_COLOR 背景の色番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Log_System::M_Set_Console_Color_Text_And_Back(E_LOG_COLOR in_txt_color, E_LOG_COLOR in_back_color)
{
	M_Set_Console_Text_Color(in_txt_color);
	M_Set_Console_Back_Ground_Color(in_back_color);

	return;
}


#endif // _DEBUG

