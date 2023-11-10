//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：マテリアルを制御するためのシステム
// 説明   ：マテリアルのロードや解放を行ったり、重複して同じマテリアルをロードしないように管理する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include <algorithm>

#include "C_Material_Manager.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::MATERIAL::MANAGER;


// ☆ スタティック変数 ☆ //
C_Material_Manager C_Material_Manager::m_this;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- 初期化 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ、シングルトン化する
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Material_Manager::C_Material_Manager(void)
{
	return;
}


//==☆ パブリック ☆==//

//-☆- 終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ、シングルトン化する
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Material_Manager::~C_Material_Manager(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリを解放する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Material_Manager::M_Release(void)
{
	for (S_Material_Manage_Inform & now_material : m_this.mpr_variable.material_inform_list)
	{
		now_material.material.reset();
	}

	m_this.mpr_variable.material_inform_list.clear();
	m_this.mpr_variable.material_inform_list.shrink_to_fit();

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたマテリアルを返す
// 引数   ：std::string マテリアルの名前
// 戻り値 ：C_Material * 指定されたマテリアルデータへのアドレス、なければnullptrを返す
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
ASSET::MATERIAL::C_Material * C_Material_Manager::M_Get_Material_By_Name(std::string in_material_name)
{
	// マテリアル名から指定されたマテリアルを探して、見つかったらそれを返す
	for (S_Material_Manage_Inform & now_material_inform : m_this.mpr_variable.material_inform_list)
	{
		if (now_material_inform.name == in_material_name)
		{
			now_material_inform.user_sum += 1;
			return now_material_inform.material.get();
		}
	}

	// 見つからなかった
	return nullptr;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：マテリアル名からマテリアルをロードする
// 引数   ：std::string マテリアルの名前
// 戻り値 ：C_Material * 指定されたマテリアルデータへのアドレス、なければnullptrを返す
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
ASSET::MATERIAL::C_Material * C_Material_Manager::M_Load_Material_By_Name(std::string in_material_name)
{
	// ☆ 定数 ☆ //
	std::string material_inform_path = "project/asset/material/" + in_material_name + ".elmat";	// マテリアル情報へのパス

	int material_slot_num = m_this.mpr_variable.material_inform_list.size();	// 操作するマテリアルの番号


	// 新しいマテリアル設定用のスロットを生成
	m_this.mpr_variable.material_inform_list.resize(material_slot_num + 1);
	m_this.mpr_variable.material_inform_list[material_slot_num].material.reset(new ASSET::MATERIAL::C_Material);

	// マテリアル情報からマテリアルをロードする、できなければfalseを返す
	if (m_this.mpr_variable.material_inform_list[material_slot_num].material->M_Load_Material_By_Path(material_inform_path) == false)
	{
		return nullptr;
	}

	// 新しいマテリアルの名前を登録し、使用されている数を加算
	m_this.mpr_variable.material_inform_list[material_slot_num].name = in_material_name;
	m_this.mpr_variable.material_inform_list[material_slot_num].user_sum = 1;

	// 生成したマテリアルを返す
	return m_this.mpr_variable.material_inform_list[material_slot_num].material.get();
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたマテリアルを返す
// 引数   ：std::string マテリアルの名前
// 戻り値 ：C_Material * 指定されたマテリアルデータへのアドレス、なければnullptrを返す
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Material_Manager::M_Release_Material(ASSET::MATERIAL::C_Material * & in_release_material_address)
{
	// マテリアル名から指定されたマテリアルを探して、見つかったら所有されている数のカウントを減らして参照できなくする
	for (S_Material_Manage_Inform & now_material_inform : m_this.mpr_variable.material_inform_list)
	{
		if (now_material_inform.material.get() == in_release_material_address)
		{
			in_release_material_address = nullptr;
			now_material_inform.user_sum -= 1;


			// このマテリアルが使われなくなったら削除する
			m_this.mpr_variable.material_inform_list.erase
			(
				std::remove_if
				(
					m_this.mpr_variable.material_inform_list.begin(),
					m_this.mpr_variable.material_inform_list.end(),

					// 残りの数が0になると削除するラムダ式
					[](S_Material_Manage_Inform & in_material)->bool
					{
						if (in_material.user_sum < 1)
						{
							in_material.material.reset();

							return true;
						}

						return false;
					}
				), 
				m_this.mpr_variable.material_inform_list.end()
			);

			return;
		}
	}

	return;
}


