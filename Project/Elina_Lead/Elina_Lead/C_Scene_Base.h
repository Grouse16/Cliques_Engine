//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：シーンの基底となるクラス
// 説明   ：シーンごとに異なる挙動をするための抽象化レイヤー
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_SCENE_BASE_H_FILE
#define D_INCLUDE_GUARD_C_SCENE_BASE_H_FILE


// ☆ ネームスペース ☆ //

// ゲームのシーンの基底のシステムを呼び出すための名前
namespace GAME::SCENE::BASE
{
	// ☆ クラス ☆ //

	// シーンの基底となるクラス
	class C_Scene_Base
	{
		//==☆ プライベート ☆==//
	private:


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ
		C_Scene_Base(void);

		// デストラクタ
		virtual ~C_Scene_Base(void);

		// メモリの解放を行う
		virtual void M_Release(void) = 0;


		//-☆- ロード -☆-//

		// シーンのロードの実行を行う
		virtual void M_Scene_Load(void) = 0;


		//-☆- 更新 -☆-//

		// ゲーム更新前のシーンの更新を行う
		virtual void M_Scene_Before_Update(void) = 0;

		// ゲーム更新後・描画前のシーンの更新を行う
		virtual void M_Scene_After_Update(void) = 0;

		// ゲーム描画前のシーンの更新を行う
		virtual void M_Scene_Update_After_Draw(void) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_SCENE_BASE_H_FILE

