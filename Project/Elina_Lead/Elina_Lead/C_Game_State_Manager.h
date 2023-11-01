//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：エンジンの状態を共有するためのクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_Engine_State_Manager_H_FILE
#define D_INCLUDE_GUARD_C_Engine_State_Manager_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>
#include <string>


// ☆ ネームスペース ☆ //

// エンジンの状態を共有する
namespace GAME::STATE
{
	// ☆ 定数 ☆ //

	const std::wstring con_Invalid_Scene_Name = L"Invald";// シーンが設定されていないことを示す文字列


	// ☆ クラス ☆ //

	// エンジンの状態を共有するためのクラス
	class C_Game_State_Manager
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// 変数をまとめた構造体
		struct S_Varible
		{
			std::wstring now_engine_scene_name = con_Invalid_Scene_Name;			// 現在のエンジンのシーン名
			std::wstring excute_change_engine_scene_name = con_Invalid_Scene_Name;	// シーン変更要求の変更先シーン名
			

		};	// 変数を呼び出すための名前


		// ☆ 変数宣言 ☆ //
		static std::unique_ptr<C_Game_State_Manager> m_this;	// 自身のインスタンス化

		S_Varible mpr_variable;	// プライベート変数を呼び出すための名前


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ
		C_Game_State_Manager(void);


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// システムを生成する
		static void M_Init(void);

		// デストラクタ
		~C_Game_State_Manager(void);

		// メモリ解放
		static void M_Release(void);


		//-☆- セッタ -☆-//

		// 現在のシーン名をセットする　引数：設定する現在のシーン名
		static void M_Set_Now_Engine_Scene_Name(std::wstring);

		// シーン変更要求の変更先シーン名をセットする　引数：セットするシーン変更要求の変更先シーン名
		static void M_Set_Execute_Change_Engine_Scene_Name(std::wstring);


		//-☆- ゲッタ -☆-//

		// 現在のシーン名の参照を取得する　戻り値：現在のシーン名の参照(const)
		static const std::wstring & M_Get_Now_Engine_Scene_Name(void);

		// シーン変更要求の変更先シーン名の参照を取得する　戻り値：シーン変更要求の変更先シーン名の参照(const)
		static const std::wstring & M_Get_Execute_Change_Engine_Scene_Name(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_Engine_State_Manager_H_FILE



