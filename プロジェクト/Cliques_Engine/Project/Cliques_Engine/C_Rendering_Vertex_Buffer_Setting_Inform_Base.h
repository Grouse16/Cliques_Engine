//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：頂点バッファのセット用のデータの基底クラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_RENDERING_VERTEX_BUFFER_SETTING_INFORM_BASE_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_VERTEX_BUFFER_SETTING_INFORM_BASE_H_FILE


// ☆ ネームスペース ☆ //

// グラフィックを制御するシステムの情報を呼び出すための名前
namespace RENDERING::API::INSTANCE
{
	// ☆ クラス ☆ //

	// 頂点バッファのセット用のデータの基底クラス
	class C_Rendering_Vertex_Buffer_Setting_Inform_Base
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Rendering_Vertex_Buffer_Setting_Inform_Base(void);

		// デストラクタ
		virtual ~C_Rendering_Vertex_Buffer_Setting_Inform_Base(void);


		//-☆- セッタ -☆-//

		// 頂点データをセットする　引数：頂点のアドレス
		virtual void M_Set_Vertex_Setting(void * ) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_VERTEX_BUFFER_SETTING_INFORM_BASE_H_FILE
