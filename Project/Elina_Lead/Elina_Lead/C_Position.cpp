//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：位置座標のクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Position.h"
#include "E_MATRIX_DIRECTION.h"


// ☆ ネームスペースの省略 ☆ //
using namespace MATH::POSITION;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Position::C_Position(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Position::~C_Position(void)
{
	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：位置座標のマトリクス変換行列を返す
// 引数   ：void
// 戻り値 ：XMMATRIX 位置座標のマトリクス変換行列
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
DirectX::XMMATRIX C_Position::M_Get_Position_Matrix(void) const
{
	return DirectX::XMMatrixTranslationFromVector(DirectX::XMVectorSet(xyz.x, xyz.y, xyz.z, 1.0f));
}


//-☆- 移動 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された位置座標までを指定された割合分移動する
// 引数   ：const XMFLOAT3 & 移動先の座標の参照(const), float 移動率
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Position::M_Go_To_Position_By_Now_Position(const DirectX::XMFLOAT3 & in_to_position, float in_percent)
{
	xyz.x += in_to_position.x * in_percent;
	xyz.y += in_to_position.y * in_percent;
	xyz.z += in_to_position.z * in_percent;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された移動元から移動先までから指定された割合分移動する
// 引数   ：const XMFLOAT3 & 移動元の座標の参照(const), const XMFLOAT3 & 移動先の座標の参照(const), float 移動率
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Position::M_Go_To_Position_To_Position(const DirectX::XMFLOAT3 & in_base_position, const DirectX::XMFLOAT3 & in_to_position, float in_percent)
{
	xyz.x = in_base_position.x + in_to_position.x * in_percent;
	xyz.y = in_base_position.y + in_to_position.y * in_percent;
	xyz.z = in_base_position.z + in_to_position.z * in_percent;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された方向を前方として、指定された移動量分移動する
// 引数   ：XMFLOAT3 移動方向, XMFLOAT3 移動量
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Position::M_Move_By_Direction(DirectX::XMFLOAT3 in_move_dire, DirectX::XMFLOAT3 in_move_value)
{
	// ☆ 変数宣言 ☆ //
	DirectX::XMMATRIX rotation_matrix = DirectX::XMMatrixIdentity();	// 回転のマトリクス
	
	DirectX::XMFLOAT3 side_vector = DirectX::XMFLOAT3();	// 横方向ベクトル（右基準）
	DirectX::XMFLOAT3 vertical_vector = DirectX::XMFLOAT3();	// 縦方向ベクトル（上基準）
	DirectX::XMFLOAT3 front_vector = DirectX::XMFLOAT3();	// 前後方向ベクトル（前基準）

	
	// 移動方向への回転マトリクスを取得
	rotation_matrix = DirectX::XMMatrixRotationRollPitchYaw(in_move_dire.y, in_move_dire.z, in_move_dire.x);

	// それぞれの方向を取得
	DirectX::XMStoreFloat3(&side_vector, rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_SIDE_VECTOR]);
	DirectX::XMStoreFloat3(&vertical_vector, rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_VERTICAL_VECTOR]);
	DirectX::XMStoreFloat3(&front_vector, rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_FRONT_VECTOR]);


	// 方向成分に対する移動を行う
	xyz.x = side_vector.x * in_move_value.x + vertical_vector.x * in_move_value.y + front_vector.x * in_move_value.z;
	xyz.y = side_vector.y * in_move_value.x + vertical_vector.y * in_move_value.y + front_vector.y * in_move_value.z;
	xyz.z = side_vector.z * in_move_value.x + vertical_vector.z * in_move_value.y + front_vector.z * in_move_value.z;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された方向を前方として、指定された移動量分移動する
// 引数   ：XMMATRIX 方向のマトリクス, XMFLOAT3 移動量
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Position::M_Move_By_Direction(DirectX::XMMATRIX in_move_dire, DirectX::XMFLOAT3 in_move_value)
{
	// ☆ 変数宣言 ☆ //
	DirectX::XMFLOAT3 side_vector = DirectX::XMFLOAT3();	// 横方向ベクトル（右基準）
	DirectX::XMFLOAT3 vertical_vector = DirectX::XMFLOAT3();	// 縦方向ベクトル（上基準）
	DirectX::XMFLOAT3 front_vector = DirectX::XMFLOAT3();	// 前後方向ベクトル（前基準）


	// それぞれの方向を取得
	DirectX::XMStoreFloat3(&side_vector, in_move_dire.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_SIDE_VECTOR]);
	DirectX::XMStoreFloat3(&vertical_vector, in_move_dire.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_VERTICAL_VECTOR]);
	DirectX::XMStoreFloat3(&front_vector, in_move_dire.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_FRONT_VECTOR]);


	// 方向成分に対する移動を行う
	xyz.x = side_vector.x * in_move_value.x + vertical_vector.x * in_move_value.y + front_vector.x * in_move_value.z;
	xyz.y = side_vector.y * in_move_value.x + vertical_vector.y * in_move_value.y + front_vector.y * in_move_value.z;
	xyz.z = side_vector.z * in_move_value.x + vertical_vector.z * in_move_value.y + front_vector.z * in_move_value.z;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された移動方向へのみ指定された移動量分移動する
