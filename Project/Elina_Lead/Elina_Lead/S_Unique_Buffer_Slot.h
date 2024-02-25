//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：DX12のレンダリングスクリーン（レンダリング先画像）のシステム
// 説明   ：レンダーターゲットビューと深度ステンシルビューを管理する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GAURD_S_UNIQUE_BUFFER_SLOT_H_FILE
#define D_INCLUDE_GAURD_S_UNIQUE_BUFFER_SLOT_H_FILE


// ☆ ネームスペース ☆ //

// シェーダー用のリソースの定義を呼び出すための名前
namespace ASSET::SHADER::RESOURCE
{
	// ☆ 構造体 ☆ //

	// 特殊バッファのスロットの番号をまとめたリストの構造体
	struct S_Unique_Buffer_Slot
	{
		int wvp = -1;	// ワールド ビュー プロジェクション
		int bone = -1;	// ボーンマトリクス

		int material = -1;	// 質感データ

		int ambient_light = -1;		// アンビエントライト
		int directional_light = -1;	// ディレクショナルライト
		int point_light = -1;		// ポイントライト
		int spot_light = -1;		// スポットライト
		int area_light = -1;		// エリアライト
	};
}


#endif // !D_INCLUDE_GAURD_S_UNIQUE_BUFFER_SLOT_H_FILE

