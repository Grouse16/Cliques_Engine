//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリング用の情報を円滑に設定し、レンダリングするためのシステム
// 説明   ：レンダリング用情報の設定をカプセル化する
// 作成者 ：��坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_RENDERING_SETTING_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_SETTING_SYSTEM_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>

#include "C_Rendering_Graphics_Setting_Inform_Base.h"
#include "S_Create_Rendering_Graphics_Setting_Inform.h"


// ☆ ネームスペース ☆ //

// 描画に使用するシステムを呼び出すための名前
namespace RENDERING::CAPSULE
{
	// ☆ クラス ☆ //

	// レンダリング用の情報を円滑に設定し、レンダリングするためのシステム
	class C_Rendering_Setting_System
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::unique_ptr <RENDERING::API::INSTANCE::C_Rendering_Graphics_Setting_Inform_Base> rendering_setting_inform = nullptr;	// レンダリング設定用情報

		} mpr_variable;	// プライベート変数を呼び出すための名前


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Rendering_Setting_System(void);

		// デストラクタ
		~C_Rendering_Setting_System(void);

		// メモリの解放を行う
		void M_Delete(void);


		//-☆- 生成 -☆-//

		// 生成用の情報を元に生成する　引数：レンダリング設定生成用情報(const)
		bool M_Create_Pipeline_Setting(const RENDERING::API::CREATE::S_Create_Rendering_Graphics_Setting_Inform & );


		//-☆- 描画 -☆-//

		// レンダリングAPIにこのレンダリング設定を適用する
		void M_Set_Rendering_Setting_For_API(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_SETTING_SYSTEM_H_FILE
