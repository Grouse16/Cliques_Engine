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
using namespace ASSET::ANIMATION_SYSTEM;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- キーフレームブレンド -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：渡された情報を元にキー値を時間で割り出してを返す
// 引数   ：float 開始のキー値, float 終了のキー値, float 時間のパーセント
// 戻り値 ：float 計算結果のキー値
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
inline float C_Animation_Data_System::M_Key_To_Key_Value_Calculation_By_Time(float in_start_key, float in_end_key, float in_time_percent) const
{
	return (in_end_key - in_start_key) * in_time_percent + in_start_key;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された情報からキーフレームの計算を行い情報をセットする
// 引数   ：float 今の時間, float ブレンド率, const vector<S_Key_Frame> & 設定元のキーフレーム情報, XMFLOAT3 & 設定先のキー値
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
inline void C_Animation_Data_System::M_Blend_Key_Frame(float in_time, float in_blend_percent, const std::vector<ASSET::ANIMATION_SYSTEM::S_Key_Frame> & in_blend_key, DirectX::XMFLOAT3 & out_set_key) const
{
	// ☆ 変数宣言 ☆ //
	DirectX::XMFLOAT3 result_key;	// 結果となるキー値
	
	int key_value_sum = in_blend_key.size();	// キー情報の総数
	int start_key_slot = in_blend_key.size() - 1;	// 始まりのキーのスロット

	bool key_is_end = true;	// 使用するキーが配列内最後の場合はtrue、配列の途中であればfalse


	// 位置のキーのうち指定された時間にあたるキーを探す（見つからなかったら最後の時間以降であるため最後のキーを指定）
	for (int now_key_num = 0; now_key_num < start_key_slot; now_key_num++)
	{
		// 今指定しているキーの時間以上、次のキーの時間以下の場合は、そこを使用するキーとする
		if (in_blend_key[now_key_num].time_of_frame <= in_time && in_blend_key[now_key_num + 1].time_of_frame <= in_time)
		{
			start_key_slot = now_key_num;

			key_is_end = false;

			break;
		}
	}

	// 現在のキーが配列の最後であればそれをそのまま使用する
	if (key_is_end)
	{
		result_key = in_blend_key[start_key_slot].key_value;
	}

	// 現在のキーが配列の途中であれば次のキーフレームまでの時間から現在の位置を割り出す
	else
	{
		// ☆ 変数宣言 ☆ //
		float time_percent = 0.0f;	// 時間の遷移率


		// 現在の時間から、現在のキーと次のキーまでの時間の何パーセント分経過しているかを割り出す
		time_percent = (in_time - in_blend_key[start_key_slot].time_of_frame) / (in_blend_key[start_key_slot + 1].time_of_frame - in_blend_key[start_key_slot].time_of_frame);

		result_key.x =
			M_Key_To_Key_Value_Calculation_By_Time(in_blend_key[start_key_slot].key_value.x, in_blend_key[start_key_slot + 1].key_value.x, time_percent);

		result_key.y =
			M_Key_To_Key_Value_Calculation_By_Time(in_blend_key[start_key_slot].key_value.y, in_blend_key[start_key_slot + 1].key_value.y, time_percent);

		result_key.z =
			M_Key_To_Key_Value_Calculation_By_Time(in_blend_key[start_key_slot].key_value.z, in_blend_key[start_key_slot + 1].key_value.z, time_percent);
	}


	// 結果をブレンド率分ブレンドする
	out_set_key.x = out_set_key.x * (1.0f - in_blend_percent) + result_key.x * in_blend_percent;
	out_set_key.y = out_set_key.y * (1.0f - in_blend_percent) + result_key.y * in_blend_percent;
	out_set_key.z = out_set_key.z * (1.0f - in_blend_percent) + result_key.z * in_blend_percent;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された情報からクォータニオンのキーフレームの計算を行い情報をセットする
// 引数   ：float 今の時間, float ブレンド率, const vector<S_Quaternion_Key_Frame> & 設定元のクォータニオンキーフレーム情報, XMVECTOR & 設定先のキー値
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
inline void C_Animation_Data_System::M_Blend_Quaternion_Key_Frame(float in_time, float in_blend_percent, const std::vector<ASSET::ANIMATION_SYSTEM::S_Quaternion_Key_Frame> & in_quaternion_key, DirectX::XMVECTOR & out_set_quaternion) const
{
	// ☆ 変数宣言 ☆ //
	DirectX::XMVECTOR result_quaternion;	// 結果となるクォータニオン値

	int key_quaternion_sum = in_quaternion_key.size();	// クォータニオンのキー情報の総数
	int start_key_slot = in_quaternion_key.size() - 1;	// 始まりのキーのスロット

	bool key_is_end = true;	// 使用するキーが配列内最後の場合はtrue、配列の途中であればfalse


	// 位置のキーのうち指定された時間にあたるキーを探す（見つからなかったら最後の時間以降であるため最後のキーを指定）
	for (int now_key_num = 0; now_key_num < start_key_slot; now_key_num++)
	{
		// 今指定しているキーの時間以上、次のキーの時間以下の場合は、そこを使用するキーとする
		if (in_quaternion_key[now_key_num].time_of_frame <= in_time && in_quaternion_key[now_key_num + 1].time_of_frame <= in_time)
		{
			start_key_slot = now_key_num;

			key_is_end = false;

			break;
		}
	}

	// 現在のキーが配列の最後であればそれをそのまま使用する
	if (key_is_end)
	{
		result_quaternion = in_quaternion_key[start_key_slot].quaternion.M_Get_Quaternion_Rotation_Vector();
	}

	// 現在のキーが配列の途中であれば次のキーフレームまでの時間から現在の位置を割り出す
	else
	{
		// ☆ 変数宣言 ☆ //
		float time_percent = 0.0f;	// 時間の遷移率


		// 現在の時間から、現在のキーと次のキーまでの時間の何パーセント分経過しているかを割り出す
		time_percent = (in_time - in_quaternion_key[start_key_slot].time_of_frame) / (in_quaternion_key[start_key_slot + 1].time_of_frame - in_quaternion_key[start_key_slot].time_of_frame);

		// 遷移先までのキーのクォータニオンの補間を時間のパーセントから掛ける（球面線形補間）
		result_quaternion = DirectX::XMQuaternionSlerp
		(
			in_quaternion_key[start_key_slot].quaternion.M_Get_Quaternion_Rotation_Vector(),
			in_quaternion_key[start_key_slot + 1].quaternion.M_Get_Quaternion_Rotation_Vector(), 
			time_percent
		);
	}


	// 結果をブレンド率分ブレンドする（球面線形補間でブレンド率分の場所を補間する）
	out_set_quaternion = DirectX::XMQuaternionSlerp(out_set_quaternion, result_quaternion, in_blend_percent);

	return;
}


//-☆- キーフレームセット -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された情報からキーフレームの計算を行い情報をセットする
// 引数   ：float 今の時間, const vector<S_Key_Frame> & 設定元のキーフレーム情報, XMFLOAT3 & 設定先のキー値
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
inline void C_Animation_Data_System::M_Set_Key_Frame(float in_time, const std::vector<ASSET::ANIMATION_SYSTEM::S_Key_Frame> & in_set_key, DirectX::XMFLOAT3 & out_set_key) const
{
	// ☆ 変数宣言 ☆ //
	int key_value_sum = in_set_key.size();	// キー情報の総数
	int start_key_slot = in_set_key.size() - 1;	// 始まりのキーのスロット

	bool key_is_end = true;	// 使用するキーが配列内最後の場合はtrue、配列の途中であればfalse


	// 位置のキーのうち指定された時間にあたるキーを探す（見つからなかったら最後の時間以降であるため最後のキーを指定）
	for (int now_key_num = 0; now_key_num < start_key_slot; now_key_num++)
	{
		// 今指定しているキーの時間以上、次のキーの時間以下の場合は、そこを使用するキーとする
		if (in_set_key[now_key_num].time_of_frame <= in_time && in_set_key[now_key_num + 1].time_of_frame <= in_time)
		{
			start_key_slot = now_key_num;

			key_is_end = false;

			break;
		}
	}

	// 現在のキーが配列の最後であればそれをそのまま使用する
	if (key_is_end)
	{
		out_set_key = in_set_key[start_key_slot].key_value;
	}

	// 現在のキーが配列の途中であれば次のキーフレームまでの時間から現在の位置を割り出す
	else
	{
		// ☆ 変数宣言 ☆ //
		float time_percent = 0.0f;	// 時間の遷移率


		// 現在の時間から、現在のキーと次のキーまでの時間の何パーセント分経過しているかを割り出す
		time_percent = (in_time - in_set_key[start_key_slot].time_of_frame) / (in_set_key[start_key_slot + 1].time_of_frame - in_set_key[start_key_slot].time_of_frame);

		out_set_key.x =
			M_Key_To_Key_Value_Calculation_By_Time(in_set_key[start_key_slot].key_value.x, in_set_key[start_key_slot + 1].key_value.x, time_percent);

		out_set_key.y =
			M_Key_To_Key_Value_Calculation_By_Time(in_set_key[start_key_slot].key_value.y, in_set_key[start_key_slot + 1].key_value.y, time_percent);

		out_set_key.z =
			M_Key_To_Key_Value_Calculation_By_Time(in_set_key[start_key_slot].key_value.z, in_set_key[start_key_slot + 1].key_value.z, time_percent);
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された情報からクォータニオンのキーフレームの計算を行い情報をセットする
// 引数   ：float 今の時間, const vector<S_Key_Frame> & 設定元のクォータニオンキーフレーム情報, XMFLOAT3 & 設定先のキー値
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
inline void C_Animation_Data_System::M_Set_Quaternion_Key_Frame(float in_time, const std::vector<ASSET::ANIMATION_SYSTEM::S_Quaternion_Key_Frame> & in_quaternion_key, DirectX::XMVECTOR & out_set_quaternion) const
{
	// ☆ 変数宣言 ☆ //
	int key_quaternion_sum = in_quaternion_key.size();	// クォータニオンのキー情報の総数
	int start_key_slot = in_quaternion_key.size() - 1;	// 始まりのキーのスロット

	bool key_is_end = true;	// 使用するキーが配列内最後の場合はtrue、配列の途中であればfalse


	// 位置のキーのうち指定された時間にあたるキーを探す（見つからなかったら最後の時間以降であるため最後のキーを指定）
	for (int now_key_num = 0; now_key_num < start_key_slot; now_key_num++)
	{
		// 今指定しているキーの時間以上、次のキーの時間以下の場合は、そこを使用するキーとする
		if (in_quaternion_key[now_key_num].time_of_frame <= in_time && in_quaternion_key[now_key_num + 1].time_of_frame <= in_time)
		{
			start_key_slot = now_key_num;

			key_is_end = false;

			break;
		}
	}

	// 現在のキーが配列の最後であればそれをそのまま使用する
	if (key_is_end)
	{
		out_set_quaternion = in_quaternion_key[start_key_slot].quaternion.M_Get_Quaternion_Rotation_Vector();
	}

	// 現在のキーが配列の途中であれば次のキーフレームまでの時間から現在の位置を割り出す
	else
	{
		// ☆ 変数宣言 ☆ //
		float time_percent = 0.0f;	// 時間の遷移率


		// 現在の時間から、現在のキーと次のキーまでの時間の何パーセント分経過しているかを割り出す
		time_percent = (in_time - in_quaternion_key[start_key_slot].time_of_frame) / (in_quaternion_key[start_key_slot + 1].time_of_frame - in_quaternion_key[start_key_slot].time_of_frame);

		// 遷移先までのキーのクォータニオンの補間を時間のパーセントから掛ける（球面線形補間）
		out_set_quaternion = DirectX::XMQuaternionSlerp
		(
			in_quaternion_key[start_key_slot].quaternion.M_Get_Quaternion_Rotation_Vector(),
			in_quaternion_key[start_key_slot + 1].quaternion.M_Get_Quaternion_Rotation_Vector(),
			time_percent
		);
	}

	return;
}


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
	for (S_Bone_Key_Inform & now_bone_key : mpr_variable.bone_key_list)
	{
		now_bone_key.key.position_key_list.clear();
		now_bone_key.key.position_key_list.shrink_to_fit();

		now_bone_key.key.quaternion_key_list.clear();
		now_bone_key.key.quaternion_key_list.shrink_to_fit();

		now_bone_key.key.scale_key_list.clear();
		now_bone_key.key.scale_key_list.shrink_to_fit();
	}

	mpr_variable.bone_key_list.clear();
	mpr_variable.bone_key_list.shrink_to_fit();

	return;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたパスのアニメーションデータをロードする
// 引数   ：string アニメーションデータまでのパス, vector<C_Bone_Inform> & アタッチ先モデルのボーンの情報
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Animation_Data_System::M_Load_Animation_Data_By_Path(std::string in_animation_data_path, std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & in_bone_inform_list)
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
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return false;
	}


	// 現在持っているアニメーションデータは削除する
	M_Release();


	// アニメーション時間を取得
	file_data.M_Goto_Right_By_Text_In_Front_Row("ENDTIME:");
	mpr_variable.animation_max_time = file_data.M_Get_Float_Double_Number();

	// アニメーションするボーン数を取得し、その数分配列を生成
	file_data.M_Goto_Right_By_Text_In_Front_Row("BONESUM:");
	mpr_variable.bone_key_list.resize(file_data.M_Get_Number());

	// 全てのアニメーションするボーンの情報をロードする
	for (S_Bone_Key_Inform & now_bone_key : mpr_variable.bone_key_list)
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
		now_bone_key.key.position_key_list.resize(file_data.M_Get_Number());

		// 座標のキーフレームを全てロードする
		for (ASSET::ANIMATION_SYSTEM::S_Key_Frame & now_position_key : now_bone_key.key.position_key_list)
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
		now_bone_key.key.quaternion_key_list.resize(file_data.M_Get_Number());

		// 回転のキーフレームを全てロードする
		for (ASSET::ANIMATION_SYSTEM::S_Quaternion_Key_Frame & now_rotation_key : now_bone_key.key.quaternion_key_list)
		{
			// ☆ 変数宣言 ☆ //
			DirectX::XMFLOAT4 set_rotation_value;	// 回転の設定値


			// 現在のキーフレーム情報の位置に移動
			file_data.M_Move_Next_Raw();

			// このキーのタイミングを時間で取得
			now_rotation_key.time_of_frame = file_data.M_Get_Float_Double_Number();

			// キー情報を取得
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			set_rotation_value.x = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			set_rotation_value.y = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			set_rotation_value.z = file_data.M_Get_Float_Double_Number();
			file_data.M_Goto_Right_By_Text_In_Front_Row(",");
			set_rotation_value.w = file_data.M_Get_Float_Double_Number();

			// クォータニオンにセット
			now_rotation_key.quaternion.M_Set_Quaternion(DirectX::XMVectorSet(set_rotation_value.x, set_rotation_value.y, set_rotation_value.z, set_rotation_value.w));
		}


		// スケールのキーフレーム数を取得し、その分配列を生成
		file_data.M_Goto_Right_By_Text_In_Front_Row("SCL:");
		now_bone_key.key.scale_key_list.resize(file_data.M_Get_Number());

		// スケールのキーフレームを全てロードする
		for (ASSET::ANIMATION_SYSTEM::S_Key_Frame & now_scale_key : now_bone_key.key.scale_key_list)
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


//-☆- キーフレームブレンド -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された時間とキーのブレンド率からそれぞれのボーンのキー情報を生成し、設定先へブレンドする
// 引数   ：float 時間, float ブレンド率, vector<C_Bone_Data> & 設定先のボーンキーのボーンごとの配列の参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Data_System::M_Blend_Bone_Key(float in_time, float in_key_blend_percent, std::vector<ASSET::ANIMATION::BONE::C_Bone_Data> & out_set_bone_key_list) const
{
	// アニメーションの影響を受けるボーンのみブレンドする
	for (const S_Bone_Key_Inform & now_bone_key : mpr_variable.bone_key_list)
	{
		// ☆ 位置のブレンド ☆ //
		M_Blend_Key_Frame(in_time, in_key_blend_percent, now_bone_key.key.position_key_list, out_set_bone_key_list[now_bone_key.bone_index].position);

		// ☆ スケールのブレンド ☆ //
		M_Blend_Key_Frame(in_time, in_key_blend_percent, now_bone_key.key.scale_key_list, out_set_bone_key_list[now_bone_key.bone_index].scale);

		// ☆ クォータニオンのブレンド ☆ //
		M_Blend_Quaternion_Key_Frame(in_time, in_key_blend_percent, now_bone_key.key.quaternion_key_list, out_set_bone_key_list[now_bone_key.bone_index].quaternion);
	}

	return;
}


//-☆- キーフレームセット -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された時間からそれぞれのボーンのキー情報を生成し、設定先へセットする
// 引数   ：float 時間, vector<C_Bone_Data> & 設定先のボーンキーのボーンごとの配列の参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Data_System::M_Set_Bone_Key(float in_time, std::vector<ASSET::ANIMATION::BONE::C_Bone_Data> & out_set_bone_list) const
{
	// アニメーションの影響を受けるボーンのみセットする
	for (const S_Bone_Key_Inform & now_bone_key : mpr_variable.bone_key_list)
	{
		// ☆ 位置のブレンド ☆ //
		M_Set_Key_Frame(in_time, now_bone_key.key.position_key_list, out_set_bone_list[now_bone_key.bone_index].position);

		// ☆ スケールのブレンド ☆ //
		M_Set_Key_Frame(in_time, now_bone_key.key.scale_key_list, out_set_bone_list[now_bone_key.bone_index].scale);

		// ☆ クォータニオンのブレンド ☆ //
		M_Set_Quaternion_Key_Frame(in_time, now_bone_key.key.quaternion_key_list, out_set_bone_list[now_bone_key.bone_index].quaternion);
	}

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーション開始から終了までの時間
// 引数   ：void
// 戻り値 ：int アニメーション開始から終了までの時間
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
int C_Animation_Data_System::M_Get_Animation_Time(void) const
{
	return mpr_variable.animation_max_time;
}


