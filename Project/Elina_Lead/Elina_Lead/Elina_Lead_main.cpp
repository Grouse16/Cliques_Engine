//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：自作ゲーム、エリナ・リードのメイン関数部
// 説明   ：ここでメインループやセットアップを行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ マクロ ☆ //

// デバッグを行うためのログシステムのマクロ
#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#include "C_Log_System.h"
#endif // _DEBUG


// ☆ OS検知 ☆ //
#include "Platform_Detector_Macro.h"


// ☆ ファイルひらき ☆ //
#include "C_Game_Manager.h"
#include "C_API_Initialize_And_Release_Manager.h"


// ☆ 関数 ☆ //

//-☆- 初期化と終了時 -☆-//

// OSシステムの生成を行う
void M_OS_Creat_System(void);

// レンダリングAPIの初期化を行う
void M_Rendering_API_Init(void);

// ゲームシステムの初期化を行う
void M_Game_Set_Up(void);

// ゲームの終了処理
void M_Game_End(void);


//-☆- デバッグ -☆-//
#if _DEBUG

// 初期化の成功を表示する
void M_Print_Log_Of_Succeeded_Init(void);

#endif // _DEBUG


// ☆ メイン関数 ☆ //

// ウィンドウズ時はWinmain関数を使うがこのマクロの有効範囲外では値を使用しないこと(他プラットフォームのために)	// ウィンドウズのサブシステムを指定すること
#ifdef D_OS_IS_WINDOWS
#include "C_Windows_System.h"
int APIENTRY WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE /* もう使用される事はない、常に０ */, _In_ LPSTR, _In_ int in_cmd_show)
{
// その他の時 OpenGL系はint main(void)関数から始める
#else
int main(void)
{
#endif

	//===☆ 処理開始 ☆===//
	
	// OS用システムの生成
	M_OS_Creat_System();


// ウィンドウズ時はコマンド番号をセット（DirectX未使用時はスルーされる）
#ifdef D_OS_IS_WINDOWS
	PLATFORM::C_API_Initialize_And_Release_Manager::M_Set_CMD_Number(in_cmd_show);
#endif


	// レンダリングAPIの生成
	M_Rendering_API_Init();

	// ゲーム用システムの初期化
	M_Game_Set_Up();


	// デバッグ時なら初期化の成功を表示（失敗時はスルーされる）
#if _DEBUG
	M_Print_Log_Of_Succeeded_Init();
#endif // _DEBUG
	

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
void M_OS_Creat_System(void)
{
	// OSを生成する　失敗で終了
	if (!PLATFORM::C_API_Initialize_And_Release_Manager::M_Creat_OS(PLATFORM::E_RENDERING_API_KIND::e_DX12))
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
	// OSの初期化を行う　失敗で終了
	if (!PLATFORM::C_API_Initialize_And_Release_Manager::M_Init_OS())
	{
		GAME::C_Game_Manager::M_Set_Game_Exist_Flg(false);
	}


	// レンダリングAPIを生成する　失敗で終了
	if (!PLATFORM::C_API_Initialize_And_Release_Manager::M_Init_API())
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
	// ☆ デバッグ時なら終了を表示 ☆ //
#if _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SHUT_DOWN, DEBUGGER::LOG::ALL_LOG_NAME::MAIN_SYSTEM::con_END, "-☆-☆-☆-☆-☆-☆-☆-終了が実行されたのでアプリケーションを停止-☆-☆-☆-☆-☆-☆-☆-");
	DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
	DEBUGGER::LOG::C_Log_System::M_Console_LOG_Flush();
#endif // _DEBUG


	// ゲームのメモリ解放
	GAME::C_Game_Manager::M_Release();

	// レンダリング用のアプリケーションを終了する
	PLATFORM::C_API_Initialize_And_Release_Manager::M_Relese_Graphics_API();

	return;
}


//-☆- デバッグ -☆-//
#if _DEBUG

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

	// ☆ デバッグ時なら初期化の成功を表示 ☆ //
#if _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::MAIN_SYSTEM::con_ALL_SET_UP_SUCCEEDED, "-☆-☆-☆-☆-☆-☆-☆-初期化終了-☆-☆-☆-☆-☆-☆-☆-");
	DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
	DEBUGGER::LOG::C_Log_System::M_Console_LOG_Flush();

	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::MAIN_SYSTEM::con_ALL_SET_UP_SUCCEEDED, "-☆-☆-☆-☆-☆-☆-☆-アプリケーション開始-☆-☆-☆-☆-☆-☆-☆-");
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::MAIN_SYSTEM::con_ALL_SET_UP_SUCCEEDED, "GUIの画面描画を開始します");
#endif

	return;
}

#endif // _DEBUG


//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆

