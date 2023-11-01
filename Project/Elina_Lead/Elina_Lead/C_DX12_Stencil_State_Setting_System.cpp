//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：深度ステンシル設定用のクラス
// 説明   ：深度ステンシルの設定用の処理をまとめるためのクラス
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_DX12_Stencil_State_Setting_System.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 設定 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：深度ステンシルを無効にする時の設定
// 引数   ：D3D12_GRAPHICS_PIPELINE_STATE_DESC & パイプライン生成用情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Stencil_State_Setting_System::M_Disabled_Depth_Stencil(D3D12_GRAPHICS_PIPELINE_STATE_DESC & in_pso_desc)
{
    // 深度ステンシルを有効にするかどうか
    in_pso_desc.DepthStencilState.DepthEnable = false;

    // 深度ステンシルバッファへの書き込みを行うかどうか
    in_pso_desc.DepthStencilState.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ZERO;

    // ランタイムが新しいオブジェクトを既存のデータと比較する方法
    in_pso_desc.DepthStencilState.DepthFunc = D3D12_COMPARISON_FUNC_ALWAYS;

    // ステンシルテストを有効にするかどうか
    in_pso_desc.DepthStencilState.StencilEnable = false;

    // ステンシルデータ読み取り時の設定
    in_pso_desc.DepthStencilState.StencilReadMask = D3D12_DEFAULT_STENCIL_READ_MASK;

    // ステンシルデータ書き込み時の設定
    in_pso_desc.DepthStencilState.StencilWriteMask = D3D12_DEFAULT_STENCIL_WRITE_MASK;

    // 深度ステンシルに送るリソースのデータ形式
    in_pso_desc.DSVFormat = DXGI_FORMAT_D32_FLOAT;

	return;
}


//-☆- テスト設定 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：深度ステンシルを無効にする時の設定
// 引数   ：D3D12_DEPTH_STENCILOP_DESC & パイプライン生成用情報のステンシルテスト設定部分
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Stencil_State_Setting_System::M_Test_Keep_Setting(D3D12_DEPTH_STENCILOP_DESC & in_stencil_op)
{
    // ステンシルテスト失敗したときにどうするか
    in_stencil_op.StencilFailOp = D3D12_STENCIL_OP_KEEP;

    // 深度テストに失敗したときにどうするか
    in_stencil_op.StencilDepthFailOp = D3D12_STENCIL_OP_KEEP;

    // ステンシルと深度両方のテストが成功したときにどうするか
    in_stencil_op.StencilPassOp = D3D12_STENCIL_OP_KEEP;

    // 新しいステンシルデータと今のデータの比較方法
    in_stencil_op.StencilFunc = D3D12_COMPARISON_FUNC_ALWAYS;

    return;
}
