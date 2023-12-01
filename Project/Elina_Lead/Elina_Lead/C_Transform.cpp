//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：オブジェクトの座標、回転、大きさの設定
// 説明   ：名前をトランスフォームとする
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Transform.h"


// ☆ ネームスペースの省略 ☆ //
using namespace MATH;


// ☆ 関数 ☆ //

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Transform::C_Transform(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Transform::~C_Transform(void)
{
	return;
}


//-☆- 移動 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：今向いている方向を前方として移動を行う
// 引数   ：移動量
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Transform::M_Move(DirectX::XMFLOAT3 in_move_value)
{
	position.M_Move_By_Direction(quaternion.M_Get_Rotation_Matrix(), in_move_value);

	return;
}


//-☆- 行列変換 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ワールド変換行列に変換して返す
// 引数   ：XMMATRIX & 変換データの設定先の参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Transform::M_Generate_World_Matrix(DirectX::XMMATRIX & put_set_matrix) const
{
	// 変換行列を生成してセットする
	put_set_matrix =

		// スケール
		scale.M_Get_Scale_Matrix()
		*

		// 回転
		quaternion.M_Get_Rotation_Matrix() 
		*

		// 位置座標
		position.M_Get_Position_Matrix();
	
	return;
}


