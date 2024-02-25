//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリングAPIの定数リソース用システムのインターフェース
// 説明   ：定数バッファに対する動作のみをまとめて提供する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_CONSTANT_RESOURCE_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_CONSTANT_RESOURCE_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>

#include "C_Rendering_Constant_Buffer_Setting_Inform_Base.h"
#include "S_Create_Constant_Buffer_Inform.h"


// ☆ ネームスペース ☆ //

// レンダリングAPI用のインターフェースを呼び出すための名前
namespace RENDERING::API::RENDER_INTERFACE
{
	// ☆ クラス ☆ //

	// レンダリングAPIの定数バッファへの動作を行うクラス
	class C_Rendering_API_Interface_Constant_Resource
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// インスタンス化防止のためにコンストラクタ隠蔽して削除
		C_Rendering_API_Interface_Constant_Resource(void) = delete;


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 生成 -☆-//

		// 定数リソース用の情報を生成する　引数：設定先の定数リソースの参照, 定数リソースを生成するための情報の参照（const）
		static void M_Create_Constant_Resource(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Constant_Buffer_Setting_Inform_Base> & , const RENDERING::API::CREATE::S_Create_Constant_Buffer_Inform & );

		
		//-☆- 描画 -☆-//

		// 定数リソースを描画用にセットする　引数：定数リソース用描画設定の参照
		static void M_Set_Constant_Resource_To_Draw(RENDERING::API::INSTANCE::S_Constant_Buffer_Drawing_Setting & );

		// 指定された番号のリソーススロットに定数データをセットする　引数：セットする定数リソースの参照, セット先のリソーススロット番号
		static void M_Set_Constant_Resource_To_Draw_By_Slot_Index(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Constant_Buffer_Setting_Inform_Base> & , int);
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_CONSTANT_RESOURCE_H_FILE
