//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：プロジェクションのシステム
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Projection_System.h"


// ☆ ネームスペースの省略 ☆ //
using namespace GAME::CAMERA::PROJECTION;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Projection_System::C_Projection_System(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Projection_System::~C_Projection_System(void)
{
	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：プロジェクションのマトリクス変換行列を渡された参照先にセットする
// 引数   ：XMMATRIX & プロジェクションのマトリクス変換行列の設定先の参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Projection_System::M_Get_Projection(DirectX::XMMATRIX & out_projection_matrix) const
{
	out_projection_matrix = DirectX::XMMatrixPerspectiveFovLH
	(
		// 視野角
		field_of_view_angle,

		// アスペクト比
		aspect_ratio,

		// 描画範囲開始までの距離（視錐台カリング）
		near_clip_plane,

		// 描画範囲終了までの距離（視錐台カリング）
		far_clip_plane
	);

	return;
}
