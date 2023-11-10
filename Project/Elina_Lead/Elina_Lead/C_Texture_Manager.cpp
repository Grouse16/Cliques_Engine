//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：テクスチャを制御するためのシステム
// 説明   ：テクスチャのロードや解放を行ったり、重複して同じテクスチャをロードしないように管理する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Texture_Manager.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::TEXTURE::MANAGER;


// ☆ スタティック変数 ☆ //
C_Texture_Manager C_Texture_Manager::m_this;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Texture_Manager::C_Texture_Manager(void)
{
	return;
}


//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャ制御用のシステムを初期化する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Manager::M_Init(void)
{
	m_this.mpr_variable.reset_texture.M_Reset_Texture();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Texture_Manager::~C_Texture_Manager(void)
{
	M_Release();

	mpr_variable.reset_texture.M_Delete();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリを解放する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Manager::M_Release(void)
{
	for (S_Texture_Manage_Inform & now_texture : m_this.mpr_variable.texture_list)
	{
		now_texture.texture.reset();
	}

	m_this.mpr_variable.texture_list.clear();
	m_this.mpr_variable.texture_list.shrink_to_fit();

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のテクスチャを返す
// 引数   ：string テクスチャの名前
// 戻り値 ：C_Texture_Data_System * 指定されたテクスチャへのアドレス、なければnullptrを返す
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
RENDERING::CAPSULE::C_Texture_Data_System * C_Texture_Manager::M_Get_Texture_By_Name(std::string in_texture_name)
{
	// テクスチャ名から指定されたテクスチャを探して、見つかったらそれを返す
	for (S_Texture_Manage_Inform & now_texture_inform : m_this.mpr_variable.texture_list)
	{
		if (now_texture_inform.name == in_texture_name)
		{
			now_texture_inform.user_sum += 1;
			return now_texture_inform.texture.get();
		}
	}

	// 見つからなかった
	return nullptr;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャ名からテクスチャをロードする
// 引数   ：string テクスチャ名
// 戻り値 ：C_Texture_Data_System * 生成したテクスチャへのアドレス、なければnullptrを返す
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
RENDERING::CAPSULE::C_Texture_Data_System * C_Texture_Manager::M_Load_Texture_By_Name(std::string in_texture_name)
{
	// ☆ 定数 ☆ //
	std::string texture_inform_path = "project/asset/texture/" + in_texture_name;	// テクスチャ情報へのパス

	int texture_slot_num = m_this.mpr_variable.texture_list.size();	// 操作するテクスチャの番号


	// 新しいテクスチャ設定用のスロットを生成
	m_this.mpr_variable.texture_list.resize(texture_slot_num + 1);
	m_this.mpr_variable.texture_list[texture_slot_num].texture.reset(new RENDERING::CAPSULE::C_Texture_Data_System());

	// テクスチャ情報からテクスチャをロードする、できなければfalseを返す
	if (m_this.mpr_variable.texture_list[texture_slot_num].texture->M_Create_Texture_By_Load_Texture_File(texture_inform_path) == false)
	{
		return nullptr;
	}

	// 新しいテクスチャの名前を登録し、使用されている数を加算
	m_this.mpr_variable.texture_list[texture_slot_num].name = in_texture_name;
	m_this.mpr_variable.texture_list[texture_slot_num].user_sum = 1;

	// ここではテクスチャマップは使用しないので削除
	m_this.mpr_variable.texture_list[texture_slot_num].texture->M_Delete_Map();

	// 生成したテクスチャを返す
	return m_this.mpr_variable.texture_list[texture_slot_num].texture.get();
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：リセット用のテクスチャを返す
// 引数   ：void
// 戻り値 ：C_Texture_Data_System * テクスチャ情報リセット時のテクスチャの参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
RENDERING::CAPSULE::C_Texture_Data_System * C_Texture_Manager::M_Get_Reset_Texture(void)
{
	return &m_this.mpr_variable.reset_texture;
}


//-☆- 削除 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたテクスチャ設定の所有権を放棄することを通知する
// 引数   ：C_Texture_Data_System * & 所有権を放棄するシェーダー設定のアドレスの参照（const）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Manager::M_Release_Texture(RENDERING::CAPSULE::C_Texture_Data_System * & in_release_texture_address)
{
	// テクスチャ名から指定されたテクスチャを探して、見つかったら所有されている数のカウントを減らして参照できなくする
	for (S_Texture_Manage_Inform & now_texture_inform : m_this.mpr_variable.texture_list)
	{
		if (now_texture_inform.texture.get() == in_release_texture_address)
		{
			in_release_texture_address = &m_this.mpr_variable.reset_texture;
			now_texture_inform.user_sum -= 1;


			// このテクスチャが使われなくなったら削除する
			m_this.mpr_variable.texture_list.erase
			(
				std::remove_if
				(
					m_this.mpr_variable.texture_list.begin(),
					m_this.mpr_variable.texture_list.end(),

					// 残りの数が0になると削除するラムダ式
					[](S_Texture_Manage_Inform & in_texture)->bool
					{
						if (in_texture.user_sum < 1)
						{
							in_texture.texture.reset();

							return true;
						}

						return false;
					}
				),
				m_this.mpr_variable.texture_list.end()
			);

			return;
		}
	}

	return;
}



