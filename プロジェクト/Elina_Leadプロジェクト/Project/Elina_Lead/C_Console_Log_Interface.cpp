//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：コンソールログを出力するためのインターフェース
// 説明   ：コンソールログの生成や初期化、出力、解放を簡略化し、依存関係を切り離すためのインターフェース
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


//-☆- ファイルひらき -☆-//
#include "C_Console_Log_Interface.h"
#include "Platform_Detector_Macro.h"

#include "C_Deactivated_Console_Log_System.h"


// ウィンドウズ用のコンソールログシステムをひらく（デバッグ時のみ）
#ifdef D_OS_IS_WINDOWS
#include "C_Windows_Console_Log_System.h"

// OpenGL環境用のコンソールログシステムをひらく（デバッグ時のみ）
#elif D_OS_IS_MAC | D_OS_IS_LINUX | D_OS_IS_UNIX

#endif


// ☆ ネームスペースの省略 ☆ //
using namespace DEBUGGER::LOG::CONSOLE;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ、インスタンス化防止のために隠蔽
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Console_Log_Interface::C_Console_Log_Interface(void)
{
	return;
}


//==☆ パブリック ☆==//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デバッグログクラスを生成する、ＯＳやビルド時の設定で分岐する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Console_Log_Interface::M_Create_And_Initialize_Console_Log_System(void)
{
	// デバッグ時はコンソールログシステムを生成する
#ifdef _DEBUG

	// ウィンドウズ用のコンソールログシステムを生成する
#ifdef D_OS_IS_WINDOWS
	DEBUGGER::LOG::CONSOLE::WINDOWS::C_Windows_Console_Log_System::M_Create_Windows_Console_Debug_Log_System();

	// OpenGL環境用のコンソールログシステムを生成する
#elif D_OS_IS_MAC | D_OS_IS_LINUX | D_OS_IS_UNIX


	// 不明な場合は無効化する
#else 
	DEBUGGER::LOG::CONSOLE::DEACTIVATED::C_Deactivated_Console_Log_System::M_Create_Deactivated_Console_Debug_Log_System();

#endif // D_OS_IS_WINDOWS


// リリース時は無効化する
#else
	DEBUGGER::LOG::CONSOLE::DEACTIVATED::C_Deactivated_Console_Log_System::M_Create_Deactivated_Console_Debug_Log_System();

#endif // _DEBUG

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デバッグログシステムを削除する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Console_Log_Interface::M_Delete_Console_Log_System(void)
{
	// ☆ 変数宣言 ☆ //
	DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base * debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();	// コンソールログシステムのアドレス


	// もしも未生成なら削除する必要はない
	if (debug_console_log_system_address == nullptr)
	{
		return;
	}


	// デバッグログシステムを削除する
	DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Release();

	return;
}


//-☆- 出力 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された文字列を設定されたファイル名で出力する
// 引数   ：E_CONSOLE_LOG_TAGS ログの種類, string 記録するファイル名, string 記録内容
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Console_Log_Interface::M_Print_Log(TAGS::E_CONSOLE_LOG_TAGS in_tag, std::string in_file_name, std::string in_text)
{
	// ☆ 変数宣言 ☆ //
	DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base * debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();	// コンソールログシステムのアドレス


	// もしも未生成の状態でログ出力を要求されたら生成する
	if (debug_console_log_system_address == nullptr)
	{
		M_Create_And_Initialize_Console_Log_System();
		debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();
	}

	// デバッグログを出力する
	debug_console_log_system_address->M_Print_Log(in_tag, in_file_name, in_text);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：処理を止めてログを出す
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Console_Log_Interface::M_Stop_Update_And_Log_Present(void)
{
	// ☆ 変数宣言 ☆ //
	DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base * debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();	// コンソールログシステムのアドレス


	// もしも未生成の状態でログ出力を要求されたら生成する
	if (debug_console_log_system_address == nullptr)
	{
		M_Create_And_Initialize_Console_Log_System();
		debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();
	}

	// ログを表示する
	debug_console_log_system_address->M_Stop_Update_And_Log_Present();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンソール画面に出力中のログをフラッシュ（初期化）する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Console_Log_Interface::M_Console_LOG_Flush(void)
{
	// ☆ 変数宣言 ☆ //
	DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base * debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();	// コンソールログシステムのアドレス


	// もしも未生成の状態でログフラッシュを要求されたら生成する
	if (debug_console_log_system_address == nullptr)
	{
		M_Create_And_Initialize_Console_Log_System();
		debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();
	}

	// ログをフラッシュする
	debug_console_log_system_address->M_Console_Log_Flush();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンソールの文字カラーを変更する
// 引数   ：E_CONSOLE_LOG_COLOR 設定する色
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Console_Log_Interface::M_Set_Console_Text_Color(COLOR::E_CONSOLE_LOG_COLOR in_text_color)
{
	// ☆ 変数宣言 ☆ //
	DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base* debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();	// コンソールログシステムのアドレス


	// もしも未生成の状態で色変更を要求されたら生成する
	if (debug_console_log_system_address == nullptr)
	{
		M_Create_And_Initialize_Console_Log_System();
		debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();
	}


	// テキストカラーを変更する
	debug_console_log_system_address->M_Set_Console_Text_Color(in_text_color);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンソールの背景カラーを変更する
// 引数   ：E_CONSOLE_LOG_COLOR 設定する色
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Console_Log_Interface::M_Set_Console_Back_Ground_Color(COLOR::E_CONSOLE_LOG_COLOR in_back_color)
{
	// ☆ 変数宣言 ☆ //
	DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base* debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();	// コンソールログシステムのアドレス


	// もしも未生成の状態で色変更を要求されたら生成する
	if (debug_console_log_system_address == nullptr)
	{
		M_Create_And_Initialize_Console_Log_System();
		debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();
	}

	
	// 背景カラーを変更する
	debug_console_log_system_address->M_Set_Console_Back_Ground_Color(in_back_color);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンソールの文字と背景カラーを変更する
// 引数   ：E_CONSOLE_LOG_COLOR 文字の色, E_CONSOLE_LOG_COLOR 背景の色
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(COLOR::E_CONSOLE_LOG_COLOR in_text_color, COLOR::E_CONSOLE_LOG_COLOR in_back_color)
{
	// ☆ 変数宣言 ☆ //
	DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base * debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();	// コンソールログシステムのアドレス


	// もしも未生成の状態で色変更を要求されたら生成する
	if (debug_console_log_system_address == nullptr)
	{
		M_Create_And_Initialize_Console_Log_System();
		debug_console_log_system_address = DEBUGGER::LOG::CONSOLE::BASE::C_Console_Debug_Log_System_Base::M_Get_Console_Debug_Log_System();
	}


	// テキストカラーを変更する
	debug_console_log_system_address->M_Set_Console_Color_Text_And_Back(in_text_color, in_back_color);

	return;
}


