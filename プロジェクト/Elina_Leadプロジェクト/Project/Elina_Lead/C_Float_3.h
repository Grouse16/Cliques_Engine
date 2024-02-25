//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：フロート３つ分を管理するクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_FLOAT_3_H_FILE
#define D_INCLUDE_GUARD_C_FLOAT_3_H_FILE


// ☆ ネームスペース ☆ //

// 数学系統の型を呼び出すための名前
namespace MATH::FORMAT
{
	// ☆ クラス ☆ //

	// フロート３つ分を管理するクラス
	class C_Float_3
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;


		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Float_3(void);

		// xyzを順にセットするコンストラクタ　引数：xにセットする値, yにセットする値, zにセットする値
		C_Float_3(float, float, float);

		// デストラクタ
		~C_Float_3(void);


		//-☆- オペレータ -☆-//

		// C_Float_3との=演算　引数：代入するフロート3値　戻り値：代入結果のフロート3値
		C_Float_3 operator= (C_Float_3);

		// C_Float_3との＋演算　引数：加算するフロート3値　戻り値：加算結果のフロート3値
		C_Float_3 operator+ (C_Float_3);

		// C_Float_3との-演算　引数：減算するフロート3値　戻り値：減算結果のフロート3値
		C_Float_3 operator- (C_Float_3);

		// C_Float_3との×演算　引数：乗算するフロート3値　戻り値：乗算結果のフロート3値
		C_Float_3 operator* (C_Float_3);

		// C_Float_3との/演算　引数：除算するフロート3値　戻り値：除算結果のフロート3値
		C_Float_3 operator/ (C_Float_3);

		// C_Float_3との%演算　引数：剰余算するフロート3値　戻り値：剰余算結果のフロート3値
		C_Float_3 operator% (C_Float_3);

		// C_Float_3との＋=演算　引数：加算代入するフロート3値　戻り値：加算代入結果のフロート3値
		C_Float_3 operator+= (C_Float_3);

		// C_Float_3との-=演算　引数：減算代入するフロート3値　戻り値：減算代入結果のフロート3値
		C_Float_3 operator-= (C_Float_3);

		// C_Float_3との×=演算　引数：乗算代入するフロート3値　戻り値：乗算代入結果のフロート3値
		C_Float_3 operator*= (C_Float_3);

		// C_Float_3との/=演算　引数：除算代入するフロート3値　戻り値：除算代入結果のフロート3値
		C_Float_3 operator/= (C_Float_3);

		// C_Float_3との%=演算　引数：剰余算代入するフロート3値　戻り値：剰余算代入結果のフロート3値
		C_Float_3 operator%= (C_Float_3);

		// floatとの=演算　引数：代入するフロート値　戻り値：代入結果のフロート3値
		C_Float_3 operator= (float);

		// floatとの＋演算　引数：加算するフロート値　戻り値：加算結果のフロート3値
		C_Float_3 operator+ (float);

		// floatとの-演算　引数：減算するフロート値　戻り値：減算結果のフロート3値
		C_Float_3 operator- (float);

		// floatとの×演算　引数：乗算するフロート値　戻り値：乗算結果のフロート3値
		C_Float_3 operator* (float);

		// floatとの/演算　引数：除算するフロート値　戻り値：除算結果のフロート3値
		C_Float_3 operator/ (float);

		// floatとの%演算　引数：剰余算するフロート値　戻り値：剰余算結果のフロート3値
		C_Float_3 operator% (float);

		// floatとの＋=演算　引数：加算代入するフロート値　戻り値：加算代入結果のフロート3値
		C_Float_3 operator+= (float);

		// floatとの-=演算　引数：減算代入するフロート値　戻り値：減算代入結果のフロート3値
		C_Float_3 operator-= (float);

		// floatとの×=演算　引数：乗算代入するフロート値　戻り値：乗算代入結果のフロート3値
		C_Float_3 operator*= (float);

		// floatとの/=演算　引数：除算代入するフロート値　戻り値：除算代入結果のフロート3値
		C_Float_3 operator/= (float);

		// floatとの%=演算　引数：剰余算代入するフロート値　戻り値：剰余算代入結果のフロート3値
		C_Float_3 operator%= (float);
	};
}


#endif // !D_INCLUDE_GUARD_C_FLOAT_3_H_FILE

