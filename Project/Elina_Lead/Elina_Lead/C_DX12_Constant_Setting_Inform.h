//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：定数バッファ用データのクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_DX12_CONSTANT_SETTING_INFORM
#define D_INCLUDE_GUARD_C_DX12_CONSTANT_SETTING_INFORM


// ☆ ファイルひらき ☆ //
#include <vector>
#include <d3d12.h>
#include <wrl.h>

#include "C_Constant_Buffer_Setting_Inform_Base.h"


// ☆ ネームスペース ☆ //

// DX12用のシステムを呼び出すための名前
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
	// ☆ クラス ☆ //

	// 定数バッファ用データのクラス
	class C_DX12_Constant_Setting_Inform : public INSTANCE::C_Constant_Buffer_Setting_Inform_Base
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> m_constant_buffer_heap = nullptr;	// 定数バッファビューのヒープシステム（木構造管理システム）

		Microsoft::WRL::ComPtr<ID3D12Resource> m_constant_buffer_data = nullptr;	// 定数データ


		//-☆- 終了時 -☆-//

		// コンストラクタ
		C_DX12_Constant_Setting_Inform(void);

		// デストラクタ
		virtual ~C_DX12_Constant_Setting_Inform(void);


		//-☆- セッタ -☆-//

		// 定数バッファに指定された情報をセットする　引数：セットするデータ, 配列数, セットするデータサイズ
		void M_Set_Data_To_Buffer(void*, int, int) override;


		//-☆- ゲッタ -☆-//

		// 定数バッファのデータのアドレスを返す　＊使用が終わったら必ずCloseすること　戻り値：定数バッファのデータのアドレス
		unsigned char * M_Get_Constant_Buffer_Data_Address(void) override;

		// 定数バッファのデータを使用終了する
		void M_Close_Constant_Buffer_Data_Address(void) override;
	};
}


#endif // !D_INCLUDE_GUARD_C_DX12_CONSTANT_SETTING_INFORM
