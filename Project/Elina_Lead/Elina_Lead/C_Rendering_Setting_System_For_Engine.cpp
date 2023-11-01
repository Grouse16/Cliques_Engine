//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリング用の情報を円滑に設定し、レンダリングするためのシステム
// 説明   ：レンダリング用情報の設定をカプセル化する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Rendering_Setting_System_For_Engine.h"
#include "C_Rendering_Graphics_API_Base.h"

#include "C_Creat_Rendering_Graphics_Setting_Inform.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::CAPSULE;


// ☆ 関数 ☆ //

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Rendering_Setting_System_For_Engine::C_Rendering_Setting_System_For_Engine(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Rendering_Setting_System_For_Engine::~C_Rendering_Setting_System_For_Engine(void)
{
	M_Delete();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリの解放を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_Setting_System_For_Engine::M_Delete(void)
{
	mpr_variable.rendering_setting_inform.reset();

	return;
}


//-☆- 生成 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：生成用の情報を元に生成する
// 引数   ：int 使用するシェーダーセットの番号
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Rendering_Setting_System_For_Engine::M_Creat_Pipeline_Setting(int in_shader_set)
{
	// ☆ 変数宣言 ☆ //
	RENDERING::GRAPHICS::CREAT::C_Creat_Rendering_Graphics_Setting_Inform creat_inform;	// 生成用情報


	// 生成用の情報を設定して生成する
	if (RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Creat_Rendering_Graphics_Inform(mpr_variable.rendering_setting_inform, creat_inform) == false)
	{
		return false;	// 失敗したらエラーで抜ける
	}

	return true;
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリングAPIにこのレンダリング設定を適用する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_Setting_System_For_Engine::M_Set_Rendering_Setting_For_API(void)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Rendering_Set_Rendering_Setting(mpr_variable.rendering_setting_inform);

	return;
}


