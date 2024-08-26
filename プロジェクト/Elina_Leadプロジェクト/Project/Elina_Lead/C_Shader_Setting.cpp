//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：一組のシェーダーの設定をまとめるためのクラス
// 説明   ：シェーダーをバラバラに設定する必要をなくす、カプセル化
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Shader_Setting.h"

#include "C_Log_System.h"


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
	C_Store_Data(int & in_data, std::string in_set_name) : data(in_data)
	{
		name = in_set_name;

		return;
	}
};


// ☆ インライン関数 ☆ //

//-☆- 変換 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：フラグ型を文字列に変換する
// 引数   ：bool 変換するフラグ
// 戻り値 ：string 変換した文字列
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
std::string M_Convert_Bool_To_String(bool in_flg)
{
	// trueなら"TRUE"を返す
	if (in_flg == true)
	{
		return "TRUE";
	}

	// falseなら"FALSE"を返す
	return "FALSE";
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シェーダーの種類を指定する列挙を文字列に変換する
// 引数   ：E_SHADER_KIND 変換するシェーダーの種類
// 戻り値 ：string 変換した文字列
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
std::string M_Convert_Shader_Kind_Flg_To_String(E_SHADER_KIND in_shader_kind)
{
	switch (in_shader_kind)
	{
	case ASSET::SHADER::E_SHADER_KIND::e_VERTEX:
		return "VS";
	case ASSET::SHADER::E_SHADER_KIND::e_HULL_TCS:
		return "HS";
	case ASSET::SHADER::E_SHADER_KIND::e_DOMAIN_TES:
		return "DS";
	case ASSET::SHADER::E_SHADER_KIND::e_GEOMETRY:
		return "GS";
	case ASSET::SHADER::E_SHADER_KIND::e_PIXEL_FRAGMENT:
		return "PS";
	case ASSET::SHADER::E_SHADER_KIND::e_ALL:
	default:
		return "AS";
	}
}


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
	vertex_layout_sum = (int)in_shader_data_file.M_Get_Number();


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
			DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::C_Log_System::M_Print_Log
			(
				DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP,
				DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR,
				"この頂点レイアウトは無効です　" + in_shader_data_file.M_Get_File_Path_Refer() + "：バイト数" + get_text
			);
			DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();

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
			DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::C_Log_System::M_Print_Log
			(
				DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP,
				DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR,
				"この頂点レイアウトは無効です　" + in_shader_data_file.M_Get_File_Path_Refer() + "：フォーマット" + get_text
			);
			DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();

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
			DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
			DEBUGGER::LOG::C_Log_System::M_Print_Log
			(
				DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP,
				DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR,
				"この頂点レイアウトは無効です　" + in_shader_data_file.M_Get_File_Path_Refer() + "：変数の数　x,y,z,w" + get_text
			);
			DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();

			return false;
		}
	}

	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シェーダーのリソースをロードした情報から設定する
