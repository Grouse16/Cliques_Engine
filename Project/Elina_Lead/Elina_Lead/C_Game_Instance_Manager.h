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


		//-☆- ゲッタ -☆-//
		
		// 指定された種類のアクターのリストを取得する
		template<class C_Actor>
		void M_Get_Actor_List(void);

		// 指定された種類のUIをリストの取得する
		template<class C_UI>
		void M_Get_User_Interface_List(void);

		// 指定された種類のサウンドのリストを取得する
		template<class C_Sound>
		void M_Get_Sound_List(void);

		// 指定された種類のポストエフェクトのリストを取得する
		template<class C_Post_Effect>
		void M_Get_Post_Effect_List(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_GAME_INSTANCE_MANAGER_H_FILE
