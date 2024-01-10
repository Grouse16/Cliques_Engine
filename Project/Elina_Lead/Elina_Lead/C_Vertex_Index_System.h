//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：頂点インデックスシステムのクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_VERTEX_INDEX_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_VERTEX_INDEX_SYSTEM_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>
#include <vector>

#include "C_Rendering_Index_Buffer_Setting_Inform_Base.h"


// ☆ ネームスペース ☆ //

// 描画に使用するシステムを呼び出すための名前
namespace RENDERING::CAPSULE
{
	// ☆ クラス ☆ //

	// 頂点インデックスシステムのクラス
	class C_Vertex_Index_System
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::unique_ptr<RENDERING::GRAPHICS::INSTANCE::C_Rendering_Index_Buffer_Setting_Inform_Base> m_index_buffer = nullptr;	// 頂点インデックスバッファ設定用情報

			std::vector<unsigned int> m_index_data;	// 頂点インデックスデータ

		} mpr_variable;	// プライベート変数を呼び出すための名前


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Vertex_Index_System(void);

		// コピーコンストラクタ　引数：コピーするデータの参照(const)
		C_Vertex_Index_System(const C_Vertex_Index_System & );

		// デストラクタ
		~C_Vertex_Index_System(void);

		// メモリを解放する
		void M_Release(void);


		//-☆- 生成 -☆-//

		// 頂点インデックスのデータとバッファを生成する　引数：生成するインデックス数
		void M_Create_Index_Data_And_Buffer(int);

		// 頂点インデックスバッファを現在のインデックスデータに合わせて生成する
		void M_Create_Index_Buffer_By_Now_Index_Data(void);


		//-☆- 削除 -☆-//

		// 頂点インデックスデータのみを削除する　＊頂点インデックスバッファは削除しない
		void M_Delete_Index_Data(void);


		//-☆- ゲッタ -☆-//

		// 頂点インデックスデータの参照を返す　戻り値：頂点インデックスデータの参照
		std::vector<unsigned int> & M_Get_Index_Data(void);


		//-☆- 描画 -☆-//

		// 頂点インデックスデータをバッファにセットする
		void M_Set_Index_Data_To_Buffer(void);

		// 頂点インデックスデータを使用して描画する
		void M_Draw_Execute_By_Index_Data(void);

		// 頂点インデックスデータを使用して描画するインデックスデータの範囲を指定して描画する　引数：描画するインデックスデータの開始位置、描画するインデックスデータの終了位置
		void M_Draw_Index_Data_By_Index_Data_Range(int, int);
	};
}


#endif // !D_INCLUDE_GUARD_C_VERTEX_INDEX_SYSTEM_H_FILE

