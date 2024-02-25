//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：DX12でフォントを使うためのデータ管理用のクラス（ポリモーフィズム用）
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_DX12_FONT_DATA_SET_H_FILE


// ☆ ファイルひらき ☆ //
#include <windows.h>

#include "C_Rendering_Font_Inform_Base.h"


// ☆ ネームスペース ☆ //

// DX12用のシステムを呼び出すための名前
namespace RENDERING::API::DX12::DX12_INSTANCE
{
	// ☆ クラス ☆ //

	// DX12用のフォントデータセット
	class C_DX12_Font_Data_Set : public INSTANCE::C_Rendering_Font_Inform_Base
	{
	//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		LOGFONTW m_log_font;	// フォントの設定


		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_DX12_Font_Data_Set(void);

		// デストラクタ
		~C_DX12_Font_Data_Set(void) override;

		// フォントデータの初期化
		void M_Reset(void) override;


		//-☆- 変更 -☆-//

		// フォントのピクセルサイズを変更する　引数：横のピクセル数, 縦のピクセル数
		void M_Resize(int, int) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_DX12_FONT_DATA_SET_H_FILE

