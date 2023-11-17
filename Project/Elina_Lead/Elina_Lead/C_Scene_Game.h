//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ゲームシーンのクラス
// 説明   ：ゲームシーン特有の動作や、ゲームシーンに必要なオブジェクトのロードを行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_SCENE_GAME_H_FILE
#define D_INCLUDE_GUARD_C_SCENE_GAME_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_Scene_Base.h"


// ☆ ネームスペース ☆ //
namespace GAME::SCENE
{
	// ☆ クラス ☆ //

	// ゲームシーンのクラス
	class C_Scene_Game : public GAME::SCENE::BASE::C_Scene_Base
	{
		//==☆ プライベート ☆==//
	private:


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ
		C_Scene_Game(void);

		// デストラクタ
		~C_Scene_Game(void) override;

		// メモリの解放を行う
		void M_Release(void) override;


		//-☆- ロード -☆-//

		// ゲームシーンのロード
		void M_Scene_Load(void) override;


		//-☆- 更新 -☆-//

		// ゲーム更新前のゲームシーンの更新を行う
		void M_Scene_Before_Update(void) override;

		// ゲーム更新後・描画前のゲームシーンの更新を行う
		void M_Scene_After_Update(void) override;

		// ゲーム描画前のゲームシーンの更新を行う
		void M_Scene_Update_After_Draw(void) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_SCENE_GAME_H_FILE
