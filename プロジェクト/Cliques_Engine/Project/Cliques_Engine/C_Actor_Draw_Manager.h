//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アクターの描画制御をするクラス
// 説明   ：アクターを描画するかどうかのフラグや、距離やカメラとの位置関係からのカリングなどを行って描画するオブジェクトをまとめて持つ
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_ACTOR_DRAW_MANAGER
#define D_INCLUDE_GUARD_C_ACTOR_DRAW_MANAGER


// ☆ ファイルひらき ☆ //
#include "C_Actor_Base.h"

#include <vector>


// ☆ ネームスペース ☆ //

// アクターの描画制御用システムを呼び出すための名前
namespace GAME::INSTANCE::ACTOR::DRAW_MANAGER
{
	// ☆ クラス ☆ //

	// アクターの描画制御をするクラス
	class C_Actor_Draw_Manager
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数 ☆ //
		
		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::vector<GAME::INSTANCE::ACTOR::BASE::C_Actor_Base * > draw_actor_list;			// 描画するアクターのリスト
			std::vector<GAME::INSTANCE::ACTOR::BASE::C_Actor_Base * > after_draw_actor_list;	// アクターの通常描画後に描画するアクターのリスト

		} mpr_variable;	// プライベート変数を呼び出すための名前

		static C_Actor_Draw_Manager m_this;	// 制御するシステムをシングルトン化するためのインスタンス

		
		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ
		C_Actor_Draw_Manager(void);


		//-☆- 描画 -☆-//

		// カリングの処理を実行する　引数：カリングの判定を行うアクターのアドレス　戻り値：描画する時のみtrue
		static bool M_Culling_Calculation(GAME::INSTANCE::ACTOR::BASE::C_Actor_Base * );


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 終了時 -☆-//

		// デストラクタ
		~C_Actor_Draw_Manager(void);


		//-☆- セッタ -☆-//

		// 描画リストにアクターを追加する　引数：追加するアクターのアドレス
		static void M_Set_Actor_To_Draw_List(GAME::INSTANCE::ACTOR::BASE::C_Actor_Base * );

		// 通常描画後の描画リストにアクターを追加する　引数：追加するアクターのアドレス
		static void M_Set_Actor_To_After_Draw_List(GAME::INSTANCE::ACTOR::BASE::C_Actor_Base * );


		//-☆- 描画 -☆-//

		// 描画リスト内のアクターを描画する
		static void M_Draw_Actor_In_Draw_List(void);

		// 通常描画後の描画リスト内のアクターを描画する
		static void M_Draw_Actor_In_After_Draw_List(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_ACTOR_DRAW_MANAGER
