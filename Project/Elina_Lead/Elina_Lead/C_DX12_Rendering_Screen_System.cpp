//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：DX12のレンダリングスクリーン（レンダリング先画像）のシステム
// 説明   ：レンダーターゲットビューと深度ステンシルビューを管理する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include <DirectXMath.h>

#include "C_DX12_Rendering_Screen_System.h"
#include "C_Half_Color.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_DX12_Rendering_Screen_System::C_DX12_Rendering_Screen_System(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_DX12_Rendering_Screen_System::~C_DX12_Rendering_Screen_System(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリを開放する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Rendering_Screen_System::M_Release(void)
{
	m_render_target_view.buffer_list.clear();
	m_render_target_view.buffer_list.shrink_to_fit();
	
	return;
}


//-☆- 画像 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された番号のレンダリング画面をテクスチャ画像として保存する
// 引数   ：int レンダリング画面番号, C_Texture_Map & 保存先のテクスチャ画面の参照
// 戻り値 ：成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_DX12_Rendering_Screen_System::M_Save_Screen_For_Texture(int in_screen_number, ASSET::TEXTURE::C_Texture_Map & in_to_texture)
{
	// 範囲外を指定されたらエラーを出して抜ける
	if (0 < in_screen_number || in_screen_number <= m_rendering_screen_sum)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_RENDERING_ERROR, "スクリーン画像番号に範囲外を指定されました");
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return;
	}


	// ☆ 変数宣言 ☆ //
	int texture_width = m_render_target_view.buffer_list[in_screen_number].screen_width;	// 画像の横幅
	int texture_height = m_render_target_view.buffer_list[in_screen_number].screen_height;	// 画像の縦幅

	void * map_data = nullptr;	// マップによって取得したデータ


	// レンダーターゲットビューのデータを取得
	m_render_target_view.buffer_list[in_screen_number].render_buffer.Get()->Map(0, nullptr, &map_data);

	// 取得に失敗したらエラーで抜ける
	if (map_data == nullptr)
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_RENDERING_ERROR, "スクリーン画像の取得に失敗しました");
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return;
	}

	// 画素の型によって分岐
	switch (m_screen_format)
	{
		// 画素の色情報はRGBそれぞれ１バイトである（０～２５５）
	case RENDERING::INFORM::RENDERING_SCREEN::E_RENDERING_SCREEN_FORMAT::e_1_BYTE:
		{
			// ☆ 変数宣言 ☆ //
			DATA::TEXTURE::C_Tex_Color* texture_color = nullptr;	// RGBAを全て０～２５５で受け取れる型


			// 型の解釈を変更
			texture_color = static_cast<DATA::TEXTURE::C_Tex_Color*>(map_data);

			// テクスチャ用のマップを生成する
			in_to_texture.M_Create_Texture_Map(m_render_target_view.buffer_list[in_screen_number].screen_width, m_render_target_view.buffer_list[in_screen_number].screen_height);


			// ☆ 変数宣言 ☆ //
			std::vector<DATA::COLOR::C_Color>& texture_map = in_to_texture.M_Get_Texture_Map();	// テクスチャのマップを取得する


			// テクスチャ用のマップに値を移す
			for (int l_now_height = 0; l_now_height < texture_height; l_now_height++)
			{
				for (int l_now_width = 0; l_now_width < texture_width; l_now_width++)
				{
					// ☆ 変数宣言 ☆ //
					int now_pixel_number = l_now_width + l_now_height * texture_width;	// 現在のピクセル番号


					// ピクセルに色を塗っていく
					texture_map[now_pixel_number].m_r = texture_color[now_pixel_number].r / 255.0f;
					texture_map[now_pixel_number].m_g = texture_color[now_pixel_number].g / 255.0f;
					texture_map[now_pixel_number].m_b = texture_color[now_pixel_number].b / 255.0f;
					texture_map[now_pixel_number].m_a = texture_color[now_pixel_number].a / 255.0f;
				}
			}

			// レンダーターゲットビューのデータを閉じて終了
			m_render_target_view.buffer_list[in_screen_number].render_buffer.Get()->Unmap(0, nullptr);
		}
		return;

		// 画素の色情報はRGBAそれぞれ２バイトである（-1.0~1.0）
	case RENDERING::INFORM::RENDERING_SCREEN::E_RENDERING_SCREEN_FORMAT::e_2_BYTE:
		{
			// ☆ 変数宣言 ☆ //
			DATA::TEXTURE::C_Tex_Color* texture_color = nullptr;	// RGBAを全て０～２５５で受け取れる型


			// 型の解釈を変更
			texture_color = static_cast<DATA::TEXTURE::C_Tex_Color*>(map_data);

			// テクスチャ用のマップを生成する
			in_to_texture.M_Create_Texture_Map(m_render_target_view.buffer_list[in_screen_number].screen_width, m_render_target_view.buffer_list[in_screen_number].screen_height);


			// ☆ 変数宣言 ☆ //
			std::vector<DATA::COLOR::C_Color>& texture_map = in_to_texture.M_Get_Texture_Map();	// テクスチャのマップを取得する


			// テクスチャ用のマップに値を移す
			for (int l_now_height = 0; l_now_height < texture_height; l_now_height++)
			{
				for (int l_now_width = 0; l_now_width < texture_width; l_now_width++)
				{
					// ☆ 変数宣言 ☆ //
					int now_pixel_number = l_now_width + l_now_height * texture_width;	// 現在のピクセル番号


					// ピクセルに色を塗っていく
					texture_map[now_pixel_number].m_r = texture_color[now_pixel_number].r / 255.0f;
					texture_map[now_pixel_number].m_g = texture_color[now_pixel_number].g / 255.0f;
					texture_map[now_pixel_number].m_b = texture_color[now_pixel_number].b / 255.0f;
					texture_map[now_pixel_number].m_a = texture_color[now_pixel_number].a / 255.0f;
				}
			}

			// レンダーターゲットビューのデータを閉じて終了
			m_render_target_view.buffer_list[in_screen_number].render_buffer.Get()->Unmap(0, nullptr);
		}
		return;

		// 画素の色情報はRGBAそれぞれ４バイトである（-1.0~1.0）
	case RENDERING::INFORM::RENDERING_SCREEN::E_RENDERING_SCREEN_FORMAT::e_4_BYTE:
		{
		}
		return;
	}

	return;
}

