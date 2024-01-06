//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーションするモデルのコンポーネントシステム
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_MODEL_COMPONENT_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_MODEL_COMPONENT_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>
#include <string>

#include "C_Component_Base.h"
#include "C_Animation_Model_User.h"
#include "C_Transform.h"
#include "C_Material_User.h"
#include "S_Model_Draw_Command.h"


// ☆ ネームスペース ☆ //

// モデル用コンポーネントを呼び出すための名前
namespace GAME::COMPONENT::MODEL_COMPONENT
{
	// ☆ クラス ☆ //

	// アニメーションするモデルのコンポーネントクラス
	class C_Animation_Model_Component : GAME::COMPONENT::BASE::C_Component_Base
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			ASSET::ANIMATION_MODEL::C_Animation_Model_User model_system;	// アニメーションモデルシステム

			MATH::C_Transform transform;	// モデルの設置位置（ローカル座標）

			std::vector<ASSET::MODEL_SYSTEM::S_Model_Draw_Command> draw_command_list;	// 描画設定リスト

			DirectX::XMMATRIX world_matrix = DirectX::XMMATRIX();	// ワールドマトリクス変換行列

			std::string time_line_name = "default";	// アニメーションに使用するタイムライン名

			bool flg_use_time_line = false;	// アニメーションにタイムラインを使用するかどうかのフラグ、trueで使用する、falseでゲーム時間を使う

		} mpr_variable;	// プライベート変数を呼び出すための名前


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Animation_Model_Component(void);

		// デストラクタ
		~C_Animation_Model_Component(void);


		//-☆- ロード -☆-//

		// 指定された名前のモデルをロードする　引数：ロードするモデル名　戻り値：成功時のみtrue
		bool M_Load_Animation_Model_By_Name(std::string);


		//-☆- セッタ -☆-//

		// 描画設定リストを番号を指定して設定する、前にあった描画設定のデータは消える　引数：設定先の描画設定番号, 使用するマテリアル名, 描画するメッシュ名のリスト（中身なしで全メッシュ描画）　戻り値：追加したマテリアル使用システムのアドレス
		ASSET::MATERIAL::C_Material_User * M_Set_Model_Draw_List(int, std::string, std::vector<std::string>);

		// タイムラインを使用するモードに切り替える　引数：使用するタイムライン名
		void M_Set_Time_Line_Name_And_Start_Time_Line_Mode(std::string);

		// 通常のゲーム時間を使用するモードに切り替える
		void M_Set_Game_Time_Mode(void);


		//-☆- ゲッタ -☆-//

		// ローカル座標の参照を返す　戻り値：ローカル座標の参照
		MATH::C_Transform & M_Get_Transform(void);

		// モデルシステムの参照を返す　戻り値：アニメーションモデルシステムの参照
		ASSET::ANIMATION_MODEL::C_Animation_Model_User & M_Get_Model_Address(void);

		
		//-☆- 更新 -☆-//

		// アニメーションの時間を更新する
		void M_Update(void);


		//-☆- 描画 -☆-//

		// 描画位置となるワールドマトリクスを設定する、描画の開始時に実行する　引数：設定するワールドマトリクス変換行列の参照（const）
		void M_Draw_Start_And_World_Matrix_Set(const DirectX::XMMATRIX & );

		// モデルの描画を行う　引数：描画する時の描画設定の番号
		void M_Model_Draw(int);

		// モデルの描画を終了する
		void M_Model_Draw_End(void);

		// コンポーネント用の描画処理だが使用しない（モデル描画前にマテリアルの設定などを行うため）
		void M_Draw(void) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_MODEL_COMPONENT_H_FILE

