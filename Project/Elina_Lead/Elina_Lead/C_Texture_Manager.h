//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：テクスチャを制御するためのシステム
// 説明   ：テクスチャのロードや解放を行ったり、重複して同じテクスチャをロードしないように管理する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_TEXTURE_MANAGER_H_FILE
#define D_INCLUDE_GUARD_C_TEXTURE_MANAGER_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>
#include <vector>
#include <string>

#include "C_Texture_Data_System.h"


// ☆ ネームスペース ☆ //
namespace ASSET::TEXTURE::MANAGER
{
	// ☆ クラス ☆ //

	// テクスチャ制御用システム
	class C_Texture_Manager
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 構造体 ☆ //

		// テクスチャ管理用の構造体
		struct S_Texture_Manage_Inform
		{
			std::unique_ptr<RENDERING::CAPSULE::C_Texture_Data_System> texture = nullptr;	// テクスチャ用のシステム

			std::string name = "DEFAULT";	// テクスチャ名

			int user_sum = 0;	// このテクスチャを使用しているインスタンス数
		};


		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::vector<S_Texture_Manage_Inform> texture_list;	// テクスチャをまとめたリスト

			RENDERING::CAPSULE::C_Texture_Data_System reset_texture;	// テクスチャをリセットするためのテクスチャデータ

		} mpr_variable;	// プライベート変数を呼び出すための名前

		static C_Texture_Manager m_this;	// テクスチャ制御用のシステム

		
		// ☆ 変数宣言 ☆ //
		
		//-☆- 初期化 -☆-//

		// コンストラクタ
		C_Texture_Manager(void);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// テクスチャ制御用のシステムを初期化する
		static void M_Init(void);

		// デストラクタ
		~C_Texture_Manager(void);

		// メモリを解放する
		static void M_Release(void);


		//-☆- ゲッタ -☆-//

		// 指定されたテクスチャを返す　引数：テクスチャの名前　戻り値：指定されたテクスチャへのアドレス、なければnullptrを返す
		static RENDERING::CAPSULE::C_Texture_Data_System * M_Get_Texture_By_Name(std::string);


		//-☆- ロード -☆-//

		// テクスチャ名からテクスチャをロードする　引数：テクスチャ名　戻り値：生成したテクスチャへのアドレス、なければnullptrを返す
		static RENDERING::CAPSULE::C_Texture_Data_System * M_Load_Texture_By_Name(std::string);


		//-☆- 生成 -☆-//

		// リセット用のテクスチャを返す　戻り値：テクスチャ情報リセット時のテクスチャの参照(const)
		static RENDERING::CAPSULE::C_Texture_Data_System * M_Get_Reset_Texture(void);


		//-☆- 削除 -☆-//

		// 指定されたテクスチャ設定の所有権を放棄することを通知する　引数：所有権を放棄するテクスチャ設定のアドレスの参照
		static void M_Release_Texture(RENDERING::CAPSULE::C_Texture_Data_System * & );
	};
}


#endif  // !D_INCLUDE_GUARD_C_TEXTURE_MANAGER_H_FILE
