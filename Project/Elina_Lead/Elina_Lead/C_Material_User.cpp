//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：マテリアルを使用するためのクラス
// 説明   ：マテリアルの取得、ロード、解放を円滑に行い、staticであるマネージャを他の実装部から切り離すためにある
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Material_User.h"
#include "C_Material_Manager.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::MATERIAL;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Material_User::C_Material_User(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Material_User::~C_Material_User(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：マテリアルを解放する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Material_User::M_Release(void)
{
	// マテリアルを持っていないならスルー
	if (mpr_variable.material_address == nullptr)
	{
		return;
	}

	// マテリアルの使用終了を制御用システムに通知
	ASSET::MATERIAL::MANAGER::C_Material_Manager::M_Release_Material(mpr_variable.material_address);

	return;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のマテリアルを読み込む
// 引数   ：std::string マテリアル名
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Material_User::M_Load_Material(std::string in_material_name)
{
	// ☆ 変数宣言 ☆ //
	ASSET::MATERIAL::C_Material * new_material_address;	// 新しいマテリアルのアドレス


	// マテリアル名前から探索して取得
	new_material_address = ASSET::MATERIAL::MANAGER::C_Material_Manager::M_Get_Material_By_Name(in_material_name);

	// 指定したマテリアルがまだないなら生成する
	if (new_material_address == nullptr)
	{
		new_material_address = ASSET::MATERIAL::MANAGER::C_Material_Manager::M_Load_Material_By_Name(in_material_name);

		// 生成に失敗したら抜ける
		if (new_material_address == nullptr)
		{
			return;
		}
	}


	// 取得できたマテリアルと入れ替える
	M_Release();
	mpr_variable.material_address = new_material_address;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：このマテリアルを描画用にセットする
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Material_User::M_Material_Attach_To_Draw(void)
{
	mpr_variable.material_address->M_Attach_To_GPU();

	return;
}



