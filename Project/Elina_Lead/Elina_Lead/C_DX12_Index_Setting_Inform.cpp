//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：DX12の頂点インデックスバッファのクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_DX12_Index_Setting_Inform.h"


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
C_DX12_Index_Setting_Inform::C_DX12_Index_Setting_Inform(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_DX12_Index_Setting_Inform::~C_DX12_Index_Setting_Inform(void)
{
	return;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点インデックスデータをセットする
// 引数   ：const vector<unsigned int> & 設定するインデックスデータの参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Index_Setting_Inform::M_Set_Index_Setting(const std::vector<unsigned int> & in_set_index_data)
{
    // ☆ 変数宣言 ☆ //
    void * get_map_address = nullptr; // 頂点データ書き込み先のマップアドレス


    // ☆ インデックスバッファデータを設定 ☆ //

    // ☆ データのアドレスを入手 ☆ //    // 入手に失敗したら処理を停止
    if (FAILED(m_index_buffer_data->Map(0, nullptr, reinterpret_cast<void**>(&get_map_address))))
    {
        return;
    }


    // ☆ 変数宣言 ☆ //
    unsigned int * buffer_data = static_cast<unsigned int * >(get_map_address);    // 書き込み先バッファ（１バイトオフセット）

    int write_index_sum = 0;    // 書き込むインデックス数


    // 書き込もうとしているインデックス数がインデックスバッファのサイズを超えていたらインデックスバッファのサイズ分まで書き込む
    if (m_index_sum < in_set_index_data.size())
    {
		write_index_sum = m_index_sum;
	}

    // 書き込もうとしているインデックス数がインデックスバッファのサイズを超えていなかったら書き込もうとしているインデックス数分まで書き込む
    else
    {
		write_index_sum = in_set_index_data.size();
	}

    // インデックスバッファにデータを書き込む
    for (int index = 0; index < write_index_sum; index++)
    {
        buffer_data[index] = in_set_index_data[index];
    }

    // マッピング解除
    m_index_buffer_data->Unmap(0, nullptr);
    get_map_address = nullptr;
    buffer_data = nullptr;

	return;
}

