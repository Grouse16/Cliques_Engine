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

//==☆ プライベート ☆==//

//-☆- 設定 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された情報と一致した深度値の書き込み方法を返す
// 引数   ：E_DEPTH_WRITE_RULE 深度値書き込みルール
// 戻り値 ：D3D12_COMPARISON_FUNC 深度値の書き込み方法
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
D3D12_COMPARISON_FUNC C_DX12_Stencil_State_Setting_System::M_Get_Depth_Write_Option(RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE in_write_rule)
{
    //-☆- 書き込む時のルールによって設定を分岐 -☆-//
    switch (in_write_rule)
    {
        // 書き込まない
    case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_DONT:
    default:
        return D3D12_COMPARISON_FUNC::D3D12_COMPARISON_FUNC_NEVER;

        // 全て上書きする
    case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_ALWAYS:
        return D3D12_COMPARISON_FUNC::D3D12_COMPARISON_FUNC_ALWAYS;

        // 元の値と等しいとき
    case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_EQUAL:
        return D3D12_COMPARISON_FUNC::D3D12_COMPARISON_FUNC_EQUAL;

        // 元の値と違うとき
    case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_NOT_EQUAL:
        return D3D12_COMPARISON_FUNC::D3D12_COMPARISON_FUNC_NOT_EQUAL;

        // 元の値よりも大きいとき
    case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_GREATER:
        return D3D12_COMPARISON_FUNC::D3D12_COMPARISON_FUNC_GREATER;

        // 元の値よりも小さいとき
    case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_LESS:
        return D3D12_COMPARISON_FUNC::D3D12_COMPARISON_FUNC_LESS;

        // 元の値以上のとき
    case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_GREATERE_EQUAL:
        return D3D12_COMPARISON_FUNC::D3D12_COMPARISON_FUNC_GREATER_EQUAL;

        // 元の値以下のとき
    case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_WRITE_RULE::e_LESS_EQUAL:
        return D3D12_COMPARISON_FUNC::D3D12_COMPARISON_FUNC_LESS_EQUAL;
    }
}


//==☆ パブリック ☆==//

//-☆- 設定 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：深度ステンシルを生成用情報をもとに設定する
// 引数   ：D3D12_GRAPHICS_PIPELINE_STATE_DESC & パイプライン設定用情報, const C_Create_Rendering_Graphics_Setting_Inform & レンダリング生成用情報(const)
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Stencil_State_Setting_System::M_Depth_Stencil_Setting(D3D12_GRAPHICS_PIPELINE_STATE_DESC & in_pipeline_state_setting_desc, const RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform & in_create_inform)
{
    //-☆- 深度のモードによって設定を分岐 -☆-//
    switch (in_create_inform.depth_stencil_data.mode)
    {
        // 深度を無効
    case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE::e_NO:
    default:

        // 深度を有効にするかどうか
        in_pipeline_state_setting_desc.DepthStencilState.DepthEnable = FALSE;

        // 深度バッファへの書き込みを行うかどうか
        in_pipeline_state_setting_desc.DepthStencilState.DepthWriteMask = D3D12_DEPTH_WRITE_MASK::D3D12_DEPTH_WRITE_MASK_ZERO;

        break;

        // 変更できる範囲を０に指定
    case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE::e_ZERO:

        // 深度を有効にするかどうか
        in_pipeline_state_setting_desc.DepthStencilState.DepthEnable = TRUE;

        // 上書きすることができる範囲
        in_pipeline_state_setting_desc.DepthStencilState.DepthWriteMask = D3D12_DEPTH_WRITE_MASK::D3D12_DEPTH_WRITE_MASK_ZERO;

        break;

        // 変更できる範囲を１に指定
    case RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_MODE::e_ONE:

        // 深度を有効にするかどうか
        in_pipeline_state_setting_desc.DepthStencilState.DepthEnable = TRUE;

        // 上書きすることができる範囲
        in_pipeline_state_setting_desc.DepthStencilState.DepthWriteMask = D3D12_DEPTH_WRITE_MASK::D3D12_DEPTH_WRITE_MASK_ALL;

        break;
    }

    
    // 深度の書き込み方法を指定
    in_pipeline_state_setting_desc.DepthStencilState.DepthFunc = M_Get_Depth_Write_Option(in_create_inform.depth_stencil_data.write_rule);


    //-☆- ステンシルを有効にするかどうかで設定を分岐 -☆-//
    switch (in_create_inform.depth_stencil_data.stencil_activate)
    {
        // 無効
    case RENDERING::INFORM::DEPTH_STENCIL::E_STENCIL_IS::e_NO_ACTIVE:

        in_pipeline_state_setting_desc.DepthStencilState.StencilEnable = FALSE;
        break;

        // 有効
    case RENDERING::INFORM::DEPTH_STENCIL::E_STENCIL_IS::e_ACTIVE:

        in_pipeline_state_setting_desc.DepthStencilState.StencilEnable = TRUE;
        break;
    }

    // ステンシルデータ読み取り時の設定
    in_pipeline_state_setting_desc.DepthStencilState.StencilReadMask = D3D12_DEFAULT_STENCIL_READ_MASK;

    // ステンシルデータ書き込み時の設定
    in_pipeline_state_setting_desc.DepthStencilState.StencilWriteMask = D3D12_DEFAULT_STENCIL_WRITE_MASK;

    // 深度ステンシルに送るリソースのデータ形式
    in_pipeline_state_setting_desc.DSVFormat = DXGI_FORMAT::DXGI_FORMAT_D32_FLOAT;

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
