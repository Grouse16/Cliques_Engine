//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーションモデルのクラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_3D_ANIMATION_MODEL_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_3D_ANIMATION_MODEL_SYSTEM_H_FILE


// ☆ ファイルひらき ☆ //
#include "C_Animative_Mesh.h"
#include "S_Bone_Inform.h"
#include "C_Animation_Data_System.h"
#include "C_Transform.h"


// ☆ ネームスペース ☆ //

// アニメーションできる3Dモデルを呼び出すための名前
namespace ASSET::ANIMATION_MODEL
{
	// ☆ クラス ☆ //

	// アニメーションモデルのシステム
	class C_3D_Animation_Model_System
	{
		//==☆ パブリック ☆==//
	public:

		// ☆ 構造体 ☆ //

		// メッシュを管理するためのデータの構造体
		struct S_Animative_Mesh_Data_Inform
		{
			std::unique_ptr<ASSET::ANIMATION::MESH::C_Animative_Mesh> mesh_data = nullptr;	// メッシュデータ

			std::string name = "default";	// メッシュ名
		};

		// アニメーションを管理するためのデータの構造体
		struct S_Animation_Data_Inform
		{
			std::unique_ptr<ASSET::ANIMATION_SYSTEM::C_Animation_Data_System> animation_data = nullptr;	// アニメーションデータ

			std::string name = "default";	// アニメーションデータ名
		};


		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::vector<S_Animative_Mesh_Data_Inform> mesh_inform_list;	// メッシュの管理用情報リスト

			std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> bone_list;	// ボーン情報のリスト

			std::vector<S_Animation_Data_Inform> animation_data_list;	// アニメーションデータのリスト

		} mpr_variable;	// プライベート変数を呼び出すための名前


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_3D_Animation_Model_System(void);

		//デストラクタ
		~C_3D_Animation_Model_System(void);

		// メモリの解放を行う
		void M_Release(void);


		//-☆- ロード -☆-//

		// 指定されたパスの3Dアニメーションモデルをロードする　引数：3Dアニメーションモデルまでのパス　戻り値：成功時のみtrue
		bool M_Load_3D_Animation_Model_By_Path(std::string);

		// 指定された名前のアニメーションデータをロードする　引数：ロードするアニメーションデータ名　戻り値：成功時のみtrue
		bool M_Load_Animation_Data_By_Name(std::string);


		//-☆- ゲッタ -☆-//

		// 指定された名前のメッシュデータ情報のアドレスを返す　引数：探すメッシュの名前　戻り値：名前が一致したメッシュのアドレス、一致しなかったらnullptrを返す
		ASSET::ANIMATION::MESH::C_Animative_Mesh * M_Get_Mesh_Data_By_Name(std::string);

		// メッシュ情報のリストの参照を返す　戻り値：メッシュ情報のリストの参照
		std::vector<S_Animative_Mesh_Data_Inform> & M_Get_Mesh_Inform_List(void);

		// 指定された名前のアニメーションデータ情報のアドレスを返す　引数：探すアニメーションデータの名前　戻り値：名前が一致したアニメーションのアドレス、一致しなかったらnullptrを返す
		const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * M_Get_Animation_Data_By_Name(std::string);

		// アニメーション情報のリストの参照を返す　戻り値：アニメーション情報のリストの参照
		const std::vector<S_Animation_Data_Inform> & M_Get_Animation_Inform_List(void);

		// ボーン情報のリストを返す　戻り値：ボーン情報のリストの参照(const)
		const std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> & M_Get_Bone_Inform_List(void);


		//-☆- 描画 -☆-//

		// 3Dモデルを描画する
		void M_Draw_3D_Model(void);

		// 3Dモデルから指定されたアニメーション名のみ描画する　引数：描画するアニメーション名（複数判定する）
		void M_Draw_Meshes_By_Name(std::string);

		// マテリアルを設定せずに、3Dモデルを描画する（描画前にマテリアルをセットするとき用）
		void M_Draw_3D_Model_Do_Not_Use_Material(void);

		// マテリアルを設定せずに、3Dモデルから指定されたメッシュ名のみ描画する（描画前にマテリアルをセットするとき用）　引数：描画するメッシュ名（複数判定する）
		void M_Draw_Meshes_By_Name_Do_Not_Use_Material(std::string);


		//-☆- 定数バッファ -☆-//

		// ボーンのマトリクスをマテリアルにセットする　引数：セットするボーンマトリクス配列の参照(const)
		void M_Set_Bone_Matrix(const std::vector<DirectX::XMFLOAT4X4>&);

		// ワールド ビュー プロジェクションをメインカメラを元に定数バッファにセットする　引数：トランスフォームの参照（const）
		void M_Set_World_View_Projection_With_Main_Camera_By_Transform(const MATH::C_Transform & );

		// ワールド ビュー プロジェクションをメインカメラを元に定数バッファにセットする、ワールドマトリクスを受け取る　引数：ワールドマトリクスの参照（const）
		void M_Set_World_View_Projection_With_Main_Camera_By_World_Matrix(const DirectX::XMMATRIX & );
	};
}


#endif // !D_INCLUDE_GUARD_C_3D_ANIMATION_MODEL_SYSTEM_H_FILE



































//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆
