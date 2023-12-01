//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：3Dモデルを使用するためのシステム
// 説明   ：3Dモデル使用時の3Dモデル制御システムとの連絡を簡略化する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_3D_MODEL_USER_H_FILE
#define D_INCLUDE_GUARD_C_3D_MODEL_USER_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_3D_Model_System.h"


// ☆ ネームスペース ☆ //

// 3Dモデル用のシステムを呼び出すための名前
namespace ASSET::MODEL
{
	// ☆ クラス ☆ //

	// 3Dモデルを使用するためのシステム
	class C_3D_Model_User
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			ASSET::MODEL::C_3D_Model_System * use_model_address = nullptr;	// 使用するモデルまでのアドレス

		} mpr_variable;	// プライベート変数を呼び出すための名前


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_3D_Model_User(void);

		// デストラクタ
		~C_3D_Model_User(void);

		// マテリアルを解放する
		void M_Release(void);


		//-☆- ロード -☆-//

		// 指定された名前の3Dモデルを読み込む　引数：ロードする3Dモデル名　戻り値：成功時のみtrue
		bool M_Load_3D_Model(std::string);


		//-☆- 描画 -☆-//

		// 3Dモデルを描画する
		void M_Draw_3D_Model(void);

		// 指定された名前のメッシュのみ描画する　引数：描画するメッシュ名
		void M_Draw_3D_Model_Meshes_By_Mesh_Name(std::string);

		// 指定されたマテリアルを使って、3Dモデルを描画する　引数：使用するマテリアルの参照
		void M_Draw_3D_Model_And_Set_Material(ASSET::MATERIAL::C_Material_User & );

		// 指定されたマテリアルを使って、3Dモデルから指定されたメッシュ名のみ描画する　引数：使用するマテリアルの参照, 描画するメッシュ名（複数判定する）
		void M_Draw_3D_Model_Meshes_By_Name_And_Set_Material(ASSET::MATERIAL::C_Material_User & , std::string);


		//-☆- ゲッタ -☆-//

		// 現在の3Dモデルを返す　戻り値：現在の3Dモデルへのアドレス
		C_3D_Model_System * M_Get_3D_Model_Address(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_3D_MODEL_USER_H_FILE
