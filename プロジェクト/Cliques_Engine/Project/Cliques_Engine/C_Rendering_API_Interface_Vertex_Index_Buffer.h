//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリングAPIの頂点インデックスバッファ用システムのインターフェース
// 説明   ：頂点インデックスバッファに対する動作のみをまとめて提供する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_API_INTERFACE_INDEX_BUFFER_H_FILE
#define D_INCLUDE_GUARD_API_INTERFACE_INDEX_BUFFER_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>

#include "C_Rendering_Index_Buffer_Setting_Inform_Base.h"
#include "S_Create_Index_Buffer_Inform.h"


// ☆ ネームスペース ☆ //

// レンダリングAPI用のインターフェースを呼び出すための名前
namespace RENDERING::API::RENDER_INTERFACE
{
	// ☆ クラス ☆ //

	// 頂点インデックスバッファへの動作を行うクラス
	class C_Rendering_API_Interface_Vertex_Index_Buffer
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// インスタンス化防止のためにコンストラクタ隠蔽して削除
		C_Rendering_API_Interface_Vertex_Index_Buffer(void) = delete;


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 生成 -☆-//

		// 頂点インデックスデータ用の情報を生成する　引数：設定先の頂点インデックスバッファの参照, 頂点インデックスバッファ生成用の情報の参照（const）
		static void M_Create_Index_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> &, const RENDERING::API::CREATE::S_Create_Index_Buffer_Inform & );


		//-☆- 描画 -☆-//

		// 頂点インデックスバッファを元に指定された頂点インデックス間の描画を行う　引数：描画する頂点インデックスバッファの参照, 描画開始位置の頂点インデックス番号, 描画終了位置の頂点インデックス番号
		static void M_Draw_By_Index_Buffer_By_Range(std::unique_ptr < RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & , int, int);

		// 頂点インデックスバッファを元に描画を行う　引数：描画する頂点インデックスバッファの参照
		static void M_Draw_By_Index_Buffer(std::unique_ptr < RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & );

		// 頂点インデックスバッファをセットする　引数：頂点インデックスデータ設定用情報の参照
		static void M_Set_Index_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & );

		// セットされた頂点インデックスバッファを元に描画を行う
		static void M_Draw_Command_By_Set_Index_Buffer(void);

		// セットされた頂点インデックスバッファを元に指定されたインデックス間の描画を行う　引数：描画を開始するインデックス番号, 描画終了のインデックス番号
		static void M_Draw_Command_By_Set_Index_Buffer_By_Range(int, int);
	};
}


#endif // !D_INCLUDE_GUARD_API_INTERFACE_INDEX_BUFFER_H_FILE
