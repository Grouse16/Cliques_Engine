//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アクターの基底となるクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_ACTOR_BASE_H_FILE
#define D_INCLUDE_GUARD_C_ACTOR_BASE_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_Game_Instance_Base.h"


// ☆ ネームスペース ☆ //

// ゲームのアクターの基底クラスを呼び出すための名前
namespace GAME::INSTANCE::ACTOR::BASE
{
	// ☆ クラス ☆ //

	// アクターの基底となるクラス
	class C_Actor_Base : public GAME::INSTANCE::BASE::C_Game_Instance_Base
	{
		//==☆ プライベート ☆==// 
	private:

		// ☆ 変数宣言 ☆ //
		



		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 優先度 -☆-//

		// アクターの優先度を返す　戻り値：アクターの優先度
		virtual int M_Get_Priority(void) = 0;


		//-☆- 更新 -☆-//

		// アクターの更新を行う
		virtual void M_Actor_Update(void) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_ACTOR_BASE_H_FILE


