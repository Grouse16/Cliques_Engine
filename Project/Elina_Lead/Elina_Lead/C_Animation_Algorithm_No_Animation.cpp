

// ☆ ファイルひらき ☆ //
#include "C_Animation_Algorithm_No_Animation.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::ANIMATION::ALGORITHM;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：const vector<S_Bone_Inform> * ボーンの初期情報のアドレス(const)
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Animation_Algorithm_No_Animation::C_Animation_Algorithm_No_Animation(const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & in_set_bone_inform_list) : C_Animation_Algorithm_No_Animation(in_set_bone_inform_list)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Animation_Algorithm_No_Animation::~C_Animation_Algorithm_No_Animation(void)
{
	return;
}


//-☆- 更新 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーション時間の更新
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Algorithm_No_Animation::M_Animation_Time_Update(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーションの更新
// 引数   ：vector<XMFLOAT4X4> & 更新をかけるボーンのマトリクスの配列の参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Algorithm_No_Animation::M_Animation_Update(std::vector<DirectX::XMFLOAT4X4> & in_bone_matrix_list)
{
	// 初期のオフセットマトリクスをセットする
	for (int l_bone_num = 0; l_bone_num < in_bone_matrix_list.size(); l_bone_num++)
	{
		in_bone_matrix_list[l_bone_num] = mpr_variable.bone_inform_list[l_bone_num].offset_matrix;
	}

	return;
}
