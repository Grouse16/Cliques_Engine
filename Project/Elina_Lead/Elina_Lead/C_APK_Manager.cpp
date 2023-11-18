//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アプリケーション制御用のクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_APK_Manager.h"
#include "C_Scene_Manager.h"
#include "C_Game_Instance_Manager.h"


// ☆ ネームスペースの省略 ☆ //
using namespace GAME::APPLICATION;


// ☆ 変数宣言 ☆ //
std::unique_ptr<C_APK_Manager> C_APK_Manager::m_this;	// 自クラスへのアクセス用の変数


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- 初期化 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_APK_Manager::C_APK_Manager(void)
{
	return;
}


//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ： 初期化して使用可能にする
// 引数   ：void
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_APK_Manager::M_Init(void)
{
	m_this.reset(new C_APK_Manager);

	// 初期シーンをロード　失敗でfalseが返る
	return GAME::SCENE::MANAGER::C_Scene_Manager::M_Scene_Load(con_INITIALIZED_SCENE_NAME);
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_APK_Manager::~C_APK_Manager(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリ解放
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_APK_Manager::M_Release(void)
{
	m_this.reset();
	GAME::SCENE::MANAGER::C_Scene_Manager::M_Release();

	return;
}


//-☆- 入力 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アプリケーションの入力を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_APK_Manager::M_APK_Input(void)
{
	// アプリケーションがアクティブでなければスルー
	if (m_this == nullptr)
	{
		return;
	}


	//--☆ 入力 ☆--//



	return;
}


//-☆- 更新 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アプリケーションの更新を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_APK_Manager::M_APK_Update(void)
{
	// アプリケーションがアクティブでなければスルー
	if (m_this == nullptr)
	{
		return;
	}


	//--☆ 更新 ☆--//

	// シーンによるゲーム更新前の更新を行う
	GAME::SCENE::MANAGER::C_Scene_Manager::M_Get_Scene()->M_Scene_Before_Update();

	// アクターの更新を行う
	GAME::INSTANCE::C_Game_Instance_Manager::M_Update_Actor();

	// UIの更新を行う
	GAME::INSTANCE::C_Game_Instance_Manager::M_Update_UI();

	// ポストエフェクトの更新を行う
	GAME::INSTANCE::C_Game_Instance_Manager::M_Update_Post_Effect();

	// サウンドの更新を行う
	GAME::INSTANCE::C_Game_Instance_Manager::M_Update_Sound();

	// シーンによるゲーム更新後の更新を行う
	GAME::SCENE::MANAGER::C_Scene_Manager::M_Get_Scene()->M_Scene_After_Update();

	return;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アプリケーションの描画を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_APK_Manager::M_APK_Draw(void)
{
	// アプリケーションがアクティブでなければスルー
	if (m_this == nullptr)
	{
		return;
	}


	//--☆ 描画 ☆--//

	// アクターの描画を行う
	GAME::INSTANCE::C_Game_Instance_Manager::M_Draw_Actor();

	// ポストエフェクト描画リストを更新
	GAME::INSTANCE::C_Game_Instance_Manager::M_Set_Post_Effect_To_Draw_List();

	// ポストエフェクトのUI描画前の描画を行う
	GAME::INSTANCE::C_Game_Instance_Manager::M_Draw_Post_Effect_Before_UI();

	// UIの描画を行う
	GAME::INSTANCE::C_Game_Instance_Manager::M_Draw_UI();

	// ポストエフェクトのUI描画後の描画を行う
	GAME::INSTANCE::C_Game_Instance_Manager::M_Draw_Post_Effect_After_UI();

	// シーンによる描画後の更新を行う
	GAME::SCENE::MANAGER::C_Scene_Manager::M_Get_Scene()->M_Scene_Update_After_Draw();

	return;
}
