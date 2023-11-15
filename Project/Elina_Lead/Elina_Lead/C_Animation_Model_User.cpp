//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーションモデルを使用するためのシステム
// 説明   ：アニメーションモデルマネージャーとの操作を隠蔽し、簡単に使用できるようにカプセル化する　アニメーションの実行を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Animation_Model_User.h"
#include "C_3D_Animation_Model_Manager.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::ANIMATION_MODEL;


// ☆ 関数 ☆ //

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
	ASSET::ANIMATION_MODEL::MANAGER::C_3D_Animation_Model_Manager::M_Release_Animation_Model(mpr_variable.animation_model);

	// アニメーションの計算システムを初期化する
	mpr_variable.animation_calculator.reset();

	return;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のアニメーションモデルを読み込む
// 引数   ：string ロードするアニメーションモデル名
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Model_User::M_Load_Animation_Model(std::string in_load_animation_model_name)
{
	// ☆ 変数宣言 ☆ //
	ASSET::ANIMATION_MODEL::C_3D_Animation_Model_System * new_animation_model_address = nullptr;	// 新しいアニメーションモデルのアドレス


	// アニメーションモデルの名前から探索して取得
	new_animation_model_address = ASSET::ANIMATION_MODEL::MANAGER::C_3D_Animation_Model_Manager::M_Get_Animation_Model_By_Name(in_load_animation_model_name);

	// 指定したアニメーションモデルがまだないなら生成する
	if (new_animation_model_address == nullptr)
	{
		new_animation_model_address = ASSET::ANIMATION_MODEL::MANAGER::C_3D_Animation_Model_Manager::M_Load_Animation_Model_By_Name(in_load_animation_model_name);

		// 生成に失敗したら抜ける
		if (new_animation_model_address == nullptr)
		{
			return;
		}
	}


	// 取得できたアニメーションモデルと入れ替える
	M_Release();
	mpr_variable.animation_model = new_animation_model_address;
	mpr_variable.animation_calculator.reset(new ANIMATION::CALCULATOR::C_Animation_Calculation_System(new_animation_model_address->M_Get_Bone_Inform_List()));

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のアニメーションデータをロードする
// 引数   ：string ロードするアニメーションデータ名
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Animation_Model_User::M_Load_Animation_Data_By_Name(std::string in_load_animation_data_name)
{
	mpr_variable.animation_model->M_Load_Animation_Data_By_Name(in_load_animation_data_name);

	return;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：このアニメーションモデルを描画する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Animation_Model_User::M_Animation_Model_Draw(void)
{
	// アニメーションモデルを持っていないなら描画しない
	if (mpr_variable.animation_model == nullptr)
	{
		return;
	}

	
	// ☆ 変数宣言 ☆ //
	std::vector<DirectX::XMFLOAT4X4> bone_matrix_list;	// ボーンマトリクスの配列


	// アニメーション結果をセットする
	mpr_variable.animation_calculator->M_Create_Animationed_Bone_Matrix(bone_matrix_list);
	mpr_variable.animation_model->M_Set_Bone_Matrix(bone_matrix_list);


	// 描画を行う
	mpr_variable.animation_model->M_Draw_3D_Model();

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在のアニメーションモデルを返す
// 引数   ：void
// 戻り値 ：C_3D_Animation_Model_System * 現在のアニメーションモデルへのアドレス
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
ASSET::ANIMATION_MODEL::C_3D_Animation_Model_System * C_Animation_Model_User::M_Get_Animation_Model_Address(void)
{
	return mpr_variable.animation_model;
}

