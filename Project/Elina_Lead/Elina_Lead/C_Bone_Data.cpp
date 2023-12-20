//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ボーンのデータのクラス
// 説明   ：設定された情報をマトリクスに変換することも行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Bone_Data.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::ANIMATION::BONE;


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- マトリクス -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在のボーン情報をマトリクスに変換した値を引数にセットする
// 引数   ：XMFLOAT4X4 & 設定先のマトリクス情報の参照
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Bone_Data::M_Set_Bone_Matrix_Data(DirectX::XMFLOAT4X4 & out_matrix) const
{
    DirectX::XMStoreFloat4x4
    (
        // 設定先マトリクス行列
        &out_matrix,

        // スケール
        DirectX::XMMatrixScaling(scale.x, scale.y, scale.z) * 

        // クォータニオン（回転）
        DirectX::XMMatrixRotationQuaternion(quaternion) *

        // ポジション
        DirectX::XMMatrixTranslation(position.x, position.y, position.z)
    );

    return;
}
