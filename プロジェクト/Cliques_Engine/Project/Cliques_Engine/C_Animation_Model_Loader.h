//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーションモデルのロードをするシステム
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_MODEL_LOADER_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_MODEL_LOADER_H_FILE


// ☆ ファイルひらき ☆ //
#include <string>

#include "C_Object_Vertex_System.h"
#include "C_Text_And_File_Manager.h"
#include "S_3D_Animation_Model_Vertex.h"
#include "S_Bone_Inform.h"
#include "C_Mesh_Data.h"


// ☆ ネームスペース ☆ //

// アニメーションモデルをロードするためのシステムを呼び出すための名前
namespace ASSET::ANIMATION_MODEL::LOADER
{
	// ☆ クラス ☆ //

	// アニメーションモデルをロードするクラス
	class C_Animation_Model_Loader
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		// インスタンス化できないようにコンストラクタを隠蔽した上で削除
		C_Animation_Model_Loader(void) = delete;


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- ロード -☆-//

		// 指定されたパスのファイルをロードし、アニメーションモデルのデータであるかどうかを判定する　引数：ファイルのパス, ロードした文字データの取得先の参照　戻り値：ロードに成功、かつアニメーションモデルのデータである場合のみtrue
		static bool M_Load_Animation_Model_File(std::string, SYSTEM::TEXT::C_Text_And_File_Manager & );

		// アニメーションモデルの頂点データをロードする　引数：モデルファイルのデータ, ロード先の頂点データの参照　戻り値：成功時のみtrue
		static bool M_Load_Animation_Model_Vertex(SYSTEM::TEXT::C_Text_And_File_Manager & , RENDERING::CAPSULE::C_Object_Vertex_System<DATA::VERTEX::S_3D_Animation_Model_Vertex> & );

		// アニメーションモデルのボーンデータをロードする　引数：モデルファイルのデータ, ロード先のボーンデータの参照　戻り値：成功時のみtrue
		static bool M_Load_Animation_Model_Bone(SYSTEM::TEXT::C_Text_And_File_Manager & , std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & );

		// アニメーションモデルのメッシュデータをロードする　引数：モデルファイルのデータ, ロード先のメッシュデータの参照　戻り値：成功時のみtrue
		static bool M_Load_Animation_Model_Mesh(SYSTEM::TEXT::C_Text_And_File_Manager & , std::vector<ASSET::MESH::C_Mesh_Data> & );
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_MODEL_LOADER_H_FILE

