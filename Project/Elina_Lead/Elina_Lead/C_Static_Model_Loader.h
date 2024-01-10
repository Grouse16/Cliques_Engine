//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：静的モデルをロードするクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_STATIC_MODEL_LOADER_H_FILE
#define D_INCLUDE_GUARD_C_STATIC_MODEL_LOADER_H_FILE


// ☆ ファイルひらき ☆ //
#include <string>

#include "C_Text_And_File_Manager.h"
#include "C_Object_Vertex_System.h"
#include "S_3D_Model_Vertex.h"
#include "C_Mesh_Data.h"


// ☆ ネームスペース ☆ //

// 静的モデルをロードするためのシステムを呼び出すための名前
namespace ASSET::MODEL::STATIC_MODEL::LOADER
{
	// ☆ クラス ☆ //

	// 静的モデルをロードするクラス
	class C_Static_Model_Loader
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// コンストラクタ、インスタンス化できないようにするために隠蔽して削除
		C_Static_Model_Loader(void) = delete;


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- ロード -☆-//

		// 指定されたファイルをロードし、静的モデルであるかどうかを判定する　引数：ファイル名, ロードしたファイルデータの記録先　戻り値：ロードに成功、かつ静的モデルであればtrue
		static bool M_Load_Static_Model_File_Data(std::string, SYSTEM::TEXT::C_Text_And_File_Manager & );

		// 静的モデルの頂点データをロードする　引数：モデルファイルのデータ, ロード先の頂点データの参照　戻り値：成功時のみtrue
		static bool M_Load_Static_Model_Vertex(SYSTEM::TEXT::C_Text_And_File_Manager & , RENDERING::CAPSULE::C_Object_Vertex_System<DATA::VERTEX::S_3D_Model_Vertex> & );

		// 静的モデルのメッシュデータをロードする　引数：モデルファイルのデータ, ロード先のメッシュデータの参照　戻り値：成功時のみtrue
		static bool M_Load_Static_Model_Mesh(SYSTEM::TEXT::C_Text_And_File_Manager & , std::vector<ASSET::MESH::C_Mesh_Data> & );
	};
}


#endif // !D_INCLUDE_GUARD_C_STATIC_MODEL_LOADER_H_FILE
