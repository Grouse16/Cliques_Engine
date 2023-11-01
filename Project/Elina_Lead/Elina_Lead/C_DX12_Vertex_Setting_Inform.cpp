//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：DX12の頂点バッファのセット用データのクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Vertex_Buffer_Setting_Inform_Base.h"
#include "C_DX12_Vertex_Setting_Inform.h"


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
C_DX12_Vertex_Setting_Inform::C_DX12_Vertex_Setting_Inform(void)
{

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_DX12_Vertex_Setting_Inform::~C_DX12_Vertex_Setting_Inform(void)
{

	return;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：頂点データをセットする
// 引数   ：void * 頂点データのアドレス
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Vertex_Setting_Inform::M_Set_Vertex_Setting(void * in_vertex_add)
{
    // ☆ 変数宣言 ☆ //
    UINT8 * add_map = nullptr; // 頂点データ書き込み先のマップアドレス


    // マップを入手出来なかったらエラーを出して抜ける
    if (FAILED(m_vertex_buffer_data->Map(0, nullptr, reinterpret_cast<void**>(&add_map))))
    {
        return;
    }


    // マップに頂点情報を書き込む
    memcpy(add_map, in_vertex_add, m_vertex_buffer_view.SizeInBytes);


    // マップを解放
    m_vertex_buffer_data->Unmap(0, nullptr);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：インデックスデータをセットする
// 引数   ：void * インデックスデータのアドレス
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Vertex_Setting_Inform::M_Set_Index_Setting(void * in_index_add)
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
    unsigned char* buffer_data = static_cast<unsigned char*>(get_map_address);    // 書き込み先バッファ（１バイトオフセット）


    // インデックスデータをコピーして設定
    memcpy(buffer_data, in_index_add, m_index_buffer_view.SizeInBytes);


    // マッピング解除
    m_index_buffer_data->Unmap(0, nullptr);
    get_map_address = nullptr;
    buffer_data = nullptr;

    return;
}
