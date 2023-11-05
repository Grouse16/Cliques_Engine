//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：マテリアルのクラス、描画時の描画方法の設定を行う
// 説明   ：バッファの管理やレンダリング設定の管理を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Material.h"
#include "C_Rendering_Graphics_API_Base.h"


// デバッグ時のみログシステムを使用
#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::MATERIAL;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：スロットの情報をセットする
// 引数   ：const S_All_Shader_Resource_Signatures & 設定するスロット識別用の情報
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Material::M_Load_Blend_Setting(std::vector<RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform::S_Blend_Setting_Create_Data>&, SYSTEM::TEXT::C_Text_And_File_Manager&)
{

	return;
}


//-☆- 生成 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：スロットの情報をセットする
// 引数   ：const S_All_Shader_Resource_Signatures & 設定するスロット識別用の情報
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Material::M_Create_Resource_By_Signature_Inform(const ASSET::SHADER::S_All_Shader_Resource_Signatures& in_resource_signature)
{
	// ☆ 変数宣言 ☆ //
	int now_index_number = 0;			// 現在操作中のインデックススロット番号
	int now_constant_index_number = 0;	// 現在操作中の定数バッファ
	int now_texture_index_number = 0;	// 現在操作中のテクスチャスロット


	//-☆- リソースの生成 -☆-//

	//--☆ 全シェーダーに共通するスロットを設定 -☆-//

	// 定義数分の定数バッファを作り、情報を設定する
	mpr_variable.constant_data_list.resize(in_resource_signature.all_shader_signature.constant_data.size());
	for (const ASSET::SHADER::S_Resource_Signature& now_constant_inform : in_resource_signature.all_shader_signature.constant_data)
	{
		mpr_variable.constant_data_list[now_constant_index_number].index = now_index_number;
		mpr_variable.constant_data_list[now_constant_index_number].signature_name = now_constant_inform.signature_name;

		now_constant_index_number += 1;
		now_index_number += 1;
	}

	// テクスチャ数分のスロットを作る
	mpr_variable.texture_data_list.resize(in_resource_signature.all_shader_signature.texture_data.size());
	for (const ASSET::SHADER::S_Resource_Signature& now_texture_inform : in_resource_signature.all_shader_signature.texture_data)
	{
		mpr_variable.texture_data_list[now_texture_index_number].index = now_index_number;
		mpr_variable.texture_data_list[now_texture_index_number].signature_name = now_texture_inform.signature_name;

		now_texture_index_number += 1;
		now_index_number += 1;
	}

	//--☆ 各シェーダーごとのスロットを設定 -☆-//
	for (int l_now_shader_number = 0; l_now_shader_number < (int)ASSET::SHADER::E_SHADER_KIND::e_ALL; l_now_shader_number++)
	{
		// 定義数分の定数バッファを作り、情報を設定する
		mpr_variable.constant_data_list.resize(in_resource_signature.signature_list[l_now_shader_number].constant_data.size());
		for (const ASSET::SHADER::S_Resource_Signature& now_constant_inform : in_resource_signature.signature_list[l_now_shader_number].constant_data)
		{
			mpr_variable.constant_data_list[now_constant_index_number].index = now_index_number;
			mpr_variable.constant_data_list[now_constant_index_number].signature_name = now_constant_inform.signature_name;

			now_constant_index_number += 1;
			now_index_number += 1;
		}

		// テクスチャ数分のスロットを作る
		mpr_variable.texture_data_list.resize(in_resource_signature.signature_list[l_now_shader_number].texture_data.size());
		for (const ASSET::SHADER::S_Resource_Signature& now_texture_inform : in_resource_signature.signature_list[l_now_shader_number].texture_data)
		{
			mpr_variable.texture_data_list[now_texture_index_number].index = now_index_number;
			mpr_variable.texture_data_list[now_texture_index_number].signature_name = now_texture_inform.signature_name;

			now_texture_index_number += 1;
			now_index_number += 1;
		}
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリング情報を生成する
// 引数   ：C_Text_And_File_Manager & 現在のファイル文字列
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Material::M_Create_Rendering_Setting(SYSTEM::TEXT::C_Text_And_File_Manager & in_file_text)
{
	// ☆ 変数宣言 ☆ //
	RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform rendering_setting_create_inform;	// レンダリング設定の生成用の情報


	// シェーダーをセットする
	rendering_setting_create_inform.shader_setting = &mpr_variable.shader_setting_data;

	// ブレンドの設定を読み込む

	

	// レンダリング設定を生成する
	return mpr_variable.rendering_setting.M_Create_Pipeline_Setting();
}


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
		now_constant_buffer.data->M_Release();
		now_constant_buffer.data.reset();
	}
	mpr_variable.constant_data_list.clear();
	mpr_variable.constant_data_list.shrink_to_fit();

	// テクスチャ
	for (S_Texture_Buffer_Data & now_texture_buffer : mpr_variable.texture_data_list)
	{
		now_texture_buffer.data.M_Release();
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


	// 指定されたファイルのロードを行う　エラーで終了する
	if (material_inform_file_data.M_Load_Select_File(in_material_path) == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR, "指定されたマテリアルのファイルはありません");
#endif // _DEBUG

		return false;
	}

	// マテリアルに使用するシェーダー設定名をがある位置へ移動　失敗でエラーを出して抜ける
	if (material_inform_file_data.M_Goto_Right_By_Text_In_Front_Sentence("Shader：") == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR, "マテリアルの情報にシェーダーのデータが設定されていません");
#endif // _DEBUG

		return false;
	}
	

	// シェーダー設定名からシェーダーを設定をロードする　失敗でエラーを出して抜ける
	if (mpr_variable.shader_setting_data.M_Load_Shaders_Inform_By_Shader_Setting_Name(material_inform_file_data.M_Get_Data_Right_In_Row()) == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR, "このシェーダー設定は無効です。存在しないファイルか設定が正しくない可能性があります");
