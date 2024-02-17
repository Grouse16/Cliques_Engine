//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリングAPIの深度ステンシル用システムのインターフェース
// 説明   ：深度ステンシルに対する動作のみをまとめて提供する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_DEPTH_STECIL_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_DEPTH_STECIL_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>

#include "C_Rendering_Depth_Stencil_Buffer_Base.h"
#include "S_Create_Depth_Stencil_Buffer_Inform.h"


// ☆ ネームスペース ☆ //

// レンダリングAPI用のインターフェースを呼び出すための名前
namespace RENDERING::API::RENDER_INTERFACE
{
	// ☆ クラス ☆ //

	// レンダリングAPIのレンダリング画面システムへの動作を行うクラス
	class C_Rendering_API_Interface_Depth_Stencil
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// インスタンス化防止のためにコンストラクタ隠蔽して削除
		C_Rendering_API_Interface_Depth_Stencil(void) = delete;


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 生成 -☆-//

		// 深度ステンシルバッファを生成する　引数：設定先の深度ステンシルバッファの参照, 深度ステンシルバッファを生成するための情報の参照（const）　戻り値：成功時のみtrue
		static bool M_Create_Depth_Stencil_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & , const RENDERING::API::CREATE::S_Create_Depth_Stencil_Buffer_Inform & );


		//-☆- 解放 -☆-//

		// 深度ステンシルバッファの削除を通知する　引数：削除された深度ステンシルバッファのアドレス（const）
		static void M_Notice_Depth_Stencil_Buffer_Deleted(const RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base * );

		// 深度ステンシルバッファをリセットする
		static void M_Reset_Draw_Depth_Stencil_Buffer(void);


		//-☆- クリア -☆-//

		// 深度ステンシルバッファをクリアする　引数：クリアする深度ステンシルバッファの参照
		static void M_Clear_Depth_Stencil_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & );


		//-☆- 描画 -☆-//

		// 深度ステンシルバッファを描画用にセットする　引数：設定する深度ステンシルバッファの参照
		static void M_Set_Depth_Stencil_Buffer_To_Rendering(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & );

		// 深度ステンシルバッファをGPU用リソースのテクスチャスロットにセット　引数：設定先のスロット番号, 設定する深度ステンシルバッファの参照
		static void M_Set_Depth_Stencil_Buffer_To_Texture_Slot(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & );
	};
}

#endif // !D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_DEPTH_STECIL_H_FILE
