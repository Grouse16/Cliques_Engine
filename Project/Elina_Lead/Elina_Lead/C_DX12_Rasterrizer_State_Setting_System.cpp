//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ラスタライザ設定用のクラス
// 説明   ：ラスタライザの設定用の処理をまとめるためのクラス
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_DX12_Rasterizer_State_Setting_System.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 設定 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された情報を元にラスタライザの設定を行う
// 引数   ：D3D12_GRAPHICS_PIPELINE_STATE_DESC & パイプライン設定用情報, const C_Create_Rendering_Graphics_Setting_Inform & レンダリング生成用情報(const)
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Rasterizer_State_Setting_System::M_Rasterizer_Setting(D3D12_GRAPHICS_PIPELINE_STATE_DESC & in_pipeline_state_setting_desc, const RENDERING::GRAPHICS::CREATE::S_Create_Rendering_Graphics_Setting_Inform & in_create_inform)
{
    //-☆- 表示モードによって設定内容を分岐 -☆-//
    switch (in_create_inform.rasterizer_data.draw_mode)
    {
        // 通常通りの描画
    case RENDERING::INFORM::RASTERIZER::E_DRAW_MODE::e_NORMAL:
    default:
        in_pipeline_state_setting_desc.RasterizerState.FillMode = D3D12_FILL_MODE::D3D12_FILL_MODE_SOLID;
        break;

        // ワイヤーフレーム表示（辺のみ描画）
    case RENDERING::INFORM::RASTERIZER::E_DRAW_MODE::e_WIRE_FRAME:
        in_pipeline_state_setting_desc.RasterizerState.FillMode = D3D12_FILL_MODE::D3D12_FILL_MODE_WIREFRAME;
        break;
    }


    //-☆- カリング方法の指定によって設定内容を分岐 -☆-//
    switch (in_create_inform.rasterizer_data.mesh_culling)
    {
        // カリングはしない
    case RENDERING::INFORM::RASTERIZER::E_MESH_CULLING::e_ALWAYS:
        in_pipeline_state_setting_desc.RasterizerState.CullMode = D3D12_CULL_MODE::D3D12_CULL_MODE_NONE;
        break;

        // 裏面をカリング
    case RENDERING::INFORM::RASTERIZER::E_MESH_CULLING::e_FRONT:
        in_pipeline_state_setting_desc.RasterizerState.CullMode = D3D12_CULL_MODE::D3D12_CULL_MODE_NONE;
        break;

        // 前面をカリング
    case RENDERING::INFORM::RASTERIZER::E_MESH_CULLING::e_BACK:
        in_pipeline_state_setting_desc.RasterizerState.CullMode = D3D12_CULL_MODE::D3D12_CULL_MODE_NONE;
        break;
    }


    //-☆- 表向きの方向によって設定内容を分岐 -☆-//
    switch (in_create_inform.rasterizer_data.mesh_front)
    {
        // 時計回りが表向き
    case RENDERING::INFORM::RASTERIZER::E_MESH_FRONT::e_CLOCK_WISE:
        in_pipeline_state_setting_desc.RasterizerState.FrontCounterClockwise = FALSE;
        break;

        // 反時計回りが表向き
    case RENDERING::INFORM::RASTERIZER::E_MESH_FRONT::e_ANTI_CLOCK_WISE:
        in_pipeline_state_setting_desc.RasterizerState.FrontCounterClockwise = TRUE;
        break;
    }


    //-☆- 深度に関する値を設定 -☆-//

    // ピクセルに対する深度バイアス(奥行き値を強制的に加算)
    in_pipeline_state_setting_desc.RasterizerState.DepthBias = in_create_inform.rasterizer_data.depth_value.depth_bias;

    // ピクセルの深度バイアスの最大値
    in_pipeline_state_setting_desc.RasterizerState.DepthBiasClamp = in_create_inform.rasterizer_data.depth_value.depth_max;

    // 深度バイアスの最大値が設定されているときのみ深度値のクリッピング有効
    if (in_pipeline_state_setting_desc.RasterizerState.DepthBiasClamp > 0.0f)
    {
        in_pipeline_state_setting_desc.RasterizerState.DepthClipEnable = TRUE;
    }
    // 設定されていないなら無効
    else
    {
        in_pipeline_state_setting_desc.RasterizerState.DepthClipEnable = FALSE;
    }

    // 傾斜表現のためのスロープ表現強度
    in_pipeline_state_setting_desc.RasterizerState.SlopeScaledDepthBias = in_create_inform.rasterizer_data.depth_value.depth_slope;


    //-☆- アンチエイリアシングの方法によって設定を分岐 -☆-//
    switch (in_create_inform.rasterizer_data.antialiasing)
    {
        // ピクセルによる補間
    case RENDERING::INFORM::RASTERIZER::E_ANTIALIASING::e_PIXEL:

        // 四角形線(TRUE)かアルファ線(FALSE)かどっちのアンチエイリアシングアルゴリズムを使用するか
        in_pipeline_state_setting_desc.RasterizerState.MultisampleEnable = TRUE;

        // 回線アンチエイリアシングを有効にするかどうか
        in_pipeline_state_setting_desc.RasterizerState.AntialiasedLineEnable = FALSE;
        break;

        // アルファ値による補間　（DirectXにアンチエイリアシングをしないという項目はない）
    case RENDERING::INFORM::RASTERIZER::E_ANTIALIASING::e_ALPHA:
    case RENDERING::INFORM::RASTERIZER::E_ANTIALIASING::e_DONT:
    default:

        // 四角形線(TRUE)かアルファ線(FALSE)かどっちのアンチエイリアシングアルゴリズムを使用するか
        in_pipeline_state_setting_desc.RasterizerState.MultisampleEnable = FALSE;

        // 辺基準でのアンチエイリアシングを有効にするかどうか
        in_pipeline_state_setting_desc.RasterizerState.AntialiasedLineEnable = FALSE;
        break;

        // 辺基準での補間
    case RENDERING::INFORM::RASTERIZER::E_ANTIALIASING::e_LINE:

        // 四角形線(TRUE)かアルファ線(FALSE)かどっちのアンチエイリアシングアルゴリズムを使用するか
        in_pipeline_state_setting_desc.RasterizerState.MultisampleEnable = FALSE;

        // 回線アンチエイリアシングを有効にするかどうか
        in_pipeline_state_setting_desc.RasterizerState.AntialiasedLineEnable = FALSE;
        break;
    }


    // UAVのラスタライズで強制するサンプル数
    in_pipeline_state_setting_desc.RasterizerState.ForcedSampleCount = in_create_inform.sampling_setting.sampling_count;


    //-☆- 保守的なラスタライズを行うかを設定 -☆-//
    switch (in_create_inform.rasterizer_data.flg_conservative)
    {
        // 無効
    case false:
    default:
        in_pipeline_state_setting_desc.RasterizerState.ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE::D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;
        break;

        // 有効
    case true:
        in_pipeline_state_setting_desc.RasterizerState.ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE::D3D12_CONSERVATIVE_RASTERIZATION_MODE_ON;
        break;
    }

	return;
}
