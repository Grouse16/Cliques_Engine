//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：サードパーティの内のグラフィックを制御するシステムの基底クラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_THIRD_PARTY_SDK_GRAPHICS_BASE_H_FILE
#define D_INCLUDE_GUARD_C_THIRD_PARTY_SDK_GRAPHICS_BASE_H_FILE


// ☆ ファイルひらき ☆ //
#include<iostream>
#include<memory>
#include<vector>
#include<string>

#include "C_Vertex_Buffer_Setting_Inform_Base.h"
#include "C_Rendering_Texture_Setting_Inform_Base.h"
#include "C_Constant_Buffer_Setting_Inform_Base.h"
#include "C_Rendering_Graphics_Setting_Inform_Base.h"
#include "C_Rendering_Font_Inform_Base.h"

#include "C_Create_Vertex_Buffer_Inform.h"
#include "C_Create_Constant_Buffer_Inform.h"
#include "C_Create_Rendering_Graphics_Setting_Inform.h"
#include "C_Create_Texture_Setting_Inform.h"
#include "C_Create_Font_Data_Inform.h"

#include "Color_Data.h"
#include "S_Tex_Color.h"
#include "S_Rect.h"
#include "S_Make_Font_To_Graph_Pakage.h"


// ☆ ネームスペース ☆ //

// グラフィックを制御するシステムの基底を呼び出すための名前
namespace RENDERING::GRAPHICS
{
	// ☆ クラス ☆ //
	
	// サードパーティの内のグラフィックを制御するシステムの基底クラス
	class C_Rendering_Graphics_API_Base
	{
	//==☆ プロテクト ☆==//
	protected:

		// ☆ 変数宣言 ☆ //
		static std::unique_ptr<C_Rendering_Graphics_API_Base> m_this;	// クラスのインスタンス用アドレス、主にポリモーフィズム化に使用


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// 初期化して使用可能にする
		virtual bool M_Set_Up(void) = 0;

		// メモリ解放
		virtual void M_Release(void) = 0;

		// レンダリング用のAPIを終了する
		static void M_Delete_API(void);

		// デストラクタ
		virtual ~C_Rendering_Graphics_API_Base(void);


		//-☆- レンダリング -☆-//

		// レンダリングを開始する
		virtual void M_Rendering_Start(void) = 0;

		// 次の描画実行を開始する　引数：レンダリングパイプライン用情報(const)
		virtual void M_Rendering_Set_Rendering_Setting(const std::unique_ptr<INSTANCE::C_Rendering_Graphics_Setting_Inform_Base> & ) = 0;

		// 定数データをセットする　引数：定数データ設定用情報(const)
		virtual void M_Rendering_Set_Constant_Buffer(INSTANCE::S_Constant_Buffer_Drawing_Setting & ) = 0;

		// 指定されたインデックス番号のスロットに定数データをセットする　引数：定数データ設定用情報, セット先のインデックス番号
		virtual void M_Rendering_Set_Constant_Buffer_By_Index(std::unique_ptr<INSTANCE::C_Constant_Buffer_Setting_Inform_Base> & , int) = 0;

		// テクスチャのデータをセットする　引数：セットするテクスチャデータ情報(const)
		virtual void M_Rendering_Set_Texture(INSTANCE::S_Texture_Buffer_Drawing_Setting & ) = 0;

		// 指定されたインデックス番号のスロットにテクスチャのデータをセットする　引数：セットするテクスチャデータ情報(const), セット先のインデックス番号
		virtual void M_Rendering_Set_Texture_By_Index(std::unique_ptr<INSTANCE::C_Rendering_Texture_Setting_Inform_Base> & , int) = 0;

		// 今の描画を実行する　引数：頂点データ設定用情報(const)
		virtual void M_Draw_All_Vertex_By_Index(const std::unique_ptr<INSTANCE::C_Vertex_Buffer_Setting_Inform_Base> & ) = 0;

		// 描画するインデックス番号を指定したうえで今の描画を実行する　引数：頂点データ設定用情報(const), 描画するインデックスの描画の開始番号,描画するインデックスの終了番号
		virtual void M_Draw_Select_Vertex_By_Index(const std::unique_ptr<INSTANCE::C_Vertex_Buffer_Setting_Inform_Base> & , int, int) = 0;

		// レンダリングを終了して、画面を表示
		virtual void M_Rendering_End_And_Swap_Screen(void) = 0;


		//-☆- 生成 -☆-//

		// 頂点データ用の情報を生成する　引数：設定先の頂点情報, 生成用の情報(const)
		virtual void M_Create_Vertex_Inform(std::unique_ptr<INSTANCE::C_Vertex_Buffer_Setting_Inform_Base> &, const CREATE::C_Create_Vertex_Buffer_Inform & ) = 0;

		// 定数データ用の情報を生成する　引数：設定先の定数情報, 生成用の情報(const)
		virtual void M_Create_Constant_Inform(std::unique_ptr<INSTANCE::C_Constant_Buffer_Setting_Inform_Base> &, const CREATE::C_Create_Constant_Buffer_Inform &) = 0;

		// テクスチャ用の情報を生成する　引数：テクスチャ用情報, 生成用の情報(const)　戻り値：成功時のみtrue
		virtual bool M_Create_Texture_Inform(std::unique_ptr<INSTANCE::C_Rendering_Texture_Setting_Inform_Base>&, const CREATE::C_Create_Texture_Setting_Inform&) = 0;

		// 描画パイプライン用の情報を生成する　引数：設定先のパイプライン情報, 生成用の情報(const)
		virtual bool M_Create_Rendering_Graphics_Inform(std::unique_ptr<INSTANCE::C_Rendering_Graphics_Setting_Inform_Base> &, const CREATE::C_Create_Rendering_Graphics_Setting_Inform &) = 0;

		// フォントを指定されたフォント名を元にロードする　引数：設定先のフォント情報パラメータ, 生成用の情報(const)　戻り値：成功時のみtrue
		virtual bool M_Create_Font_Data(std::unique_ptr<INSTANCE::C_Rendering_Font_Inform_Base> &, const CREATE::C_Create_Font_Data_Inform &) = 0;

		// 渡された情報を元に文字列をマップにセットする　引数：フォントから画像を作るためのパッケージ情報　戻り値：成功時のみtrue
		virtual bool M_Set_Font_To_Texture_Map(PAKAGE::FONT::S_Make_Font_To_Graph_Package & ) = 0;


		//-☆- ゲッタ -☆-//

		// このクラスの実体のアドレスを返す　戻り値：自クラスのインスタンスへのアドレス
		static C_Rendering_Graphics_API_Base * M_Get_Instance(void);

		// このレンダリングシステムのシェーダーのフォルダまでのパス　戻り値：シェーダーのフォルダまでのパス
		virtual std::string M_Get_Shader_Folder_Path(void) = 0;


		//-☆- セッタ -☆-//

		// 画面をクリアする色を設定する　引数：設定する色(const)
		virtual void M_Set_Clear_Color(const DATA::COLOR::C_Color & ) = 0;


		//-☆- ロード -☆-//

		// テクスチャをロードする　引数：テクスチャファイルのパス, テクスチャマップの参照
		virtual bool M_Load_Texture(std::string, ASSET::TEXTURE::C_Texture_Map &) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_THIRD_PARTY_SDK_GRAPHICS_BASE


//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆

