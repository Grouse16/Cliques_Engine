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
#include <vector>

#include "C_Animation_Algorithm_Base.h"
#include "S_Bone_Inform.h"
#include "S_Animation_Status.h"
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
			std::unique_ptr<ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Base> animation_algorithm = nullptr;	// アニメーションのアルゴリズム

			ASSET::ANIMATION::S_Animation_Status animation_status;	// アニメーションのステータス

			int bone_sum = 0;	// ボーン数

		} mpr_variable;	// プライベート変数を呼び出すための名前


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタによる初期化を無効し、ボーン情報のリストをセットしなければ初期化できなくする
		C_Animation_Calculation_System(void) = delete;

		// コンストラクタ　引数：ボーン情報のリストの参照(const)
		C_Animation_Calculation_System(const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & );

		// デストラクタ
		~C_Animation_Calculation_System(void);

		// メモリの解放を行う
		void M_Release(void);


		//-☆- アニメーション -☆-//

		// 渡されたアニメーションを再生する　引数：設定するアニメーションデータのアドレス
		void M_Play_Animation(ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * );

		// 指定された配列にアニメーション結果のボーンマトリクス配列のデータをセットする　引数：設定先のボーンマトリクス配列のデータの参照
		void M_Create_Animationed_Bone_Matrix(std::vector<DirectX::XMFLOAT4X4> &);
	};
}

#endif // !D_INCLUDE_GUARD_C_ANIMATION_CALCULATION_SYSTEM_H_FILE
