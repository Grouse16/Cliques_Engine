//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ゲームの機能の基底インスタンスの定義
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_Game_FUNCTION_BASE_H_FILE
#define D_INCLUDE_GUARD_Game_FUNCTION_BASE_H_FILE


// ☆ ファイルひらき ☆ //
#include "Game_Function_Priority_Setting.h"



// ☆ ネームスペース ☆ //

// 機能の基底クラスを呼び出すための名前
namespace GAME::FUNCTION
{
	// ☆ クラス ☆ //

	// ゲームのイベント用の基底クラスを定義
	class C_Game_Function_Base
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プロテクトの変数をまとめた構造体
		struct SPr_Variable
		{
			float update_period_time = 0.0f;	// イベント実行の周期

			int after_draw_priority = (int)GAME::FUNCTION::PRIOTRITY::E_AFTER_GAME_DRAW_PRIORITY::e_INVALID;	// シーン後の描画の優先度、高いほど上に表示される

			int before_update_priority = (int)GAME::FUNCTION::PRIOTRITY::E_GAME_BEFORE_UPDATE_PRIORITY::e_INVALID;	// シーン前の更新の優先度、高いほど先に更新される
			int after_update_priority = (int)GAME::FUNCTION::PRIOTRITY::E_GAME_AFTER_UPDATE_PRIORITY::e_INVALID;	// シーン後の更新の優先度、高いほど先に更新される

			bool flg_function_end = false;	// 機能を終了するかどうかのフラグ

		} mpr_variable;	// プロテクトの変数を呼び出すための名前


		//==☆ プロテクト ☆==//
	protected:

		//-☆- 更新 -☆-//

		// シーン前の更新
		virtual void M_Before_Event_Update(void);

		// シーン後の更新
		virtual void M_After_Event_Update(void);


		//-☆- セッタ -☆-//

		// シーン前の更新の優先度レベルを設定する　引数：設定する優先度
		void M_Set_Before_Update_Priority(int);

		// シーン後の更新の優先度レベルを設定する　引数：設定する優先度
		void M_Set_After_Update_Priority(int);

		// シーン後の描画の優先度レベルを設定する　引数：設定する優先度
		void M_Set_After_Draw_Priority(int);


		//== ☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Game_Function_Base(void);

		// デストラクタ
		virtual ~C_Game_Function_Base(void);


		//-☆- 更新 -☆-//

		// シーン処理前のイベントを呼び出して実行する
		void M_Call_Event_Before_Scene_Process(void);

		// シーン処理後のイベントを呼び出して実行する
		void M_Call_Event_After_Scene_Process(void);


		//-☆- 出力 -☆-//

		// シーン前に行う出力処理
		virtual void M_Draw_Before_Scene_Process(void);

		// シーン後に行う出力処理
		virtual void M_After_Draw_Process(void);


		//-☆- セッタ -☆-//

		// イベント実行の周期を設定する　引数：設定する次の実行までの待ち時間
		void M_Set_Update_Period_Time(float);

		// 機能を終了させるかどうかを設定する　引数：設定する終了するかどうかのフラグ
		void M_Set_Flg_End_Function(bool);


		//-☆- ゲッタ -☆-//

		// シーン前の更新の優先度のレベルを返す　戻り値：優先度の値の参照
		const int & M_Get_Before_Update_Priority(void);

		// シーン後の更新の優先度のレベルを返す　戻り値：優先度の値の参照
		const int & M_Get_After_Update_Priority(void);

		// シーン後の描画の優先度のレベル返す　戻り値：優先度の値の参照
		const int & M_Get_After_Draw_Priority(void);

		// 機能を終了するかどうかのフラグを返す　戻り値：機能を終了するかどうかのフラグの参照
		const bool & M_Get_Flg_End_Function(void);
	};
}


#endif // !D_INCLUDE_GUARD_EVENT_BASE_H_FILE


//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆

