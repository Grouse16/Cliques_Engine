//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーションデータのクラス
// 説明   ：ロード、指定された時間でのマトリクス変換情報を返すなどをする
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_ANIMATION_DATA_SYSTEM_H_FILE
#define D_INCLUDE_GUARD_C_ANIMATION_DATA_SYSTEM_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>
#include <string>

#include "S_Bone_Inform.h"
#include "C_Bone_Data.h"
#include "S_Bone_Key_Frame_List.h"


// ☆ ネームスペース ☆ //

// アニメーションデータを呼び出すための名前
namespace ASSET::ANIMATION_SYSTEM
{
	// ☆ クラス ☆ //

	// アニメーションデータのクラス
	class C_Animation_Data_System
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 構造体 ☆ //

		// ボーンのアニメーションキー管理用の情報の構造体
		struct S_Bone_Key_Inform
		{
			ASSET::ANIMATION::BONE::S_Bone_Key_Frame_List key;	// ボーンのキー情報のリスト

			int bone_index = 0;	// ボーンのインデックス番号
		};


		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::vector<S_Bone_Key_Inform> bone_key_list;	// ボーンのキー情報のリスト

			float animation_max_time = 0.0f;	// アニメーションの最大時間

		} mpr_variable;	// プライベート変数を呼び出すための名前


		// ☆ 関数 ☆ //

		//-☆- キーフレームブレンド -☆-//

		// 渡された情報を元にキー値を時間で割り出してを返す　引数：開始のキー値, 終了のキー値, 時間のパーセント　戻り値：計算結果のキー値
		inline float M_Key_To_Key_Value_Calculation_By_Time(float, float, float) const;

		// 指定された情報からキーフレームの計算を行い情報をブレンドする　引数：今の時間, ブレンド率, 設定元のキーフレーム情報, 設定先のキー値
		inline void M_Blend_Key_Frame(float , float , const std::vector<ASSET::ANIMATION_SYSTEM::S_Key_Frame> &, DirectX::XMFLOAT3 &) const;

		// 指定された情報からクォータニオンのキーフレームの計算を行い情報をブレンドする　引数：今の時間, ブレンド率, 設定元のクォータニオンキーフレーム情報, 設定先のキー値
		inline void M_Blend_Quaternion_Key_Frame(float, float, const std::vector<ASSET::ANIMATION_SYSTEM::S_Quaternion_Key_Frame> &, DirectX::XMVECTOR &) const;


		//-☆- キーフレームセット -☆-//

		// 指定された情報からキーフレームの計算を行い情報をセットする　引数：今の時間, 設定元のキーフレーム情報, 設定先のキー値
		inline void M_Set_Key_Frame(float, const std::vector<ASSET::ANIMATION_SYSTEM::S_Key_Frame> & , DirectX::XMFLOAT3 & ) const;

		// 指定された情報からクォータニオンのキーフレームの計算を行い情報をセットする　引数：今の時間, 設定元のクォータニオンキーフレーム情報, 設定先のキー値
		inline void M_Set_Quaternion_Key_Frame(float, const std::vector<ASSET::ANIMATION_SYSTEM::S_Quaternion_Key_Frame> &, DirectX::XMVECTOR &) const;


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Animation_Data_System(void);

		// デストラクタ
		~C_Animation_Data_System(void);

		// メモリの解放を行う
		void M_Release(void);

		
		//-☆- ロード -☆-//

		// 指定されたパスのアニメーションデータをロードする　引数：アニメーションデータまでのパス, アタッチ先モデルのボーンの情報　戻り値：成功時のみtrue
		bool M_Load_Animation_Data_By_Path(std::string, std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> &);


		//-☆- キーフレームブレンド -☆-//

		// 指定された時間とキーのブレンド率からそれぞれのボーンのキー情報を生成し、設定先へブレンドする　引数：時間, ブレンド率, 設定先のボーンキーのボーンごとの配列の参照
		void M_Blend_Bone_Key(float, float, std::vector<ASSET::ANIMATION::BONE::C_Bone_Data> &) const;


		//-☆- キーフレームセット -☆-//

		// 指定された時間からそれぞれのボーンのキー情報を生成し、設定先へセットする　引数：時間, 設定先のボーンキーのボーンごとの配列の参照
		void M_Set_Bone_Key(float, std::vector<ASSET::ANIMATION::BONE::C_Bone_Data> &) const;


		//-☆- ゲッタ -☆-//

		// アニメーション開始から終了までの時間　戻り値：アニメーション開始から終了までの時間
		int M_Get_Animation_Time(void) const;
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_DATA_SYSTEM_H_FILE

