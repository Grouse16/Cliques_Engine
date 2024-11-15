//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：DX12の頂点バッファのセット用データのクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Rendering_Vertex_Buffer_Setting_Inform_Base.h"
#include "C_DX12_Vertex_Setting_Inform.h"


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

