//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ゲーム上のシステムの基底となるクラス
// 説明   ：特定のクラスのインスタンスをまとめるクラスなど、ゲーム上で存在するが描画されないインスタンス
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_SYSTEM_BASE_H_FILE
#define D_INCLUDE_GUARD_C_SYSTEM_BASE_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_Game_Instance_Base.h"


// ☆ ネームスペース ☆ //

// ゲーム上のインスタンスのシステムの基底となるクラスを呼び出すための名前
namespace GAME::INSTANCE::GAME_SYSTEM::BASE
{
	// ☆ クラス ☆ //

	// システムの基底となるクラス
	class C_Game_System_Base : public GAME::INSTANCE::BASE::C_Game_Instance_Base
	{
		//==☆ プライベート ☆==//
	private:


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//
		
		// コンストラクタ
		C_Game_System_Base(void);

		// デストラクタ
		virtual ~C_Game_System_Base(void);

		
		//-☆- 更新 -☆-//

		// 更新を行う
		virtual void M_System_Update(void) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_SYSTEM_BASE_H_FILE

