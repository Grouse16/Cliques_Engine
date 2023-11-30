//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：カメラのクラス
// 説明   ：カメラビューとプロジェクションを担当するシステム
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Camera_System.h"
#include "E_MATRIX_DIRECTION.h"
#include "C_OS_System_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace GAME::CAMERA;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Camera_System::C_Camera_System(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Camera_System::~C_Camera_System(void)
{
	return;
}


//-☆- 更新 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：マトリクス変換行列を更新する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Camera_System::M_Update_Matrix(void)
{
	// ☆ 変数宣言 ☆ //
	DirectX::XMMATRIX rotation_matrix;	// 回転マトリクス

	DirectX::XMFLOAT3 camera_target_position = DirectX::XMFLOAT3();	// カメラの注視点
	DirectX::XMFLOAT3 camera_front_vector = DirectX::XMFLOAT3();	// カメラの前方ベクトル


	// 回転マトリクスを取得する
	rotation_matrix = mpr_variable.quaternion.M_Get_Rotation_Matrix();

	// カメラのターゲットをカメラの回転方向から求める
	DirectX::XMStoreFloat3(&camera_front_vector, rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_FRONT_VECTOR]);
	camera_target_position.x = mpr_variable.position.xyz.x + camera_front_vector.x * 100.0f;
	camera_target_position.y = mpr_variable.position.xyz.y + camera_front_vector.y * 100.0f;
	camera_target_position.z = mpr_variable.position.xyz.z + camera_front_vector.z * 100.0f;

	// ビュー変換行列を生成する
	mpr_variable.view_matrix = DirectX::XMMatrixLookAtLH
	(
		// カメラ座標
		DirectX::XMLoadFloat3(&mpr_variable.position.xyz),

		// カメラターゲット座標
		DirectX::XMLoadFloat3(&camera_target_position),

		// 上方向ベクトル
		rotation_matrix.r[(int)MATH::MATRIX::E_MATRIX_DIRECTION::e_VERTICAL_VECTOR]
	);


	// アスペクト比を更新
	mpr_variable.projection_system.aspect_ratio = OS::C_OS_System_Base::M_Get_Instance()->M_Get_Aspect_Size();

	// プロジェクション変換行列を生成する
	mpr_variable.projection_system.M_Get_Projection(mpr_variable.projection_matrix);

	return;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：カメラの視野角をラジアン基準の角度でセットする
// 引数   ：float ラジアンでの角度
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Camera_System::M_Set_Camera_Field_Of_View_Angle_By_Radian(float in_set_field_of_view_angle)
{
	mpr_variable.projection_system.field_of_view_angle = in_set_field_of_view_angle;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：カメラの視野角を度数基準の角度でセットする
// 引数   ：float 度数での角度
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Camera_System::M_Set_Camera_Field_Of_View_Angle_By_Degree(float in_set_field_of_view_angle)
{
	mpr_variable.projection_system.field_of_view_angle = DirectX::XMConvertToDegrees(in_set_field_of_view_angle);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：カメラのニアクリップ距離をセットする
// 引数   ：float ニアクリップ距離（視錐台カリングの描画範囲の最も近い距離）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Camera_System::M_Set_Near_Clip(float in_near_clip_distance)
{
	mpr_variable.projection_system.near_clip_plane = in_near_clip_distance;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：カメラのファークリップ距離をセットする
// 引数   ：float ファークリップ距離（視錐台カリングの描画範囲の最も近い距離）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Camera_System::M_Set_Far_Clip(float in_far_clip_distance)
{
	mpr_variable.projection_system.far_clip_plane = in_far_clip_distance;

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ビューのマトリクス変換行列を返す
// 引数   ：void
// 戻り値 ：const XMMATRIX & ビューのマトリクス変換行列の参照（const）
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const DirectX::XMMATRIX & C_Camera_System::M_Get_View_Matrix(void) const
{
	return mpr_variable.view_matrix;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：プロジェクションのマトリクス変換行列を返す
// 引数   ：void
// 戻り値 ：const XMMATRIX & プロジェクションのマトリクス変換行列の参照（const）
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const DirectX::XMMATRIX & C_Camera_System::M_Get_Projection_Matrix(void) const
{
	return mpr_variable.projection_matrix;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：カメラの座標への参照を返す
// 引数   ：void
// 戻り値 ：C_Position & カメラの座標への参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
MATH::POSITION::C_Position & C_Camera_System::M_Get_Position(void)
{
	return mpr_variable.position;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：カメラの回転（クォータニオン）への参照を返す
// 引数   ：void
// 戻り値 ：C_Quaternion & 回転（クォータニオン）への参照
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
MATH::QUATERNION::C_Quaternion & C_Camera_System::M_Get_Quaternion(void)
{
	return mpr_variable.quaternion;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：カメラの視野角をラジアン基準の角度で返す
// 引数   ：void
// 戻り値 ：float ラジアンでの角度
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
float C_Camera_System::M_Get_Camera_Field_Of_View_Angle(void)
{
	return mpr_variable.projection_system.field_of_view_angle;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：カメラのニアクリップ距離を返す
// 引数   ：void
// 戻り値 ：float ニアクリップ距離（視錐台カリングの描画範囲の最も近い距離）
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
float C_Camera_System::M_Get_Near_Clip(float)
{
	return mpr_variable.projection_system.near_clip_plane;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：カメラのファークリップ距離を返す
// 引数   ：void
// 戻り値 ：float ファークリップ距離（視錐台カリングの描画範囲の最も遠い距離）
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
float C_Camera_System::M_Get_Far_Clip(float)
{
	return mpr_variable.projection_system.far_clip_plane;
}
