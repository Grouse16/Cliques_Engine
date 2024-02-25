//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：位置座標のクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_POSITION_H_FILE
#define D_INCLUDE_GUARD_C_POSITION_H_FILE


// ☆ 変数宣言 ☆ //
#include <DirectXMath.h>


// ☆ ネームスペース ☆ //

// 位置座標を呼び出すための名前
namespace MATH::POSITION
{
	// ☆ クラス ☆ //

	// 位置座標のクラス
	class C_Position
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		DirectX::XMFLOAT3 xyz = DirectX::XMFLOAT3();	// 座標値


		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Position(void);

		// デストラクタ
		~C_Position(void);


		//-☆- ゲッタ -☆-//

		// 位置座標のマトリクス変換行列を返す　戻り値：位置座標のマトリクス変換を行列
		DirectX::XMMATRIX M_Get_Position_Matrix(void) const;


		//-☆- 移動 -☆-//

		// 指定された位置座標までを指定された割合分移動する　引数：移動先の座標の参照(const), 移動率
		void M_Go_To_Position_By_Now_Position(const DirectX::XMFLOAT3 & , float);

		// 指定された移動元から移動先までから指定された割合分移動する　引数：移動元の座標の参照(const), 移動先の座標の参照(const), 移動率
		void M_Go_To_Position_To_Position(const DirectX::XMFLOAT3 & , const DirectX::XMFLOAT3 & , float);

		// 指定された方向を前方として、指定された移動量分移動する　引数：移動方向, 移動量
		void M_Move_By_Direction(DirectX::XMFLOAT3, DirectX::XMFLOAT3);

		// 指定された方向を前方として、指定された移動量分移動する　引数：方向のマトリクス, XMFLOAT3 移動量
		void M_Move_By_Direction(DirectX::XMMATRIX, DirectX::XMFLOAT3);

		// 指定された移動方向へのみ移動量分移動する　引数：移動方向, 移動量
		void M_Move_Front_By_Direction(DirectX::XMFLOAT3, float);

		// 指定された移動方向へのみ移動量分移動する　引数：XMMATRIX 方向のマトリクス, float 移動量
		void M_Move_Front_By_Direction(DirectX::XMMATRIX, float);
	};
}


#endif // !D_INCLUDE_GUARD_C_POSITION_H_FILE
