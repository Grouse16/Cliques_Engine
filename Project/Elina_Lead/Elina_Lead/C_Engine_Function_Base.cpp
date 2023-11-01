//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：イベント指定用の基底インスタンスの定義
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Engine_Function_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace GAME::FUNCTION;


// ☆ 関数 ☆ //

//==☆ プロテクト ☆==//

//-☆- 更新 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シーン前の更新
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Function_Base::M_Before_Event_Update(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シーン後の更新
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Function_Base::M_After_Event_Update(void)
{
	return;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シーン前の更新の優先度レベルを設定する
// 引数   ：int 設定する優先度
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Function_Base::M_Set_Before_Update_Priority(int in_set_priority)
{
	mpr_variable.before_update_priority = in_set_priority;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シーン後の更新の優先度レベルを設定する
// 引数   ：int 設定する優先度
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Function_Base::M_Set_After_Update_Priority(int in_set_priority)
{
	mpr_variable.after_update_priority = in_set_priority;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シーン前の描画の優先度レベルを設定する
// 引数   ：int 設定する優先度
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Function_Base::M_Set_Before_Draw_Priority(int in_set_priority)
{
	mpr_variable.before_draw_priority = in_set_priority;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シーン後の描画の優先度レベルを設定する
// 引数   ：int 設定する優先度
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Function_Base::M_Set_After_Draw_Priority(int in_set_priority)
{
	mpr_variable.after_draw_priority = in_set_priority;

	return;
}


//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Engine_Function_Base::C_Engine_Function_Base(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Engine_Function_Base::~C_Engine_Function_Base(void)
{
	return;
}


//-☆- 更新 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シーン後のイベントの更新
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Function_Base::M_Call_Event_Before_Scene_Process(void)
{
	// 待ち時間があるなら呼ばれても待機
	if (mpr_variable.update_period_time > 0.0f)
	{
		return;
	}


	// シーン処理前の更新処理
	M_Before_Event_Update();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シーン後のイベントの更新
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Function_Base::M_Call_Event_After_Scene_Process(void)
{
	// 待ち時間があるなら呼ばれても待機
	if (mpr_variable.update_period_time > 0.0f)
	{
		return;
	}


	// シーン処理後の更新処理
	M_After_Event_Update();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シーン前に行う出力処理
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Function_Base::M_Draw_Before_Scene_Process(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シーン後に行う出力処理
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Function_Base::M_After_Draw_Process(void)
{
	return;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：イベント実行の周期を設定する
// 引数   ：float 設定する次の実行までの待ち時間
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Function_Base::M_Set_Update_Period_Time(float in_set_period)
{
	mpr_variable.update_period_time = in_set_period;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：機能を終了させるかどうかを設定する
// 引数   ：bool 設定する終了するかどうかのフラグ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Function_Base::M_Set_Flg_End_Function(bool in_set_flg_end_function)
{
	mpr_variable.flg_function_end = in_set_flg_end_function;

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シーン前の更新の優先度のレベルを返す
// 引数   ：void
// 戻り値 ：const int & 優先度の値の参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const int & C_Engine_Function_Base::M_Get_Before_Update_Priority(void)
{
	return mpr_variable.before_update_priority;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シーン後の更新の優先度のレベルを返す
// 引数   ：void
// 戻り値 ：const int & 優先度の値の参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const int & C_Engine_Function_Base::M_Get_After_Update_Priority(void)
{
	return mpr_variable.after_update_priority;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シーン前の描画の優先度のレベルを返す
// 引数   ：void
// 戻り値 ：const int & 優先度の値の参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const int & C_Engine_Function_Base::M_Get_Before_Draw_Priority(void)
{
	return mpr_variable.before_draw_priority;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シーン後の描画の優先度のレベルを返す
// 引数   ：void
// 戻り値 ：const int & 優先度の値の参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const int & C_Engine_Function_Base::M_Get_After_Draw_Priority(void)
{
	return mpr_variable.after_draw_priority;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：機能を終了するかどうかのフラグを返す
// 引数   ：void
// 戻り値 ：const bool & 機能を終了するかどうかのフラグの参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const bool & C_Engine_Function_Base::M_Get_Flg_End_Function(void)
{
	return mpr_variable.flg_function_end;
}
