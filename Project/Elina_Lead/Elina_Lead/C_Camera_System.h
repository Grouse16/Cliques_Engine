//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：カメラのクラス
// 説明   ：カメラビューとプロジェクションを担当するシステム
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_CAMERA_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_CAMERA_SYSTEM_H_FILE


// ☆ ファイルひらき ☆ //
#include <DirectXMath.h>

#include "C_Position.h"
#include "C_Quaternion.h"
#include "C_Projection_System.h"


// ☆ ネームスペース ☆ //

// カメラを呼び出すための名前
namespace GAME::CAMERA
{
	// ☆ クラス ☆ //

	// カメラのシステム
	class C_Camera_System
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			MATH::POSITION::C_Position position;	// カメラのポジション

			MATH::QUATERNION::C_Quaternion quaternion;	// カメラの回転（クォータニオン）

			GAME::CAMERA::PROJECTION::C_Projection_System projection_system;	// プロジェクション

			DirectX::XMMATRIX view_matrix = DirectX::XMMATRIX();		// ビューのマトリクス変換行列
			DirectX::XMMATRIX projection_matrix = DirectX::XMMATRIX();	// プロジェクションのマトリクス変換行列

		} mpr_variable;	// プライベート変数を呼び出すための名前


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Camera_System(void);

		// デストラクタ
		~C_Camera_System(void);


		//-☆- 更新 -☆-//

		// マトリクス変換行列を更新する
		void M_Update_Matrix(void);


		//-☆- セッタ -☆-//

		// カメラの視野角をラジアン基準の角度でセットする　引数：ラジアンでの角度
		void M_Set_Camera_Field_Of_View_Angle_By_Radian(float);

		// カメラの視野角を度数基準の角度でセットする　引数：度数での角度
		void M_Set_Camera_Field_Of_View_Angle_By_Degree(float);

		// カメラのニアクリップ距離をセットする　引数：ニアクリップ距離（視錐台カリングの描画範囲の最も近い距離）
		void M_Set_Near_Clip(float);

		// カメラのファークリップ距離をセットする　引数：ファークリップ距離（視錐台カリングの描画範囲の最も遠い距離）
		void M_Set_Far_Clip(float);


		//-☆- ゲッタ -☆-//

		// ビューのマトリクス変換行列を返す　戻り値：ビューのマトリクス変換行列の参照（const）
		const DirectX::XMMATRIX & M_Get_View_Matrix(void) const;

		// プロジェクションのマトリクス変換行列を返す　戻り値：プロジェクションのマトリクス変換行列の参照（const）
		const DirectX::XMMATRIX & M_Get_Projection_Matrix(void) const;

		// カメラの座標への参照を返す　戻り値：カメラの座標への参照
		MATH::POSITION::C_Position & M_Get_Position(void);

		// カメラの回転（クォータニオン）への参照を返す　戻り値：回転（クォータニオン）への参照
		MATH::QUATERNION::C_Quaternion & M_Get_Quaternion(void);

		// カメラの視野角をラジアン基準の角度で返す　引数：ラジアンでの角度
		float M_Get_Camera_Field_Of_View_Angle(void);

		// カメラのニアクリップ距離を返す　引数：ニアクリップ距離（視錐台カリングの描画範囲の最も近い距離）
		float M_Get_Near_Clip(float);

		// カメラのファークリップ距離を返す　引数：ファークリップ距離（視錐台カリングの描画範囲の最も遠い距離）
		float M_Get_Far_Clip(float);
	};
}


#endif // !D_INCLUDE_GUARD_C_CAMERA_SYSTEM_H_FILE

