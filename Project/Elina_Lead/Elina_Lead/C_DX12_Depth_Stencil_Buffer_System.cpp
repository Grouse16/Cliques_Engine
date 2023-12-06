//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：DX12の深度ステンシルバッファシステム
// 説明   ：深度ステンシルバッファ用のデータを管理する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include <directxpackedvector.h>

#include "C_DX12_Depth_Stencil_Buffer_System.h"
#include "E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE.h"
#include "C_Log_System.h"
#include "C_Half_Color.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE;


// ☆ 関数 ☆ //

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_DX12_Depth_Stencil_Buffer_System::C_DX12_Depth_Stencil_Buffer_System(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_DX12_Depth_Stencil_Buffer_System::~C_DX12_Depth_Stencil_Buffer_System(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリを解放する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Depth_Stencil_Buffer_System::M_Release(void)
{
	m_data.depth_stencil_buffer.Reset();
	m_data.heap.Reset();
}


//-☆- 画像 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：深度ステンシルバッファ画面をテクスチャ画像として保存する
// 引数   ：C_Texture_Map & 保存先のテクスチャ画面の参照
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_DX12_Depth_Stencil_Buffer_System::M_Save_Screen_For_Texture(ASSET::TEXTURE::C_Texture_Map & in_texture_map)
{
	// ☆ 変数宣言 ☆ //
	D3D12_RESOURCE_DESC resource_inform = m_data.depth_stencil_buffer->GetDesc();	// リソースの情報

	void * get_mapped_data = nullptr;	// 取得したテクスチャデータ


	// 深度ステンシルバッファのデータを取得、失敗したらエラーで抜ける
	if (FAILED(m_data.depth_stencil_buffer->Map(0, nullptr, &get_mapped_data)))
	{
#ifdef _DEBUG
		DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_GAME_RENDERING, DEBUGGER::LOG::ALL_LOG_NAME::GAME_RENDERING::con_RENDERING_ERROR, "深度ステンシル画像の取得に失敗しました");
		DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
#endif // _DEBUG

		return false;
	}

	// 必要なテクスチャサイズを生成
	in_texture_map.M_Create_Texture_Map((int)RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE::e_WIDTH_SIZE, (int)RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE::e_HEIGHT_SIZE);


	// バイトの設定に合わせてテクスチャのデータを移す
	switch (resource_inform.Format)
	{
		// ２バイトの読み取り
	case DXGI_FORMAT::DXGI_FORMAT_D16_UNORM:
	{
		// ☆ 変数宣言 ☆ //
		DirectX::PackedVector::HALF * get_depth_data = reinterpret_cast<DirectX::PackedVector::HALF * >(get_mapped_data);	// 深度データ（マップのデータをhalf_float型で読み替え)

		std::vector<DATA::COLOR::C_Color> & texture_map = in_texture_map.M_Get_Texture_Map();	// テクスチャマップへの参照


		// テクスチャのデータを移す
		for (int now_depth_pixel = 0; now_depth_pixel < (int)RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE::e_ALL_SIZE; now_depth_pixel++)
		{
			// ☆ 変数宣言 ☆ //
			float color_data = DirectX::PackedVector::XMConvertHalfToFloat(get_depth_data[now_depth_pixel]);	// 色のデータ


			// テクスチャのデータを移す
			texture_map[now_depth_pixel].m_r = color_data;
			texture_map[now_depth_pixel].m_g = color_data;
			texture_map[now_depth_pixel].m_b = color_data;
			texture_map[now_depth_pixel].m_a = 1.0f;
		}
	}
	return true;

	// ４バイトの読み取り
	case DXGI_FORMAT::DXGI_FORMAT_D32_FLOAT:
	{
		// ☆ 変数宣言 ☆ //
		float * get_depth_data = reinterpret_cast<float*>(get_mapped_data);	// 深度データ（マップのデータをfloat型で読み替え)

		std::vector<DATA::COLOR::C_Color> & texture_map = in_texture_map.M_Get_Texture_Map();	// テクスチャマップへの参照


		// テクスチャのデータを移す
		for (int now_depth_pixel = 0; now_depth_pixel < (int)RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_SIZE::e_ALL_SIZE; now_depth_pixel++)
		{
			// テクスチャのデータを移す
			texture_map[now_depth_pixel].m_r = get_depth_data[now_depth_pixel];
			texture_map[now_depth_pixel].m_g = get_depth_data[now_depth_pixel];
			texture_map[now_depth_pixel].m_b = get_depth_data[now_depth_pixel];
			texture_map[now_depth_pixel].m_a = 1.0f;
		}
	}
	return true;
	}

	// 型が無効なのでエラー
	return false;
}
