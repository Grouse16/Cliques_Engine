//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーションのアルゴリズムの基底クラス
// 説明   ：どんなアニメーションをするかを分岐ではなく、生成するクラスによって分岐できるようにするための抽象化レイヤー
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_ALGORITHM_BASE_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_ALGORITHM_BASE_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>
#include <DirectXMath.h>

#include "C_Animation_Data_System.h"
#include "S_Animation_Status.h"


// ☆ ネームスペース ☆ //

// アニメーションの計算アルゴリズムを呼び出すための名前
namespace ASSET::ANIMATION::ALGORITHM
{
	// ☆ クラス ☆ //

	// アニメーションの計算を制御するクラスの基底クラス
	class C_Animation_Algorithm_Base
	{
		//==☆ プロテクト ☆==//
	protected:

		// ☆ 関数 ☆ //

		//-☆- 論理演算 -☆-//

		// 値１が値２より大きいなら値１に値２をセットする、そうでないなら何もしない　引数：値１, 値２
		void M_Guard_1_Over_2(float &, float);

		// アニメーションの時間の再生と逆再生時を行い、アニメーションの終了も判定する　引数：アニメーションの情報の参照, アニメーション開始から終了までの時間
		void M_Animation_Time_Base_Update(ASSET::ANIMATION::S_Animation_Status &, float);

		// ブレンド元の時間の再生と逆再生を行う　引数：アニメーションの情報(const), ブレンド元の時間の参照, アニメーション開始から終了までの時間
		void M_Animation_Blend_Time_Update(const ASSET::ANIMATION::S_Animation_Status &, float & , float);

		// ループするアニメーションの時間の再生と逆再生時を行う　引数：アニメーションの情報の参照, アニメーション開始から終了までの時間
		void M_Loop_Animation_Time_Base_Update(ASSET::ANIMATION::S_Animation_Status &, float);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Animation_Algorithm_Base(void);

		// デストラクタ
		virtual ~C_Animation_Algorithm_Base(void);

		
		//-☆- 更新 -☆-//

		// アニメーション時間の更新
		virtual void M_Animation_Time_Update(void) = 0;

		// アニメーションの更新　引数：更新をかけるボーンのマトリクスの配列の参照, ボーンのオフセットマトリクスのリストの参照(const)
		virtual void M_Animation_Update(std::vector<DirectX::XMFLOAT4X4> &, const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> &) = 0;


		//-☆- ゲッタ -☆-//

		// 現在のアニメーションを返す　戻り値：現在のアニメーションのアドレス
		virtual const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * M_Get_Now_Animation(void) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_CALCULATE_ALGORITHM_BASE_H_FILE
