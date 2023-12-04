//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリングスクリーン（レンダリング先画像）のデータを保持するシステムの基底クラス
// 説明   ：書き込むレンダリング先画像の設定や、レンダリング先画像を画像に変換またはシェーダーによる画像としての使用をするためのレンダリング先画像を管理する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//

 
// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_RENDERING_SCREEN_SYSTEM_BASE_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_SCREEN_SYSTEM_BASE_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_Texture_Map.h"


// ☆ ネームスペース ☆ //

// グラフィックを制御するシステムの情報を呼び出すための名前
namespace RENDERING::GRAPHICS::INSTANCE
{
	// ☆ クラス ☆ //

	// レンダリングスクリーン（レンダリング先画像）のデータを保持するシステムの基底クラス
	class C_Rendering_Screen_System_Base
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Rendering_Screen_System_Base(void);

		// デストラクタ
		virtual ~C_Rendering_Screen_System_Base(void);

		// メモリの解放
		virtual void M_Release(void) = 0;


		//-☆- 画像 -☆-//

		// 指定された番号のレンダリング画面をテクスチャ画像として保存する　引数：レンダリング画面番号, 保存先のテクスチャ画面の参照　戻り値：成功時のみtrue
		virtual bool M_Save_Screen_For_Texture(int, ASSET::TEXTURE::C_Texture_Map & ) = 0;


		//-☆- ゲッタ -☆-//

		// レンダリング画面数を返す　戻り値：レンダリング画面数
		virtual int M_Get_Rendering_Screen_Sum(void) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_SCREEN_SYSTEM_BASE_H_FILE

