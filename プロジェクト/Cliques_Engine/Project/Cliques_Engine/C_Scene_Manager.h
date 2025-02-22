//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：シーンを制御するためのクラス
// 説明   ：シーンのロードと解放など、管理を行う
// 作成者 ：��坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード -☆-//
#ifndef D_INCLUDE_GUARD_C_SCENE_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_SCENE_MANAGER_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>
#include <string>

#include "C_Scene_Base.h"


// ☆ ネームスペース ☆ //

// シーンを制御するシステムを呼び出すための名前
namespace GAME::SCENE::MANAGER
{
	// ☆ クラス ☆ //

	// シーンを制御するためのクラス
	class C_Scene_Manager
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 構造体 ☆ //

		// シーン遷移の命令を記録するための情報の構造体
		struct S_Scene_Change_Inform
		{
			std::string scene_name = "default";	// 遷移先のシーン名

			bool flg_scene_change = false;	// シーン遷移を実行するかどうかのフラグ、trueでシーン遷移実行
		};



		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::unique_ptr<GAME::SCENE::BASE::C_Scene_Base> game_scene = nullptr;	// シーンシステム

		} mpr_variable;	// プライベート変数を呼び出すための名前

		static C_Scene_Manager m_this;	// 制御システムの実体（シングルトン化）


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ
		C_Scene_Manager(void);


		//-☆- シーン遷移 -☆-//

		// シーン遷移時に必要なシステム
		static void M_Scene_Change_Option(void);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 終了時 -☆-//

		// デストラクタ
		~C_Scene_Manager(void);

		// メモリの解放を行う
		static void M_Release(void);


		//-☆- ロード -☆-//
		
		// 名前からシーンをロードする　引数：ロードするシーン名
		static bool M_Scene_Load(std::string);

		// 現在のシーンのアドレスを返す　戻り値：現在のシーンのアドレス
		static GAME::SCENE::BASE::C_Scene_Base * M_Get_Scene(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_SCENE_MANAGER_H_FILE

