//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：DX12の頂点インデックスバッファのクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GAURD_C_DX12_INDEX_SETTING_INFORM_H_FILE
#define D_INCLUDE_GAURD_C_DX12_INDEX_SETTING_INFORM_H_FILE


// ☆ ファイルひらき ☆ //
#include <d3d12.h>
#include <wrl.h>

#include "C_Rendering_Index_Buffer_Setting_Inform_Base.h"


// ☆ ネームスペース ☆ //

// DX12用のシステムを呼び出すための名前
namespace RENDERING::API::DX12::DX12_INSTANCE
{
	// ☆ クラス ☆ //

	// DX12の頂点インデックスバッファのクラス
	class C_DX12_Index_Setting_Inform : public INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base
	{
	//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		D3D12_INDEX_BUFFER_VIEW m_index_buffer_view = D3D12_INDEX_BUFFER_VIEW();	// インデックスバッファビュー

		Microsoft::WRL::ComPtr<ID3D12Resource> m_index_buffer_data;	// インデックスバッファのデータ

		int m_index_sum = 0;	// インデックス数


		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_DX12_Index_Setting_Inform(void);

		// デストラクタ
		virtual ~C_DX12_Index_Setting_Inform(void) override;


		//-☆- セッタ -☆-//

		// 頂点インデックスデータをセットする　引数：設定するインデックスデータの参照
		void M_Set_Index_Setting(const std::vector<unsigned int> & ) override;
	};
}


#endif // !D_INCLUDE_GAURD_C_DX12_INDEX_SETTING_INFORM_H_FILE

