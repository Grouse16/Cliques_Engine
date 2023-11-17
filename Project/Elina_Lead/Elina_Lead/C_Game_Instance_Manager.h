//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ゲーム上のインスタンスを制御するクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_GAME_INSTANCE_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_GAME_INSTANCE_MANAGER_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>
#include <string>
#include <memory>

#include "C_Actor_List.h"
#include "C_User_Interface_List.h"
#include "C_Sound_List.h"
#include "C_Post_Effect_List.h"


// ☆ ネームスペース ☆ //

// ゲームのオブジェクト系統のリストを呼び出すための名前
namespace GAME::INSTANCE
{
	// ☆ クラス ☆ //

	// ゲーム上のインスタンスを制御するクラス
	class C_Game_Instance_Manager
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Game_Instance_Manager(void);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 削除 -☆-//

		// ゲーム上の全てのインスタンスのなかから、削除のフラグが立っているものを消す
		void M_All_Instance_Destroy_Update(void);

		// 全てのインスタンスを削除する
		void M_Delete_All_Instance(void);


		//-☆- 更新 -☆-//


		//-☆- ゲッタ -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された種類のアクターのリストを取得する
		// 引数   ：void
		// 戻り値 ：vector<unique_ptr<C_Actor>> & 指定されたアクターのリストの参照
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		template<ACTOR::LIST::CONCEPT::C_Checked_Actor_Class C_Actor>
		static std::vector<std::unique_ptr<C_Actor>> & M_Get_Actor_List(void)
		{
			return ACTOR::LIST::C_Actor_List<C_Actor>::M_Get_Actor_List();
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された種類のUIのリストを取得する
		// 引数   ：void
		// 戻り値 ：vector<unique_ptr<C_UI>> & 指定されたUIのリストの参照
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		template<UI::LIST::CONCEPT::C_Checked_UI_Class C_UI>
		static std::vector<std::unique_ptr<C_UI>> & M_Get_UI_List(void)
		{
			return UI::LIST::C_User_Interface_List<C_UI>::M_Get_UI_List();
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された種類のサウンドのリストを取得する
		// 引数   ：void
		// 戻り値 ：vector<unique_ptr<C_Sound>> & 指定されたサウンドのリストの参照
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		template<SOUND::LIST::C_Checked_Sound_Class C_Sound>
		static std::vector<std::unique_ptr<C_Sound>> & M_Get_Sound_List(void)
		{
			return SOUND::LIST::C_Sound_List<C_Sound>::M_Get_Sound_List();
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された種類のポストエフェクトのリストを取得する
		// 引数   ：void
		// 戻り値 ：vector<unique_ptr<UI>> & 指定されたポストエフェクトのリストの参照
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		template<SOUND::LIST::C_Checked_Sound_Class C_Sound>
		static std::vector<std::unique_ptr<C_Sound>> & M_Get_Post_Effect_List(void)
		{
			return POST_EFFECT::LIST::C_Post_Effect_List<C_Sound>::M_Get_Post_Effect_List();
		}
	};
}


#endif // !D_INCLUDE_GUARD_C_GAME_INSTANCE_MANAGER_H_FILE
