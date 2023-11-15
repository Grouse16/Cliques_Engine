//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：3Dアニメーションをするモデルを管理するシステム
// 説明   ：同じアニメーションモデルの多重ロードを防ぎ、名前によるモデルの管理を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_3D_Animation_Model_Manager.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::ANIMATION_MODEL::MANAGER;


// ☆ スタティック変数 ☆ //
C_3D_Animation_Model_Manager C_3D_Animation_Model_Manager::m_this;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- 初期化 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ、シングルトン化する
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_3D_Animation_Model_Manager::C_3D_Animation_Model_Manager(void)
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
C_3D_Animation_Model_Manager::~C_3D_Animation_Model_Manager(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリを解放する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_3D_Animation_Model_Manager::M_Release(void)
{
	for (S_3D_Animation_Model_Manage_Inform & in_animation_model_inform : m_this.mpr_variable.animation_model_inform_list)
	{
		in_animation_model_inform.animation_model->M_Release();
		in_animation_model_inform.animation_model.reset();
	}

	m_this.mpr_variable.animation_model_inform_list.clear();
	m_this.mpr_variable.animation_model_inform_list.shrink_to_fit();

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたアニメーションモデルを返す
// 引数   ：string 探すアニメーションモデルの名前
// 戻り値 ：C_3D_Animation_Model_System * 指定されたアニメーションモデルへのアドレス、なければnullptrを返す
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
ASSET::ANIMATION_MODEL::C_3D_Animation_Model_System * C_3D_Animation_Model_Manager::M_Get_Animation_Model_By_Name(std::string in_search_animation_model_name)
{
	// 指定されたアニメーションモデル名と一致するアニメーションモデルのアドレスを返す
	for (S_3D_Animation_Model_Manage_Inform & now_animation_model_inform : m_this.mpr_variable.animation_model_inform_list)
	{
		if (now_animation_model_inform.name == in_search_animation_model_name)
		{
			now_animation_model_inform.user_sum += 1;
			return now_animation_model_inform.animation_model.get();
		}
	}

	// 見つからなかった
	return nullptr;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーションモデル名からアニメーションモデルをロードする
// 引数   ：string ロードするアニメーションモデル名
// 戻り値 ：C_3D_Animation_Model_System * 生成したアニメーションモデルへのアドレス
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
ASSET::ANIMATION_MODEL::C_3D_Animation_Model_System * C_3D_Animation_Model_Manager::M_Load_Animation_Model_By_Name(std::string in_load_animation_model_name)
{
	// ☆ 変数宣言 ☆ //
	std::string model_3d_inform_path = "project/asset/animation_model/" + in_load_animation_model_name + ".elanmmdl";	// アニメーションモデル情報へのパス

	int animation_model_slot_num = m_this.mpr_variable.animation_model_inform_list.size();	// 操作するアニメーションモデルの番号


	// 新しいアニメーションモデル設定用のスロットを生成
	m_this.mpr_variable.animation_model_inform_list.resize(animation_model_slot_num + 1);
	m_this.mpr_variable.animation_model_inform_list[animation_model_slot_num].animation_model.reset(new ASSET::ANIMATION_MODEL::C_3D_Animation_Model_System());

	// アニメーションモデル情報からアニメーションモデルをロードする、できなければfalseを返す
	if (m_this.mpr_variable.animation_model_inform_list[animation_model_slot_num].animation_model->M_Load_3D_Animation_Model_By_Path(model_3d_inform_path) == false)
	{
		return nullptr;
	}

	// 新しいアニメーションモデルの名前を登録し、使用されている数を加算
	m_this.mpr_variable.animation_model_inform_list[animation_model_slot_num].name = in_load_animation_model_name;
	m_this.mpr_variable.animation_model_inform_list[animation_model_slot_num].user_sum = 1;

	// 生成したアニメーションモデルを返す
	return m_this.mpr_variable.animation_model_inform_list[animation_model_slot_num].animation_model.get();
}


//-☆- 削除 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたアニメーションモデルの所有権を放棄することを通知する
// 引数   ：C_3D_Animation_Model_System * & 所有権を放棄するアニメーションモデルのアドレスの参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_3D_Animation_Model_Manager::M_Release_Animation_Model(ASSET::ANIMATION_MODEL::C_3D_Animation_Model_System * & in_animation_model)
{
	// アニメーションモデル設定名から指定された3Dモデル設定を探して、見つかったら所有されている数のカウントを減らして参照できなくする
	for (S_3D_Animation_Model_Manage_Inform & now_animation_model_inform : m_this.mpr_variable.animation_model_inform_list)
	{
		if (now_animation_model_inform.animation_model.get() == in_animation_model)
		{
			in_animation_model = nullptr;
			now_animation_model_inform.user_sum -= 1;


			// このアニメーションモデル設定が使われなくなったら削除する
			m_this.mpr_variable.animation_model_inform_list.erase
			(
				std::remove_if
				(
					m_this.mpr_variable.animation_model_inform_list.begin(),
					m_this.mpr_variable.animation_model_inform_list.end(),

					// 残りの数が0になると削除するラムダ式
					[](S_3D_Animation_Model_Manage_Inform & in_animation_model_setting)->bool
					{
						if (in_animation_model_setting.user_sum < 1)
						{
							in_animation_model_setting.animation_model.reset();

							return true;
						}

						return false;
					}
				),
				m_this.mpr_variable.animation_model_inform_list.end()
			);

			return;
		}
	}

	return;
}
