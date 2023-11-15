//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：3Dモデルを制御するためのクラス
// 説明   ：3Dモデルが多重でロードされないように、ロードとメモリの解放を管理する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_3D_MODEL_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_3D_MODEL_MANAGER_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>
#include <memory>

#include "C_3D_Model_System.h"


// ☆ ネームスペース ☆ //

// 3Dモデルの制御用システムを呼び出すための名前
namespace ASSET::MODEL::MANAGER
{
	// ☆ クラス ☆ //

	// 3Dモデルを制御するためのクラス
	class C_3D_Model_Manager
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 構造体 ☆ //

		// 3Dモデルを管理するための情報の構造体
		struct S_3D_Model_Inform
		{
			std::unique_ptr<ASSET::MODEL::C_3D_Model_System> model_data;	// モデルのデータ

			std::string name = "default";	// この3Dモデル名

			int user_sum = 0;	// この3Dモデルを使用するインスタンス数
		};


		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::vector <S_3D_Model_Inform> model_list;	// 3Dモデル用のリスト

		} mpr_variable;	// プライベート変数を呼び出すための名前

		static C_3D_Model_Manager m_this;	// 自クラスのインスタンス（シングルトン化）


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ、シングルトン化する
		C_3D_Model_Manager(void);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 終了時 -☆-//

		// デストラクタ
		~C_3D_Model_Manager(void);

		// メモリを解放する
		static void M_Release(void);


		//-☆- ゲッタ -☆-//

		// 指定された3Dモデルを返す　引数：3Dモデルの名前　戻り値：指定された3Dモデルデータへのアドレス、なければnullptrを返す
		static ASSET::MODEL::C_3D_Model_System * M_Get_3D_Model_By_Name(std::string);


		//-☆- ロード -☆-//

		// 3Dモデル名から3Dモデルをロードする　引数：3Dモデル名　戻り値：生成した3Dモデルデータへのアドレス
		static ASSET::MODEL::C_3D_Model_System * M_Load_3D_Model_By_Name(std::string);


		//-☆- 削除 -☆-//

		// 指定された3Dモデル設定の所有権を放棄することを通知する　引数：所有権を放棄する3Dモデル設定のアドレスの参照
		static void M_Release_3D_Model(ASSET::MODEL::C_3D_Model_System * &);
	};
}


#endif // !D_INCLUDE_GUARD_C_3D_MODEL_MANAGER_H_FILE


