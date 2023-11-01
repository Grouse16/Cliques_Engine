//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：DX12のレンダリング設定用データのセット用のデータのクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_DX12_RENDERING_GRAPHICS_SETTING_INFORM
#define D_INCLUDE_GUARD_C_DX12_RENDERING_GRAPHICS_SETTING_INFORM


// ☆ ファイルひらき ☆ //
#include <wrl.h>
#include <d3d12.h>

#include "C_Rendering_Graphics_Setting_Inform_Base.h"
#include "S_Shader_Resource_Signature_Inform.h"
#include "C_Shader_Setting.h"


// ☆ ネームスペース ☆ //

// DX12用のシステムを呼び出すための名前
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
	// ☆ クラス ☆ //

	// DX12のレンダリング設定用データのセット用のデータのクラス
	class C_DX12_Rendering_Graphics_Setting_Inform : public INSTANCE::C_Rendering_Graphics_Setting_Inform_Base
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		Microsoft::WRL::ComPtr<ID3D12RootSignature> m_root_signature;	// ルート著名のアドレス

		Microsoft::WRL::ComPtr<ID3D12PipelineState> m_pipeline_state_setting;	// 描画パイプライン設定

		D3D12_PRIMITIVE_TOPOLOGY m_topology_type = D3D12_PRIMITIVE_TOPOLOGY::D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;	// 描画する図形の種類

		ASSET::SHADER::C_Shader_Setting m_shader_setting;	// シェーダーの情報


		//-☆- 終了時 -☆-//

		// コンストラクタ
		C_DX12_Rendering_Graphics_Setting_Inform(void);

		// デストラクタ
		virtual ~C_DX12_Rendering_Graphics_Setting_Inform(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_DX12_RENDERING_GRAPHICS_SETTING_INFORM
