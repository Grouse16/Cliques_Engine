//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーションデータのクラス
// 説明   ：ロード、指定された時間でのマトリクス変換情報を返すなどをする
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Animation_Data_System.h"
#include "C_Text_And_File_Manager.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::ANIMATION::DATA;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Animation_Data_System::C_Animation_Data_System(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Animation_Data_System::~C_Animation_Data_System(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリを解放する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Data_System::M_Release(void)
{
	for (ASSET::ANIMATION::BONE::S_Bone_Key_Inform & now_bone_key : mpr_variable.bone_key_list)
	{
		now_bone_key.position_key_list.clear();
		now_bone_key.position_key_list.shrink_to_fit();

		now_bone_key.rotation_key_list.clear();
		now_bone_key.rotation_key_list.shrink_to_fit();

		now_bone_key.scale_key_list.clear();
		now_bone_key.scale_key_list.shrink_to_fit();
	}

	mpr_variable.bone_key_list.clear();
	mpr_variable.bone_key_list.shrink_to_fit();

	return;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたパスのアニメーションデータをロードする
// 引数   ：string アニメーションデータまでのパス, vector<S_Bone_Inform> & アタッチ先モデルのボーンの情報
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Animation_Data_System::M_Load_Anmation_Data_By_Path(std::string in_animation_data_path, std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & in_bone_inform_list)
{
	// ☆ 変数宣言 ☆ //
	SYSTEM::TEXT::C_Text_And_File_Manager file_data;	// ファイルのデータを読み取るシステム


	// ファイルのロード
	if (file_data.M_Load_Select_File(in_animation_data_path) == false)
	{
		// ロードに成功、デバッグ時は成功ログを表示
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "このアニメーションデータのファイルはありません：" + in_animation_data_path);
#endif // _DEBUG

		return false;
	}

	// 認証名を探索する
	if (file_data.M_Goto_Right_By_Text_In_Front_Row("This-Is-ELANMDT") == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "このファイルは.elanmdt形式ではありません：" + in_animation_data_path);
#endif // _DEBUG

		return false;
	}
	
	// データの開始位置へ移動
	if (file_data.M_Goto_Right_By_Text_In_Front_Row("ANIMATION:"))
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "アニメーションのデータが確認できませんでした：" + in_animation_data_path);
#endif // _DEBUG

		return false;
	}


	// 現在持っているアニメーションデータは削除する
	M_Release();


	// アニメーションするボーン数を取得し、その数分配列を生成
	file_data.M_Goto_Right_By_Text_In_Front_Row("BONESUM:");
	mpr_variable.bone_key_list.resize(file_data.M_Get_Number());

	// 全てのアニメーションするボーンの情報をロードする
	for (ASSET::ANIMATION::BONE::S_Bone_Key_Inform & now_bone_key : mpr_variable.bone_key_list)
	{
		// 次のボーン情報まで移動
		file_data.M_Goto_Right_By_Text_In_Front_Row("BONE:");


		// ボーンのインデックスのロード
		{
			// ☆ 変数宣言 ☆ //
			std::string now_bone_name = file_data.M_Get_Data_Right_In_Row();	// 現在のボーン名


			// ボーン名から操作先のボーンのインデックス番号を取得
			for (int now_bone_index = 0; now_bone_index < in_bone_inform_list.size(); now_bone_index++)
			{
				if (in_bone_inform_list[now_bone_index].bone_name == now_bone_name)
				{
					now_bone_key.bone_index = now_bone_index;
				}
			}
		}


		// 座標のキーフレーム数を取得し、その分配列を生成
		file_data.M_Goto_Right_By_Text_In_Front_Row("POS:");
		now_bone_key.position_key_list.resize(file_data.M_Get_Number());

		// 座標のキーフレームを全てロードする
		for (ASSET::ANIMATION::DATA::S_Key_Frame & now_position_key : now_bone_key.position_key_list)
		{
			// 現在のキーフレーム情報の位置に移動
			file_data.M_Move_Next_Raw();

			// このキーのタイミングを時間で取得
			now_position_key.time_of_frame = file_data.M_Get_Float_Double_Number();

			// キー情報を取得
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_position_key.key_value.x = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_position_key.key_value.y = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_position_key.key_value.z = file_data.M_Get_Float_Double_Number();
		}


		// 回転のキーフレーム数を取得し、その分配列を生成
		file_data.M_Goto_Right_By_Text_In_Front_Row("ROT:");
		now_bone_key.rotation_key_list.resize(file_data.M_Get_Number());

		// 回転のキーフレームを全てロードする
		for (ASSET::ANIMATION::DATA::S_Rotation_Key_Frame & now_rotation_key : now_bone_key.rotation_key_list)
		{
			// 現在のキーフレーム情報の位置に移動
			file_data.M_Move_Next_Raw();

			// このキーのタイミングを時間で取得
			now_rotation_key.time_of_frame = file_data.M_Get_Float_Double_Number();

			// キー情報を取得
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_rotation_key.quaternion.x = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_rotation_key.quaternion.y = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_rotation_key.quaternion.z = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_rotation_key.quaternion.w = file_data.M_Get_Float_Double_Number();
		}


		// スケールのキーフレーム数を取得し、その分配列を生成
		file_data.M_Goto_Right_By_Text_In_Front_Row("SCL:");
		now_bone_key.scale_key_list.resize(file_data.M_Get_Number());

		// スケールのキーフレームを全てロードする
		for (ASSET::ANIMATION::DATA::S_Key_Frame & now_scale_key : now_bone_key.scale_key_list)
		{
			// 現在のキーフレーム情報の位置に移動
			file_data.M_Move_Next_Raw();

			// このキーのタイミングを時間で取得
			now_scale_key.time_of_frame = file_data.M_Get_Float_Double_Number();

			// キー情報を取得
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_scale_key.key_value.x = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_scale_key.key_value.y = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			now_scale_key.key_value.z = file_data.M_Get_Float_Double_Number();
		}
	}


	// ロードに成功、デバッグ時は成功ログを表示
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "アニメーションデータのロードに成功しました：" + in_animation_data_path);
#endif // _DEBUG

	return true;
}


//-☆- キーフレーム -☆-//



