//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーション用のメッシュのクラス
// 説明   ：アニメーションブレンド用の定数バッファを持つシステムを追加したメッシュシステムクラス
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_ANIMATIVE_MESH_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATIVE_MESH_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_Vertex_Index_System.h"
#include "C_Material_User.h"


// ☆ ネームスペース ☆ //

// アニメーションするメッシュを呼び出すための名前
namespace ASSET::ANIMATION::MESH
{
	// ☆ クラス ☆ //
	
	// アニメーション用のメッシュのクラス
	class C_Animative_Mesh
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			RENDERING::CAPSULE::C_Vertex_Index_System m_vertex_index_system;	// 頂点インデックスシステム

			ASSET::MATERIAL::C_Material_User material;	// マテリアルデータ

		} mpr_variable;	// プライベート変数を呼び出すための名前


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Animative_Mesh(void);

		// デストラクタ
		~C_Animative_Mesh(void);

		// メモリを解放する
		void M_Release(void);


		//-☆- 頂点インデックス -☆-//

		// 頂点インデックスを指定された数分生成　引数：生成する頂点インデックス数
		void M_Create_Index_List(int);

		// 頂点インデックスデータを頂点インデックスバッファに設定する
		void M_Attach_Index_Data_To_Buffer(void);

		// 頂点インデックスデータのみを削除する（頂点インデックスバッファに設定後、編集しないなら持っておく必要がない）
		void M_Delete_Index_Data(void);


		//-☆- ロード -☆-//

		// 指定された名前のマテリアルをロードする　引数：マテリアル名　戻り値：成功時のみtrue
		bool M_Load_Material_By_Name(std::string);


		//-☆- ゲッタ -☆-//

		// 頂点インデックスデータのリストの参照を返す　戻り値：頂点インデックスデータのリストの参照
		std::vector<unsigned int> & M_Get_Index_Data_List(void);

		// 現在のマテリアルユーザーの参照を返す　戻り値：マテリアルユーザーの参照を返す
		ASSET::MATERIAL::C_Material_User & M_Get_Material_User(void);


		//-☆- 描画 -☆-//

		// メッシュの描画を実行する
		void M_Draw_Mesh(void);

		// マテリアルの設定をせずに面の描画のみ行う（外部でマテリアルを設定してから描画するとき用）
		void m_Draw_Mesh_Do_Not_Set_Material(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATIVE_MESH_H_FILE
