//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリングAPIに対する基本動作を行うためのインターフェース
// 説明   ：基本動作のみをまとめて提供する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_USER_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_USER_H_FILE


// ☆ ファイルひらき ☆ //
#include <string>

#include "C_Color.h"


// ☆ ネームスペース ☆ //

// レンダリングAPI用のインターフェースを呼び出すための名前
namespace RENDERING::API::RENDER_INTERFACE
{
	// ☆ クラス ☆ //

	// レンダリングAPIの基本動作を行うクラス
	class C_Rendering_API_Interface_User
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// インスタンス化防止のためにコンストラクタ隠蔽して削除
		C_Rendering_API_Interface_User(void) = delete;


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- レンダリング -☆-//

		// レンダリングの開始の実行
		static void M_Rendering_Start(void);

		// レンダリングの終了と描画バッファ切り替えの実行
		static void M_Rendering_End_And_Swap_Screen(void);


		//-☆- 判定 -☆-//

		// レンダリングAPIが正常であるかどうかをチェックする　戻り値：正常時のみtrue
		static bool M_Rendering_API_Safe_Check(void);


		//-☆- ゲッタ -☆-//

		// 現在のレンダリングシステムのシェーダーのフォルダまでのパスを返す　戻り値：シェーダーまでのパス
		static std::string M_Get_Shader_Folder_Path(void);

		// 現在のレンダリングシステムのシェーダーの拡張子を返す　戻り値：シェーダーの拡張子
		static std::string M_Get_Shader_Extension(void);


		//-☆- セッタ -☆-//

		// 画面をクリアする色を設定する　引数：セットする色
		static void M_Set_Screen_Clear_Color(DATA::COLOR::C_Color);
	};
}



#endif // !D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_USER_H_FILE
