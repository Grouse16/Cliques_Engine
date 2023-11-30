//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：変形しないモデルのコンポーネントのシステム
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_STATIC_MODEL_COMPONENT
#define D_INCLUDE_GUARD_C_STATIC_MODEL_COMPONENT


// ☆ ファイルひらき ☆ //
#include <string>

#include "C_Component_Base.h"
#include "C_3D_Model_User.h"
#include "C_Transform.h"
#include "C_Material_User.h"


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


		//-☆- ゲッタ -☆-//

		// ローカル座標の参照を返す　戻り値：ローカル座標の参照
		MATH::C_Transform & M_Get_Transform(void);

		// モデルシステムのアドレスを返す　戻り値：モデルシステムのアドレス
		ASSET::MODEL::C_3D_Model_User * M_Get_Model_Address(void);


		//-☆- 描画 -☆-//

		// 描画を行う
		void M_Draw();
	};
}


#endif // !D_INCLUDE_GUARD_C_STATIC_MODEL_COMPONENT
