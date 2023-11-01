//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリング設定用データのセット用のデータの基底クラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_RENDERING_GRAPHICS_SETTING_INFORM_BASE
#define D_INCLUDE_GUARD_C_RENDERING_GRAPHICS_SETTING_INFORM_BASE


// ☆ ネームスペース ☆ //

// グラフィックを制御するシステムの情報を呼び出すための名前
namespace RENDERING::GRAPHICS::INSTANCE
{
	// ☆ クラス ☆ //

	// レンダリング設定用データのセット用のデータの基底クラス
	class C_Rendering_Graphics_Setting_Inform_Base
	{
	//==☆ パブリック ☆==//
	public:

		//-☆- 関数 -☆-//

		//-☆- 終了時 -☆-//

		// デストラクタ
		virtual ~C_Rendering_Graphics_Setting_Inform_Base(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_GRAPHICS_SETTING_INFORM_BASE