// 引数   ：E_SHADER_KIND シェーダーの種類名, C_Text_And_File_Manager & シェーダー情報ファイルのデータ
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Shader_Setting::M_Load_Resource_Signature(E_SHADER_KIND in_shader_kind, SYSTEM::TEXT::C_Text_And_File_Manager & in_shader_data_file)
{
	// ☆ 変数宣言 ☆ //
	std::string shader_kind_name = "default";	// シェーダーの種類名


	// シェーダーの種類名を取得
	shader_kind_name = M_Convert_Shader_Kind_Flg_To_String(in_shader_kind);


	// シェーダーの情報の開始位置を探す、なければエラー
	in_shader_data_file.M_Goto_Sentence_Start();
	if (in_shader_data_file.M_Goto_Right_By_Text_In_Front_Row(shader_kind_name + "START:") == false)
	{
		return false;
	}


	// ☆ 変数宣言 ☆ //
	int constant_number = (int)mpr_variable.resource_inform.constant_list.size();	// 現在の定数バッファの番号
	int sampler_number = (int)mpr_variable.resource_inform.sampler_list.size();		// 現在のサンプラーバッファの番号

	int texture_number = (int)mpr_variable.resource_inform.texture_list.size();		// 現在のテクスチャバッファの番号
	int screen_number = (int)mpr_variable.resource_inform.screen_list.size();		// 現在のレンダリング画面の番号
	int depth_stencil_number = (int)mpr_variable.resource_inform.depth_stencil_list.size();		// 現在の深度ステンシルバッファの番号
	
	int texture_kind_number = texture_number + screen_number + depth_stencil_number;		// 現在のテクスチャ系のバッファの番号
	
	int constant_sum = constant_number;		// 定数の数
	int texture_sum = texture_kind_number;	// テキストの数
	int sampler_sum = sampler_number;		// サンプラーの数


	// 定数バッファ数を取得
	in_shader_data_file.M_Move_Next_Raw();
	constant_sum += (int)in_shader_data_file.M_Get_Number();

	// テキスト数を取得
	in_shader_data_file.M_Move_Next_Raw();
	texture_sum += (int)in_shader_data_file.M_Get_Number();

	// サンプラー数を取得
	in_shader_data_file.M_Move_Next_Raw();
	sampler_sum += (int)in_shader_data_file.M_Get_Number();


	// 取得した数分リソースの識別を生成
	mpr_variable.resource_inform.constant_list.resize(constant_sum);
	mpr_variable.resource_inform.sampler_list.resize(sampler_sum);

	// スロットの情報を生成
	mpr_variable.resource_inform.slot_list.resize(mpr_variable.slot_number + constant_sum + texture_sum);


	// 定数バッファの識別名の行に移動
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(shader_kind_name + "CON:");

	// 定数バッファの情報を取得
	for (constant_number; constant_number < constant_sum; constant_number++)
	{
		// 次の行に移動
		in_shader_data_file.M_Move_Next_Raw();

		// 識別名を取得
		mpr_variable.resource_inform.constant_list[constant_number].resource_name = in_shader_data_file.M_Get_Data_By_Text(",");

		// 配列数を取得
		in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(",");
		mpr_variable.resource_inform.constant_list[constant_number].array_sum = (int)in_shader_data_file.M_Get_Number();

		// 配列数が０なら少なくとも一つは確保する
		mpr_variable.resource_inform.constant_list[constant_number].array_sum =
			(mpr_variable.resource_inform.constant_list[constant_number].array_sum <= 0)
			+
			(mpr_variable.resource_inform.constant_list[constant_number].array_sum > 0) * mpr_variable.resource_inform.constant_list[constant_number].array_sum;

		// データを生成するかどうかのフラグを取得
		in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(",");
		mpr_variable.resource_inform.constant_list[constant_number].flg_data_creation = in_shader_data_file.M_Get_Data_By_Text(",") == "TRUE";

		// シェーダーの種類を指定
		mpr_variable.resource_inform.constant_list[constant_number].shader_kind = in_shader_kind;

		// スロット番号を記録
		mpr_variable.resource_inform.constant_list[constant_number].slot_number = mpr_variable.slot_number;


		// スロットの情報を設定
		mpr_variable.resource_inform.slot_list[mpr_variable.slot_number].resource_kind = E_RESOURCE_KIND::e_CONSTANT_BUFFER;
		mpr_variable.resource_inform.slot_list[mpr_variable.slot_number].shader_kind = in_shader_kind;


		// 次のスロットへ移動
		mpr_variable.slot_number += 1;
	}


	// テクスチャの識別名と数の行に移動
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(shader_kind_name + "TEX:");

	// テクスチャの識別名を取得する
	for (texture_kind_number; texture_kind_number < texture_sum; texture_kind_number++)
	{
		// ☆ 変数宣言 ☆ //
		std::string resource_name = "\0";	// リソース名

		// 次の行に移動
		in_shader_data_file.M_Move_Next_Raw();

		// 識別名を取得
		resource_name = in_shader_data_file.M_Get_Data_By_Text(",");


		// レンダリング画面の識別名の時は、レンダリング画面の情報を設定
		if (resource_name.substr(0, 3) == "RSC")
		{
			// レンダリング画面用のスロットを増やす
			mpr_variable.resource_inform.screen_list.resize(screen_number + 1);

			// レンダリング画面の識別名を取得
			mpr_variable.resource_inform.screen_list[screen_number].resource_name = resource_name;

			// シェーダーの種類を指定
			mpr_variable.resource_inform.screen_list[screen_number].shader_kind = in_shader_kind;

			// スロット番号を記録
			mpr_variable.resource_inform.screen_list[screen_number].slot_number = mpr_variable.slot_number;

			// 次のスロットへ移動
			screen_number += 1;
		}

		// 深度ステンシルバッファの識別名の時は、深度ステンシルバッファの情報を設定
		else if (resource_name.substr(0,3) == "DSB")
		{
			// 深度ステンシルバッファ用のスロットを増やす
			mpr_variable.resource_inform.depth_stencil_list.resize(depth_stencil_number + 1);

			// レンダリング画面の識別名を取得
			mpr_variable.resource_inform.depth_stencil_list[depth_stencil_number].resource_name = resource_name;

			// シェーダーの種類を指定
			mpr_variable.resource_inform.depth_stencil_list[depth_stencil_number].shader_kind = in_shader_kind;

			// スロット番号を記録
			mpr_variable.resource_inform.depth_stencil_list[depth_stencil_number].slot_number = mpr_variable.slot_number;

			// 次のスロットへ移動
			depth_stencil_number += 1;
		}

		// 通常時は、テクスチャの情報を設定
		else
		{
			// テクスチャ用のスロットを増やす
			mpr_variable.resource_inform.texture_list.resize(texture_number + 1);

			// 識別名を設定
			mpr_variable.resource_inform.texture_list[texture_number].resource_name = resource_name;

			// 初期ロードする時のテクスチャの動作を取得
			in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(",");
			mpr_variable.resource_inform.texture_list[texture_number].initialize_texture_name = in_shader_data_file.M_Get_Data_By_Text(",");

			// シェーダーの種類を指定
			mpr_variable.resource_inform.texture_list[texture_number].shader_kind = in_shader_kind;

			// スロット番号を記録
			mpr_variable.resource_inform.texture_list[texture_number].slot_number = mpr_variable.slot_number;

			// 次のスロットへ移動
			texture_number += 1;
		}

		// スロットの情報を設定
		mpr_variable.resource_inform.slot_list[mpr_variable.slot_number].resource_kind = E_RESOURCE_KIND::e_TEXTURE;
		mpr_variable.resource_inform.slot_list[mpr_variable.slot_number].shader_kind = in_shader_kind;

		// 次のスロットへ移動
		mpr_variable.slot_number += 1;
	}


	// サンプラーの識別名と数の行に移動
	in_shader_data_file.M_Goto_Right_By_Text_In_Front_Column(shader_kind_name + "SAM:");

	// サンプラーの識別名を取得する
	for (sampler_number; sampler_number < sampler_sum; sampler_number++)
	{
		// 次の行に移動
		in_shader_data_file.M_Move_Next_Raw();

		// UVの使用方法を取得
		mpr_variable.resource_inform.sampler_list[sampler_number].uv_setting = in_shader_data_file.M_Get_Data_By_Text(",");

		// シェーダーの種類を指定
		mpr_variable.resource_inform.sampler_list[sampler_number].shader_kind = in_shader_kind;
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
	M_Load_Resource_Signature(E_SHADER_KIND::e_ALL, in_shader_data_file);

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
	case (int)E_SHADER_KIND::e_HULL_TCS:
		shader_type_text = "HS";
		shader_kind = E_SHADER_KIND::e_HULL_TCS;
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
	int shader_slot_num = (int)mpr_variable.shader_list.size();	// 操作するシェーダーの配列番号

	
	// シェーダーを取得する、生成に失敗したらエラーを出して抜ける
	mpr_variable.shader_list.resize(shader_slot_num + 1);
	if (mpr_variable.shader_list[shader_slot_num].M_Load_Shader_Code(shader_kind, in_shader_data_file.M_Get_Data_Right_In_Row()) == false)
	{
		return false;
	}

	// シェーダーのリソースを取得
	M_Load_Resource_Signature(shader_kind, in_shader_data_file);

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
	// ☆ 定数 ☆ //
	constexpr int con_CONSTANT_UNIQUE_BUFFER_KIND_SUM = 8;	// 特殊な定数バッファスロットの総数数


	// ☆ 変数宣言 ☆ //
	std::vector <std::unique_ptr<C_Store_Data>> data_list;	// データのリスト

	int constant_slot_sum = 0;	// インスタンススロットの数
	

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


	// 定数バッファのスロットの総数を取得
	constant_slot_sum = (int)mpr_variable.resource_inform.constant_list.size();

	// シェーダー共通情報の定数バッファを探索し、特殊な名前のスロットの番号を取得する
	for (int l_now_constant_buffer_num = 0; l_now_constant_buffer_num < constant_slot_sum; l_now_constant_buffer_num++)
	{
		// ☆ 変数宣言 ☆ //
		S_Constant_Resource_Inform & now_resource_data = mpr_variable.resource_inform.constant_list[l_now_constant_buffer_num];	// 現在のリソース情報


		// 全ての名前を探索し終えたら抜ける
		if (data_list.size() <= 0)
		{
			return;
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
		data_list.shrink_to_fit();
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

	// リソース情報の削除
	mpr_variable.resource_inform.constant_list.clear();
	mpr_variable.resource_inform.constant_list.shrink_to_fit();
	mpr_variable.resource_inform.texture_list.clear();
	mpr_variable.resource_inform.texture_list.shrink_to_fit();
	mpr_variable.resource_inform.screen_list.clear();
	mpr_variable.resource_inform.screen_list.shrink_to_fit();
	mpr_variable.resource_inform.depth_stencil_list.clear();
	mpr_variable.resource_inform.depth_stencil_list.shrink_to_fit();
	mpr_variable.resource_inform.sampler_list.clear();
	mpr_variable.resource_inform.sampler_list.shrink_to_fit();
	mpr_variable.resource_inform.slot_list.clear();
	mpr_variable.resource_inform.slot_list.shrink_to_fit();
	mpr_variable.slot_number = 0;

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
// 詳細   ：頂点入力レイアウトのリストを返す
// 引数   ：void
// 戻り値 ：const vector<S_INPUT_LAYOUT_SETTING> & 入力レイアウトへの参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const std::vector<DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING> & C_Shader_Setting::M_Get_Input_Layout(void) const
{
	return mpr_variable.vertex_layout_setting;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：特殊なシェーダーのリストの参照を返す
// 引数   ：void
// 戻り値 ：const S_Unique_Buffer_Slot & 特殊なシェーダーのリストの参照（const）
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const ASSET::SHADER::RESOURCE::S_Unique_Buffer_Slot & C_Shader_Setting::M_Get_Unique_Buffer_Slot(void) const
{
	return mpr_variable.unique_buffer_slot_list;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：リソース情報のリストを返す
// 引数   ：void
// 戻り値 ：S_Resource_Inform & リソース情報のリストの参照(const)
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const S_Resource_Inform_List & C_Shader_Setting::M_Get_Resource_Inform(void) const
{
	return mpr_variable.resource_inform;
}




