//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ゲームの入力の当たり判定を制御するシステム
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆　//
#ifndef D_INCLUDE_GUARD_C_Game_INPUT_COLLISION_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_Game_INPUT_COLLISION_MANAGER_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>
#include <string>
#include <vector>

#include "E_Game_Input_Collision_State.h"
#include "Game_Input_Collision_Names.h"


// ☆ ネームスペース ☆ //

// ゲームの入力系統を呼び出すための名前
namespace GAME::INPUT::COLLISION
{
	// ☆ クラス ☆ //

	// ゲームの入力を受け取るシステム、基底クラス
	class C_Game_Input_Collision
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			E_Game_Input_Collision_State collision_state;	// 当たり判定の状態

			std::wstring collision_name = GAME::INPUT::COLLISION::NAME::con_Game_INPUT_COLLISION_INITIALIZED_NAME;	// 入力ボックス名

			bool is_active = true;	// 当たり判定を有効にするかどうか

			int priority = 0;	// 優先度

		} mpr_variable;	// プライベート変数をまとめた名前


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Game_Input_Collision(void);

		// デストラクタ
		virtual ~C_Game_Input_Collision(void);


		//-☆- セッタ -☆-//

		// ボックスの名前をセットする　引数：設定するボックス名
		void M_Set_Box_Name(std::wstring);

		// 当たり判定を有効にするかどうかをセットする　引数：trueでアクティブに
		void M_Set_Is_Active(bool);

		// 当たり判定の優先度をセットする　引数：設定する優先度
		void M_Set_Priority(int);


		//-☆- ゲッタ -☆-//

		// 当たり判定の名前を取得する　戻り値：現在の当たり判定の名前の参照(const)
		const std::wstring & M_Get_Collision_Name(void) const;

		// 当たり判定が有効かどうかを取得する　戻り値：trueならアクティブ
		bool M_Get_Is_Active(void) const;

		// 現在の当たり判定の優先度を返す　戻り値：当たり判定の優先度
		int M_Get_Priority(void) const;


		//-☆- 判定 -☆-//

		// 指定された座標と重なっているかどうか　引数：当たり判定の座標ｘ, 当たり判定の座標ｙ　戻り値：当たっていたらtrue
		virtual bool M_Collision_To_Pixel(int, int) const = 0;


		//-☆- 状態の遷移 -☆-//

		// 何もされていない状態へ遷移
		void M_Change_State_Command_Not_Hit(void);

		// カーソルが重なっている状態へ遷移
		void M_Change_State_Command_Overed(void);

		// クリック中の状態へ遷移
		void M_Change_State_Command_Clicking(void);

		// ダブルクリック中の状態へ遷移
		void M_Change_State_Command_Double_Clicking(void);

		// ドラッグ中の状態へ遷移
		void M_Change_State_Command_Dragging(void);

		// ドラッグ中にカーソルが重なっている状態へ遷移
		void M_Change_State_Command_Dragging_Over(void);

		// ドラッグ中に当たり判定の上でドロップされたことを示す
		void M_Change_State_Command_Drag_Dropped(void);
	};


	// ゲームの入力の当たり判定を制御するシステム
	class C_Game_Input_Collision_Manager
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::vector<C_Game_Input_Collision * > collision_list;	// 入力判定のリスト

		} mpr_variable;	// プライベート変数を呼び出すための名前

		static std::unique_ptr<C_Game_Input_Collision_Manager> m_this;	// このクラスをインスタンス化するための変数（シングルトン化）


		//-☆- 初期化 -☆-//

		// コンストラクタ
		C_Game_Input_Collision_Manager(void);


		//==☆ パブリック ☆==//
	public:

		//-☆- 初期化と終了時 -☆-//

		// ゲームの入力ボックス制御用システムの生成
		static void M_Init(void);

		// デストラクタ
		~C_Game_Input_Collision_Manager(void);

		// メモリ解放
		static void M_Release(void);


		//-☆- ゲッタ -☆-//

		// 入力判定のリストの参照を返す　戻り値：入力判定のリストの参照
		static std::vector<C_Game_Input_Collision * > & M_Get_Input_Collision_List(void);

		
		//-☆- リスト -☆-//

		// 指定された入力判定のアドレスを管理用リストに追加する　引数：リストに追加する入力判定のアドレス
		static void M_Add_Input_Box_Address_To_List(C_Game_Input_Collision * );

		// 指定された入力判定のアドレスを管理用リストから削除する　引数：リストから削除したい入力判定のアドレス
		static void M_Delete_Input_Box_Address_From_List(C_Game_Input_Collision * );
	};
}


#endif // !D_INCLUDE_GUARD_C_Game_INPUT_COLLISION_MANAGER



