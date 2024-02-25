//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリングAPIのレンダリング設定のインターフェース
// 説明   ：レンダリング設定に対する動作のみをまとめて提供する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_RENDERING_SETTING_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_RENDERING_SETTING_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>

#include "C_Rendering_Graphics_Setting_Inform_Base.h"
#include "S_Create_Rendering_Graphics_Setting_Inform.h"


// ☆ ネームスペース ☆ //

// レンダリングAPI用のインターフェースを呼び出すための名前
namespace RENDERING::API::RENDER_INTERFACE
{
	// ☆ クラス ☆ //

	// レンダリングAPIのレンダリング設定への動作を行うクラス
	class C_Rendering_API_Interface_Rendering_Setting
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// インスタンス化防止のためにコンストラクタ隠蔽して削除
		C_Rendering_API_Interface_Rendering_Setting(void) = delete;


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 生成 -☆-//

		// レンダリング設定の生成　引数：設定先のレンダリング設定の参照, 生成用の情報の参照（const）　戻り値：成功時のみtrue
		static bool M_Create_Rendering_Setting(std::unique_ptr <RENDERING::API::INSTANCE::C_Rendering_Graphics_Setting_Inform_Base> & , const RENDERING::API::CREATE::S_Create_Rendering_Graphics_Setting_Inform & );


		//-☆- 描画 -☆-//

		// レンダリング設定を描画用にセットする　引数：セットするレンダリング設定の参照
		static void M_Set_Rendering_Setting_To_Draw(std::unique_ptr <RENDERING::API::INSTANCE::C_Rendering_Graphics_Setting_Inform_Base> & );
	};
}

#endif // !D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_RENDERING_SETTING_H_FILE
