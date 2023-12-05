//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：DX12のレンダリング設定用データのセット用のデータのクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_DX12_Rendering_Texture_Setting_Inform.h"


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
C_DX12_Rendering_Texture_Setting_Inform::C_DX12_Rendering_Texture_Setting_Inform(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_DX12_Rendering_Texture_Setting_Inform::~C_DX12_Rendering_Texture_Setting_Inform(void)
{
	M_Delete();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリを解放する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Rendering_Texture_Setting_Inform::M_Delete(void)
{
	m_texture_data.Reset();
	m_texture_heap.Reset();
	m_pix_size_x = 0;
	m_pix_size_y = 0;

	return;
}


//-☆- 更新 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：テクスチャのデータをセットする
// 引数   ：const vector<C_Color> & 設定する色配列への参照, int テクスチャの横幅, int テクスチャの縦幅
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Rendering_Texture_Setting_Inform::M_Set_Texture_Data(const std::vector<DATA::COLOR::C_Color> & in_texture_map, int in_width, int in_height)
{
	// ☆ 変数宣言 ☆ //
	int pixel_width = in_width;	// 横幅でのピクセルサイズ
	int pixel_height = in_height;	// 縦幅でのピクセルサイズ


	// 書き込み範囲の方が広いなら自身のピクセルサイズに調整
	if (pixel_width > m_pix_size_x)
	{
		pixel_width = m_pix_size_x;
	}

	if (pixel_height > m_pix_size_y)
	{
		pixel_height = m_pix_size_y;
	}


	//サブリソースに書き込み
	m_texture_data->WriteToSubresource(0, nullptr, &in_texture_map[0], (pixel_width * 4), (pixel_height * 4));

	return;
}
