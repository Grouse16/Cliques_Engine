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
#include "S_Bone_Key_Inform.h"


// ☆ ネームスペース ☆ //

// アニメーションデータを呼び出すための名前
namespace ASSET::ANIMATION::DATA
{
	// ☆ クラス ☆ //

	// アニメーションデータのクラス
	class C_Animation_Data_System
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::vector<ASSET::ANIMATION::BONE::S_Bone_Key_Inform> bone_key_list;	// ボーンのキー情報のリスト

		} mpr_variable;	// プライベート変数を呼び出すための名前


		//==☆ パブリック ☆==//
	public:

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Animation_Data_System(void);

		// デストラクタ
		~C_Animation_Data_System(void);

		// メモリの解放を行う
		void M_Release(void);

		
		//-☆- ロード -☆-//

		// 指定されたパスのアニメーションデータをロードする　引数：アニメーションデータまでのパス, アタッチ先モデルのボーンの情報　戻り値：成功時のみtrue
		bool M_Load_Anmation_Data_By_Path(std::string, std::vector<ASSET::ANIMATION::BONE::S_Bone_Inform> &);


		//-☆- キーフレーム -☆-//

		// 指定された時間とキーの影響量からそれぞれのボーンのキー情報を生成し、設定先へセットする　引数：時間, キー影響量, 設定先のボーンキー配列の参照
	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_DATA_SYSTEM_H_FILE

