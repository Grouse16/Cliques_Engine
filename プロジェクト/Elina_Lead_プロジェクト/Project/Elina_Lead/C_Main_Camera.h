//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：メインカメラのシステム
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_MAIN_CAMERA_H_FILE
#define D_INCLUDE_GUARD_C_MAIN_CAMERA_H_FILE


// ☆ ファイルひらき ☆ //
#include <DirectXMath.h>


// ☆ ネームスペース ☆ //

// メインとなるカメラを呼び出すための名前
namespace GAME::CAMERA::MAIN_CAMERA
{
	// ☆ クラス ☆ //
	
	// メインカメラのクラス
	class C_Main_Camera
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			DirectX::XMMATRIX view = DirectX::XMMATRIX();	// ビューのマトリクス変換行列
			DirectX::XMMATRIX projection = DirectX::XMMATRIX();	// プロジェクションのマトリクス変換行列

		} mpr_variable;	// プライベート変数を呼び出すための名前

		static C_Main_Camera m_this;	// シングルトン化するためのインスタンス


		//-☆- 初期化 -☆-//

		// コンストラクタ
		C_Main_Camera(void);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// メインカメラを初期化する
		static void M_Reset(void);

		// デストラクタ
		~C_Main_Camera(void);


		//-☆- セッタ -☆-//

		// ビューのマトリクス変換行列をセットする　引数：セットするビューのマトリクス変換行列の参照（const）
		static void M_Set_View_Matrix(const DirectX::XMMATRIX & );

		// プロジェクションのマトリクス変換行列をセットする　引数：セットするプロジェクションのマトリクス変換行列の参照（const）
		static void M_Set_Projection_Matrix(const DirectX::XMMATRIX & );

		
		//-☆- ゲッタ -☆-//

		// ビューのマトリクス変換行列の参照を返す　戻り値：ビューのマトリクス変換行列の参照（const）
		static const DirectX::XMMATRIX & M_Get_View_Matrix(void);

		// プロジェクションのマトリクス変換行列の参照を返す　戻り値：プロジェクションのマトリクス変換行列の参照（const）
		static const DirectX::XMMATRIX & M_Get_Projection_Matrix(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_MAIN_CAMERA_H_FILE
