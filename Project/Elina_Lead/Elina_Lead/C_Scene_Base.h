//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：シーンの基底となるクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_SCENE_BASE_H_FILE
#define D_INCLUDE_GUARD_C_SCENE_BASE_H_FILE


// ☆ ネームスペース ☆ //

// ゲームのシーンの基底となるクラス
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
		virtual ~C_Scene_Base(void) = 0;

		// メモリの解放を行う
		virtual void M_Release(void) = 0;


		//-☆- ロード -☆-//

		// シーンのロードの実行を行う
		virtual void M_Scene_Load(void) = 0;


		//-☆- 更新 -☆-//

		// シーンの更新を行う
		virtual void M_Scene_Update(void) = 0;


		//-☆- 描画 -☆-//

		// シーンの描画を行う
		virtual void M_Scene_Draw(void) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_SCENE_BASE_H_FILE

