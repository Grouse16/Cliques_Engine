//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ウィンドウズ用のログを出力するクラスの定義
// 説明   ：デバッグ用にログを記録するシステムをウィンドウズ用に形成する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ デバッグ時のみ有効 ☆ //
#ifdef _DEBUG

// ☆ ウィンドウズ環境での実行時のみ有効 ☆ //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS


// ☆ ファイルひらき ☆ //
#include <string>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>
#include <conio.h>

#include "C_Windows_Console_Log_System.h"
#include "C_Text_And_File_Manager.h"
#include "C_OS_User_System.h"
#include "E_CONSOLE_LOG_TAGS.h"
#include "E_CONSOLE_LOG_COLOR.h"
#include "Console_Debug_Log_Names.h"
#include "GCC_Or_MSVC_Macro.h"
#include "Challenge_Mode_Macro.h"


// デバッグ時はメモリリーク検出
#define _CRTDBG_MAP_ALLOC


// ☆ ネームスペースの省略 ☆ //
using namespace DEBUGGER::LOG::CONSOLE::WINDOWS;


// ☆ ネームスペース ☆ //

// Windows用のコンソールシステムに使用する定数群を呼び出すための名前
namespace LOCALSPACE::CONSTANT_DATAS
{
	// ☆ 定数 ☆ //
	const char * con_DEBUG_FOLDER_PATH = "DEBUG_DATA/DEBUG_LOG";	// デバッグデータ保存先のパス

