//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：深度ステンシルバッファの抽象化レイヤーとなる基底クラス
// 説明   ：派生クラスは深度ステンシルバッファをしようする時に、各レンダリングAPIごとに必要な情報をもつクラスとして作成する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_RENDERING_DEPTH_STENCIL_BUFFER_BASE_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_DEPTH_STENCIL_BUFFER_BASE_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_Texture_Map.h"


// ☆ ネームスペース ☆ //

// グラフィックを制御するシステムの情報を呼び出すための名前
namespace RENDERING::GRAPHICS::INSTANCE
{
	// ☆ クラス ☆ //

	// 深度ステンシルバッファの抽象化レイヤーとなる基底クラス
	class C_Rendering_Depth_Stencil_Buffer_Base
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Rendering_Depth_Stencil_Buffer_Base(void);
		
		// デストラクタ
		virtual ~C_Rendering_Depth_Stencil_Buffer_Base(void);

		// メモリの解放
		virtual void M_Release(void) = 0;


		//-☆- 画像 -☆-//

		// 深度ステンシルバッファ画面をテクスチャ画像として保存する　引数：保存先のテクスチャ画面の参照　戻り値：成功時のみtrue
		virtual bool M_Save_Screen_For_Texture(ASSET::TEXTURE::C_Texture_Map & ) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_DEPTH_STENCIL_BUFFER_BASE_H_FILE

