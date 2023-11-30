//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーションモデルを使用するためのシステム
// 説明   ：アニメーションモデルマネージャーとの操作を隠蔽し、簡単に使用できるようにカプセル化する　アニメーションの実行を行う
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_MODEL_USER
#define D_INCLUDE_GUARD_C_ANIMATION_MODEL_USER


// ☆ ファイルひらき ☆ //
#include <memory>

#include "C_3D_Animation_Model_System.h"
#include "C_Animation_Calculation_System.h"
#include "C_Transform.h"


// ☆ ネームスペース ☆ //

// アニメーションモデルを使用するシステムを呼び出すための名前
namespace ASSET::ANIMATION_MODEL
{
	// ☆ クラス ☆ //

	// アニメーションモデルを使用するためのシステム
	class C_Animation_Model_User
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::vector<DirectX::XMFLOAT4X4> bone_matrix_list;	// ボーンマトリクスの配列

			ASSET::ANIMATION_MODEL::C_3D_Animation_Model_System * animation_model = nullptr;	// 使用するアニメーションモデルまでのアドレス

			std::unique_ptr<ASSET::ANIMATION::CALCULATOR::C_Animation_Calculation_System> animation_calculator = nullptr;	// アニメーションの計算システム

			std::string model_name = "default";	// モデル名

		} mpr_variable;	// プライベート変数を呼び出すための名前

		
		// ☆ 関数 ☆ //

		//-☆- アニメーション -☆-//

		// 指定された名前のアニメーションデータをモデルから取得するシステム　引数：アニメーション名の参照　戻り値：アニメーションデータのアドレス(const)
		const ASSET::ANIMATION_SYSTEM::C_Animation_Data_System * M_Get_Animation(std::string &);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Animation_Model_User(void);

		// デストラクタ
		~C_Animation_Model_User(void);

		// メモリの解放を行う
		void M_Release(void);


		//-☆- ロード -☆-//

		// 指定された名前のアニメーションモデルを読み込む　引数：ロードするアニメーションモデル名　戻り値：成功時のみtrue
		bool M_Load_Animation_Model(std::string);

		// 指定された名前のアニメーションデータをロードする　引数：ロードするアニメーションデータ名　戻り値：成功時のみtrue
		bool M_Load_Animation_Data_By_Name(std::string);


		//-☆- 更新 -☆-//

		// アニメーションを指定された時間分経過させる　引数：経過させる時間
		void M_Time_Update(float);


		//-☆- 描画 -☆-//

		// モデルの描画を開始する、描画前に実行する必要がある　引数：ワールドマトリクス変換行列の参照（const）
		void M_Model_Draw_Start(const DirectX::XMMATRIX & );

		// アニメーションモデルを描画する
		void M_Draw_Model(void);

		// アニメーションモデルから指定された名前のメッシュのみを描画する　引数：メッシュ名
		void M_Draw_Mesh_By_Mesh_Name(std::string);

		// 指定されたマテリアルでアニメーションモデルを描画する　引数：使用するマテリアル参照
		void M_Draw_Model_And_Set_Material(ASSET::MATERIAL::C_Material_User & );

		// 指定されたマテリアルでアニメーションモデルから指定された名前のメッシュのみを描画する　引数：使用するマテリアルの参照, メッシュ名
		void M_Draw_Mesh_By_Mesh_Name_And_Set_Material(ASSET::MATERIAL::C_Material_User & ,std::string);

		// モデルの描画を終了する
		void M_Model_Draw_End(void);


		//-☆- アニメーション -☆-//

		// アニメーションを現在の時間のまま再生する（ブレンドあり） 引数：アニメーション名, ブレンドに必要な時間　戻り値：成功時のみtrue
		bool M_Play_Animation(std::string, float);

		// アニメーションを指定された時間から再生する（ブレンドあり）　引数：アニメーション名, ブレンドに必要な時間, アニメーション開始時間　戻り値：成功時のみtrue
		bool M_Play_Animation_Set_Time(std::string, float, float);

		// アニメーションを現在の時間のままループ再生する（ブレンドあり）（ブレンド後のアニメーションは0秒から始まる）　引数：アニメーション名, ブレンドに必要な時間　戻り値：成功時のみtrue
		bool M_Loop_Play_Animation(std::string, float);

		// アニメーションを指定された時間からループ再生する（ブレンドあり）（ブレンド後のアニメーションは0秒から始まる）　引数：アニメーション名, ブレンドに必要な時間, アニメーション開始時間　戻り値：成功時のみtrue
		bool M_Loop_Play_Animation_And_Set_Time(std::string, float, float);

		// アニメーションを現在の時間のまま強制的に再生する（ブレンドなし）　引数：アニメーション名　戻り値：成功時のみtrue
		bool M_Force_Play_Animation(std::string);

		// アニメーションを指定された時間から強制的に再生する（ブレンドなし）　引数：アニメーション名, アニメーションの開始時間　戻り値：成功時のみtrue
		bool M_Force_Play_Animation_And_Set_Time(std::string, float);

		// アニメーションを現在の時間のまま強制的にループ再生する（ブレンドなし）　引数：アニメーション名　戻り値：成功時のみtrue
		bool M_Force_Loop_Play_Animation(std::string);

		// アニメーションを指定された時間から強制的にループ再生する（ブレンドなし）　引数：アニメーション名, アニメーションの開始時間　戻り値：成功時のみtrue
		bool M_Force_Loop_Play_Animation_And_Set_Time(std::string, float);

		// アニメーション速度をセットする　引数：セットするアニメーション速度
		void M_Set_Animation_Speed(float);


		//-☆- ゲッタ -☆-//

		// 現在のアニメーションモデルを返す　戻り値：現在のアニメーションモデルへのアドレス
		ASSET::ANIMATION_MODEL::C_3D_Animation_Model_System * M_Get_Animation_Model_Address(void);
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_MODEL_USER
