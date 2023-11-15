//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：テクスチャのデータを使用するためのクラス
// 説明   ：テクスチャの取得、ロード、解放を円滑に行い、staticであるマネージャを他の実装部から切り離すためにある
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_TEXTURE_DATA_USER_H_FILE
#define D_INCLUDE_GUARD_C_TEXTURE_DATA_USER_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_Texture_Data_System.h"


// ☆ ネームスペース ☆ //

// テクスチャのシステムを呼び出すための名前
namespace ASSET::TEXTURE
{
	// ☆ クラス ☆ //

	// テクスチャのデータを使用するためのクラス
	class C_Texture_Data_User
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::unique_ptr<RENDERING::CAPSULE::C_Texture_Data_System> texture_data = nullptr;	// 使用するテクスチャデータへの参照

			std::string signature_name = "default";	// テクスチャの識別名（ロードしたテクスチャの識別名を上書きする）
			ASSET::SHADER::E_SHADER_KIND shader_kind = ASSET::SHADER::E_SHADER_KIND::e_ALL;	// テクスチャの識別名（ロードしたテクスチャの設定先シェーダーを上書きする）

			bool flg_original_texture = false;	// オリジナルのテクスチャかどうかのフラグ

		} mpr_variable;	// プライベート変数を呼び出すための名前


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Texture_Data_User(void);

		// デストラクタ
		~C_Texture_Data_User(void);

		// テクスチャを解放する
		void M_Release(void);


		//-☆- ロード -☆-//

		// 指定された名前のテクスチャを読み込む　引数：ロードするテクスチャ名
		void M_Load_Texture(std::string);

		// オリジナルのテクスチャデータを生成する
		void M_Create_Original_Texture_Data(void);


		//-☆- 描画 -☆-//

		// このテクスチャを描画用情報（識別名,シェーダーの種類）を元にGPUにセットする
		void M_Texture_Attach_To_Draw_By_Inform(void);

		// このテクスチャを描画用にセットする　引数：設定先のインデックス番号
		void M_Texture_Attach_To_Draw_By_Index(int);


		//-☆- ゲッタ -☆-//

		// テクスチャデータのアドレスを返す　戻り値：テクスチャデータのアドレス
		RENDERING::CAPSULE::C_Texture_Data_System * M_Get_Texture_Data(void);


		//-☆- セッタ -☆-//

		// テクスチャの識別名をセットする　引数：テクスチャ識別名
		void M_Set_Texture_Signature(std::string);

		// シェーダーの種類をセットする　引数：シェーダーの種類
		void M_Set_Texture_Shader_Kind(ASSET::SHADER::E_SHADER_KIND);
	};
}

#endif // !D_INCLUDE_GUARD_C_TEXTURE_DATA_USER_H_FILE
