//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：プロジェクションのシステム
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_PROJECTION_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_PROJECTION_SYSTEM_H_FILE


// ☆ ファイルひらき ☆ //
#include <DirectXMath.h>


// ☆ ネームスペース ☆ //

// プロジェクションのシステムを呼び出すための名前
namespace GAME::CAMERA::PROJECTION
{
	// ☆ 構造体 ☆ //

	// プロジェクションのシステムの構造体
	class C_Projection_System
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 変数宣言 ☆ //
		float field_of_view_angle = 0.7853f;	// 視野角（ラジアン）
		float aspect_ratio = 1.0f;			// アスペクト比	
		float near_clip_plane = 1.0f;			// ニアクリップ（視錐台カリング：これ以下の距離にあるメッシュは描画しない）
		float far_clip_plane = 1000.0f;		// ファークリップ（視錐台カリング：これ以上の距離にあるメッシュは描画しない）


		// ☆ 関数 ☆ //
		
		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Projection_System(void);
		
		// デストラクタ
		~C_Projection_System(void);


		//-☆- ゲッタ -☆-//

		// プロジェクションのマトリクス変換行列を渡された参照先にセットする　引数：プロジェクションのマトリクス変換行列の設定先の参照
		void M_Get_Projection(DirectX::XMMATRIX & ) const;
	};
}


#endif // !D_INCLUDE_GUARD_C_PROJECTION_SYSTEM_H_FILE
