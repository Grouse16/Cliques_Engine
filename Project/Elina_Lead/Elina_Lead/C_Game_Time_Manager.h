//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：エンジンの入力を制御するシステム
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_ENGINE_TIME_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_ENGINE_TIME_MANAGER_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>


// ☆ ネームスペース ☆ //

// エンジンの時間を呼び出すための名前
namespace GAME::TIME
{
	// ☆ クラス ☆ //

	// エンジンの時間を制御するシステム
	class C_Game_Time_Manager
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			unsigned __int64 time_of_seconds_start = 0;	// 一秒の始まりの時間
			unsigned __int64 now_timer = 0;				// 今の時間を計測する
			unsigned __int64 then_timer = 0;			// 前回の時間を計測する

			float need_spend_time = 0;		// フレームレートを維持するためにはこの時間まで待機するべきという時間
			float delta_second = 0.0f;		// 前の更新からの経過時間（秒単位）
			float one_frame_time = 0.0f;	// １フレーム間で経過しているべき時間
			float game_speed = 1.0f;		// ゲームのスピード

			int frame_rate = 60;	// フレームレート
			int fps = 1;		// 一秒間のフレーム数
			int now_frame = 0;	// 現在のフレーム数

			bool flg_constant_frame = false;	// 固定フレームにするかどうかのフラグ

		} mpr_variable;	// プライベート変数を呼び出すための名前

		static std::unique_ptr<C_Game_Time_Manager> m_this;	// インスタンス化するための実体（シングルトン用）


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ
		C_Game_Time_Manager(void);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// 時間用システムを生成する
		static void M_Init(void);

		// デストラクタ
		~C_Game_Time_Manager(void);

		// メモリを解放する
		static void M_Release(void);


		//-☆- 更新 -☆-//

		// 時間の更新
		static void M_Time_Update(void);

		// フレームの終了時に行う更新
		static void M_Frame_End_Update(void);


		//-☆- ゲッタ -☆-//

		// FPSを維持するための時間が経過しているかどうかを返す　戻り値：trueなら経過している
		static bool M_Get_FPS_Request_Time_Passed(void);

		// 現在の規定フレームレートを返す　戻り値：規定フレームレート
		static int M_Get_Frame_Rate(void);

		// 現在のfpsを返す　戻り値：現在のfps
		static int M_Get_FPS(void);

		// 現在の経過時間を返す　戻り値：現在の経過時間
		static float M_Get_Delta_Second(void);

		// ゲーム内での経過時間を返す　戻り値：ゲームでの経過時間
		static float M_Get_Game_Second(void);

		// ゲーム内時間のスピードを返す　戻り値：ゲーム内時間のスピード
		static float M_Get_Game_Speed(void);


		//-☆- セッタ -☆-//

		// フレームレートをセットする　引数：設定するフレームレート
		static void M_Set_Frame_Rate(int);

		// ゲーム内時間のスピードをセットする　引数：セットするゲーム内時間のスピード
		static void M_Set_Game_Speed(float);
	};
}


#endif // !D_INCLUDE_GUARD_C_ENGINE_TIME_H_FILE
