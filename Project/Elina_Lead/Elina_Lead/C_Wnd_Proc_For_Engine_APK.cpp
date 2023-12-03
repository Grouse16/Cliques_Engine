//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ゲーム用のウィンドウプロシージャのクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ OS検知 ☆ //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS


// ☆ ファイルひらき ☆ //
#include "C_Wnd_Proc_For_Game_APK.h"
#include "C_Wnd_Proc_Manager.h"
#include "C_OS_System_Base.h"
#include "C_Game_Manager.h"

#include <windowsx.h>


// ☆ ネームスペースの省略 ☆ //
using namespace OS::WINDOWS::PROC;


// ☆ 変数宣言 ☆ //
C_Wnd_Proc_For_Game_APK C_Wnd_Proc_For_Game_APK::m_this;	// 自身をインスタンス化するための変数


// ☆ 関数 ☆ //

//==☆ プライベート ☆==//

//-☆- 初期化 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Wnd_Proc_For_Game_APK::C_Wnd_Proc_For_Game_APK(void)
{
	// ウィンドウプロシージャをセット
	OS::WINDOWS::PROC::C_Wnd_Proc_Manager::M_Set_Game_APK_Wnd_Proc(Wnd_Proc);

	return;
}


//==☆ パブリック ☆==//

//-☆- システム用 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ウィンドウの処理を行うプロシージャ
// 引数   ：HWND 自アプリのウィンドウ情報, UINT ユーザーの入力情報, WPARAM 中ホイール等の入力情報, LPARAM マウスなどの入力情報
// 戻り値 ：LRESULT 処理結果を返す
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
LRESULT CALLBACK C_Wnd_Proc_For_Game_APK::Wnd_Proc(HWND in_h_wnd, UINT in_msg, WPARAM in_w_param, LPARAM in_l_param)
{
	// ☆ 変数宣言 ☆ //
	LRESULT window_update_result = DefWindowProc(in_h_wnd, in_msg, in_w_param, in_l_param);	// ウィンドウの更新結果


	// 終了されてからこの処理を行わないように止める
	if (in_h_wnd == NULL || in_msg == WM_QUIT)
	{
		return 0;
	}


	// uMsg（この関数の第2引数）が、ユーザー操作のID情報
	switch (in_msg)
	{
		// ☆ 終了系統 ☆ //

		// いずれかのキーが押されたとき
	case WM_KEYDOWN:

		//  終了のボタン  //
		if (LOWORD(in_w_param) == VK_ESCAPE)
		{
			DestroyWindow(in_h_wnd);  // “WM_DESTROY”メッセージを送る
		}

		break;

		// ウィンドウ破棄のメッセージ
	case WM_DESTROY:
		PostQuitMessage(0);	// “WM_QUIT”メッセージを送る　→　アプリ終了

		break;

		// xボタン
	case WM_CLOSE:
		DestroyWindow(in_h_wnd);  // “WM_DESTROY”メッセージを送る

		break;

		// 左クリック
	case WM_LBUTTONDOWN:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Left_Click_State(OS::E_MOUSE_CLICK_STATE::e_CLICK);

		break;

		// 左クリック終了
	case WM_LBUTTONUP:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Left_Click_State(OS::E_MOUSE_CLICK_STATE::e_NON);

		break;

		// 左ダブルクリック
	case WM_LBUTTONDBLCLK:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Left_Click_State(OS::E_MOUSE_CLICK_STATE::e_DOUBLE_CLICK);

		break;

		// 右クリック
	case WM_RBUTTONDOWN:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Right_Click_State(OS::E_MOUSE_CLICK_STATE::e_CLICK);

		break;

		// 右クリック終了
	case WM_RBUTTONUP:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Right_Click_State(OS::E_MOUSE_CLICK_STATE::e_NON);

		break;

		// 右ダブルクリック
	case WM_RBUTTONDBLCLK:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Right_Click_State(OS::E_MOUSE_CLICK_STATE::e_DOUBLE_CLICK);

		break;

		// 中クリック
	case WM_MBUTTONDOWN:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Center_Click_State(OS::E_MOUSE_CLICK_STATE::e_CLICK);

		break;

		// 中クリック終了
	case WM_MBUTTONUP:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Center_Click_State(OS::E_MOUSE_CLICK_STATE::e_NON);

		break;

		// 中ダブルクリック
	case WM_MBUTTONDBLCLK:
		OS::C_OS_System_Base::M_Get_Instance()->M_Set_Center_Click_State(OS::E_MOUSE_CLICK_STATE::e_DOUBLE_CLICK);

		break;


		// ウィンドウのサイズ変更中
	case WM_SIZING:

		// ウィンドウサイズを更新してもう一度処理を実行
		OS::C_OS_System_Base::M_Get_Instance()->M_Window_Size_Update();
		GAME::C_Game_Manager::M_Executes_Process();

		break;


		// ウィンドウの移動中
	case WM_MOVE:

		// ウィンドウサイズを更新してもう一度処理を実行
		OS::C_OS_System_Base::M_Get_Instance()->M_Window_Size_Update();
		GAME::C_Game_Manager::M_Executes_Process();

		break;


		// ウィンドウのサイズ変更完了時
	case WM_SIZE:

		// ☆ サイズの変更内容によって分岐 ☆ //
		switch (in_w_param)
		{
			//  サイズ変更時  //
		case SIZE_RESTORED:

			// ウィンドウサイズを更新してもう一度処理を実行
			OS::C_OS_System_Base::M_Get_Instance()->M_Window_Size_Update();
			GAME::C_Game_Manager::M_Executes_Process();

			break;


			//  最大化された時  //
		case SIZE_MAXIMIZED:

			// ウィンドウサイズを更新してもう一度処理を実行
			OS::C_OS_System_Base::M_Get_Instance()->M_Window_Size_Update();
			GAME::C_Game_Manager::M_Executes_Process();

			break;

			//  その他のメッセージは反応しない  //
		default:
			break;
		}

		break;


		//  枠を触っているだけの時  //
	case WM_WINDOWPOSCHANGED:

		// ウィンドウサイズを更新してもう一度処理を実行
		OS::C_OS_System_Base::M_Get_Instance()->M_Window_Size_Update();
		GAME::C_Game_Manager::M_Executes_Process();

		break;

		// その他の時は何もしない
	default:
		break;
	}

	return window_update_result;
}


#endif // OS_IS_WINDOWS

