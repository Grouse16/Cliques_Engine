//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：Cliques Engineのメイン関数部
// 説明   ：ここでメインループやセットアップを行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ マクロ ☆ //

// デバッグを行うためのログシステムのマクロ
#define _CRTDBG_MAP_ALLOC


// ☆ ファイルひらき ☆ //
#include "C_Game_Manager.h"
#include "C_OS_Manager_And_Rendering_API_Initialize_And_Release_System.h"

#include "C_Console_Log_Interface.h"


// ☆ 関数 ☆ //

//-☆- 初期化と終了時 -☆-//

// OSシステムの生成を行う
void M_OS_Create_System(void);

// レンダリングAPIの初期化を行う
void M_Rendering_API_Init(void);

// ゲームシステムの初期化を行う
void M_Game_Set_Up(void);

// ゲームの終了処理
void M_Game_End(void);


//-☆- デバッグログ -☆-//

// 初期化の成功を表示する
void M_Print_Log_Of_Succeeded_Init(void);


// ☆ メイン関数 ☆ //

// メイン関数（エントリーポイント）
int main(void)
{
	// ☆ 初期化 ☆ //
	
	// OS用システムの生成
	M_OS_Create_System();

	// レンダリングAPIの生成
	M_Rendering_API_Init();

	// ゲーム用システムの初期化
	M_Game_Set_Up();

	// デバッグ中は初期化成功時のみ成功のログを残す
	M_Print_Log_Of_Succeeded_Init();


	// ☆ メインループ ☆ //
	while (GAME::C_Game_Manager::M_Get_Game_Exist_Flg())
	{
		// ゲームのプロセスを実行
		GAME::C_Game_Manager::M_Executes_Process();
	}


	// ☆ 終了処理 ☆ //
	M_Game_End();


	// ☆ アプリおわり ☆ //
	return 0;
}


// ☆ 関数 ☆ //

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：OSシステムの生成を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void M_OS_Create_System(void)
{
	// OSを生成する　失敗で終了
	if (!PLATFORM::C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Create_OS(PLATFORM::E_RENDERING_API_KIND::e_DX12))
	{
		GAME::C_Game_Manager::M_Set_Game_Exist_Flg(false);
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリングAPIシステムの生成を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void M_Rendering_API_Init(void)
{
	// OS制御システムを初期化してレンダリングAPIを生成する　失敗で終了
	if (!PLATFORM::C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Init_OS_Management_System_And_Create_Rendering_API())
	{
		GAME::C_Game_Manager::M_Set_Game_Exist_Flg(false);
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ゲームシステムの初期化を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void M_Game_Set_Up(void)
{
	// これまでの初期化が成功している時のみ初期化を行う
	if (GAME::C_Game_Manager::M_Get_Game_Exist_Flg())
	{
		GAME::C_Game_Manager::M_Init();
	}

	return;
}



//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ゲームの終了処理
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void M_Game_End(void)
{
	// 終了が実行されたのでアプリケーションを停止を告知
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SHUT_DOWN, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::MAIN_SYSTEM::con_END, "-☆-☆-☆-☆-☆-☆-☆-終了が実行されたのでアプリケーションを停止-☆-☆-☆-☆-☆-☆-☆-");
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Console_LOG_Flush();

	// ゲームのメモリ解放
	GAME::C_Game_Manager::M_Release();

	// レンダリング用のアプリケーションを終了する
	PLATFORM::C_OS_Manager_And_Rendering_API_Initialize_And_Release_System::M_Release_OS_Management_System_And_Rendering_API();

	return;
}


//-☆- デバッグログ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：初期化の成功を表示する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void M_Print_Log_Of_Succeeded_Init(void)
{
	// 初期化に成功していなかったら抜ける
	if (!GAME::C_Game_Manager::M_Get_Game_Exist_Flg())
	{
		return;
	}

	// 初期化の成功のログを残す
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::MAIN_SYSTEM::con_ALL_SET_UP_SUCCEEDED, "-☆-☆-☆-☆-☆-☆-☆-初期化終了-☆-☆-☆-☆-☆-☆-☆-");
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Console_LOG_Flush();

	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::MAIN_SYSTEM::con_ALL_SET_UP_SUCCEEDED, "-☆-☆-☆-☆-☆-☆-☆-アプリケーション開始-☆-☆-☆-☆-☆-☆-☆-");
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::MAIN_SYSTEM::con_ALL_SET_UP_SUCCEEDED, "GUIの画面描画を開始します");

	return;
}




//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆

