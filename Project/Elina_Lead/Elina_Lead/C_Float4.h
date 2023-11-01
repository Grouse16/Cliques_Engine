//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：フロート四つ分を管理するクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_MY_FLOAT_4_H_FILE
#define D_INCLUDE_GUARD_C_MY_FLOAT_4_H_FILE


// ☆ ネームスペース ☆ //

// 数学系統を呼び出すための名前
namespace MATH
{
	// ☆ クラス ☆ //

	// フロート四つ分を管理するクラス
	class C_Float4
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		float x = 0.0f;	// 要素１
		float y = 0.0f;	// 要素２
		float z = 0.0f;	// 要素３
		float w = 0.0f;	// 要素４


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ
		C_Float4(void);

		// xyzwを順にセットするコンストラクタ　引数：xにセットする値, yにセットする値, zにセットする値, wにセットする値
		C_Float4(float, float, float, float);

		// xyzを順にセットするコンストラクタ　引数：xにセットする値, yにセットする値, zにセットする値
		C_Float4(float, float, float);

		// xyを順にセットするコンストラクタ　引数：xにセットする値, yにセットする値
		C_Float4(float, float);

		// xを順にセットするコンストラクタ　引数：xにセットする値
		C_Float4(float);

		// デストラクタ
		~C_Float4(void);


		//-☆- オペレータ -☆-//

		// Float4とのイコール演算(参照型)　引数；代入するフロート4値
		void operator= (C_Float4 & );

		// Float4とのイコール演算　引数：代入するフロート4値
		void operator= (C_Float4);

		// Float4との＋演算(参照型)　引数：加算するフロート4値
		C_Float4 operator+ (C_Float4 & );

		// Float4との＋演算　引数：加算するフロート4値
		C_Float4 operator+ (C_Float4);

		// floatとの＋演算（全ての変数を加算）　引数：加算するフロート値
		C_Float4 operator+ (float &);
	};
}


#endif // !D_INCLUDE_GUARD_C_MY_FLOAT_4_H_FILE
