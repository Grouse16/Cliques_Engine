//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：マテリアルを使用するためのクラス
// 説明   ：マテリアルの取得、ロード、解放を円滑に行い、staticであるマネージャを他の実装部から切り離すためにある
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_MATERIAL_USER_H_FILE
#define D_INCLUDE_GUARD_C_MATERIAL_USER_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_Material.h"

#include <string>


// ☆ ネームスペース ☆ //

// マテリアルを呼び出すための名前
namespace ASSET::MATERIAL
{
	// ☆ クラス ☆ //

	// マテリアルを使用するためのクラス
	class C_Material_User
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			ASSET::MATERIAL::C_Material * material_address = nullptr;	// マテリアル

		} mpr_variable;	// プライベート変数を呼び出すための名前


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Material_User(void);

		// デストラクタ
		~C_Material_User(void);

		// マテリアルを解放する
		void M_Release(void);

		
		//-☆- ロード -☆-//

		// 指定された名前のマテリアルを読み込む　引数：ロードするマテリアル名
		void M_Load_Material(std::string);


		//-☆- 描画 -☆-//

		// このマテリアルを描画用にセットする
		void M_Material_Attach_To_Draw(void);


		//-☆- ゲッタ -☆-//

		// 現在のマテリアルを返す　戻り値：現在のマテリアルへのアドレス
		C_Material * M_Get_Material_Address(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_MATERIAL_MANAGER_H_FILE
