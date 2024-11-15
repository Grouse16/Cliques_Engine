//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ウィンドウプロシージャを制御するためのシステム
// 説明   ：循環参照を避けるために使用する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_WND_PROC_SYSTEM
#define D_INCLUDE_GUARD_C_WND_PROC_SYSTEM


// ☆ OS検知 ☆ //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS


// ☆ ファイルひらき ☆ //
#include <Windows.h>


// ☆ ネームスペース ☆ //

// ウィンドウズ系統を呼び出すための名前
namespace OS::WINDOWS::PROC
{
	// ☆ クラス ☆ //

	// ウィンドウプロシージャ制御用システム
	class C_Wnd_Proc_Manager
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //
		static WNDPROC m_add_Game_apk_wnd_proc;	// ゲームアプリケーション用のウィンドウプロシージャのアドレス


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- セッタ -☆-//

		// ゲーム用のウィンドウプロシージャを返す
		static void M_Set_Game_APK_Wnd_Proc(WNDPROC);


		//-☆- ゲッタ -☆-//

		// ゲーム用のウィンドウプロシージャを返す
		static WNDPROC M_Get_Game_APK_Wnd_Proc(void);
	};
}


#endif // OS_IS_WINDOWS
#endif // !D_INCLUDE_GUARD_C_WND_PROC_SYSTEM



//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆
