//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーションモデルのロードをするシステム
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_MODEL_LOADER_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_MODEL_LOADER_H_FILE


// ☆ ファイルひらき ☆ //
#include "S_Animation_Model_Load_Information.h"


// ☆ ネームスペース ☆ //

// アニメーションモデルをロードするためのシステムを呼び出すための名前
namespace ASSET::ANIMATION_MODEL::LOADER
{
	// ☆ クラス ☆ //

	// アニメーションモデルをロードするクラス
	class C_Animation_Model_Loader
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// インスタンス化できないようにコンストラクタを隠蔽した上で削除
		C_Animation_Model_Loader(void) = delete;


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- ロード -☆-//

		// アニメーションモデルをロードする　引数：ロードするための情報の参照　戻り値：成功時のみtrue
		static bool M_Load_Animation_Model(S_Animation_Model_Load_System &);
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_MODEL_LOADER_H_FILE

