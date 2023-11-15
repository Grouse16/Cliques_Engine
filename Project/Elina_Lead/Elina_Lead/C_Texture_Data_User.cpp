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
	mpr_variable.texture_data.reset(ASSET::TEXTURE::MANAGER::C_Texture_Manager::M_Get_Reset_Texture());

	// オリジナルのテクスチャではないことを示す
	mpr_variable.flg_original_texture = false;

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
	if (mpr_variable.texture_data.get() == ASSET::TEXTURE::MANAGER::C_Texture_Manager::M_Get_Reset_Texture())
	{
		return;
	}


	// オリジナルのテクスチャなら、メモリを解放しリセット用テクスチャと入れ替える
	if (mpr_variable.flg_original_texture)
	{
		mpr_variable.texture_data->M_Delete();
		mpr_variable.texture_data.reset(ASSET::TEXTURE::MANAGER::C_Texture_Manager::M_Get_Reset_Texture());
	}

	// ロードしたテクスチャなら問い合わせして削除　ロードしたテクスチャだった場合はリセット用テクスチャになって返ってくる
	else
	{
		ASSET::TEXTURE::MANAGER::C_Texture_Manager::M_Release_Texture(mpr_variable.texture_data);
	}

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
	M_Release();
	mpr_variable.texture_data.release();
	mpr_variable.texture_data.reset(get_texture);

	// オリジナルのテクスチャではないことを示す
	mpr_variable.flg_original_texture = false;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：オリジナルのテクスチャデータを生成する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Data_User::M_Create_Original_Texture_Data(void)
{
	// 以前までのテクスチャを解放する
	M_Release();

	// 独自のデータをロード
	mpr_variable.texture_data.release();
	mpr_variable.texture_data.reset(new RENDERING::CAPSULE::C_Texture_Data_System());

	// オリジナルのテクスチャであることを示す
	mpr_variable.flg_original_texture = true;

	return;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：このテクスチャを描画用情報（識別名,シェーダーの種類）を元にGPUにセットする
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Data_User::M_Texture_Attach_To_Draw_By_Inform(void)
{
	mpr_variable.texture_data->M_Set_Attach_Shader_Kind(mpr_variable.shader_kind);
	mpr_variable.texture_data->M_Set_Data_Signature_Name(mpr_variable.signature_name);
	mpr_variable.texture_data->M_Attach_To_Shader();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：このテクスチャを描画用にセットする
// 引数   ：int 設定先のインデックス番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Data_User::M_Texture_Attach_To_Draw_By_Index(int in_index_number)
{
	mpr_variable.texture_data->M_Attach_To_Shader_By_Index(in_index_number);

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャデータのアドレスを返す
// 引数   ：void
// 戻り値 ：C_Texture_Data_System * テクスチャデータのアドレス
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
RENDERING::CAPSULE::C_Texture_Data_System * C_Texture_Data_User::M_Get_Texture_Data(void)
{
	return mpr_variable.texture_data.get();
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャの識別名をセットする
// 引数   ：string テクスチャ識別名
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Data_User::M_Set_Texture_Signature(std::string in_set_signature_name)
{
	mpr_variable.signature_name = in_set_signature_name;

	return;
}

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シェーダーの種類をセットする
// 引数   ：E_SHADER_KIND シェーダーの種類
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Data_User::M_Set_Texture_Shader_Kind(ASSET::SHADER::E_SHADER_KIND in_set_shader_kind)
{
	mpr_variable.shader_kind = in_set_shader_kind;

	return;
}
