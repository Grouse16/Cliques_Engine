//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：プラットフォームで分岐する初期化と解放を制御するクラス
// 説明   ：OSと描画用レンダリングAPI（サードパーティ製）をOSごとに分岐する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_GRAPHICS_API_INISIALIZER_H_FILE
#define D_INCLUDE_GUARD_C_GRAPHICS_API_INISIALIZER_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>

#include "E_RENDERING_API_KIND.h"


// ☆ ネームスペース ☆ //

// プラットフォームで分岐する初期化と解放を制御するクラスを呼び出すための名前
namespace PLATFORM
{
	// ☆ クラス ☆ //
	
	// プラットフォームで分岐する初期化と解放を制御するクラス
	class C_OS_Manager_And_Rendering_API_Initialize_And_Release_System
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ	生成できなくする
		C_OS_Manager_And_Rendering_API_Initialize_And_Release_System(void);


		//-☆- 生成 -☆-//

		// OS制御システムの初期化を行う　戻り値：成功時のみtrue
		static bool M_Init_OS(void);

		// レンダリングAPIの初期化を行う　戻り値：bool 成功時のみtrue
		static bool M_Init_Rendering_API(void);


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 生成 -☆-//

		// OS制御システムの生成を行う　引数：使用するAPIの種類への参照　戻り値：bool 成功時のみtrue
		static bool M_Create_OS(E_RENDERING_API_KIND);

		// OS制御システムを初期化してレンダリングAPIを生成する　引数：使用するAPIの種類への参照　戻り値：成功時のみtrue
		static bool M_Init_OS_Management_System_And_Create_Rendering_API(void);


		//-☆- 終了時 -☆-//

		// OS制御システムとレンダリングAPIを解放する
		static void M_Release_OS_Management_System_And_Rendering_API(void);


		//-☆- 削除 -☆-//

		// コンソール画面を削除する
		static void M_Destruct_Console_Window(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_GRAPHICS_API_INISIALIZER_H_FILE


//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆

