//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：頂点インデックスバッファ設定用のデータの基底クラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_RENDERING_INFORM_BASE_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_INFORM_BASE_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>


// ☆ ネームスペース ☆ //

// グラフィックを制御するシステムの情報を呼び出すための名前
namespace RENDERING::GRAPHICS::INSTANCE
{
	// ☆ クラス ☆ //

	// 頂点インデックスバッファ設定用のデータの基底クラス
	class C_Rendering_Index_Buffer_Setting_Inform_Base
	{
	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Rendering_Index_Buffer_Setting_Inform_Base(void);

		// デストラクタ
		virtual ~C_Rendering_Index_Buffer_Setting_Inform_Base(void);


		//-☆- セッタ -☆-//

		// 頂点インデックスデータをセットする　引数：設定するインデックスデータの参照
		virtual void M_Set_Index_Setting(const std::vector<unsigned int> & ) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_INFORM_BASE_H_FILE


