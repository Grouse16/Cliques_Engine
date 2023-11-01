//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：エンジン用のウィンドウプロシージャのクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_WND_PROC_FOR_ENGINE_APK
#define D_INCLUDE_GUARD_C_WND_PROC_FOR_ENGINE_APK


// ☆ OS検知 ☆ //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS


// ☆ ファイルひらき ☆ //
#include <Windows.h>


// ☆ ネームスペース ☆ //

// ウィンドウズ用のシステムを呼び出すための名前
namespace OS::WINDOWS::PROC
{
	// ☆ クラス ☆ //

	// ウィンドウプロシージャを制御するためのシステム
	class C_Wnd_Proc_For_Engine_APK
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //
		static C_Wnd_Proc_For_Engine_APK m_this;	// 自身のインスタンス(シングルトン化に使用)


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ
		C_Wnd_Proc_For_Engine_APK(void);

	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- ウィンドウズ -☆-//

		// ウィンドウプロシージャ
		static LRESULT CALLBACK Wnd_Proc(HWND, UINT, WPARAM, LPARAM);
	};
}


#endif // OS_IS_WINDOWS
#endif // !D_INCLUDE_GUARD_C_WND_PROC_FOR_ENGINE_APK



//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆

