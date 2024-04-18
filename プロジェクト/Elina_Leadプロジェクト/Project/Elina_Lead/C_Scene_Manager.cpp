//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：シーンを制御するためのクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Scene_Manager.h"
#include "C_Scene_Title.h"
#include "C_Scene_Game.h"
#include "C_Game_State_Manager.h"
#include "C_Game_Instance_Manager.h"

#include "C_Log_System.h"


// ☆ ネームスペースの省略 ☆ //
using namespace GAME::SCENE::MANAGER;


// ☆ スタティック変数 ☆ //
C_Scene_Manager C_Scene_Manager::m_this;


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- 終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Scene_Manager::C_Scene_Manager(void)
{
	return;
}


//-☆- シーン遷移 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：シーン遷移時に必要なシステム
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Scene_Manager::M_Scene_Change_Option(void)
{
	if (m_this.mpr_variable.game_scene)
	{
		m_this.mpr_variable.game_scene->M_Release();
		GAME::INSTANCE::C_Game_Instance_Manager::M_Instance_Destroy_On_Scene_Change();
	}

	return;
}


//==☆ パブリック ☆==//

//-☆- 終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Scene_Manager::~C_Scene_Manager(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリの解放を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Scene_Manager::M_Release(void)
{
	if (m_this.mpr_variable.game_scene)
	{
		m_this.mpr_variable.game_scene->M_Release();
		m_this.mpr_variable.game_scene.reset();
	}

	return;
}


//-☆- ロード -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：名前からシーンをロードする
// 引数   ：string ロードするシーン名
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Scene_Manager::M_Scene_Load(std::string in_load_scene)
{
	// タイトルシーン
	if (in_load_scene == "TITLE")
	{
		M_Scene_Change_Option();
		GAME::STATE::C_Game_State_Manager::M_Set_Now_Game_Scene_Name(L"TITLE");
		m_this.mpr_variable.game_scene.reset(new C_Scene_Title());

		return true;
	}

	// ゲームシーン
	if (in_load_scene == "GAME")
	{
		M_Scene_Change_Option();
		GAME::STATE::C_Game_State_Manager::M_Set_Now_Game_Scene_Name(L"GAME");
		m_this.mpr_variable.game_scene.reset(new C_Scene_Game());

		return true;
	}

	
	// シーンがないならそのことを返す
	DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT_ERROR, "このシーンはありません：" + in_load_scene);
	DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();

	// シーンが見つからなかった
	return false;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：現在のシーンのアドレスを返す
// 引数   ：void
// 戻り値 ：C_Scene_Base * 現在のシーンのアドレス
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
GAME::SCENE::BASE::C_Scene_Base * C_Scene_Manager::M_Get_Scene(void)
{
	return m_this.mpr_variable.game_scene.get();
}
