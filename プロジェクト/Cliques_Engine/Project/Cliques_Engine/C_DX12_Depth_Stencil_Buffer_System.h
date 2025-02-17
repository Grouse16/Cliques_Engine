//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：DX12の深度ステンシルバッファシステム
// 説明   ：深度ステンシルバッファ用のデータを管理する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_DX12_DEPTH_STENCIL_BUFFER_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_DX12_DEPTH_STENCIL_BUFFER_SYSTEM_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_Rendering_Depth_Stencil_Buffer_Base.h"

#include <d3d12.h>
#include <wrl.h>


// ☆ ネームスペース ☆ //

// DX12用のシステムを呼び出すための名前
namespace RENDERING::API::DX12::DX12_INSTANCE
{
	// ☆ 構造体 ☆ //

	// 深度ステンシルのバッファを定義する構造体
	struct S_DX12_Depth_Stencil_Buffer
	{
		Microsoft::WRL::ComPtr<ID3D12Resource> depth_stencil_buffer;	// 深度ステンシル用のバッファ

		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> heap;	// デスクリプタを整理するための木構造データシステム

		D3D12_CPU_DESCRIPTOR_HANDLE handle = D3D12_CPU_DESCRIPTOR_HANDLE();	// テクスチャリソース識別用情報(GPUのためにリソースを分解して変換する
	};


	// ☆ クラス ☆ //

	// DX12の深度ステンシルバッファのクラス
	class C_DX12_Depth_Stencil_Buffer_System : public RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		S_DX12_Depth_Stencil_Buffer m_data;	// 深度ステンシルバッファ用パラメータ
		

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_DX12_Depth_Stencil_Buffer_System(void);

		// デストラクタ
		~C_DX12_Depth_Stencil_Buffer_System(void) override;

		// メモリの解放
		void M_Release(void) override;


		//-☆- 画像 -☆-//

		// 深度ステンシルバッファ画面をテクスチャ画像として保存する　引数：保存先のテクスチャ画面の参照　戻り値：成功時のみtrue
		bool M_Save_Screen_For_Texture(ASSET::TEXTURE::C_Texture_Map & ) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_DX12_DEPTH_STENCIL_BUFFER_SYSTEM_H_FILE
