//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：サードパーティのレンダリングによるグラフィックを制御するシステムの基底クラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_RENDERING_API_BASE_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_API_BASE_H_FILE


// ☆ ファイルひらき ☆ //
#include<iostream>
#include<memory>
#include<vector>
#include<string>

#include "C_Rendering_Vertex_Buffer_Setting_Inform_Base.h"
#include "C_Rendering_Index_Buffer_Setting_Inform_Base.h"
#include "C_Rendering_Texture_Setting_Inform_Base.h"
#include "C_Rendering_Constant_Buffer_Setting_Inform_Base.h"
#include "C_Rendering_Graphics_Setting_Inform_Base.h"
#include "C_Rendering_Font_Inform_Base.h"
#include "C_Rendering_Screen_Data_Base.h"
#include "C_Rendering_Depth_Stencil_Buffer_Base.h"

#include "S_Create_Vertex_Buffer_Inform.h"
#include "S_Create_Index_Buffer_Inform.h"
#include "S_Create_Texture_Setting_Inform.h"
#include "S_Create_Constant_Buffer_Inform.h"
#include "S_Create_Rendering_Graphics_Setting_Inform.h"
#include "S_Create_Font_Data_Inform.h"
#include "S_Create_Render_Screen_Inform.h"
#include "S_Create_Depth_Stencil_Buffer_Inform.h"

#include "C_Color.h"
#include "S_Rect.h"
#include "S_Make_Font_To_Graph_Pakage.h"


// ☆ ネームスペース ☆ //

// レンダリングAPIの基底クラスを呼び出すための名前
namespace RENDERING::API::BASE
{
	// ☆ クラス ☆ //
	
	// レンダリングAPIの基底クラス
	class C_Rendering_API_Base
	{
	//==☆ プロテクト ☆==//
	protected:

		// ☆ 変数宣言 ☆ //
		static std::unique_ptr<C_Rendering_API_Base> m_this;	// クラスのインスタンス用アドレス、主にポリモーフィズム化に使用


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// レンダリングAPIの初期化
		virtual bool M_Set_Up(void) = 0;

		// レンダリングAPIのメモリ解放
		virtual void M_Release(void) = 0;

		// レンダリングAPIの削除
		static void M_Delete_API(void);

		// デストラクタ
		virtual ~C_Rendering_API_Base(void);


		//-☆- レンダリング -☆-//

		// レンダリング開始時の処理
		virtual void M_Rendering_Start(void) = 0;

		// レンダリング終了と描画バッファの切り替え処理
		virtual void M_Rendering_End_And_Swap_Screen(void) = 0;


		//-☆- レンダリング設定 -☆-//

		// レンダリング設定の生成する　引数：設定先のレンダリング設定, レンダリング設定の生成用の情報(const)
		virtual bool M_Create_Rendering_Graphics_Inform(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Graphics_Setting_Inform_Base>&, const RENDERING::API::CREATE::S_Create_Rendering_Graphics_Setting_Inform&) const = 0;

		// レンダリング設定のセットする　引数：セットするレンダリング設定(const)
		virtual void M_Rendering_Set_Rendering_Setting(const std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Graphics_Setting_Inform_Base>&) = 0;


		//-☆- レンダリング画面 -☆-//

		// レンダリング画面の生成する　引数：設定先のレンダリング画面の参照, レンダリング画面を生成するための情報の参照（const）　戻り値：成功時のみtrue
		virtual bool M_Create_Rendering_Screen(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> &, const RENDERING::API::CREATE::S_Create_Render_Screen_Inform & ) const = 0;

		// レンダリング画面のクリアする　引数：クリアするレンダリング画面番号, クリアするレンダリング画面システムの参照
		virtual void M_Clear_Rendering_Screen(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & ) const = 0;

		// レンダリング画面を描画先としてセットする　引数：設定先のレンダリング画面の参照
		virtual void M_Set_Rendering_Screen_To_Render_Target(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & ) = 0;

		// レンダリング画面を指定されたテクスチャリソーススロットにセットする　引数：レンダリング画面番号, 設定先のテクスチャのスロット番号, レンダリング画面システムの参照
		virtual void M_Set_Rendering_Screen_To_Texture_Slot(int, int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & ) = 0;