	constexpr int con_BLACK = 0;	// 黒色
	constexpr int con_GRAY = FOREGROUND_INTENSITY;	// 灰色
	constexpr int con_WHITE = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;	// 白色
	constexpr int con_LIGHT_WHITE = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;	// 明るい白色
	constexpr int con_RED = FOREGROUND_RED;		// 赤色
	constexpr int con_PINK = FOREGROUND_RED | FOREGROUND_INTENSITY;		// ピンク
	constexpr int con_GREEN = FOREGROUND_GREEN;	// 緑色
	constexpr int con_LIGHT_GREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY;	// 黄緑色
	constexpr int con_BLUE = FOREGROUND_BLUE;	// 青色
	constexpr int con_LIGHT_BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY;	// 水色
	constexpr int con_PURPLE = FOREGROUND_RED | FOREGROUND_BLUE;	// 紫色
	constexpr int con_LIGHT_PURPLE = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;	// 明るい紫色
	constexpr int con_YELLOW = FOREGROUND_RED | FOREGROUND_GREEN;	// 黄色
	constexpr int con_LIGHT_YELLOW = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;	// 明るい黄色
	constexpr int con_CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE;	// シアン（青紫）
	constexpr int con_LIGHT_CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;	// 明るいシアン（青紫）
}


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ、インスタンス化防止のために隠蔽
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Windows_Console_Log_System::C_Windows_Console_Log_System(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デバッグシステムの初期化
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Windows_Console_Log_System::M_Init_Debug(void)
{
	// アセンブラチャレンジ中
#ifdef  D_ASM_CHALLENGE

	// GCCでのコンパイル時
#ifdef D_GCC_COMPILE & D_ASM_CHALLENGE

	// すでに初期化されていれば抜ける
	asm volatile
		(
			"cmpb $1, %0\n"			// initialized が true (1) かどうかを比較
			"ret\n"					// initialized が true の場合はリターン
			:						// 出力オペランド
	: "m" (mpr_variable.initialized) // 入力オペランド
		);

	// MSVCでのコンパイル時
#elif D_MSVC_COMPILE

	// すでに初期化されていれば抜ける
	__asm
	{
		mov al, mpr_variable.initialized // initialized を AL レジスタにロード
		cmp al, 1                       // true (1) と比較
		ret                             // true の場合はリターン
	}

#endif

	// アセンブラチャレンジ中ではない時
#else

	// すでに初期化されていれば抜ける
	if (mpr_variable.initialized == true)
	{
		return;
	}

#endif //  D_ASM_CHALLENGE


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
	if (_setmode(_fileno(stdout), _O_TEXT) == -1)
	{
		return;
	}


	// なんとなくカッコいい色を設定する
	DEBUGGER::LOG::CONSOLE::WINDOWS::C_Windows_Console_Log_System::M_Set_Console_Color_Text_And_Back(COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);

	// ログの生成に成功したことをログとして残す
	M_Print_Log(TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, ALL_LOG_NAME::MAIN_SYSTEM::con_CONSOLE_CREATED, "デバッグ用コンソール及びシステムの生成に成功");

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：Windows用のコンソールログシステムを生成する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Windows_Console_Log_System::M_Create_Windows_Console_Debug_Log_System(void)
{
	// ☆ 変数宣言 ☆ //
	C_Windows_Console_Log_System * new_windows_console_log_system = new C_Windows_Console_Log_System();	// ウィンドウズ用のコンソールログシステム


	// デバッグシステムの初期化
	new_windows_console_log_system->M_Init_Debug();

	// シングルトンのインスタンスを生成
	m_this.reset(new_windows_console_log_system);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Windows_Console_Log_System::~C_Windows_Console_Log_System(void)
{
	M_Delete_Console_Debug_Log_System();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デバッグログシステムを削除する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Windows_Console_Log_System::M_Delete_Console_Debug_Log_System(void)
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
// 引数   ：C_Console_Debug_Log_System_Base::E_CONSOLE_LOG_TAGS ログの種類, string 記録するファイル名, string 記録内容
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Windows_Console_Log_System::M_Print_Log(TAGS::E_CONSOLE_LOG_TAGS in_tag, std::string in_file_name, std::string in_print_log)
{
	// ☆ 変数宣言 ☆ //
	SYSTEM::TEXT::C_Text_And_File_Manager file_user_system;	// ファイル操作用システム

	OS::S_Day_And_Time_Inform now_time_and_day;	// 時間と日付

	std::string log_file_path;	// 出力するログタイトル
	std::string print_log;	// 出力するログ


	// 現在の時間情報を取得
	OS::C_OS_User_System::M_Update_Time();
	now_time_and_day = OS::C_OS_User_System::M_Get_Now_Day_And_Time();


	// 出力するログの日付を設定
	log_file_path += std::to_string(now_time_and_day.year)		// 年の表示
		+ "-" + std::to_string(now_time_and_day.month)		// 月の表示
		+ "-" + std::to_string(now_time_and_day.day) + "/";	// 日の表示


	// ☆ ログの識別番号によって別々の情報を付加 ☆ //
	switch (in_tag)
	{
		//-☆- システム -☆-//

		//  セットアップ  //
	case TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP:
		log_file_path += "SYSTEM_00-SET_UP-";
		break;

		//  シャットダウン時  //
	case TAGS::E_CONSOLE_LOG_TAGS::e_SHUT_DOWN:
		log_file_path += "SYSTEM_01-SHUT_DOWN-";
		break;


		//-☆- アプリケーション -☆-//

		//  オブジェクト  //
	case TAGS::E_CONSOLE_LOG_TAGS::e_OBJECT:
		log_file_path += "APPLICATION_00-OBJECT-";
		break;

		//  ゲームの描画用システム  //
	case TAGS::E_CONSOLE_LOG_TAGS::e_GAME_RENDERING:
		log_file_path += "APPLICATION_01-GAME_RENDERING-";
		break;

		//  UI  //
	case TAGS::E_CONSOLE_LOG_TAGS::e_UI:
		log_file_path += "APPLICATION_02-UI-";
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
	std::wcout << std::endl << log_file_path.c_str() << std::endl << print_log.c_str();


	// データを記入する
	file_user_system.M_Set_File_Path
	(
		((std::string)LOCALSPACE::CONSTANT_DATAS::con_DEBUG_FOLDER_PATH
		+ "/" + log_file_path
		+ "/" + (std::string)(in_file_name) + ".txt").c_str()
	);
	file_user_system.M_Input_This_Data((print_log + "\n\0").c_str());
	file_user_system.M_Add_Data_To_Now_File();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンソールをみるために処理を止めて入力バッファを全てクリアし
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Windows_Console_Log_System::M_Stop_Update_And_Log_Present(void)
{
	// ☆ 定数 ☆ //
	constexpr int con_ENTER = 13;	// Enterのアスキーコード


	// ☆ 変数宣言 ☆ //
	bool inputted_enter = false;	// Enterが押されたかどうか


	// バッファの内容を画面に出力
	std::wcout << std::flush;

	// Enterを待つことを表示する
	std::cout << std::endl;
	std::cout << "Press Enter to continue...";
	
	// Enterが押されるまで待機する
	while (inputted_enter == false)
	{
		// キーボードの入力をチェック
		if (_kbhit())
		{
			// Enterキーのアスキーコードが入力されたら（Enterの入力があったら）ループを抜ける
			if (_getch() == con_ENTER)
			{
				inputted_enter = true;
			}
		}
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンソールのログを初期化する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Windows_Console_Log_System::M_Console_Log_Flush(void)
{
	// ☆ 定数 ☆ //
	constexpr int con_LINE_SUM = 50;	// 画面をクリアするための空行の数


	// 色を元に戻す
	M_Set_Console_Text_Color(COLOR::E_CONSOLE_LOG_COLOR::e_WHITE);
	M_Set_Console_Back_Ground_Color(COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	
	// 空行を出力して画面をクリアしたように見せる
	for (int l_write_line = 0; l_write_line < con_LINE_SUM; ++l_write_line)
	{
		std::cout << std::endl;
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンソールの文字カラーを変更する
// 引数   ：E_CONSOLE_LOG_COLOR 設定する色番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Windows_Console_Log_System::M_Set_Console_Text_Color(COLOR::E_CONSOLE_LOG_COLOR in_set_color)
{
	// ☆ 変数宣言 ☆ //
	int & color_data = mpr_variable.text_color;	// 色データの設定先の参照


	// 本家ホームページ https://learn.microsoft.com/ja-JP/windows/console/console-screen-buffers#character-attributes

	// ☆ 文字カラー変更を設定 ☆ //
	switch (in_set_color)
	{
		//  黒  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_BLACK:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_BLACK;
		break;

		//  グレー  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_GRAY:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_GRAY;
		break;

		//  白  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_WHITE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_WHITE;
		break;

		//  明るい白  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_WHITE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_WHITE;
		break;

		//  赤  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_RED:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_RED;
		break;

		//  ピンク  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_PINK:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_PINK;
		break;

		//  緑  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_GREEN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_GREEN;
		break;

		//  明るい緑  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_GREEN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_GREEN;
		break;

		//  青  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_BLUE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_BLUE;
		break;

		//  明るい青  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_BLUE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_BLUE;
		break;

		//  紫  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_PURPLE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_PURPLE;
		break;

		//  明るい紫  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_PURPLE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_PURPLE;
		break;

		//  黄  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_YELLOW:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_YELLOW;
		break;

		//  明るい黄  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_YELLOW:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_YELLOW;
		break;

		//  シアン  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_CYAN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_CYAN;
		break;

		//  明るいシアン  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_CYAN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_CYAN;
		break;
	}


	// 色の更新
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), mpr_variable.text_color | mpr_variable.color_back);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンソールの背景カラーを変更する
// 引数   ：E_CONSOLE_LOG_COLOR 設定する色番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Windows_Console_Log_System::M_Set_Console_Back_Ground_Color(COLOR::E_CONSOLE_LOG_COLOR in_set_color)
{
	// ☆ 変数宣言 ☆ //
	int & color_data = mpr_variable.color_back;	// 色データの設定先の参照


	// ☆ 文字カラー変更を設定 ☆ //
	switch (in_set_color)
	{
		//  黒  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_BLACK:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_BLACK;
		break;

		//  グレー  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_GRAY:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_GRAY;
		break;

		//  白  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_WHITE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_WHITE;
		break;

		//  明るい白  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_WHITE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_WHITE;
		break;

		//  赤  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_RED:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_RED;
		break;

		//  ピンク  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_PINK:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_PINK;
		break;

		//  緑  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_GREEN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_GREEN;
		break;

		//  明るい緑  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_GREEN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_GREEN;
		break;

		//  青  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_BLUE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_BLUE;
		break;

		//  明るい青  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_BLUE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_BLUE;
		break;

		//  紫  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_PURPLE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_PURPLE;
		break;

		//  明るい紫  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_PURPLE:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_PURPLE;
		break;

		//  黄  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_YELLOW:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_YELLOW;
		break;

		//  明るい黄  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_YELLOW:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_YELLOW;
		break;

		//  シアン  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_CYAN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_CYAN;
		break;

		//  明るいシアン  //
	case COLOR::E_CONSOLE_LOG_COLOR::e_LIGHT_CYAN:
		color_data = LOCALSPACE::CONSTANT_DATAS::con_LIGHT_CYAN;
		break;
	}


	// 色の更新
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), mpr_variable.text_color | mpr_variable.color_back);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンソールの背景カラーを変更する
// 引数   ：E_CONSOLE_LOG_COLOR テキストの色番号, E_CONSOLE_LOG_COLOR 背景の色番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Windows_Console_Log_System::M_Set_Console_Color_Text_And_Back(COLOR::E_CONSOLE_LOG_COLOR in_txt_color, COLOR::E_CONSOLE_LOG_COLOR in_back_color)
{
	M_Set_Console_Text_Color(in_txt_color);
	M_Set_Console_Back_Ground_Color(in_back_color);

	return;
}


#endif // D_OS_IS_WINDOWS

#endif // _DEBUG

