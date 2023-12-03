//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリング用の情報を円滑に設定し、レンダリングするためのシステム
// 説明   ：レンダリング用情報の設定をカプセル化する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Rendering_Setting_System.h"
#include "C_Rendering_Graphics_API_Base.h"

#include "C_Create_Rendering_Graphics_Setting_Inform.h"


// ☆ ネームスペースの省略 ☆ //
using namespace RENDERING::CAPSULE;


// ☆ 関数 ☆ //

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Rendering_Setting_System::C_Rendering_Setting_System(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Rendering_Setting_System::~C_Rendering_Setting_System(void)
{
	M_Delete();

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：メモリの解放を行う
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_Setting_System::M_Delete(void)
{
	mpr_variable.rendering_setting_inform.reset();

	return;
}


//-☆- 生成 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：生成用の情報を元に生成する
// 引数   ：const RENDERING::GRAPHICS::CREATE::C_Create_Rendering_Graphics_Setting_Inform & in_create_inform レンダリング設定生成用情報(const)
// 戻り値 ：bool 成功時のみtrue
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
bool C_Rendering_Setting_System::M_Create_Pipeline_Setting(const RENDERING::GRAPHICS::CREATE::S_Create_Rendering_Graphics_Setting_Inform& in_create_inform)
{
	// 生成用の情報を設定して生成する
	return RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Create_Rendering_Graphics_Inform(mpr_variable.rendering_setting_inform, in_create_inform);
}


//-☆- 描画 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：レンダリングAPIにこのレンダリング設定を適用する
// 引数   ：void
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Rendering_Setting_System::M_Set_Rendering_Setting_For_API(void)
{
	RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Rendering_Set_Rendering_Setting(mpr_variable.rendering_setting_inform);

	return;
}


