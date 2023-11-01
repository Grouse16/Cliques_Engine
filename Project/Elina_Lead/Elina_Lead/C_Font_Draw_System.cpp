//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：フォントデータを正確に使うためのシステム
// 説明   ：フォントの読み込みから描画までを行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Font_Draw_System.h"
#include "C_Rendering_Graphics_API_Base.h"
#include "S_Make_Font_To_Graph_Pakage.h"


// ☆ ネームスペースの省略 ☆ //
using namespace DATA::FONT;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在のテキストに応じて画像を生成する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Font_Draw_System::M_Creat_Texture_On_Now_Text(void)
{
	// ☆ 変数宣言 ☆ //
	int text_size = (int)mpr_variable.now_draw_text.size();	// 文字数

	PAKAGE::FONT::S_Make_Font_To_Graph_Package make_font_setting;	// フォントデータの設定用情報


	// 情報のセット
	make_font_setting.attach_font_data = &mpr_variable.font_data;
	make_font_setting.tex_map_data = &mpr_variable.texture_data.M_Get_Texture_Map();


	// 初期の書き込み位置設定
	make_font_setting.draw_rect.left_x = 1;
	make_font_setting.draw_rect.right_x = mpr_variable.font_size;

	make_font_setting.draw_rect.top_y = mpr_variable.font_size;
	make_font_setting.draw_rect.bottom_y = 1;


	// 一文字づつ画像にセットしていく
	for (int l_text_elem = 0; l_text_elem < text_size; l_text_elem++)
	{
		// 改行時は現在の行数を更新
		if (mpr_variable.now_draw_text[l_text_elem] == L'\n')
		{
			make_font_setting.draw_rect.left_x = 1;
			make_font_setting.draw_rect.right_x = mpr_variable.font_size;

			make_font_setting.draw_rect.bottom_y += mpr_variable.font_size + mpr_variable.span_size;
			make_font_setting.draw_rect.top_y += mpr_variable.font_size + mpr_variable.span_size;
		}

		// 空白（半角は間隔をあける）
		else if (mpr_variable.now_draw_text[l_text_elem] == L' ')
		{
			make_font_setting.draw_rect.left_x += mpr_variable.font_size / 2;
			make_font_setting.draw_rect.right_x += mpr_variable.font_size / 2;
		}

		// 空白（全角は次の文字までスルー）
		else if (mpr_variable.now_draw_text[l_text_elem] == L'　')
		{
			make_font_setting.draw_rect.left_x += mpr_variable.font_size;
			make_font_setting.draw_rect.right_x += mpr_variable.font_size;
		}

		// 通常の文字列なら画像に文字を書き込む
		else
		{
			make_font_setting.text_code = mpr_variable.now_draw_text[l_text_elem];

			RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Set_Font_To_Texture_Map(make_font_setting);

			make_font_setting.draw_rect.left_x += mpr_variable.font_size + mpr_variable.span_size;
			make_font_setting.draw_rect.right_x += mpr_variable.font_size + mpr_variable.span_size;
		}
	}

	// GPUにテクスチャマップをテクスチャバッファへセット
	mpr_variable.texture_data.M_Creat_Texture_Resource_By_Texture_Map();


	// マップを保存しないなら画像マップを削除
	if (mpr_variable.flg_save_map == false)
	{
		mpr_variable.texture_data.M_Delete_Map();
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
C_Font_Draw_System::C_Font_Draw_System(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Font_Draw_System::~C_Font_Draw_System(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：フォントデータを初期化する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Font_Draw_System::M_Reset(void)
{
	mpr_variable.font_data.reset();
	mpr_variable.texture_data.M_Delete();

	mpr_variable.font_size = 60;

	return;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された名前のフォントを取得する(PCに存在している時のみ動作)
// 引数   ：std::wstring フォント名, int フォントのピクセルサイズ
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Font_Draw_System::M_Load_Font_By_Font_Name(std::wstring in_load_font_name, int in_font_pixel_size)
{
	// ☆ 変数宣言 ☆ //
	RENDERING::GRAPHICS::CREAT::C_Creat_Font_Data_Inform creat_setting;	// 生成用情報


	// 今持っているデータは削除する
	M_Reset();


	// フォントデータ生成用情報の設定
	creat_setting.m_width = in_font_pixel_size;
	creat_setting.m_height = in_font_pixel_size;
	creat_setting.m_font_name = in_load_font_name;


	// フォントをロードする
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Creat_Font_Data(mpr_variable.font_data, creat_setting);

	return true;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：描画位置を設定する
// 引数   ：int フォントサイズ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Font_Draw_System::M_Set_Font_Size(int in_font_size)
{
	mpr_variable.font_size = in_font_size;
	mpr_variable.font_data->M_Resize(in_font_size, in_font_size);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：描画位置を設定する
// 引数   ：int フォントサイズ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Font_Draw_System::M_Set_Span(int in_span)
{
	mpr_variable.span_size = in_span;

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャデータの参照を返す
// 引数   ：void
// 戻り値 ：C_Texture_Data_System & テクスチャーデータの参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
RENDERING::CAPSULE::C_Texture_Data_System & C_Font_Draw_System::M_Get_Texture_Data(void)
{
	return mpr_variable.texture_data;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テキストから画像を生成する
// 引数   ：const wstring 設定するテキスト
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Font_Draw_System::M_Creat_Graph_By_Text(const std::wstring in_set_string)
{
	mpr_variable.now_draw_text = in_set_string;
	M_Creat_Texture_On_Now_Text();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：設定されたテキストによる画像をもう一度生成する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Font_Draw_System::M_Recreate_Graph(void)
{
	M_Creat_Texture_On_Now_Text();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：インデックス指定用の識別名をセットする
// 引数   ：const std::string 設定する識別名
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Font_Draw_System::M_Set_Signature_Name(const std::string in_set_string)
{
	mpr_variable.texture_data.M_Set_Data_Signature_Name(in_set_string);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：適応するシェーダーの種類を設定する
// 引数   ：const E_SHADER_KIND 設定する種類
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Font_Draw_System::M_Set_Attach_Shader_Kind(const ASSET::SHADER::E_SHADER_KIND in_set_kind)
{
	mpr_variable.texture_data.M_Set_Attach_Shader_Kind(in_set_kind);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：このテクスチャのデータをGPUへ送る
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Font_Draw_System::M_Attach_To_Shader(void)
{
	mpr_variable.texture_data.M_Attach_To_Shader();

	return;
}

