//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：サウンドの基底となるクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_SOUND_BASE_H_FILE
#define D_INCLUDE_GUARD_C_SOUND_BASE_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_Game_Instance_Base.h"


// ☆ ネームスペース ☆ //

// ゲームのサウンドの基底クラスを呼び出すための名前
namespace GAME::INSTANCE::SOUND::BASE
{
	// ☆ クラス ☆ //

	// サウンドの基底となるクラス
	class C_Sound_Base : public GAME::INSTANCE::BASE::C_Game_Instance_Base
	{
		//==☆ プライベート ☆==//
	private:


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Sound_Base(void);

		// デストラクタ
		virtual ~C_Sound_Base(void);


		//-☆- 更新 -☆-//

		// サウンドの更新を行う
		virtual void M_Sound_Update(void) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_SOUND_BASE_H_FILE

