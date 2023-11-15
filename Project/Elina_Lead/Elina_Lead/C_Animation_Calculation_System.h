//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーションの計算を制御するクラス
// 説明   ：ボーンマトリクスに対するアニメーションの操作を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_CALCULATION_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_CALCULATION_SYSTEM_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>

#include "C_Animation_Calculator_Algorithm_Base.h"
#include "C_Animation_Data_System.h"


// ☆ ネームスペース ☆ //

// アニメーションの計算システムを呼び出すための名前
namespace ASSET::ANIMATION::CALCULATOR
{
	// ☆ クラス ☆ //
	
	// アニメーションの計算を制御するクラス
	class C_Animation_Calculation_System
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::unique_ptr<ASSET::ANIMATION::CALCULATOR::ALGORITHM::C_Animation_Calculate_Algorithm_Base> animation_algorithm = nullptr;	// アニメーションのアルゴリズム


		} mpr_variable;	// プライベート変数を呼び出すための名前


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Animation_Calculation_System(void);

		// デストラクタ
		~C_Animation_Calculation_System(void);


		//-☆- 更新 -☆-//


		//-☆- アニメーション -☆-//

		// 指定された配列にボーンマトリクス配列のデータをセットする
		void M_Get_Bone_Matrix(std::vector<DirectX::XMFLOAT4X4> &);
	};
}

#endif // !D_INCLUDE_GUARD_C_ANIMATION_CALCULATION_SYSTEM_H_FILE
