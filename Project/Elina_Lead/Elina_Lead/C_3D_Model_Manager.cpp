//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：3Dモデルのクラス
// 説明   ：3Dモデルの取得から描画、アニメーションの実行までを行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_3D_Model_Manager.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::MODEL::MANAGER;


// ☆ スタティック変数 ☆ //
C_3D_Model_Manager C_3D_Model_Manager::m_this;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- 初期化 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_3D_Model_Manager::C_3D_Model_Manager(void)
{
	return;
}


//==☆ パブリック ☆==//

//-☆- 終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_3D_Model_Manager::~C_3D_Model_Manager(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリの解放をする
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_3D_Model_Manager::M_Release(void)
{
	for (S_3D_Model_Inform & now_3d_model : m_this.mpr_variable.model_list)
	{
		now_3d_model.model_data.reset();
	}

	m_this.mpr_variable.model_list.clear();
	m_this.mpr_variable.model_list.shrink_to_fit();

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された3Dモデルを返す
// 引数   ：string 3Dモデルの名前
// 戻り値 ：C_3D_Model_System * 指定された3Dモデルデータへのアドレス、なければnullptrを返す
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
ASSET::MODEL::C_3D_Model_System * C_3D_Model_Manager::M_Get_3D_Model_By_Name(std::string in_3D_model_name)
{
	// 指定された名前の3Dモデルを探す
	for (S_3D_Model_Inform & model_inform : m_this.mpr_variable.model_list)
	{
		if (model_inform.name == in_3D_model_name)
		{
			model_inform.user_sum += 1;
			return model_inform.model_data.get();
		}
	}

	// 見つからなかった
	return nullptr;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：3Dモデル名から3Dモデルをロードする
// 引数   ：string 3Dモデル名
// 戻り値 ：C_Material * 生成した3Dモデルデータへのアドレス
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
ASSET::MODEL::C_3D_Model_System * C_3D_Model_Manager::M_Load_3D_Model_By_Name(std::string in_3D_model_name)
{
	// ☆ 変数宣言 ☆ //
	std::string model_3d_inform_path = "project/asset/model/" + in_3D_model_name + ".elsttmdl";	// 3Dモデル情報へのパス

	int model_slot_num = m_this.mpr_variable.model_list.size();	// 操作する3Dモデルの番号


	// 新しい3Dモデル設定用のスロットを生成
	m_this.mpr_variable.model_list.resize(model_slot_num + 1);
	m_this.mpr_variable.model_list[model_slot_num].model_data.reset(new ASSET::MODEL::C_3D_Model_System());

	// 3Dモデル情報から3Dモデルをロードする、できなければfalseを返す
	if (m_this.mpr_variable.model_list[model_slot_num].model_data->M_Load_3D_Model_By_Path(model_3d_inform_path) == false)
	{
		return nullptr;
	}

	// 新しい3Dモデルの名前を登録し、使用されている数を加算
	m_this.mpr_variable.model_list[model_slot_num].name = in_3D_model_name;
	m_this.mpr_variable.model_list[model_slot_num].user_sum = 1;

	// 生成した3Dモデルを返す
	return m_this.mpr_variable.model_list[model_slot_num].model_data.get();
}


//-☆- 削除 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：3Dモデル名から3Dモデルをロードする
// 引数   ：string 3Dモデル名
// 戻り値 ：C_Material * 生成した3Dモデルデータへのアドレス
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_3D_Model_Manager::M_Release_3D_Model(ASSET::MODEL::C_3D_Model_System * & in_delete_model)
{
	// 3Dモデル設定名から指定された3Dモデル設定を探して、見つかったら所有されている数のカウントを減らして参照できなくする
	for (S_3D_Model_Inform & now_3d_model_inform : m_this.mpr_variable.model_list)
	{
		if (now_3d_model_inform.model_data.get() == in_delete_model)
		{
			in_delete_model = nullptr;
			now_3d_model_inform.user_sum -= 1;


			// この3Dモデル設定が使われなくなったら削除する
			m_this.mpr_variable.model_list.erase
			(
				std::remove_if
				(
					m_this.mpr_variable.model_list.begin(),
					m_this.mpr_variable.model_list.end(),

					// 残りの数が0になると削除するラムダ式
					[](S_3D_Model_Inform & in_3d_model_setting)->bool
					{
						if (in_3d_model_setting.user_sum < 1)
						{
							in_3d_model_setting.model_data.reset();

							return true;
						}

						return false;
					}
				),
				m_this.mpr_variable.model_list.end()
			);

			return;
		}
	}

	return;
}

