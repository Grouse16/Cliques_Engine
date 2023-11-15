//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：アニメーションの計算を制御するクラスの基底クラス
// 説明   ：どんなアニメーションをするかを分岐ではなく、生成するクラスによって分岐できるようにするための抽象化レイヤー　アニメーションの計算がおこなわれないときはこれを実体化する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ ファイルひらき ☆ //
#include "C_Animation_Algorithm_Base.h"
#include "C_Game_Time_Manager.h"


// ☆ ネームスペースの省略 ☆ //
using namespace ASSET::ANIMATION::ALGORITHM;


// ☆ 関数 ☆ //

//==☆ プロテクト ☆==//

//-☆- 論理演算 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：値１が値２より大きいなら値１に値２をセットする、そうでないなら何もしない
// 引数   ：float & 値１, float 値２
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
inline void C_Animation_Algorithm_Base::M_Guard_1_Over_2(float & out_value_1, float in_value_2)
{
	out_value_1 =
		(out_value_1 > in_value_2) * in_value_2
		+ 
		(out_value_1 <= in_value_2) * out_value_1;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：アニメーションの時間の再生と逆再生時を行い、アニメーションの終了も判定する
// 引数   ：S_Animation_Status & アニメーションの情報の参照, float アニメーション開始から終了までの時間
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
inline void C_Animation_Algorithm_Base::M_Animation_Time_Base_Update(ASSET::ANIMATION::S_Animation_Status & out_animation_status, float in_animation_max_time)
{
	// アニメーション時間の再生、または逆再生
	out_animation_status.animation_time += GAME::TIME::C_Game_Time_Manager::M_Get_Game_Second() * out_animation_status.animation_speed * (1.0f - 2.0f * out_animation_status.flg_animation_reverse);


	// アニメーションの終了時間を過ぎないようにする
	out_animation_status.animation_time =

		// 通常再生時
		(
			(out_animation_status.animation_time > in_animation_max_time) * in_animation_max_time
			+
			(out_animation_status.animation_time <= in_animation_max_time) * out_animation_status.animation_time
		) * !out_animation_status.flg_animation_reverse
		+
		// 逆再生時
		(out_animation_status.animation_time >= 0.0f) * out_animation_status.animation_time * out_animation_status.flg_animation_reverse;

	// 終了時間に到達していたらアニメーション終了のフラグを立てる
	out_animation_status.flg_animation_reverse = 

		// 通常再生時
		(out_animation_status.animation_time >= in_animation_max_time) * !out_animation_status.flg_animation_reverse
		+
		// 逆再生時
		(out_animation_status.animation_time <= 0.0f) * out_animation_status.flg_animation_reverse;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ブレンド元の時間の再生と逆再生を行う
// 引数   ：const S_Animation_Status & アニメーションの情報(const), ブレンド元の時間の参照, アニメーション開始から終了までの時間
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
inline void C_Animation_Algorithm_Base::M_Animation_Blend_Time_Update(const ASSET::ANIMATION::S_Animation_Status & in_animation_status, float & out_blend_from_time, float in_animation_max_time)
{
	// アニメーション時間の再生、または逆再生
	out_blend_from_time += GAME::TIME::C_Game_Time_Manager::M_Get_Game_Second() * in_animation_status.animation_speed * (1.0f - 2.0f * in_animation_status.flg_animation_reverse);


	// アニメーションの終了時間を過ぎないようにする
	out_blend_from_time =

		// 通常再生時
		(
			(out_blend_from_time > in_animation_max_time) * in_animation_max_time
			+
			(out_blend_from_time <= in_animation_max_time) * out_blend_from_time
			) * !in_animation_status.flg_animation_reverse
		+
		// 逆再生時
		(out_blend_from_time >= 0.0f) * out_blend_from_time * in_animation_status.flg_animation_reverse;

	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：ループするアニメーションの時間の再生と逆再生時を行う
// 引数   ：S_Animation_Status & アニメーションの情報の参照, float アニメーション開始から終了までの時間
// 戻り値 ：void
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
inline void C_Animation_Algorithm_Base::M_Loop_Animation_Time_Base_Update(ASSET::ANIMATION::S_Animation_Status & out_animation_status, float in_animation_max_time)
{
	// ゲーム時間に合わせて時間経過する
	out_animation_status.animation_time += GAME::TIME::C_Game_Time_Manager::M_Get_Game_Second() * out_animation_status.animation_speed * (1.0f - 2.0f * out_animation_status.flg_animation_reverse);

	// アニメーションの終了時間を過ぎないようにする
	out_animation_status.animation_time =

		// 通常再生時の計算
		(
			(out_animation_status.animation_time > in_animation_max_time) * (out_animation_status.animation_time - in_animation_max_time)
			+ (out_animation_status.animation_time <= in_animation_max_time) * out_animation_status.animation_time
			)
		* !out_animation_status.flg_animation_reverse
		+

		// 逆再生時の計算
		(
			(out_animation_status.animation_time < 0.0f) * (in_animation_max_time + out_animation_status.animation_time)
			+ (out_animation_status.animation_time >= 0.0f) * out_animation_status.animation_time
			)
		* out_animation_status.flg_animation_reverse;

	return;
}


//==☆ パブリック ☆==//

//-☆- 初期化と終了時 -☆-//

//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：コンストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Animation_Algorithm_Base::C_Animation_Algorithm_Base(void)
{
	return;
}


//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
// 詳細   ：デストラクタ
// 引数   ：void
// 戻り値 ：なし
//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
C_Animation_Algorithm_Base::~C_Animation_Algorithm_Base(void)
{
	return;
}