		// レンダリング画面のデータを読み取り可能にする　引数：設定するレンダリング画面番号, レンダリング画面システムの参照
		virtual void M_Set_Rendering_Screen_Can_Readable(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & ) = 0;

		// メインのレンダリング画面を描画先にする
		virtual void M_Set_Main_Rendering_Screen_To_Rendering(void) = 0;

		// メインの表示中のレンダリング画面を指定されたテクスチャスロットにセットする　引数：設定先のテクスチャのスロット番号
		virtual void M_Set_Main_Front_Rendering_Screen_To_Texture_Slot(int) = 0;

		// メインの描画書き込み中のレンダリング画面を指定されたテクスチャスロットにセットする　引数：設定先のテクスチャのスロット番号
		virtual void M_Set_Main_Back_Rendering_Screen_To_Texture_Slot(int) = 0;

		// メインのレンダリング画面のデータをテクスチャに移す　引数：設定先のテクスチャの参照
		virtual void M_Save_Main_Rendering_Screen_To_Texture(ASSET::TEXTURE::C_Texture_Map & ) const = 0;

		// 指定されたレンダリング画面のデータをテクスチャに移す　引数：設定するレンダリング画面番号, レンダリング画面システムの参照, 設定先のテクスチャの参照
		virtual void M_Save_Rendering_Screen_To_Texture(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base> & , ASSET::TEXTURE::C_Texture_Map & ) const = 0;

		// レンダリング画面の削除を通知する　引数：削除されたレンダリング画面のアドレス（const）
		virtual void M_Notice_Rendering_Screen_Deleted(const RENDERING::API::INSTANCE::C_Rendering_Screen_Data_Base * ) = 0;


		//-☆- 深度ステンシルバッファ -☆-//

		// 深度ステンシルバッファを生成する　引数：生成先の深度ステンシルバッファの参照, 深度ステンシルバッファを生成するための情報の参照（const）　戻り値：成功時のみtrue
		virtual bool M_Create_Depth_Stencil_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & , const RENDERING::API::CREATE::S_Create_Depth_Stencil_Buffer_Inform & ) const = 0;

		// 深度ステンシルバッファをクリアする　引数：クリアする深度ステンシルバッファの参照
		virtual void M_Clear_Depth_Stencil_Buffer(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & ) const = 0;

		// 深度ステンシルバッファを描画用にセットする　引数：設定する深度ステンシルバッファの参照
		virtual void M_Set_Depth_Stencil_Buffer_To_Rendering(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & ) = 0;

		// 深度ステンシルバッファをGPU用リソースのテクスチャスロットにセット　引数：設定先のスロット番号, 設定する深度ステンシルバッファの参照
		virtual void M_Set_Depth_Stencil_Buffer_To_Texture_Slot(int, std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base> & ) = 0;

		// 深度ステンシルバッファの削除を通知する　引数：削除された深度ステンシルバッファのアドレス（const）
		virtual void M_Notice_Depth_Stencil_Buffer_Deleted(const RENDERING::API::INSTANCE::C_Rendering_Depth_Stencil_Buffer_Base * ) = 0;

		// 深度ステンシルバッファをリセットする
		virtual void M_Reset_Depth_Stencil_Buffer(void) = 0;


		//-☆- 頂点バッファ -☆-//

		// 頂点データ用の情報を生成する　引数：設定先の頂点情報, 生成用の情報(const)
		virtual void M_Create_Vertex_Inform(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & , const RENDERING::API::CREATE::S_Create_Vertex_Buffer_Inform & ) const = 0;

		// 頂点バッファをセットする　引数：頂点データ設定用情報(const)
		virtual void M_Set_Vertex_Buffer(const std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & ) = 0;

		// 頂点バッファを元に描画を実行する　引数：描画する頂点データ(const)
		virtual void M_Draw_Command_By_Vertex_Buffer(const std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Vertex_Buffer_Setting_Inform_Base> & ) = 0;


		//-☆- インデックスバッファ -☆-//

		// インデックスデータ用の情報を生成する　引数：設定先のインデックス情報, 生成用の情報(const)
		virtual void M_Create_Index_Inform(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & , const RENDERING::API::CREATE::S_Create_Index_Buffer_Inform & ) const = 0;

