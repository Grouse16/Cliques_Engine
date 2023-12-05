//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリング画像を円滑に設定し、使用するためのシステム
// 説明   ：レンダリングAPIとの連携や、複雑な抽象化レイヤーのシステムのカプセル化を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#ifndef D_INCLUDE_GUARD_C_RENDERING_SCREEN_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_SCREEN_SYSTEM_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>

#include "C_Rendering_Screen_System_Base.h"
#include "E_RENDERING_SCREEN_FORMAT.h"
#include "E_SCREEN_TEXTURE_SETTING.h"


// ☆ ネームスペース ☆ //

// 描画に使用するシステムを呼び出すための名前
namespace RENDERING::CAPSULE
{
	// ☆ クラス ☆ //

	// レンダリング画面を使用するためのシステム
	class C_Rendering_Screen_System
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::unique_ptr<RENDERING::GRAPHICS::INSTANCE::C_Rendering_Screen_System_Base> rendering_screen;	// レンダリング画面

		} mpr_variable;	// プライベート変数を呼び出すための名前


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Rendering_Screen_System(void);

		// デストラクタ
		~C_Rendering_Screen_System(void);

		// レンダリング画面を削除する
		void M_Release(void);


		//-☆- 生成 -☆-//

		// レンダリング画面を生成する　引数：画面数, 画面のバイト数, 画面のテクスチャ設定　戻り値：成功時のみtrue
		bool M_Create_Rendering_Screen(int, RENDERING::INFORM::RENDERING_SCREEN::E_RENDERING_SCREEN_FORMAT, RENDERING::GRAPHICS::CREATE::E_SCREEN_TEXTURE_SETTING);


		//-☆- テクスチャ -☆-//

		// レンダリング画面をテクスチャ画像として保存する　引数：レンダリング画面番号, 保存先のテクスチャ画面の参照
		void M_Save_Screen_For_Texture(int, ASSET::TEXTURE::C_Texture_Map & );


		//-☆- 描画 -☆-//

		// レンダリング画像をレンダリング先として設定する　引数：レンダリング先とするレンダリング画像番号
		void M_Set_Render_Target(int);

		// 画面をクリアする
		void M_Clear_Screen(void);

		// 指定した画面のみをクリアする　引数：クリアする画面番号
		void M_Clear_Screen_By_Number(int);

		// 指定されたテクスチャのスロット番号にレンダリング画面の画像をセットする　引数：セットする画面番号, セットするスロット番号
		void M_Set_Rendering_Screen_To_Texture_Slot(int, int);
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_SCREEN_SYSTEM_H_FILE

