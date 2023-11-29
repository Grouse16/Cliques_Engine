//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：クォータニオンシステムのクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_QUATERNION_H_FILE
#define D_INCLUDE_GUARD_C_QUATERNION_H_FILE


// ☆ ファイルひらき ☆ //
#include <DirectXMath.h>


// ☆ ネームスペース ☆ //

// クォータニオンを呼び出すための名前
namespace MATH::QUATERNION
{
	// ☆ クラス ☆ //

	// クォータニオンのクラス
	class C_Quaternion
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			DirectX::XMVECTOR m_rotation_vector = DirectX::XMVECTOR();	// 回転（クォータニオン）

		} mpr_variable;	// プライベート変数を呼び出すための名前


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Quaternion(void);

		// デストラクタ
		~C_Quaternion(void);


		//-☆- セッタ -☆-//

		// クォータニオンをセットする　引数：セットするクォータニオンの参照（const）
		void M_Set_Quaternion(const DirectX::XMVECTOR & );

		// 度数の回転の情報からクォータニオンをセットする　引数：回転情報
		void M_Set_Quaternion_By_Angle(DirectX::XMFLOAT3);

		// 度数の回転の情報からクォータニオンをセットする　引数：ロール, ピッチ, ヨウ
		void M_Set_Quaternion_By_Angle(float, float, float);

		// ラジアンの回転の情報からクォータニオンをセットする　引数：回転情報
		void M_Set_Quaternion_By_Radian(DirectX::XMFLOAT3);

		// ラジアンの回転の情報からクォータニオンをセットする　引数：ロール, ピッチ, ヨウ
		void M_Set_Quaternion_By_Radian(float, float, float);


		//-☆- ゲッタ -☆-//

		// クォータニオンの回転ベクトルを返す　戻り値：クォータニオンの回転ベクトル
		DirectX::XMVECTOR M_Get_Quaternion_Rotation_Vector(void) const;

		// 回転のマトリクス変換行列を返す　戻り値：回転マトリクス行列
		DirectX::XMMATRIX M_Get_Rotation_Matrix(void) const;

		// 現在のクォータニオンから指定された方向を向いたベクトルを返す　引数：向く方向(const参照:高速化用)　戻り値：方向を変えた後のベクトル
		DirectX::XMFLOAT3 M_Get_Rotated_Vector_By_Angle(const DirectX::XMFLOAT3 & ) const;


		//-☆- クォータニオン -☆-//

		// 度数で指定値分だけ回転させる　引数：ロール, ピッチ, ヨウ
		void M_Add_Rotation_By_Angle(float, float, float);

		// 度数で指定値分だけ回転させる　引数：回転情報
		void M_Add_Rotation_By_Angle(DirectX::XMFLOAT3);

		// ラジアンで指定値分だけ回転させる　引数：ロール, ピッチ, ヨウ
		void M_Add_Rotation_By_Radian(float, float, float);

		// ラジアンで指定値分だけ回転させる　引数：回転情報
		void M_Add_Rotation_By_Radian(DirectX::XMFLOAT3);

		// 現在の回転ベクトルから指定されたクォータニオンまで補間率による球面線形補間を行う　引数：補間先のクォータニオンへの参照(const), 補間率（0%で元値、100%で移動先と同じ値）
		void M_Slerp_To_Quaternion_By_Now_Vector(const DirectX::XMVECTOR &, float);
		
		// 一つ目のクォータニオンから二つ目のクォータニオンへ指定された補間率の球面線形補間を行う　引数：補間元クォータニオンの参照(const), 補間先クォータニオンの参照(const), 補間率（0%で一つ目、100%で二つと同じ位置）
		void M_Slerp_Quaternion_A_To_B(const DirectX::XMVECTOR &, const DirectX::XMVECTOR & , float );

		// 現在の回転ベクトルから指定されたクォータニオンまで補間率による線形補間を行う　引数：補間先のクォータニオンへの参照(const), 補間率（0%で元値、100%で移動先と同じ値）
		void M_Lerp_To_Quaternion_By_Now_Vector(const DirectX::XMVECTOR &, float);

		// 一つ目のクォータニオンから二つ目のクォータニオンへ指定された補間率の線形補間を行う　引数：補間元クォータニオンの参照(const), 補間先クォータニオンの参照(const), 補間率（0%で一つ目、100%で二つと同じ位置）
		void M_Lerp_Quaternion_A_To_B(const DirectX::XMVECTOR &, const DirectX::XMVECTOR &, float);
	};
}


#endif // !D_INCLUDE_GUARD_C_QUATERNION_H_FILE


