//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリングAPIの頂点バッファ用システムのインターフェース
// 説明   ：頂点バッファに対する動作のみをまとめて提供する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_VERTEX_BUFFER_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_VERTEX_BUFFER_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>

#include "C_Rendering_Vertex_Buffer_Setting_Inform_Base.h"
#include "S_Create_Vertex_Buffer_Inform.h"


// ☆ ネームスペース ☆ //

// レンダリングAPI用のインターフェースを呼び出すための名前
namespace RENDERING::API::RENDER_INTERFACE
{
	// ☆ クラス ☆ //

	// レンダリングAPIの頂点バッファへの動作を行うクラス
	class C_Rendering_API_Interface_Vertex_Buffer
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// インスタンス化防止のためにコンストラクタ隠蔽して削除
		C_Rendering_API_Interface_Vertex_Buffer(void) = delete;


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 生成 -☆-//

		// 頂点データ用の情報を生成する　引数：設定先の頂点バッファの参照,　生成するための情報の参照（const）
		static void M_Create_Vertex_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & , const RENDERING::API::CREATE::S_Create_Vertex_Buffer_Inform & );


		//-☆- 描画 -☆-//

		// 頂点データを描画用にセットする　引数：セットする頂点バッファ
		static void M_Set_Vertex_Buffer_To_Draw(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & );

		// 頂点バッファを元に描画を実行する　引数：描画する頂点バッファ
		static void M_Draw_By_Vertex_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & );
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_VERTEX_BUFFER_H_FILE
