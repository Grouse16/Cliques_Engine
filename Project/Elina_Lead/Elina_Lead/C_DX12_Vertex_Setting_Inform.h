//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：DX12の頂点バッファのセット用データのクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_DX12_VERTEX_SETTING_INFORM_H_FILE
#define D_INCLUDE_GUARD_C_DX12_VERTEX_SETTING_INFORM_H_FILE


// ☆ ファイルひらき ☆ //
#include <d3d12.h>
#include <wrl.h>

#include "C_Rendering_Vertex_Buffer_Setting_Inform_Base.h"


// ☆ ネームスペース ☆ //

// DX12用のシステムを呼び出すための名前
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
	// ☆ クラス ☆ //

	// DX12の頂点バッファのセット用データのクラス
	class C_DX12_Vertex_Setting_Inform : public INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		D3D12_VERTEX_BUFFER_VIEW m_vertex_buffer_view;	// 頂点バッファビューのアドレス

		D3D12_INDEX_BUFFER_VIEW m_index_buffer_view;	// インデックスバッファビューのアドレス

		Microsoft::WRL::ComPtr<ID3D12Resource> m_vertex_buffer_data;	// 頂点バッファのデータ
		Microsoft::WRL::ComPtr<ID3D12Resource> m_index_buffer_data;	// インデックスバッファのデータ

		int m_draw_index_sum = 0;	// 描画する回数（インデックス数）


		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_DX12_Vertex_Setting_Inform(void);

		// デストラクタ
		virtual ~C_DX12_Vertex_Setting_Inform(void) override;


		//-☆- セッタ -☆-//

		// 頂点データをセットする　引数：頂点データのアドレス
		void M_Set_Vertex_Setting(void*) override;

		// インデックスデータをセットする　引数：インデックスデータ
		void M_Set_Index_Setting(void*) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_DX12_VERTEX_SETTING_INFORM_H_FILE

