//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ゲームの入力を制御するシステム
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Game_Time_Manager.h"
#include "C_OS_User_System.h"

#include "C_Log_System.h"


// ☆ ネームスペースの省略 ☆ //
using namespace GAME::TIME;


// ☆ スタティック変数 ☆ //
std::unique_ptr<C_Game_Time_Manager> C_Game_Time_Manager::m_this;	// インスタンス化するための実体（シングルトン用）


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- 初期化 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Game_Time_Manager::C_Game_Time_Manager(void)
{
	// ゲーム用の時間システムの生成を告知
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "ゲーム用の時間システムを生成");

	// 初期時間を記録
	mpr_variable.now_timer = OS::C_OS_User_System::M_Get_Now_Time_Millisecond_By_Start_Application();
	mpr_variable.time_of_seconds_start = mpr_variable.now_timer;
	mpr_variable.then_timer = mpr_variable.now_timer;

	return;
}


//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：時間用システムを生成する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Time_Manager::M_Init(void)
{
	m_this.reset(new C_Game_Time_Manager);
	M_Set_Frame_Rate(m_this->mpr_variable.frame_rate);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Game_Time_Manager::~C_Game_Time_Manager(void)
{
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "ゲーム用の時間システムを削除");

	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリを解放する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Time_Manager::M_Release(void)
{
	m_this.reset();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ： タイムラインをリセットする
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Time_Manager::M_Reset_Time_Line(void)
{
	m_this->mpr_variable.time_line_list.clear();
	m_this->mpr_variable.time_line_list.shrink_to_fit();

	return;
}


//-☆- 更新 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：時間の更新
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Time_Manager::M_Time_Update(void)
{
	// 最新の時間を取得する
	m_this->mpr_variable.now_timer = OS::C_OS_User_System::M_Get_Now_Time_Millisecond_By_Start_Application();


	//経過時間を更新
	m_this->mpr_variable.delta_second = ((float)(m_this->mpr_variable.now_timer - m_this->mpr_variable.then_timer)) / 1000.0f;
	m_this->mpr_variable.delta_second =
		(m_this->mpr_variable.delta_second >= m_this->mpr_variable.delta_second_limit) * m_this->mpr_variable.delta_second_limit
		+
		(m_this->mpr_variable.delta_second < m_this->mpr_variable.delta_second_limit) * m_this->mpr_variable.delta_second;

	// ゲームの経過時間を計測する
	m_this->mpr_variable.game_delta_second = m_this->mpr_variable.delta_second * m_this->mpr_variable.game_speed;

	// フレーム情報を更新
	m_this->mpr_variable.now_frame += 1;


	// それぞれの時間の流れの経過を設定
	for (S_Time_Line & now_time_line : m_this->mpr_variable.time_line_list)
	{
		now_time_line.delta_second = now_time_line.time_speed * m_this->mpr_variable.delta_second;
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：フレームの終了時に行う更新
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Time_Manager::M_Frame_End_Update(void)
{
	// １フレーム経過時の情報更新
	m_this->mpr_variable.need_spend_time = ((float)m_this->mpr_variable.time_of_seconds_start / 1000.0f) + m_this->mpr_variable.one_frame_time * m_this->mpr_variable.now_frame;
	m_this->mpr_variable.then_timer = m_this->mpr_variable.now_timer;


	// フレームレートを保つための時間が経過するまで待機する
	if (m_this->mpr_variable.flg_constant_frame)
	{
		while (M_Get_FPS_Request_Time_Passed() == false)
		{
			m_this->mpr_variable.now_timer = OS::C_OS_User_System::M_Get_Now_Time_Millisecond_By_Start_Application();
		}
	}

	// 一秒間以上経過したらフレームレート情報を更新
	if (m_this->mpr_variable.now_timer - m_this->mpr_variable.time_of_seconds_start >= 1000)
	{
		m_this->mpr_variable.time_of_seconds_start = m_this->mpr_variable.now_timer;
		m_this->mpr_variable.fps = m_this->mpr_variable.now_frame;
		m_this->mpr_variable.now_frame = 0;
	}


	// タイムラインを削除する要求が来ている場合は削除を行う
	if (m_this->mpr_variable.time_line_list.size() > 0)
	{
		m_this->mpr_variable.time_line_list.erase
		(
			std::remove_if
			(
				m_this->mpr_variable.time_line_list.begin(),
				m_this->mpr_variable.time_line_list.end(),

				// タイムライン名が一致するものを削除するラムダ
				[](S_Time_Line & in_time_line)
				{
					for (std::string now_delete_name : m_this->mpr_variable.delete_time_line_list)
					{
						if (in_time_line.time_name == now_delete_name)
						{
							return true;
						}
					}

					return false;
				}
			)
		);
	}

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：FPSを維持するための時間が経過しているかどうかを返す
// 引数   ：void
// 戻り値 ：bool trueなら経過している
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Game_Time_Manager::M_Get_FPS_Request_Time_Passed(void)
{
	return ((float)m_this->mpr_variable.now_timer / 1000.0f) >= m_this->mpr_variable.need_spend_time;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在の規定フレームレートを返す
// 引数   ：void
// 戻り値 ：int 規定フレームレート
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
int C_Game_Time_Manager::M_Get_Frame_Rate(void)
{
	return m_this->mpr_variable.frame_rate;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在のfpsを返す
// 引数   ：void
// 戻り値 ：int 現在のfps（一秒間のフレーム数）
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
int C_Game_Time_Manager::M_Get_FPS(void)
{
	return m_this->mpr_variable.fps;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在の経過時間を返す
// 引数   ：void
// 戻り値 ：float 現在の経過時間
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
float C_Game_Time_Manager::M_Get_Delta_Second(void)
{
	return m_this->mpr_variable.delta_second;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ゲーム内での経過時間を返す
// 引数   ：void
// 戻り値 ：float ゲームでの経過時間
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
float C_Game_Time_Manager::M_Get_Game_Second(void)
{
	return m_this->mpr_variable.game_delta_second;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ゲーム内時間のスピードを返す
// 引数   ：void
// 戻り値 ：float ゲーム内時間のスピード
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
float C_Game_Time_Manager::M_Get_Game_Speed(void)
{
	return m_this->mpr_variable.game_speed;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のタイムラインの経過時間を返す
// 引数   ：string 取得するタイムライン名
// 戻り値 ：float そのタイムラインでの経過スピード
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
float C_Game_Time_Manager::M_Get_Time_Line_Delta_Second(std::string in_time_line_name)
{
	// 一致する名前があれば経過時間を返す
	for (S_Time_Line & now_time_line : m_this->mpr_variable.time_line_list)
	{
		if (now_time_line.time_name == in_time_line_name)
		{
			return now_time_line.delta_second;
		}
	}

	// なければゲーム時間を返す
	return m_this->mpr_variable.game_delta_second;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：フレームレートをセットする
// 引数   ：int 設定するフレームレート
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Time_Manager::M_Set_Frame_Rate(int in_set_frame_rate)
{
	// ☆ 定数 ☆ //
	constexpr float con_LIMIT_BASE_OF_FRAME_COUNT = 10.0f;	// 経過時間の最大値を何フレーム時間分とするか


	m_this->mpr_variable.frame_rate = in_set_frame_rate;
	m_this->mpr_variable.one_frame_time = (1.0f / (float)m_this->mpr_variable.frame_rate);
	m_this->mpr_variable.delta_second_limit = con_LIMIT_BASE_OF_FRAME_COUNT * m_this->mpr_variable.one_frame_time;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ゲーム内時間のスピードをセットする
// 引数   ：float セットするゲーム内時間のスピード
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Time_Manager::M_Set_Game_Speed(float in_set_game_speed)
{
	m_this->mpr_variable.game_speed = in_set_game_speed;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のタイムラインに指定されたスピードをセットする
// 引数   ：string 設定先のタイムライン名, float 設定する時間の流れのスピード
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Time_Manager::M_Set_Time_Line_Speed(std::string in_time_line_name, float in_time_line_speed)
{
	// タイムライン名が一致するものがあれば、時間の流れのスピードをセットする
	for (S_Time_Line & now_time_line : m_this->mpr_variable.time_line_list)
	{
		if (now_time_line.time_name == in_time_line_name)
		{
			now_time_line.delta_second = in_time_line_speed;
		}
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：タイムライン（時間の流れ）を生成する
// 引数   ：string 生成する時間の流れの名前, float 時間の流れの初期スピード
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Time_Manager::M_Create_New_Time_Line(std::string in_set_time_line_name, float in_set_speed)
{
	// すでに使用されている名前ならスルー
	for (S_Time_Line & now_time_line : m_this->mpr_variable.time_line_list)
	{
		if (now_time_line.time_name == in_set_time_line_name)
		{
			return;
		}
	}


	// ☆ 変数宣言 ☆ //
	int new_time_line_number = (int)m_this->mpr_variable.time_line_list.size();	// 新しいタイムラインの番号


	// 新しいタイムラインを生成し、名前とスピードを設定し、経過時間を登録する
	m_this->mpr_variable.time_line_list.resize(new_time_line_number + 1);
	m_this->mpr_variable.time_line_list[new_time_line_number].time_name = in_set_time_line_name;
	m_this->mpr_variable.time_line_list[new_time_line_number].time_speed = in_set_speed;
	m_this->mpr_variable.time_line_list[new_time_line_number].delta_second = m_this->mpr_variable.game_delta_second * in_set_speed;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のタイムラインを削除する
// 引数   ：string 削除するタイムライン名
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Time_Manager::M_Delete_Time_Line_By_Name(std::string in_delete_time_line_name)
{
	// ☆ 変数宣言 ☆ //
	int set_delete_name_slot = (int)m_this->mpr_variable.delete_time_line_list.size();	// 設定先のタイムライン番号


	m_this->mpr_variable.delete_time_line_list.resize(set_delete_name_slot + 1);
	m_this->mpr_variable.delete_time_line_list[set_delete_name_slot + 1] = in_delete_time_line_name;

	return;
}



