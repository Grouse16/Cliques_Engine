//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：１バイトのカラーの構造体
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_1_BYTE_COLOR_H_FILE
#define D_INCLUDE_GUARD_C_1_BYTE_COLOR_H_FILE


// ☆ ネームスペース ☆ //

// テクスチャ用の定義を呼び出すための名前
namespace DATA::COLOR
{
	// ☆ 構造体 ☆ //

	// １バイトのカラーの構造体
	class C_1_Byte_Color
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		unsigned char m_r = 0;	// 赤
		unsigned char m_g = 0;	// 緑
		unsigned char m_b = 0;	// 青
		unsigned char m_a = 0;	// 透明度


		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_1_Byte_Color(void);

		// ０～１で色を設定する時のコンストラクタ　引数：赤, 緑, 青, 透明度
		C_1_Byte_Color(float, float, float, float);

		// ０～２５５で色を設定する時のコンストラクタ　引数：赤, 緑, 青, 透明度
		C_1_Byte_Color(int, int, int, int);

		// デストラクタ
		~C_1_Byte_Color(void);


		//-☆- セッタ -☆-//

		// ０～１で色の設定を行う　引数：赤, 緑, 青, 透明度
		void M_Set_Color_By_0_1(float, float, float, float);

		// ０～２５５で色の設定を行う　引数：赤, 緑, 青, 透明度
		void M_Set_Color_By_0_255(int, int, int, int);


		//-☆- オペレーター -☆-//

		// 色同士の掛け算　引数：色情報 戻り値：色情報の掛け算結果
		C_1_Byte_Color operator*(C_1_Byte_Color);

		// 色を設定する　引数：色情報
		void operator=(C_1_Byte_Color);
	};
}


#endif // !D_INCLUDE_GUARD_C_1_BYTE_COLOR_H_FILE
