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
#include "C_Post_Effect_List.h"
#include "C_Sound_List.h"
#include "C_Game_System_List.h"


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
		static void M_All_Instance_Destroy_Update(void);

		// インスタンスのシーン遷移時の削除を行う
		static void M_Instance_Destroy_On_Scene_Change(void);

		// 全てのインスタンスを削除する
		static void M_Delete_All_Instance(void);


		//-☆- 更新 -☆-//

		// 全てのアクターの更新をする
		static void M_Update_Actor(void);

		// 全てのUIの更新をする
		static void M_Update_UI(void);

		// 全てのポストエフェクトの更新をする
		static void M_Update_Post_Effect(void);

		// 全てのサウンドの更新をする
		static void M_Update_Sound(void);

		// 全てのゲームシステムの更新をする
		static void M_Update_Game_System(void);


		//-☆- 描画 -☆-//

		// 全てのアクターの描画をする
		static void M_Draw_Actor(void);

		// ポストエフェクトを描画用リストに追加する
		static void M_Set_Post_Effect_To_Draw_List(void);

		// UIの前にポストエフェクトをかける描画をする
		static void M_Draw_Post_Effect_Before_UI(void);

		// 全てのUIを描画する
		static void M_Draw_UI(void);

		// UIの後にポストエフェクトをかける描画をする
		static void M_Draw_Post_Effect_After_UI(void);


		//-☆- 生成 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された種類のアクターを生成する
		// 引数   ：string 設定するアクター名
		// 戻り値 ：C_Actor * 生成されたアクターのアドレス
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		template<ACTOR::LIST::CONCEPT::C_Checked_Actor_Class C_Actor>
		static C_Actor * M_Create_Actor(std::string in_actor_name)
		{
			return ACTOR::LIST::C_Actor_List<C_Actor>::M_Create_Actor(in_actor_name);
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された種類のUIを生成する
		// 引数   ：string 設定するUI名
		// 戻り値 ：C_UI * 生成されたUIのアドレス
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		template<UI::LIST::CONCEPT::C_Checked_UI_Class C_UI>
		static C_UI * M_Create_UI_List(std::string in_ui_name)
		{
			return UI::LIST::C_User_Interface_List<C_UI>::M_Create_UI(in_ui_name);
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された種類のポストエフェクトを生成する
		// 引数   ：string 設定するポストエフェクト名
		// 戻り値 ：C_Post_Effect * 生成されたポストエフェクトのアドレス
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		template<POST_EFFECT::LIST::CONCEPT::C_Checked_Post_Effect_Class C_Post_Effect>
		static C_Post_Effect * M_Create_Post_Effect_List(std::string in_post_effect_name)
		{
			return POST_EFFECT::LIST::C_Post_Effect_List<C_Post_Effect>::M_Create_Post_Effect(in_post_effect_name);
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された種類のサウンドを生成する
		// 引数   ：string 設定するサウンド名
		// 戻り値 ：C_Sound * 生成されたサウンドのアドレス
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		template<SOUND::LIST::CONCEPT::C_Checked_Sound_Class C_Sound>
		static C_Sound * M_Create_Sound_List(std::string in_sound_name)
		{
			return SOUND::LIST::C_Sound_List<C_Sound>::M_Create_Sound(in_sound_name);
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された種類のゲームシステムを生成する
		// 引数   ：string 設定するゲームシステム名
		// 戻り値 ：C_Game_System * 生成されたゲームシステムのアドレス
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		template<GAME_SYSTEM::LIST::CONCEPT::C_Checked_System_Class C_Game_System>
		static C_Game_System * M_Get_Game_System_List(std::string in_game_system_name)
		{
			return GAME_SYSTEM::LIST::C_Game_System_List<C_Game_System>::M_Create_System(in_game_system_name);
		}


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
		// 詳細   ：指定された種類のポストエフェクトのリストを取得する
		// 引数   ：void
		// 戻り値 ：vector<unique_ptr<C_Post_Effect>> & 指定されたポストエフェクトのリストの参照
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		template<POST_EFFECT::LIST::CONCEPT::C_Checked_Post_Effect_Class C_Post_Effect>
		static std::vector<std::unique_ptr<C_Post_Effect>>& M_Get_Post_Effect_List(void)
		{
			return POST_EFFECT::LIST::C_Post_Effect_List<C_Post_Effect>::M_Get_Post_Effect_List();
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された種類のサウンドのリストを取得する
		// 引数   ：void
		// 戻り値 ：vector<unique_ptr<C_Sound>> & 指定されたサウンドのリストの参照
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		template<SOUND::LIST::CONCEPT::C_Checked_Sound_Class C_Sound>
		static std::vector<std::unique_ptr<C_Sound>> & M_Get_Sound_List(void)
		{
			return SOUND::LIST::C_Sound_List<C_Sound>::M_Get_Sound_List();
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された種類のゲームシステムのリストを取得する
		// 引数   ：void
		// 戻り値 ：vector<unique_ptr<C_Game_System>> & 指定されたゲームシステムのリストの参照
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		template<GAME_SYSTEM::LIST::CONCEPT::C_Checked_System_Class C_Game_System>
		static std::vector<std::unique_ptr<C_Game_System>> & M_Get_Game_System_List(void)
		{
			return GAME_SYSTEM::LIST::C_Game_System_List<C_Game_System>::M_Get_System_List();
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された種類で、指定された名前のアクター取得する
		// 引数   ：string 取得するアクター名
		// 戻り値 ：C_Actor * 指定されたアクターのアドレス
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		template<ACTOR::LIST::CONCEPT::C_Checked_Actor_Class C_Actor>
		static C_Actor * M_Get_Actor_By_Name(std::string in_actor_name)
		{
			return ACTOR::LIST::C_Actor_List<C_Actor>::M_Get_Actor_By_Name(in_actor_name);
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された種類で、指定された名前のUIのリストを取得する
		// 引数   ：string 取得するUI名
		// 戻り値 ：C_UI * 指定されたUIのアドレス
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		template<UI::LIST::CONCEPT::C_Checked_UI_Class C_UI>
		static C_UI * M_Get_UI_By_Name(std::string in_ui_name)
		{
			return UI::LIST::C_User_Interface_List<C_UI>::M_Get_UI_By_Name(in_ui_name);
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された種類で、指定された名前のポストエフェクトのリストを取得する
		// 引数   ：string 取得するポストエフェクト名
		// 戻り値 ：C_Post_Effect * 指定されたポストエフェクトのアドレス
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		template<POST_EFFECT::LIST::CONCEPT::C_Checked_Post_Effect_Class C_Post_Effect>
		static C_Post_Effect * M_Get_Post_Effect_By_Name(std::string in_post_effect_name)
		{
			return POST_EFFECT::LIST::C_Post_Effect_List<C_Post_Effect>::M_Get_Post_Effect_By_Name(in_post_effect_name);
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された種類で、指定された名前のサウンドのリストを取得する
		// 引数   ：string 取得するサウンド名
		// 戻り値 ：C_Sound * 指定されたサウンドのアドレス
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		template<SOUND::LIST::CONCEPT::C_Checked_Sound_Class C_Sound>
		static C_Sound * M_Get_Sound_By_Name(std::string in_sound_name)
		{
			return SOUND::LIST::C_Sound_List<C_Sound>::M_Get_Sound_By_Name(in_sound_name);
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された種類で、指定された名前のゲームシステムのリストを取得する
		// 引数   ：stirng 取得するゲームシステム名
		// 戻り値 ：C_Game_System * 指定されたゲームシステムのアドレス
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		template<GAME_SYSTEM::LIST::CONCEPT::C_Checked_System_Class C_Game_System>
		static C_Game_System * M_Get_Game_System_By_Name(std::string in_game_system_name)
		{
			return GAME_SYSTEM::LIST::C_Game_System_List<C_Game_System>::M_Get_System_By_Name(in_game_system_name);
		}
	};
}


#endif // !D_INCLUDE_GUARD_C_GAME_INSTANCE_MANAGER_H_FILE
