//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：マテリアルのクラス、描画時の描画方法の設定を行う
// 説明   ：バッファの管理やレンダリング設定の管理を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Log_System.h"
#include "C_Material.h"
#include "C_Rendering_Graphics_API_Base.h"
#include "C_Text_And_File_Manager.h"


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
C_Material::C_Material(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Material::~C_Material(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリ解放
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Material::M_Release(void)
{
	// 描画用設定
	mpr_variable.rendering_setting.M_Delete();

	// 定数バッファ
	for (S_Constant_Buffer_Data & now_constant_buffer : mpr_variable.constant_data_list)
	{
		now_constant_buffer.data.M_Release();
	}
	mpr_variable.constant_data_list.clear();
	mpr_variable.constant_data_list.shrink_to_fit();

	// テクスチャ
	for (S_Texture_Buffer_Data & now_texture_buffer : mpr_variable.texture_data_list)
	{
		now_texture_buffer.data->M_Delete();
	}
	mpr_variable.texture_data_list.clear();
	mpr_variable.texture_data_list.shrink_to_fit();

	return;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：マテリアルデータへのパスからマテリアル情報をロード
// 引数   ：string マテリアルデータへのパス
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Material::M_Load_Material_By_Path(std::string in_material_path)
{
	// ☆ 変数宣言 ☆ //
	SYSTEM::TEXT::C_Text_And_File_Manager material_inform_file_data;	// マテリアル情報のファイルのデータ

	mpr_variable.constant_data_list.size();	// 


	// 指定されたファイルのロードを行う　エラーで終了する
	if (material_inform_file_data.M_Load_Select_File(in_material_path) == false)
	{
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "指定されたマテリアルのファイルはありません");

		return false;
	}

	// マテリアルに使用するシェーダー設定名を取得する
	material_inform_file_data.M_Goto_Right_By_Text_In_Front_Sentence("Shader：");
	mpr_variable.shader_setting_data.M_Load_Shaders_Inform_By_Shader_Setting_Name(material_inform_file_data.M_Get_Data_Right_In_Row());


	// 定数バッファを設定する


	return true;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリング用の情報をGPUに設定する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Material::M_Attach_To_GPU(void)
{
	// レンダリング設定を適用
	mpr_variable.rendering_setting.M_Set_Rendering_Setting_For_API();

	// 定数バッファを一つづつ適用する
	for (S_Constant_Buffer_Data & now_constant_buffer : mpr_variable.constant_data_list)
	{
		now_constant_buffer.data.M_Set_Constant_Buffer_To_GPU_By_Index(now_constant_buffer.index);
	}

	// テクスチャバッファを一つづつ適用する
	for (S_Texture_Buffer_Data & now_texture_buffer : mpr_variable.texture_data_list)
	{
		now_texture_buffer.data->M_Attach_To_Shader_By_Index(now_texture_buffer.index);
	}

	return;
}



