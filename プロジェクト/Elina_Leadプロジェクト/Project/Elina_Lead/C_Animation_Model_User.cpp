//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーションモデルを使用するためのシステム
// 説明   ：アニメーションモデルマネージャーとの操作を隠蔽し、簡単に使用できるようにカプセル化する　アニメーションの実行を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Animation_Model_User.h"
#include "C_Animation_Model_Manager.h"

#include "C_Log_System.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::ANIMATION_MODEL;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- アニメーション -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のアニメーションデータをモデルから取得するシステム
// 引数   ：string & アニメーション名の参照
// 戻り値 ：const C_Animation_Data_System * アニメーションデータのアドレス(const)
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * C_Animation_Model_User::M_Get_Animation(std::string & in_animation_name)
{
	// ☆ 変数宣言 ☆ //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * selected_animation = mpr_variable.animation_model->M_Get_Animation_Data_By_Name(in_animation_name);	// 指定された名前のアニメーションデータ


	// アニメーションが取得できなかったらエラーを出して抜ける
	if (selected_animation == nullptr)
	{
		// ☆ 変数宣言 ☆ //
		std::string print_log = "モデル名：" + mpr_variable.model_name + "\n指定された名前のアニメーションデータが見つかりませんでした：" + in_animation_name + "\n現在ののアニメーション一覧：";	// 出力するログ

		const std::vector<ASSET::ANIMATION_SYSTEM::C_Animation_Data_System> & animation_list = mpr_variable.animation_model->M_Get_Animation_Inform_List();	// アニメーションデータのリスト


		// アニメーション名を記録
		for (const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System & now_animation : animation_list)
		{
			print_log += "\n" + now_animation.M_Get_Name();
		}

		// ログを出力し全ての実行を停止する
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, print_log);
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();

		return nullptr;
	}

	return selected_animation;
}


