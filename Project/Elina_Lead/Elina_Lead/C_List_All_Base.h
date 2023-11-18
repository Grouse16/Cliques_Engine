//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：インスタンス分離リストの全ての元となる基底クラス
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_LIST_ALL_BASE
#define D_INCLUDE_GUARD_C_LIST_ALL_BASE


// ☆ ファイルひらき ☆ //
#include <vector>


// ☆ ネームスペース ☆ //

// インスタンス分離リストの全ての元となる基底クラスを呼び出すための名前
namespace SYSTEM::LIST::BASE::ALL_LIST_BASE
{
	// ☆ クラス ☆ //

	// インスタンス分離リストの全ての元となる基底クラス
	class C_List_All_Base
	{
		//==☆ プロテクト ☆==//
	protected:

		// ☆ 変数宣言 ☆ //
		std::vector<int> m_priority_list;	// 優先度のリスト


		// ☆ 関数 ☆ //

		//-☆- ゲッタ -☆-//

		// 優先度のリストを返す　戻り値：vector<int> & 優先度のリスト
		std::vector<int> & M_Get_Priority_List(void);


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_List_All_Base(void);

		// デストラクタ
		virtual ~C_List_All_Base(void);


		//-☆- 更新 -☆-//

		// リスト内のインスタンスの更新を行う
		virtual void M_Instance_Update(void) = 0;


		//-☆- 描画 -☆-//

		// リスト内のインスタンスの描画を行う
		virtual void M_Instance_Draw(void) = 0;


		//-☆- 削除 -☆-//

		// 一部のインスタンスの削除を行う
		virtual void M_Delete_Instance_Execute(void) = 0;

		// 全てのインスタンスの削除を行う
		virtual void M_Delete_All_Instance_Execute(void) = 0;
	};
}


#endif // !D_INCLUDE_GUARD_C_LIST_ALL_BASE

