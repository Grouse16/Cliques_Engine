//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーションの計算を制御するクラス
// 説明   ：ボーンマトリクスに対するアニメーションの操作を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Animation_Calculation_System.h"
#include "C_Animation_Algorithm_No_Animation.h"
#include "C_Animation_Algorithm_Play.h"
#include "C_Animation_Algorithm_Loop_Play.h"
#include "C_Animation_Algorithm_Blend_Play.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::ANIMATION::CALCULATOR;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：const vector<S_Bone_Inform> & ボーン情報のリストの参照
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Animation_Calculation_System::C_Animation_Calculation_System(const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & in_bone_list) : mpr_variable((int)in_bone_list.size())
{
	// 初期状態のボーンを設定するアルゴリズムを生成
	mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_No_Animation(in_bone_list));

	// 初期状態は最初からアニメーション終了状態
	mpr_variable.animation_status.flg_animation_end = true;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Animation_Calculation_System::~C_Animation_Calculation_System(void)
{
	mpr_variable.animation_algorithm.reset();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーションのステータスの初期化
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Calculation_System::M_Animation_Status_Reset(void)
{
	mpr_variable.animation_status.animation_time = 0.0f;
	mpr_variable.animation_status.animation_blend_percent = 0.0f;
	mpr_variable.animation_status.animation_speed = 1.0f;
	mpr_variable.animation_status.flg_animation_end = false;

	return;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在のアニメーション時間をセットする
// 引数   ：float セットするアニメーション時間
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Calculation_System::M_Set_Animation_Time(float in_set_animation_time)
{
	mpr_variable.animation_status.animation_time = in_set_animation_time;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在のアニメーション時間をセットする
// 引数   ：float セットするアニメーションのスピード
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Calculation_System::M_Set_Animation_Speed(float in_set_speed)
{
	mpr_variable.animation_status.animation_speed = in_set_speed;

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーションが終了しているかどうかを返す
// 引数   ：void
// 戻り値 ：bool アニメーション終了のフラグ
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Animation_Calculation_System::M_Get_Animation_Is_End(void)
{
	return mpr_variable.animation_status.flg_animation_end;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在のアニメーション時間を返す
// 引数   ：void
// 戻り値 ：float 現在のアニメーション時間
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
float C_Animation_Calculation_System::M_Get_Animation_Time(void)
{
	return mpr_variable.animation_status.animation_time;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在のアニメーションのスピードを返す
// 引数   ：void
// 戻り値 ：float 現在のアニメーションのスピード
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
float C_Animation_Calculation_System::M_Get_Animation_Speed(void)
{
	return mpr_variable.animation_status.animation_speed;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在のアニメーションのブレンド率を返す
// 引数   ：void
// 戻り値 ：float 現在のアニメーションのブレンド率
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
float C_Animation_Calculation_System::M_Get_Animation_Blend_Percent(void)
{
	return mpr_variable.animation_status.animation_blend_percent;
}


//-☆- アニメーション -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：渡されたアニメーションを再生する
// 引数   ：C_Animation_Data_System * 再生するアニメーションデータのアドレス
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Calculation_System::M_Play_Animation(ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * in_play_animation)
{
	mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Play(mpr_variable.animation_status, in_play_animation));

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：渡されたアニメーションをループ再生する
// 引数   ：C_Animation_Data_System * ループ再生するアニメーションデータのアドレス
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Calculation_System::M_Loop_Play_Animation(ASSET::ANIMATION_SYSTEM::C_Animation_Data_System* in_loop_play_animation)
{
	mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Loop_Play(mpr_variable.animation_status, in_loop_play_animation));

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：渡されたアニメーションをブレンドして再生する
// 引数   ：C_Animation_Data_System * 再生するアニメーションデータのアドレス（ブレンド先）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Calculation_System::M_Blend_Play_Animation(ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * in_blend_play_animation)
{
	// ☆ 変数宣言 ☆ //
	ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * now_animation_data = mpr_variable.animation_algorithm->M_Get_Now_Animation();	// 現在のアニメーションのデータ（ブレンド元）


	// ブレンド元のアニメーションがあるなら、ブレンドアニメーションを開始
	if (now_animation_data)
	{
		mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Blend_Play(mpr_variable.animation_status, now_animation_data, in_blend_play_animation));
	}

	// ブレンド元のアニメーションがないなら通常のアニメーションを行う
	else
	{
		mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Play(mpr_variable.animation_status, in_blend_play_animation));
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された配列にアニメーション結果のボーンマトリクス配列のデータをセットする
// 引数   ：vector<XMFLOAT4X4> & 設定先のボーンマトリクス配列のデータの参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Calculation_System::M_Create_Animationed_Bone_Matrix(std::vector<DirectX::XMFLOAT4X4> & out_bone_matrix_list)
{
	// ボーンデータ用の配列を確保する
	out_bone_matrix_list.clear();
	out_bone_matrix_list.shrink_to_fit();
	out_bone_matrix_list.resize(mpr_variable.animation_status.bone_sum);

	mpr_variable.animation_algorithm->M_Animation_Time_Update();
	mpr_variable.animation_algorithm->M_Animation_Update(out_bone_matrix_list);

	return;
}
