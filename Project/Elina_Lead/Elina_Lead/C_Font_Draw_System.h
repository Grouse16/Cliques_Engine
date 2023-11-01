//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：フォントデータを正確に使うためのシステム
// 説明   ：フォントの読み込みから描画までを行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_FONT_DATA_H_FILE
#define D_INCLUDE_GUARD_C_FONT_DATA_H_FILE


// ☆ ファイルひらき ☆ //
#include <string>
#include <memory>

#include "C_Rendering_Font_Inform_Base.h"
#include "C_Texture_Data_System.h"
#include "S_Rect.h"


// ☆ ネームスペース ☆ //

// フォントを呼び出すための名前
namespace DATA::FONT
{
	// ☆ クラス ☆ //

	// フォントを制御するシステム
	class C_Font_Draw_System
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			RENDERING::CAPSULE::C_Texture_Data_System texture_data;	// 画像データ管理用システム

			std::unique_ptr<RENDERING::GRAPHICS::INSTANCE::C_Rendering_Font_Inform_Base> font_data;	// フォントのデータ管理用システム

			std::wstring now_draw_text = L"\0";	// 描画するテキスト

			int font_size = 60;	// フォントの大きさ

			int span_size = 0;	// 文字間隔

			bool flg_save_map = true;	// 動的に操作できるテクスチャマップを持つかどうか

		} mpr_variable;	// プライベート変数を呼び出すための名前


		// ☆ 関数 ☆ //

		//-☆- 描画 -☆-//

		// 現在のテキストに応じて画像を生成する
		void M_Creat_Texture_On_Now_Text(void);


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Font_Draw_System(void);

		// デストラクタ
		~C_Font_Draw_System(void);
		
		// フォントデータを初期化する
		void M_Reset(void);


		//-☆- ロード -☆-//

		// 指定されたパスにあるフォントを取得する


		// 指定された名前のフォントを取得する(PCに存在している時のみ動作)　引数：フォント名, フォントのピクセルサイズ　戻り値：成功時のみtrue
		bool M_Load_Font_By_Font_Name(std::wstring, int);


		//-☆- セッタ -☆-//

		// フォントサイズを設定する　引数：フォントサイズ
		void M_Set_Font_Size(int);

		// 文字間隔を設定する　引数：設定する文字間隔
		void M_Set_Span(int);


		//-☆- ゲッタ -☆-//

		// テクスチャデータの参照を返す　戻り値：テクスチャーデータの参照
		RENDERING::CAPSULE::C_Texture_Data_System & M_Get_Texture_Data(void);


		//-☆- 描画 -☆-//

		// テキストから画像を生成する　引数：設定するテキスト
		void M_Creat_Graph_By_Text(const std::wstring);

		// 設定されたテキストによる画像をもう一度生成する
		void M_Recreate_Graph(void);

		// インデックス指定用の識別名をセットする　引数：設定する識別名
		void M_Set_Signature_Name(const std::string);

		// 適応するシェーダーの種類を設定する　引数：設定する種類
		void M_Set_Attach_Shader_Kind(const ASSET::SHADER::E_SHADER_KIND);

		// このテクスチャのデータをGPUへ送る
		void M_Attach_To_Shader(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_FONT_DATA_H_FILE



