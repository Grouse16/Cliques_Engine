//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーションモデルを使用するためのシステム
// 説明   ：アニメーションモデルマネージャーとの操作を隠蔽し、簡単に使用できるようにカプセル化する　アニメーションの実行を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_MODEL_USER
#define D_INCLUDE_GUARD_C_ANIMATION_MODEL_USER


// ☆ ファイルひらき ☆ //
#include <memory>

#include "C_3D_Animation_Model_System.h"
#include "C_Animation_Calculator_Base.h"


// ☆ ネームスペース ☆ //

// アニメーションモデルを使用するシステムを呼び出すための名前
namespace ASSET::ANIMATION_MODEL
{
	// ☆ クラス ☆ //

	// アニメーションモデルを使用するためのシステム
	class C_Animation_Model_User
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			ASSET::ANIMATION_MODEL::C_3D_Animation_Model_System * animation_model = nullptr;	// 使用するアニメーションモデルまでのアドレス

			std::unique_ptr<ASSET::ANIMATION::CALCULATOR::C_Animation_Calculator_Base> animation_calculator = nullptr;	// アニメーションの計算システム

		} mpr_variable;	// プライベート変数を呼び出すための名前


		//==☆ パブリック ☆==//
	public:


	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_MODEL_USER
