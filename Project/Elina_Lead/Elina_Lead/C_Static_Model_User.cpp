//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：3Dモデルを使用するためのシステム
// 説明   ：3Dモデル使用時の3Dモデル制御システムとの連絡を簡略化する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Static_Model_User.h"
#include "C_Static_Model_Manager.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::MODEL;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Static_Model_User::C_Static_Model_User(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Static_Model_User::~C_Static_Model_User(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリの解放を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Static_Model_User::M_Release(void)
{
	// 3Dモデルを持っていないなら実行しない
	if (mpr_variable.use_model_address == nullptr)
	{
		return;
	}


	// 現在所持している3Dモデルの所有権を放棄する
	ASSET::MODEL::MANAGER::C_Static_Model_Manager::M_Release_3D_Model(mpr_variable.use_model_address);

	return;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前の3Dモデルを読み込む
// 引数   ：string ロードする3Dモデル名
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Static_Model_User::M_Load_3D_Model(std::string in_load_3d_model_name)
{
	// ☆ 変数宣言 ☆ //
	ASSET::MODEL::C_Static_Model_System * new_3D_model_address = nullptr;	// 新しい3Dモデルのアドレス


	// 3Dモデル名前から探索して取得
	new_3D_model_address = ASSET::MODEL::MANAGER::C_Static_Model_Manager::M_Get_3D_Model_By_Name(in_load_3d_model_name);

	// 指定した3Dモデルがまだないなら生成する
	if (new_3D_model_address == nullptr)
	{
		new_3D_model_address = ASSET::MODEL::MANAGER::C_Static_Model_Manager::M_Load_3D_Model_By_Name(in_load_3d_model_name);

		// 生成に失敗したら抜ける
		if (new_3D_model_address == nullptr)
		{
			return false;
		}
	}


	// 取得できたマテリアルと入れ替える
	M_Release();
	mpr_variable.use_model_address = new_3D_model_address;

	return true;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：3Dモデルを描画する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Static_Model_User::M_Draw_3D_Model(void)
{
	// モデルを持っていないなら描画はしない
	if (mpr_variable.use_model_address == nullptr)
	{
		return;
	}

	mpr_variable.use_model_address->M_Draw_Model();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のメッシュのみ描画する
// 引数   ：string 描画するメッシュ名
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Static_Model_User::M_Draw_3D_Model_Meshes_By_Mesh_Name(std::string in_mesh_name)
{
	// モデルを持っていないなら描画はしない
	if (mpr_variable.use_model_address == nullptr)
	{
		return;
	}

	mpr_variable.use_model_address->M_Draw_Meshes_By_Name(in_mesh_name);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：マテリアルを設定せずに、3Dモデルを描画する（描画前にマテリアルをセットするとき用）
// 引数   ：C_Material_User & 使用するマテリアルの参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Static_Model_User::M_Draw_3D_Model_And_Set_Material(ASSET::MATERIAL::C_Material_User & in_use_material)
{
	// モデルを持っていないなら描画はしない
	if (mpr_variable.use_model_address == nullptr)
	{
		return;
	}


	// 指定されたマテリアルをレンダリンシステムに送る
	in_use_material.M_Material_Attach_To_Draw();

	// 3Dモデルを描画する
	mpr_variable.use_model_address->M_Draw_Model_Do_Not_Use_Material();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   マテリアルを設定せずに、3Dモデルから指定されたメッシュ名のみ描画する（描画前にマテリアルをセットするとき用）
// 引数   ：C_Material_User & 使用するマテリアルの参照, string 描画するメッシュ名（複数判定する）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Static_Model_User::M_Draw_3D_Model_Meshes_By_Name_And_Set_Material(ASSET::MATERIAL::C_Material_User & in_use_material, std::string in_mesh_name)
{
	// モデルを持っていないなら描画はしない
	if (mpr_variable.use_model_address == nullptr)
	{
		return;
	}


	// 指定されたマテリアルをレンダリンシステムに送る
	in_use_material.M_Material_Attach_To_Draw();

	// 指定された名前のメッシュのみを描画する
	mpr_variable.use_model_address->M_Draw_Meshes_By_Name_Do_Not_Use_Material(in_mesh_name);

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在の3Dモデルを返す
// 引数   ：string 描画するメッシュ名
// 戻り値 ：C_Static_Model_System * 現在の3Dモデルへのアドレス
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Static_Model_System * C_Static_Model_User::M_Get_3D_Model_Address(void)
{
	return mpr_variable.use_model_address;
}


