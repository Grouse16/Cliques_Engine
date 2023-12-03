//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：UIの図形定義用のデータ
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_UI_FIGURE_DATA_H_FILE
#define D_INCLUDE_GUARD_UI_FIGURE_DATA_H_FILE


// ☆ ファイルひらき ☆ //
#include <d3d12.h>

#include "2D_Position_Data.h"
#include "C_Color.h"
#include "Texture_UV_Data.h"
#include "Figure_Base_Data.h"
#include "S_Rect.h"


// ☆ ネームスペース ☆ //

// UI系統を呼び出すための名前
namespace DATA::FIGURE::UI
{
	// ☆ 定数 ☆ //

	// UIの図形のための数値群
	enum class E_UI_FIGURE_PARAMATOR
	{
		e_PICXCEL_BASE_SIZE = 1000,	// ピクセルの基準とする大きさ
	};


	// ☆ 変数宣言 ☆ //

	// UI設定用の変数群
	class C_UI_SETTING_DATA
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //
		static C_UI_SETTING_DATA m_this;	// オブジェクト定義用の変数（シングルトン化）


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ
		C_UI_SETTING_DATA(void);


		//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		static float ui_width;	// UIの基本ピクセルの横幅
		static float ui_height;	// UIの基本ピクセルの縦幅

		static float aspect_x;	// アスペクト比でのｘ
		static float aspect_y;		// アスペクト比でのｙ

		static float percent_of_aspect_x;	// アスペクト比のｘの比率
		static float percent_of_aspect_y;	// アスペクト比のｙの比率

	};	// UI設定用の変数群を呼び出すための名前


	// ☆ クラス ☆ //

	// 四角形のUI用のクラス
	class C_UI_Box : DATA::FIGURE::BASE::C_Figure_Base
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		RECTSETTING::S_Rect m_box_pos;	// 四角形の座標

		DATA::COLOR::C_Color m_box_color;	// 四角形の色


		// ☆ 関数 ☆ //

		//-☆- 更新 -☆-//

		// UI用の四角形をレクトから設定する　引数：RECT & 設置位置
		virtual void M_Set_Constant_Pixel_By_Rect(RECTSETTING::S_Rect & );

		// 色を全ての頂点に設定する　引数：COLOR & 色
		void M_Set_UI_Box_Color(DATA::COLOR::C_Color & );


		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_UI_Box(void) { return; }

		// デストラクタ
		virtual ~C_UI_Box(void) { return; }
	};


	// 描画するピクセル座標を完全に固定した四角形のUI
	class C_Scale_Constant_UI : public C_UI_Box
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 定数 ☆ //

		// ピクセルのサイズを設定するときに基準とする場所を設定する
		enum class E_Scale_Base_Position
		{
			e_LEFT_TOP,		// 左上
			e_LEFT_BOTTOM,	// 左下

			e_RIGHT_TOP,	// 右上
			e_RIGHT_BOTTOM,	// 右下
		};


		// ☆ 変数宣言 ☆ //
		DATA::RECTSETTING::S_Rect m_constant_pixel_pos;	// ピクセルの座標

		E_Scale_Base_Position m_base_position = E_Scale_Base_Position::e_LEFT_BOTTOM;	// 固定時の基準となる場所の指定


		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Scale_Constant_UI(void);

		// デストラクタ
		~C_Scale_Constant_UI(void);


		//-☆- セッタ -☆-//

		// 基準となる場所を指定する　引数：指定する場所
		void M_Set_Scale_Base_Position(E_Scale_Base_Position);


		//-☆- 更新 -☆-//

		// UI用の四角形をレクトから設定する　引数：RECT & 設置位置
		void M_Set_Constant_Pixel_By_Rect(RECTSETTING::S_Rect & ) override;
		
		// スケールをピクセル座標に合わせる更新を行う
		void M_Scale_Update(void);
	};
}


#endif // !D_INCLUDE_GUARD_UI_FIGURE_DATA_H_FILE
