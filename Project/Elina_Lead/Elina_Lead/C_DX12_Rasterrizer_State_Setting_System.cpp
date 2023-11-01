//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ラスタライザ設定用のクラス
// 説明   ：ラスタライザの設定用の処理をまとめるためのクラス
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_DX12_Rasterrizer_State_Setting_System.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 設定 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：低いコストでラスタライズする際の設定を行う
// 引数   ：D3D12_GRAPHICS_PIPELINE_STATE_DESC & パイプライン生成用情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_DX12_Rasterrizer_State_Setting_System::M_Law_Cost_Setting(D3D12_GRAPHICS_PIPELINE_STATE_DESC & in_pso_desc)
{
    // レンダリング結果を画面に反映するときのモード
    in_pso_desc.RasterizerState.FillMode = D3D12_FILL_MODE_SOLID;

    // 面(三角形)の方向によって表示するかしないかを指定する
    in_pso_desc.RasterizerState.CullMode = D3D12_CULL_MODE_NONE;

    // 反時計回りを表、時計回りを裏と判定するかどうか
    in_pso_desc.RasterizerState.FrontCounterClockwise = false;

    // ピクセルに対する深度バイアス(奥行き表現)
    in_pso_desc.RasterizerState.DepthBias = D3D12_DEFAULT_DEPTH_BIAS;

    // ピクセルの深度バイアスの最大値
    in_pso_desc.RasterizerState.DepthBiasClamp = D3D12_DEFAULT_DEPTH_BIAS_CLAMP;

    // 傾斜表現のためのスカラー
    in_pso_desc.RasterizerState.SlopeScaledDepthBias = D3D12_DEFAULT_SLOPE_SCALED_DEPTH_BIAS;

    // 距離によるクリッピング(色のはみ出しの防止)をするかどうかのフラグ
    in_pso_desc.RasterizerState.DepthClipEnable = true;

    // 四角形線(TRUE)かアルファ線(FALSE)かどっちのアンチエイリアシングアルゴリズムを使用するか
    in_pso_desc.RasterizerState.MultisampleEnable = false;

    // 回線アンチエイリアシングを有効にするかどうか
    in_pso_desc.RasterizerState.AntialiasedLineEnable = false;

    // UAVのラスタライズで強制するサンプル数
    in_pso_desc.RasterizerState.ForcedSampleCount = 0;

    // 保守的なラスタライズを行うかどうか(保守か効率か)
    in_pso_desc.RasterizerState.ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;

	return;
}
