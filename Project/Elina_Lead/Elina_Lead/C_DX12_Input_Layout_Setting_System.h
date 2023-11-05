//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ダイレクトエックス12の入力レイアウト設定用のクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_DX12_INPUT_LAYOUT_SETING_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_DX12_INPUT_LAYOUT_SETING_SYSTEM_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>
#include <memory.h>
#include <d3d12.h>

#include "Input_Layout_Data.h"


// ☆ ネームスペース ☆ //

// DX12システムを呼び出すための名前
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
	// ☆ クラス ☆ //

	// ダイレクトエックス12の入力レイアウト設定用のクラス
	class C_DX12_Input_Layout_Setting_System
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //
		std::vector<D3D12_INPUT_ELEMENT_DESC> m_element_list;	// 入力エレメント管理用配列


		// ☆ 関数 ☆ //

		//-☆- ゲッタ -☆-//

		// 指定された情報に合った形式の識別用の情報を返す　引数：インプットレイアウト設定用情報　戻り値：フォーマット情報
		DXGI_FORMAT M_Get_Format_By_Fit_Setting(const DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING &);


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 生成 -☆-//
		
		// 指定されたデータを元に入力用のセマンティック情報を生成する　引数：設定先の入力レイアウト情報, レイアウト設定用の情報
		void M_Create_Input_Layout_By_Create_Inform(D3D12_INPUT_LAYOUT_DESC &, const std::vector<DATA::INPUTLAYOUT::S_INPUT_LAYOUT_SETTING> &);


		//-☆- 削除 -☆-//
		
		// デストラクタ
		~C_DX12_Input_Layout_Setting_System(void);

		// 入力用セマンティック設定用の情報を削除する、パイプラインステートオブジェクトを生成し終わったら削除
		void M_Close_Input_Layout_Inform(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_DX12_INPUT_LAYOUT_SETING_SYSTEM_H_FILE

