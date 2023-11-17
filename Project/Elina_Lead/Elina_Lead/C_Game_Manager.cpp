//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ゲームのシステム制御用のクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include <algorithm>

#include "C_Game_Manager.h"
#include "C_OS_System_Base.h"
#include "C_Rendering_Graphics_API_Base.h"
#include "C_Game_Function_Manager.h"
#include "C_Game_State_Manager.h"
#include "C_APK_Manager.h"
#include "C_Game_Input_Manager.h"
#include "C_Game_Input_Collision_Manager.h"
#include "C_Game_Time_Manager.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


// ☆ ネームスペースの省略 ☆ //
using namespace GAME;


// ☆ 変数宣言 ☆ //
C_Game_Manager C_Game_Manager::m_this;	// 自クラスへのアクセス用の変数

C_Game_Manager::SPr_Variable C_Game_Manager::mpr_variable;		// 自クラスの変数へのアクセス用の変数


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- 初期化 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ、初期状態の指定とイベントの生成を行う
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Game_Manager::C_Game_Manager(void)
{

	return;
}


//-☆- 更新 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：データの更新を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Manager::M_Data_Update(void)
{
	// ☆ 変数宣言 ☆ //
	const std::wstring & executed_scene_name = GAME::STATE::C_Game_State_Manager::M_Get_Execute_Change_Game_Scene_Name();	// 変更要求のあったシーン名の参照


	// 変更要求がないならスルー
	if (executed_scene_name == GAME::STATE::con_Invalid_Scene_Name)
	{
		return;
	}

	// 変更先が現在と同じなら変更拒否
	if (GAME::STATE::C_Game_State_Manager::M_Get_Now_Game_Scene_Name() == executed_scene_name)
	{
		GAME::STATE::C_Game_State_Manager::M_Set_Execute_Change_Game_Scene_Name(executed_scene_name);

		return;
	}


	// ☆ 変更先シーン名から必要な機能の生成を行う ☆ //

	// タイトルシーン
	if (executed_scene_name == L"TITLE")
	{

	}

	// ゲームシーン
	if (executed_scene_name == L"GAME")
	{

	}

	// 指定されたシーンが存在しない
	else
	{
		// デバッグ時はないことを示す
#ifdef _DEBUG

#endif // _DEBUG
	}


	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ウィンドウタイトルの更新
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Manager::M_Window_Title_Update(void)
{
	// デバッグ時のみ変更
#ifdef _DEBUG
	
	// ☆ 変数宣言 ☆ //
	std::wstring new_title;	// 新しいタイトルの文字列


	new_title = OS::con_DEVICE_NAME + L"    fps : "
		+ 
		std::to_wstring(TIME::C_Game_Time_Manager::M_Get_FPS()) + L"/" + std::to_wstring(TIME::C_Game_Time_Manager::M_Get_Frame_Rate())
		+
		L"　speed:" + std::to_wstring(TIME::C_Game_Time_Manager::M_Get_Delta_Second());
	OS::C_OS_System_Base::M_Get_Instance()->M_Set_Window_Title(new_title);

#endif	// _DEBUG

	return;
}


//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シーンの処理前に行うゲーム側の処理
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Manager::M_Init(void)
{
	// ☆ デバッグ時なら初期化開始を告知 ☆ //
#if _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "-☆-☆-☆-☆-☆-☆-☆- ゲームの初期化を開始 -☆-☆-☆-☆-☆-☆-☆-");
#endif

	// ゲームの共通情報をまとめるシステムを生成する
	GAME::STATE::C_Game_State_Manager::M_Init();

	// ゲームの入力システムを生成する
	GAME::INPUT::COLLISION::C_Game_Input_Collision_Manager::M_Init();
	GAME::INPUT::C_Game_Input_Manager::M_Init();

	// ゲームの時間システムを生成する
	GAME::TIME::C_Game_Time_Manager::M_Init();

	// アプリケーションシステムの初期化を行う
	M_Set_Game_Exist_Flg(GAME::APPLICATION::C_APK_Manager::M_Init());


	// 初期化に失敗したら失敗を告知する
	if (M_Get_Game_Exist_Flg() == false)
	{
		// ☆ デバッグ時なら初期化の失敗を告知 ☆ //
#if _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_RED);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "-☆-☆-☆-☆-☆-☆-☆- ゲームの初期化に失敗 -☆-☆-☆-☆-☆-☆-☆-");
#endif // _DEBUG

		return;
	}


	// ☆ デバッグ時なら初期化の成功を告知 ☆ //
#if _DEBUG
	// 初期化に成功したら成功を告知する
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "-☆-☆-☆-☆-☆-☆-☆- ゲームの初期化に成功 -☆-☆-☆-☆-☆-☆-☆-");
#endif //_DEBUG


	// アクティブ状態を指定
	mpr_variable.flg_game_activate = true;
	M_Set_Game_Exist_Flg(true);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ、使用しているメモリを解放する
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Game_Manager::~C_Game_Manager(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリ解放
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Manager::M_Release(void)
{
	// アプリケーションの終了を示す
	mpr_variable.flg_game_activate = false;
	M_Set_Game_Exist_Flg(false);

	// アプリケーションの解放
	GAME::APPLICATION::C_APK_Manager::M_Release();

	// ゲーム用システムを削除
	GAME::FUNCTION::C_Game_Function_Manager::M_Release_Memory();
	GAME::INPUT::C_Game_Input_Manager::M_Release();
	GAME::INPUT::COLLISION::C_Game_Input_Collision_Manager::M_Release();
	GAME::TIME::C_Game_Time_Manager::M_Release();
	GAME::STATE::C_Game_State_Manager::M_Release();

	return;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ゲームを存在している状態かどうかを設定する
// 引数   ：trueは正常に存在している
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Manager::M_Set_Game_Exist_Flg(bool in_set_exist)
{
	mpr_variable.flg_game_exist = in_set_exist;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ゲームが稼働中かどうかを設定する
// 引数   ：trueは正常に存在している
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Manager::M_Set_Game_Activate_Flg(bool in_set_active)
{
	mpr_variable.flg_game_activate = in_set_active;

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ゲームを存在している状態かどうかを取得する
// 引数   ：trueは正常に存在している
// 戻り値 ：終了時の場合は、true
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Game_Manager::M_Get_Game_Exist_Flg(void)
{
	return mpr_variable.flg_game_exist;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ゲームがアクティブ状態かどうかを返す
// 引数   ：void
// 戻り値 ：アクティブ時の場合は、true
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Game_Manager::M_Get_Game_Active_Flg(void)
{
	return mpr_variable.flg_game_activate;
}


//-☆- 実行 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ゲームの処理を実行する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Manager::M_Executes_Process(void)
{
	//======☆ 実行確認 ☆======//

	// ゲームが存在していないか稼働中でないなら実行しない
	if ((M_Get_Game_Active_Flg() & M_Get_Game_Exist_Flg()) == false)
	{
		return;
	}


	//======☆ スタート ☆======//

	// OSの更新　すでに更新中ならスルー
	if (mpr_variable.flg_OS_active_now == false)
	{
		mpr_variable.flg_OS_active_now = true;
		OS::C_OS_System_Base::M_Get_Instance()->M_Update();

		// OSが終了していたらゲームを終了する
		if (OS::C_OS_System_Base::M_Get_OS_Active() == false)
		{
			M_Set_Game_Exist_Flg(false);

			return;
		}
		mpr_variable.flg_OS_active_now = false;
	}

	// 時間の更新
	GAME::TIME::C_Game_Time_Manager::M_Time_Update();

	// ウィンドウタイトルを更新
	M_Window_Title_Update();



	//======☆ 入力 ☆======//

	// ゲーム制御システムの入力
	GAME::INPUT::C_Game_Input_Manager::M_Update();

	// ゲームの入力
	GAME::APPLICATION::C_APK_Manager::M_APK_Input();



	//======☆ 更新 ☆======//

	// ゲーム更新前の機能の更新
	GAME::FUNCTION::C_Game_Function_Manager::M_Before_Scene_Update();

	// ゲームの更新
	GAME::APPLICATION::C_APK_Manager::M_APK_Update();

	// ゲーム更新後の機能の更新
	GAME::FUNCTION::C_Game_Function_Manager::M_After_Scene_Update();



	//======☆ 描画 ☆======//

	//  レンダリングシステムの描画準備  //
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Rendering_Start();

	// ゲームの描画
	GAME::APPLICATION::C_APK_Manager::M_APK_Draw();

	// ゲーム描画後の機能の更新
	GAME::FUNCTION::C_Game_Function_Manager::M_After_Scene_Draw_Update();


	//  レンダリング終了と画面出力  //
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Rendering_End_And_Swap_Screen();



	//======☆ 次のフレームへの準備 ☆======//

	// 必要のない機能の削除
	GAME::FUNCTION::C_Game_Function_Manager::M_Delete_Function();

	// 必要な機能の生成
	GAME::FUNCTION::C_Game_Function_Manager::M_Execute_Create_Function_By_List();

	// ゲームの共有データの更新
	M_Data_Update();

	// フレームの終了時の更新
	GAME::TIME::C_Game_Time_Manager::M_Frame_End_Update();

	return;
}
