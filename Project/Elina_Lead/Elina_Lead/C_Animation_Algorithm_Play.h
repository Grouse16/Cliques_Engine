//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：通常にアニメーションを再生するクラス
// 説明   ：一つのアニメーションを持ってそれの再生のみ行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_ALGORITHM_PLAY_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_ALGORITHM_PLAY_H_FILE


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

	// 通常にアニメーションを再生するクラス
	class C_Animation_Algorithm_Play : public ASSET::ANIMATION::ALGORITHM::C_Animation_Algorithm_Base
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //
		ASSET::ANIMATION::S_Animation_Status & m_animation_status;	// アニメーションステータス

		const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * m_now_animation = nullptr;	// 現在のアニメーション


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ　何も引数に設定しないコンストラクタを無効化
		C_Animation_Algorithm_Play(void) = delete;

		// コンストラクタ　引数：アニメーションステータスの参照, アニメーションするデータのセット(const)
		C_Animation_Algorithm_Play(ASSET::ANIMATION::S_Animation_Status & , const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * );

		// デストラクタ
		~C_Animation_Algorithm_Play(void) override;


		//-☆- 更新 -☆-//

		// アニメーション時間の更新
		void M_Animation_Time_Update(void) override;

		// アニメーションの更新　引数：更新をかけるボーンのマトリクスの配列の参照, ボーンのオフセットマトリクスのリストの参照(const)
		void M_Animation_Update(std::vector<DirectX::XMFLOAT4X4> &, const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & ) override;


		//-☆- ゲッタ -☆-//

		// 現在のアニメーションを返す　戻り値：現在のアニメーションのアドレス(const)
		const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * M_Get_Now_Animation(void) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_ALGORITHM_PLAY_H_FILE
