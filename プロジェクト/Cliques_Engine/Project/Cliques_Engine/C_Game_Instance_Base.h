//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ゲームインスタンスの基底となるクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_GAME_INSTANCE_BASE_H_FILE
#define D_INCLUDE_GUARD_C_GAME_INSTANCE_BASE_H_FILE


// ☆ ファイルひらき ☆ //
#include <string>


// ☆ ネームスペース ☆ //

// ゲームのオブジェクトの基底となるシステムを呼び出すための名前
namespace GAME::INSTANCE::BASE
{
	// ☆ クラス ☆ //

	// ゲーム上のインスタンスの基底となるクラス
	class C_Game_Instance_Base
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //
		std::string m_name = "default";	// インスタンス名

		bool m_flg_destroy_instance = false;	// ゲームインスタンスを削除するかどうかのフラグ
		bool m_flg_scene_over = false;			// シーン遷移時に削除されなくなるフラグ


		//==☆ パブリック ☆==//
	public:

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Game_Instance_Base(void);

		// デストラクタ
		virtual ~C_Game_Instance_Base(void);


		//-☆- セッタ -☆-//

		// インスタンス名を設定する　引数：設定するインスタンスの名前
		void M_Set_Instance_Name(std::string);

		// シーン遷移時に削除されるかどうかのフラグをセットする　引数：trueで削除されない、falseで削除される
		void M_Set_Scene_Over_Flg(bool);


		//-☆- ゲッタ -☆-//

		// インスタンスを削除するかどうかのフラグを返す　戻り値：trueで削除される、falseで削除されない
		bool M_Get_Destroy_Instance_Flg(void);

		// シーン遷移時に削除されるかどうかのフラグを返す　戻り値：trueで削除されない、falseで削除される
		bool M_Get_Scene_Over_Flg(void);

		// インスタンス名を返す　戻り値：インスタンスの名前（const型）
		const std::string & M_Get_Instance_Name(void);


		//-☆- 削除 -☆-//

		// 削除の実行を申告する
		void M_Destroy(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_GAME_INSTANCE_BASE_H_FILE



