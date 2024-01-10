//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：3Dアニメーションをするモデルを管理するシステム
// 説明   ：同じアニメーションモデルの多重ロードを防ぎ、名前によるモデルの管理を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_MODEL_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_MODEL_MANAGER_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>
#include <vector>

#include "C_Animation_Model_System.h"


// ☆ ネームスペース ☆ //

// アニメーションモデルを呼び出すための名前
namespace ASSET::ANIMATION_MODEL::MANAGER
{
	// ☆ クラス ☆ //

	// 3Dアニメーションをするモデルを管理するシステム
	class C_Animation_Model_Manager
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 構造体 ☆ //

		// アニメーションするモデルの管理用の情報の構造体
		struct S_Animation_Model_Inform
		{
			std::unique_ptr<ASSET::ANIMATION_MODEL::C_Animation_Model_System> animation_model = nullptr;	// アニメーションモデル

			std::string name = "DEFAULT";	// アニメーションモデル名

			int user_sum = 0;	// このアニメーションモデルを使用しているインスタンス数
		};


		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::vector<S_Animation_Model_Inform> animation_model_inform_list;	// アニメーションモデル情報のリスト

		} mpr_variable;	// プライベート変数を呼び出すための名前

		static C_Animation_Model_Manager m_this;	// アニメーションモデル制御用システムのシングルトン化用インスタンス


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ、シングルトン化する
		C_Animation_Model_Manager(void);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 終了時 -☆-//

		// デストラクタ
		~C_Animation_Model_Manager(void);

		// メモリを解放する
		static void M_Release(void);


		//-☆- ゲッタ -☆-//

		// 指定されたアニメーションモデルを返す　引数：探すアニメーションモデルの名前　戻り値：指定されたアニメーションモデルへのアドレス、なければnullptrを返す
		static ASSET::ANIMATION_MODEL::C_Animation_Model_System * M_Get_Animation_Model_By_Name(std::string);


		//-☆- ロード -☆-//

		// アニメーションモデル名からアニメーションモデルをロードする　引数：ロードするアニメーションモデル名　戻り値：生成したアニメーションモデルへのアドレス
		static ASSET::ANIMATION_MODEL::C_Animation_Model_System * M_Load_Animation_Model_By_Name(std::string);


		//-☆- 削除 -☆-//

		// 指定されたアニメーションモデルの所有権を放棄することを通知する　引数：所有権を放棄するアニメーションモデルのアドレスの参照
		static void M_Release_Animation_Model(ASSET::ANIMATION_MODEL::C_Animation_Model_System * &);
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_MODEL_MANAGER_H_FILE

