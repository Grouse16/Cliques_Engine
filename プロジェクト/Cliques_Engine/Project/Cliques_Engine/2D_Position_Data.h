//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：2D頂点座標用のデータ定義用のファイル
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_2D_VERTEX_DATA_H_FILE
#define D_INCLUDE_GUARD_2D_VERTEX_DATA_H_FILE


// ☆ ネームスペース ☆ //

// 2Dの頂点座標用のデータの定義を呼び出すための名前
namespace DATA::POSITION_2D
{
	// ☆ クラス ☆ //

	// 2Dの頂点座標のクラス
	class C_2D_Position
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		float x = 0.0f;	// ｘ座標
		float y = 0.0f;	// ｙ座標


		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_2D_Position(void) { return; }

		// デストラクタ
		~C_2D_Position(void) { return; }


		//-☆- 設定 -☆-//

		// 頂点をセットする
		void M_Set_Position(float in_x, float in_y)
		{
			x = in_x;
			y = in_y;

			return;
		}
	};


	// 2Dのピクセル座標のクラス
	class C_2D_Pixel_Position
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		int x = 0;	// ｘ座標
		int y = 0;	// ｙ座標


		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_2D_Pixel_Position(void) { return; }

		// デストラクタ
		~C_2D_Pixel_Position(void) { return; }


		//-☆- 設定 -☆-//

		// 頂点をセットする
		void M_Set_Vertex(int in_x, int in_y)
		{
			x = in_x;
			y = in_y;

			return;
		}
	};
}


#endif // !D_INCLUDE_GUARD_2D_VERTEX_DATA_H_FILE

