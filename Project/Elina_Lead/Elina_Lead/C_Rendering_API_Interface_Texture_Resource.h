//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリングAPIのテスクチャリソース用システムのインターフェース
// 説明   ：テスクチャバッファに対する動作のみをまとめて提供する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_TEXTURE_RESOURCE_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_TEXTURE_RESOURCE_H_FILE


// ☆ ファイルひらき ☆ //
#include <string>

#include "C_Rendering_Texture_Setting_Inform_Base.h"
#include "S_Create_Texture_Setting_Inform.h"
#include "C_Texture_Map.h"


// ☆ ネームスペース ☆ //

// レンダリングAPI用のインターフェースを呼び出すための名前
namespace RENDERING::API::RENDER_INTERFACE
{
	// ☆ クラス ☆ //

	// レンダリングAPIのテスクチャリソースへの動作を行うクラス
	class C_Rendering_API_Interface_Texture_Resource
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// インスタンス化防止のためにコンストラクタ隠蔽して削除
		C_Rendering_API_Interface_Texture_Resource(void) = delete;


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 生成 -☆-//

		// テスクチャリソース用の情報を生成する　引数：設定先のテスクチャリソースの参照, テスクチャリソースを生成するための情報の参照（const）　戻り値：成功時のみtrue
		static bool M_Create_Texture_Resource(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Texture_Setting_Inform_Base> & , const RENDERING::API::CREATE::S_Create_Texture_Setting_Inform & );


		//-☆- 描画 -☆-//

		// テスクチャリソースを描画用にセットする　引数：テスクチャリソース用描画設定の参照
		static void M_Set_Texture_Resource_To_Draw(RENDERING::API::INSTANCE::S_Texture_Buffer_Drawing_Setting & );

		// 指定された番号のリソーススロットにテスクチャデータをセットする　引数：セットするテスクチャリソースの参照, セット先のリソーススロット番号
		static void M_Set_Texture_Resource_To_Draw_By_Slot_Index(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Texture_Setting_Inform_Base> & , int);


		//-☆- ロード -☆-//

		// テスクチャをロードする　引数：ロードするテクスチャまでのパス, ロード先のテクスチャマップの参照　戻り値：成功時のみtrue
		static bool M_Load_Texture(std::string, ASSET::TEXTURE::C_Texture_Map & );
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_TEXTURE_RESOURCE_H_FILE
