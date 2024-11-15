//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：画像を表示するUIのクラス（UIのコンポーネント）
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_UIC_TEXT_BOX
#define D_INCLUDE_GUARD_C_UIC_TEXT_BOX


// ☆ ファイルひらき ☆ //
#include <string>

#include "C_UI_Component_Base.h"
#include "C_Material_User.h"
#include "C_Object_Vertex_System.h"
#include "C_Vertex_Index_System.h"
#include "S_UI_Vertex.h"
#include "S_Rect.h"


// ☆ ネームスペース ☆ //

// UIのコンポーネントを呼び出すための名前
namespace GAME::UI_COMPONENT
{
	// ☆ クラス ☆ //

	// 画像を表示するUIのクラス
	class C_UIC_Text_Box : GAME::UI_COMPONENT::BASE::C_UI_Component_Base
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			ASSET::MATERIAL::C_Material_User material;	// マテリアル

			RENDERING::CAPSULE::C_Object_Vertex_System<DATA::VERTEX::S_UI_Vertex> vertex_system;	// UIの頂点用のシステム

			RENDERING::CAPSULE::C_Vertex_Index_System index_system;	// 頂点インデックスシステム

		} mpr_variable;	// プライベート変数を呼び出すための名前


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_UIC_Text_Box(void);

		// デストラクタ
		~C_UIC_Text_Box(void);


		//-☆- ロード -☆-//

		// 指定された名前のテクスチャをロードする　引数：ロードするテクスチャ名
		void M_Load_Texture(std::string);


		//-☆- 更新 -☆-//

		// 更新を行う
		void M_Update(void) override;


		//-☆- 描画 -☆-//

		// 描画を行う
		void M_Draw(void) override;


		//-☆- 座標 -☆-//

		// UIの座標をセットする　引数：セット位置の四角形（左下が０，右上が１）
		void M_Set_UI_Position(DATA::RECTSETTING::S_Rect);


		//-☆- カラー -☆-//

		// 色を設定する　引数：色
		void M_Set_Color(DATA::COLOR::C_Color);
	};
}


#endif // !D_INCLUDE_GUARD_C_UIC_TEXT_BOX