		// インデックスバッファを元に描画を行う　引数：インデックスデータ設定用情報(const)
		virtual void M_Draw_Command_By_Index_Buffer(const std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & ) = 0;

		// インデックスバッファを元に指定されたインデックス間の描画を行う　引数：インデックスデータ設定用情報(const), 描画を開始するインデックス番号, 描画終了のインデックス番号
		virtual void M_Draw_Command_By_Index_Buffer_By_Range(const std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> & , int, int) = 0;


		//-☆- 定数バッファ -☆-//

		// 定数データ用の情報を生成する　引数：設定先の定数情報, 生成用の情報(const)
		virtual void M_Create_Constant_Inform(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Constant_Buffer_Setting_Inform_Base> & , const RENDERING::API::CREATE::S_Create_Constant_Buffer_Inform & ) const = 0;

		// 定数データをセットする　引数：定数データ設定用情報(const)
		virtual void M_Rendering_Set_Constant_Buffer(RENDERING::API::INSTANCE::S_Constant_Buffer_Drawing_Setting & ) = 0;

		// 指定されたインデックス番号のスロットに定数データをセットする　引数：定数データ設定用情報, セット先のインデックス番号
		virtual void M_Rendering_Set_Constant_Buffer_By_Index(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Constant_Buffer_Setting_Inform_Base> & , int) = 0;


		//-☆- テクスチャ -☆-//

		// テクスチャ用の情報を生成する　引数：テクスチャ用情報, 生成用の情報(const)　戻り値：成功時のみtrue
		virtual bool M_Create_Texture_Inform(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Texture_Setting_Inform_Base>&, const RENDERING::API::CREATE::S_Create_Texture_Setting_Inform & ) const = 0;

		// テクスチャのデータをセットする　引数：セットするテクスチャデータ情報(const)
		virtual void M_Rendering_Set_Texture(RENDERING::API::INSTANCE::S_Texture_Buffer_Drawing_Setting & ) = 0;

		// 指定されたインデックス番号のスロットにテクスチャのデータをセットする　引数：セットするテクスチャデータ情報(const), セット先のインデックス番号
		virtual void M_Rendering_Set_Texture_By_Index(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Texture_Setting_Inform_Base> & , int) = 0;


		//-☆- フォント -☆-//

		// フォントを指定されたフォント名を元にロードする　引数：設定先のフォント情報パラメータ, 生成用の情報(const)　戻り値：成功時のみtrue
		virtual bool M_Create_Font_Data(std::unique_ptr<RENDERING::API::INSTANCE::C_Rendering_Font_Inform_Base> &, const RENDERING::API::CREATE::S_Create_Font_Data_Inform & ) const = 0;

		// 渡された情報を元に文字列をマップにセットする　引数：フォントから画像を作るためのパッケージ情報　戻り値：成功時のみtrue
		virtual bool M_Set_Font_To_Texture_Map(PAKAGE::FONT::S_Make_Font_To_Graph_Package & ) const = 0;


		//-☆- ゲッタ -☆-//

		// このクラスの実体のアドレスを返す　戻り値：自クラスのインスタンスへのアドレス
		static C_Rendering_API_Base * M_Get_Instance(void);

		// このレンダリングシステムのシェーダーのフォルダまでのパスを返す　戻り値：シェーダーのフォルダまでのパス
		virtual std::string M_Get_Shader_Folder_Path(void) const = 0;

		// このレンダリングシステムのシェーダーの拡張子を返す　戻り値：シェーダーの拡張子
		virtual std::string M_Get_Shader_Extension(void) const = 0;

		// レンダリングシステムが終了しているかどうかのフラグを返す　戻り値：レンダリングシステムが終了しているかどうかのフラグ
		virtual bool M_Get_End_Rendering_System(void) const = 0;


		//-☆- セッタ -☆-//

		// 画面をクリアする色を設定する　引数：設定する色(const)
		virtual void M_Set_Clear_Color(const DATA::COLOR::C_Color & ) = 0;


		//-☆- ロード -☆-//

		// テクスチャをロードする　引数：テクスチャファイルのパス, テクスチャマップの参照
		virtual bool M_Load_Texture(std::string, ASSET::TEXTURE::C_Texture_Map &) const = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_API_BASE_H_FILE


//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆

