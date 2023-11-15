//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：マテリアルを制御するためのシステム
// 説明   ：マテリアルのロードや解放を行ったり、重複して同じマテリアルをロードしないように管理する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_MATERIAL_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_MATERIAL_MANAGER_H_FILE


// ☆ ファイルひらき ☆ //
#include <string>
#include <vector>

#include "C_Material.h"


// ☆ ネームスペース ☆ //

// マテリアル制御用のシステムを呼び出すための名前
namespace ASSET::MATERIAL::MANAGER
{
	// ☆ クラス ☆ //

	// マテリアルを制御用するためのシステム
	class C_Material_Manager
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 構造体 ☆ //

		// マテリアル管理用の情報の構造体
		struct S_Material_Manage_Inform
		{
			std::unique_ptr<C_Material> material = nullptr;	// マテリアル

			std::string name = "DEFAULT";	// マテリアル名

			int user_sum = 0;	// このマテリアルを使用しているインスタンス数
		};


		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::vector<S_Material_Manage_Inform> material_inform_list;	// マテリアル情報のリスト

		} mpr_variable;	// プライベート変数を呼び出すための名前

		static C_Material_Manager m_this;	// マテリアル制御用システムのシングルトン化用インスタンス


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ、シングルトン化する
		C_Material_Manager(void);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 終了時 -☆-//

		// デストラクタ
		~C_Material_Manager(void);

		// メモリを解放する
		static void M_Release(void);


		//-☆- ゲッタ -☆-//

		// 指定されたマテリアルを返す　引数：マテリアルの名前　戻り値：指定されたマテリアルデータへのアドレス、なければnullptrを返す
		static ASSET::MATERIAL::C_Material * M_Get_Material_By_Name(std::string);


		//-☆- ロード -☆-//

		// マテリアル名からマテリアルをロードする　引数：マテリアル名　戻り値：生成したマテリアルデータへのアドレス
		static ASSET::MATERIAL::C_Material * M_Load_Material_By_Name(std::string);


		//-☆- 削除 -☆-//

		// 指定されたマテリアルの所有権を放棄することを通知する　引数：所有権を放棄するマテリアルのアドレスの参照
		static void M_Release_Material(ASSET::MATERIAL::C_Material * &);
	};
}


#endif // !D_INCLUDE_GUARD_C_MATERIAL_MANAGER_H_FILE
