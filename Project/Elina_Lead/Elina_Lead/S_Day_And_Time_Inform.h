//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：日付と時間情報の型の定義
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード
#ifndef D_INCLUDE_GUARD_S_TIME_INFORM_H_FILE
#define D_INCLUDE_GUARD_S_TIME_INFORM_H_FILE


// ☆ ネームスペース ☆ //

// OSの基底クラスを呼び出すための名前
namespace OS
{
	// ☆ 構造体 ☆//

	// 日付と時間情報の構造体
	struct S_Day_And_Time_Inform
	{
		int year = 0;	// 年
		int month = 0;	// 月
		int day = 0;	// 日

		int hour = 0;	// 時
		int minute = 0;	// 分
		int second = 0;	// 秒
	};
}


#endif // !D_INCLUDE_GUARD_S_TIME_INFORM_H_FILE
