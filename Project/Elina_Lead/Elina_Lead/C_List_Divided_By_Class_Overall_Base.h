//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：クラスごとに分離したリストを管理するクラスの基底、派生先のリストをまとめたリストを生成できる（テンプレートには派生先のリストのクラスを設定）
// 説明   ：テンプレートに派生先のリストのクラスを設定することで、設定したリストが複数作られた場合でも、それらのリストを配列としてまとめられるシステムを用意している（Overallは「全体の」という意味）
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆　//
#ifndef D_INCLUDE_GUARD_C_INSTANCE_LIST_OVERALL_BASE_H_FILE
#define D_INCLUDE_GUARD_C_INSTANCE_LIST_OVERALL_BASE_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>

#include "C_Game_Instance_Base.h"


// ☆ ネームスペース ☆ //

// リストの基底となるシステムを呼び出すための名前
namespace SYSTEM::LIST::BASE
{
	// ☆ クラス ☆ //

	// クラスごとに分離したリストを管理するクラスの基底、派生先のリストをまとめたリストを生成できる（テンプレートには派生先のリストのクラスを設定）
	template <template <typename> class C_List>
	class C_List_Divided_By_Class_Overall_Base
	{
		//==☆ プロテクト ☆==//
	protected:

		// ☆ 変数宣言 ☆ //
		std::vector<C_List * > m_list_of_all_instance_list;	// 現在あるインスタンス管理リストをまとめた配列

		static inline C_List_Divided_By_Class_Overall_Base<C_List> m_this;	// シングルトン化用インスタンス


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：コンストラクタ、シングルトン化する
		// 引数   ：void
		// 戻り値 ：なし
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		C_List_Divided_By_Class_Overall_Base(void)
		{
			return;
		}


		//-☆- 追加 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定されたリストをインスタンス管理リストのリストに加える
		// 引数   ：C_List * インスタンス管理リストのアドレス
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		static void M_Add_To_List_Of_All_Instance_List(C_List * in_instance_list_address)
		{
			m_this.m_list_of_all_instance_list.reserve(m_this.m_list_of_all_instance_list.size() + 1);
			m_this.m_list_of_all_instance_list.emplace_back(in_instance_list_address);

			return;
		}


		//-☆- 削除 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定されたリストをインスタンス管理リストのリストから削除する
		// 引数   ：C_List * インスタンス管理リストのアドレス
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		static void M_Delete_By_List_Of_All_Instance_List(C_List * in_instance_list_address)
		{
			m_this.m_list_of_all_instance_list.erase
			(
				std::remove_if
				(
					m_this.m_list_of_all_instance_list.begin(),
					m_this.m_list_of_all_instance_list.end(),
					[in_instance_list_address](C_List * & in_check_list)
					{
						return in_check_list == in_instance_list_address;
					}
				),
				m_this.m_list_of_all_instance_list.end()
			);
			m_this.m_list_of_all_instance_list.shrink_to_fit();

			return;
		}


		//-☆- ソート -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定されたラムダ式でインスタンス配列をソートする
		// 引数   ：function<bool(C_Instance &)> ソート用のラムダ式、全ての要素の関係がtrueになるまでソートを続ける
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		static void M_Sort_Instance_By_Lambda(std::function<bool(C_List &, C_List&)> in_sort_lamda)
		{
			// ソートする
			std::sort
			(
				m_this.m_list_of_all_instance_list.begin(),	// ソートの開始位置
				m_this.m_list_of_all_instance_list.end(),	// ソートの終了位置

				// ソート用ラムダ式、全ての要素の関係がtrueになるまでソートを続ける、クイックソートを行う
				in_delete_lamda
			);

			return;
		}


		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 終了時 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：デストラクタ
		// 引数   ：void
		// 戻り値 ：なし
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		virtual ~C_List_Divided_By_Class_Overall_Base(void)
		{
			return;
		}


		//-☆- ゲッタ -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：テンプレート引数型のインスタンス管理リストをまとめた配列の参照を返す
		// 引数   ：void
		// 戻り値 ：vector<C_Instance_List_Overall_Base<C_List> * > &  引数型の全てのリスト
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		static std::vector<C_List * > & M_Get_List_Of_All_Instance_List(void)
		{
			return m_this.m_list_of_all_instance_list;
		}
	};
}


#endif // !D_INCLUDE_GUARD_C_INSTANCE_LIST_BASE_H_FILE


//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆


