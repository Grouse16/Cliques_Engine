//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：メインカメラのシステム
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Main_Camera.h"
#include "C_Projection_System.h"
#include "C_OS_System_Base.h"


// ☆ ネームスペースの省略 ☆ //
using namespace GAME::CAMERA::MAIN_CAMERA;


// ☆ スタティック変数 ☆ //
C_Main_Camera C_Main_Camera::m_this;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- 初期化 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Main_Camera::C_Main_Camera(void)
{
	return;
}


//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メインカメラを初期化する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Main_Camera::M_Reset(void)
{
	// ☆ 定数 ☆ //
	GAME::CAMERA::PROJECTION::C_Projection_System projection_init;	// プロジェクションの初期値


	// ビューのマトリクスを初期化する
	m_this.mpr_variable.view = DirectX::XMMATRIX();

	// プロジェクションのマトリクスを初期化する
	projection_init.aspect_ratio = OS::C_OS_System_Base::M_Get_Instance()->M_Get_Aspect_Size();
	projection_init.M_Get_Projection(m_this.mpr_variable.projection);

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Main_Camera::~C_Main_Camera(void)
{
	return;
}


//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ビューのマトリクス変換行列をセットする
// 引数   ：const XMMATRIX & セットするビューのマトリクス変換行列の参照（const）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Main_Camera::M_Set_View_Matrix(const DirectX::XMMATRIX & in_set_view)
{
	m_this.mpr_variable.view = in_set_view;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：プロジェクションのマトリクス変換行列をセットする
// 引数   ：const XMMATRIX & セットするプロジェクションのマトリクス変換行列の参照（const）
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Main_Camera::M_Set_Projection_Matrix(const DirectX::XMMATRIX & in_set_projection)
{
	m_this.mpr_variable.projection = in_set_projection;

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ビューのマトリクス変換行列の参照を返す
// 引数   ：void
// 戻り値 ：const XMMATRIX & ビューのマトリクス変換行列の参照（const）
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const DirectX::XMMATRIX & C_Main_Camera::M_Get_View_Matrix(void)
{
	return m_this.mpr_variable.view;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：プロジェクションのマトリクス変換行列の参照を返す
// 引数   ：void
// 戻り値 ：const XMMATRIX & プロジェクションのマトリクス変換行列の参照（const）
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
const DirectX::XMMATRIX & C_Main_Camera::M_Get_Projection_Matrix(void)
{
	return m_this.mpr_variable.projection;
}
