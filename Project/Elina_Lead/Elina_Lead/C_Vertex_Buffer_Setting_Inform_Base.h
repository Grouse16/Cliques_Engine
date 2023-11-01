//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：頂点バッファのセット用のデータの基底クラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_VERTEX_BUFFER_SETTING_INFORM_BASE_H_FILE
#define D_INCLUDE_GUARD_VERTEX_BUFFER_SETTING_INFORM_BASE_H_FILE


// ☆ ネームスペース ☆ //

// グラフィックを制御するシステムの情報を呼び出すための名前
namespace RENDERING::GRAPHICS::INSTANCE
{
	// ☆ クラス ☆ //

	// 頂点バッファのセット用のデータの基底クラス
	class C_Vertex_Buffer_Setting_Inform_Base
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 終了時 -☆-//

		// デストラクタ
		virtual ~C_Vertex_Buffer_Setting_Inform_Base(void) = 0;


		//-☆- セッタ -☆-//

		// 頂点データをセットする　引数：頂点のアドレス
		virtual void M_Set_Vertex_Setting(void * ) = 0;

		// インデックスデータをセットする　引数：インデックスのアドレス
		virtual void M_Set_Index_Setting(void*) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_VERTEX_BUFFER_SETTING_INFORM_BASE_H_FILE
