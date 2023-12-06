//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：テクスチャデータの情報を円滑に設定し、レンダリングするためのシステム
// 説明   ：テクスチャデータのレンダリングをカプセル化する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Texture_Data_System.h"
#include "C_Rendering_Graphics_API_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::CAPSULE;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Texture_Data_System::C_Texture_Data_System(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Texture_Data_System::~C_Texture_Data_System(void)
{
	M_Delete();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリの解放を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Data_System::M_Delete(void)
{
	mpr_variable.texture_setting_inform.reset();
	mpr_variable.texture_map.M_Delete_Map();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャマップのみ解放する（バッファは残る）
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Data_System::M_Delete_Map(void)
{
	mpr_variable.texture_map.M_Delete_Map();

	return;
}


//-☆- リセット -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャマップのみ解放する（バッファは残る）
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Data_System::M_Reset_Texture(void)
{
	// ☆ 変数宣言 ☆ //
	DATA::COLOR::C_Color reset_color(255, 0, 255, 255);	// リセット用の色


	// テクスチャを生成し初期化色を設定
	M_Create_Texture_Data(10, 10);
	mpr_variable.texture_map.M_Flush_All_Color(reset_color);

	return;
}


//-☆- 生成 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャデータを生成する
// 引数   ：int テクスチャの横サイズ, int テクスチャの縦サイズ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Data_System::M_Create_Texture_Data(int in_tex_width, int in_tex_height)
{
	// マイナス時は生成できないのでエラーで抜ける
	if (in_tex_width <= 0 || in_tex_height <= 0)
	{
		return;
	}


	// ☆ 変数宣言 ☆ //
	RENDERING::GRAPHICS::CREATE::S_Create_Texture_Setting_Inform create_inform;	// 生成用情報


	// 生成用の情報を設定して、生成する
	create_inform.pixel_width = in_tex_width;
	create_inform.pixel_height = in_tex_height;
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Create_Texture_Inform(mpr_variable.texture_setting_inform, create_inform);


	// マップを指定されたピクセル数分生成する
	mpr_variable.texture_map.M_Create_Texture_Map(in_tex_width, in_tex_height);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャマップに合わせて、テクスチャのリソースを生成する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Data_System::M_Create_Texture_Resource_By_Texture_Map(void)
{
	// ☆ 変数宣言 ☆ //
	RENDERING::GRAPHICS::CREATE::S_Create_Texture_Setting_Inform create_inform;	// 生成用情報


	// 生成用の情報を設定して、生成する
	create_inform.pixel_width = mpr_variable.texture_map.M_Get_Width_Size();
	create_inform.pixel_height = mpr_variable.texture_map.M_Get_Height_Size();
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Create_Texture_Inform(mpr_variable.texture_setting_inform, create_inform);
	M_Texture_Map_To_Texture_Resource_Data();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャをロードしたデータを元に生成する
// 引数   ：string テクスチャのパス
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Texture_Data_System::M_Create_Texture_By_Load_Texture_File(std::string in_tex_file_path)
{
	// テクスチャをロードしてテクスチャマップを作る　エラーで抜ける
	if (RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Load_Texture(in_tex_file_path, mpr_variable.texture_map) == false)
	{
		return false;
	}


	// ☆ 変数宣言 ☆ //
	RENDERING::GRAPHICS::CREATE::S_Create_Texture_Setting_Inform create_inform;	// 生成用情報


	// 生成用の情報を設定して、生成する
	create_inform.pixel_width = mpr_variable.texture_map.M_Get_Width_Size();
	create_inform.pixel_height = mpr_variable.texture_map.M_Get_Height_Size();
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Create_Texture_Inform(mpr_variable.texture_setting_inform, create_inform);


	// 生成したテクスチャ用のバッファにテクスチャマップを適用する
	M_Texture_Map_To_Texture_Resource_Data();

	return true;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：データの識別名をセットする
// 引数   ：string セットする文字列
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Data_System::M_Set_Data_Signature_Name(std::string in_set_name)
{
	mpr_variable.data_signature_name.clear();
	mpr_variable.data_signature_name = in_set_name;
	mpr_variable.data_signature_name.shrink_to_fit();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャデータ設定先のシェーダーの種類を変更する
// 引数   ：E_SHADER_KIND 設定先のシェーダーの種類
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Data_System::M_Set_Attach_Shader_Kind(ASSET::SHADER::E_SHADER_KIND in_set_shader_kind)
{
	mpr_variable.attach_shader = in_set_shader_kind;

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：データの識別名を返す
// 引数   ：void
// 戻り値 ：const string & 現在のデータ識別名の参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const std::string & C_Texture_Data_System::M_Get_Data_Signature_Name(void)
{
	return mpr_variable.data_signature_name;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャデータ設定先のシェーダーの種類を返す
// 引数   ：void
// 戻り値 ：E_SHADER_KIND 設定先のシェーダーの種類
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
ASSET::SHADER::E_SHADER_KIND C_Texture_Data_System::M_Get_Attach_Shader_Kind(void)
{
	return mpr_variable.attach_shader;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャマップの参照を返す
// 引数   ：void
// 戻り値 ：DATA::TEXTURE::C_Texture_Map & テクスチャマップの参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
ASSET::TEXTURE::C_Texture_Map & C_Texture_Data_System::M_Get_Texture_Map(void)
{
	return mpr_variable.texture_map;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャマップのデータをテクスチャとしてセットする
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Data_System::M_Texture_Map_To_Texture_Resource_Data(void)
{
	mpr_variable.texture_setting_inform->M_Set_Texture_Data(mpr_variable.texture_map.M_Get_Texture_Map(), mpr_variable.texture_map.M_Get_Width_Size(), mpr_variable.texture_map.M_Get_Height_Size());

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャ情報をGPUに渡す
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Data_System::M_Attach_To_Shader(void)
{
	// ☆ 変数宣言 ☆ //
	RENDERING::GRAPHICS::INSTANCE::S_Texture_Buffer_Drawing_Setting drawing_setting;	// 描画用設定


	// 描画用情報を設定して描画する
	drawing_setting.add_texture_data = mpr_variable.texture_setting_inform.get();
	drawing_setting.attach_shader_kind = mpr_variable.attach_shader;
	drawing_setting.add_signature_name = &mpr_variable.data_signature_name;
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Rendering_Set_Texture(drawing_setting);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャ情報を指定されたインデックスに設定し、GPUに渡す
// 引数   ：int インデックス番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Texture_Data_System::M_Attach_To_Shader_By_Index(int in_index)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Rendering_Set_Texture_By_Index(mpr_variable.texture_setting_inform, in_index);

	return;
}


