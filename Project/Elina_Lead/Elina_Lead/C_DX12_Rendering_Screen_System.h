//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：DX12のレンダリングスクリーン（レンダリング先画像）のシステム
// 説明   ：レンダーターゲットビューを管理する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード
#ifndef D_INCLUDE_GUARD_C_DX12_RENDERING_SCREEN_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_DX12_RENDERING_SCREEN_SYSTEM_H_FILE


// ☆ ファイルひらき ☆ //
#include <d3d12.h>
#include <wrl.h>
#include <vector>

#include "C_Rendering_Screen_System_Base.h"
#include "E_RENDERING_SCREEN_FORMAT.h"
#include "E_SCREEN_TEXTURE_SETTING.h"


// ☆ ネームスペース ☆ //

// DX12用のシステムを呼び出すための名前
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
    // ☆ 構造体 ☆ //

	// レンダーターゲットのバッファを定義する構造体
	struct S_DX12_Render_Target_Buffer
	{
		Microsoft::WRL::ComPtr<ID3D12Resource> render_buffer;	// レンダー先の画面バッファ

		D3D12_CPU_DESCRIPTOR_HANDLE handle;	// テクスチャリソース識別用情報(GPUのためにリソースを分解して変換する)
	};


	// レンダーターゲットビュー用の構造体
	struct S_DX12_Render_Target_View
	{
		std::vector<S_DX12_Render_Target_Buffer> buffer_list;	// レンダーターゲットのバッファリスト

		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> heap;	// デスクリプタを整理するための木構造データシステム

		D3D12_RESOURCE_STATES now_resource_barrier = D3D12_RESOURCE_STATES::D3D12_RESOURCE_STATE_PRESENT;	// このリソースのバリア状態
	};


    // ☆ クラス ☆ //

    // DX12のレンダリングスクリーンのクラス
	class C_DX12_Rendering_Screen_System : public RENDERING::GRAPHICS::INSTANCE::C_Rendering_Screen_System_Base
    {
        //==☆ パブリック ☆==//
    public:

        // ☆ 変数宣言 ☆ //
		S_DX12_Render_Target_View m_render_target_view;	// レンダーターゲットビュー用パラメータ

		int m_rendering_screen_sum = 0;	// レンダリング画面数


		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_DX12_Rendering_Screen_System(void);

		// デストラクタ
		~C_DX12_Rendering_Screen_System(void) override;

		// メモリの解放
		void M_Release(void) override;


		//-☆- 画像 -☆-//

		// 指定された番号のレンダリング画面をテクスチャ画像として保存する　引数：レンダリング画面番号, 保存先のテクスチャ画面の参照　戻り値：成功時のみtrue
		bool M_Save_Screen_For_Texture(int, ASSET::TEXTURE::C_Texture_Map & ) override;


		//-☆- ゲッタ -☆-//

		// レンダリング画面数を返す　戻り値：レンダリング画面数
		int M_Get_Rendering_Screen_Sum(void) override;
    };
}


#endif // !D_INCLUDE_GUARD_C_DX12_RENDERING_SCREEN_SYSTEM_H_FILE

