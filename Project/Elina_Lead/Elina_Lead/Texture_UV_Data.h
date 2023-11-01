//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：テクスチャUV用のデータ定義用のファイル
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_TEXTURE_UV_DATA_H_FILE
#define D_INCLUDE_GUARD_TEXTURE_UV_DATA_H_FILE


// ☆ ネームスペース ☆ //

// テクスチャUV用のデータの定義を呼び出すための名前
namespace DATA::TEXTURE_UV
{
	// ☆ クラス ☆ //

	// 頂点座標のクラス
	class C_Textuer_UV
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		float u = 0.0f;	// U座標
		float v = 0.0f;	// V座標


		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Textuer_UV(void) { return; }
		
		// ＵＶ座標をセットするコンストラクタ
		C_Textuer_UV(float in_u, float in_v) 
		{
			u = in_u;
			v = in_v;

			return;
		}

		// デストラクタ
		~C_Textuer_UV(void) { return; }


		//-☆- 設定 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：UV座標をセットする
		// 引数   ：float セットするU, float セットするV
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		void M_Set_UV(float in_u, float in_v)
		{
			u = in_u;
			v = in_v;

			return;
		}
	};
}


#endif // !D_INCLUDE_GUARD_TEXTURE_UV_DATA_H_FILE

