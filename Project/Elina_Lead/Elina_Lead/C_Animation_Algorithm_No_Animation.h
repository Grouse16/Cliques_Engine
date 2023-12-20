//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーションを行わない時のモデル表示用のクラス（初期化用）
// 説明   ：アニメーションの再生が設定されるまでの間、Tポーズのような初期状態を設定するクラス
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_ALGORITHM_NO_ANIMATION_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_ALGORITHM_NO_ANIMATION_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>

#include "C_Animation_Algorithm_Base.h"
#include "S_Bone_Inform.h"


// ☆ ネームスペース ☆ //

// アニメーションの計算アルゴリズムを呼び出すための名前
namespace ASSET::ANIMATION::ALGORITHM
{
	// ☆ クラス ☆ //

	// アニメーションを行わない時のモデル表示用のクラス（初期化用）
	class C_Animation_Algorithm_No_Animation : public ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Base
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Animation_Algorithm_No_Animation(void);

		// デストラクタ
		~C_Animation_Algorithm_No_Animation(void) override;


		//-☆- 更新 -☆-//

		// アニメーション時間の更新
		void M_Animation_Time_Update(void) override;

		// アニメーションの更新　引数：更新をかけるボーンのマトリクスの配列の参照, ボーンのオフセットマトリクスの配列の参照(const)
		void M_Animation_Update(std::vector<DirectX::XMFLOAT4X4> & , const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & ) override;


		//-☆- ゲッタ -☆-//

		// 現在のアニメーションを返す　戻り値：現在のアニメーションのアドレス
		ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * M_Get_Now_Animation(void) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_ALGORITHM_NO_ANIMATION_H_FILE

