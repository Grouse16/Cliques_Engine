//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：変形しないモデルのコンポーネントのシステム
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_STATIC_MODEL_COMPONENT
#define D_INCLUDE_GUARD_C_STATIC_MODEL_COMPONENT


// ☆ ファイルひらき ☆ //
#include <vector>
#include <string>

#include "C_Component_Base.h"
#include "C_3D_Model_User.h"
#include "C_Transform.h"
#include "C_Material_User.h"
#include "S_Model_Draw_Command.h"


// ☆ ネームスペース ☆ //

// モデル用コンポーネントを呼び出すための名前
namespace GAME::COMPONENT::MODEL_COMPONENT
{
	// ☆ クラス ☆ //

	// 変形しないモデルのコンポーネントクラス
	class C_Static_Model_Component : public GAME::COMPONENT::BASE::C_Component_Base
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			ASSET::MODEL::C_3D_Model_User model_system;	// 3Dモデルシステム
			
			MATH::C_Transform transform;	// モデルの設置位置（ローカル座標）

			std::vector<ASSET::MODEL_SYSTEM::S_Model_Draw_Command> draw_command_list;	// 描画設定リスト

			DirectX::XMMATRIX world_matrix = DirectX::XMMATRIX();	// ワールドマトリクス変換行列

		} mpr_variable;	// プライベート変数を呼び出すための名前


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Static_Model_Component(void);

		// デストラクタ
		~C_Static_Model_Component(void);


		//-☆- ロード -☆-//

		// 指定された名前のモデルをロードする　引数：ロードするモデル名　戻り値：成功時のみtrue
		bool M_Load_Model_By_Name(std::string);


		//-☆- セッタ -☆-//

		// 描画設定リストを番号を指定して設定する、前にあった描画設定のデータは消える　引数：設定先の描画設定番号, 使用するマテリアル名, 描画するメッシュ名のリスト（中身なしで全メッシュ描画）　戻り値：追加したマテリアル使用システムのアドレス
		ASSET::MATERIAL::C_Material_User * M_Set_Model_Draw_List(int, std::string, std::vector<std::string>);


		//-☆- ゲッタ -☆-//

		// ローカル座標の参照を返す　戻り値：ローカル座標の参照
		MATH::C_Transform & M_Get_Transform(void);

		// モデルシステムの参照を返す　戻り値：モデルシステムの参照
		ASSET::MODEL::C_3D_Model_User & M_Get_Model_Address(void);


		//-☆- 描画 -☆-//

		// 描画位置となるワールドマトリクスを設定する、描画の開始時に実行する、通常描画の開始時でよい　引数：設定するワールドマトリクス変換行列の参照（const）
		void M_Draw_Start_World_Matrix_Set(const DirectX::XMMATRIX & );

		// モデルの描画を行う　引数：描画する時の描画設定の番号
		void M_Model_Draw(int);

		// コンポーネント用の描画処理だが使用しない（モデル描画前にマテリアルの設定などを行うため）
		void M_Draw(void) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_STATIC_MODEL_COMPONENT
