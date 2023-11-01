//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：エンジンの入力を制御するシステム
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include <algorithm>

#include "C_OS_System_Base.h"
#include "C_Engine_Input_Manager.h"

#include "C_Log_System.h"


// ☆ ネームスペースの省略 ☆ //
using namespace GAME::INPUT;


// ☆ スタティック変数 ☆ //
std::unique_ptr<C_Engine_Input_Manager> C_Engine_Input_Manager::m_this;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- 初期化 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Engine_Input_Manager::C_Engine_Input_Manager(void)
{
	// デバッグ時は生成したことをログに残す
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "エンジン用入力システムを生成");
#endif // _DEBUG

	return;
}


//-☆- 更新 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：マウス入力判定の更新
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Input_Manager::M_Update_Mouse_Input(void)
{
	// ☆ 変数宣言 ☆ //
	const OS::S_Mouse_State & now_mouse_state = OS::C_OS_System_Base::M_Get_Instance()->M_Get_Mouse_State();	// 現在のマウスの状態の参照
	

	// マウスの座標を取得
	mpr_variable.mouse.cursor_pixel.x = now_mouse_state.x;
	mpr_variable.mouse.cursor_pixel.y = now_mouse_state.y;

	// ☆ マウスのクリック状態を更新 ☆ //
	switch (now_mouse_state.left_click)
	{
		// 何も入力されていない
	case OS::E_MOUSE_CLICK_STATE::e_NON:

		// クリック系終了時は終了時の座標を記録
		if (mpr_variable.mouse.flg_clicking || mpr_variable.mouse.flg_double_clicking)
		{
			mpr_variable.mouse.end_clicked_pixel = mpr_variable.mouse.cursor_pixel;
		}

		mpr_variable.mouse.flg_clicking = false;
		mpr_variable.mouse.flg_double_clicking = false;
		break;

		// 入力中
	case OS::E_MOUSE_CLICK_STATE::e_CLICK:

		// クリック開始時は開始位置を記録
		if (mpr_variable.mouse.flg_clicking == false)
		{
			mpr_variable.mouse.start_clicked_pixel = mpr_variable.mouse.cursor_pixel;
		}

		mpr_variable.mouse.flg_clicking = true;
		mpr_variable.mouse.flg_double_clicking = false;
		break;

		// ダブルクリック中
	case OS::E_MOUSE_CLICK_STATE::e_DOUBLE_CLICK:
		mpr_variable.mouse.flg_clicking = false;
		mpr_variable.mouse.flg_double_clicking = true;
		break;
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：通常時の入力判定の更新
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Input_Manager::M_Update_Input_Collision_On_Normal_Timing(void)
{
	// ☆ 変数宣言 ☆ //
	std::vector<GAME::INPUT::COLLISION::C_Engine_Input_Collision* > & input_collision_list =	// 入力判定リストへの参照
		GAME::INPUT::COLLISION::C_Engine_Input_Collision_Manager::M_Get_Input_Collision_List();

	bool flg_ones_overed = false;	// 一つの判定と重なったかどうかのフラグ

	// 入力判定の更新
	for (GAME::INPUT::COLLISION::C_Engine_Input_Collision * & input_collision : input_collision_list)
	{
		// 判定がアクティブな状態でないなら飛ばす
		if (input_collision->M_Get_Is_Active() == false)
		{
			continue;
		}

		// もうすでに重なった入力判定があるなら、二つ同時にはとらないので入力されていない状態にする
		if (flg_ones_overed)
		{
			input_collision->M_Change_State_Command_Not_Hit();
		}

		// マウス座標との判定を行い、当たっているなら状態の更新を行う
		else if (input_collision->M_Collision_To_Pixel(mpr_variable.mouse.cursor_pixel.x, mpr_variable.mouse.cursor_pixel.y))
		{
			// クリック中へ遷移し、入力された判定を取得
			if (mpr_variable.mouse.flg_clicking)
			{
				input_collision->M_Change_State_Command_Clicking();

				mpr_variable.mouse.clicking_collision_add = input_collision;
			}

			// ダブルクリック中へ遷移し、入力された判定を取得
			else if (mpr_variable.mouse.flg_double_clicking)
			{
				input_collision->M_Change_State_Command_Double_Clicking();

				mpr_variable.mouse.clicking_collision_add = input_collision;
			}

			// 重なっている時へ遷移する
			else
			{
				input_collision->M_Change_State_Command_Overed();
			}
		}

		// 入力されていない
		else
		{
			input_collision->M_Change_State_Command_Not_Hit();
		}
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：クリック入力後の判定の更新
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Input_Manager::M_Update_Input_Collision_After_Clicked(void)
{
	// ☆ 変数宣言 ☆ //
	std::vector<GAME::INPUT::COLLISION::C_Engine_Input_Collision * > & input_collision_list =	// 入力判定リストへの参照
		GAME::INPUT::COLLISION::C_Engine_Input_Collision_Manager::M_Get_Input_Collision_List();

	bool flg_exist_collision = false;	// まだ当たり判定が存在しているかどうかのフラグ
	bool flg_overed = false;			// 一つでも重なった判定があるかどうか


	// ドラッグ時に重なっている判定の取得は毎回更新するのでここで初期化
	mpr_variable.mouse.drag_overed_add = nullptr;


	// 入力判定の更新
	for (GAME::INPUT::COLLISION::C_Engine_Input_Collision * & input_collision : input_collision_list)
	{
		// クリック中の判定があるならあることを示す
		if (input_collision == mpr_variable.mouse.clicking_collision_add)
		{
			flg_exist_collision = true;


			// ドラッグ中に自身と重なっているなら、重なっていることを示す
			if (input_collision->M_Collision_To_Pixel(mpr_variable.mouse.cursor_pixel.x, mpr_variable.mouse.cursor_pixel.y))
			{
				flg_overed = true;
			}
		}

		// ドラッグ中はどの判定と重なっているかを判定する、もうすでに重なっている判定があるならしない、重なっていたらそのことを示す
		if (mpr_variable.mouse.flg_dragging && !flg_overed && input_collision->M_Collision_To_Pixel(mpr_variable.mouse.cursor_pixel.x, mpr_variable.mouse.cursor_pixel.y))
		{
			flg_overed = true;

			mpr_variable.mouse.drag_overed_add = input_collision;

			input_collision->M_Change_State_Command_Dragging_Over();
		}

		// ドラッグ中でないなら入力されていない状態にする
		else
		{
			input_collision->M_Change_State_Command_Not_Hit();
		}
	}


	// 入力判定がなんらかの理由で削除されているなら入力終了をまつ
	if (flg_exist_collision == false)
	{
		// 入力終了まではここで待機する
		if (mpr_variable.mouse.flg_clicking || mpr_variable.mouse.flg_double_clicking || mpr_variable.mouse.flg_dragging)
		{
			return;
		}

		// 入力が終了したら入力状態を解除して戻る
		mpr_variable.mouse.drag_overed_add->M_Change_State_Command_Not_Hit();
		mpr_variable.mouse.clicking_collision_add = nullptr;
		mpr_variable.mouse.drag_overed_add = nullptr;

		return;
	}


	// ☆ 入力中の処理 ☆ //

	// クリック中はクリックされている状態を指定し続ける
	if (mpr_variable.mouse.flg_clicking)
	{
		mpr_variable.mouse.clicking_collision_add->M_Change_State_Command_Clicking();
	}

	// ダブルクリック中はダブルクリックされている状態を指定し続ける
	else if (mpr_variable.mouse.flg_double_clicking)
	{
		mpr_variable.mouse.clicking_collision_add->M_Change_State_Command_Double_Clicking();
	}

	// ドラッグ中はドラッグ操作をされている状態を指定し続ける
	else if (mpr_variable.mouse.flg_dragging)
	{
		mpr_variable.mouse.clicking_collision_add->M_Change_State_Command_Dragging();
	}

	// 何も操作されなくなったら通常状態に戻る
	else
	{
		mpr_variable.mouse.clicking_collision_add->M_Change_State_Command_Not_Hit();
		mpr_variable.mouse.drag_overed_add->M_Change_State_Command_Not_Hit();

		mpr_variable.mouse.clicking_collision_add = nullptr;
		mpr_variable.mouse.drag_overed_add = nullptr;
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：入力判定の更新
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Input_Manager::M_Update_Input_Collision(void)
{
	// クリック入力がされていない状態なら通常通りの入力判定をする
	if (mpr_variable.mouse.clicking_collision_add == nullptr)
	{
		M_Update_Input_Collision_On_Normal_Timing();
	}

	// クリック入力がすでにあるならクリック入力中の判定を行う
	else
	{
		M_Update_Input_Collision_After_Clicked();
	}

	return;
}


//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：入力用システムを生成する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Input_Manager::M_Init(void)
{
	m_this.reset(new C_Engine_Input_Manager);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Engine_Input_Manager::~C_Engine_Input_Manager(void)
{	
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリを解放する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Input_Manager::M_Release(void)
{
	m_this.reset();

	return;
}


//-☆- 更新 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：入力の更新
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Input_Manager::M_Update(void)
{
	// マウスの判定を行う
	m_this->M_Update_Mouse_Input();

	// 入力判定の更新を行う
	m_this->M_Update_Input_Collision();

	return;
}

