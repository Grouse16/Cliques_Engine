//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：エンジン用のレンダリング設定を管理するマネージャー
// 説明   ：エンジンに使用するレンダリングパイプライン設定の初期化と使用を制御する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Engine_Rendering_Setting_Manager.h"


// ☆ ネームスペースの省略 ☆ //
using namespace GAME::DRAW;


// ☆ 変数宣言 ☆ //
C_Engine_Rendering_Setting_Manager::SPr_Variable C_Engine_Rendering_Setting_Manager::mpr_variable;	// プライベート変数を呼び出すための名前

C_Engine_Rendering_Setting_Manager C_Engine_Rendering_Setting_Manager::m_this;	// このクラスをインスタンス化するための変数


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- 初期化 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ、シングルトン化のために隠蔽
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Engine_Rendering_Setting_Manager::C_Engine_Rendering_Setting_Manager(void)
{
	return;
}


//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：初期化を行う
// 引数   ：void
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Engine_Rendering_Setting_Manager::M_Init(void)
{
	// 全ての描画用設定を初期化する　// 失敗したらエラーを出して抜ける
	for (int loop_x = 0; loop_x < (int)E_RENDERING_SETTING_NUM::e_OBJECT; loop_x++)
	{
		if (mpr_variable.rendering_setting_system_list[loop_x].M_Creat_Pipeline_Setting(loop_x) == false)
		{
			return false;
		}
	}

	// 成功
	return true;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Engine_Rendering_Setting_Manager::~C_Engine_Rendering_Setting_Manager(void)
{
	M_Release();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリの解放を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Rendering_Setting_Manager::M_Release(void)
{
	for (int loop_x = 0; loop_x < (int)E_RENDERING_SETTING_NUM::e_SUM; loop_x++)
	{
		mpr_variable.rendering_setting_system_list[loop_x].M_Delete();
	}

	return;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：指定されたレンダリング設定を描画に適用する
// 引数   ：E_RENDERING_SETTING_NUM レンダリング設定の番号
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Engine_Rendering_Setting_Manager::M_Attach_This_Rendering_Setting(E_RENDERING_SETTING_NUM in_rendering_setting_num)
{
	mpr_variable.rendering_setting_system_list[(int)in_rendering_setting_num].M_Set_Rendering_Setting_For_API();

	return;
}
