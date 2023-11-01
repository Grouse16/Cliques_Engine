//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：プラットフォーム検出用システム
// 説明   ：プラットフォームが何かを示す、マクロで分岐させるべきではない場所のために使用する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_PLATFORM_DETECTION_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_PLATFORM_DETECTION_SYSTEM_H_FILE


// ☆ ネームスペース ☆ //

// プラットフォーム検出用システムを呼び出すための名前
namespace PLATFORM::DETECTION
{
	// ☆ 定数 ☆ //

	// プラットフォームを指定する列挙
	enum class E_PLATFORM_NUMBER
	{
		e_WINDOWS,	// ウィンドウズ
		e_MAC,		// マック
		e_LINUX,	// リナックス
		e_UNIX,		// ユニックス
		e_UNKNOWN,	// 識別不可
	};

	// レンダリングAPIを指定する列挙
	enum class E_RENDERING_API_NUMBER
	{
		e_DX12,		// ダイレクトエックス12
		e_DX11,		// ダイレクトエックス11
		e_OPENGL,	// オープンGL
		e_VULKAN,	// バルカン
		e_UNKNOWN,	// 識別不可
	};


	// ☆ クラス ☆ //

	// プラットフォーム検出用システム
	class C_Platform_Detection_System
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //
		static C_Platform_Detection_System m_this_instance;	// コンストラクタ起動用用のインスタンス

		E_PLATFORM_NUMBER m_platform_num = E_PLATFORM_NUMBER::e_UNKNOWN;	// プラットフォーム識別用番号

		E_RENDERING_API_NUMBER m_rendering_api_num = E_RENDERING_API_NUMBER::e_UNKNOWN;	// プラットフォーム識別用番号

		
		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ
		C_Platform_Detection_System(void);


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- ゲッタ -☆-//

		// プラットフォーム識別用番号を渡す
		static const E_PLATFORM_NUMBER & M_Get_Platform_Number(void);

		// 現在のレンダリングAPI番号を渡す
		static const E_RENDERING_API_NUMBER & M_Get_Rendering_API_Number(void);


		//-☆- セッタ -☆-//

		// レンダリングAPIを指定する番号を設定する　引数：設定するレンダリングAPI番号
		static void M_Set_Rendering_API_Number(E_RENDERING_API_NUMBER);
	};
}


#endif // !D_INCLUDE_GUARD_C_PLATFORM_DETECTION_SYSTEM_H_FILE


//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆

