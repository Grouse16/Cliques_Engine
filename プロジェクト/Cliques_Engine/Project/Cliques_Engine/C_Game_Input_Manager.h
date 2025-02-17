//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ゲームの入力を制御するシステム
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_Game_INPUT_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_Game_INPUT_MANAGER_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_Game_Input_Collision_Manager.h"


// ☆ ネームスペース ☆ //

// ゲームの入力を制御するシステム
namespace GAME::INPUT
{
	// ☆ クラス ☆ //

	// ゲームの入力を制御するシステム
	class C_Game_Input_Manager
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			// カーソルの座標用の構造体
			struct S_Cursor_Pixel
			{
				int x = 0;	// ｘ座標
				int y = 0;	// ｙ座標

			};

			// マウスの判定用の情報をまとめた構造体
			struct S_Game_Mouse_Inform
			{
				bool flg_clicking = false;			// クリック中のみたつフラグ
				bool flg_double_clicking = false;	// ダブルクリック中のみたつフラグ
				bool flg_dragging = false;			// ドラッグ操作中のみたつフラグ

				GAME::INPUT::COLLISION::C_Game_Input_Collision * clicking_collision_add = nullptr;	// クリック中の判定のアドレス
				GAME::INPUT::COLLISION::C_Game_Input_Collision * drag_overed_add = nullptr;			// ドラッグ中のカーソルの下にある判定のアドレス

				S_Cursor_Pixel cursor_pixel;		// 現在のカーソルの座標
				S_Cursor_Pixel start_clicked_pixel;	// クリック入力開始位置
				S_Cursor_Pixel end_clicked_pixel;	// クリック入力終了位置

			}mouse;	// マウス用の情報を呼び出すための名前

		} mpr_variable;	// プライベート変数を呼び出すための名前

		static std::unique_ptr<C_Game_Input_Manager> m_this;	// インスタンス化するための実体（シングルトン用）


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ
		C_Game_Input_Manager(void);


		//-☆- 更新 -☆-//

		// マウス入力判定の更新
		void M_Update_Mouse_Input(void);

		// 通常時の入力判定の更新
		void M_Update_Input_Collision_On_Normal_Timing(void);

		// クリック入力後の判定の更新
		void M_Update_Input_Collision_After_Clicked(void);

		// 入力判定の更新
		void M_Update_Input_Collision(void);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// 入力用システムを生成する
		static void M_Init(void);

		// デストラクタ
		~C_Game_Input_Manager(void);

		// メモリを解放する
		static void M_Release(void);


		//-☆- 更新 -☆-//

		// 入力の更新
		static void M_Update(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_Game_INPUT_MANAGER_H_FILE

