//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：DX12のレンダリングスクリーン（レンダリング先画像）のシステム
// 説明   ：レンダーターゲットビューと深度ステンシルビューを管理する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include <DirectXMath.h>

#include "C_DX12_Rendering_Screen_System.h"
#include "C_Half_Color.h"
#include "C_1_Byte_Color.h"
#include "C_Color_Converter.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::API::DX12::DX12_INSTANCE;


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
// 戻り値 ：bool 成功時のみtrue
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

		return false;
	}


	// ☆ 変数宣言 ☆ //
	D3D12_RESOURCE_DESC render_target_view_inform = m_render_target_view.buffer_list[in_screen_number].render_buffer->GetDesc();	// レンダーターゲットビューの情報

	int texture_width = (int)render_target_view_inform.Width;	// 画像の横幅
	int texture_height = (int)render_target_view_inform.Height;	// 画像の縦幅

	void * map_data = nullptr;	// マップによって取得したデータ


	// レンダーターゲットビューのデータを取得、取得に失敗したらエラーで抜ける
	if (FAILED(m_render_target_view.buffer_list[in_screen_number].render_buffer.Get()->Map(0, nullptr, &map_data)))
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_RENDERING_ERROR, "スクリーン画像の取得に失敗しました");
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return false;
	}

	// 画素の型によって分岐
	switch (render_target_view_inform.Format)
	{
		// 画素の色情報はRGBそれぞれ１バイトの画像を取得（０～２５５）
	case DXGI_FORMAT::DXGI_FORMAT_B8G8R8A8_UNORM:
		{
			// ☆ 変数宣言 ☆ //
			DATA::COLOR::C_1_Byte_Color * texture_color = nullptr;	// RGBAを全て０～２５５で受け取れる型

			int pixel_sum = texture_width * texture_height;	// 画像の画素数


			// 型の解釈を変更
			texture_color = static_cast<DATA::COLOR::C_1_Byte_Color * >(map_data);

			// テクスチャ用のマップを生成する
			in_to_texture.M_Create_Texture_Map(texture_width, texture_height);


			// ☆ 変数宣言 ☆ //
			std::vector<DATA::COLOR::C_Color> & texture_map = in_to_texture.M_Get_Texture_Map();	// テクスチャのマップを取得する


			// テクスチャ用のマップに値を移す
			for (int l_now_pixel_number = 0; l_now_pixel_number < pixel_sum; l_now_pixel_number++)
			{
				// ピクセルに色を塗っていく
				texture_map[l_now_pixel_number] = DATA::COLOR::C_Color_Converter::M_Convert_1_Byte_Color_To_Color(texture_color[l_now_pixel_number]);
			}

			// レンダーターゲットビューのデータを閉じて終了
			m_render_target_view.buffer_list[in_screen_number].render_buffer.Get()->Unmap(0, nullptr);
		}
		return true;

		// 画素の色情報はRGBAそれぞれ２バイトである（-1.0～1.0）
	case DXGI_FORMAT::DXGI_FORMAT_R16G16B16A16_FLOAT:
		{
			// ☆ 変数宣言 ☆ //
			DATA::COLOR::C_Half_Color * texture_color = nullptr;	// RGBAを全て０～２５５で受け取れる型

			int pixel_sum = texture_width * texture_height;	// 画像の画素数


			// 型の解釈を変更
			texture_color = static_cast<DATA::COLOR::C_Half_Color * >(map_data);

			// テクスチャ用のマップを生成する
			in_to_texture.M_Create_Texture_Map(texture_width, texture_height);


			// ☆ 変数宣言 ☆ //
			std::vector<DATA::COLOR::C_Color> & texture_map = in_to_texture.M_Get_Texture_Map();	// テクスチャのマップを取得する


			// テクスチャ用のマップに値を移す
			for (int l_now_pixel_number = 0; l_now_pixel_number < pixel_sum; l_now_pixel_number++)
			{
				// ピクセルに色を塗っていく
				texture_map[l_now_pixel_number] = DATA::COLOR::C_Color_Converter::M_Convert_Half_Color_To_Color(texture_color[l_now_pixel_number]);
			}

			// レンダーターゲットビューのデータを閉じて終了
			m_render_target_view.buffer_list[in_screen_number].render_buffer.Get()->Unmap(0, nullptr);
		}
		return true;

		// 画素の色情報はRGBAそれぞれ４バイトである（-1.0～1.0）
	case DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_FLOAT:
		{
			// ☆ 変数宣言 ☆ //
			DATA::COLOR::C_Color * texture_color = nullptr;	// RGBAを全て０～２５５で受け取れる型

			int pixel_sum = texture_width * texture_height;	// 画像の画素数


			// 型の解釈を変更
			texture_color = static_cast<DATA::COLOR::C_Color * >(map_data);

			// テクスチャ用のマップを生成する
			in_to_texture.M_Create_Texture_Map(texture_width, texture_height);


			// ☆ 変数宣言 ☆ //
			std::vector<DATA::COLOR::C_Color> & texture_map = in_to_texture.M_Get_Texture_Map();	// テクスチャのマップを取得する


			// テクスチャ用のマップに値を移す
			for (int l_now_pixel_number = 0; l_now_pixel_number < pixel_sum; l_now_pixel_number++)
			{
				// ピクセルに色を塗っていく
				texture_map[l_now_pixel_number] = texture_color[l_now_pixel_number];
			}

			// レンダーターゲットビューのデータを閉じて終了
			m_render_target_view.buffer_list[in_screen_number].render_buffer.Get()->Unmap(0, nullptr);
		}
		return true;
	}

	// テクスチャの種類が不明ならエラーで抜ける
	return false;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリング画面数を返す
// 引数   ：void
// 戻り値 ：int レンダリング画面数
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
int C_DX12_Rendering_Screen_System::M_Get_Rendering_Screen_Sum(void)
{
	return m_rendering_screen_sum;
}