//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Animation_Model_User::C_Animation_Model_User(void)
{
	return;
}

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Animation_Model_User::~C_Animation_Model_User(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリの解放を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Model_User::M_Release(void)
{
	// アニメーションモデルを持ってないならスルー
	if (mpr_variable.animation_model == nullptr)
	{
		return;
	}

	// 制御システムにこのアニメーションモデルの使用放棄を通知する
	ASSET::ANIMATION_MODEL::MANAGER::C_Animation_Model_Manager::M_Release_Animation_Model(mpr_variable.animation_model);

	// アニメーションの計算システムを初期化する
	mpr_variable.animation_calculator.reset();

	return;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のアニメーションモデルを読み込む
// 引数   ：string ロードするアニメーションモデル名
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Animation_Model_User::M_Load_Animation_Model(std::string in_load_animation_model_name)
{
	// ☆ 変数宣言 ☆ //
	ASSET::ANIMATION_MODEL::C_Animation_Model_System * new_animation_model_address = nullptr;	// 新しいアニメーションモデルのアドレス


	// アニメーションモデルの名前から探索して取得
	new_animation_model_address = ASSET::ANIMATION_MODEL::MANAGER::C_Animation_Model_Manager::M_Get_Animation_Model_By_Name(in_load_animation_model_name);

	// 指定したアニメーションモデルがまだないなら生成する
	if (new_animation_model_address == nullptr)
	{
		new_animation_model_address = ASSET::ANIMATION_MODEL::MANAGER::C_Animation_Model_Manager::M_Load_Animation_Model_By_Name(in_load_animation_model_name);

		// 生成に失敗したら抜ける
		if (new_animation_model_address == nullptr)
		{
			return false;
		}
	}


	// 取得できたアニメーションモデルと入れ替える
	M_Release();
	mpr_variable.animation_model = new_animation_model_address;
	mpr_variable.animation_calculator.reset(new ANIMATION::CALCULATOR::C_Animation_Calculation_System(new_animation_model_address->M_Get_Bone_Inform_List()));

	// モデル名を記録
	mpr_variable.model_name = in_load_animation_model_name;

	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のアニメーションデータをロードする
// 引数   ：string ロードするアニメーションデータ名
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Animation_Model_User::M_Load_Animation_Data_By_Name(std::string in_load_animation_data_name)
{
	// デバッグ時はエラーチェックをする
#ifdef _DEBUG

	// ☆ 変数宣言 ☆ //
	bool flg_succeed = false;	// 成功したかどうかのフラグ


	// アニメーションをロードする
	flg_succeed = mpr_variable.animation_model->M_Load_Animation_Data_By_Name(in_load_animation_data_name);


	// エラー時はエラーログを出す
	if (flg_succeed == false)
	{
		// ログを出力し全ての実行を停止する
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_OBJECT, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "モデル名：" + mpr_variable.model_name + "\n指定されたアニメーションデータはありません：" + in_load_animation_data_name);
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
	}

	return flg_succeed;

	// リリース時は通常通りデータを返す
#else

	// アニメーションをロードして結果を返す
	return mpr_variable.animation_model->M_Load_Animation_Data_By_Name(in_load_animation_data_name);

#endif // _DEBUG
}


//-☆- 更新 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーションを指定された時間分経過させる
// 引数   ：float 経過させる時間
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Model_User::M_Time_Update(float in_time_update)
{
	mpr_variable.animation_calculator->M_Update_Time(in_time_update);

	return;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：モデルの描画を開始する、描画前に実行する必要がある
// 引数   ：const C_Transform & ワールドマトリクス変換行列の参照（const）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Model_User::M_Model_Draw_Start(const DirectX::XMMATRIX & in_world_matrix)
{
	// ☆ 変数宣言 ☆ //
	const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & bone_inform_list = mpr_variable.animation_model->M_Get_Bone_Inform_List();	// ボーン情報のリストを取得する


	// アニメーション結果を生成する
	mpr_variable.animation_calculator->M_Create_Animation_Bone_Matrix(mpr_variable.bone_matrix_list, bone_inform_list);


	// アニメーション結果をセットする
	mpr_variable.animation_model->M_Set_Bone_Matrix(mpr_variable.bone_matrix_list);

	// ワールドマトリクス変換行列をセット
	mpr_variable.animation_model->M_Set_World_View_Projection_With_Main_Camera_By_World_Matrix(in_world_matrix);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーションモデルを描画する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Model_User::M_Draw_Model(void)
{
	// アニメーションモデルを持っていないなら描画しない
	if (mpr_variable.animation_model == nullptr)
	{
		return;
	}

	// 描画を行う
	mpr_variable.animation_model->M_Draw_3D_Model();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーションモデルから指定された名前のメッシュのみを描画する
// 引数   ：string メッシュ名
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Model_User::M_Draw_Mesh_By_Mesh_Name(std::string in_mesh_name)
{
	// アニメーションモデルを持っていないなら描画しない
	if (mpr_variable.animation_model == nullptr)
	{
		return;
	}

	// 描画を行う
	mpr_variable.animation_model->M_Draw_Meshes_By_Name(in_mesh_name);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたマテリアルでアニメーションモデルを描画する
// 引数   ：C_Material_User & 使用するマテリアルの参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Model_User::M_Draw_Model_And_Set_Material(ASSET::MATERIAL::C_Material_User & in_use_material)
{
	// アニメーションモデルを持っていないなら描画しない
	if (mpr_variable.animation_model == nullptr)
	{
		return;
	}


	// マテリアルにボーンマトリクスをセットする
	in_use_material.M_Get_Material_Address()->M_Set_Bone_Matrix(mpr_variable.bone_matrix_list);

	// マテリアルをセットする
	in_use_material.M_Material_Attach_To_Draw();

	// 描画を行う
	mpr_variable.animation_model->M_Draw_3D_Model_Do_Not_Use_Material();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたマテリアルでアニメーションモデルから指定された名前のメッシュのみを描画する
// 引数   ：C_Material_User & 使用するマテリアルの参照, string メッシュ名
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Model_User::M_Draw_Mesh_By_Mesh_Name_And_Set_Material(ASSET::MATERIAL::C_Material_User & in_use_material, std::string in_mesh_name)
{
	// アニメーションモデルを持っていないなら描画しない
	if (mpr_variable.animation_model == nullptr)
	{
		return;
	}


	// マテリアルにボーンマトリクスをセットする
	in_use_material.M_Get_Material_Address()->M_Set_Bone_Matrix(mpr_variable.bone_matrix_list);

	// マテリアルをセットする
	in_use_material.M_Material_Attach_To_Draw();

	// 指定されたメッシュのみ描画する
	mpr_variable.animation_model->M_Draw_Meshes_By_Name_Do_Not_Use_Material(in_mesh_name);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：モデルの描画を終了する、モデルの描画が完了したときに実行することでメモリが最適化される
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Model_User::M_Model_Draw_End(void)
{
	mpr_variable.bone_matrix_list.clear();
	mpr_variable.bone_matrix_list.shrink_to_fit();

	return;
}


//-☆- アニメーション -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーションを現在の時間のまま再生する（ブレンドあり）
// 引数   ：string アニメーション名, float ブレンドに必要な時間
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Animation_Model_User::M_Play_Animation(std::string in_animation_name, float in_need_blend_time)
{
	// ☆ 変数宣言 ☆ //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * selected_animation = M_Get_Animation(in_animation_name);	// 指定された名前のアニメーションデータ


	// アニメーションのデータが正しくロードされているときのみアニメーションを再生
	if (selected_animation)
	{
		mpr_variable.animation_calculator->M_Set_Need_Blend_Time(in_need_blend_time);
		mpr_variable.animation_calculator->M_Blend_Play_Animation(selected_animation);

		return true;
	}

	return false;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーションを指定された時間から再生する（ブレンドあり）
// 引数   ：string アニメーション名, float ブレンドに必要な時間, float アニメーション開始時間
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Animation_Model_User::M_Play_Animation_Set_Time(std::string in_animation_name, float in_need_blend_time, float in_start_time)
{
	// ☆ 変数宣言 ☆ //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * selected_animation = M_Get_Animation(in_animation_name);	// 指定された名前のアニメーションデータ


	// アニメーションのデータが正しくロードされているときのみ開始時間を設定してアニメーションを再生
	if (selected_animation)
	{
		mpr_variable.animation_calculator->M_Set_Need_Blend_Time(in_need_blend_time);
		mpr_variable.animation_calculator->M_Set_Animation_Time(in_start_time);
		mpr_variable.animation_calculator->M_Blend_Play_Animation(selected_animation);

		return true;
	}

	return false;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーションを現在の時間のままループ再生する（ブレンドあり）
// 引数   ：string アニメーション名, float ブレンドに必要な時間
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Animation_Model_User::M_Loop_Play_Animation(std::string in_animation_name, float in_need_blend_time)
{
	// ☆ 変数宣言 ☆ //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * selected_animation = M_Get_Animation(in_animation_name);	// 指定された名前のアニメーションデータ


	// アニメーションのデータが正しくロードされているときのみループアニメーションを再生
	if (selected_animation)
	{
		mpr_variable.animation_calculator->M_Set_Need_Blend_Time(in_need_blend_time);
		mpr_variable.animation_calculator->M_Blend_Play_Animation(selected_animation);

		return true;
	}

	return false;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーションを指定された時間からループ再生する（ブレンドあり）（ブレンド後のアニメーションは0秒から始まる）
// 引数   ：string アニメーション名, float ブレンドに必要な時間, float アニメーション開始時間
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Animation_Model_User::M_Loop_Play_Animation_And_Set_Time(std::string in_animation_name, float in_need_blend_time, float in_start_time)
{
	// ☆ 変数宣言 ☆ //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * selected_animation = M_Get_Animation(in_animation_name);	// 指定された名前のアニメーションデータ


	// アニメーションのデータが正しくロードされているときのみ開始時間を設定してループアニメーションを再生
	if (selected_animation)
	{
		mpr_variable.animation_calculator->M_Set_Need_Blend_Time(in_need_blend_time);
		mpr_variable.animation_calculator->M_Set_Animation_Time(in_start_time);
		mpr_variable.animation_calculator->M_Blend_Loop_Play_Animation(selected_animation);

		return true;
	}

	return false;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーションを現在の時間のまま強制的に再生する（ブレンドなし）
// 引数   ：string アニメーション名
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Animation_Model_User::M_Force_Play_Animation(std::string in_animation_name)
{
	// ☆ 変数宣言 ☆ //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * selected_animation = M_Get_Animation(in_animation_name);	// 指定された名前のアニメーションデータ


	// アニメーションのデータが正しくロードされているときのみ開始時間を設定してアニメーションを再生
	if (selected_animation)
	{
		mpr_variable.animation_calculator->M_Play_Animation(selected_animation);

		return true;
	}

	return false;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーションを指定された時間から強制的に再生する（ブレンドなし）
// 引数   ：string アニメーション名, float アニメーションの開始時間
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Animation_Model_User::M_Force_Play_Animation_And_Set_Time(std::string in_animation_name, float in_start_time)
{
	// ☆ 変数宣言 ☆ //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * selected_animation = M_Get_Animation(in_animation_name);	// 指定された名前のアニメーションデータ


	// アニメーションのデータが正しくロードされているときのみ開始時間を設定してアニメーションを再生
	if (selected_animation)
	{
		mpr_variable.animation_calculator->M_Set_Animation_Time(in_start_time);
		mpr_variable.animation_calculator->M_Play_Animation(selected_animation);

		return true;
	}

	return false;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーションを現在の時間のまま強制的にループ再生する（ブレンドなし）
// 引数   ：string アニメーション名
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Animation_Model_User::M_Force_Loop_Play_Animation(std::string in_animation_name)
{
	// ☆ 変数宣言 ☆ //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * selected_animation = M_Get_Animation(in_animation_name);	// 指定された名前のアニメーションデータ


	// アニメーションのデータが正しくロードされているときのみ開始時間を設定してループアニメーションを再生
	if (selected_animation)
	{
		mpr_variable.animation_calculator->M_Loop_Play_Animation(selected_animation);

		return true;
	}

	return false;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーションを指定された時間から強制的にループ再生する（ブレンドなし）
// 引数   ：string アニメーション名, float アニメーションの開始時間
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Animation_Model_User::M_Force_Loop_Play_Animation_And_Set_Time(std::string in_animation_name, float in_start_time)
{
	// ☆ 変数宣言 ☆ //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * selected_animation = M_Get_Animation(in_animation_name);	// 指定された名前のアニメーションデータ


	// アニメーションのデータが正しくロードされているときのみ開始時間を設定してループアニメーションを再生
	if (selected_animation)
	{
		mpr_variable.animation_calculator->M_Set_Animation_Time(in_start_time);
		mpr_variable.animation_calculator->M_Loop_Play_Animation(selected_animation);

		return true;
	}

	return false;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーション速度をセットする
// 引数   ：float セットするアニメーション速度
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Model_User::M_Set_Animation_Speed(float in_set_animation_speed)
{
	mpr_variable.animation_calculator->M_Set_Animation_Speed(in_set_animation_speed);

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在のアニメーションモデルを返す
// 引数   ：void
// 戻り値 ：C_Animation_Model_System * 現在のアニメーションモデルへのアドレス
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
ASSET::ANIMATION_MODEL::C_Animation_Model_System * C_Animation_Model_User::M_Get_Animation_Model_Address(void)
{
	return mpr_variable.animation_model;
}

