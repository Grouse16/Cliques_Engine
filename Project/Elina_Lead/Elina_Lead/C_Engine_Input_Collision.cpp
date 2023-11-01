//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：エンジンの入力判定をとる当たり判定
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Engine_Input_Collision_Manager.h"


// ☆ ネームスペースの省略 ☆ //
using namespace GAME::INPUT::COLLISION;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//


//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Engine_Input_Collision::C_Engine_Input_Collision(void)
{
	C_Engine_Input_Collision_Manager::M_Add_Input_Box_Address_To_List(this);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Engine_Input_Collision::~C_Engine_Input_Collision(void)
{
	C_Engine_Input_Collision_Manager::M_Delete_Input_Box_Address_From_List(this);

	return;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ボックスの名前をセットする
// 引数   ：wstring 設定するボックス名
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Input_Collision::M_Set_Box_Name(std::wstring in_set_name)
{
	mpr_variable.collision_name = in_set_name;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：当たり判定を有効にするかどうかをセットする
// 引数   ：bool trueでアクティブにする
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Input_Collision::M_Set_Is_Active(bool in_set_active_state)
{
	mpr_variable.is_active = in_set_active_state;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：当たり判定の優先度をセットする
// 引数   ：int 設定する優先度
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Input_Collision::M_Set_Priority(int in_set_priority)
{
	mpr_variable.priority = in_set_priority;

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：当たり判定の名前を取得する
// 引数   ：const wstring & 現在の当たり判定の名前の変数の参照(const)
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const std::wstring & C_Engine_Input_Collision::M_Get_Collision_Name(void) const
{
	return mpr_variable.collision_name;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：当たり判定を有効にするかどうかを取得する
// 引数   ：void
// 戻り値 ：bool trueならアクティブ
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Engine_Input_Collision::M_Get_Is_Active(void) const
{
	return mpr_variable.is_active;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在の当たり判定の優先度を返す
// 引数   ：void
// 戻り値 ：int 当たり判定の優先度
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
int C_Engine_Input_Collision::M_Get_Priority(void) const
{
	return mpr_variable.priority;
}


//-☆- 状態の遷移 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：何もされていない状態へ遷移
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Input_Collision::M_Change_State_Command_Not_Hit(void)
{
	//  前回の入力判定の状態によって分岐  //
	switch (mpr_variable.collision_state)
	{
	// クリック入力中なら、入力終了をする
	case E_Engine_Input_Collision_State::e_CLICK_START:
	case E_Engine_Input_Collision_State::e_CLICK_DOING:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_CLICK_END;
		break;

	// ダブルクリック中なら、入力終了をする
	case E_Engine_Input_Collision_State::e_DOUBLE_CLICK_START:
	case E_Engine_Input_Collision_State::e_DOUBLE_CLICK_DOING:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_DOUBLE_CLICK_END;
		break;

	// ドラッグ入力中は、ドラッグ入力を終了する
	case E_Engine_Input_Collision_State::e_DRAG_START:
	case E_Engine_Input_Collision_State::e_DRAG_DOING:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_DRAG_END;
		break;

	// 重なっている時か、通常状態に戻るときは、通常状態に戻す
	default:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_NOT_HIT;
		break;
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：カーソルが重なっている状態へ遷移
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Input_Collision::M_Change_State_Command_Overed(void)
{
	//  前回の入力判定の状態によって分岐  //
	switch (mpr_variable.collision_state)
	{
		// クリック入力中なら、入力終了をする
	case E_Engine_Input_Collision_State::e_CLICK_START:
	case E_Engine_Input_Collision_State::e_CLICK_DOING:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_CLICK_END;
		break;

		// ダブルクリック中なら、入力終了をする
	case E_Engine_Input_Collision_State::e_DOUBLE_CLICK_START:
	case E_Engine_Input_Collision_State::e_DOUBLE_CLICK_DOING:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_DOUBLE_CLICK_END;
		break;

		// ドラッグ入力中は、ドラッグ入力を終了する
	case E_Engine_Input_Collision_State::e_DRAG_START:
	case E_Engine_Input_Collision_State::e_DRAG_DOING:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_DRAG_END;
		break;

		// 通常状態か、通常状態に戻る状態なら重なっている状態になる
	default:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_OVERED;
		break;
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：クリック中の状態へ遷移
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Input_Collision::M_Change_State_Command_Clicking(void)
{
	//  前回の入力判定の状態によって分岐  //
	switch (mpr_variable.collision_state)
	{
		// クリック入力されていない状態ならクリック入力を始める
	default:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_CLICK_START;
		break;

		// クリック入力開始じならクリック入力を続行
	case E_Engine_Input_Collision_State::e_CLICK_START:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_CLICK_DOING;
		break;

		// クリック入力中は何もしない(default用)
	case E_Engine_Input_Collision_State::e_CLICK_DOING:
		break;
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ダブルクリック中の状態へ遷移
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Input_Collision::M_Change_State_Command_Double_Clicking(void)
{
	//  前回の入力判定の状態によって分岐  //
	switch (mpr_variable.collision_state)
	{
		// ダブルクリック入力されていない状態ならダブルクリック入力を始める
	default:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_DOUBLE_CLICK_START;
		break;

		// ダブルクリック入力開始時ならダブルクリック入力を続行
	case E_Engine_Input_Collision_State::e_DOUBLE_CLICK_START:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_DOUBLE_CLICK_DOING;
		break;

		// ダブルクリック入力中は何もしない(default用)
	case E_Engine_Input_Collision_State::e_DOUBLE_CLICK_DOING:
		break;
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ドラッグ中の状態へ遷移
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Input_Collision::M_Change_State_Command_Dragging(void)
{
	//  前回の入力判定の状態によって分岐  //
	switch (mpr_variable.collision_state)
	{
		// ドラッグ入力されていない状態ならドラッグ入力を始める
	default:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_DRAG_START;
		break;

		// ドラッグ入力開始時ならドラッグ入力を続行
	case E_Engine_Input_Collision_State::e_DRAG_START:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_DRAG_DOING;
		break;

		// ドラッグ入力中は何もしない(default用)
	case E_Engine_Input_Collision_State::e_DRAG_DOING:
		break;
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ドラッグ中にカーソルが重なっている状態へ遷移
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Input_Collision::M_Change_State_Command_Dragging_Over(void)
{
	//  前回の入力判定の状態によって分岐  //
	switch (mpr_variable.collision_state)
	{
		// ドラッグ入力にかさなっていない状態ならドラッグ入力に重なっている状態を指定
	default:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_DRAG_OVERED;
		break;

		// ドラッグ入力に重なっている判定中は何もしない(default用)
	case E_Engine_Input_Collision_State::e_DRAG_OVERED:
		break;
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ドラッグ中に当たり判定の上でドロップされたことを示す
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Input_Collision::M_Change_State_Command_Drag_Dropped(void)
{
	//  前回の入力判定の状態によって分岐  //
	switch (mpr_variable.collision_state)
	{
		// ドロップされた状態でないなら状態ならドロップされた状態を指定
	default:
		mpr_variable.collision_state = E_Engine_Input_Collision_State::e_DRAG_OVER_DROPPED;
		break;

		// ドロップされた状態になっているなら何もしない(default用)
	case E_Engine_Input_Collision_State::e_DRAG_OVER_DROPPED:
		break;
	}

	return;
}


