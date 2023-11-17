//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：タイトルシーンのクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_SCENE_TITLE_H_FILE
#define D_INCLUDE_GUARD_C_SCENE_TITLE_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_Scene_Base.h"


// ☆ ネームスペース ☆ //

// ゲームシーンのシステムを呼び出すための名前
namespace GAME::SCENE
{
	// ☆ クラス ☆ //

	// タイトルシーンのクラス
	class C_Scene_Title : public GAME::SCENE::BASE::C_Scene_Base
	{
		//==☆ プライベート ☆==//
	private:


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ
		C_Scene_Title(void);

		// デストラクタ
		~C_Scene_Title(void) override;

		// メモリの解放を行う
		void M_Release(void) override;


		//-☆- ロード -☆-//

		// タイトルシーンのロード
		void M_Scene_Load(void) override;


		//-☆- 更新 -☆-//

		// ゲーム更新前のタイトルシーンの更新を行う
		void M_Scene_Before_Update(void) override;

		// ゲーム更新後・描画前のタイトルシーンの更新を行う
		void M_Scene_After_Update(void) override;

		// ゲーム描画前のタイトルシーンの更新を行う
		void M_Scene_Update_After_Draw(void) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_SCENE_TITLE_H_FILE
