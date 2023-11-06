//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリング設定の定義を行うファイル
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_RENDERING_ANOTHER_SETTING_INFORM_H_FILE
#define D_INCLUDE_GUARD_RENDERING_ANOTHER_SETTING_INFORM_H_FILE


// ☆ ネームスペース ☆ //

// レンダリング設定定義用の情報を呼び出すための名前
namespace RENDERING::INFORM::SETTING
{
	// ☆ 構造体 ☆ //

	// サンプリングの設定を行うための情報の構造体
	struct S_Sampling_Setting_Inform
	{
		int sampling_count = 1;		// サンプリングの回数
		int sampling_quality = 1;	// サンプリングの品質
	};
}


#endif // !D_INCLUDE_GUARD_RENDERING_ANOTHER_SETTING_INFORM_H_FILE



