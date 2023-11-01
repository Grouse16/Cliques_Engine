//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ウィンドウプロシージャを制御するためのシステム
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ OS検知 ☆ //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS


// ☆ ファイルひらき ☆ //
#include "C_Wnd_Proc_Manager.h"


// ☆ ネームスペースの省略 ☆ //
using namespace OS::WINDOWS::PROC;


// ☆ 変数宣言 ☆ //
WNDPROC C_Wnd_Proc_Manager::m_add_engine_apk_wnd_proc = nullptr;	// ウィンドウプロシージャのアドレスを持つ


// ☆ 関数 ☆ //

//==☆ パブリック ☆==//

//-☆- セッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：エンジン用のウィンドウプロシージャを設定する
// 引数   ：void
// 戻り値 ：WNDPROC ウィンドウプロシージャ関数のアドレス
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
void C_Wnd_Proc_Manager::M_Set_Engine_APK_Wnd_Proc(WNDPROC in_proc)
{
	m_add_engine_apk_wnd_proc = in_proc;

	return;
}


//-☆- ゲッタ -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：エンジン用のウィンドウプロシージャを返す
// 引数   ：void
// 戻り値 ：WNDPROC ウィンドウプロシージャ関数のアドレス
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
WNDPROC C_Wnd_Proc_Manager::M_Get_Engine_APK_Wnd_Proc(void)
{
	return m_add_engine_apk_wnd_proc;
}


#endif // OS_IS_WINDOWS
