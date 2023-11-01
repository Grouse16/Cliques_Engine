//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：サンプリング設定用のクラス
// 説明   ：サンプリング設定用の処理をまとめるためのクラス
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_DX12_Sampling_Setting_System.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 設定 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：サンプリング設定をまとめて行う
// 引数   ：引数：D3D12_GRAPHICS_PIPELINE_STATE_DESC & パイプライン生成用情報, UINT サンプリング回数, UINT クオリティ, UINT ノード数
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Sampling_Setting_System::M_Sampling_Setting(D3D12_GRAPHICS_PIPELINE_STATE_DESC & in_pso_desc, UINT in_sampling_count, UINT in_quality, UINT in_node_sum)
{
    // １ピクセルに対してレンダリングサンプルを用意する数
    in_pso_desc.SampleDesc.Count = in_sampling_count;

    // 画質のレベル、高いと画質が良くなるがパフォーマンスが悪くなる
    in_pso_desc.SampleDesc.Quality = in_quality;

    // パイプラインに適応するノード(GPUや物理アダプター)の数
    in_pso_desc.NodeMask = in_node_sum;

	return;
}
