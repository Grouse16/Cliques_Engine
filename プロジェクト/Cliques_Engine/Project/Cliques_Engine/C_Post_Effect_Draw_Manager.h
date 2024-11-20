//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ポストエフェクトの描画制御システム
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_POST_EFFECT_DRAW_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_POST_EFFECT_DRAW_MANAGER_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>

#include "C_Post_Effect_Base.h"


// ☆ ネームスペース ☆ //

// ポストエフェクトの描画制御システムを呼び出すための名前
namespace GAME::INSTANCE::POST_EFFECT::DRAW_MANAGER
{
	// ☆ クラス ☆ //

	// ポストエフェクトの描画制御をするクラス
	class C_Post_Effect_Draw_Manager
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::vector<GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base * > post_effect_before_ui_list;	// UIの描画前に描画するポストエフェクトのリスト
			std::vector<GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base * > post_effect_after_ui_list;	// UIの描画後に描画するポストエフェクトのリスト

		} mpr_variable;	// プライベート変数を呼び出すための名前

		static C_Post_Effect_Draw_Manager m_this;	// ポストエフェクトの描画制御システムをシングルトン化するためのインスタンス


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ
		C_Post_Effect_Draw_Manager(void);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 終了時 -☆-//

		// デストラクタ
		~C_Post_Effect_Draw_Manager(void);


		//-☆- セッタ -☆-//

		// UIの前に描画するポストエフェクトを描画リストに追加する　引数：追加するポストエフェクト
		static void M_Set_Post_Effect_Before_UI(GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base * );

		// UIの後に描画するポストエフェクトを描画リストに追加する　引数：追加するポストエフェクト
		static void M_Set_Post_Effect_After_UI(GAME::INSTANCE::POST_EFFECT::BASE::C_Post_Effect_Base * );


		//-☆- 描画 -☆-//

		// UIの前のポストエフェクトを描画する
		static void M_Draw_Post_Effect_Before_UI(void);

		// UIの後のポストエフェクトを描画する
		static void M_Draw_Post_Effect_After_UI(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_POST_EFFECT_DRAW_MANAGER_H_FILE

