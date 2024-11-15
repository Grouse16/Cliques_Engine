//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：プラットフォーム検出用システム
// 説明   ：プラットフォームが何かを示す、マクロで分岐させるべきではない場所のために使用する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_PLATFORM_DETECTION_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_PLATFORM_DETECTION_SYSTEM_H_FILE


// ☆ ファイルひらき ☆ //
#include "E_OS_KIND.h"
#include "E_RENDERING_API_KIND.h"


// ☆ ネームスペース ☆ //

// プラットフォーム検出用システムを呼び出すための名前
namespace PLATFORM::DETECTION
{
	// ☆ クラス ☆ //

	// プラットフォーム検出用システム
	class C_Platform_Detection_System
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //
		static C_Platform_Detection_System m_this_instance;	// コンストラクタ起動用用のインスタンス

		E_OS_KIND m_platform_num = E_OS_KIND::e_UNKNOWN;	// OSの種類を指定する番号

		E_RENDERING_API_KIND m_rendering_api_num = E_RENDERING_API_KIND::e_UNKNOWN;	// レンダリングAPIの種類を指定する番号

		
		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ
		C_Platform_Detection_System(void);


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- ゲッタ -☆-//

		// プラットフォーム識別用番号を渡す
		static const E_OS_KIND & M_Get_Platform_Number(void);

		// 現在のレンダリングAPI番号を渡す
		static const E_RENDERING_API_KIND & M_Get_Rendering_API_Number(void);


		//-☆- セッタ -☆-//

		// レンダリングAPIを指定する番号を設定する　引数：設定するレンダリングAPI番号
		static void M_Set_Rendering_API_Number(E_RENDERING_API_KIND);
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

