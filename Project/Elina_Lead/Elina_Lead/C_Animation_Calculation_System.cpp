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
#include "C_Animation_Algorithm_Blend_And_Loop.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::ANIMATION::CALCULATOR;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- ブレンド制御 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ブレンド終了を確認し、対応したアニメーション処理に入れ替える
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Calculation_System::M_Check_Blend_End_And_Animation_Setting(void)
{
	// ブレンドが完了しているなら分岐をブレンド後に遷移する分岐を実行
	if (mpr_variable.animation_status.need_blend_time >= 1.0f)
	{
		// ☆ ブレンド後の挙動で処理を分岐 ☆ //
		switch (mpr_variable.blend_after)
		{
			//--☆ 通常の再生に遷移する ☆--//
		case E_ANIMATION_BLENDED_AFTER::e_PLAY_ANIMATION:
			M_Play_Animation(mpr_variable.animation_algorithm->M_Get_Now_Animation());
			break;

			//--☆ ループ再生に遷移する ☆--//
		case E_ANIMATION_BLENDED_AFTER::e_LOOP_ANIMATION:
			M_Loop_Play_Animation(mpr_variable.animation_algorithm->M_Get_Now_Animation());
			break;

			//--☆ ブレンドしていないとき ☆--//
		case E_ANIMATION_BLENDED_AFTER::e_NOT_BLENDING_NOW:
		default:
			break;
		}
	}

	return;
}


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


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ブレンドにかかる時間をセットする
// 引数   ：float セットするブレンドにかかる時間
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Calculation_System::M_Set_Need_Blend_Time(float in_set_need_blend_time)
{
	mpr_variable.animation_status.need_blend_time = in_set_need_blend_time;

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


//-☆- 更新 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーション時間の経過を行う
// 引数   ：float 経過させる時間
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Calculation_System::M_Update_Time(float in_pass_time)
{
	mpr_variable.animation_status.passed_time = 
		in_pass_time 
		* mpr_variable.animation_status.animation_speed
		* (1.0f - 2.0f * mpr_variable.animation_status.flg_animation_reverse);

	return;
}


//-☆- アニメーション -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：渡されたアニメーションを再生する
// 引数   ：const C_Animation_Data_System * 再生するアニメーションデータのアドレス(const)
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Calculation_System::M_Play_Animation(const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * in_play_animation)
{
	mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Play(mpr_variable.animation_status, in_play_animation));
	mpr_variable.blend_after = E_ANIMATION_BLENDED_AFTER::e_NOT_BLENDING_NOW;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：渡されたアニメーションをループ再生する
// 引数   ：const C_Animation_Data_System * ループ再生するアニメーションデータのアドレス(const)
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Calculation_System::M_Loop_Play_Animation(const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * in_loop_play_animation)
{
	mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Loop_Play(mpr_variable.animation_status, in_loop_play_animation));
	mpr_variable.blend_after = E_ANIMATION_BLENDED_AFTER::e_NOT_BLENDING_NOW;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：渡されたアニメーションをブレンドして再生する
// 引数   ：const C_Animation_Data_System * 再生するアニメーションデータのアドレス（ブレンド先）(const)
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Calculation_System::M_Blend_Play_Animation(const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * in_blend_play_animation)
{
	// ☆ 変数宣言 ☆ //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * now_animation_data = mpr_variable.animation_algorithm->M_Get_Now_Animation();	// 現在のアニメーションのデータ（ブレンド元）


	// ブレンド元のアニメーションがあるなら、ブレンドアニメーションを開始
	if (now_animation_data)
	{
		mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Blend_Play(mpr_variable.animation_status, now_animation_data, in_blend_play_animation));
		mpr_variable.blend_after = E_ANIMATION_BLENDED_AFTER::e_PLAY_ANIMATION;
	}

	// ブレンド元のアニメーションがないなら通常のアニメーションを行う
	else
	{
		mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Play(mpr_variable.animation_status, in_blend_play_animation));
		mpr_variable.blend_after = E_ANIMATION_BLENDED_AFTER::e_NOT_BLENDING_NOW;
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：渡されたアニメーションをブレンド後、ループ再生する
// 引数   ：const C_Animation_Data_System * 再生するアニメーションデータのアドレス（ブレンド先）(const)
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Calculation_System::M_Blend_Loop_Play_Animation(const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * in_blend_loop_animation)
{
	// ☆ 変数宣言 ☆ //
	const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * now_animation_data = mpr_variable.animation_algorithm->M_Get_Now_Animation();	// 現在のアニメーションのデータ（ブレンド元）


	// ブレンド元のアニメーションがあるなら、ブレンドアニメーションを開始
	if (now_animation_data)
	{
		mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Blend_And_Loop(mpr_variable.animation_status, now_animation_data, in_blend_loop_animation));
		mpr_variable.blend_after = E_ANIMATION_BLENDED_AFTER::e_LOOP_ANIMATION;
	}

	// ブレンド元のアニメーションがないならループアニメーションを行う
	else
	{
		mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Loop_Play(mpr_variable.animation_status, in_blend_loop_animation));
		mpr_variable.blend_after = E_ANIMATION_BLENDED_AFTER::e_NOT_BLENDING_NOW;
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された配列にアニメーション結果のボーンマトリクス配列のデータをセットする
// 引数   ：vector<XMFLOAT4X4> & 設定先のボーンマトリクス配列のデータの参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Calculation_System::M_Create_Animation_Bone_Matrix(std::vector<DirectX::XMFLOAT4X4> & out_bone_matrix_list)
{
	// ボーンデータ用の配列を確保する
	out_bone_matrix_list.clear();
	out_bone_matrix_list.shrink_to_fit();
	out_bone_matrix_list.resize(mpr_variable.animation_status.bone_sum);

	mpr_variable.animation_algorithm->M_Animation_Time_Update();
	mpr_variable.animation_algorithm->M_Animation_Update(out_bone_matrix_list);

	// アニメーションブレンド中であれば、ブレンド完了したタイミングで通常のアニメーションに戻る（ブレンドの処理だけを抜いたバージョンに入れ替える）
	M_Check_Blend_End_And_Animation_Setting();

	return;
}
