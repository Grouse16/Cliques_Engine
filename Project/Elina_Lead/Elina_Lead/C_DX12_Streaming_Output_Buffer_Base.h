//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ストリーミング出力用バッファの基底クラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_STREAMING_OUTPUT_BUFFER_H_FILE
#define D_INCLUDE_GUARD_C_STREAMING_OUTPUT_BUFFER_H_FILE


// ☆ ファイルひらき ☆ //
#include <d3d12.h>


// ☆ ネームスペース ☆ //

// ストリーミング出力用バッファを呼び出すための名前
namespace RENDERING::GRAPHICS::DX12::DX12INSTANCE
{
	// ☆ クラス ☆ //

	// ストリーミング出力用バッファの基底クラス
	class C_DX12_Streaming_Output_Buffer_Base
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// ストリーミング出力用バッファを使用しない時の初期化を行う　引数：パイプライン設定用情報
		static void M_Do_Not_Use_Setting(D3D12_GRAPHICS_PIPELINE_STATE_DESC &);
	};
}


#endif // !D_INCLUDE_GUARD_C_STREAMING_OUTPUT_BUFFER_H_FILE
