//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：レンダリングAPIの生成と解放のインターフェース
// 説明   ：生成と解放の動作のみをまとめて提供する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_INITIALIZE_AND_RELEASE_H_FILE
#define D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_INITIALIZE_AND_RELEASE_H_FILE


// ☆ ネームスペース ☆ //

// レンダリングAPI用のインターフェースを呼び出すための名前
namespace RENDERING::API::RENDER_INTERFACE
{
	// ☆ クラス ☆ //

	// レンダリングAPIの生成と解放を行うクラス
	class C_Rendering_API_Interface_Initialize_And_Release
	{
	//==☆ プライベート ☆==//
private:

		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// インスタンス化防止のためにコンストラクタ隠蔽して削除
		C_Rendering_API_Interface_Initialize_And_Release(void) = delete;


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 生成 -☆-//

		// レンダリングAPIの初期化　戻り値：成功時のみtrue
		static bool M_Initialize_Rendering_API(void);

		// レンダリングAPIのDX12を生成する
		static void M_Create_DX12(void);


		//-☆- 解放 -☆-//

		// レンダリングAPIの解放
		static void M_Release_Rendering_API(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_RENDERING_API_INTERFACE_INITIALIZE_AND_RELEASE_H_FILE


