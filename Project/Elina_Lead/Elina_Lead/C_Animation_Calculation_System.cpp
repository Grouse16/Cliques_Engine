//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーションの計算を制御するクラス
// 説明   ：ボーンマトリクスに対するアニメーションの操作を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Animation_Calculation_System.h"
#include "C_Bone_Data.h"
#include "C_Animation_Algorithm_No_Animation.h"


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
C_Animation_Calculation_System::C_Animation_Calculation_System(const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & in_bone_list)
{
	// ボーン数を取得
	mpr_variable.bone_sum = in_bone_list.size();

	// 初期状態のボーンを設定するアルゴリズムを生成
	mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_No_Animation(in_bone_list));

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Animation_Calculation_System::~C_Animation_Calculation_System(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリの解放を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Calculation_System::M_Release(void)
{
	mpr_variable.animation_algorithm.reset();
	mpr_variable.bone_sum = 0;

	return;
}


//-☆- アニメーション -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された配列にボーンマトリクス配列のデータをセットする
// 引数   ：vector<XMFLOAT4X4> & 設定先のボーンマトリクス配列のデータ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Calculation_System::M_Get_Bone_Matrix(std::vector<DirectX::XMFLOAT4X4> & out_bone_matrix_list)
{
	// ボーンデータ用の配列を確保する
	out_bone_matrix_list.clear();
	out_bone_matrix_list.shrink_to_fit();
	out_bone_matrix_list.resize(mpr_variable.bone_sum);

	mpr_variable.animation_algorithm->M_Animation_Time_Update();
	mpr_variable.animation_algorithm->M_Animation_Update(out_bone_matrix_list);

	return;
}