// 引数   ：XMFLOAT3 方向のマトリクス, float 移動量
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Position::M_Move_Front_By_Direction(DirectX::XMFLOAT3 in_move_dire, float in_move_value)
{
	// ☆ 変数宣言 ☆ //
	DirectX::XMMATRIX rotation_matrix = DirectX::XMMatrixIdentity();	// 回転のマトリクス

	DirectX::XMFLOAT3 side_vector = DirectX::XMFLOAT3();	// 横方向ベクトル（右基準）
	DirectX::XMFLOAT3 vertical_vector = DirectX::XMFLOAT3();	// 縦方向ベクトル（上基準）
	DirectX::XMFLOAT3 front_vector = DirectX::XMFLOAT3();	// 前後方向ベクトル（前基準）


	// 移動方向への回転マトリクスを取得
	rotation_matrix = DirectX::XMMatrixRotationRollPitchYaw(in_move_dire.y, in_move_dire.z, in_move_dire.x);

	// それぞれの方向を取得
	DirectX::XMStoreFloat3(&side_vector, rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_SIDE_VECTOR]);
	DirectX::XMStoreFloat3(&vertical_vector, rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_VERTICAL_VECTOR]);
	DirectX::XMStoreFloat3(&front_vector, rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_FRONT_VECTOR]);


	// 方向成分に対する移動を行う
	xyz.x = front_vector.x * in_move_value;
	xyz.y = front_vector.y * in_move_value;
	xyz.z = front_vector.z * in_move_value;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定された移動方向へのみ指定された移動量分移動する
// 引数   ：XMMATRIX 方向のマトリクス, float 移動量
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Position::M_Move_Front_By_Direction(DirectX::XMMATRIX in_move_dire, float in_move_value)
{
	// ☆ 変数宣言 ☆ //
	DirectX::XMFLOAT3 side_vector = DirectX::XMFLOAT3();	// 横方向ベクトル（右基準）
	DirectX::XMFLOAT3 vertical_vector = DirectX::XMFLOAT3();	// 縦方向ベクトル（上基準）
	DirectX::XMFLOAT3 front_vector = DirectX::XMFLOAT3();	// 前後方向ベクトル（前基準）


	// それぞれの方向を取得
	DirectX::XMStoreFloat3(&side_vector, in_move_dire.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_SIDE_VECTOR]);
	DirectX::XMStoreFloat3(&vertical_vector, in_move_dire.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_VERTICAL_VECTOR]);
	DirectX::XMStoreFloat3(&front_vector, in_move_dire.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_FRONT_VECTOR]);


	// 方向成分に対する移動を行う
	xyz.x = front_vector.x * in_move_value;
	xyz.y = front_vector.y * in_move_value;
	xyz.z = front_vector.z * in_move_value;

	return;
}
