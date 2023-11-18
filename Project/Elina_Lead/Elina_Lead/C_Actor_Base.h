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
		bool m_draw_flg = true;			// 描画するかどうかのフラグ
		bool m_after_draw_flg = false;	// 通常描画後に描画するかどうかのフラグ


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Actor_Base(void);

		// デストラクタ
		~C_Actor_Base(void);


		//-☆- 優先度 -☆-//

		// アクターの優先度を返す　戻り値：アクターの優先度
		virtual int M_Get_Priority(void) = 0;


		//-☆- 更新 -☆-//

		// アクターの更新を行う
		virtual void M_Actor_Update(void) = 0;


		//-☆- 描画 -☆-//

		// アクター描画する
		virtual void M_Actor_Draw(void) = 0;

		// 通常描画後にアクターを描画する
		virtual void M_Actor_After_Draw(void) = 0;


		//-☆- セッタ -☆-//

		// アクターを通常描画で描画するかどうかのフラグをセットする　引数：trueの時は描画する、falseの時は描画しない
		void M_Set_Draw_Flg(bool);

		// 通常描画後にアクターを描画するかどうかのフラグをセットする　引数：trueの時は描画する、falseの時は描画しない
		void M_Set_After_Draw_Flg(bool);

		
		//-☆- ゲッタ -☆-//

		// アクターを描画するかどうかのフラグを返す　戻り値：trueは描画する、falseは描画しない
		bool M_Get_Draw_Flg(void);

		// 通常描画後にアクターを描画するかどうかのフラグを返す　戻り値：trueは描画する、falseは描画しない
		bool M_Get_After_Draw_Flg(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_ACTOR_BASE_H_FILE


