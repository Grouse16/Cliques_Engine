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

//-☆- ブレンド設定 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：どのブレンドモードを設定するかを指定された文字列から特定して返す
// 引数   ：string ブレンドモードを示す文字列
// 戻り値 ：E_BLEND_MODE 特定したブレンドモード
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
RENDERING::INFORM::BLEND::E_BLEND_MODE C_Material::M_Get_Blend_Mode_By_Text(std::string in_blend_mode_signature)
{
	// 通常時は、色をそのまま使う
	if (in_blend_mode_signature == "NORMAL")
	{
		return RENDERING::INFORM::BLEND::E_BLEND_MODE::e_NORMAL;
	}

	// 通常描画でα値のみ１で固定
	if (in_blend_mode_signature == "NORMAL_NOT_ALPHA")
	{
		return RENDERING::INFORM::BLEND::E_BLEND_MODE::e_NORMAL_NOT_ALPHA;
	}

	// 出力された色を減算方式で使用する
	if (in_blend_mode_signature == "INVERT")
	{
		return RENDERING::INFORM::BLEND::E_BLEND_MODE::e_INVERT;
	}

	// 出力された色を減算方式で使用するが、α値は１で固定
	if (in_blend_mode_signature == "INVERT_NOT_ALPHA")
	{
		return RENDERING::INFORM::BLEND::E_BLEND_MODE::e_INVERT_NOT_ALPHA;
	}

	// どれにも当てはまらなかったら初期値を返す
	return RENDERING::INFORM::BLEND::E_BLEND_MODE::e_NORMAL;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：どの色の操作を設定するかを指定された文字列から特定して返す
// 引数   ：string 色の操作を示す文字列
// 戻り値 ：E_BLEND_OPTION 特定した色の操作
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
RENDERING::INFORM::BLEND::E_BLEND_OPTION C_Material::M_Get_Blend_Option_By_Text(std::string in_blend_option_signature)
{
	// 加算する
	if (in_blend_option_signature == "ADD")
	{
		return RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_ADD;
	}

	// 減算する
	if (in_blend_option_signature == "SUB")
	{
		RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_SUB;
	}

	// ピクセルシェーダーの出力色を減算する
	if (in_blend_option_signature == "SUB_PIX")
	{
		RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_SUB_PIX;
	}

	// ピクセルシェーダーとレンダリング画像を比較し、最大値を出力する
	if (in_blend_option_signature == "MAX")
	{
		RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_MAX;
	}

	// ピクセルシェーダーとレンダリング画像を比較し、最小値を出力する
	if (in_blend_option_signature == "MIN")
	{
		RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_MIN;
	}

	// どれにも当てはまらなかったら初期値を返す
	return RENDERING::INFORM::BLEND::E_BLEND_OPTION::e_ADD;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：どの書き込む形式を設定するかを指定された文字列から特定して返す
// 引数   ：string 書き込むデータ形式をを示す文字列
// 戻り値 ：E_RENDERING_DRAW_FORMAT 書き込むデータの形式
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT C_Material::M_Get_Blend_Write_Format_By_Text(std::string in_format_signature)
{
	// ４バイトのFLOAT
	if (in_format_signature == "BYTE_4_FLOAT")
	{
		return RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_4_FLOAT;
	}

	// 2バイトのFLOAT
	if (in_format_signature == "BYTE_2_FLOAT")
	{
		return RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_2_FLOAT;
	}

	// ４バイトのUINT
	if (in_format_signature == "BYTE_4_UINT")
	{
		return RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_4_UINT;
	}

	// ２バイトのUINT
	if (in_format_signature == "BYTE_2_UINT")
	{
		return RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_2_UINT;
	}

	// １バイトのUINT
	if (in_format_signature == "BYTE_1_UINT")
	{
		return RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_1_UINT;
	}

	return RENDERING::INFORM::BLEND::E_RENDERING_DRAW_FORMAT::e_BYTE_2_FLOAT;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：どの書き込む色の種類を設定するかを指定された文字列から特定して返す
// 引数   ：string 書き込む色の種類を示す文字列
// 戻り値 ：E_RENDERING_DRAW_COLOR 書き込む色の種類
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
RENDERING::INFORM::BLEND::E_RENDERING_DRAW_COLOR C_Material::M_Get_Blend_Write_Color_By_Text(std::string in_color_signature)
{
	// ４色ともある
	if (in_color_signature == "RGBA")
	{
		return RENDERING::INFORM::BLEND::E_RENDERING_DRAW_COLOR::e_RGBA;
	}

	// 赤と緑色分のみ
	if (in_color_signature == "RG")
	{
		return RENDERING::INFORM::BLEND::E_RENDERING_DRAW_COLOR::e_RG;
	}

	// 赤色分のみ
	if (in_color_signature == "R")
	{
		return RENDERING::INFORM::BLEND::E_RENDERING_DRAW_COLOR::e_R;
	}

	return RENDERING::INFORM::BLEND::E_RENDERING_DRAW_COLOR::e_RGBA;
}


//-☆- 深度ステンシル -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：どの深度モードを設定するかを指定された文字列から特定して返す
// 引数   ：string 深度モードの種類を示す文字列
// 戻り値 ：E_DEPTH_MODE 深度モードの種類
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE C_Material::M_Get_Depth_Mode_By_Text(std::string in_depth_mode_signature)
{
	// 深度データが０の部分にのみ書き込む
	if (in_depth_mode_signature == "ZERO")
	{
		return RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE::e_ZERO;
	}

	// 常時深度データを書き込む
	if (in_depth_mode_signature == "ONE")
	{
		return RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE::e_ONE;
	}

	// 深度なし、または情報がないときは無効
	return RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE::e_NO;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：どの深度オプションを設定するかを指定された文字列から特定して返す
// 引数   ：string 深度オプションの種類を示す文字列
// 戻り値 ：E_DEPTH_WRITE_RULE 深度オプションの種類
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE C_Material::M_Get_Depth_Option_By_Text(std::string in_depth_option_signature)
{
	// 常時書き込む
	if (in_depth_option_signature == "ALWAYS")
	{
		return RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_ALWAYS;
	}

	// 元の値を超える時のみ書き込む
	if (in_depth_option_signature == "GREATER")
	{
		return RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_GREATER;
	}

	// 元の値未満の時のみ書き込む
	if (in_depth_option_signature == "LESS")
	{
		return RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_LESS;
	}

	// 元の値以上の時のみ書き込む
	if (in_depth_option_signature == "GREATER_EQUAL")
	{
		return RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_GREATERE_EQUAL;
	}

	// 元の値以下の時のみ書き込む
	if (in_depth_option_signature == "LESS_EQUAL")
	{
		return RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_LESS_EQUAL;
	}

	// 同じ値の時のみ書き込む
	if (in_depth_option_signature == "EQUAL")
	{
		return RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_EQUAL;
	}

	// 元の値と等しくない時のみ書き込む
	if (in_depth_option_signature == "NOT_EQUAL")
	{
		return RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_NOT_EQUAL;
	}

	// 情報がないか何もしないとき
	return RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_DONT;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：どのステンシルを有効にするかを指定された文字列から特定して返す
// 引数   ：string ステンシルの有効無効を示す文字列
// 戻り値 ：E_STENCIL_IS ステンシルの有効無効
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
RENDERING::INFORM::DEPTH_STENCIL::E_STENCIL_IS C_Material::M_Get_Stencil_Is_Active_By_Text(std::string in_stencil_signature)
{
	// ステンシル有効
	if (in_stencil_signature == "ACTIVE")
	{
		return RENDERING::INFORM::DEPTH_STENCIL::E_STENCIL_IS::e_ACTIVE;
	}

	// ステンシル無効、または情報がないとき
	return RENDERING::INFORM::DEPTH_STENCIL::E_STENCIL_IS::e_NO_ACTIVE;
}


//-☆- ラスタライザ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：どの描画モードを設定するかを指定された文字列から特定して返す
// 引数   ：string 描画モードの種類を示す文字列
// 戻り値 ：E_DRAW_MODE 描画モードの種類
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
RENDERING::INFORM::RASTERIZER::E_DRAW_MODE C_Material::M_Get_Draw_Mode_By_Text(std::string in_draw_mode_signature)
{
	// ワイヤーフレーム表示
	if (in_draw_mode_signature == "WIRE_FRAME")
	{
		return RENDERING::INFORM::RASTERIZER::E_DRAW_MODE::e_WIRE_FRAME;
	}

	// 通常表示を行う、または情報がないとき
	return RENDERING::INFORM::RASTERIZER::E_DRAW_MODE::e_NORMAL;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：どの面を表示するかを指定された文字列から特定して返す
// 引数   ：string 面表示の種類を示す文字列
// 戻り値 ：E_MESH_CULLING 面の表示モードを返す
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
RENDERING::INFORM::RASTERIZER::E_MESH_CULLING C_Material::M_Get_Mesh_Culling_By_Text(std::string in_culling_signature)
{
	// 表面のみ描画
	if (in_culling_signature == "FRONT")
	{
		RENDERING::INFORM::RASTERIZER::E_MESH_CULLING::e_FRONT;
	}

	// 裏面のみ描画
	if (in_culling_signature == "BACK")
	{
		RENDERING::INFORM::RASTERIZER::E_MESH_CULLING::e_BACK;
	}

	// 特に指定がないなら全ての面を描画
	return RENDERING::INFORM::RASTERIZER::E_MESH_CULLING::e_ALWAYS;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：どの面の表面の設定を使用するかを指定された文字列から特定して返す
// 引数   ：string 表面設定の種類を示す文字列
// 戻り値 ：E_MESH_FRONT 表面設定を返す
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
RENDERING::INFORM::RASTERIZER::E_MESH_FRONT ASSET::MATERIAL::C_Material::M_Get_Mesh_Front_By_Text(std::string in_mesh_front_signature)
{
	// 反時計回り
	if (in_mesh_front_signature == "ANTI_CLOCK_WISE")
	{
		return RENDERING::INFORM::RASTERIZER::E_MESH_FRONT::e_ANTI_CLOCK_WISE;
	}

	// 時計回り、または情報がないとき
	return RENDERING::INFORM::RASTERIZER::E_MESH_FRONT::e_CLOCK_WISE;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：どのアンチエイリアシングの種類を指定された文字列から特定して返す
// 引数   ：string アンチエイリアシングの種類を示す文字列
// 戻り値 ：E_ANTIALIASING アンチエイリアシングの種類を返す
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
RENDERING::INFORM::RASTERIZER::E_ANTIALIASING C_Material::M_Get_Antialiasing_By_Text(std::string in_antialiasing_signature)
{
	// α値でアンチエイリアシングをかける
	if (in_antialiasing_signature == "ALPHA")
	{
		return RENDERING::INFORM::RASTERIZER::E_ANTIALIASING::e_ALPHA;
	}

	// ピクセル基準でアンチエイリアシングをかける
	if (in_antialiasing_signature == "PIXEL")
	{
		return RENDERING::INFORM::RASTERIZER::E_ANTIALIASING::e_PIXEL;
	}

	// 辺の補間でアンチエイリアシングをかける
	if (in_antialiasing_signature == "LINE")
	{
		return RENDERING::INFORM::RASTERIZER::E_ANTIALIASING::e_LINE;
	}

	// アンチエイリアシングをしない、または情報がないとき
	return RENDERING::INFORM::RASTERIZER::E_ANTIALIASING::e_DONT;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ブレンドの設定をマテリアル情報からロードする
// 引数   ：vector<C_Create_Rendering_Graphics_Setting_Inform::S_Blend_Setting_Create_Data> & ブレンドの設定先, C_Text_And_File_Manager & 読み込んだファイルの情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Material::M_Load_Blend_Setting(std::vector<RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform::S_Blend_Setting_Create_Data> & in_blend_setting_list, SYSTEM::TEXT::C_Text_And_File_Manager & in_file_data)
{
	// ☆ 定数 ☆ //
	const int con_blend_setting_max = 8;	// ブレンド設定を生成できる上限値


	// 情報の最初へ移動
	in_file_data.M_Goto_Sentence_Start();


	// ブレンドの情報が残っている間、8つになるまでは設定し続ける
	for (int l_slot_num = 0; l_slot_num < con_blend_setting_max; l_slot_num++)
	{
		// ブレンド設定の現在の番号まで移動、なければ終了
		if (in_file_data.M_Goto_Left_By_Text_In_Front_Row("BLEND" + std::to_string(l_slot_num + 1) + ":") == false)
		{
			return;
		}


		// ブレンド設定登録用の配列を拡張
		in_blend_setting_list.resize(l_slot_num + 1);


		// ブレンドモードを取得
		in_file_data.M_Move_Next_Raw();
		in_blend_setting_list[l_slot_num].blend_mode = M_Get_Blend_Mode_By_Text(in_file_data.M_Get_Data_Now_Row());

		// ブレンドの操作を取得
		in_file_data.M_Move_Next_Raw();
		in_blend_setting_list[l_slot_num].blend_option = M_Get_Blend_Option_By_Text(in_file_data.M_Get_Data_Now_Row());

		// レンダーターゲットへの書き込み形式を取得
		in_file_data.M_Move_Next_Raw();
		in_blend_setting_list[l_slot_num].draw_format = M_Get_Blend_Write_Format_By_Text(in_file_data.M_Get_Data_Now_Row());

		// レンダーターゲットへの書き込む色の種類数を取得
		in_file_data.M_Move_Next_Raw();
		in_blend_setting_list[l_slot_num].draw_color = M_Get_Blend_Write_Color_By_Text(in_file_data.M_Get_Data_Now_Row());
	}

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：深度ステンシルをマテリアル情報からロードする
// 引数   ：C_Create_Rendering_Graphics_Setting_Inform::S_Depth_Stencil_Create_Data & 深度ステンシルの設定先, C_Text_And_File_Manager & 読み込んだファイルの情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Material::M_Load_Depth_Stencil_Setting(RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform::S_Depth_Stencil_Create_Data & in_depth_stencil_inform, SYSTEM::TEXT::C_Text_And_File_Manager & in_file_data)
{
	// 深度ステンシルの位置へ移動、なければ初期値のまま
	in_file_data.M_Goto_Sentence_Start();
	if (in_file_data.M_Goto_Right_By_Text_In_Front_Row("DEPTH") == false)
	{
		return;
	}


	// 深度の書き込みモードを設定
	in_file_data.M_Move_Next_Raw();
	in_depth_stencil_inform.mode = M_Get_Depth_Mode_By_Text(in_file_data.M_Get_Data_Now_Row());

	// 深度オプションを設定
	in_file_data.M_Move_Next_Raw();
	in_depth_stencil_inform.write_rule = M_Get_Depth_Option_By_Text(in_file_data.M_Get_Data_Now_Row());

	// ステンシルの有効無効を設定
	in_file_data.M_Move_Next_Raw();
	in_depth_stencil_inform.stencil_activate = M_Get_Stencil_Is_Active_By_Text(in_file_data.M_Get_Data_Now_Row());

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ラスタライザをマテリアル情報からロードする
// 引数   ：C_Create_Rendering_Graphics_Setting_Inform::S_Rasterizer_Create_Data & ラスタライザの設定先, C_Text_And_File_Manager & 読み込んだファイルの情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Material::M_Load_Rasterizer_Setting(RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform::S_Rasterizer_Create_Data & in_rasterizer_setting, SYSTEM::TEXT::C_Text_And_File_Manager & in_file_data)
{
	// ラスタライザ情報の位置に行く、なければ初期値のまま
	in_file_data.M_Goto_Start_Row();
	if (in_file_data.M_Goto_Right_By_Text_In_Front_Row("RASTERIZER") == false)
	{
		return;
	}


	// 描画モードの設定
	in_file_data.M_Move_Next_Raw();
	in_rasterizer_setting.draw_mode = M_Get_Draw_Mode_By_Text(in_file_data.M_Get_Data_Now_Row());

	// 残すメッシュの向きを決める
	in_file_data.M_Move_Next_Raw();
	in_rasterizer_setting.mesh_culling = M_Get_Mesh_Culling_By_Text(in_file_data.M_Get_Data_Now_Row());

	// メッシュの表面設定を決める
	in_file_data.M_Move_Next_Raw();
	in_rasterizer_setting.mesh_front = M_Get_Mesh_Front_By_Text(in_file_data.M_Get_Data_Now_Row());

	// 深度バイアスを決める
	in_file_data.M_Move_Next_Raw();
	in_rasterizer_setting.depth_value.depth_bias = in_file_data.M_Get_Number();

	// メッシュの表面設定を決める
	in_file_data.M_Move_Next_Raw();
	in_rasterizer_setting.depth_value.depth_max = in_file_data.M_Get_Float_Double_Number();

	// メッシュの表面設定を決める
	in_file_data.M_Move_Next_Raw();
	in_rasterizer_setting.depth_value.depth_slope = in_file_data.M_Get_Float_Double_Number();

	// アンチエイリアシング設定を決める
	in_file_data.M_Move_Next_Raw();
	in_rasterizer_setting.antialiasing = M_Get_Antialiasing_By_Text(in_file_data.M_Get_Data_Now_Row());

	// 保守的なラスタライズを決める
	in_file_data.M_Move_Next_Raw();
	in_rasterizer_setting.flg_conservative = in_file_data.M_Get_Data_Now_Row() == "true";

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：その他設定をロードする
// 引数   ：C_Create_Rendering_Graphics_Setting_Inform & 設定先のレンダリング設定生成用情報, C_Text_And_File_Manager & 読み込んだファイルの情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Material::M_Load_Another_Setting(RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform & in_creat_rendering_graphics_setting, SYSTEM::TEXT::C_Text_And_File_Manager & in_file_data)
{
	// サンプリング設定まで移動する、なければ初期値のまま
	in_file_data.M_Goto_Start_Row();
	if (in_file_data.M_Goto_Right_By_Text_In_Front_Row("SAMPLING") == false)
	{
		return;
	}


	// サンプリング回数を取得
	in_file_data.M_Move_Next_Raw();
	in_creat_rendering_graphics_setting.sampling_setting.sampling_count = in_file_data.M_Get_Number();

	// サンプリング品質を取得
	in_file_data.M_Move_Next_Raw();
	in_creat_rendering_graphics_setting.sampling_setting.sampling_quality = in_file_data.M_Get_Number();

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
		for (const ASSET::SHADER::S_Resource_Signature & now_texture_inform : in_resource_signature.signature_list[l_now_shader_number].texture_data)
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
	RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform create_rendering_setting_inform;	// レンダリング設定の生成用の情報


	// シェーダー設定をセット
	create_rendering_setting_inform.shader_setting = mpr_variable.shader_setting_data.M_Get_Shader_Setting();

	// ブレンドの設定を読み込む
	M_Load_Blend_Setting(create_rendering_setting_inform.blend_setting, in_file_text);

	// ステンシルの設定を読み込む
	M_Load_Depth_Stencil_Setting(create_rendering_setting_inform.depth_stencil_data, in_file_text);

	// ラスタライザの設定を読み込む
	M_Load_Rasterizer_Setting(create_rendering_setting_inform.rasterizer_data, in_file_text);

	// その他の設定を読み込む
	M_Load_Another_Setting(create_rendering_setting_inform, in_file_text);


	// レンダリング設定を生成する
	return mpr_variable.rendering_setting.M_Create_Pipeline_Setting(create_rendering_setting_inform);
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

	// シェーダー設定
	mpr_variable.shader_setting_data.M_Release();
	
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
	if (material_inform_file_data.M_Goto_Right_By_Text_In_Front_Row("Shader：") == false)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR, "マテリアルの情報にシェーダーのデータが設定されていません");
#endif // _DEBUG

		return false;
	}
	

	// シェーダー設定名からシェーダーを設定をロードする　失敗でエラーを出して抜ける
	mpr_variable.shader_setting_data.M_Load_Shader_Setting(material_inform_file_data.M_Get_Data_Right_In_Row());
	if (mpr_variable.shader_setting_data.M_Get_Shader_Setting() == nullptr)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_ERROR, "このシェーダー設定は無効です。存在しないファイルか設定が正しくない可能性があります");
#endif // _DEBUG

		return false;
	}


	// シェーダー設定のリソースの情報をもとにリソースを生成する
	M_Create_Resource_By_Signature_Inform(mpr_variable.shader_setting_data.M_Get_Shader_Setting()->M_Get_Resource_Signature());


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



