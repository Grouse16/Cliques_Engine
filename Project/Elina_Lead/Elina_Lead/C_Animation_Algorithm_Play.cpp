//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：通常にアニメーションを再生するクラス
// 説明   ：一つのアニメーションを持ってそれの再生のみ行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Animation_Algorithm_Play.h"
#include "C_Bone_Data.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::ANIMATION::ALGORITHM;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：S_Animation_Status & アニメーションステータスの参照, C_Animation_Data_System * アニメーションするデータのセット
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Animation_Algorithm_Play::C_Animation_Algorithm_Play(ASSET::ANIMATION::S_Animation_Status & in_set_animation_status, ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * in_set_animation_data) : m_animation_status(in_set_animation_status)
{
	m_now_animation = in_set_animation_data;
	m_animation_status.animation_blend_percent = 0.0f;


	// 現在のアニメーション時間が新しいアニメーションの終了時間を超えるなら超えないように直す
	M_Guard_1_Over_2(m_animation_status.animation_time, in_set_animation_data->M_Get_Animation_Time());

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Animation_Algorithm_Play::~C_Animation_Algorithm_Play(void)
{
	return;
}


//-☆- 更新 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーション時間の更新
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Algorithm_Play::M_Animation_Time_Update(void)
{
	// アニメーションの時間の更新を行う
	M_Animation_Time_Base_Update(m_animation_status, m_now_animation->M_Get_Animation_Time());

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーションの更新
// 引数   ：vector<XMFLOAT4X4> & 更新をかけるボーンのマトリクスの配列の参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Algorithm_Play::M_Animation_Update(std::vector<DirectX::XMFLOAT4X4> & out_set_matrix)
{
	// ☆ 変数宣言 ☆ //
	std::vector<ASSET::ANIMATION::BONE::C_Bone_Data> bone_data_list;	// ボーンのデータのリスト


	// ボーンデータにアニメーションによるボーンデータを受け取る
	bone_data_list.resize(m_animation_status.bone_sum);
	m_now_animation->M_Set_Bone_Key(m_animation_status.animation_time, bone_data_list);


	// ボーンデータをマトリクスに変換してセットする
	for (int l_now_bone_num = 0; l_now_bone_num < m_animation_status.bone_sum; l_now_bone_num++)
	{
		bone_data_list[l_now_bone_num].M_Set_Bone_Matrix_Data(out_set_matrix[l_now_bone_num]);
	}

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在のアニメーションを返す
// 引数   ：void
// 戻り値 ：C_Animation_Data_System * 現在のアニメーションのアドレス
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * C_Animation_Algorithm_Play::M_Get_Now_Animation(void)
{
	return m_now_animation;
}

