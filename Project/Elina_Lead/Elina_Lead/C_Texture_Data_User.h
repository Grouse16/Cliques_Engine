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
			RENDERING::CAPSULE::C_Texture_Data_System * texture_data = nullptr;	// 使用するテクスチャデータへの参照

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

		// 指定された名前のテクスチャを読み込む　引数：テクスチャ名
		void M_Load_Texture(std::string);


		//-☆- 描画 -☆-//

		// このテクスチャを描画用にセットする　引数：設定先のインデックス番号
		void M_Texture_Attach_To_Draw(int);
	};
}

#endif // !D_INCLUDE_GUARD_C_TEXTURE_DATA_USER_H_FILE