#endif // _DEBUG

		return false;
	}


	// シェーダー設定のリソースの情報をもとにリソースを生成する
	M_Create_Resource_By_Signature_Inform(mpr_variable.shader_setting_data.M_Get_Resource_Signature());


	// レンダリング設定を生成する、失敗でエラーを出して抜ける
	if (M_Create_Rendering_Setting(material_inform_file_data) == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR, "レンダリング設定の生成に失敗しました");
#endif // _DEBUG

		return false;
	}


	// デバッグ時は生成に成功したことを記録する
#ifdef _DEBUG
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_INIT, "マテリアルの生成に成功しました");
#endif // _DEBUG
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
		now_constant_buffer.data->M_Set_Constant_Buffer_To_GPU_By_Index(now_constant_buffer.index);
	}

	// テクスチャバッファを一つづつ適用する
	for (S_Texture_Buffer_Data & now_texture_buffer : mpr_variable.texture_data_list)
	{
		now_texture_buffer.data.M_Texture_Attach_To_Draw(now_texture_buffer.index);
	}

	return;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたスロットにテクスチャをロードする
// 引数   ：int テクスチャスロット番号, string ロードするテクスチャ名
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Material::M_Load_Texture_For_Slot_By_Index(int in_index, std::string in_load_texture_name)
{
	// 配列外を指定されたら抜ける
	if (mpr_variable.texture_data_list.size() <= in_index)
	{
		return;
	}

	mpr_variable.texture_data_list[in_index].data.M_Load_Texture(in_load_texture_name);

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された定数バッファ管理用データを返す
// 引数   ：int 取得する定数バッファ管理用データの番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const S_Constant_Buffer_Data & C_Material::M_Get_Constant_Buffer_Data_By_Index(int in_index)
{
	return mpr_variable.constant_data_list[in_index];
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたテクスチャ管理用データを返す
// 引数   ：int 取得するテクスチャ管理用データの番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const S_Texture_Buffer_Data & C_Material::M_Get_Texture_Data_By_Index(int in_index)
{
	return mpr_variable.texture_data_list[in_index];
}



