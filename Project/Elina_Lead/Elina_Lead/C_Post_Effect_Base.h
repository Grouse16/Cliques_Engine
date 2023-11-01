//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ポストエフェクトの基底となるクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_POST_EFFECT_BASE_H_FILE
#define D_INCLUDE_GUARD_C_POST_EFFECT_BASE_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_Game_Instance_Base.h"


// ☆ ネームスペース ☆ //

// ゲームのポストエフェクトの基底クラスを呼び出すための名前
namespace GAME::INSTANCE::POST_EFFECT::BASE
{
	// ☆ クラス ☆ //

	// ポストエフェクトの基底となるクラス
	class C_Post_Effect_Base : public GAME::INSTANCE::BASE::C_Game_Instance_Base
	{
		//==☆ プライベート ☆==//
	private:


		//==☆ パブリック ☆==//
	public:
	};
}


#endif // !D_INCLUDE_GUARD_C_POST_EFFECT_BASE_H_FILE
