//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：フォントデータを制御するための名前
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDEA_GUARD_C_RENDERING_FONT_INFORM_BASE_H_FILE
#define D_INCLUDEA_GUARD_C_RENDERING_FONT_INFORM_BASE_H_FILE


// ☆ ネームスペース ☆ //

// グラフィックを制御するシステムの情報を呼び出すための名前
namespace RENDERING::GRAPHICS::INSTANCE
{
	// ☆ クラス ☆ //

	// フォントのデータを管理するシステム
	class C_Rendering_Font_Inform_Base
	{
	//==☆ プロテクト ☆==//
	protected:


	//==☆ パブリック ☆==//
	public:


		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Rendering_Font_Inform_Base(void);

		// デストラクタ
		virtual ~C_Rendering_Font_Inform_Base(void);

		// フォントのデータをリセットする
		virtual void M_Reset(void) = 0;


		//-☆- 変更 -☆-//

		// フォントのピクセルサイズを変更する　引数：横のピクセル数, 縦のピクセル数
		virtual void M_Resize(int, int) = 0;
	};
}


#endif // !D_INCLUDEA_GUARD_C_RENDERING_FONT_INFORM_BASE_H_FILE
