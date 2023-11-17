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


// ☆ ネームスペース ☆ //

// プラットフォームで分岐する初期化と解放を制御するクラスを呼び出すための名前
namespace PLATFORM
{
	// ☆ 定数 ☆ //

	// レンダリング用APIの種類を指定する列挙
	enum class E_RENDERING_API_KIND
	{
		e_DX11,		// ダイレクトエックス１１
		e_DX12,		// ダイレクトエックス１２
		e_OPENGL,	// オープンGL
		e_VULKAN,	// バルカン
	};


	// ☆ クラス ☆ //
	
	// プラットフォームで分岐する初期化と解放を制御するクラス
	class C_API_Initialize_And_Release_Manager
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ	生成できなくする
		C_API_Initialize_And_Release_Manager(void);


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// OSの初期化を行う　※先に生成すること　戻り値：成功時のみtrue
		static bool M_Init_OS(void);

		// OSの生成を行う　引数：使用するAPIの種類　戻り値：成功時のみtrue
		static bool M_Create_OS(E_RENDERING_API_KIND);

		// APIの初期化を行う　引数：void　戻り値：成功時のみtrue
		static bool M_Init_API(void);

		// ウィンドウズOSのときのみ必要なコマンド番号を指定する、これがないとウィンドウを生成できない　引数：コマンド番号
		static void M_Set_CMD_Number(int);


		//-☆- 終了時 -☆-//

		// デストラクタ
		~C_API_Initialize_And_Release_Manager(void);

		// APIを解放する
		static void M_Relese_Graphics_API(void);
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

