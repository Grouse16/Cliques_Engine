//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：テクスチャデータの情報を円滑に設定し、レンダリングするためのシステム
// 説明   ：テクスチャデータのレンダリングをカプセル化する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Texture_Manager.h"
#include "C_Texture_Data_User.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::TEXTURE;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Texture_Data_User::C_Texture_Data_User(void)
{
	// 初期のテクスチャを取得する
	mpr_variable.texture_data = ASSET::TEXTURE::MANAGER::C_Texture_Manager::M_Get_Reset_Texture();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Texture_Data_User::~C_Texture_Data_User(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャを解放する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Data_User::M_Release(void)
{
	// テクスチャをもっていないなら解放はしない（リセット用のテクスチャの時）
	if (mpr_variable.texture_data == ASSET::TEXTURE::MANAGER::C_Texture_Manager::M_Get_Reset_Texture())
	{
		return;
	}

	ASSET::TEXTURE::MANAGER::C_Texture_Manager::M_Release_Texture(mpr_variable.texture_data);

	return;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のテクスチャを読み込む
// 引数   ：string テクスチャ名
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Data_User::M_Load_Texture(std::string in_texture_name)
{
	// ☆ 変数宣言 ☆ //
	RENDERING::CAPSULE::C_Texture_Data_System * get_texture = nullptr;	// 入手したテクスチャデータ


	// テクスチャ名からテクスチャを取得する
	get_texture = ASSET::TEXTURE::MANAGER::C_Texture_Manager::M_Get_Texture_By_Name(in_texture_name);


	// テクスチャがまだ生成されていないならロードする
	if (get_texture == nullptr)
	{
		get_texture = ASSET::TEXTURE::MANAGER::C_Texture_Manager::M_Load_Texture_By_Name(in_texture_name);

		// 生成にも失敗したら抜ける
		if (get_texture == nullptr)
		{
			return;
		}
	}

	// 取得したテクスチャを所持する
	mpr_variable.texture_data = get_texture;

	return;
}



//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：このテクスチャを描画用にセットする
// 引数   ：int 設定先のインデックス番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Data_User::M_Texture_Attach_To_Draw(int in_index_number)
{
	mpr_variable.texture_data->M_Attach_To_Shader_By_Index(in_index_number);

	return;
}
