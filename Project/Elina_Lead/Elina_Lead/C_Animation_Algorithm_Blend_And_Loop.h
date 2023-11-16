//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ブレンド後ループアニメーションを行うクラス
// 説明   ：ブレンドが終了した際のシングルトンアニメーションと入れ替えるための情報はアニメーションステータス情報にセットされる
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_ALGORITHM_BLEND_LOOP_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_ALGORITHM_BLEND_LOOP_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>

#include "C_Animation_Algorithm_Base.h"
#include "C_Animation_Data_System.h"
#include "S_Animation_Status.h"


// ☆ ネームスペース ☆ //

// アニメーションの計算アルゴリズムを呼び出すための名前
namespace ASSET::ANIMATION::ALGORITHM
{
	// ☆ クラス ☆ //

	// ブレンド後ループアニメーションを行うクラス
	class C_Animation_Algorithm_Blend_And_Loop : public ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Base
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //
		ASSET::ANIMATION::S_Animation_Status & m_animation_status;	// アニメーションステータス

		const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * m_from_animation = nullptr;	// ブレンド元のアニメーション
		const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * m_to_animation = nullptr;	// ブレンド先のアニメーション

		float animation_from_time = 0.0f;	// アニメーション元のアニメーション時間


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ　何も引数に設定しないコンストラクタを無効化
		C_Animation_Algorithm_Blend_And_Loop(void) = delete;

		// コンストラクタ　引数：アニメーションステータスの参照, ブレンド元のアニメーション(const), ブレンド先のアニメーション(const)
		C_Animation_Algorithm_Blend_And_Loop(ASSET::ANIMATION::S_Animation_Status &, const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System *, const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System *);

		// デストラクタ
		~C_Animation_Algorithm_Blend_And_Loop(void) override;


		//-☆- 更新 -☆-//

		// アニメーション時間の更新
		void M_Animation_Time_Update(void) override;

		// アニメーションの更新　引数：更新をかけるボーンのマトリクスの配列の参照
		void M_Animation_Update(std::vector<DirectX::XMFLOAT4X4> &) override;


		//-☆- ゲッタ -☆-//

		// 現在のアニメーションを返す　戻り値：現在のアニメーションのアドレス(const)
		const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System* M_Get_Now_Animation(void) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_ALGORITHM_BLEND_LOOP_H_FILE
