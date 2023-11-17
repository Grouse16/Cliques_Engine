//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アプリケーション制御用のクラス
// 説明   ：ゲーム画面のデバッグ時に実行されるシーン画面を制御するためのシステム
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_APK_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_APK_MANAGER_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>
#include <string>


// ☆ ネームスペース ☆ //

// アプリケーション用のシステムを呼び出すための名前
namespace GAME::APPLICATION
{
	// ☆ 定数 ☆ //
	const std::string con_INITIALIZED_SCENE_NAME = "TITLE";	// 初期のシーン名


	// ☆ クラス ☆ //

	// アプリケーション制御用のクラス、（ゲームタブの実行時）
	class C_APK_Manager
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// 変数をまとめた構造体
		struct SPr_Variable
		{
			bool flg_apk_active = false;	// アプリケーション（シーンの更新や描画）がアクティブかどうか trueでアクティブ
		};

		SPr_Variable mpr_variable;	// 変数を呼び出すための名前

		static std::unique_ptr<C_APK_Manager> m_this;	// アプリケーション制御用のシステムの実体(シングルトン)


		//-☆- 初期化 -☆-//

		// コンストラクタ　シングルトン化のために隠蔽
		C_APK_Manager(void);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 終了時 -☆-//

		// 初期化して使用可能にする　戻り値：成功時のみtrue
		static bool M_Init(void);

		// デストラクタ
		~C_APK_Manager(void);

		// メモリ解放
		static void M_Release(void);


		//-☆- 入力 -☆-//

		// アプリケーションの入力
		static void M_APK_Input(void);


		//-☆- 更新 -☆-//

		// アプリケーションの更新
		static void M_APK_Update(void);
		

		//-☆- 描画 -☆-//

		// アプリケーションの描画
		static void M_APK_Draw(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_APK_MANAGER_H_FILE


//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆
