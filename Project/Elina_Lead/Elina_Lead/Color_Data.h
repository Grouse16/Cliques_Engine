//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：色定義用のファイル
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_COLOR_DATA_H_FILE
#define D_INCLUDE_GUARD_COLOR_DATA_H_FILE


// ☆ ネームスペース ☆ //

// 色の定義を呼び出すための名前
namespace DATA::COLOR
{
	// ☆ クラス ☆ //

	// 色のクラス
	class C_Color
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		float r = 0.0f;	// 赤
		float g = 0.0f;	// 緑
		float b = 0.0f;	// 青
		float a = 0.0f;	// 透明度


		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Color(void) { return; }

		// ０～１色を設定する時のコンストラクタ
		C_Color(float in_r, float in_g, float in_b, float in_a)
		{
			r = in_r;
			g = in_g;
			b = in_b;
			a = in_a;

			return;
		}

		// ０～２５５で色を設定する時のコンストラクタ
		C_Color(int in_r, int in_g, int in_b, int in_a)
		{
			r = in_r / static_cast<float>(255);
			g = in_g / static_cast<float>(255);
			b = in_b / static_cast<float>(255);
			a = in_a / static_cast<float>(255);

			return;
		}


		// デストラクタ
		~C_Color(void) { return; }


		//-☆- 設定 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：０～１で色の設定を行う
		// 引数   ：float 赤, float 緑, float 青, float 透明度
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		void M_Set_Color_By_0_1(float in_r, float in_g, float in_b, float in_a)
		{
			r = in_r;
			g = in_g;
			b = in_b;
			a = in_a;

			return;
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：// ０～２５５で色の設定を行う
		// 引数   ：int 赤, int 緑, int 青, int 透明度
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		void M_Set_Color_By_0_255(int in_r, int in_g, int in_b, int in_a)
		{
			r = in_r / static_cast<float>(255);
			g = in_g / static_cast<float>(255);
			b = in_b / static_cast<float>(255);
			a = in_a / static_cast<float>(255);

			return;
		}


		//-☆- オペレーター -☆-//

		// 色同士の掛け算
		C_Color operator*(C_Color& in_color)
		{
			// ☆ 変数宣言 ☆ //
			C_Color result;	// 計算結果


			// 色を合成する
			result.r = in_color.r * r;
			result.g = in_color.g * g;
			result.b = in_color.b * b;
			result.a = in_color.a * a;

			return result;
		}

		// 色を設定する
		void operator=(C_Color& in_color)
		{
			// 色を合成する
			r = in_color.r;
			g = in_color.g;
			b = in_color.b;
			a = in_color.a;

			return;
		}
	};
}


#endif // !D_INCLUDE_GUARD_COLOR_DATA_H_FILE

