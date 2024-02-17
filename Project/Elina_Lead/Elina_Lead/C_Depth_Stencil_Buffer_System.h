//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：深度ステンシルバッファの情報を円滑に設定し、レンダリングするためのシステム
// 説明   ：深度ステンシルバッファのレンダリングをカプセル化する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_DEPTH_STENCIL_BUFFER_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_DEPTH_STENCIL_BUFFER_SYSTEM_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>

#include "C_Rendering_Depth_Stencil_Buffer_Base.h"
#include  "E_DEPTH_STENCIL_BUFFER_PIXEL_BYTE_FORMAT.h"


// ☆ ネームスペース ☆ //

// 描画に使用するシステムを呼び出すための名前
namespace RENDERING::CAPSULE
{
	// ☆ クラス ☆ //

	// 深度ステンシルバッファ用のシステム
	class C_Depth_Stencil_Buffer_System
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた変数
		struct SPr_Variable
		{
			std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> depth_stencil_buffer;	// 深度ステンシルバッファシステム

		} mpr_variable;	// プライベート変数を呼び出すための名前


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Depth_Stencil_Buffer_System(void);

		// デストラクタ
		~C_Depth_Stencil_Buffer_System(void);

		// メモリを解放する
		void M_Release(void);


		//-☆- ロード -☆-//

		// 深度ステンシルバッファをロードする　引数：深度ステンシルバッファのバイトフォーマット　戻り値：成功時のみtrue
		bool M_Load_Depth_Stencil_Buffer(RENDERING::INFORM::DEPTH_STENCIL::E_DEPTH_STENCIL_BUFFER_PIXEL_BYTE_FORMAT);


		//-☆- 描画 -☆-//

		// 深度ステンシルバッファをクリアする
		void M_Clear_Depth_Stencil_Buffer(void);

		// 深度ステンシルバッファを指定されたテクスチャスロットにセットする　引数：テクスチャスロット番号
		void M_Set_Depth_Stencil_Buffer_To_Texture_Slot(int);

		// 深度ステンシルバッファをレンダリング先として設定する
		void M_Set_Depth_Stencil_Buffer_To_Render_Target(void);
		
		// 深度ステンシルバッファをテクスチャに変換する　引数：設定先のテクスチャの参照
		void M_Save_Depth_Stencil_Buffer_To_Texture(ASSET::TEXTURE::C_Texture_Map & );

		// 深度ステンシルバッファをメインの深度ステンシルバッファに戻す
		void M_Reset_Draw_Depth_Stencil_Buffer(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_DEPTH_STENCIL_BUFFER_SYSTEM_H_FILE

