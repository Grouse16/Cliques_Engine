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

#include "S_Key_Frame.h"


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
			std::vector<ASSET::ANIMATION::DATA::S_Key_Frame> position_key_list;	// 位置座標のキーのリスト
			std::vector<ASSET::ANIMATION::DATA::S_Key_Frame> scale_key_list;	// スケールのキーのリスト

			std::vector<ASSET::ANIMATION::DATA::S_Rotation_Key_Frame> rotation_key_list;	// 回転のキーのリスト

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

		// 指定されたパスのアニメーションデータをロードする
		bool M_Get_Animation_Data_Load(std::string);


	};
}


#endif // !D_INCLUDE_GUARD_C_ANIMATION_DATA_SYSTEM_H_FILE

