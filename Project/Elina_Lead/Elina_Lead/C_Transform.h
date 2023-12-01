//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：オブジェクトの座標、回転、大きさの設定を行うシステム
// 説明   ：名前をトランスフォームとする
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_TRANSFORM_H_FILE
#define D_INCLUDE_GUARD_TRANSFORM_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_Position.h"
#include "C_Quaternion.h"
#include "C_Scale.h"


// ☆ ネームスペース ☆ //

// 数学系統のシステムを呼び出すための名前
namespace MATH
{
	// ☆ クラス ☆ //

	// トランスフォームのクラス
	class C_Transform
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		MATH::POSITION::C_Position position;	// 座標

		MATH::SCALE::C_Scale scale;	// スケール

		MATH::QUATERNION::C_Quaternion quaternion;	// クォータニオン


		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Transform(void);

		// デストラクタ
		~C_Transform(void);


		//-☆- 移動 -☆-//

		// 今向いている方向を前方として移動を行う　引数：移動量
		void M_Move(DirectX::XMFLOAT3);


		//-☆- 行列変換 -☆-//

		// ワールド変換行列に変換して返す　引数：変換データの設定先の参照
		void M_Generate_World_Matrix(DirectX::XMMATRIX & ) const;
	};
}


#endif // !D_INCLUDE_GUARD_TRANSFORM_H_FILE
