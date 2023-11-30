//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ゲームの機能を制御するクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include <algorithm>

#include "C_Game_Function_Manager.h"
#include "Game_Function_Include_List.h"


// ☆ デバッグ時なら初期化の成功および失敗を告知 ☆ //
#if _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG



// ☆ ネームスペースの省略 ☆ //
using namespace GAME::FUNCTION;


// ☆ 変数宣言 ☆ //

// プライベート変数をまとめた構造体
C_Game_Function_Manager::SPR_Variable C_Game_Function_Manager::mpr_variable;	// プライベート変数を呼び出すための名前

C_Game_Function_Manager C_Game_Function_Manager::m_this;	// 自身を呼び出すための名前


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- 初期化 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Game_Function_Manager::C_Game_Function_Manager(void)
{
	return;
}


//-☆- 機能 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：機能の生成を行う
// 引数   ：string 生成する機能の種類
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Function_Manager::M_Create_Function_By_Kind(std::string in_create_kind)
{
	// ☆ 変数宣言 ☆ //
	GAME::FUNCTION::C_Game_Function_Base * new_function_address = nullptr;	// 新しい機能のアドレス
	

	// ☆ 指定された種類によって生成内容を分岐 ☆ //

	// まだない
	if (in_create_kind == "non")
	{

	}

	// 名前がみつからなかったらエラー
	else
	{
		// ☆ デバッグ時なら生成できなかったことを告知 ☆ //
#if _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_CREATE_FUNCTION, "機能の生成に失敗　指定されたタイプ：＜" + in_create_kind + "＞　は見つかりませんでした。未定義の機能、およびスペルミスの可能性があります。");
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return;
	}


	// 処理順のリストに新しく生成された機能を追加
	M_Set_Before_Update_Func_To_List(new_function_address);
	M_Set_After_Update_Func_To_List(new_function_address);
	M_Set_After_Draw_Func_To_List(new_function_address);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シーン処理前に更新する機能を追加
// 引数   ：C_Game_Function_Base * 追加する機能のアドレス
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Function_Manager::M_Set_Before_Update_Func_To_List(GAME::FUNCTION::C_Game_Function_Base * in_add_function)
{
	// シーン前の更新を行わないなら追加しない
	if (in_add_function->M_Get_Before_Update_Priority() < 0)
	{
		return;
	}


	// 配列に生成された直近の機能を追加
	mpr_variable.before_func_update_list.reserve(mpr_variable.before_func_update_list.size() + 1);
	mpr_variable.before_func_update_list.emplace_back(in_add_function);


	// 優先度を元に降順にソートする
	std::sort
	(
		mpr_variable.before_func_update_list.begin(),	// ソートの開始
		mpr_variable.before_func_update_list.end(),		// ソートのおわり

		// ラムダ式、右の要素が左の要素よりも値が大きければ、順番を入れ替える
		[](GAME::FUNCTION::C_Game_Function_Base * & l_vec, GAME::FUNCTION::C_Game_Function_Base * & r_vec)
		{
			return l_vec->M_Get_Before_Update_Priority() >= r_vec->M_Get_Before_Update_Priority();
		}
	);

	return;
}

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シーン処理後に更新する機能を追加
// 引数   ：C_Game_Function_Base * 追加する機能のアドレス
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Function_Manager::M_Set_After_Update_Func_To_List(GAME::FUNCTION::C_Game_Function_Base * in_add_function)
{
	// シーン後の更新を行わないなら追加しない
	if (in_add_function->M_Get_After_Update_Priority() < 0)
	{
		return;
	}


	// 配列に生成された直近の機能を追加
	mpr_variable.after_func_update_list.reserve(mpr_variable.after_func_update_list.size() + 1);
	mpr_variable.after_func_update_list.emplace_back(in_add_function);


	// 優先度を元に降順にソートする
	std::sort
	(
		mpr_variable.after_func_update_list.begin(),	// ソートの開始
		mpr_variable.after_func_update_list.end(),		// ソートのおわり

		// ラムダ式、右の要素が左の要素よりも値が大きければ、順番を入れ替える
		[](GAME::FUNCTION::C_Game_Function_Base * & left_function, GAME::FUNCTION::C_Game_Function_Base * & right_function)
		{
			return left_function->M_Get_Before_Update_Priority() >= right_function->M_Get_Before_Update_Priority();
		}
	);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シーン後に描画する機能を追加する
// 引数   ：C_Game_Function_Base * 追加する機能のアドレス
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Function_Manager::M_Set_After_Draw_Func_To_List(GAME::FUNCTION::C_Game_Function_Base * in_add_function)
{
	// シーン後の更新を行わないなら追加しない
	if (in_add_function->M_Get_After_Draw_Priority() < 0)
	{
		return;
	}


	// 配列に生成された直近の機能を追加
	mpr_variable.after_func_draw_list.reserve(mpr_variable.after_func_draw_list.size() + 1);
	mpr_variable.after_func_draw_list.emplace_back(in_add_function);


	// 優先度を元に昇順にソートする
	std::sort
	(
		mpr_variable.after_func_draw_list.begin(),	// ソートの開始
		mpr_variable.after_func_draw_list.end(),	// ソートのおわり

		// ラムダ式、左の要素が右の要素よりも値が大きければ、順番を入れ替える
		[](GAME::FUNCTION::C_Game_Function_Base * & left_function, GAME::FUNCTION::C_Game_Function_Base * & right_function)
		{
			return left_function->M_Get_After_Draw_Priority() <= right_function->M_Get_After_Draw_Priority();
		}
	);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたアドレスの機能をすべての登録から削除する
// 引数   ：C_Game_Function_Base * 削除する機能のアドレス
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Function_Manager::M_Erase_This_Function_On_All_List(GAME::FUNCTION::C_Game_Function_Base * in_delete_function)
{
	// ☆ ラムダ式 ☆ //

	// ベクターから機能削除用の判定を行うラムダ式
	auto delete_lambda = [] (GAME::FUNCTION::C_Game_Function_Base * & in_function)
	{
		return in_function->M_Get_Flg_End_Function();
	};


	// 機能をそれぞれのリストから削除する
	mpr_variable.before_func_update_list.erase(std::remove_if(mpr_variable.function_list.begin(), mpr_variable.function_list.end(), delete_lambda), mpr_variable.function_list.end());
	mpr_variable.before_func_update_list.shrink_to_fit();
	mpr_variable.after_func_update_list.erase(std::remove_if(mpr_variable.function_list.begin(), mpr_variable.function_list.end(), delete_lambda), mpr_variable.function_list.end());
	mpr_variable.after_func_draw_list.shrink_to_fit();
	mpr_variable.before_func_draw_list.erase(std::remove_if(mpr_variable.function_list.begin(), mpr_variable.function_list.end(), delete_lambda), mpr_variable.function_list.end());
	mpr_variable.before_func_draw_list.shrink_to_fit();
	mpr_variable.after_func_draw_list.erase(std::remove_if(mpr_variable.function_list.begin(), mpr_variable.function_list.end(), delete_lambda), mpr_variable.function_list.end());
	mpr_variable.after_func_draw_list.shrink_to_fit();

	return;
}


//==☆ パブリック ☆==//

//-☆- 終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Game_Function_Manager::~C_Game_Function_Manager(void)
{
	M_Release_Memory();

	return;
}

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリ解放
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Function_Manager::M_Release_Memory(void)
{
	// 機能の処理指定用のリストのメモリを解放する
	mpr_variable.before_func_update_list.clear();
	mpr_variable.before_func_update_list.shrink_to_fit();
	mpr_variable.after_func_update_list.clear();
	mpr_variable.after_func_update_list.shrink_to_fit();
	mpr_variable.before_func_draw_list.clear();
	mpr_variable.before_func_draw_list.shrink_to_fit();
	mpr_variable.after_func_draw_list.clear();
	mpr_variable.after_func_draw_list.shrink_to_fit();


	// 機能のリストのメモリを解放する
	for (GAME::FUNCTION::C_Game_Function_Base * & now_func : mpr_variable.function_list)
	{
		if (now_func != nullptr)
		{
			delete[] now_func;
			now_func = nullptr;
		}
	}


	mpr_variable.function_list.clear();
	mpr_variable.function_list.shrink_to_fit();


	// 機能生成命令を初期化する
	mpr_variable.function_create_kind_list.clear();
	mpr_variable.function_create_kind_list.shrink_to_fit();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シーン処理前の機能の更新を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Function_Manager::M_Before_Scene_Update(void)
{
	for (GAME::FUNCTION::C_Game_Function_Base * & now_function : mpr_variable.before_func_update_list)
	{
		now_function->M_Call_Event_Before_Scene_Process();
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シーン処理後の機能の更新を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Function_Manager::M_After_Scene_Update(void)
{
	for (GAME::FUNCTION::C_Game_Function_Base * & now_function : mpr_variable.after_func_update_list)
	{
		now_function->M_Call_Event_After_Scene_Process();
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シーン処理後の機能の描画を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Function_Manager::M_After_Scene_Draw_Update(void)
{
	for (GAME::FUNCTION::C_Game_Function_Base * & now_function : mpr_variable.after_func_draw_list)
	{
		now_function->M_After_Draw_Process();
	}

	return;
}


//-☆- 機能 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：削除のフラグがたった機能を消す
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Function_Manager::M_Delete_Function(void)
{
	// 削除のフラグがたっている要素を消す
	for (GAME::FUNCTION::C_Game_Function_Base * & now_function : mpr_variable.function_list)
	{
		if (now_function != nullptr)
		{
			if (now_function->M_Get_Flg_End_Function() == true)
			{
				M_Erase_This_Function_On_All_List(now_function);

				delete[] now_function;
				now_function = nullptr;
			}
		}
	}

	// 解放された配列を削除
	mpr_variable.function_list.erase(std::remove(mpr_variable.function_list.begin(), mpr_variable.function_list.end(), nullptr), mpr_variable.function_list.end());
	mpr_variable.function_list.shrink_to_fit();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：生成する要求のあった機能を全て生成する
// 引数   ：void
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Game_Function_Manager::M_Execute_Create_Function_By_List(void)
{
	// 生成する機能がなければ何もしない
	if (mpr_variable.function_create_kind_list.size() <= 0)
	{
		return true;
	}


	// 生成要求のあった機能を全て生成
	for (std::string & create_kind : mpr_variable.function_create_kind_list)
	{
		M_Create_Function_By_Kind(create_kind);
	}


	// 完了した生成要求を削除
	mpr_variable.function_create_kind_list.clear();
	mpr_variable.function_create_kind_list.shrink_to_fit();

	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：機能の生成を要求する
// 引数   ：string 生成する機能の種類
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Game_Function_Manager::M_Command_Create_Function(std::string in_creat_kind)
{
	mpr_variable.function_create_kind_list.reserve(mpr_variable.function_create_kind_list.size() + 1);
	mpr_variable.function_create_kind_list.emplace_back(in_creat_kind);

	return;
}

