//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：色定義用のファイル
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_COLOR_H_FILE
#define D_INCLUDE_GUARD_C_COLOR_H_FILE


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
		float m_r = 0.0f;	// 赤
		float m_g = 0.0f;	// 緑
		float m_b = 0.0f;	// 青
		float m_a = 0.0f;	// 透明度


		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Color(void);

		// ０～１で色を設定する時のコンストラクタ　引数：赤, 緑, 青, 透明度
		C_Color(float, float, float, float);

		// ０～２５５で色を設定する時のコンストラクタ　引数：赤, 緑, 青, 透明度
		C_Color(int, int, int, int);

		// デストラクタ
		~C_Color(void);


		//-☆- セッタ -☆-//
		
		// ０～１で色の設定を行う　引数：赤, 緑, 青, 透明度
		void M_Set_Color_By_0_1(float, float, float, float);

		// ０～２５５で色の設定を行う　引数：赤, 緑, 青, 透明度
		void M_Set_Color_By_0_255(int, int, int, int);


		//-☆- オペレーター -☆-//

		// 色同士の掛け算　引数：色情報 戻り値：色情報の掛け算結果
		C_Color operator*(C_Color);

		// 色を設定する　引数：色情報
		void operator=(C_Color);
	};
}


#endif // !D_INCLUDE_GUARD_C_COLOR_H_FILE

