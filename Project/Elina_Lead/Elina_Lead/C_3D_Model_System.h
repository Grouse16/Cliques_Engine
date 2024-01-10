//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：3Dモデルのクラス
// 説明   ：3Dモデルの取得から描画、アニメーションの実行までを行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_3D_MODEL_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_3D_MODEL_SYSTEM_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>
#include <memory>
#include <string>
#include <DirectXMath.h>

#include "C_Mesh_Data.h"
#include "C_Transform.h"
#include "C_Object_Vertex_System.h"
#include "S_3D_Model_Vertex.h"


// ☆ ネームスペース ☆ //

// 3Dモデルを呼び出すための名前
namespace ASSET::MODEL
{
	// ☆ クラス ☆ //

	// 3Dモデルのクラス
	class C_3D_Model_System
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //
		
		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			RENDERING::CAPSULE::C_Object_Vertex_System<DATA::VERTEX::S_3D_Model_Vertex> vertex_system;	// 頂点データを管理するクラス

			std::vector<ASSET::MESH::C_Mesh_Data> mesh_list;	// メッシュの管理用情報リスト

		} mpr_variable;	// プライベート変数を呼び出すための名前


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_3D_Model_System(void);

		//デストラクタ
		~C_3D_Model_System(void);

		// メモリの解放を行う
		void M_Release(void);


		//-☆- ロード -☆-//

		// 指定されたパスの3Dモデルをロードする　引数：3Dモデルまでのパス　戻り値：成功時のみtrue
		bool M_Load_3D_Model_By_Path(std::string);


		//-☆- ゲッタ -☆-//

		// 指定された名前のメッシュ情報のアドレスを返す　引数：探すメッシュの名前　戻り値：名前が一致したメッシュのアドレス、一致しなかったらnullptrを返す
		ASSET::MESH::C_Mesh_Data * M_Get_Mesh_Data_By_Name(std::string);

		// メッシュ情報のリストの参照を返す　戻り値：メッシュ情報のリストの参照
		std::vector<ASSET::MESH::C_Mesh_Data> & M_Get_Mesh_Inform_List(void);


		//-☆- 描画 -☆-//

		// 3Dモデルを描画する
		void M_Draw_Model(void);

		// 3Dモデルから指定されたメッシュ名のみ描画する　引数：描画するメッシュ名（複数判定する）
		void M_Draw_Meshes_By_Name(std::string);

		// マテリアルを設定せずに、3Dモデルを描画する（描画前にマテリアルをセットするとき用）
		void M_Draw_Model_Do_Not_Use_Material(void);

		// マテリアルを設定せずに、3Dモデルから指定されたメッシュ名のみ描画する（描画前にマテリアルをセットするとき用）　引数：描画するメッシュ名（複数判定する）
		void M_Draw_Meshes_By_Name_Do_Not_Use_Material(std::string);


		//-☆- 定数バッファ -☆-//

		// ワールド ビュー プロジェクションをメインカメラを元に定数バッファにセットする、トランスフォームを受け取る　引数：トランスフォームの参照（const）
		void M_Set_World_View_Projection_With_Main_Camera_By_Transform(const MATH::C_Transform & );

		// ワールド ビュー プロジェクションをメインカメラを元に定数バッファにセットする、ワールドマトリクスを受け取る　引数：ワールドマトリクスの参照（const）
		void M_Set_World_View_Projection_With_Main_Camera_By_World_Matrix(const DirectX::XMMATRIX &);
	};
}


#endif // !D_INCLUDE_GUARD_C_3D_MODEL_SYSTEM_H_FILE





































//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆
