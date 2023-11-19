//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：コンポーネントの基底クラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_COMPONET_BASE_H_FILE
#define D_INCLUDE_GUARD_C_COMPONET_BASE_H_FILE


// ☆ ネームスペース ☆ //

// コンポーネントを呼び出すための名前
namespace GAME::COMPONENT::BASE
{
	// ☆ クラス ☆ //

	// コンポーネントの基底クラス
	class C_Component_Base
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //
		bool m_flg_destroy_component = false;	// コンポーネントを削除する


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Component_Base(void);

		// デストラクタ
		virtual ~C_Component_Base(void);


		//-☆- 更新 -☆-//

		// コンポーネントの更新
		virtual void M_Update(void) = 0;


		//-☆- 描画 -☆-//

		// コンポーネントの描画
		virtual void M_Draw(void) = 0;


		//-☆- ゲッタ -☆-//

		// コンポーネントを削除するかどうかのフラグを返す　戻り値：trueで削除する、falseで削除しない
		bool M_Get_Component_Destroy_Flg(void);


		//-☆- 削除 -☆-//

		// コンポーネントを削除するフラグを立てる
		void M_Destroy(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_COMPONET_BASE_H_FILE
