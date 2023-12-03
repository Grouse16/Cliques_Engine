//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：一組のシェーダーの設定をまとめるためのクラス
// 説明   ：シェーダーをバラバラに設定する必要をなくす、カプセル化
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Shader_Setting.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::SHADER;


// ☆ クラス ☆ //

// データと名前を関連付けるための構造体
class C_Store_Data
{
	//==☆ パブリック ☆==//
public:

	// ☆ 変数宣言 ☆ //
	std::string name = "default";	// 名前

	int & data;	// データ


	// ☆ 関数 ☆ //

	//-☆- 初期化と終了時 -☆-//
	C_Store_Data(int& in_data, std::string in_set_name) : data(in_data)
	{
		name = in_set_name;

		return;
	}
};


// ☆ 関数 ☆ //

//==☆　プライベート ☆==//

//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点レイアウトをロードする
// 引数   ：C_Text_And_File_Manager & シェーダー情報ファイルのデータ
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Shader_Setting::M_Load_Vertex_Layout(SYSTEM::TEXT::C_Text_And_File_Manager & in_shader_data_file)
{
	// ☆ 変数宣言 ☆ //
	int vertex_layout_sum = 0;	// 頂点レイアウト数


	// 頂点レイアウトの位置に移動する、なければエラー
	in_shader_data_file.M_Goto_Sentence_Start();
	if (in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row("VERTEXLAYOUT=") == false)
	{
		return false;
	}


	// 頂点レイアウト数を取得
	in_shader_data_file.M_Move_Next_Raw();
	vertex_layout_sum = in_shader_data_file.M_Get_Number();


	// 頂点レイアウトを設定する
	mpr_variable.vertex_layout_setting.resize(vertex_layout_sum);
	for (int layout_number = 0; layout_number < vertex_layout_sum; layout_number++)
	{
		// ☆ 変数宣言 ☆ //
		std::string get_text;		// 取得した識別用の文字列
		

		// 現在の番号の頂点レイアウト情報の最初に移動
		in_shader_data_file.M_Move_Next_Raw();


		// ビットサイズの文字列を取得
		get_text = in_shader_data_file.M_Get_Data_By_Text(",");

		// 1バイト
		if (get_text == "1")
		{
			mpr_variable.vertex_layout_setting[layout_number].size = DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT;
		}
		// 2バイト
		else if (get_text == "2")
		{
			mpr_variable.vertex_layout_setting[layout_number].size = DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_2BYTE_16BIT;
		}
		// 4バイト
		else if(get_text == "4")
		{
			mpr_variable.vertex_layout_setting[layout_number].size = DATA::INPUTLAYOUT::E_INPUT_DATA_BITSIZE::e_4BYTE_32BIT;
		}
		// 指定する文字が誤っているならエラー
		else
		{
#ifdef _DEBUG
			DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::C_Log_System::M_Print_Log
			(
				DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP,
				DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR,
				"この頂点レイアウトは無効です　" + in_shader_data_file.M_Get_File_Path_Refer() + "：バイト数" + get_text
			);
			DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

			return false;
		}


		// データ形式を取得
		in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row(",");
		get_text = in_shader_data_file.M_Get_Data_By_Text(",");

		// float型
		if (get_text == "FLOAT")
		{
			mpr_variable.vertex_layout_setting[layout_number].format = DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_FLOAT;
		}
		// unsigned int型
		else if (get_text == "UINT")
		{
			mpr_variable.vertex_layout_setting[layout_number].format = DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_UINT;
		}
		// int型
		else if(get_text == "INT")
		{
			mpr_variable.vertex_layout_setting[layout_number].format = DATA::INPUTLAYOUT::E_INPUT_DATA_FORMAT::e_INT;
		}
		// 型が正しく指定されていないならエラー
		else
		{
#ifdef _DEBUG
			DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::C_Log_System::M_Print_Log
			(
				DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP,
				DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR,
				"この頂点レイアウトは無効です　" + in_shader_data_file.M_Get_File_Path_Refer() + "：フォーマット" + get_text
			);
			DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

			return false;
		}

		// データ形式を取得
		in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row(",");
		get_text = in_shader_data_file.M_Get_Data_By_Text(",");

		// 変数は１つ　ｘ
		if (get_text == "1")
		{
			mpr_variable.vertex_layout_setting[layout_number].sum = DATA::INPUTLAYOUT::E_INPUT_DATA_PARAMATOR_SUM::e_1;
		}
		// 変数は２つ　ｘ,y
		else if (get_text == "2")
		{
			mpr_variable.vertex_layout_setting[layout_number].sum = DATA::INPUTLAYOUT::E_INPUT_DATA_PARAMATOR_SUM::e_2;
		}
		// 変数は３つ　ｘ,y,z
		else if (get_text == "3")
		{
			mpr_variable.vertex_layout_setting[layout_number].sum = DATA::INPUTLAYOUT::E_INPUT_DATA_PARAMATOR_SUM::e_2;
		}
		// 変数は４つ　ｘ,y,z,w
		else if (get_text == "4")
		{
			mpr_variable.vertex_layout_setting[layout_number].sum = DATA::INPUTLAYOUT::E_INPUT_DATA_PARAMATOR_SUM::e_4;
		}
		// 変数の数が無効ならエラー
		else
		{
#ifdef _DEBUG
			DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::C_Log_System::M_Print_Log
			(
				DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP,
				DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR,
				"この頂点レイアウトは無効です　" + in_shader_data_file.M_Get_File_Path_Refer() + "：変数の数　x,y,z,w" + get_text
			);
			DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

			return false;
		}
	}

	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シェーダーのリソースをロードした情報から設定する
// 引数   ：string シェーダーの種類名, C_Text_And_File_Manager & シェーダー情報ファイルのデータ
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Shader_Setting::M_Load_Shader_Resource_Signature(std::string in_shader_kind_name, SYSTEM::TEXT::C_Text_And_File_Manager& in_shader_data_file)
{
	// シェーダーの情報の開始位置を探す、なければエラー
	in_shader_data_file.M_Goto_Sentence_Start();
	if (in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row(in_shader_kind_name + "START:") == false)
	{
		return false;
	}


	// ☆ 変数宣言 ☆ //
	int constant_sum = 0;	// 定数の数
	int texture_sum = 0;	// テキストの数
	int sampler_sum = 0;	// サンプラーの数


	// 定数バッファ数を取得
	in_shader_data_file.M_Move_Next_Raw();
	constant_sum = in_shader_data_file.M_Get_Number();

	// テキスト数を取得
	in_shader_data_file.M_Move_Next_Raw();
	texture_sum = in_shader_data_file.M_Get_Number();

	// サンプラー数を取得
	in_shader_data_file.M_Move_Next_Raw();
	sampler_sum = in_shader_data_file.M_Get_Number();


	// 取得した数分リソースの識別を生成
	mpr_variable.resource_signature.all_shader_signature.constant_data.resize(constant_sum);
	mpr_variable.resource_signature.all_shader_signature.texture_data.resize(texture_sum);
	mpr_variable.resource_signature.all_shader_signature.sampler_data.resize(sampler_sum);


	// 定数バッファの識別名の行に移動
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(in_shader_kind_name + "CON:");

	// 定数バッファの情報を取得
	for (ASSET::SHADER::S_Constant_Resource_Signature & now_constant_data : mpr_variable.resource_signature.all_shader_signature.constant_data)
	{
		// 次の行に移動
		in_shader_data_file.M_Move_Next_Raw();

		// 識別名を取得
		now_constant_data.signature_name = in_shader_data_file.M_Get_Data_By_Text(",");

		// 配列数を取得
		in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(",");
		now_constant_data.array_sum = in_shader_data_file.M_Get_Number();

		// データを生成するかどうかのフラグを取得
		in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(",");
		now_constant_data.data_create_flg = in_shader_data_file.M_Get_Data_By_Text(",") == "TRUE";

		// 配列数が０なら少なくとも一つは確保する
		now_constant_data.array_sum =
			(now_constant_data.array_sum <= 0)
			+
			(now_constant_data.array_sum > 0) * now_constant_data.array_sum;
	}


	// テクスチャの識別名と数の行に移動
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(in_shader_kind_name + "TEX:");

	// テクスチャの識別名を取得する
	for (ASSET::SHADER::S_Texture_Resource_Signature & now_texture_data : mpr_variable.resource_signature.all_shader_signature.texture_data)
	{
		// 次の行に移動
		in_shader_data_file.M_Move_Next_Raw();

		// 識別名を取得
		in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(",");

		// 初期ロードする時のテクスチャの動作を取得
		now_texture_data.signature_name = in_shader_data_file.M_Get_Data_By_Text(",");
		now_texture_data.initialized_texture_name = in_shader_data_file.M_Get_Data_By_Text(",");
	}


	// サンプラーの識別名と数の行に移動
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(in_shader_kind_name + "SAM:");

	// サンプラーの識別名を取得する
	for (ASSET::SHADER::S_Sampler_Resource_Signature & now_sampler_data : mpr_variable.resource_signature.all_shader_signature.sampler_data)
	{
		// 次の行に移動
		in_shader_data_file.M_Move_Next_Raw();

		// UVの使用方法を取得
		now_sampler_data.uv_setting = in_shader_data_file.M_Get_Data_By_Text(",");
	}
	
	// 成功
	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：各種シェーダーのロードとリソースの定義を行う
// 引数   ：C_Text_And_File_Manager & シェーダー情報ファイルのデータ
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Shader_Setting::M_Load_Shaders_And_Setting_Resource_Signature(SYSTEM::TEXT::C_Text_And_File_Manager & in_shader_data_file)
{
	// 全てのシェーダーに共通する設定をロード
	M_Load_Shader_Resource_Signature("AS", in_shader_data_file);

	// 各種シェーダーの情報を読み取りコンパイル結果を取得
	for (int now_shader_kind = 0; now_shader_kind < (int)ASSET::SHADER::E_SHADER_KIND::e_ALL; now_shader_kind++)
	{
		if (M_Load_Shader_And_Setting_Resource_Signature(in_shader_data_file, now_shader_kind) == false)
		{
			return false;
		}
	}

	// 成功
	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：一種類分のシェーダーロードを行う処理
// 引数   ：C_Text_And_File_Manager & シェーダー情報ファイルのデータ, int シェーダーの種類
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Shader_Setting::M_Load_Shader_And_Setting_Resource_Signature(SYSTEM::TEXT::C_Text_And_File_Manager & in_shader_data_file, int in_shader_kind)
{
	// ☆ 変数宣言 ☆ //
	std::string shader_type_text;	// シェーダータイプの文字列

	E_SHADER_KIND shader_kind = E_SHADER_KIND::e_VERTEX;	// 使用するシェーダーの種類


	// ☆ シェーダーの種類ごとに識別に使用する文字を変える ☆　//
	switch (in_shader_kind)
	{
	//  頂点シェーダー  //
	case (int)E_SHADER_KIND::e_VERTEX:
		shader_type_text = "VS";
		shader_kind = E_SHADER_KIND::e_VERTEX;
		break;

		//  ハルシェーダー  //
	case (int)E_SHADER_KIND::e_HUL_TCS:
		shader_type_text = "HS";
		shader_kind = E_SHADER_KIND::e_HUL_TCS;
		break;

		//  ドメインシェーダー  //
	case (int)E_SHADER_KIND::e_DOMAIN_TES:
		shader_type_text = "DS";
		shader_kind = E_SHADER_KIND::e_DOMAIN_TES;
		break;

		//  ジオメトリシェーダー  //
	case (int)E_SHADER_KIND::e_GEOMETRY:
		shader_type_text = "GS";
		shader_kind = E_SHADER_KIND::e_GEOMETRY;
		break;

		//  ピクセルシェーダー  //
	case (int)E_SHADER_KIND::e_PIXEL_FRAGMENT:
		shader_type_text = "PS";
		shader_kind = E_SHADER_KIND::e_PIXEL_FRAGMENT;
		break;
	}


	// シェーダーの情報の位置を探す、なければ一番最初に戻ってもう一度探索する、それでもなければこのシェーダーは未使用
	if (in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row(shader_type_text + "START:") == false)
	{
		in_shader_data_file.M_Goto_Sentence_Start();
		if (in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row(shader_type_text + "START:") == false)
		{
			return true;
		}
	}


	// ☆ 変数宣言 ☆ //
	int shader_slot_num = mpr_variable.shader_list.size();	// 操作するシェーダーの配列番号

	
	// シェーダーを取得する、生成に失敗したらエラーを出して抜ける
	mpr_variable.shader_list.resize(shader_slot_num + 1);
	if (mpr_variable.shader_list[shader_slot_num].M_Load_Shader_Code(shader_kind, in_shader_data_file.M_Get_Data_Right_In_Row()) == false)
	{
		return false;
	}

	// シェーダーのリソースを取得
	M_Load_Shader_Resource_Signature(shader_type_text, in_shader_data_file);

	// 成功
	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シェーダーのスロット情報を整列する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Shader_Setting::M_Slot_Inform_Alignment(void)
{
	// ☆ 変数宣言 ☆ //
	int now_slot_num = 0;	// 現在のスロット番号
	

	// 全シェーダー共通情報のリソース数を取得
	mpr_variable.resource_inform_list.resize(
		mpr_variable.resource_signature.all_shader_signature.constant_data.size() + 
		mpr_variable.resource_signature.all_shader_signature.texture_data.size()
	);

	// シェーダー共通情報の定数バッファを探索し、スロット番号とスロット名を取得
	for (ASSET::SHADER::S_Constant_Resource_Signature & constant_buffer_inform : mpr_variable.resource_signature.all_shader_signature.constant_data)
	{
		mpr_variable.resource_inform_list[now_slot_num].resource_name = constant_buffer_inform.signature_name;
		mpr_variable.resource_inform_list[now_slot_num].shader_resource_kind = E_RESOURCE_KIND::e_CONSTANT_BUFFER;
		now_slot_num += 1;
	}

	// シェーダー共通情報のテクスチャバッファを探索し、スロット番号とスロット名を取得
	for (ASSET::SHADER::S_Texture_Resource_Signature & texture_buffer_inform : mpr_variable.resource_signature.all_shader_signature.texture_data)
	{
		mpr_variable.resource_inform_list[now_slot_num].resource_name = texture_buffer_inform.signature_name;

		// レンダリング画像を使用するバッファを識別して登録
		if(texture_buffer_inform.signature_name.substr(0,3) == "RSC")
		{
			mpr_variable.resource_inform_list[now_slot_num].shader_resource_kind = E_RESOURCE_KIND::e_RENDERING_SCREEN;
		}

		// それ以外はテクスチャ
		else
		{
			mpr_variable.resource_inform_list[now_slot_num].shader_resource_kind = E_RESOURCE_KIND::e_TEXTURE;
		}
		now_slot_num += 1;
	}


	// シェーダーごとのリソース設定を行う
	for (ASSET::SHADER::S_Shader_Resource_Signature_Inform & signature_inform : mpr_variable.resource_signature.signature_list)
	{
		// シェーダー共通情報の定数バッファを探索し、スロット番号とスロット名を取得
		for (ASSET::SHADER::S_Constant_Resource_Signature & constant_buffer_inform : signature_inform.constant_data)
		{
			mpr_variable.resource_inform_list[now_slot_num].resource_name = constant_buffer_inform.signature_name;
			mpr_variable.resource_inform_list[now_slot_num].shader_resource_kind = E_RESOURCE_KIND::e_CONSTANT_BUFFER;
			now_slot_num += 1;
		}

		// シェーダー共通情報のテクスチャバッファを探索し、スロット番号とスロット名を取得
		for (ASSET::SHADER::S_Texture_Resource_Signature& texture_buffer_inform : signature_inform.texture_data)
		{
			mpr_variable.resource_inform_list[now_slot_num].resource_name = texture_buffer_inform.signature_name;

			// レンダリング画像を使用するバッファを識別して登録
			if (texture_buffer_inform.signature_name.substr(0, 3) == "RSC")
			{
				mpr_variable.resource_inform_list[now_slot_num].shader_resource_kind = E_RESOURCE_KIND::e_RENDERING_SCREEN;
			}

			// それ以外はテクスチャ
			else
			{
				mpr_variable.resource_inform_list[now_slot_num].shader_resource_kind = E_RESOURCE_KIND::e_TEXTURE;
			}
			now_slot_num += 1;
		}
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：特殊なバッファスロットを探索して番号を記録する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Shader_Setting::M_Search_And_Save_Index_Of_Unique_Buffer_Slot_Number(void)
{
	// ☆ 定数 ☆ //
	constexpr int con_CONSTANT_UNIQUE_BUFFER_KIND_SUM = 8;	// 特殊な定数バッファスロットの総数数
	constexpr int con_MATERIAL_DETAIL_SUM = 6;	// マテリアル質感情報の設定できる項目数


	// ☆ 変数宣言 ☆ //
	std::vector <std::unique_ptr<C_Store_Data>> data_list;	// データのリスト

	int instance_slot_sum = mpr_variable.resource_inform_list.size();	// インスタンススロットの数


	// 名前と変数の関連を登録
	data_list.resize(con_CONSTANT_UNIQUE_BUFFER_KIND_SUM);
	data_list.emplace_back(new C_Store_Data(mpr_variable.unique_buffer_slot_list.wvp, "CB_WVP"));
	data_list.emplace_back(new C_Store_Data(mpr_variable.unique_buffer_slot_list.bone, "CB_BONE"));
	data_list.emplace_back(new C_Store_Data(mpr_variable.unique_buffer_slot_list.material, "CB_MATERIAL"));
	data_list.emplace_back(new C_Store_Data(mpr_variable.unique_buffer_slot_list.ambient_light, "CB_AMBIENT_LIGHT"));
	data_list.emplace_back(new C_Store_Data(mpr_variable.unique_buffer_slot_list.directional_light, "CB_DIRECTIONAL_LIGHT"));
	data_list.emplace_back(new C_Store_Data(mpr_variable.unique_buffer_slot_list.point_light, "CB_POINT_LIGHT"));
	data_list.emplace_back(new C_Store_Data(mpr_variable.unique_buffer_slot_list.spot_light, "CB_SPOT_LIGHT"));
	data_list.emplace_back(new C_Store_Data(mpr_variable.unique_buffer_slot_list.area_light, "CB_AREA_LIGHT"));
	

	// シェーダー共通情報の定数バッファを探索し、特殊な名前のスロットの番号を取得する
	for (int l_now_constant_buffer_num = 0; l_now_constant_buffer_num < instance_slot_sum; l_now_constant_buffer_num++)
	{
		// ☆ 変数宣言 ☆ //
		ASSET::SHADER::S_Resource_Inform & now_resource_data = mpr_variable.resource_inform_list[l_now_constant_buffer_num];	// 現在のリソース情報


		// 定数バッファ以外はスルー
		if (now_resource_data.shader_resource_kind != E_RESOURCE_KIND::e_CONSTANT_BUFFER)
		{
			continue;
		}

		// データ名＆変数関連リストから名前が一致するものにデータを設定し、設定が完了したものはリストから削除
		data_list.erase
		(
			std::remove_if
			(
				data_list.begin(),
				data_list.end(),

				// 名前が一致すれば番号をセットして削除、そうでなければスルーするラムダ
				[now_resource_data, l_now_constant_buffer_num](std::unique_ptr<C_Store_Data>& in_data)
				{
					if (in_data->name == now_resource_data.resource_name)
					{
						in_data->data = l_now_constant_buffer_num;
						in_data.reset();

						return true;
					}

					return false;
				}
			)
		);
	}

	return;
}


//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Shader_Setting::C_Shader_Setting(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Shader_Setting::~C_Shader_Setting(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリを解放する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Shader_Setting::M_Release(void)
{
	// シェーダーの種類分、使用している状態を解除
	for (C_Shader_User & now_shader_user : mpr_variable.shader_list)
	{
		now_shader_user.M_Release();
	}
	mpr_variable.shader_list.clear();
	mpr_variable.shader_list.shrink_to_fit();


	// 頂点レイアウトの削除
	mpr_variable.vertex_layout_setting.clear();
	mpr_variable.vertex_layout_setting.shrink_to_fit();


	// 全体共通のリソース定義用情報をすべて削除
	mpr_variable.resource_signature.all_shader_signature.constant_data.clear();
	mpr_variable.resource_signature.all_shader_signature.constant_data.shrink_to_fit();
	mpr_variable.resource_signature.all_shader_signature.texture_data.clear();
	mpr_variable.resource_signature.all_shader_signature.texture_data.shrink_to_fit();
	mpr_variable.resource_signature.all_shader_signature.sampler_data.clear();
	mpr_variable.resource_signature.all_shader_signature.sampler_data.shrink_to_fit();


	// シェーダーごとのリソース定義用情報をすべて削除
	for (int now_shader_kind = 0; now_shader_kind < (int)ASSET::SHADER::E_SHADER_KIND::e_ALL; now_shader_kind++)
	{
		mpr_variable.resource_signature.signature_list[now_shader_kind].constant_data.clear();
		mpr_variable.resource_signature.signature_list[now_shader_kind].constant_data.shrink_to_fit();
		mpr_variable.resource_signature.signature_list[now_shader_kind].texture_data.clear();
		mpr_variable.resource_signature.signature_list[now_shader_kind].texture_data.shrink_to_fit();
		mpr_variable.resource_signature.signature_list[now_shader_kind].sampler_data.clear();
		mpr_variable.resource_signature.signature_list[now_shader_kind].sampler_data.shrink_to_fit();
	}

	return;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シェーダー情報ファイルの内容を読み取って各種シェーダーをロードし、頂点レイアウトとリソースの定義を設定する
// 引数   ：std::string 読み込むシェーダー設定ファイルまでの相対パス
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Shader_Setting::M_Load_Shaders_Inform_By_Shader_Setting_File_Path(std::string in_shader_setting_file_path)
{
	// ☆ 変数宣言 ☆ //
	SYSTEM::TEXT::C_Text_And_File_Manager text_file_system;	// テキストとファイル用システム

	std::string shader_name;	// シェーダーデータがあるフォルダパス


	// ファイル読み取り	// 失敗したら抜ける
	if (text_file_system.M_Load_Select_File(in_shader_setting_file_path) == false)
	{
		return false;
	}


	// ロードできたファイルのパスを記録
	text_file_system.M_Set_File_Path(in_shader_setting_file_path);


	// シェーダーをロードしてリソースの定義をする	// 失敗したら抜ける
	if (M_Load_Shaders_And_Setting_Resource_Signature(text_file_system) == false)
	{
		return false;
	}


	// 頂点レイアウトを入手	// 失敗したら抜ける
	if (M_Load_Vertex_Layout(text_file_system) == false)
	{
		return false;
	}


	// シェーダーのリソース情報を整列
	M_Slot_Inform_Alignment();


	// 成功した
	return true;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シェーダーのコードのセットを返す
// 引数   ：void
// 戻り値 ：const S_Shader_Byte_Code_List & シェーダーのコードの種類別リストの参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const std::vector<C_Shader_User> & C_Shader_Setting::M_Get_Shader_Code_List(void) const
{
	return mpr_variable.shader_list;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：リソース識別用情報を返す
// 引数   ：void
// 戻り値 ：const S_All_Shader_Resource_Signatures & リソース識別用情報の参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const S_All_Shader_Resource_Signatures & C_Shader_Setting::M_Get_Resource_Signature(void) const
{
	return mpr_variable.resource_signature;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点入力レイアウトのリストを返す
// 引数   ：void
// 戻り値 ：const vector<S_INPUT_LAYOUT_SETTING> & 入力レイアウトへの参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const std::vector<DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING> & C_Shader_Setting::M_Get_Input_Layout(void) const
{
	return mpr_variable.vertex_layout_setting;
}
