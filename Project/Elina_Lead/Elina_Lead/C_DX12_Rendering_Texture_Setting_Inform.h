//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：DX12のテスクチャのセット用のデータのクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_DX12_RENDERING_TEXTURE_SETTING_INFORM
#define D_INCLUDE_GUARD_C_DX12_RENDERING_TEXTURE_SETTING_INFORM


// ☆ ファイルひらき ☆ //
#include <wrl.h>
#include <d3d12.h>
#include <vector>

#include "E_Shader_Kind.h"
#include "C_Rendering_Texture_Setting_Inform_Base.h"


// ☆ ネームスペース ☆ //

// DX12用のシステムを呼び出すための名前
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
	// ☆ クラス ☆ //

	// DX12のテスクチャのセット用のデータのクラス
	class C_DX12_Rendering_Texture_Setting_Inform : public INSTANCE::C_Rendering_Texture_Setting_Inform_Base
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_texture_heap;	// テクスチャ用ヒープ

		Microsoft::WRL::ComPtr<ID3D12Resource> m_texture_data;	// テクスチャ用データ

		int m_pix_size_x = 0;	// テクスチャのピクセルサイズx
		int m_pix_size_y = 0;	// テクスチャのピクセルサイズy


		//-☆- 終了時 -☆-//

		// コンストラクタ
		C_DX12_Rendering_Texture_Setting_Inform(void);

		// デストラクタ
		virtual ~C_DX12_Rendering_Texture_Setting_Inform(void);

		// メモリを解放する
		void M_Delete(void);


		//-☆- 更新 -☆-//

		// テクスチャのデータをセットする　引数：設定する色配列への参照, テクスチャの横幅, テクスチャの縦幅
		void M_Set_Texture_Data(const std::vector<DATA::COLOR::C_Color> &, int, int) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_DX12_RENDERING_TEXTURE_SETTING_INFORM
