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

		// ☆ 変数宣言 ☆ //
		bool m_flg_draw_before_ui = true;	// UI描画前にポストエフェクトを描画するかどうかのフラグ、trueで描画する
		bool m_flg_draw_after_ui = false;	// UI描画後にポストエフェクトを描画するかどうかのフラグ、trueで描画する


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Post_Effect_Base(void);

		// デストラクタ
		virtual ~C_Post_Effect_Base(void);


		//-☆- 更新 -☆-//

		// ポストエフェクトの更新を行う
 		virtual void M_Post_Effect_Update(void) = 0;


		//-☆- 描画 -☆-//

		// ポストエフェクトのUI前の描画を行う
		virtual void M_Post_Effect_Draw_Before_UI(void) = 0;

		// ポストエフェクトのUI後の描画を行う
		virtual void M_Post_Effect_Draw_After_UI(void) = 0;


		//-☆- セッタ -☆-//

		// UI描画前にポストエフェクトを描画するかどうかのフラグをセットする　引数：trueで描画する、falseは描画しない
		void M_Set_Flg_Post_Effect_Before_UI_Draw(bool);

		// UI描画後にポストエフェクトを描画するかどうかのフラグをセットする　引数：trueで描画する、falseは描画しない
		void M_Set_Flg_Post_Effect_After_UI_Draw(bool);


		//-☆- ゲッタ -☆-//

		// UI描画前にポストエフェクトを描画するかどうかのフラグを返す　戻り値：trueで描画する、falseは描画しない
		bool M_Get_Flg_Post_Effect_Before_UI_Draw(void);

		// UI描画後にポストエフェクトを描画するかどうかのフラグを返す　戻り値：trueで描画する、falseは描画しない
		bool M_Get_Flg_Post_Effect_After_UI_Draw(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_POST_EFFECT_BASE_H_FILE
