//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーションの計算を制御するクラス
// 説明   ：ボーンマトリクスに対するアニメーションの操作を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Animation_Calculation_System.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::ANIMATION::CALCULATOR;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Animation_Calculation_System::C_Animation_Calculation_System(void)
{
	mpr_variable.animation_algorithm.reset(new ASSET::ANIMATION::CALCULATOR::ALGORITHM::C_Animation_Calculate_Algorithm_Base);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Animation_Calculation_System::~C_Animation_Calculation_System(void)
{
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


	return;
}
