//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ストリーミング出力用バッファの基底クラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_DX12_Streaming_Output_Buffer_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::API::DX12::DX12_TOOL;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ストリーミング出力用バッファを使用しない時の初期化を行う
// 引数   ：D3D12_GRAPHICS_PIPELINE_STATE_DESC & パイプライン生成用情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Streaming_Output_Buffer_Base::M_Do_Not_Use_Setting(D3D12_GRAPHICS_PIPELINE_STATE_DESC & in_pipeline_desc)
{
    // ストリーミング出力スロットの頂点バッファの頂点要素用の構造体の配列のアドレス
    in_pipeline_desc.StreamOutput.pSODeclaration = nullptr;

    // 上記、頂点バッファの頂点要素用の構造体の配列の配列数
    in_pipeline_desc.StreamOutput.NumEntries = 0;

    // 頂点のストライド(ピッチ)の配列のアドレス（バッファの要素のサイズ）
    in_pipeline_desc.StreamOutput.pBufferStrides = nullptr;

    // 上記、頂点のストライド(ピッチ)の配列の配列数
    in_pipeline_desc.StreamOutput.NumStrides = 0;

    // ラスタライザーに送るストリーム出力バッファの画面番号(インデックス番号)
    in_pipeline_desc.StreamOutput.RasterizedStream = 0;

	return;
}
