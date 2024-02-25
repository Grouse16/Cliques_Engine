//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリングAPIのフォントデータ用システムのインターフェース
// 説明   ：フォントに対する動作のみをまとめて提供する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_FONT_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_FONT_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>

#include "C_Rendering_Font_Inform_Base.h"
#include "S_Create_Font_Data_Inform.h"
#include "S_Make_Font_To_Graph_Pakage.h"


// ☆ ネームスペース ☆ //

// レンダリングAPI用のインターフェースを呼び出すための名前
namespace RENDERING::API::RENDER_INTERFACE
{
	// ☆ クラス ☆ //

	// レンダリングAPIのフォントシステムへの動作を行うクラス
	class C_Rendering_API_Interface_Font
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// インスタンス化防止のためにコンストラクタ隠蔽して削除
		C_Rendering_API_Interface_Font(void) = delete;


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- ロード -☆-//

		// フォントを指定されたフォント名を元にロードする　引数：設定先のフォントシステムの参照, フォントを生成するための情報の参照（const）　戻り値：成功時のみtrue
		static bool M_Load_Font(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Font_Inform_Base> & , const RENDERING::API::CREATE::S_Create_Font_Data_Inform & );


		//-☆- セッタ -☆-//

		// 渡された情報を元に文字列をマップにセットする　引数：フォントデータをテクスチャマップに移すための情報
		static void M_Set_Font_Map(PAKAGE::FONT::S_Make_Font_To_Graph_Package & );
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_FONT_H_FILE
