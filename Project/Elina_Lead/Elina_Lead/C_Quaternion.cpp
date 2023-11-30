//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：クォータニオンシステムのクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Quaternion.h"


// ☆ ネームスペースの省略 ☆ //
using namespace MATH::QUATERNION;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Quaternion::C_Quaternion(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Quaternion::~C_Quaternion(void)
{
	return;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：クォータニオンをセットする
// 引数   ：const XMVECTOR & セットするクォータニオンの参照（const）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Quaternion::M_Set_Quaternion(const DirectX::XMVECTOR & in_set_quaternion)
{
	mpr_variable.m_rotation_vector = in_set_quaternion;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：度数の回転の情報からクォータニオンをセットする
// 引数   ：XMFLOAT3 回転情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Quaternion::M_Set_Quaternion_By_Angle(DirectX::XMFLOAT3 in_set_rotation)
{
	mpr_variable.m_rotation_vector = DirectX::XMQuaternionRotationMatrix
	(
		DirectX::XMMatrixRotationRollPitchYaw
		(
			DirectX::XMConvertToRadians(in_set_rotation.x),
			DirectX::XMConvertToRadians(in_set_rotation.y),
			DirectX::XMConvertToRadians(in_set_rotation.z)
		)
	);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：度数の回転の情報からクォータニオンをセットする
// 引数   ：float ロール, float ピッチ, float ヨウ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Quaternion::M_Set_Quaternion_By_Angle(float in_roll, float in_pitch, float in_yaw)
{
	mpr_variable.m_rotation_vector = DirectX::XMQuaternionRotationMatrix
	(
		DirectX::XMMatrixRotationRollPitchYaw
		(
			DirectX::XMConvertToRadians(in_roll),
			DirectX::XMConvertToRadians(in_pitch),
			DirectX::XMConvertToRadians(in_yaw)
		)
	);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ラジアンの回転の情報からクォータニオンをセットする
// 引数   ：XMFLOAT3 回転情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Quaternion::M_Set_Quaternion_By_Radian(DirectX::XMFLOAT3 in_set_rotation)
{
	mpr_variable.m_rotation_vector = DirectX::XMQuaternionRotationMatrix
	(
		DirectX::XMMatrixRotationRollPitchYaw
		(
			in_set_rotation.x,
			in_set_rotation.y,
			in_set_rotation.z
		)
	);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ラジアンの回転の情報からクォータニオンをセットする
// 引数   ：float ロール, float ピッチ, float ヨウ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Quaternion::M_Set_Quaternion_By_Radian(float in_roll, float in_pitch, float in_yaw)
{
	mpr_variable.m_rotation_vector = DirectX::XMQuaternionRotationMatrix
	(
		DirectX::XMMatrixRotationRollPitchYaw
		(
			in_roll,
			in_pitch,
			in_yaw
		)
	);

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：クォータニオンの回転ベクトルを返す
// 引数   ：void
// 戻り値 ：XMVECTOR クォータニオンの回転ベクトル
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
DirectX::XMVECTOR C_Quaternion::M_Get_Quaternion_Rotation_Vector(void) const
{
	return mpr_variable.m_rotation_vector;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：回転のマトリクス変換行列を返す
// 引数   ：void
// 戻り値 ：XMMATRIX 回転マトリクス行列
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
DirectX::XMMATRIX C_Quaternion::M_Get_Rotation_Matrix(void) const
{
	return DirectX::XMMatrixRotationQuaternion(mpr_variable.m_rotation_vector);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在のクォータニオンから指定された回転方向へのベクトルを返す
// 引数   ：const XMFLOAT3 & 回転方向
// 戻り値 ：XMFLOAT3 指定された回転方向へのベクトル
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
DirectX::XMFLOAT3 C_Quaternion::M_Get_Rotated_Vector_By_Angle(const DirectX::XMFLOAT3 & in_rotation_vector) const
{
	// ☆ 変数宣言 ☆ //
	DirectX::XMFLOAT3 result_vector = DirectX::XMFLOAT3();	// 回転結果
	

	// マトリクス行列で指定された方向へのベクトルを生成
	DirectX::XMStoreFloat3
	(
		// 方向の設定先
		&result_vector,
		
		// 方向ベクトルの計算
		DirectX::XMVector3TransformNormal
		(
			DirectX::XMLoadFloat3(&in_rotation_vector),
			DirectX::XMMatrixRotationQuaternion(mpr_variable.m_rotation_vector)
		)
	);

	return result_vector;
}


//-☆- クォータニオン -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：度数で指定値分だけ回転させる
// 引数   ：float ロール, float ピッチ, float ヨウ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Quaternion::M_Add_Rotation_By_Angle(float in_roll, float in_pitch, float in_yaw)
{
	mpr_variable.m_rotation_vector = DirectX::XMQuaternionMultiply
	(
		mpr_variable.m_rotation_vector,
		DirectX::XMQuaternionRotationRollPitchYaw
		(
			DirectX::XMConvertToRadians(in_roll),
			DirectX::XMConvertToRadians(in_pitch),
			DirectX::XMConvertToRadians(in_yaw)
		)
	);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：度数で指定値分だけ回転させる
// 引数   ：XMFLOAT3 回転情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Quaternion::M_Add_Rotation_By_Angle(DirectX::XMFLOAT3 in_rotation)
{
	mpr_variable.m_rotation_vector = DirectX::XMQuaternionMultiply
	(
		mpr_variable.m_rotation_vector,
		DirectX::XMQuaternionRotationRollPitchYaw
		(
			DirectX::XMConvertToRadians(in_rotation.x),
			DirectX::XMConvertToRadians(in_rotation.y),
			DirectX::XMConvertToRadians(in_rotation.z)
		)
	);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ラジアンで指定値分だけ回転させる
// 引数   ：float ロール, float ピッチ, float ヨウ
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Quaternion::M_Add_Rotation_By_Radian(float in_roll, float in_pitch, float in_yaw)
{
	mpr_variable.m_rotation_vector = DirectX::XMQuaternionMultiply
	(
		mpr_variable.m_rotation_vector,
		DirectX::XMQuaternionRotationRollPitchYaw
		(
			in_roll,
			in_pitch,
			in_yaw
		)
	);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ラジアンで指定値分だけ回転させる
// 引数   ：XMFLOAT3 回転情報
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Quaternion::M_Add_Rotation_By_Radian(DirectX::XMFLOAT3 in_rotation)
{
	mpr_variable.m_rotation_vector = DirectX::XMQuaternionMultiply
	(
		mpr_variable.m_rotation_vector,
		DirectX::XMQuaternionRotationRollPitchYaw
		(
			in_rotation.x,
			in_rotation.y,
			in_rotation.z
		)
	);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在の回転ベクトルから指定されたクォータニオンまで補間率による球面線形補間を行う
// 引数   ：const XMVECTOR & 補間先のクォータニオンへの参照(const), float 補間率（0%で元値、100%で移動先と同じ値）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Quaternion::M_Slerp_To_Quaternion_By_Now_Vector(const DirectX::XMVECTOR & in_slerp_to, float in_percent)
{
	mpr_variable.m_rotation_vector = DirectX::XMQuaternionSlerp(mpr_variable.m_rotation_vector, in_slerp_to, in_percent);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：一つ目のクォータニオンから二つ目のクォータニオンへ指定された補間率の球面線形補間を行う
// 引数   ：const XMVECTOR & 補間元クォータニオンの参照(const), const XMVECTOR & 補間元クォータニオンの参照(const), float 補間率（0%で一つ目、100%で二つと同じ位置）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Quaternion::M_Slerp_Quaternion_A_To_B(const DirectX::XMVECTOR & in_slerp_base, const DirectX::XMVECTOR & in_slerp_to, float in_percent)
{
	mpr_variable.m_rotation_vector = DirectX::XMQuaternionSlerp(in_slerp_base, in_slerp_to, in_percent);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在の回転ベクトルから指定されたクォータニオンまで補間率による線形補間を行う
// 引数   ：const XMVECTOR & 補間先クォータニオンの参照(const), float 補間率（0%で元値、100%で移動先と同じ値）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Quaternion::M_Lerp_To_Quaternion_By_Now_Vector(const DirectX::XMVECTOR & in_lerp_to, float in_percent)
{
	mpr_variable.m_rotation_vector = DirectX::XMVectorLerp(mpr_variable.m_rotation_vector, in_lerp_to, in_percent);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：一つ目のクォータニオンから二つ目のクォータニオンへ指定された補間率の線形補間を行う
// 引数   ：const XMVECTOR & 補間元クォータニオンの参照(const), const XMVECTOR & 補間先クォータニオンの参照(const), float 補間率（0%で一つ目、100%で二つと同じ位置）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Quaternion::M_Lerp_Quaternion_A_To_B(const DirectX::XMVECTOR & in_lerp_base, const DirectX::XMVECTOR & in_lerp_to, float in_percent)
{
	mpr_variable.m_rotation_vector = DirectX::XMVectorLerp(in_lerp_base, in_lerp_to, in_percent);

	return;
}
