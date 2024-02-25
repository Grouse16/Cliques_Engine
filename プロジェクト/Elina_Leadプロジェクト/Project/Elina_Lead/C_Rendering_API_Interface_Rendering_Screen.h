//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリングAPIのレンダリング画面用システムのインターフェース
// 説明   ：レンダリング画面に対する動作のみをまとめて提供する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_RENDERING_SCREEN_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_RENDERING_SCREEN_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>

#include "C_Rendering_Screen_Data_Base.h"
#include "S_Create_Render_Screen_Inform.h"
#include "C_Texture_Map.h"


// ☆ ネームスペース ☆ //

// レンダリングAPI用のインターフェースを呼び出すための名前
namespace RENDERING::API::RENDER_INTERFACE
{
	// ☆ クラス ☆ //

	// レンダリングAPIのレンダリング画面システムへの動作を行うクラス
	class C_Rendering_API_Interface_Rendering_Screen
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// インスタンス化防止のためにコンストラクタ隠蔽して削除
		C_Rendering_API_Interface_Rendering_Screen(void) = delete;


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 生成 -☆-//

		// レンダリング画面システムの解放　引数：設定先のレンダリング画面の参照, レンダリング画面を生成するための情報の参照（const）　戻り値：成功時のみtrue
		static bool M_Create_Rendering_Screen(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & , const RENDERING::API::CREATE::S_Create_Render_Screen_Inform & );


		//-☆- 解放 -☆-//

		// レンダリング画面の削除を通知する　引数：削除されたレンダリング画面のアドレス（const）
		static void M_Notice_Rendering_Screen_Deleted(const RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base * );


		//-☆- クリア -☆-//

		// レンダリング画面のクリアする　引数：クリアするレンダリング画面番号, クリアするレンダリング画面システムの参照
		static void M_Clear_Rendering_Screen(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & );


		//-☆- 描画 -☆-//

		// 指定されたレンダリング画面を描画先にセット　引数：設定先のレンダリング画面の参照
		static void M_Set_Rendering_Screen_To_Draw_Screen(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & );

		// メインのレンダリング画面を描画先にする
		static void M_Set_Main_Rendering_Screen_To_Draw(void);

		// 指定されたレンダリング画面をテクスチャリソーススロットにセット　引数：設定先のスロット番号, 設定する画面の番号, 設定先のレンダリング画面の参照
		static void M_Set_Rendering_Screen_To_Texture_Resource_Slot(int, int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & );

		// メインの表示中のレンダリング画面を指定されたテクスチャスロットにセットする　引数：設定先のテクスチャのスロット番号
		static void M_Set_Main_Front_Rendering_Screen_To_Texture_Slot(int);

		// メインの描画書き込み中のレンダリング画面を指定されたテクスチャスロットにセットする　引数：設定先のテクスチャのスロット番号
		static void M_Set_Main_Back_Rendering_Screen_To_Texture_Slot(int);


		//-☆- テクスチャ -☆-//

		// 指定されたレンダリング画面のデータをテクスチャに移す　引数：設定するレンダリング画面番号, レンダリング画面システムの参照, 設定先のテクスチャの参照
		static void M_Save_Rendering_Screen_To_Texture(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & , ASSET::TEXTURE::C_Texture_Map & );

		// メインのレンダリング画面のデータをテクスチャに移す　引数：設定先のテクスチャの参照
		static void M_Save_Main_Rendering_Screen_To_Texture(ASSET::TEXTURE::C_Texture_Map & );


		//-☆- リソース設定 -☆-//

		// レンダリング画面のデータを読み取り可能にする　引数：設定するレンダリング画面番号, レンダリング画面システムの参照
		static void M_Set_Rendering_Screen_Can_Readable(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & );
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_RENDERING_SCREEN_H_FILE
