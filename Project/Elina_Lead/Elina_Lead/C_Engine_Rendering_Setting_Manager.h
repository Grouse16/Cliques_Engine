//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：エンジン用のレンダリング設定を管理するマネージャー
// 説明   ：エンジンに使用するレンダリングパイプライン設定の初期化と使用を制御する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_ENGINE_RENDERING_SETTING_MANAGER
#define D_INCLUDE_GUARD_C_ENGINE_RENDERING_SETTING_MANAGER


// ☆ ファイルひらき ☆ //
#include "C_Rendering_Setting_System_For_Engine.h"


// ☆ ネームスペース ☆ //

// エンジン用の描画用システムを呼び出すための名前
namespace GAME::DRAW
{
	// ☆ 列挙 ☆ //

	// 使用するレンダリング設定の番号を指定する
	enum class E_RENDERING_SETTING_NUM
	{
		e_UI,		// UI用のレンダリング設定
		e_OBJECT,	// オブジェクト用のレンダリング設定

		e_SUM,	// レンダリング設定数
	};


	// ☆ クラス ☆ //

	// エンジン用のレンダリング設定を管理するマネージャーのクラス
	class C_Engine_Rendering_Setting_Manager
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //
		
		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			RENDERING::CAPSULE::C_Rendering_Setting_System_For_Engine rendering_setting_system_list[(int)E_RENDERING_SETTING_NUM::e_SUM];	// レンダリング設定システムのリスト
		};

		static SPr_Variable mpr_variable;	// プライベート変数を呼び出すための名前

		static C_Engine_Rendering_Setting_Manager m_this;	// このクラスをインスタンス化するための変数


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ、シングルトン化のために隠蔽
		C_Engine_Rendering_Setting_Manager(void);


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// 初期化を行う　戻り値：成功時の場合は、true
		static bool M_Init(void);

		// デストラクタ
		~C_Engine_Rendering_Setting_Manager(void);

		// メモリの解放
		static void M_Release(void);


		//-☆- 描画 -☆-//

		// 指定されたレンダリング設定を描画に適用する　引数：レンダリング設定の番号
		static void M_Attach_This_Rendering_Setting(E_RENDERING_SETTING_NUM);
	};
}


#endif // !D_INCLUDE_GUARD_C_ENGINE_RENDERING_SETTING_MANAGER

