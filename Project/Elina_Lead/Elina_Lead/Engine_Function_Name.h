//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：エンジンの機能名一覧
// 説明   ：主に生成時に使用する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_ENGINE_FUNCTION_NAME_H_FILE
#define D_INCLUDE_GUARD_ENGINE_FUNCTION_NAME_H_FILE


// ☆ ファイルひらき ☆ //
#include <string>


// ☆ ネームスペース ☆ //

// エンジンの機能用の名前の定義を呼び出すための名前
namespace GAME::FUNCTION::NAME
{
	// 基本部分
	namespace BASE
	{
		const std::string con_FRAME_WORK = "FRAME_WORK";	// エンジンの枠組み
	}
}


#endif // !D_INCLUDE_GUARD_ENGINE_FUNCTION_NAME_H_FILE

